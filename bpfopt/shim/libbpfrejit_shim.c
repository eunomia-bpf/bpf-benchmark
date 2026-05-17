/*
 * libbpfrejit_shim.so — LD_PRELOAD observation + state-tracking shim for BPF.
 *
 * Phase 1 (intercept + log):
 *   wrap syscall(2)/ioctl(2)/perf_event_open(2)/close(2)/dup2/dup3 in libc.
 *   For each observed BPF/perf control-plane call: log, then pass through.
 *
 * Phase 1.5 (state tables — this file):
 *   maintain in-process tables of every BPF object whose fd lives in this
 *   process: programs, maps, links, perf_event handles. Tables are keyed by
 *   app-side fd. Each entry records the kernel-side id (resolved via
 *   BPF_OBJ_GET_INFO_BY_FD), the original load attr (for prog), and the
 *   attach relationship (for link / perf_event). close() / dup2() / dup3()
 *   maintain table consistency. SIGUSR1 dumps tables as JSON.
 *
 * Phase 2 (not yet): bpfopt subprocess pipeline, candidate BPF_PROG_LOAD with
 *   captured attr, per-attach swap recipe.
 *
 * Usage:
 *   gcc -shared -fPIC -O2 libbpfrejit_shim.c -o libbpfrejit_shim.so -ldl -lpthread
 *   BPFREJIT_SHIM_LOG=/tmp/shim.log LD_PRELOAD=./libbpfrejit_shim.so <app>
 *   kill -USR1 <pid>     # dump state to BPFREJIT_SHIM_DIR/state_<pid>.json
 */

#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/perf_event.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Intentionally omit <sys/ioctl.h>: musl declares `ioctl(int, int, ...)` while
 * glibc declares `ioctl(int, unsigned long, ...)`. We pick the kernel ABI
 * (unsigned long request) and self-declare what we need from asm-generic/ioctl.h
 * via <linux/ioctl.h>. */
#include <linux/ioctl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#ifndef SYS_perf_event_open
#define SYS_perf_event_open 298 /* x86_64 */
#endif

#ifndef PERF_EVENT_IOC_SET_BPF
#define PERF_EVENT_IOC_SET_BPF _IOW('$', 8, __u32)
#endif

#ifndef PERF_EVENT_IOC_QUERY_BPF
#define PERF_EVENT_IOC_QUERY_BPF _IOWR('$', 10, struct perf_event_query_bpf *)
#endif

/* Resolved real symbols, set in shim_init(). */
static long (*real_syscall)(long, ...);
static int (*real_ioctl)(int, unsigned long, ...);
static int (*real_close)(int);
static int (*real_dup2)(int, int);
static int (*real_dup3)(int, int, int);

static FILE *log_file;
static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Recursion guard: shim-internal syscalls must not re-enter the logger. */
static __thread int in_shim;

/* ====================================================================
 * State tables — Phase 1.5
 *
 * One table per object type, keyed by app-side fd. fd is bounded by
 * RLIMIT_NOFILE which is typically <= 1<<20; we use a hash map with a
 * per-bucket linked list to be safe and forward-compatible.
 *
 * Entry types:
 *   OBJ_PROG  — BPF program loaded via BPF_PROG_LOAD
 *   OBJ_MAP   — BPF map created via BPF_MAP_CREATE (or opened via
 *               BPF_MAP_GET_FD_BY_ID, in which case kernel_id is the id
 *               passed by app)
 *   OBJ_LINK  — link returned by BPF_LINK_CREATE
 *   OBJ_PERF  — perf_event fd returned by perf_event_open(2); attached_prog_fd
 *               is updated on PERF_EVENT_IOC_SET_BPF.
 *
 * All accesses go through state_mutex.
 * ==================================================================== */

enum obj_kind {
    OBJ_NONE = 0,
    OBJ_PROG,
    OBJ_MAP,
    OBJ_LINK,
    OBJ_PERF,
};

struct prog_data {
    uint32_t prog_type;
    char name[17]; /* BPF_OBJ_NAME_LEN+1 NUL-terminated */
    uint32_t insn_cnt;
    uint64_t hash;
    char bytecode_path[256];
    uint32_t expected_attach_type;
    uint32_t attach_btf_id;
    uint32_t kernel_prog_id; /* 0 until resolved via OBJ_GET_INFO_BY_FD */
    /* Captured BPF_PROG_LOAD attr — used later for candidate re-load.
     * insns pointer inside attr is left dangling intentionally; consumers must
     * patch it with the heap-owned copy below before re-LOAD. */
    union bpf_attr load_attr;
    /* Heap-owned deep copy of the bytecode itself (so the dangling pointer
     * inside load_attr is unambiguous and the file in bytecode_path is also
     * available for the bpfopt CLI). */
    struct bpf_insn *insns;
};

struct map_data {
    uint32_t map_type;
    uint32_t key_size;
    uint32_t value_size;
    uint32_t max_entries;
    uint32_t kernel_map_id;
    char name[17];
};

struct link_data {
    uint32_t prog_fd; /* app-side prog fd at create time */
    uint32_t target_fd;
    uint32_t attach_type;
    uint32_t link_type;
    uint32_t kernel_link_id;
};

struct perf_data {
    uint32_t type;
    uint64_t config;
    int32_t pid;
    int32_t cpu;
    int32_t attached_prog_fd; /* -1 until SET_BPF observed */
};

struct obj_entry {
    int fd;
    enum obj_kind kind;
    struct obj_entry *next;
    union {
        struct prog_data prog;
        struct map_data map;
        struct link_data link;
        struct perf_data perf;
    } u;
};

#define OBJ_TABLE_BUCKETS 1024
static struct obj_entry *obj_table[OBJ_TABLE_BUCKETS];
static pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;

static unsigned obj_bucket(int fd) {
    return ((unsigned)fd * 2654435761u) % OBJ_TABLE_BUCKETS;
}

/* Caller must hold state_mutex. Returns existing entry for fd or NULL. */
static struct obj_entry *obj_find(int fd) {
    if (fd < 0) return NULL;
    for (struct obj_entry *e = obj_table[obj_bucket(fd)]; e; e = e->next)
        if (e->fd == fd) return e;
    return NULL;
}

/* Caller must hold state_mutex. Replaces any existing entry for fd. */
static void obj_insert(struct obj_entry *e) {
    unsigned b = obj_bucket(e->fd);
    /* Remove any previous entry for this fd (e.g. fd reused after close). */
    struct obj_entry **prev = &obj_table[b];
    while (*prev) {
        if ((*prev)->fd == e->fd) {
            struct obj_entry *dead = *prev;
            *prev = dead->next;
            if (dead->kind == OBJ_PROG) free(dead->u.prog.insns);
            free(dead);
        } else {
            prev = &(*prev)->next;
        }
    }
    e->next = obj_table[b];
    obj_table[b] = e;
}

/* Caller must hold state_mutex. Removes and frees entry for fd, if any. */
static void obj_remove(int fd) {
    if (fd < 0) return;
    struct obj_entry **prev = &obj_table[obj_bucket(fd)];
    while (*prev) {
        if ((*prev)->fd == fd) {
            struct obj_entry *dead = *prev;
            *prev = dead->next;
            if (dead->kind == OBJ_PROG) free(dead->u.prog.insns);
            free(dead);
            return;
        }
        prev = &(*prev)->next;
    }
}

/* OBJ_GET_INFO_BY_FD on prog/map/link, used to resolve kernel ids. The shim
 * is allowed to call this re-entrantly while in_shim is set. */
static uint32_t resolve_kernel_id(int fd, enum obj_kind kind) {
    /* struct bpf_prog_info / bpf_map_info / bpf_link_info all start with
     * a u32 type field followed by u32 id; we just read id. */
    struct {
        uint32_t type;
        uint32_t id;
        uint8_t pad[256];
    } info;
    memset(&info, 0, sizeof(info));
    union bpf_attr attr = {0};
    attr.info.bpf_fd = (uint32_t)fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = (uintptr_t)&info;
    long r = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr));
    if (r < 0) return 0;
    (void)kind;
    return info.id;
}

static void log_line(const char *fmt, ...) {
    /* No in_shim guard: log_line only emits via fprintf+write, which never
     * issues SYS_bpf and therefore cannot recurse into our intercept path. */
    if (!log_file)
        return;
    pthread_mutex_lock(&log_mutex);
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    fprintf(log_file, "[%ld.%06ld pid=%d tid=%ld] ", ts.tv_sec,
            ts.tv_nsec / 1000, getpid(), syscall(SYS_gettid));
    va_list ap;
    va_start(ap, fmt);
    vfprintf(log_file, fmt, ap);
    va_end(ap);
    fputc('\n', log_file);
    fflush(log_file);
    pthread_mutex_unlock(&log_mutex);
}

static const char *bpf_cmd_name(int cmd) {
    switch (cmd) {
    case BPF_MAP_CREATE: return "MAP_CREATE";
    case BPF_MAP_LOOKUP_ELEM: return "MAP_LOOKUP_ELEM";
    case BPF_MAP_UPDATE_ELEM: return "MAP_UPDATE_ELEM";
    case BPF_MAP_DELETE_ELEM: return "MAP_DELETE_ELEM";
    case BPF_MAP_GET_NEXT_KEY: return "MAP_GET_NEXT_KEY";
    case BPF_PROG_LOAD: return "PROG_LOAD";
    case BPF_OBJ_PIN: return "OBJ_PIN";
    case BPF_OBJ_GET: return "OBJ_GET";
    case BPF_PROG_ATTACH: return "PROG_ATTACH";
    case BPF_PROG_DETACH: return "PROG_DETACH";
    case BPF_PROG_TEST_RUN: return "PROG_TEST_RUN";
    case BPF_PROG_GET_NEXT_ID: return "PROG_GET_NEXT_ID";
    case BPF_MAP_GET_NEXT_ID: return "MAP_GET_NEXT_ID";
    case BPF_PROG_GET_FD_BY_ID: return "PROG_GET_FD_BY_ID";
    case BPF_MAP_GET_FD_BY_ID: return "MAP_GET_FD_BY_ID";
    case BPF_OBJ_GET_INFO_BY_FD: return "OBJ_GET_INFO_BY_FD";
    case BPF_PROG_QUERY: return "PROG_QUERY";
    case BPF_RAW_TRACEPOINT_OPEN: return "RAW_TRACEPOINT_OPEN";
    case BPF_BTF_LOAD: return "BTF_LOAD";
    case BPF_BTF_GET_FD_BY_ID: return "BTF_GET_FD_BY_ID";
    case BPF_TASK_FD_QUERY: return "TASK_FD_QUERY";
    case BPF_MAP_LOOKUP_AND_DELETE_ELEM: return "MAP_LOOKUP_AND_DELETE_ELEM";
    case BPF_MAP_FREEZE: return "MAP_FREEZE";
    case BPF_BTF_GET_NEXT_ID: return "BTF_GET_NEXT_ID";
    case BPF_LINK_CREATE: return "LINK_CREATE";
    case BPF_LINK_UPDATE: return "LINK_UPDATE";
    case BPF_LINK_GET_FD_BY_ID: return "LINK_GET_FD_BY_ID";
    case BPF_LINK_GET_NEXT_ID: return "LINK_GET_NEXT_ID";
    case BPF_ENABLE_STATS: return "ENABLE_STATS";
    case BPF_ITER_CREATE: return "ITER_CREATE";
    case BPF_LINK_DETACH: return "LINK_DETACH";
    case BPF_PROG_BIND_MAP: return "PROG_BIND_MAP";
    default: return "UNKNOWN";
    }
}

static const char *prog_type_name(uint32_t t) {
    switch (t) {
    case BPF_PROG_TYPE_SOCKET_FILTER: return "SOCKET_FILTER";
    case BPF_PROG_TYPE_KPROBE: return "KPROBE";
    case BPF_PROG_TYPE_SCHED_CLS: return "SCHED_CLS";
    case BPF_PROG_TYPE_SCHED_ACT: return "SCHED_ACT";
    case BPF_PROG_TYPE_TRACEPOINT: return "TRACEPOINT";
    case BPF_PROG_TYPE_XDP: return "XDP";
    case BPF_PROG_TYPE_PERF_EVENT: return "PERF_EVENT";
    case BPF_PROG_TYPE_CGROUP_SKB: return "CGROUP_SKB";
    case BPF_PROG_TYPE_CGROUP_SOCK: return "CGROUP_SOCK";
    case BPF_PROG_TYPE_LWT_IN: return "LWT_IN";
    case BPF_PROG_TYPE_LWT_OUT: return "LWT_OUT";
    case BPF_PROG_TYPE_LWT_XMIT: return "LWT_XMIT";
    case BPF_PROG_TYPE_SOCK_OPS: return "SOCK_OPS";
    case BPF_PROG_TYPE_SK_SKB: return "SK_SKB";
    case BPF_PROG_TYPE_CGROUP_DEVICE: return "CGROUP_DEVICE";
    case BPF_PROG_TYPE_SK_MSG: return "SK_MSG";
    case BPF_PROG_TYPE_RAW_TRACEPOINT: return "RAW_TRACEPOINT";
    case BPF_PROG_TYPE_CGROUP_SOCK_ADDR: return "CGROUP_SOCK_ADDR";
    case BPF_PROG_TYPE_LWT_SEG6LOCAL: return "LWT_SEG6LOCAL";
    case BPF_PROG_TYPE_LIRC_MODE2: return "LIRC_MODE2";
    case BPF_PROG_TYPE_SK_REUSEPORT: return "SK_REUSEPORT";
    case BPF_PROG_TYPE_FLOW_DISSECTOR: return "FLOW_DISSECTOR";
    case BPF_PROG_TYPE_CGROUP_SYSCTL: return "CGROUP_SYSCTL";
    case BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE: return "RAW_TRACEPOINT_WRITABLE";
    case BPF_PROG_TYPE_CGROUP_SOCKOPT: return "CGROUP_SOCKOPT";
    case BPF_PROG_TYPE_TRACING: return "TRACING";
    case BPF_PROG_TYPE_STRUCT_OPS: return "STRUCT_OPS";
    case BPF_PROG_TYPE_EXT: return "EXT";
    case BPF_PROG_TYPE_LSM: return "LSM";
    case BPF_PROG_TYPE_SK_LOOKUP: return "SK_LOOKUP";
    case BPF_PROG_TYPE_SYSCALL: return "SYSCALL";
    case BPF_PROG_TYPE_NETFILTER: return "NETFILTER";
    default: return "UNKNOWN";
    }
}

/* Lightweight non-cryptographic hash of the prog bytecode for cross-correlation. */
static uint64_t fnv1a64(const void *data, size_t len) {
    uint64_t h = 0xcbf29ce484222325ULL;
    const uint8_t *p = (const uint8_t *)data;
    for (size_t i = 0; i < len; i++) {
        h ^= p[i];
        h *= 0x100000001b3ULL;
    }
    return h;
}

static void dump_bytecode(uint64_t hash, const struct bpf_insn *insns,
                          uint32_t insn_cnt) {
    /* Write raw bytecode for the optimizer to pick up later.
     * Path: $BPFREJIT_SHIM_DIR/<pid>_<hash>.bpf
     */
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir)
        dir = "/tmp";
    char path[512];
    snprintf(path, sizeof(path), "%s/bpfrejit_%d_%016lx.bpf", dir, getpid(),
             hash);
    int fd = open(path, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd < 0)
        return; /* duplicate hash, race, or no perm — fine */
    size_t bytes = (size_t)insn_cnt * sizeof(struct bpf_insn);
    ssize_t n = write(fd, insns, bytes);
    close(fd);
    if (n != (ssize_t)bytes)
        log_line("  bytecode dump truncated: wrote=%zd want=%zu path=%s", n,
                 bytes, path);
}

/* Returned heap struct must be fed to obj_insert under state_mutex once the
 * load result fd is known. Caller takes ownership; on error returns NULL. */
static struct obj_entry *capture_prog_load(const union bpf_attr *attr) {
    char name[17] = {0};
    memcpy(name, attr->prog_name, 16);
    uint32_t insn_cnt = attr->insn_cnt;
    const struct bpf_insn *insns = (const struct bpf_insn *)(uintptr_t)attr->insns;
    uint64_t hash = 0;
    char path[256] = {0};
    struct bpf_insn *copy = NULL;
    if (insns && insn_cnt > 0) {
        size_t bytes = (size_t)insn_cnt * sizeof(struct bpf_insn);
        hash = fnv1a64(insns, bytes);
        dump_bytecode(hash, insns, insn_cnt);
        const char *dir = getenv("BPFREJIT_SHIM_DIR");
        if (!dir) dir = "/tmp";
        snprintf(path, sizeof(path), "%s/bpfrejit_%d_%016lx.bpf", dir,
                 getpid(), hash);
        copy = (struct bpf_insn *)malloc(bytes);
        if (copy)
            memcpy(copy, insns, bytes);
    }
    log_line("BPF_PROG_LOAD type=%u (%s) name=%s insn_cnt=%u hash=%016lx "
             "license=%s expected_attach=%u attach_btf_id=%u",
             attr->prog_type, prog_type_name(attr->prog_type), name, insn_cnt,
             hash, (const char *)(uintptr_t)attr->license,
             attr->expected_attach_type, attr->attach_btf_id);
    if (!copy && insn_cnt > 0)
        return NULL; /* OOM: drop state, keep log */
    struct obj_entry *e = (struct obj_entry *)calloc(1, sizeof(*e));
    if (!e) {
        free(copy);
        return NULL;
    }
    e->kind = OBJ_PROG;
    e->u.prog.prog_type = attr->prog_type;
    memcpy(e->u.prog.name, attr->prog_name, 16);
    e->u.prog.name[16] = 0;
    e->u.prog.insn_cnt = insn_cnt;
    e->u.prog.hash = hash;
    e->u.prog.expected_attach_type = attr->expected_attach_type;
    e->u.prog.attach_btf_id = attr->attach_btf_id;
    e->u.prog.load_attr = *attr;
    e->u.prog.insns = copy;
    if (path[0]) memcpy(e->u.prog.bytecode_path, path, sizeof(path));
    return e;
}

static struct obj_entry *capture_map_create(const union bpf_attr *attr) {
    struct obj_entry *e = (struct obj_entry *)calloc(1, sizeof(*e));
    if (!e) return NULL;
    e->kind = OBJ_MAP;
    e->u.map.map_type = attr->map_type;
    e->u.map.key_size = attr->key_size;
    e->u.map.value_size = attr->value_size;
    e->u.map.max_entries = attr->max_entries;
    memcpy(e->u.map.name, attr->map_name, 16);
    e->u.map.name[16] = 0;
    log_line("BPF_MAP_CREATE type=%u key_size=%u value_size=%u max_entries=%u "
             "name=%s",
             attr->map_type, attr->key_size, attr->value_size,
             attr->max_entries, e->u.map.name);
    return e;
}

static struct obj_entry *capture_link_create(const union bpf_attr *attr) {
    struct obj_entry *e = (struct obj_entry *)calloc(1, sizeof(*e));
    if (!e) return NULL;
    e->kind = OBJ_LINK;
    e->u.link.prog_fd = attr->link_create.prog_fd;
    e->u.link.target_fd = attr->link_create.target_fd;
    e->u.link.attach_type = attr->link_create.attach_type;
    return e;
}

static void on_link_update(const union bpf_attr *attr) {
    log_line("BPF_LINK_UPDATE link_fd=%u new_prog_fd=%u flags=%u old_prog_fd=%u",
             attr->link_update.link_fd, attr->link_update.new_prog_fd,
             attr->link_update.flags, attr->link_update.old_prog_fd);
}

static void on_prog_attach(const union bpf_attr *attr) {
    log_line("BPF_PROG_ATTACH target_fd=%u attach_bpf_fd=%u attach_type=%u",
             attr->target_fd, attr->attach_bpf_fd, attr->attach_type);
}

static void on_raw_tp_open(const union bpf_attr *attr) {
    log_line("BPF_RAW_TRACEPOINT_OPEN name=%s prog_fd=%u",
             (const char *)(uintptr_t)attr->raw_tracepoint.name,
             attr->raw_tracepoint.prog_fd);
}

static void sigusr1_handler(int sig);   /* forward decl */
static void *worker_thread(void *arg);  /* forward decl */

__attribute__((constructor)) static void shim_init(void) {
    real_syscall = dlsym(RTLD_NEXT, "syscall");
    real_ioctl = dlsym(RTLD_NEXT, "ioctl");
    real_close = dlsym(RTLD_NEXT, "close");
    real_dup2 = dlsym(RTLD_NEXT, "dup2");
    real_dup3 = dlsym(RTLD_NEXT, "dup3");

    /* Auto-create the bytecode dump dir. */
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    mkdir(dir, 0755); /* idempotent */

    const char *log_path = getenv("BPFREJIT_SHIM_LOG");
    if (!log_path)
        log_path = "/tmp/bpfrejit_shim.log";
    log_file = fopen(log_path, "a");
    if (log_file) {
        setvbuf(log_file, NULL, _IOLBF, 0);
        char exe[256] = {0};
        ssize_t n = readlink("/proc/self/exe", exe, sizeof(exe) - 1);
        if (n > 0) exe[n] = 0;
        log_line("shim_init pid=%d exe=%s", getpid(), exe);
    }

    /* SIGUSR1 → dump JSON snapshot. NOTE: Go runtime hijacks SIGUSR1 after
     * its own init runs, so this is unreliable for Go apps; for those use
     * BPFREJIT_SHIM_PERIODIC_DUMP_MS instead. C/C++ apps still get the
     * signal-driven dump. */
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigusr1_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);

    /* Periodic dump worker, if enabled by env. */
    pthread_t tid;
    pthread_create(&tid, NULL, worker_thread, NULL);
    pthread_detach(tid);
}

/* Intercept syscall(2). */
long syscall(long number, ...) {
    /* Forward 6 long args verbatim — kernel-side ABI takes <= 6, reading
     * unused-but-not-passed va_args is UB but practically safe on x86_64
     * because syscall(2) callers always pass through the same register
     * convention. We do not introspect args for non-bpf syscalls. */
    va_list ap;
    va_start(ap, number);
    long a0 = va_arg(ap, long);
    long a1 = va_arg(ap, long);
    long a2 = va_arg(ap, long);
    long a3 = va_arg(ap, long);
    long a4 = va_arg(ap, long);
    long a5 = va_arg(ap, long);
    va_end(ap);

    if (in_shim || number != SYS_bpf) {
        if (number == SYS_perf_event_open && !in_shim) {
            const struct perf_event_attr *pa =
                (const struct perf_event_attr *)a0;
            pid_t pid = (pid_t)a1;
            int cpu = (int)a2;
            int group_fd = (int)a3;
            unsigned long flags = (unsigned long)a4;
            in_shim = 1;
            long ret = real_syscall(number, a0, a1, a2, a3, a4, a5);
            int saved_errno = errno;
            if (ret >= 0 && pa) {
                struct obj_entry *e = (struct obj_entry *)calloc(1, sizeof(*e));
                if (e) {
                    e->fd = (int)ret;
                    e->kind = OBJ_PERF;
                    e->u.perf.type = pa->type;
                    e->u.perf.config = pa->config;
                    e->u.perf.pid = pid;
                    e->u.perf.cpu = cpu;
                    e->u.perf.attached_prog_fd = -1;
                    pthread_mutex_lock(&state_mutex);
                    obj_insert(e);
                    pthread_mutex_unlock(&state_mutex);
                }
            }
            in_shim = 0;
            log_line("perf_event_open type=%u config=%llu pid=%d cpu=%d "
                     "group_fd=%d flags=%lu -> fd=%ld errno=%d",
                     pa ? pa->type : 0, pa ? (unsigned long long)pa->config : 0,
                     pid, cpu, group_fd, flags, ret, ret < 0 ? saved_errno : 0);
            errno = saved_errno;
            return ret;
        }
        return real_syscall(number, a0, a1, a2, a3, a4, a5);
    }

    int cmd = (int)a0;
    union bpf_attr *attr = (union bpf_attr *)a1;
    unsigned int size = (unsigned int)a2;

    /* Pre-call: capture inputs we will need after the call returns.
     * Each capture_* allocates a heap obj_entry we'll insert if fd >= 0. */
    struct obj_entry *pending = NULL;
    if (!in_shim && attr) {
        in_shim = 1;
        switch (cmd) {
        case BPF_PROG_LOAD:
            pending = capture_prog_load(attr);
            break;
        case BPF_MAP_CREATE:
            pending = capture_map_create(attr);
            break;
        case BPF_LINK_CREATE:
            pending = capture_link_create(attr);
            log_line("BPF_LINK_CREATE prog_fd=%u target_fd=%u attach_type=%u "
                     "flags=%u",
                     attr->link_create.prog_fd, attr->link_create.target_fd,
                     attr->link_create.attach_type, attr->link_create.flags);
            break;
        case BPF_LINK_UPDATE:
            on_link_update(attr);
            break;
        case BPF_PROG_ATTACH:
            on_prog_attach(attr);
            break;
        case BPF_RAW_TRACEPOINT_OPEN:
            on_raw_tp_open(attr);
            break;
        default:
            log_line("bpf cmd=%d (%s) size=%u", cmd, bpf_cmd_name(cmd), size);
            break;
        }
        in_shim = 0;
    }

    in_shim = 1;
    long ret = real_syscall(number, a0, a1, a2, a3, a4, a5);
    int saved_errno = errno;

    /* Post-call: if fd-returning call succeeded, attach state and resolve
     * kernel id. If failed, drop pending. */
    uint32_t resolved_id = 0;
    if (pending) {
        if (ret >= 0) {
            pending->fd = (int)ret;
            resolved_id = resolve_kernel_id((int)ret, pending->kind);
            if (pending->kind == OBJ_PROG)
                pending->u.prog.kernel_prog_id = resolved_id;
            else if (pending->kind == OBJ_MAP)
                pending->u.map.kernel_map_id = resolved_id;
            else if (pending->kind == OBJ_LINK)
                pending->u.link.kernel_link_id = resolved_id;
            pthread_mutex_lock(&state_mutex);
            obj_insert(pending);
            pthread_mutex_unlock(&state_mutex);
        } else {
            if (pending->kind == OBJ_PROG) free(pending->u.prog.insns);
            free(pending);
        }
    }
    in_shim = 0;

    if (cmd == BPF_PROG_LOAD)
        log_line("  PROG_LOAD -> fd=%ld errno=%d kernel_prog_id=%u", ret,
                 ret < 0 ? saved_errno : 0, resolved_id);
    else if (cmd == BPF_LINK_CREATE)
        log_line("  LINK_CREATE -> fd=%ld errno=%d kernel_link_id=%u", ret,
                 ret < 0 ? saved_errno : 0, resolved_id);
    else if (cmd == BPF_LINK_UPDATE)
        log_line("  LINK_UPDATE -> ret=%ld errno=%d", ret,
                 ret < 0 ? saved_errno : 0);
    else if (cmd == BPF_MAP_CREATE)
        log_line("  MAP_CREATE -> fd=%ld errno=%d kernel_map_id=%u", ret,
                 ret < 0 ? saved_errno : 0, resolved_id);

    errno = saved_errno;
    return ret;
}

/* Intercept ioctl(2) to catch PERF_EVENT_IOC_SET_BPF on perf_event fds. */
int ioctl(int fd, unsigned long request, ...) {
    void *arg;
    va_list ap;
    va_start(ap, request);
    arg = va_arg(ap, void *);
    va_end(ap);

    if (!in_shim) {
        if (request == PERF_EVENT_IOC_SET_BPF) {
            int prog_fd = (int)(intptr_t)arg;
            log_line("PERF_EVENT_IOC_SET_BPF event_fd=%d prog_fd=%d", fd,
                     prog_fd);
        } else if (request == PERF_EVENT_IOC_ENABLE) {
            log_line("PERF_EVENT_IOC_ENABLE event_fd=%d", fd);
        } else if (request == PERF_EVENT_IOC_DISABLE) {
            log_line("PERF_EVENT_IOC_DISABLE event_fd=%d", fd);
        }
    }

    in_shim = 1;
    int ret = real_ioctl(fd, request, arg);
    int saved_errno = errno;
    in_shim = 0;

    if (request == PERF_EVENT_IOC_SET_BPF) {
        if (ret == 0) {
            pthread_mutex_lock(&state_mutex);
            struct obj_entry *e = obj_find(fd);
            if (e && e->kind == OBJ_PERF)
                e->u.perf.attached_prog_fd = (int)(intptr_t)arg;
            pthread_mutex_unlock(&state_mutex);
        }
        log_line("  PERF_EVENT_IOC_SET_BPF -> ret=%d errno=%d", ret,
                 ret < 0 ? saved_errno : 0);
    }

    errno = saved_errno;
    return ret;
}

/* Intercept close(2): release the table entry if any. */
int close(int fd) {
    if (!in_shim && fd >= 0) {
        pthread_mutex_lock(&state_mutex);
        obj_remove(fd);
        pthread_mutex_unlock(&state_mutex);
    }
    in_shim = 1;
    int ret = real_close(fd);
    int saved_errno = errno;
    in_shim = 0;
    errno = saved_errno;
    return ret;
}

/* Intercept dup2(2): duplicate table entry to the new fd. */
int dup2(int oldfd, int newfd) {
    in_shim = 1;
    int ret = real_dup2(oldfd, newfd);
    int saved_errno = errno;
    in_shim = 0;
    if (ret >= 0 && !in_shim) {
        pthread_mutex_lock(&state_mutex);
        struct obj_entry *src = obj_find(oldfd);
        if (src) {
            struct obj_entry *copy =
                (struct obj_entry *)calloc(1, sizeof(*copy));
            if (copy) {
                *copy = *src;
                copy->fd = ret;
                copy->next = NULL;
                if (copy->kind == OBJ_PROG && src->u.prog.insns) {
                    size_t bytes = (size_t)src->u.prog.insn_cnt *
                                   sizeof(struct bpf_insn);
                    copy->u.prog.insns = (struct bpf_insn *)malloc(bytes);
                    if (copy->u.prog.insns)
                        memcpy(copy->u.prog.insns, src->u.prog.insns, bytes);
                }
                obj_insert(copy);
            }
        }
        pthread_mutex_unlock(&state_mutex);
    }
    errno = saved_errno;
    return ret;
}

int dup3(int oldfd, int newfd, int flags) {
    in_shim = 1;
    int ret = real_dup3(oldfd, newfd, flags);
    int saved_errno = errno;
    in_shim = 0;
    if (ret >= 0 && !in_shim) {
        pthread_mutex_lock(&state_mutex);
        struct obj_entry *src = obj_find(oldfd);
        if (src) {
            struct obj_entry *copy =
                (struct obj_entry *)calloc(1, sizeof(*copy));
            if (copy) {
                *copy = *src;
                copy->fd = ret;
                copy->next = NULL;
                if (copy->kind == OBJ_PROG && src->u.prog.insns) {
                    size_t bytes = (size_t)src->u.prog.insn_cnt *
                                   sizeof(struct bpf_insn);
                    copy->u.prog.insns = (struct bpf_insn *)malloc(bytes);
                    if (copy->u.prog.insns)
                        memcpy(copy->u.prog.insns, src->u.prog.insns, bytes);
                }
                obj_insert(copy);
            }
        }
        pthread_mutex_unlock(&state_mutex);
    }
    errno = saved_errno;
    return ret;
}

/* SIGUSR1 handler: write a JSON snapshot of all tracked objects. */
static void dump_state_json(void) {
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    char path[512];
    snprintf(path, sizeof(path), "%s/state_%d.json", dir, getpid());
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return;
    FILE *f = fdopen(fd, "w");
    if (!f) {
        real_close(fd);
        return;
    }
    fprintf(f, "{\n  \"pid\": %d,\n  \"objects\": [\n", getpid());
    pthread_mutex_lock(&state_mutex);
    int first = 1;
    for (int b = 0; b < OBJ_TABLE_BUCKETS; b++) {
        for (struct obj_entry *e = obj_table[b]; e; e = e->next) {
            if (!first) fprintf(f, ",\n");
            first = 0;
            const char *kind = "?";
            switch (e->kind) {
            case OBJ_PROG: kind = "prog"; break;
            case OBJ_MAP: kind = "map"; break;
            case OBJ_LINK: kind = "link"; break;
            case OBJ_PERF: kind = "perf_event"; break;
            default: break;
            }
            fprintf(f, "    {\"fd\":%d,\"kind\":\"%s\"", e->fd, kind);
            if (e->kind == OBJ_PROG)
                fprintf(f,
                        ",\"prog_type\":%u,\"name\":\"%s\",\"insn_cnt\":%u,"
                        "\"hash\":\"%016lx\",\"kernel_prog_id\":%u,"
                        "\"bytecode_path\":\"%s\",\"expected_attach\":%u,"
                        "\"attach_btf_id\":%u",
                        e->u.prog.prog_type, e->u.prog.name,
                        e->u.prog.insn_cnt, e->u.prog.hash,
                        e->u.prog.kernel_prog_id, e->u.prog.bytecode_path,
                        e->u.prog.expected_attach_type,
                        e->u.prog.attach_btf_id);
            else if (e->kind == OBJ_MAP)
                fprintf(f,
                        ",\"map_type\":%u,\"name\":\"%s\","
                        "\"key_size\":%u,\"value_size\":%u,"
                        "\"max_entries\":%u,\"kernel_map_id\":%u",
                        e->u.map.map_type, e->u.map.name, e->u.map.key_size,
                        e->u.map.value_size, e->u.map.max_entries,
                        e->u.map.kernel_map_id);
            else if (e->kind == OBJ_LINK)
                fprintf(f,
                        ",\"prog_fd\":%u,\"target_fd\":%u,"
                        "\"attach_type\":%u,\"kernel_link_id\":%u",
                        e->u.link.prog_fd, e->u.link.target_fd,
                        e->u.link.attach_type, e->u.link.kernel_link_id);
            else if (e->kind == OBJ_PERF)
                fprintf(f,
                        ",\"type\":%u,\"config\":%llu,\"pid\":%d,\"cpu\":%d,"
                        "\"attached_prog_fd\":%d",
                        e->u.perf.type,
                        (unsigned long long)e->u.perf.config, e->u.perf.pid,
                        e->u.perf.cpu, e->u.perf.attached_prog_fd);
            fprintf(f, "}");
        }
    }
    pthread_mutex_unlock(&state_mutex);
    fprintf(f, "\n  ]\n}\n");
    fclose(f);
    log_line("state dumped to %s", path);
}

static void sigusr1_handler(int sig) {
    (void)sig;
    dump_state_json();
}

/* Worker thread: every BPFREJIT_SHIM_PERIODIC_DUMP_MS milliseconds, write
 * the state JSON. Default off (0 = disabled). Set the env var to enable.
 * This is also the home for the Phase 2 bpfopt+swap pipeline. */
static void *worker_thread(void *arg) {
    (void)arg;
    const char *ms_env = getenv("BPFREJIT_SHIM_PERIODIC_DUMP_MS");
    int ms = ms_env ? atoi(ms_env) : 0;
    if (ms <= 0)
        return NULL;
    /* Block all signals on this thread so Go-runtime / async-signal-driven
     * apps do not wake nanosleep with EINTR every microsecond. */
    sigset_t mask;
    sigfillset(&mask);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);
    while (1) {
        struct timespec ts, rem;
        ts.tv_sec = ms / 1000;
        ts.tv_nsec = (long)(ms % 1000) * 1000000L;
        /* Loop on EINTR; do not poll-spin. */
        while (nanosleep(&ts, &rem) == -1 && errno == EINTR)
            ts = rem;
        dump_state_json();
    }
    return NULL;
}
