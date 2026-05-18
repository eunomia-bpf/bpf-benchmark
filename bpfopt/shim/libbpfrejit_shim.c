/*
 * libbpfrejit_shim.so — LD_PRELOAD interception + state shim for BPF apps.
 *
 * Intercept layer wraps syscall(2)/ioctl(2)/perf_event_open(2)/close(2) in
 * libc. For each observed BPF/perf control-plane call: log, then pass through.
 *
 * State tables (keyed by app-side fd) record every BPF object whose fd lives
 * in this process: programs, maps, links, perf_event handles. Each entry
 * records the kernel-side id (resolved via BPF_OBJ_GET_INFO_BY_FD), the
 * original load attr (for prog), and the attach relationship (for link /
 * perf_event). close() maintains table consistency.
 *
 * Per-pid socket implements daemon-protocol RPCs (list_progs / execute_step /
 * dump_state). Optimization is runner-driven: the runner reads its yaml,
 * resolves a shell command, sends it via execute_step; the shim substitutes
 * ${VAR}s and runs /bin/sh -c.
 *
 * Usage:
 *   gcc -shared -fPIC -O2 libbpfrejit_shim.c -o libbpfrejit_shim.so -ldl -lpthread
 *   BPFREJIT_SHIM_LOG=/tmp/shim.log LD_PRELOAD=./libbpfrejit_shim.so <app>
 */

#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/perf_event.h>
#include <pthread.h>
#include <signal.h>
#include <spawn.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
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

extern char **environ;

#ifndef SYS_perf_event_open
#define SYS_perf_event_open 298 /* x86_64 */
#endif

#ifndef PERF_EVENT_IOC_SET_BPF
#define PERF_EVENT_IOC_SET_BPF _IOW('$', 8, __u32)
#endif

#ifndef PERF_EVENT_IOC_QUERY_BPF
#define PERF_EVENT_IOC_QUERY_BPF _IOWR('$', 10, struct perf_event_query_bpf *)
#endif

/* Resolved real symbols. Filled at shim_init() but every interceptor must
 * also handle the case where the symbol is still NULL — heavy C++ runtime
 * apps (katran's folly/grpc) call syscall(3) from their own constructors,
 * which can race ahead of our constructor depending on dynamic init order. */
static long (*real_syscall)(long, ...);
static int (*real_ioctl)(int, unsigned long, ...);
static int (*real_close)(int);

/* Resolve any not-yet-resolved real symbols. Called at the top of every
 * interceptor so that apps which call syscall(3)/ioctl(2)/close(2) from a
 * constructor that runs before ours (folly/grpc/etc.) don't see NULL. */
static void ensure_syms_resolved(void) {
    if (!real_syscall)
        real_syscall = (long (*)(long, ...))dlsym(RTLD_NEXT, "syscall");
    if (!real_ioctl)
        real_ioctl = (int (*)(int, unsigned long, ...))dlsym(RTLD_NEXT, "ioctl");
    if (!real_close)
        real_close = (int (*)(int))dlsym(RTLD_NEXT, "close");
}

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
    /* License string (deep copy from attr->license user pointer). Needed for
     * candidate BPF_PROG_LOAD(log_level=2) verifier-state probes. */
    char license[64];
    /* Per-prog execute_step state: lazily filled on first call. */
    int canonicalized;          /* 1 once --canonicalize-map-refs has run */
    int step_seq;               /* incremented every successful execute_step */
    /* Per-prog flag: did we already run `bpfopt --canonicalize-map-refs`?
     * Map fd lists are not cached per-prog — they come from a fresh
     * obj_table snapshot at execute_step time. */
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

static void free_prog_data(struct prog_data *p) {
    free(p->insns);
    free(p->used_map_ids);
    free(p->used_map_types);
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
            if (dead->kind == OBJ_PROG) free_prog_data(&dead->u.prog);
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
            if (dead->kind == OBJ_PROG) free_prog_data(&dead->u.prog);
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

/* Map BPF_PROG_TYPE_* enum to bpfopt's --prog-type short name. Used in log
 * lines and as the ${PROG_TYPE} variable when substituting runner-supplied
 * command templates. */
static const char *prog_type_short_name(uint32_t t) {
    switch (t) {
    case BPF_PROG_TYPE_SOCKET_FILTER: return "socket_filter";
    case BPF_PROG_TYPE_KPROBE: return "kprobe";
    case BPF_PROG_TYPE_SCHED_CLS: return "sched_cls";
    case BPF_PROG_TYPE_SCHED_ACT: return "sched_act";
    case BPF_PROG_TYPE_TRACEPOINT: return "tracepoint";
    case BPF_PROG_TYPE_XDP: return "xdp";
    case BPF_PROG_TYPE_PERF_EVENT: return "perf_event";
    case BPF_PROG_TYPE_CGROUP_SKB: return "cgroup_skb";
    case BPF_PROG_TYPE_CGROUP_SOCK: return "cgroup_sock";
    case BPF_PROG_TYPE_RAW_TRACEPOINT: return "raw_tracepoint";
    case BPF_PROG_TYPE_TRACING: return "tracing";
    case BPF_PROG_TYPE_LSM: return "lsm";
    default: return "socket_filter";
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
             attr->prog_type, prog_type_short_name(attr->prog_type), name,
             insn_cnt, hash, (const char *)(uintptr_t)attr->license,
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
    /* Deep-copy license (app-owned user string, lifetime unknown after the
     * call returns). Required to later issue candidate BPF_PROG_LOAD calls
     * for verifier-state capture. */
    const char *lic = (const char *)(uintptr_t)attr->license;
    if (lic) {
        size_t n = strnlen(lic, sizeof(e->u.prog.license) - 1);
        memcpy(e->u.prog.license, lic, n);
        e->u.prog.license[n] = 0;
    }
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

static void *worker_thread(void *arg);  /* forward decl */
static void *socket_thread(void *arg);  /* forward decl */

__attribute__((constructor)) static void shim_init(void) {
    real_syscall = dlsym(RTLD_NEXT, "syscall");
    real_ioctl = dlsym(RTLD_NEXT, "ioctl");
    real_close = dlsym(RTLD_NEXT, "close");

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

    /* Periodic dump worker, if enabled by env. */
    pthread_t tid;
    pthread_create(&tid, NULL, worker_thread, NULL);
    pthread_detach(tid);

    /* Socket server thread — per-pid daemon-compatible socket.
     * Disable by setting BPFREJIT_SHIM_SOCK_DISABLE=1. */
    if (!getenv("BPFREJIT_SHIM_SOCK_DISABLE")) {
        pthread_t stid;
        pthread_create(&stid, NULL, socket_thread, NULL);
        pthread_detach(stid);
    }
}

/* Intercept syscall(2). */
long syscall(long number, ...) {
    /* Forward 6 long args verbatim — kernel-side ABI takes <= 6, reading
     * unused-but-not-passed va_args is UB but practically safe on x86_64
     * because syscall(2) callers always pass through the same register
     * convention. We do not introspect args for non-bpf syscalls. */
    ensure_syms_resolved();
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
            log_line("bpf cmd=%d size=%u", cmd, size);
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
    ensure_syms_resolved();
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
    ensure_syms_resolved();
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

/* Write a JSON snapshot of all tracked objects.
 * Invoked by the periodic worker thread (BPFREJIT_SHIM_PERIODIC_DUMP_MS) and
 * by the `dump_state` socket RPC. */
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

/* =========================================================================
 * Socket server thread — Plan A: per-pid socket reusing daemon JSON protocol.
 *
 * Path: $BPFREJIT_SHIM_SOCK_DIR/shim-<pid>.sock (default /var/run/bpfrejit/)
 *
 * Protocol (line-delimited JSON, one request per line, one response per line,
 * same shape as the existing bpfrejit-daemon at daemon/src/server.rs):
 *
 *   request:  {"cmd": "list_progs"}
 *   response: {"ok": true, "progs": [{"id": <kernel_prog_id>, "name": "...",
 *               "type": <prog_type>, "insn_cnt": ..., "hash": "...",
 *               "bytecode_path": "..."}]}
 *
 *   request:  {"cmd": "optimize", "enabled_passes": ["noop"]}
 *   response: {"ok": true, "passes": ["noop"]}
 *             (invokes bpfopt on all tracked progs; result via shim log)
 *
 *   request:  {"cmd": "dump_state"}
 *   response: {"ok": true, "path": "/tmp/dumps/state_<pid>.json"}
 *
 * Unknown cmd → {"ok": false, "error": "unknown cmd"}.
 *
 * Parsing is intentionally a tiny ad-hoc tokenizer; it accepts the field
 * subset listed above and ignores everything else. ===================== */

static int unix_socket_listen(const char *path) {
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0)
        return -1;
    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    snprintf(addr.sun_path, sizeof(addr.sun_path), "%s", path);
    unlink(path);
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        real_close(fd);
        return -1;
    }
    if (listen(fd, 8) < 0) {
        real_close(fd);
        return -1;
    }
    return fd;
}

/* Extract a quoted string after `"key":` with JSON escape decoding. Handles
 * \", \\, \n, \t, \r, \/, \b, \f, \uXXXX (BMP only — non-BMP unsupported,
 * shell commands are ASCII in practice). Returns 1 on success and writes up
 * to out_sz-1 bytes + NUL to out. */
static int json_get_str(const char *json, const char *key, char *out,
                        size_t out_sz) {
    char needle[64];
    snprintf(needle, sizeof(needle), "\"%s\"", key);
    const char *p = strstr(json, needle);
    if (!p)
        return 0;
    p = strchr(p + strlen(needle), ':');
    if (!p)
        return 0;
    p++;
    while (*p == ' ' || *p == '\t')
        p++;
    if (*p != '"')
        return 0;
    p++;
    size_t i = 0;
    while (*p && *p != '"' && i + 1 < out_sz) {
        if (*p == '\\' && p[1]) {
            char c = 0;
            switch (p[1]) {
            case '"': c = '"'; break;
            case '\\': c = '\\'; break;
            case '/': c = '/'; break;
            case 'b': c = '\b'; break;
            case 'f': c = '\f'; break;
            case 'n': c = '\n'; break;
            case 'r': c = '\r'; break;
            case 't': c = '\t'; break;
            case 'u': {
                /* \uXXXX — accept ASCII subset; non-ASCII encoded as raw 0
                 * which would break the command, but shell commands are
                 * ASCII in practice. */
                if (p[2] && p[3] && p[4] && p[5]) {
                    unsigned v = 0;
                    for (int k = 0; k < 4; k++) {
                        char h = p[2 + k];
                        v <<= 4;
                        if (h >= '0' && h <= '9') v |= (h - '0');
                        else if (h >= 'a' && h <= 'f') v |= 10 + (h - 'a');
                        else if (h >= 'A' && h <= 'F') v |= 10 + (h - 'A');
                        else { v = 0; break; }
                    }
                    out[i++] = (char)(v & 0xff);
                    p += 6;
                    continue;
                }
                c = 'u';
                break;
            }
            default: c = p[1]; break;
            }
            out[i++] = c;
            p += 2;
            continue;
        }
        out[i++] = *p++;
    }
    out[i] = 0;
    return 1;
}

static void emit_list_progs(int cli) {
    pthread_mutex_lock(&state_mutex);
    /* Estimate buffer size: ~256 bytes per prog. */
    size_t cap = 4096;
    char *buf = (char *)malloc(cap);
    if (!buf) {
        pthread_mutex_unlock(&state_mutex);
        return;
    }
    size_t len = 0;
    len += snprintf(buf + len, cap - len, "{\"ok\":true,\"progs\":[");
    int first = 1;
    for (int b = 0; b < OBJ_TABLE_BUCKETS; b++) {
        for (struct obj_entry *e = obj_table[b]; e; e = e->next) {
            if (e->kind != OBJ_PROG)
                continue;
            if (cap - len < 512) {
                cap *= 2;
                char *nb = (char *)realloc(buf, cap);
                if (!nb)
                    break;
                buf = nb;
            }
            len += snprintf(
                buf + len, cap - len,
                "%s{\"id\":%u,\"name\":\"%s\",\"type\":%u,\"insn_cnt\":%u,"
                "\"hash\":\"%016lx\",\"bytecode_path\":\"%s\"}",
                first ? "" : ",", e->u.prog.kernel_prog_id, e->u.prog.name,
                e->u.prog.prog_type, e->u.prog.insn_cnt, e->u.prog.hash,
                e->u.prog.bytecode_path);
            first = 0;
        }
    }
    pthread_mutex_unlock(&state_mutex);
    len += snprintf(buf + len, cap - len, "]}\n");
    if (write(cli, buf, len) < 0) { /* best effort */ }
    free(buf);
}

/* Substitute ${VAR} occurrences in `in` to `out`. Vars known: PROG_ID,
 * PROG_TYPE, INPUT, OUTPUT, REPORT, WORKDIR, TARGET. Unknown vars stay as
 * literal ${VAR} (so /bin/sh's own expansion can still see them via env). */
static void substitute_vars(char *out, size_t out_sz, const char *in,
                            const char *vars[][2], size_t n_vars) {
    size_t o = 0;
    for (size_t i = 0; in[i] && o + 1 < out_sz;) {
        if (in[i] == '$' && in[i + 1] == '{') {
            const char *end = strchr(in + i + 2, '}');
            if (end) {
                size_t name_len = end - (in + i + 2);
                int replaced = 0;
                for (size_t k = 0; k < n_vars; k++) {
                    if (strlen(vars[k][0]) == name_len &&
                        strncmp(in + i + 2, vars[k][0], name_len) == 0) {
                        size_t rl = strlen(vars[k][1]);
                        if (o + rl >= out_sz)
                            rl = out_sz - 1 - o;
                        memcpy(out + o, vars[k][1], rl);
                        o += rl;
                        replaced = 1;
                        break;
                    }
                }
                i = end - in + 1;
                if (!replaced) {
                    /* leave ${VAR} literal so shell can substitute */
                    size_t lit_len = name_len + 3;
                    if (o + lit_len >= out_sz)
                        lit_len = out_sz - 1 - o;
                    memcpy(out + o, in + i - lit_len, lit_len);
                    o += lit_len;
                }
                continue;
            }
        }
        out[o++] = in[i++];
    }
    out[o] = 0;
}

/* --- daemon-parity helpers (MAP_IDS / MAP_VALUES / canonicalize / VERIFIER_STATES) --- */

/* Mirror of daemon's needs_bpftool_map_dump. */
static int map_type_needs_dump(uint32_t t) {
    return t == BPF_MAP_TYPE_HASH || t == BPF_MAP_TYPE_ARRAY ||
           t == BPF_MAP_TYPE_PERCPU_ARRAY || t == BPF_MAP_TYPE_LRU_HASH ||
           t == BPF_MAP_TYPE_LPM_TRIE || t == BPF_MAP_TYPE_ARRAY_OF_MAPS ||
           t == BPF_MAP_TYPE_HASH_OF_MAPS;
}

/* Snapshot all currently-open map fds from the shim's state table. We
 * already intercept BPF_MAP_CREATE / BPF_MAP_GET_FD_BY_ID and track every
 * map fd the loader has; that's the authoritative source. No bytecode
 * inspection, no kernel queries.
 *
 * Caller frees both arrays. Caller must hold state_mutex. */
static int snapshot_map_fds_from_obj_table(uint32_t **fds_out,
                                           uint32_t **types_out,
                                           uint32_t *n_out) {
    uint32_t cap = 16;
    uint32_t *fds = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *types = (uint32_t *)calloc(cap, sizeof(uint32_t));
    if (!fds || !types) { free(fds); free(types); return -1; }
    uint32_t n = 0;
    for (int b = 0; b < OBJ_TABLE_BUCKETS; b++) {
        for (struct obj_entry *e = obj_table[b]; e; e = e->next) {
            if (e->kind != OBJ_MAP) continue;
            if (n == cap) {
                cap *= 2;
                uint32_t *nf = (uint32_t *)realloc(fds, cap * sizeof(uint32_t));
                uint32_t *nt = (uint32_t *)realloc(types, cap * sizeof(uint32_t));
                if (!nf || !nt) { free(nf ? nf : fds); free(nt ? nt : types); return -1; }
                fds = nf; types = nt;
            }
            fds[n] = (uint32_t)e->fd;
            types[n] = e->u.map.map_type;
            n++;
        }
    }
    *fds_out = fds; *types_out = types; *n_out = n;
    return 0;
}

static void format_map_ids_csv(uint32_t *ids, uint32_t n, char *out, size_t out_sz) {
    if (n == 0 || !ids) { snprintf(out, out_sz, "0"); return; }
    size_t o = 0;
    for (uint32_t i = 0; i < n && o + 16 < out_sz; i++)
        o += snprintf(out + o, out_sz - o, "%s%u", i ? "," : "", ids[i]);
}

/* Run `bpftool <args...>` redirecting stdout to `out_path`. Returns 0 on
 * exit 0, else -1. Args must be NULL-terminated. */
static int run_bpftool_to_file(char *const argv[], const char *out_path) {
    posix_spawn_file_actions_t fa;
    if (posix_spawn_file_actions_init(&fa) != 0) return -1;
    posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, out_path,
                                     O_WRONLY | O_CREAT | O_TRUNC, 0644);
    /* /dev/null for stderr to keep the log tidy; bpftool warnings can be
     * inspected via the saved JSON file if missing. */
    posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, "/dev/null",
                                     O_WRONLY, 0);
    pid_t pid;
    int rc = posix_spawnp(&pid, argv[0], &fa, NULL, argv, environ);
    posix_spawn_file_actions_destroy(&fa);
    if (rc != 0) return -1;
    int st = 0;
    waitpid(pid, &st, 0);
    return (WIFEXITED(st) && WEXITSTATUS(st) == 0) ? 0 : -1;
}

/* Write per-map snapshots into map_values_dir. File names use the loader-fd
 * token (so they line up with bpfopt's --map-ids CSV); bpftool itself wants
 * the kernel map id, so we translate fd → kernel id on the spot via
 * BPF_OBJ_GET_INFO_BY_FD. Skip the dump for types where bpftool produces
 * nothing useful (PROG_ARRAY / RINGBUF / ...). */
static void write_map_snapshots(const char *map_values_dir,
                                const uint32_t *loader_fds,
                                const uint32_t *types, uint32_t n) {
    mkdir(map_values_dir, 0755);
    for (uint32_t i = 0; i < n; i++) {
        /* bpftool wants a kernel map id, not a process fd. Inline the
         * fd → kernel-id resolution here; we don't store kernel ids in
         * obj_table so this is the only place we ever look them up. */
        struct bpf_map_info info;
        memset(&info, 0, sizeof(info));
        union bpf_attr ia = {0};
        ia.info.bpf_fd = loader_fds[i];
        ia.info.info_len = sizeof(info);
        ia.info.info = (uintptr_t)&info;
        long r = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia));
        if (r < 0 || info.id == 0) continue; /* fd closed since snapshot */
        char id_str[16];
        snprintf(id_str, sizeof(id_str), "%u", info.id);
        char show_path[512], dump_path[512];
        snprintf(show_path, sizeof(show_path), "%s/map-%u.show.json",
                 map_values_dir, loader_fds[i]);
        char *const show_argv[] = {"bpftool", "-j", "map", "show", "id",
                                   id_str, NULL};
        (void)run_bpftool_to_file(show_argv, show_path);
        if (!map_type_needs_dump(types[i])) continue;
        snprintf(dump_path, sizeof(dump_path), "%s/map-%u.dump.json",
                 map_values_dir, loader_fds[i]);
        char *const dump_argv[] = {"bpftool", "-j", "map", "dump", "id",
                                   id_str, NULL};
        (void)run_bpftool_to_file(dump_argv, dump_path);
    }
}

/* Invoke `bpfopt --canonicalize-map-refs ...`. Writes canonicalized bytecode
 * to out_path. Captures stdout+stderr into `log_path` (if non-NULL) so a
 * caller can surface the failure reason. Returns 0 on success. */
static int run_canonicalize(const char *input_path, const char *out_path,
                            const char *target_json, const char *map_ids_csv,
                            const char *log_path) {
    char *const argv[] = {
        "bpfopt", "--canonicalize-map-refs",
        "--input", (char *)input_path,
        "--output", (char *)out_path,
        "--map-ids", (char *)map_ids_csv,
        "--target", (char *)target_json,
        "--target-output", (char *)target_json,
        NULL};
    /* Strip LD_PRELOAD so the bpfopt child doesn't re-attach the shim. */
    size_t n_env = 0;
    while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    size_t j = 0;
    for (size_t i = 0; clean_env && i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    if (clean_env) clean_env[j] = NULL;
    posix_spawn_file_actions_t fa;
    int fa_inited = 0;
    if (log_path && posix_spawn_file_actions_init(&fa) == 0) {
        fa_inited = 1;
        posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, log_path,
                                         O_WRONLY | O_CREAT | O_TRUNC, 0644);
        posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, log_path,
                                         O_WRONLY | O_APPEND, 0);
    }
    pid_t pid;
    int rc = posix_spawnp(&pid, "bpfopt", fa_inited ? &fa : NULL, NULL, argv,
                          clean_env ? clean_env : environ);
    if (fa_inited) posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0) return -1;
    int st = 0;
    waitpid(pid, &st, 0);
    return (WIFEXITED(st) && WEXITSTATUS(st) == 0) ? 0 : -1;
}

/* Issue a stock BPF_PROG_LOAD with the pass-output bytecode + log_level=2 to
 * capture verifier states. Writes the verifier log to log_path. The probe fd
 * is closed; we never run the probe program. Failures fall through silently
 * (the log path will exist with whatever the kernel wrote before bailing). */
static void capture_verifier_states(const struct prog_data *p,
                                    const char *bytecode_path,
                                    const char *log_path) {
    int bfd = open(bytecode_path, O_RDONLY);
    if (bfd < 0) return;
    struct stat st;
    if (fstat(bfd, &st) != 0 || st.st_size <= 0 ||
        (st.st_size % (off_t)sizeof(struct bpf_insn)) != 0) {
        real_close(bfd);
        return;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) { real_close(bfd); return; }
    ssize_t rd = read(bfd, insns, bytes);
    real_close(bfd);
    if (rd != (ssize_t)bytes) { free(insns); return; }

    /* Reconstruct fd_array — required because canonicalize rewrote
     * BPF_PSEUDO_MAP_FD refs into BPF_PSEUDO_MAP_IDX. The token in
     * used_map_ids is a loader fd; we run inside the loader process so we
     * can dup it directly. If the loader has since closed the fd, fall back
     * to BPF_OBJ_GET_INFO_BY_FD + BPF_MAP_GET_FD_BY_ID, but that path needs
     * a kernel id we no longer cache — accept fd_array[i] = -1 in that case
     * (rare; verifier will reject and the candidate load fails cleanly). */
    int *fd_array = NULL;
    if (p->nr_map_ids > 0) {
        fd_array = (int *)calloc(p->nr_map_ids, sizeof(int));
        if (!fd_array) { free(insns); return; }
        for (uint32_t i = 0; i < p->nr_map_ids; i++) {
            int loader_fd = (int)p->used_map_ids[i];
            int dup_fd = (loader_fd >= 0) ? dup(loader_fd) : -1;
            fd_array[i] = dup_fd;
        }
    }

    /* 16 MB log buffer matches daemon's REJIT_VERBOSE_LOG_BUF_SIZE. */
    size_t log_buf_size = 16 * 1024 * 1024;
    char *log_buf = (char *)malloc(log_buf_size);
    if (!log_buf) {
        free(insns);
        if (fd_array) {
            for (uint32_t i = 0; i < p->nr_map_ids; i++)
                if (fd_array[i] >= 0) real_close(fd_array[i]);
            free(fd_array);
        }
        return;
    }
    log_buf[0] = 0;

    union bpf_attr a;
    memset(&a, 0, sizeof(a));
    a.prog_type = p->prog_type;
    a.insns = (uintptr_t)insns;
    a.insn_cnt = (uint32_t)(bytes / sizeof(struct bpf_insn));
    a.license = (uintptr_t)p->license;
    a.expected_attach_type = p->expected_attach_type;
    a.attach_btf_id = p->attach_btf_id;
    a.prog_flags = p->load_attr.prog_flags;
    a.kern_version = p->load_attr.kern_version;
    a.log_level = 2;
    a.log_buf = (uintptr_t)log_buf;
    a.log_size = (uint32_t)log_buf_size;
    if (fd_array) {
        a.fd_array = (uintptr_t)fd_array;
    }

    long pfd = real_syscall(SYS_bpf, BPF_PROG_LOAD, &a, sizeof(a));
    /* Whether the verifier accepted or rejected, the log was populated. */
    int saved_errno = errno;
    size_t lg = strnlen(log_buf, log_buf_size);
    int wfd = open(log_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (wfd >= 0) {
        (void)!write(wfd, log_buf, lg);
        real_close(wfd);
    }
    if (pfd >= 0) real_close((int)pfd);
    if (fd_array) {
        for (uint32_t i = 0; i < p->nr_map_ids; i++)
            if (fd_array[i] >= 0) real_close(fd_array[i]);
        free(fd_array);
    }
    free(log_buf);
    free(insns);
    errno = saved_errno;
}

/* Base64-encode `bytes` into a heap string (NUL-terminated). Caller frees. */
static char *base64_encode_alloc(const uint8_t *bytes, size_t n) {
    static const char tbl[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t out_n = ((n + 2) / 3) * 4;
    char *out = (char *)malloc(out_n + 1);
    if (!out) return NULL;
    size_t o = 0;
    for (size_t i = 0; i < n; i += 3) {
        uint32_t v = (uint32_t)bytes[i] << 16;
        v |= (i + 1 < n) ? ((uint32_t)bytes[i + 1] << 8) : 0;
        v |= (i + 2 < n) ? (uint32_t)bytes[i + 2] : 0;
        out[o++] = tbl[(v >> 18) & 0x3f];
        out[o++] = tbl[(v >> 12) & 0x3f];
        out[o++] = (i + 1 < n) ? tbl[(v >> 6) & 0x3f] : '=';
        out[o++] = (i + 2 < n) ? tbl[v & 0x3f] : '=';
    }
    out[o] = 0;
    return out;
}

/* Tar a workdir into base64 and return the encoded string. Caller frees.
 * Uses /bin/tar via posix_spawnp + a temp file. */
static char *tar_workdir_b64(const char *workdir) {
    char tar_path[320];
    snprintf(tar_path, sizeof(tar_path), "%s.tar.gz", workdir);
    char *const argv[] = {"tar", "-czf", tar_path, "-C", "/", (char *)(workdir + 1), NULL};
    posix_spawn_file_actions_t fa;
    if (posix_spawn_file_actions_init(&fa) != 0) return NULL;
    posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, "/dev/null", O_WRONLY, 0);
    posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, "/dev/null", O_WRONLY, 0);
    pid_t pid;
    int rc = posix_spawnp(&pid, "tar", &fa, NULL, argv, environ);
    posix_spawn_file_actions_destroy(&fa);
    if (rc != 0) return NULL;
    int st = 0;
    waitpid(pid, &st, 0);
    if (!(WIFEXITED(st) && WEXITSTATUS(st) == 0)) return NULL;
    int fd = open(tar_path, O_RDONLY);
    if (fd < 0) return NULL;
    struct stat sb;
    if (fstat(fd, &sb) != 0 || sb.st_size <= 0) { real_close(fd); return NULL; }
    uint8_t *buf = (uint8_t *)malloc((size_t)sb.st_size);
    if (!buf) { real_close(fd); return NULL; }
    ssize_t rd = read(fd, buf, (size_t)sb.st_size);
    real_close(fd);
    unlink(tar_path);
    if (rd != sb.st_size) { free(buf); return NULL; }
    char *b64 = base64_encode_alloc(buf, (size_t)rd);
    free(buf);
    return b64;
}

/* execute_step — daemon-style RPC. Runner sends a pre-resolved shell command
 * (read from runner/config/passes/<pass>/default.yaml), shim substitutes
 * shim-owned vars and runs /bin/sh -c verbatim. Mirrors daemon's contract at
 * daemon/src/commands.rs:execute_one + daemon/src/server.rs:execute_plan.
 *
 *   request:  {"cmd":"execute_step","prog_id":<u32>,"command":"<sh>",
 *              "step_seq":<int optional>}
 *   response: {"ok":<bool>,"exit_code":<int>,"output":"<path>","report":"<path>",
 *              "bpfopt_ms":<u64>,"program":{...},"workdir_tar_b64":"..."}
 */
static void emit_execute_step(int cli, const char *json) {
    char prog_id_str[32] = {0};
    char command[4096] = {0};
    const char *p = strstr(json, "\"prog_id\"");
    if (p && (p = strchr(p, ':'))) {
        p++;
        while (*p == ' ' || *p == '\t' || *p == '"') p++;
        size_t i = 0;
        while ((*p >= '0' && *p <= '9') && i + 1 < sizeof(prog_id_str))
            prog_id_str[i++] = *p++;
        prog_id_str[i] = 0;
    }
    if (!json_get_str(json, "command", command, sizeof(command)) ||
        !prog_id_str[0]) {
        dprintf(cli, "{\"ok\":false,\"error\":\"missing prog_id or command\"}\n");
        return;
    }
    uint32_t want_id = (uint32_t)strtoul(prog_id_str, NULL, 10);

    /* Snapshot of prog state under lock — fields we read are stable enough
     * to copy out, but per-prog mutable state (canonicalized flag, step_seq,
     * used_map_ids array) must be updated back into the entry below. */
    char original_bc[256] = {0}, prog_type_name[32] = "socket_filter";
    char prog_name[17] = {0};
    uint32_t prog_type_num = 0;
    int found = 0;
    pthread_mutex_lock(&state_mutex);
    struct prog_data *pd = NULL;
    for (int b = 0; b < OBJ_TABLE_BUCKETS && !pd; b++) {
        for (struct obj_entry *e = obj_table[b]; e; e = e->next) {
            if (e->kind == OBJ_PROG && e->u.prog.kernel_prog_id == want_id) {
                pd = &e->u.prog;
                break;
            }
        }
    }
    if (!pd) {
        /* Surface the set we DO track so the caller can diagnose why discovery
         * and shim state diverged (process re-exec, libbpf fork, prog id
         * raced past OBJ_GET_INFO_BY_FD resolve, etc.). Cap at ~30 ids in the
         * error message to avoid blowing up the JSON line. */
        char tracked[512];
        size_t to = 0;
        int n_listed = 0;
        for (int b = 0; b < OBJ_TABLE_BUCKETS && to + 16 < sizeof(tracked); b++) {
            for (struct obj_entry *e = obj_table[b]; e; e = e->next) {
                if (e->kind != OBJ_PROG) continue;
                if (n_listed >= 30) goto done;
                to += snprintf(tracked + to, sizeof(tracked) - to, "%s%u",
                               n_listed ? "," : "", e->u.prog.kernel_prog_id);
                n_listed++;
            }
        }
done:
        tracked[to] = 0;
        pthread_mutex_unlock(&state_mutex);
        dprintf(cli,
                "{\"ok\":false,\"error\":\"prog_id %u not tracked by shim "
                "pid=%d; tracked=[%s] (n=%d)\"}\n",
                want_id, getpid(), tracked, n_listed);
        return;
    }
    snprintf(original_bc, sizeof(original_bc), "%s", pd->bytecode_path);
    snprintf(prog_type_name, sizeof(prog_type_name), "%s",
             prog_type_short_name(pd->prog_type));
    memcpy(prog_name, pd->name, sizeof(prog_name));
    prog_type_num = pd->prog_type;
	/* Lazy: populate used_map_ids on first execute_step. */
	if (!pd->used_map_ids && pd->nr_map_ids == 0 && pd->kernel_prog_id) {
		if (extract_used_map_fds(pd) != 0) {
			pthread_mutex_unlock(&state_mutex);
			dprintf(cli,
			        "{\"ok\":false,\"error\":\"failed to extract used map fds for prog_id %u\"}\n",
			        want_id);
			return;
		}
	}
    /* Local copies of map metadata so we can drop the lock for slow work. */
    uint32_t nr_maps = pd->nr_map_ids;
    uint32_t *local_ids = NULL, *local_types = NULL;
    if (nr_maps > 0) {
        local_ids = (uint32_t *)calloc(nr_maps, sizeof(uint32_t));
        local_types = (uint32_t *)calloc(nr_maps, sizeof(uint32_t));
        if (local_ids && local_types) {
            memcpy(local_ids, pd->used_map_ids, nr_maps * sizeof(uint32_t));
            memcpy(local_types, pd->used_map_types, nr_maps * sizeof(uint32_t));
        } else {
            free(local_ids); free(local_types);
            local_ids = local_types = NULL;
            nr_maps = 0;
        }
    }
    int canonicalized = pd->canonicalized;
    int step_seq = pd->step_seq;
    /* Take a copy of prog_data needed by verifier-state capture. */
    struct prog_data probe_meta = *pd;
    probe_meta.insns = NULL; /* don't share heap ownership */
    probe_meta.used_map_ids = local_ids;
    probe_meta.used_map_types = local_types;
    probe_meta.nr_map_ids = nr_maps;
    pthread_mutex_unlock(&state_mutex);
    found = 1;
    (void)found;

    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    const char *arch = getenv("BPFREJIT_TARGET_ARCH");
    if (!arch) arch = "x86_64";
    char workdir[280], cur[320], nxt[320], report[320], target_json[320];
    char map_values_dir[320], verifier_log[320];
    snprintf(workdir, sizeof(workdir), "%s/work_%u", dir, want_id);
    mkdir(workdir, 0755);
    snprintf(cur, sizeof(cur), "%s/output.bin", workdir);
    snprintf(nxt, sizeof(nxt), "%s/output.next.bin", workdir);
    snprintf(report, sizeof(report), "%s/report.json", workdir);
    snprintf(target_json, sizeof(target_json), "%s/target.json", workdir);
    snprintf(map_values_dir, sizeof(map_values_dir), "%s/map-values", workdir);

    /* ${TARGET} is a JSON file path (bpfopt --target reads a TargetJson with
     * arch + kinsns map). For the stock-kernel shim path there are no kinsns
     * loaded; emit a minimal target.json with just the arch field. */
    struct stat tst;
    if (stat(target_json, &tst) != 0) {
        int fd = open(target_json, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd >= 0) {
            char buf[64];
            int n = snprintf(buf, sizeof(buf),
                             "{\"arch\":\"%s\",\"kinsns\":{}}\n", arch);
            (void)!write(fd, buf, n);
            close(fd);
        }
    }

    /* Format MAP_IDS CSV — "0" when prog has no maps (matches daemon). */
    char map_ids_csv[1024];
    format_map_ids_csv(local_ids, nr_maps, map_ids_csv, sizeof(map_ids_csv));

    /* First-time setup for this prog:
     *   1. bpfopt --canonicalize-map-refs (in -> cur)
     *   2. bpftool map snapshots into $workdir/map-values
     *   3. mark canonicalized=1, store back
     * Subsequent calls reuse cur as the input. */
    char input_path[320] = {0};
    if (!canonicalized) {
        char canon_log[320];
        snprintf(canon_log, sizeof(canon_log), "%s/canonicalize.log", workdir);
        if (run_canonicalize(original_bc, cur, target_json, map_ids_csv,
                             canon_log) != 0) {
            /* Surface the bpfopt stderr/stdout tail. */
            char err_tail[1024] = {0};
            int lfd = open(canon_log, O_RDONLY);
            if (lfd >= 0) {
                struct stat lst;
                if (fstat(lfd, &lst) == 0 && lst.st_size > 0) {
                    off_t off = lst.st_size > 512 ? lst.st_size - 512 : 0;
                    lseek(lfd, off, SEEK_SET);
                    char raw[513];
                    ssize_t n = read(lfd, raw, sizeof(raw) - 1);
                    if (n > 0) {
                        raw[n] = 0;
                        size_t o = 0;
                        for (ssize_t i = 0; i < n && o + 8 < sizeof(err_tail); i++) {
                            unsigned char c = raw[i];
                            if (c == '"' || c == '\\') {
                                err_tail[o++] = '\\'; err_tail[o++] = c;
                            } else if (c == '\n') {
                                err_tail[o++] = '\\'; err_tail[o++] = 'n';
                            } else if (c >= 0x20) {
                                err_tail[o++] = c;
                            }
                        }
                        err_tail[o] = 0;
                    }
                }
                real_close(lfd);
            }
            dprintf(cli,
                    "{\"ok\":false,\"exit_code\":-1,\"error\":"
                    "\"bpfopt --canonicalize-map-refs failed for prog %u: %s\"}\n",
                    want_id, err_tail);
            free(local_ids); free(local_types);
            return;
        }
        write_map_snapshots(map_values_dir, local_ids, local_types, nr_maps);
        canonicalized = 1;
        pthread_mutex_lock(&state_mutex);
        if (pd) pd->canonicalized = 1;
        pthread_mutex_unlock(&state_mutex);
    }
    snprintf(input_path, sizeof(input_path), "%s", cur);

    /* Two verifier-log paths, matching daemon semantics:
     *   verifier_states_in  -> ${VERIFIER_STATES} for the current step. It
     *      points to the log written by the previous successful step. For
     *      step_seq==0 we use a sentinel path that intentionally does not
     *      exist (`verifier_log_initial.log`); state-producing passes like
     *      `noop` ignore the input, and any pass requiring real states will
     *      surface ENOENT — same contract as the daemon (which also writes
     *      nothing initial).
     *   verifier_log        -> path to write *this* step's states to after
     *      bpfopt succeeds. */
    char verifier_states_in[320];
    if (step_seq == 0)
        snprintf(verifier_states_in, sizeof(verifier_states_in),
                 "%s/verifier_log_initial.log", workdir);
    else
        snprintf(verifier_states_in, sizeof(verifier_states_in),
                 "%s/verifier_log_step%d.log", workdir, step_seq - 1);
    snprintf(verifier_log, sizeof(verifier_log),
             "%s/verifier_log_step%d.log", workdir, step_seq);

    unlink(nxt); /* ensure stale tmp doesn't bleed in */

    const char *vars[10][2] = {
        {"PROG_ID", prog_id_str},
        {"PROG_TYPE", prog_type_name},
        {"INPUT", input_path},
        {"OUTPUT", nxt},
        {"REPORT", report},
        {"WORKDIR", workdir},
        {"TARGET", target_json},
        {"MAP_IDS", map_ids_csv},
        {"MAP_VALUES", map_values_dir},
        {"VERIFIER_STATES", verifier_states_in},
    };
    char resolved[4200];
    substitute_vars(resolved, sizeof(resolved), command, vars, 10);

    /* /bin/sh -c <resolved> with LD_PRELOAD stripped. */
    size_t n_env = 0;
    while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    size_t j = 0;
    for (size_t i = 0; clean_env && i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    if (clean_env) clean_env[j] = NULL;

    /* Redirect bpfopt stdout+stderr to a per-step log file so we can surface
     * its diagnostic output via the JSON response. Daemon callers expect
     * meaningful error text, not a bare exit code. */
    char subproc_log[320];
    snprintf(subproc_log, sizeof(subproc_log), "%s/step%d.log", workdir,
             step_seq);
    char *const argv[] = {"/bin/sh", "-c", resolved, NULL};
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    posix_spawn_file_actions_t fa;
    int fa_inited = 0;
    if (posix_spawn_file_actions_init(&fa) == 0) {
        fa_inited = 1;
        posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, subproc_log,
                                         O_WRONLY | O_CREAT | O_TRUNC, 0644);
        posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, subproc_log,
                                         O_WRONLY | O_APPEND, 0);
    }
    pid_t pid;
    int rc = posix_spawn(&pid, "/bin/sh", fa_inited ? &fa : NULL, NULL, argv,
                         clean_env ? clean_env : environ);
    if (fa_inited) posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0) {
        dprintf(cli, "{\"ok\":false,\"error\":\"spawn failed rc=%d\"}\n", rc);
        free(local_ids); free(local_types);
        return;
    }
    int status = 0;
    waitpid(pid, &status, 0);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    uint64_t bpfopt_ms = (uint64_t)(t1.tv_sec - t0.tv_sec) * 1000ULL +
                         (uint64_t)((t1.tv_nsec - t0.tv_nsec) / 1000000);
    int ok = WIFEXITED(status) && WEXITSTATUS(status) == 0;
    int code = WIFEXITED(status) ? WEXITSTATUS(status) : -1;

    /* Promote nxt -> cur and capture verifier states on a successful step
     * that produced new bytecode. Empty nxt (utility step) keeps cur. */
    struct stat nst;
    uint32_t final_insn_count = probe_meta.insn_cnt;
    if (ok && stat(nxt, &nst) == 0 && nst.st_size > 0) {
        capture_verifier_states(&probe_meta, nxt, verifier_log);
        rename(nxt, cur);
        final_insn_count = (uint32_t)(nst.st_size / sizeof(struct bpf_insn));
        pthread_mutex_lock(&state_mutex);
        if (pd) pd->step_seq = step_seq + 1;
        pthread_mutex_unlock(&state_mutex);
    } else {
        unlink(nxt);
    }

    char *tar_b64 = NULL;
    if (!ok) tar_b64 = tar_workdir_b64(workdir);

    /* On failure, surface the last N bytes of bpfopt stdout+stderr as a
     * JSON-escaped string so the runner can log a useful diagnostic without
     * needing access to the workdir. */
    char err_msg[2048] = {0};
    if (!ok) {
        int lfd = open(subproc_log, O_RDONLY);
        if (lfd >= 0) {
            struct stat lst;
            if (fstat(lfd, &lst) == 0 && lst.st_size > 0) {
                off_t off = lst.st_size > 1024 ? lst.st_size - 1024 : 0;
                lseek(lfd, off, SEEK_SET);
                char raw[1024];
                ssize_t n = read(lfd, raw, sizeof(raw) - 1);
                if (n > 0) {
                    raw[n] = 0;
                    /* JSON-escape: replace ", \, control chars. */
                    size_t o = 0;
                    for (ssize_t i = 0; i < n && o + 8 < sizeof(err_msg); i++) {
                        unsigned char c = raw[i];
                        if (c == '"' || c == '\\') {
                            err_msg[o++] = '\\';
                            err_msg[o++] = c;
                        } else if (c == '\n') {
                            err_msg[o++] = '\\';
                            err_msg[o++] = 'n';
                        } else if (c == '\r') {
                            err_msg[o++] = '\\';
                            err_msg[o++] = 'r';
                        } else if (c == '\t') {
                            err_msg[o++] = '\\';
                            err_msg[o++] = 't';
                        } else if (c >= 0x20) {
                            err_msg[o++] = c;
                        }
                    }
                    err_msg[o] = 0;
                }
            }
            real_close(lfd);
        }
    }

    log_line("execute_step prog_id=%u exit=%d ms=%lu seq=%d output=%s",
             want_id, code, (unsigned long)bpfopt_ms, step_seq, cur);

    /* Build response with daemon-parity fields. */
    size_t cap = 8192 + (tar_b64 ? strlen(tar_b64) : 0);
    char *resp = (char *)malloc(cap);
    if (!resp) {
        dprintf(cli, "{\"ok\":false,\"error\":\"oom building response\"}\n");
        free(tar_b64);
        free(local_ids); free(local_types);
        return;
    }
    size_t roff = 0;
    roff += snprintf(resp + roff, cap - roff,
                     "{\"ok\":%s,\"exit_code\":%d,\"output\":\"%s\","
                     "\"report\":\"%s\",\"bpfopt_ms\":%lu,"
                     "\"program\":{\"prog_id\":%u,\"prog_name\":\"%s\","
                     "\"prog_type\":%u,\"orig_insn_count\":%u,"
                     "\"final_insn_count\":%u}",
                     ok ? "true" : "false", code, cur, report,
                     (unsigned long)bpfopt_ms, want_id, prog_name,
                     prog_type_num, probe_meta.insn_cnt, final_insn_count);
    if (!ok && err_msg[0])
        roff += snprintf(resp + roff, cap - roff, ",\"error\":\"%s\"", err_msg);
    if (tar_b64)
        roff += snprintf(resp + roff, cap - roff,
                         ",\"workdir_tar_b64\":\"%s\"", tar_b64);
    roff += snprintf(resp + roff, cap - roff, "}\n");
    (void)!write(cli, resp, roff);
    free(resp);
    free(tar_b64);
    free(local_ids); free(local_types);
}

static void emit_dump_state(int cli) {
    dump_state_json();
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir)
        dir = "/tmp";
    dprintf(cli, "{\"ok\":true,\"path\":\"%s/state_%d.json\"}\n", dir,
            getpid());
}

static void handle_client(int cli) {
    char buf[8192];
    ssize_t n = read(cli, buf, sizeof(buf) - 1);
    if (n <= 0)
        return;
    buf[n] = 0;
    char cmd[64] = {0};
    if (!json_get_str(buf, "cmd", cmd, sizeof(cmd))) {
        dprintf(cli, "{\"ok\":false,\"error\":\"missing cmd\"}\n");
        return;
    }
    log_line("socket: cmd=%s", cmd);
    if (strcmp(cmd, "list_progs") == 0)
        emit_list_progs(cli);
    else if (strcmp(cmd, "execute_step") == 0)
        emit_execute_step(cli, buf);
    else if (strcmp(cmd, "dump_state") == 0)
        emit_dump_state(cli);
    else
        dprintf(cli, "{\"ok\":false,\"error\":\"unknown cmd: %s\"}\n", cmd);
}

static void *socket_thread(void *arg) {
    (void)arg;
    const char *dir = getenv("BPFREJIT_SHIM_SOCK_DIR");
    if (!dir)
        dir = "/var/run/bpfrejit";
    mkdir(dir, 0755);
    char path[256];
    snprintf(path, sizeof(path), "%s/shim-%d.sock", dir, getpid());
    int srv = unix_socket_listen(path);
    if (srv < 0) {
        /* Fallback to /tmp if the default dir is not writable. */
        snprintf(path, sizeof(path), "/tmp/bpfrejit-shim-%d.sock", getpid());
        srv = unix_socket_listen(path);
        if (srv < 0) {
            log_line("socket: failed to bind, server disabled errno=%d",
                     errno);
            return NULL;
        }
    }
    log_line("socket: listening on %s", path);
    sigset_t mask;
    sigfillset(&mask);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);
    while (1) {
        int cli = accept(srv, NULL, NULL);
        if (cli < 0) {
            if (errno == EINTR)
                continue;
            break;
        }
        handle_client(cli);
        real_close(cli);
    }
    real_close(srv);
    return NULL;
}

/* Worker thread: optional periodic state JSON dump
 * (env: BPFREJIT_SHIM_PERIODIC_DUMP_MS, ms). Optimization itself is driven
 * by the runner over the socket via execute_step, not by this thread. */
static void *worker_thread(void *arg) {
    (void)arg;
    const char *dump_env = getenv("BPFREJIT_SHIM_PERIODIC_DUMP_MS");
    int dump_ms = dump_env ? atoi(dump_env) : 0;
    if (dump_ms <= 0)
        return NULL;
    sigset_t mask;
    sigfillset(&mask);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);
    while (1) {
        struct timespec ts = {dump_ms / 1000,
                              (long)(dump_ms % 1000) * 1000000L}, rem;
        while (nanosleep(&ts, &rem) == -1 && errno == EINTR)
            ts = rem;
        dump_state_json();
    }
    return NULL;
}
