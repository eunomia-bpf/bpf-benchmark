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

/* Resolved real symbols, set in shim_init(). */
static long (*real_syscall)(long, ...);
static int (*real_ioctl)(int, unsigned long, ...);
static int (*real_close)(int);

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

/* Extract a quoted string after `"key":`. Returns 1 on success and writes up
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
    while (*p && *p != '"' && i + 1 < out_sz)
        out[i++] = *p++;
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

/* execute_step — daemon-style RPC. Runner sends a pre-resolved shell command
 * (read from runner/config/passes/<pass>/default.yaml), shim substitutes
 * shim-owned vars and runs /bin/sh -c verbatim. Mirrors daemon's contract at
 * daemon/src/commands.rs:execute_one + daemon/src/server.rs:execute_plan.
 *
 *   request:  {"cmd":"execute_step","prog_id":<u32>,"command":"<sh>",
 *              "step_seq":<int optional>}
 *   response: {"ok":<bool>,"exit_code":<int>,"output":"<path>","report":"<path>"}
 */
static void emit_execute_step(int cli, const char *json) {
    char prog_id_str[32] = {0};
    char command[4096] = {0};
    /* prog_id is a number; reuse json_get_str by also accepting unquoted. */
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

    /* Look up prog in state table. */
    char input_path[256] = {0}, prog_type_name[32] = "socket_filter";
    pthread_mutex_lock(&state_mutex);
    for (int b = 0; b < OBJ_TABLE_BUCKETS; b++) {
        for (struct obj_entry *e = obj_table[b]; e; e = e->next) {
            if (e->kind == OBJ_PROG &&
                e->u.prog.kernel_prog_id == want_id) {
                snprintf(input_path, sizeof(input_path), "%s",
                         e->u.prog.bytecode_path);
                snprintf(prog_type_name, sizeof(prog_type_name), "%s",
                         prog_type_short_name(e->u.prog.prog_type));
                goto found;
            }
        }
    }
found:
    pthread_mutex_unlock(&state_mutex);
    if (!input_path[0]) {
        dprintf(cli, "{\"ok\":false,\"error\":\"prog_id %u not tracked\"}\n",
                want_id);
        return;
    }

    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    const char *target = getenv("BPFREJIT_TARGET");
    if (!target) target = "x86";
    char workdir[280], output[320], report[320];
    snprintf(workdir, sizeof(workdir), "%s/work_%u", dir, want_id);
    mkdir(workdir, 0755);
    snprintf(output, sizeof(output), "%s/output.bin", workdir);
    snprintf(report, sizeof(report), "%s/report.json", workdir);

    const char *vars[][2] = {
        {"PROG_ID", prog_id_str},
        {"PROG_TYPE", prog_type_name},
        {"INPUT", input_path},
        {"OUTPUT", output},
        {"REPORT", report},
        {"WORKDIR", workdir},
        {"TARGET", target},
    };
    char resolved[4200];
    substitute_vars(resolved, sizeof(resolved), command,
                    vars, sizeof(vars) / sizeof(vars[0]));

    /* /bin/sh -c <resolved> with LD_PRELOAD stripped. */
    size_t n_env = 0;
    while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    size_t j = 0;
    for (size_t i = 0; clean_env && i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    if (clean_env) clean_env[j] = NULL;

    char *const argv[] = {"/bin/sh", "-c", resolved, NULL};
    pid_t pid;
    int rc = posix_spawn(&pid, "/bin/sh", NULL, NULL, argv,
                         clean_env ? clean_env : environ);
    free(clean_env);
    if (rc != 0) {
        dprintf(cli, "{\"ok\":false,\"error\":\"spawn failed rc=%d\"}\n", rc);
        return;
    }
    int status = 0;
    waitpid(pid, &status, 0);
    int ok = WIFEXITED(status) && WEXITSTATUS(status) == 0;
    int code = WIFEXITED(status) ? WEXITSTATUS(status) : -1;
    log_line("execute_step prog_id=%u exit=%d output=%s",
             want_id, code, output);
    dprintf(cli,
            "{\"ok\":%s,\"exit_code\":%d,\"output\":\"%s\",\"report\":\"%s\"}\n",
            ok ? "true" : "false", code, output, report);
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
