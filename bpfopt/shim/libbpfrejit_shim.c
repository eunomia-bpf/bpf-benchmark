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

#include <dirent.h>
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
 * State tables — one per syscall-observed kind. Each table is an
 * fd-keyed open hash with per-bucket linked lists. Kept under a single
 * state_mutex; contention is negligible in practice (shim work is
 * dominated by bpfopt subprocess time).
 *
 * Design rule: the shim never reads or modifies BPF bytecode. It only
 * observes BPF syscall ABI and records what each control-plane fd is.
 * Map / link / perf state is recorded for future re-attach logic; it is
 * NOT used to drive bpfopt (bpfopt is a pure bytecode tool).
 * ==================================================================== */

#define BPF_STATE_BUCKETS 1024
static pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;

static unsigned fd_bucket(int fd) {
    return ((unsigned)fd * 2654435761u) % BPF_STATE_BUCKETS;
}

/* ---- prog table ---- */
struct prog_entry {
    int fd;                       /* app-side fd at PROG_LOAD time */
    struct prog_entry *next;
    uint32_t prog_type;
    char name[17];                /* BPF_OBJ_NAME_LEN+1 NUL-terminated */
    uint32_t insn_cnt;
    uint64_t hash;
    char bytecode_path[256];      /* path to dumped raw bytecode on disk */
    uint32_t expected_attach_type;
    uint32_t attach_btf_id;
    uint32_t kernel_prog_id;      /* 0 until resolved via OBJ_GET_INFO_BY_FD */
    /* Captured BPF_PROG_LOAD attr for candidate re-load (verifier-state
     * probe). The insns pointer is left dangling; consumers re-read from
     * bytecode_path. */
    union bpf_attr load_attr;
    char license[64];             /* deep-copied license string */
    /* fd-typed attr fields cannot survive the loader closing the originals
     * (and tracee in particular runs close_range after init, wiping any
     * dup'd fds the shim cached). Persist the kernel IDs of the referenced
     * BTF / prog objects and re-resolve to fresh fds at reload time via
     * BPF_BTF_GET_FD_BY_ID / BPF_PROG_GET_FD_BY_ID. 0 means unused. */
    uint32_t prog_btf_kid;
    uint32_t attach_btf_obj_kid;
    uint32_t attach_prog_kid;
    /* func_info / line_info are arrays of records pointed to by attr at
     * load time. The kernel does copy_from_user during verification; after
     * the loader frees the buffer those user pages may hold random heap
     * data, causing EINVAL on reload. Deep-copy the bytes so the reload
     * sees the same content. */
    void *func_info_buf;
    uint32_t func_info_cnt;
    uint32_t func_info_rec_size;
    void *line_info_buf;
    uint32_t line_info_cnt;
    uint32_t line_info_rec_size;
    /* Per-prog execute_step state. */
    int canonicalized;            /* 1 once --canonicalize-map-refs has run */
    int step_seq;                 /* incremented per successful execute_step */
    /* Snapshot of map_table at PROG_LOAD time — libbpf may close the map fds
     * shortly after load (especially when handling map-in-map relocations or
     * temporary metadata fds), but the bytecode still references those fd
     * VALUES. We freeze them here so the fd-to-id mapping survives the close. */
    uint32_t *snap_fds;
    uint32_t *snap_kids;
    uint32_t *snap_types;
    uint32_t snap_n;
    /* Live attach points for this prog. Populated by BPF_LINK_CREATE post-call
     * and PERF_EVENT_IOC_SET_BPF post-ioctl; pruned by close() intercept. Used
     * by reload_and_reattach to know what to BPF_LINK_UPDATE / SET_BPF when
     * we swap in a new prog fd. */
    int *attached_link_fds;
    uint32_t n_links;
    int *attached_perf_fds;
    uint32_t n_perfs;
};
static struct prog_entry *prog_table[BPF_STATE_BUCKETS];

/* ---- map table (control-plane observation only — bpfopt never sees this) ---- */
struct map_entry {
    int fd;
    struct map_entry *next;
    uint32_t map_type;
    uint32_t key_size;
    uint32_t value_size;
    uint32_t max_entries;
    uint32_t kernel_map_id;
    char name[17];
};
static struct map_entry *map_table[BPF_STATE_BUCKETS];

/* ---- link table (records BPF_LINK_CREATE for future detach/re-attach) ---- */
struct link_entry {
    int fd;
    struct link_entry *next;
    uint32_t prog_fd;             /* app-side prog fd at create time */
    uint32_t target_fd;
    uint32_t attach_type;
    uint32_t link_type;
    uint32_t kernel_link_id;
    /* Full BPF_LINK_CREATE attrs at capture time. Used by reload_and_reattach
     * when BPF_LINK_UPDATE isn't supported by the kernel for this link type
     * (raw_tracepoint, kprobe, perf_event, tracing — only cgroup/tcx/netns/iter
     * support update). We re-issue BPF_LINK_CREATE with the saved attrs, just
     * substituting prog_fd = new_pfd. */
    char create_attr_blob[80];
};
static struct link_entry *link_table[BPF_STATE_BUCKETS];

/* ---- perf_event table (records perf_event_open + SET_BPF) ---- */
struct perf_entry {
    int fd;
    struct perf_entry *next;
    uint32_t type;
    uint64_t config;
    int32_t pid;
    int32_t cpu;
    int32_t group_fd;             /* group_fd from perf_event_open(2) call */
    uint32_t open_flags;          /* flags from perf_event_open(2) call */
    int32_t attached_prog_fd;     /* -1 until PERF_EVENT_IOC_SET_BPF observed */
    /* Full perf_event_attr captured at perf_event_open(2) time. Stored so
     * reload_and_reattach can re-open the event with identical settings
     * when PERF_EVENT_IOC_SET_BPF returns EEXIST (kernel doesn't support
     * BPF prog replacement on a live perf_event — see
     * perf_event_attach_bpf_prog in kernel/trace/bpf_trace.c). */
    char attr_blob[256];
    uint32_t attr_size;
};
static struct perf_entry *perf_table[BPF_STATE_BUCKETS];

/* Generic remove-by-fd over a typed table. Each table macro-expands its
 * own remove because the chained pointer types differ; macro keeps the
 * tedium colocated. Caller holds state_mutex. */
#define DECLARE_FD_TABLE_OPS(KIND, ENTRY_T, TABLE)                            \
    __attribute__((unused))                                                   \
    static ENTRY_T *KIND##_find(int fd) {                                     \
        if (fd < 0) return NULL;                                              \
        for (ENTRY_T *e = TABLE[fd_bucket(fd)]; e; e = e->next)               \
            if (e->fd == fd) return e;                                        \
        return NULL;                                                          \
    }                                                                         \
    static void KIND##_insert(ENTRY_T *e) {                                   \
        unsigned b = fd_bucket(e->fd);                                        \
        ENTRY_T **prev = &TABLE[b];                                           \
        while (*prev) {                                                       \
            if ((*prev)->fd == e->fd) {                                       \
                ENTRY_T *dead = *prev;                                        \
                *prev = dead->next;                                           \
                free(dead);                                                   \
            } else {                                                          \
                prev = &(*prev)->next;                                        \
            }                                                                 \
        }                                                                     \
        e->next = TABLE[b];                                                   \
        TABLE[b] = e;                                                         \
    }                                                                         \
    static void KIND##_remove(int fd) {                                       \
        if (fd < 0) return;                                                   \
        ENTRY_T **prev = &TABLE[fd_bucket(fd)];                               \
        while (*prev) {                                                       \
            if ((*prev)->fd == fd) {                                          \
                ENTRY_T *dead = *prev;                                        \
                *prev = dead->next;                                           \
                free(dead);                                                   \
                return;                                                       \
            }                                                                 \
            prev = &(*prev)->next;                                            \
        }                                                                     \
    }

DECLARE_FD_TABLE_OPS(map, struct map_entry, map_table)
DECLARE_FD_TABLE_OPS(link, struct link_entry, link_table)
DECLARE_FD_TABLE_OPS(perf, struct perf_entry, perf_table)

/* prog table needs custom insert (free insns on overwrite). */
__attribute__((unused))
static struct prog_entry *prog_find(int fd) {
    if (fd < 0) return NULL;
    for (struct prog_entry *e = prog_table[fd_bucket(fd)]; e; e = e->next)
        if (e->fd == fd) return e;
    return NULL;
}
static struct prog_entry *prog_find_by_kernel_id(uint32_t kid) {
    for (int b = 0; b < BPF_STATE_BUCKETS; b++)
        for (struct prog_entry *e = prog_table[b]; e; e = e->next)
            if (e->kernel_prog_id == kid) return e;
    return NULL;
}
static void prog_free(struct prog_entry *e) {
    free(e->snap_fds);
    free(e->snap_kids);
    free(e->snap_types);
    free(e->attached_link_fds);
    free(e->attached_perf_fds);
    free(e->func_info_buf);
    free(e->line_info_buf);
    free(e);
}

/* Append a fd to a prog's attached_link_fds / attached_perf_fds, growing the
 * array geometrically. Caller holds state_mutex. Returns 0 on success. */
static int prog_attach_append(int **fds, uint32_t *n, int fd) {
    /* Skip duplicates (close-then-reopen-same-fd race). */
    for (uint32_t i = 0; i < *n; i++)
        if ((*fds)[i] == fd) return 0;
    /* Geometric growth: realloc when n is a power of two. */
    if (*n == 0 || ((*n) & ((*n) - 1)) == 0) {
        uint32_t cap = (*n == 0) ? 4 : (*n) * 2;
        int *nf = (int *)realloc(*fds, cap * sizeof(int));
        if (!nf) return -1;
        *fds = nf;
    }
    (*fds)[(*n)++] = fd;
    return 0;
}

/* Drop a fd from a prog's attached_*_fds (linear scan). Caller holds mutex. */
static void prog_attach_drop(int *fds, uint32_t *n, int fd) {
    for (uint32_t i = 0; i < *n; i++) {
        if (fds[i] == fd) {
            fds[i] = fds[--(*n)];
            return;
        }
    }
}

/* Walk every prog_entry and drop `fd` from its link/perf attach lists. Cheap
 * since we usually have few progs. Caller holds mutex. */
static void prog_table_drop_attach_fd(int fd) {
    for (int b = 0; b < BPF_STATE_BUCKETS; b++)
        for (struct prog_entry *e = prog_table[b]; e; e = e->next) {
            prog_attach_drop(e->attached_link_fds, &e->n_links, fd);
            prog_attach_drop(e->attached_perf_fds, &e->n_perfs, fd);
        }
}
static void prog_insert(struct prog_entry *e) {
    unsigned b = fd_bucket(e->fd);
    struct prog_entry **prev = &prog_table[b];
    while (*prev) {
        if ((*prev)->fd == e->fd) {
            struct prog_entry *dead = *prev;
            *prev = dead->next;
            prog_free(dead);
        } else {
            prev = &(*prev)->next;
        }
    }
    e->next = prog_table[b];
    prog_table[b] = e;
}
static void prog_remove(int fd) {
    if (fd < 0) return;
    struct prog_entry **prev = &prog_table[fd_bucket(fd)];
    while (*prev) {
        if ((*prev)->fd == fd) {
            struct prog_entry *dead = *prev;
            *prev = dead->next;
            prog_free(dead);
            return;
        }
        prev = &(*prev)->next;
    }
}

/* Resolve any fd's kernel id via BPF_OBJ_GET_INFO_BY_FD. Works for prog,
 * map, link — all info structs start with {type, id} so we just read id. */
static uint32_t resolve_kernel_id(int fd) {
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

/* Each capture_* returns a heap entry the caller must insert into the right
 * table under state_mutex once the syscall's return fd is known. On OOM or
 * pre-call validation failure: NULL.
 *
 * capture_prog_load: dumps the original bytecode to disk (the kernel does
 * not preserve it). NEVER touches/modifies the bytecode buffer otherwise —
 * the bytecode_path is the only piece of state downstream pipeline needs. */
static struct prog_entry *capture_prog_load(const union bpf_attr *attr) {
    char name[17] = {0};
    memcpy(name, attr->prog_name, 16);
    uint32_t insn_cnt = attr->insn_cnt;
    const struct bpf_insn *insns = (const struct bpf_insn *)(uintptr_t)attr->insns;
    uint64_t hash = 0;
    char path[256] = {0};
    if (insns && insn_cnt > 0) {
        size_t bytes = (size_t)insn_cnt * sizeof(struct bpf_insn);
        hash = fnv1a64(insns, bytes);
        dump_bytecode(hash, insns, insn_cnt);
        const char *dir = getenv("BPFREJIT_SHIM_DIR");
        if (!dir) dir = "/tmp";
        snprintf(path, sizeof(path), "%s/bpfrejit_%d_%016lx.bpf", dir,
                 getpid(), hash);
    }
    log_line("BPF_PROG_LOAD type=%u (%s) name=%s insn_cnt=%u hash=%016lx "
             "license=%s expected_attach=%u attach_btf_id=%u "
             "prog_btf_fd=%u attach_btf_obj_fd=%u attach_prog_fd=%u",
             attr->prog_type, prog_type_short_name(attr->prog_type), name,
             insn_cnt, hash, (const char *)(uintptr_t)attr->license,
             attr->expected_attach_type, attr->attach_btf_id,
             attr->prog_btf_fd, attr->attach_btf_obj_fd, attr->attach_prog_fd);
    struct prog_entry *e = (struct prog_entry *)calloc(1, sizeof(*e));
    if (!e) return NULL;
    e->prog_type = attr->prog_type;
    memcpy(e->name, attr->prog_name, 16);
    e->name[16] = 0;
    e->insn_cnt = insn_cnt;
    e->hash = hash;
    e->expected_attach_type = attr->expected_attach_type;
    e->attach_btf_id = attr->attach_btf_id;
    e->load_attr = *attr;
    /* Resolve fd-typed attr fields to kernel IDs while the originals are
     * still valid (just before the syscall fires). dup() doesn't survive
     * because long-lived loaders (tracee) call close_range() after init.
     * Reload re-resolves these IDs back to fresh fds via *_GET_FD_BY_ID. */
    e->prog_btf_kid = 0;
    e->attach_btf_obj_kid = 0;
    e->attach_prog_kid = 0;
    if (attr->prog_btf_fd) {
        struct bpf_btf_info bi = {0};
        union bpf_attr ia = {0};
        ia.info.bpf_fd = attr->prog_btf_fd;
        ia.info.info_len = sizeof(bi);
        ia.info.info = (uintptr_t)&bi;
        if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) >= 0)
            e->prog_btf_kid = bi.id;
    }
    if (attr->attach_btf_obj_fd) {
        struct bpf_btf_info bi = {0};
        union bpf_attr ia = {0};
        ia.info.bpf_fd = attr->attach_btf_obj_fd;
        ia.info.info_len = sizeof(bi);
        ia.info.info = (uintptr_t)&bi;
        if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) >= 0)
            e->attach_btf_obj_kid = bi.id;
    }
    if (attr->attach_prog_fd) {
        struct bpf_prog_info pi = {0};
        union bpf_attr ia = {0};
        ia.info.bpf_fd = attr->attach_prog_fd;
        ia.info.info_len = sizeof(pi);
        ia.info.info = (uintptr_t)&pi;
        if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) >= 0)
            e->attach_prog_kid = pi.id;
    }
    /* Copy func_info / line_info bytes — pointers in attr reference loader
     * memory that may be freed by the time the runner triggers a reload.
     * Without the actual record bytes the kernel reads garbage and rejects
     * the prog (EINVAL). */
    e->func_info_buf = NULL;
    e->func_info_cnt = 0;
    e->func_info_rec_size = 0;
    e->line_info_buf = NULL;
    e->line_info_cnt = 0;
    e->line_info_rec_size = 0;
    if (attr->func_info && attr->func_info_cnt && attr->func_info_rec_size) {
        size_t n = (size_t)attr->func_info_cnt * attr->func_info_rec_size;
        e->func_info_buf = malloc(n);
        if (e->func_info_buf) {
            memcpy(e->func_info_buf, (void *)(uintptr_t)attr->func_info, n);
            e->func_info_cnt = attr->func_info_cnt;
            e->func_info_rec_size = attr->func_info_rec_size;
        }
    }
    if (attr->line_info && attr->line_info_cnt && attr->line_info_rec_size) {
        size_t n = (size_t)attr->line_info_cnt * attr->line_info_rec_size;
        e->line_info_buf = malloc(n);
        if (e->line_info_buf) {
            memcpy(e->line_info_buf, (void *)(uintptr_t)attr->line_info, n);
            e->line_info_cnt = attr->line_info_cnt;
            e->line_info_rec_size = attr->line_info_rec_size;
        }
    }
    /* Deep-copy license (app-owned user string, lifetime unknown after the
     * call returns). Required for candidate BPF_PROG_LOAD verifier-state
     * probes. */
    const char *lic = (const char *)(uintptr_t)attr->license;
    if (lic) {
        size_t n = strnlen(lic, sizeof(e->license) - 1);
        memcpy(e->license, lic, n);
        e->license[n] = 0;
    }
    if (path[0]) memcpy(e->bytecode_path, path, sizeof(path));
    return e;
}

static struct map_entry *capture_map_create(const union bpf_attr *attr) {
    struct map_entry *e = (struct map_entry *)calloc(1, sizeof(*e));
    if (!e) return NULL;
    e->map_type = attr->map_type;
    e->key_size = attr->key_size;
    e->value_size = attr->value_size;
    e->max_entries = attr->max_entries;
    memcpy(e->name, attr->map_name, 16);
    e->name[16] = 0;
    log_line("BPF_MAP_CREATE type=%u key_size=%u value_size=%u max_entries=%u "
             "name=%s",
             attr->map_type, attr->key_size, attr->value_size,
             attr->max_entries, e->name);
    return e;
}

static struct link_entry *capture_link_create(const union bpf_attr *attr) {
    struct link_entry *e = (struct link_entry *)calloc(1, sizeof(*e));
    if (!e) return NULL;
    e->prog_fd = attr->link_create.prog_fd;
    e->target_fd = attr->link_create.target_fd;
    e->attach_type = attr->link_create.attach_type;
    /* Save the full link_create attr verbatim — for reload_and_reattach
     * fallback when BPF_LINK_UPDATE is unsupported. All link_create fields
     * are inline u32/u64 (no user pointers), so a memcpy is sufficient. */
    size_t lc_size = sizeof(attr->link_create);
    if (lc_size > sizeof(e->create_attr_blob)) lc_size = sizeof(e->create_attr_blob);
    memcpy(e->create_attr_blob, &attr->link_create, lc_size);
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

    /* Probe the kernel BTF for all available kinsn kfunc targets and write
     * target.json once. Subsequent execute_step RPCs reuse this file for the
     * `--target` arg to every bpfopt pass. Daemon-equivalent of the
     * `probe_target_json` step. */
    char target_json_path[320];
    snprintf(target_json_path, sizeof(target_json_path), "%s/target.json", dir);
    if (access(target_json_path, F_OK) != 0) {
        char *const argv[] = {"kinsnprober", "--out", target_json_path, NULL};
        posix_spawn_file_actions_t fa;
        int fa_inited = (posix_spawn_file_actions_init(&fa) == 0);
        if (fa_inited) {
            posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, "/dev/null", O_WRONLY, 0);
            posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, "/dev/null", O_WRONLY, 0);
        }
        /* Strip LD_PRELOAD so kinsnprober doesn't re-attach the shim. */
        size_t n_env = 0; while (environ[n_env]) n_env++;
        char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
        size_t j = 0;
        for (size_t i = 0; clean_env && i < n_env; i++)
            if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
                clean_env[j++] = environ[i];
        if (clean_env) clean_env[j] = NULL;
        pid_t ppid;
        int rc = posix_spawnp(&ppid, "kinsnprober", fa_inited ? &fa : NULL,
                              NULL, argv, clean_env ? clean_env : environ);
        free(clean_env);
        if (fa_inited) posix_spawn_file_actions_destroy(&fa);
        if (rc == 0) {
            int st = 0; waitpid(ppid, &st, 0);
            log_line("kinsnprober exit=%d target=%s",
                     WIFEXITED(st) ? WEXITSTATUS(st) : -1, target_json_path);
        }
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
                struct perf_entry *e = (struct perf_entry *)calloc(1, sizeof(*e));
                if (e) {
                    e->fd = (int)ret;
                    e->type = pa->type;
                    e->config = pa->config;
                    e->pid = pid;
                    e->cpu = cpu;
                    e->group_fd = group_fd;
                    e->open_flags = (uint32_t)flags;
                    e->attached_prog_fd = -1;
                    /* Save the full perf_event_attr so reload_and_reattach
                     * can recreate the event when SET_BPF rejects replacement. */
                    uint32_t asize = pa->size;
                    if (asize == 0 || asize > sizeof(e->attr_blob))
                        asize = sizeof(e->attr_blob);
                    if (asize > sizeof(struct perf_event_attr))
                        asize = sizeof(struct perf_event_attr);
                    memcpy(e->attr_blob, pa, asize);
                    e->attr_size = asize;
                    pthread_mutex_lock(&state_mutex);
                    perf_insert(e);
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

    /* Pre-call captures: one pending pointer per kind. Each capture_*
     * allocates a heap entry we insert into the corresponding table iff
     * the syscall succeeds. */
    struct prog_entry *pending_prog = NULL;
    struct map_entry *pending_map = NULL;
    struct link_entry *pending_link = NULL;
    if (!in_shim && attr) {
        in_shim = 1;
        switch (cmd) {
        case BPF_PROG_LOAD:
            pending_prog = capture_prog_load(attr);
            break;
        case BPF_MAP_CREATE:
            pending_map = capture_map_create(attr);
            break;
        case BPF_LINK_CREATE:
            pending_link = capture_link_create(attr);
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

    uint32_t resolved_id = 0;
    if (pending_prog) {
        if (ret >= 0) {
            pending_prog->fd = (int)ret;
            resolved_id = resolve_kernel_id((int)ret);
            pending_prog->kernel_prog_id = resolved_id;
            /* Capture only the maps THIS prog actually references. Earlier we
             * enumerated all of /proc/self/fd, but for a long-lived loader
             * (e.g. tracee with 158 progs) that snapshot accumulates every
             * map fd ever opened (hundreds), and the kernel rejects PROG_LOAD
             * with -E2BIG once nr_maps > MAX_USED_MAPS=64. Use the prog's own
             * used_maps list (kernel-authoritative) and only map those ids
             * back to loader fds via a single /proc/self/fd scan. */
            uint32_t pmap_ids[64] = {0};
            uint32_t pmap_n = 0;
            {
                struct bpf_prog_info pi;
                memset(&pi, 0, sizeof(pi));
                pi.nr_map_ids = 64;
                pi.map_ids = (uintptr_t)pmap_ids;
                union bpf_attr pa = {0};
                pa.info.bpf_fd = (uint32_t)ret;
                pa.info.info_len = sizeof(pi);
                pa.info.info = (uintptr_t)&pi;
                long pr = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD,
                                       &pa, sizeof(pa));
                if (pr >= 0) {
                    pmap_n = pi.nr_map_ids;
                    if (pmap_n > 64) pmap_n = 64;
                }
            }
            uint32_t cap = pmap_n ? pmap_n : 1, n = 0;
            uint32_t *fds = (uint32_t *)calloc(cap, sizeof(uint32_t));
            uint32_t *kids = (uint32_t *)calloc(cap, sizeof(uint32_t));
            uint32_t *types = (uint32_t *)calloc(cap, sizeof(uint32_t));
            DIR *fd_dir = pmap_n > 0 ? opendir("/proc/self/fd") : NULL;
            if (fd_dir && fds && kids && types) {
                struct dirent *de;
                while ((de = readdir(fd_dir)) != NULL && n < pmap_n) {
                    if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
                    int probe_fd = atoi(de->d_name);
                    if (probe_fd < 0) continue;
                    char fdpath[64], link_target[64];
                    snprintf(fdpath, sizeof(fdpath), "/proc/self/fd/%d", probe_fd);
                    ssize_t lr = readlink(fdpath, link_target, sizeof(link_target) - 1);
                    if (lr <= 0) continue;
                    link_target[lr] = 0;
                    if (strcmp(link_target, "anon_inode:bpf-map") != 0) continue;
                    struct bpf_map_info mi;
                    memset(&mi, 0, sizeof(mi));
                    union bpf_attr ia = {0};
                    ia.info.bpf_fd = (uint32_t)probe_fd;
                    ia.info.info_len = sizeof(mi);
                    ia.info.info = (uintptr_t)&mi;
                    long r = real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD,
                                          &ia, sizeof(ia));
                    if (r < 0 || mi.id == 0) continue;
                    /* Only keep fds whose kernel map id is in this prog's
                     * used_maps list. */
                    int wanted = 0;
                    for (uint32_t i = 0; i < pmap_n; i++)
                        if (pmap_ids[i] == mi.id) { wanted = 1; break; }
                    if (!wanted) continue;
                    /* Skip duplicates — multiple loader fds may alias the
                     * same kernel id; one representative is enough. */
                    int dup = 0;
                    for (uint32_t i = 0; i < n; i++)
                        if (kids[i] == mi.id) { dup = 1; break; }
                    if (dup) continue;
                    fds[n] = (uint32_t)probe_fd;
                    kids[n] = mi.id;
                    types[n] = mi.type;
                    n++;
                }
                pending_prog->snap_fds = fds;
                pending_prog->snap_kids = kids;
                pending_prog->snap_types = types;
                pending_prog->snap_n = n;
            } else {
                free(fds); free(kids); free(types);
            }
            if (fd_dir) closedir(fd_dir);
            pthread_mutex_lock(&state_mutex);
            prog_insert(pending_prog);
            pthread_mutex_unlock(&state_mutex);
        } else {
            free(pending_prog);
        }
    }
    if (pending_map) {
        if (ret >= 0) {
            pending_map->fd = (int)ret;
            resolved_id = resolve_kernel_id((int)ret);
            pending_map->kernel_map_id = resolved_id;
            pthread_mutex_lock(&state_mutex);
            map_insert(pending_map);
            pthread_mutex_unlock(&state_mutex);
        } else {
            free(pending_map);
        }
    }
    if (pending_link) {
        if (ret >= 0) {
            pending_link->fd = (int)ret;
            resolved_id = resolve_kernel_id((int)ret);
            pending_link->kernel_link_id = resolved_id;
            pthread_mutex_lock(&state_mutex);
            link_insert(pending_link);
            /* Record this attach on the prog so reload_and_reattach can
             * BPF_LINK_UPDATE us to the optimized prog later. */
            struct prog_entry *pe = prog_find((int)pending_link->prog_fd);
            if (pe)
                (void)prog_attach_append(&pe->attached_link_fds,
                                         &pe->n_links, (int)ret);
            pthread_mutex_unlock(&state_mutex);
        } else {
            free(pending_link);
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
            int prog_fd = (int)(intptr_t)arg;
            pthread_mutex_lock(&state_mutex);
            struct perf_entry *e = perf_find(fd);
            if (!e) {
                /* perf_event was opened before the shim attached (early
                 * constructor, fd inherited from a parent, etc.) — recover
                 * the attr from /proc/self/fdinfo/<fd>. This is best-effort:
                 * we only need type+config for perf_event_open re-creation
                 * during reload_and_reattach. */
                char fdpath[64], line[256];
                snprintf(fdpath, sizeof(fdpath), "/proc/self/fdinfo/%d", fd);
                FILE *fpi = fopen(fdpath, "r");
                if (fpi) {
                    struct perf_event_attr attr;
                    memset(&attr, 0, sizeof(attr));
                    attr.size = sizeof(attr);
                    int got = 0;
                    while (fgets(line, sizeof(line), fpi)) {
                        unsigned long long v;
                        if (sscanf(line, "attr_type: %llu", &v) == 1) {
                            attr.type = (uint32_t)v; got |= 1;
                        } else if (sscanf(line, "attr_config: %llu", &v) == 1) {
                            attr.config = (uint64_t)v; got |= 2;
                        } else if (sscanf(line, "attr_config1: %llu", &v) == 1) {
                            attr.config1 = (uint64_t)v;
                        } else if (sscanf(line, "attr_config2: %llu", &v) == 1) {
                            attr.config2 = (uint64_t)v;
                        }
                    }
                    fclose(fpi);
                    if ((got & 3) == 3) {
                        e = (struct perf_entry *)calloc(1, sizeof(*e));
                        if (e) {
                            e->fd = fd;
                            e->type = attr.type;
                            e->config = attr.config;
                            e->pid = -1;
                            e->cpu = -1;
                            e->group_fd = -1;
                            e->open_flags = 0;
                            e->attached_prog_fd = -1;
                            memcpy(e->attr_blob, &attr, sizeof(attr));
                            e->attr_size = sizeof(attr);
                            perf_insert(e);
                            log_line("perf recover from fdinfo: fd=%d "
                                     "type=%u config=%llu",
                                     fd, attr.type,
                                     (unsigned long long)attr.config);
                        }
                    }
                }
            }
            if (e) e->attached_prog_fd = prog_fd;
            /* Record this attach on the prog so reload_and_reattach can
             * re-issue SET_BPF with the optimized prog fd later. */
            struct prog_entry *pe = prog_find(prog_fd);
            if (pe)
                (void)prog_attach_append(&pe->attached_perf_fds,
                                         &pe->n_perfs, fd);
            pthread_mutex_unlock(&state_mutex);
        }
        log_line("  PERF_EVENT_IOC_SET_BPF -> ret=%d errno=%d", ret,
                 ret < 0 ? saved_errno : 0);
    }

    errno = saved_errno;
    return ret;
}

/* Intercept close(2): release table entries if any (cheap; fd is unique
 * across kinds so at most one removes a real entry). */
int close(int fd) {
    ensure_syms_resolved();
    if (!in_shim && fd >= 0) {
        pthread_mutex_lock(&state_mutex);
        prog_remove(fd);
        map_remove(fd);
        link_remove(fd);
        perf_remove(fd);
        /* If this fd was a link/perf_event attached to some prog, drop it
         * from that prog's attach lists too (no-op if fd was not a known
         * attach). */
        prog_table_drop_attach_fd(fd);
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
    fprintf(f, "{\n  \"pid\": %d,\n  \"progs\": [", getpid());
    pthread_mutex_lock(&state_mutex);
    int first = 1;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct prog_entry *e = prog_table[b]; e; e = e->next) {
            fprintf(f, "%s\n    {\"fd\":%d,\"prog_type\":%u,\"name\":\"%s\","
                       "\"insn_cnt\":%u,\"hash\":\"%016lx\","
                       "\"kernel_prog_id\":%u,\"bytecode_path\":\"%s\","
                       "\"expected_attach\":%u,\"attach_btf_id\":%u}",
                    first ? "" : ",", e->fd, e->prog_type, e->name,
                    e->insn_cnt, e->hash, e->kernel_prog_id, e->bytecode_path,
                    e->expected_attach_type, e->attach_btf_id);
            first = 0;
        }
    }
    fprintf(f, "\n  ],\n  \"maps\": [");
    first = 1;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct map_entry *e = map_table[b]; e; e = e->next) {
            fprintf(f, "%s\n    {\"fd\":%d,\"map_type\":%u,\"name\":\"%s\","
                       "\"key_size\":%u,\"value_size\":%u,"
                       "\"max_entries\":%u,\"kernel_map_id\":%u}",
                    first ? "" : ",", e->fd, e->map_type, e->name,
                    e->key_size, e->value_size, e->max_entries,
                    e->kernel_map_id);
            first = 0;
        }
    }
    fprintf(f, "\n  ],\n  \"links\": [");
    first = 1;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct link_entry *e = link_table[b]; e; e = e->next) {
            fprintf(f, "%s\n    {\"fd\":%d,\"prog_fd\":%u,\"target_fd\":%u,"
                       "\"attach_type\":%u,\"kernel_link_id\":%u}",
                    first ? "" : ",", e->fd, e->prog_fd, e->target_fd,
                    e->attach_type, e->kernel_link_id);
            first = 0;
        }
    }
    fprintf(f, "\n  ],\n  \"perf_events\": [");
    first = 1;
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct perf_entry *e = perf_table[b]; e; e = e->next) {
            fprintf(f, "%s\n    {\"fd\":%d,\"type\":%u,\"config\":%llu,"
                       "\"pid\":%d,\"cpu\":%d,\"attached_prog_fd\":%d}",
                    first ? "" : ",", e->fd, e->type,
                    (unsigned long long)e->config, e->pid, e->cpu,
                    e->attached_prog_fd);
            first = 0;
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

/* Parse a non-negative integer that follows `"key":` (no escape handling).
 * Returns -1 if the key is missing or the value isn't a number. */
static long json_get_int(const char *json, const char *key) {
    char needle[64];
    snprintf(needle, sizeof(needle), "\"%s\"", key);
    const char *p = strstr(json, needle);
    if (!p) return -1;
    p = strchr(p + strlen(needle), ':');
    if (!p) return -1;
    p++;
    while (*p == ' ' || *p == '\t' || *p == '"') p++;
    if (*p < '0' || *p > '9') return -1;
    long v = 0;
    while (*p >= '0' && *p <= '9') { v = v * 10 + (*p - '0'); p++; }
    return v;
}

/* Locate the bracketed `[...]` array right after `"key":`. Returns a pointer
 * to the first byte inside the brackets and writes one-past-`]` to *end_out.
 * Skips quoted strings while tracking nesting. */
static const char *json_array_at(const char *json, const char *key,
                                 const char **end_out) {
    char needle[64];
    snprintf(needle, sizeof(needle), "\"%s\"", key);
    const char *p = strstr(json, needle);
    if (!p) return NULL;
    p = strchr(p + strlen(needle), ':');
    if (!p) return NULL;
    p++;
    while (*p == ' ' || *p == '\t' || *p == '\n') p++;
    if (*p != '[') return NULL;
    const char *start = ++p;
    int depth = 1, in_str = 0;
    while (*p && depth > 0) {
        if (*p == '\\' && p[1]) { p += 2; continue; }
        if (*p == '"') { in_str = !in_str; p++; continue; }
        if (!in_str) {
            if (*p == '[' || *p == '{') depth++;
            else if (*p == ']' || *p == '}') depth--;
        }
        if (depth > 0) p++;
    }
    if (end_out) *end_out = p;
    return start;
}

/* Walk an array. cursor starts at the array's first inside char (from
 * json_array_at). On success writes the `{` and one-past-`}` of the next
 * top-level object to obj_start and obj_end, advances cursor, returns 1.
 * Returns 0 when no more objects (or hits the end). */
static int json_array_next_obj(const char **cursor, const char *array_end,
                               const char **obj_start, const char **obj_end) {
    const char *c = *cursor;
    while (c < array_end &&
           (*c == ' ' || *c == ',' || *c == '\n' || *c == '\t' || *c == '\r'))
        c++;
    if (c >= array_end || *c != '{') return 0;
    *obj_start = c;
    int depth = 1, in_str = 0;
    c++;
    while (c < array_end && depth > 0) {
        if (*c == '\\' && c + 1 < array_end) { c += 2; continue; }
        if (*c == '"') { in_str = !in_str; c++; continue; }
        if (!in_str) {
            if (*c == '{') depth++;
            else if (*c == '}') depth--;
        }
        c++;
    }
    *obj_end = c;
    *cursor = c;
    return 1;
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
    for (int b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct prog_entry *e = prog_table[b]; e; e = e->next) {
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
                first ? "" : ",", e->kernel_prog_id, e->name,
                e->prog_type, e->insn_cnt, e->hash, e->bytecode_path);
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

/* Dedup an (fd, kid, type) snapshot into per-unique-kid arrays. The result
 * matches what the downstream `--map-ids` CSV needs (one slot per unique
 * kernel map) plus a representative loader fd per kid (used to rebuild
 * fd_array during verifier-state probes). Caller frees all three arrays. */
static int dedup_snapshot_by_kid(const uint32_t *snap_fds,
                                 const uint32_t *snap_kids,
                                 const uint32_t *snap_types,
                                 uint32_t snap_n,
                                 uint32_t **kids_out, uint32_t **types_out,
                                 uint32_t **rep_fds_out, uint32_t *n_out) {
    uint32_t cap = snap_n + 1;
    uint32_t *kids = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *types = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *fds = (uint32_t *)calloc(cap, sizeof(uint32_t));
    if (!kids || !types || !fds) { free(kids); free(types); free(fds); return -1; }
    uint32_t n = 0;
    for (uint32_t i = 0; i < snap_n; i++) {
        if (snap_kids[i] == 0) continue;
        uint32_t k = 0;
        for (; k < n; k++) if (kids[k] == snap_kids[i]) break;
        if (k < n) continue;
        kids[n] = snap_kids[i];
        types[n] = snap_types[i];
        fds[n] = snap_fds[i];
        n++;
    }
    *kids_out = kids; *types_out = types; *rep_fds_out = fds; *n_out = n;
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

/* For map-in-map outers (ARRAY_OF_MAPS / HASH_OF_MAPS): walk the outer map
 * via BPF_MAP_GET_NEXT_KEY + BPF_MAP_LOOKUP_ELEM and write each slot's inner
 * map id to map-<outer_kid>.inner_map_ids.json. map_inline reads this file to
 * resolve inner refs during inlining; daemon-equivalent supplement. */
static void write_inner_map_ids_supplement(const char *map_values_dir,
                                           uint32_t outer_kid,
                                           uint32_t outer_type) {
    /* Reopen the outer map fresh — we don't keep its fd. */
    union bpf_attr ga = {0};
    ga.map_id = outer_kid;
    long ofd = real_syscall(SYS_bpf, BPF_MAP_GET_FD_BY_ID, &ga, sizeof(ga));
    if (ofd < 0) return;
    struct bpf_map_info info;
    memset(&info, 0, sizeof(info));
    union bpf_attr ia = {0};
    ia.info.bpf_fd = (uint32_t)ofd;
    ia.info.info_len = sizeof(info);
    ia.info.info = (uintptr_t)&info;
    if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) < 0) {
        real_close((int)ofd);
        return;
    }
    if (info.key_size == 0) { real_close((int)ofd); return; }

    char path[512];
    snprintf(path, sizeof(path), "%s/map-%u.inner_map_ids.json",
             map_values_dir, outer_kid);
    FILE *f = fopen(path, "w");
    if (!f) { real_close((int)ofd); return; }

    fprintf(f, "{\n  \"%u\": {", outer_kid);
    int first = 1;
    uint8_t *key = (uint8_t *)calloc(1, info.key_size);
    uint8_t *prev_key = NULL;
    if (!key) { fprintf(f, "}\n}\n"); fclose(f); real_close((int)ofd); return; }

    /* ARRAY_OF_MAPS: 4-byte u32 indices 0..max_entries-1. HASH_OF_MAPS: walk
     * with BPF_MAP_GET_NEXT_KEY. */
    if (outer_type == BPF_MAP_TYPE_ARRAY_OF_MAPS && info.key_size == 4) {
        for (uint32_t k = 0; k < info.max_entries; k++) {
            uint32_t inner_kid = 0;
            *(uint32_t *)key = k;
            union bpf_attr la = {0};
            la.map_fd = (uint32_t)ofd;
            la.key = (uintptr_t)key;
            la.value = (uintptr_t)&inner_kid;
            if (real_syscall(SYS_bpf, BPF_MAP_LOOKUP_ELEM, &la, sizeof(la)) < 0)
                continue;
            if (inner_kid == 0) continue;
            fprintf(f, "%s\n    \"%02x%02x%02x%02x\": \"%u\"",
                    first ? "" : ",",
                    key[0], key[1], key[2], key[3], inner_kid);
            first = 0;
        }
    } else if (outer_type == BPF_MAP_TYPE_HASH_OF_MAPS) {
        uint8_t *cur = (uint8_t *)calloc(1, info.key_size);
        if (cur) {
            for (;;) {
                union bpf_attr na = {0};
                na.map_fd = (uint32_t)ofd;
                na.key = prev_key ? (uintptr_t)prev_key : 0;
                na.next_key = (uintptr_t)cur;
                if (real_syscall(SYS_bpf, BPF_MAP_GET_NEXT_KEY, &na, sizeof(na)) < 0)
                    break;
                uint32_t inner_kid = 0;
                union bpf_attr la = {0};
                la.map_fd = (uint32_t)ofd;
                la.key = (uintptr_t)cur;
                la.value = (uintptr_t)&inner_kid;
                if (real_syscall(SYS_bpf, BPF_MAP_LOOKUP_ELEM, &la, sizeof(la)) == 0
                    && inner_kid != 0) {
                    fprintf(f, "%s\n    \"", first ? "" : ",");
                    for (uint32_t b = 0; b < info.key_size; b++)
                        fprintf(f, "%02x", cur[b]);
                    fprintf(f, "\": \"%u\"", inner_kid);
                    first = 0;
                }
                if (!prev_key) prev_key = (uint8_t *)malloc(info.key_size);
                if (prev_key) memcpy(prev_key, cur, info.key_size);
                else break;
            }
            free(cur);
        }
    }
    free(key);
    free(prev_key);
    fprintf(f, "\n  }\n}\n");
    fclose(f);
    real_close((int)ofd);
}

/* Write per-map snapshots into map_values_dir, keyed by kernel map id so the
 * filename matches what map_inline cross-checks against (`show.id`). bpfopt
 * gets a separate fd-to-id.json so canonicalize can route loader-fd-in-imm
 * back to the right kernel map. */
static void write_map_snapshots(const char *map_values_dir,
                                const uint32_t *kernel_ids,
                                const uint32_t *types, uint32_t n) {
    mkdir(map_values_dir, 0755);
    for (uint32_t i = 0; i < n; i++) {
        if (kernel_ids[i] == 0) continue;
        char id_str[16];
        snprintf(id_str, sizeof(id_str), "%u", kernel_ids[i]);
        char show_path[512], dump_path[512];
        snprintf(show_path, sizeof(show_path), "%s/map-%u.show.json",
                 map_values_dir, kernel_ids[i]);
        char *const show_argv[] = {"bpftool", "-j", "map", "show", "id",
                                   id_str, NULL};
        (void)run_bpftool_to_file(show_argv, show_path);
        if (!map_type_needs_dump(types[i])) continue;
        snprintf(dump_path, sizeof(dump_path), "%s/map-%u.dump.json",
                 map_values_dir, kernel_ids[i]);
        char *const dump_argv[] = {"bpftool", "-j", "map", "dump", "id",
                                   id_str, NULL};
        (void)run_bpftool_to_file(dump_argv, dump_path);
        /* Match daemon's 64 KB skip threshold: large dumps (e.g. katran's
         * reals/ch_rings 1M-entry arrays) would otherwise live as raw entries
         * AND collide with the overlays.json that map_inline expects to be
         * the sole source of truth for those map_ids. */
        struct stat dst;
        const uint64_t MAP_SNAPSHOT_MAX_BYTES = 64ULL * 1024ULL;
        if (stat(dump_path, &dst) == 0 &&
            (uint64_t)dst.st_size > MAP_SNAPSHOT_MAX_BYTES) {
            int wfd = open(dump_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (wfd >= 0) {
                dprintf(wfd,
                        "{\"skipped\":true,\"reason\":\"size_limit\","
                        "\"size_bytes\":%llu,\"limit_bytes\":%llu}\n",
                        (unsigned long long)dst.st_size,
                        (unsigned long long)MAP_SNAPSHOT_MAX_BYTES);
                real_close(wfd);
            }
            /* Skip inner_map_ids supplement when we've dropped the raw dump,
             * matching daemon's `dump_size <= MAP_SNAPSHOT_MAX_BYTES` guard. */
            continue;
        }
        if (types[i] == BPF_MAP_TYPE_ARRAY_OF_MAPS ||
            types[i] == BPF_MAP_TYPE_HASH_OF_MAPS) {
            write_inner_map_ids_supplement(map_values_dir, kernel_ids[i],
                                           types[i]);
        }
    }
}

/* Write the loader-fd → kernel-map-id JSON for one prog's PROG_LOAD-time
 * snapshot (see prog_entry.snap_*). Canonicalize uses these to collapse
 * N-fds-pointing-to-same-kid into one fd_array slot. */
static int write_fd_to_id_json(const char *path, const uint32_t *fds,
                               const uint32_t *kids, uint32_t n) {
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return -1;
    FILE *f = fdopen(fd, "w");
    if (!f) { real_close(fd); return -1; }
    fprintf(f, "{");
    int first = 1;
    for (uint32_t i = 0; i < n; i++) {
        if (kids[i] == 0) continue;
        fprintf(f, "%s\"%u\":%u", first ? "" : ",", fds[i], kids[i]);
        first = 0;
    }
    fprintf(f, "}\n");
    fclose(f);
    return 0;
}

/* Invoke `bpfopt --canonicalize-map-refs ...`. Writes canonicalized bytecode
 * to out_path. Captures stdout+stderr into `log_path` (if non-NULL) so a
 * caller can surface the failure reason. Returns 0 on success. */
static int run_canonicalize(const char *input_path, const char *out_path,
                            const char *target_json, const char *map_ids_csv,
                            const char *fd_to_id_json,
                            const char *log_path) {
    char *const argv[] = {
        "bpfopt", "--canonicalize-map-refs",
        "--input", (char *)input_path,
        "--output", (char *)out_path,
        "--map-ids", (char *)map_ids_csv,
        "--target", (char *)target_json,
        "--target-output", (char *)target_json,
        "--fd-to-id", (char *)fd_to_id_json,
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

/* Parse target.json for the (btf_id, call_offset) pairs of BTF modules that
 * provide kinsn kfuncs. Pairs are stored adjacent in the JSON by serde_json's
 * alphabetic field ordering: "btf_func_id" < "btf_id" < "call_offset". We
 * scan linearly to extract each (btf_id, call_offset). Skips call_offset==0
 * entries (those mean vmlinux which doesn't need an fd_array slot). Caller
 * frees both arrays. Returns 0 on success even if no modules. */
static int parse_target_btf_modules(const char *target_json_path,
                                    uint32_t **btf_ids_out,
                                    uint32_t **call_offsets_out,
                                    uint32_t *n_out) {
    *btf_ids_out = NULL; *call_offsets_out = NULL; *n_out = 0;
    int fd = open(target_json_path, O_RDONLY);
    if (fd < 0) return 0;
    struct stat st;
    if (fstat(fd, &st) != 0 || st.st_size <= 0 || st.st_size > 1024 * 1024) {
        real_close(fd); return 0;
    }
    char *buf = (char *)malloc(st.st_size + 1);
    if (!buf) { real_close(fd); return -1; }
    ssize_t n = read(fd, buf, st.st_size);
    real_close(fd);
    if (n != st.st_size) { free(buf); return -1; }
    buf[n] = 0;
    uint32_t cap = 8, count = 0;
    uint32_t *bids = (uint32_t *)calloc(cap, sizeof(uint32_t));
    uint32_t *offs = (uint32_t *)calloc(cap, sizeof(uint32_t));
    if (!bids || !offs) { free(bids); free(offs); free(buf); return -1; }
    const char *p = buf;
    while ((p = strstr(p, "\"btf_id\""))) {
        const char *col = strchr(p, ':');
        if (!col) break;
        col++;
        while (*col == ' ' || *col == '\t') col++;
        uint32_t bid = (uint32_t)strtoul(col, NULL, 10);
        const char *co_key = strstr(col, "\"call_offset\"");
        if (!co_key) break;
        const char *co_col = strchr(co_key, ':');
        if (!co_col) break;
        co_col++;
        while (*co_col == ' ' || *co_col == '\t') co_col++;
        uint32_t off = (uint32_t)strtoul(co_col, NULL, 10);
        p = co_col;
        if (off == 0 || bid == 0) continue; /* vmlinux or empty entry */
        int dup = 0;
        for (uint32_t i = 0; i < count; i++)
            if (bids[i] == bid && offs[i] == off) { dup = 1; break; }
        if (dup) continue;
        if (count == cap) {
            cap *= 2;
            uint32_t *nb = (uint32_t *)realloc(bids, cap * sizeof(uint32_t));
            uint32_t *no = (uint32_t *)realloc(offs, cap * sizeof(uint32_t));
            if (!nb || !no) { free(nb ? nb : bids); free(no ? no : offs); free(buf); return -1; }
            bids = nb; offs = no;
        }
        bids[count] = bid; offs[count] = off;
        count++;
    }
    free(buf);
    *btf_ids_out = bids; *call_offsets_out = offs; *n_out = count;
    return 0;
}

/* Build the fd_array passed to BPF_PROG_LOAD for an optimized bytecode.
 * Layout (matches daemon's build_rejit_fd_array):
 *   - slots [0..nr_map_fds): map fds (dup'd from loader fds)
 *   - slots at each module's `call_offset`: BTF module fds (from
 *     BPF_BTF_GET_FD_BY_ID(btf_id))
 *   - padding -1 for unused slots between
 *
 * `*out_fd_array` is heap-allocated; *out_count = total slot count. Caller
 * frees the array and `real_close()`s each non-negative fd. Returns 0 on
 * success, -1 on OOM/IO. */
/* `map_kernel_ids[i]` is the kernel-side BPF map id (stable). We open a fresh
 * fd via BPF_MAP_GET_FD_BY_ID for every reload — loader-side fds captured at
 * PROG_LOAD time may have been closed by the host app after init (tracee
 * drops its loader map fds once libbpf is done with them; reusing the
 * cached fd would return -EBADF). */
static int build_full_fd_array(const char *target_json_path,
                               const uint32_t *map_kernel_ids,
                               uint32_t nr_maps,
                               int **out_fd_array,
                               uint32_t *out_count) {
    *out_fd_array = NULL; *out_count = 0;
    uint32_t *btf_ids = NULL, *call_offsets = NULL, n_mods = 0;
    if (parse_target_btf_modules(target_json_path, &btf_ids, &call_offsets,
                                 &n_mods) != 0)
        return -1;

    /* Determine total slot count = max(nr_maps, max(call_offset) + 1). */
    uint32_t total = nr_maps;
    for (uint32_t i = 0; i < n_mods; i++) {
        uint32_t need = call_offsets[i] + 1;
        if (need > total) total = need;
    }
    if (total == 0) {
        *out_count = 0;
        free(btf_ids); free(call_offsets);
        return 0;
    }
    int *arr = (int *)malloc(total * sizeof(int));
    if (!arr) { free(btf_ids); free(call_offsets); return -1; }
    for (uint32_t i = 0; i < total; i++) arr[i] = -1;
    /* Map fds in [0, nr_maps). Resolve fresh from kernel id; the snapshot's
     * loader-side fds may have been closed since PROG_LOAD. */
    for (uint32_t i = 0; i < nr_maps; i++) {
        uint32_t kid = map_kernel_ids[i];
        if (kid == 0) { arr[i] = -1; continue; }
        union bpf_attr ga = {0};
        ga.map_id = kid;
        long mfd = real_syscall(SYS_bpf, BPF_MAP_GET_FD_BY_ID, &ga, sizeof(ga));
        arr[i] = (mfd >= 0) ? (int)mfd : -1;
    }
    /* BTF module fds at call_offset slots. */
    for (uint32_t i = 0; i < n_mods; i++) {
        union bpf_attr ga = {0};
        ga.info.bpf_fd = 0;        /* unused for BTF_GET_FD_BY_ID */
        ga.btf_id = btf_ids[i];
        long bfd = real_syscall(SYS_bpf, BPF_BTF_GET_FD_BY_ID, &ga, sizeof(ga));
        if (bfd >= 0) {
            if (call_offsets[i] < total) arr[call_offsets[i]] = (int)bfd;
            else real_close((int)bfd);
        }
    }
    /* Slot [0] sanity: if no maps but ≥1 module, fd_array[0] must be a
     * valid BTF fd (kernel verifier pre-scans). Reuse the first module fd. */
    if (nr_maps == 0 && n_mods > 0) {
        for (uint32_t i = 0; i < total; i++)
            if (arr[i] >= 0) { arr[0] = arr[i]; break; }
    }
    free(btf_ids); free(call_offsets);
    *out_fd_array = arr;
    *out_count = total;
    return 0;
}

/* Close every non-negative fd in arr and free arr. Pairs with build_full_fd_array. */
static void free_full_fd_array(int *arr, uint32_t count) {
    if (!arr) return;
    /* Slot 0 may alias a higher slot when nr_maps==0; deduplicate before close. */
    for (uint32_t i = 0; i < count; i++) {
        if (arr[i] < 0) continue;
        int dupd = 0;
        for (uint32_t j = i + 1; j < count; j++) if (arr[j] == arr[i]) { arr[j] = -1; dupd = 1; break; }
        (void)dupd;
        real_close(arr[i]);
        arr[i] = -1;
    }
    free(arr);
}

/* Issue a stock BPF_PROG_LOAD with the pass-output bytecode + log_level=2 to
 * capture verifier states. Writes the verifier log to log_path. The probe fd
 * is closed; we never run the probe program. Failures fall through silently
 * (the log path will exist with whatever the kernel wrote before bailing). */
static void capture_verifier_states(const struct prog_entry *p,
                                    const char *bytecode_path,
                                    const char *target_json_path,
                                    const uint32_t *map_fds, uint32_t nr_fds,
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

    /* Full fd_array: map fds + BTF module fds at call_offset slots, parsed
     * from target.json. */
    int *fd_array = NULL;
    uint32_t fd_array_n = 0;
    (void)build_full_fd_array(target_json_path, map_fds, nr_fds,
                              &fd_array, &fd_array_n);

    /* 16 MB log buffer matches daemon's REJIT_VERBOSE_LOG_BUF_SIZE. */
    size_t log_buf_size = 16 * 1024 * 1024;
    char *log_buf = (char *)malloc(log_buf_size);
    if (!log_buf) {
        free(insns);
        free_full_fd_array(fd_array, fd_array_n);
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
    if (fd_array) a.fd_array = (uintptr_t)fd_array;

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
    free_full_fd_array(fd_array, fd_array_n);
    free(log_buf);
    free(insns);
    errno = saved_errno;
}

/* Result of reload_and_reattach. */
enum reload_status {
    RELOAD_OK = 0,         /* PROG_LOAD + all attaches succeeded */
    RELOAD_FAILED_REJIT,   /* PROG_LOAD rejected; verifier_log filled */
    RELOAD_PARTIAL_ATTACH, /* LOAD ok, ≥1 attach swap failed mid-way */
    RELOAD_INTERNAL,       /* OOM / I/O before any kernel call */
};

/* Replace the live kernel BPF program identified by `p` with the bytecode at
 * `new_bytecode_path`. After successful return, every link/perf_event that
 * was attached to the old prog points at the new one, and `p` is updated in
 * place so subsequent steps re-load against the new fd/id.
 *
 * Pre-conditions (caller-enforced):
 *   - `map_fds[]` (length nr_fds) is the deduped fd_array the canonicalized
 *     bytecode expects (one fd per BPF_PSEUDO_MAP_IDX slot).
 *   - `p->fd` is still the live, open prog fd.
 *
 * On failure modes:
 *   - RELOAD_FAILED_REJIT: verifier_log (size log_buf_sz) is populated.
 *     Old prog stays attached and live; caller treats step as FailedRejit
 *     and continues without advancing input.
 *   - RELOAD_PARTIAL_ATTACH: the new prog was loaded but ≥1 attach point
 *     swap failed. The kernel state is now mixed; caller logs the error
 *     but the step is best-effort marked as RELOAD_PARTIAL_ATTACH (no
 *     clean rollback exists — BPF_LINK_UPDATE is atomic per-link but
 *     can't undo prior successful swaps without re-applying old fd).
 *
 * Writes `*out_rejit_ms` (CLOCK_MONOTONIC, LOAD + all swap iterations). */
static enum reload_status reload_and_reattach(struct prog_entry *p,
                                              const char *new_bytecode_path,
                                              const char *target_json_path,
                                              const uint32_t *map_fds,
                                              uint32_t nr_fds,
                                              char *verifier_log,
                                              size_t log_buf_sz,
                                              uint64_t *out_rejit_ms) {
    if (out_rejit_ms) *out_rejit_ms = 0;
    if (verifier_log && log_buf_sz > 0) verifier_log[0] = 0;

    int bfd = open(new_bytecode_path, O_RDONLY);
    if (bfd < 0) return RELOAD_INTERNAL;
    struct stat st;
    if (fstat(bfd, &st) != 0 || st.st_size <= 0 ||
        (st.st_size % (off_t)sizeof(struct bpf_insn)) != 0) {
        real_close(bfd);
        return RELOAD_INTERNAL;
    }
    size_t bytes = (size_t)st.st_size;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(bytes);
    if (!insns) { real_close(bfd); return RELOAD_INTERNAL; }
    ssize_t rd = read(bfd, insns, bytes);
    real_close(bfd);
    if (rd != (ssize_t)bytes) { free(insns); return RELOAD_INTERNAL; }

    /* Full fd_array: maps + BTF module fds (read from target.json). */
    int *fd_array = NULL;
    uint32_t fd_array_n = 0;
    (void)build_full_fd_array(target_json_path, map_fds, nr_fds,
                              &fd_array, &fd_array_n);

    /* Use the caller-supplied verifier_log buffer (or a small heap one if
     * absent) — log_level=2 always so we can return a useful verifier log
     * on failure. */
    char *log_buf = verifier_log;
    size_t log_size = log_buf_sz;
    char *owned_log = NULL;
    if (!log_buf) {
        log_size = 1 * 1024 * 1024;
        owned_log = (char *)malloc(log_size);
        log_buf = owned_log;
        if (!log_buf) {
            if (fd_array) {
                for (uint32_t i = 0; i < nr_fds; i++)
                    if (fd_array[i] >= 0) real_close(fd_array[i]);
                free(fd_array);
            }
            free(insns);
            return RELOAD_INTERNAL;
        }
    }

    /* Start from the captured original PROG_LOAD attr — preserves every
     * field tracee/etc. passed (line_info, func_info, core_relos, etc.)
     * without us having to enumerate them. Only patch the fields the reload
     * actually needs to swap, plus the fd-typed fields which we dup at
     * intercept time (the originals may already be closed). */
    union bpf_attr a = p->load_attr;
    a.insns = (uintptr_t)insns;
    a.insn_cnt = (uint32_t)(bytes / sizeof(struct bpf_insn));
    a.license = (uintptr_t)p->license;
    /* Open fresh fds for the BTF / attach-prog objects we captured by id.
     * These get closed below after PROG_LOAD returns (kernel takes refs
     * during the syscall; we only need the fd alive across the call). */
    int prog_btf_resolved = -1;
    int attach_btf_obj_resolved = -1;
    int attach_prog_resolved = -1;
    if (p->prog_btf_kid) {
        union bpf_attr ia = {0};
        ia.btf_id = p->prog_btf_kid;
        long r = real_syscall(SYS_bpf, BPF_BTF_GET_FD_BY_ID, &ia, sizeof(ia));
        if (r >= 0) prog_btf_resolved = (int)r;
    }
    if (p->attach_btf_obj_kid) {
        union bpf_attr ia = {0};
        ia.btf_id = p->attach_btf_obj_kid;
        long r = real_syscall(SYS_bpf, BPF_BTF_GET_FD_BY_ID, &ia, sizeof(ia));
        if (r >= 0) attach_btf_obj_resolved = (int)r;
    }
    if (p->attach_prog_kid) {
        union bpf_attr ia = {0};
        ia.prog_id = p->attach_prog_kid;
        long r = real_syscall(SYS_bpf, BPF_PROG_GET_FD_BY_ID, &ia, sizeof(ia));
        if (r >= 0) attach_prog_resolved = (int)r;
    }
    a.prog_btf_fd = (prog_btf_resolved >= 0) ? (uint32_t)prog_btf_resolved : 0;
    a.attach_btf_obj_fd = (attach_btf_obj_resolved >= 0)
                          ? (uint32_t)attach_btf_obj_resolved : 0;
    a.attach_prog_fd = (attach_prog_resolved >= 0)
                       ? (uint32_t)attach_prog_resolved : 0;
    /* Replay func_info / line_info from the byte buffers we captured at
     * intercept time — the loader's original user pointers reference
     * memory that's likely freed by now. */
    a.func_info = (uintptr_t)p->func_info_buf;
    a.func_info_cnt = p->func_info_cnt;
    a.func_info_rec_size = p->func_info_rec_size;
    a.line_info = (uintptr_t)p->line_info_buf;
    a.line_info_cnt = p->line_info_cnt;
    a.line_info_rec_size = p->line_info_rec_size;
    /* core_relos are consumed by libbpf in userspace BEFORE PROG_LOAD; the
     * kernel never reads them. Safe to zero. */
    a.core_relos = 0;
    a.core_relo_cnt = 0;
    a.core_relo_rec_size = 0;
    /* BPF_F_TOKEN_FD requires a live token fd; the loader's may have been
     * closed and we don't have a kid for it. Drop the flag — kernel falls
     * back to system-wide capability checks. Hard-coded bit (1U<<8) so this
     * works even when libbpf-sys is too old to expose the constant. */
    a.prog_flags &= ~((uint32_t)(1U << 8));
    log_line("reload prog kid=%u type=%u prog_btf_fd=%u attach_btf_obj_fd=%u "
             "attach_prog_fd=%u attach_btf_id=%u expected_attach=%u "
             "nr_map_fds=%u",
             p->kernel_prog_id, p->prog_type, a.prog_btf_fd,
             a.attach_btf_obj_fd, a.attach_prog_fd, a.attach_btf_id,
             a.expected_attach_type, nr_fds);
    /* log_level=1 is enough for reload — we only need to diagnose verifier
     * rejection (last failure line). Detailed state dumps for downstream
     * passes are produced separately by capture_verifier_states() at
     * log_level=2. Large progs (e.g. katran balancer 67939 insns) overflow
     * even a 16 MB buffer at log_level=2, causing -ENOSPC even when the
     * bytecode is valid. */
    a.log_level = 1;
    a.log_buf = (uintptr_t)log_buf;
    /* Reserve 128B at the tail so we can always append errno post-failure. */
    a.log_size = (uint32_t)(log_size > 128 ? log_size - 128 : log_size);
    a.log_true_size = 0;
    if (fd_array) a.fd_array = (uintptr_t)fd_array;

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    long new_pfd = real_syscall(SYS_bpf, BPF_PROG_LOAD, &a, sizeof(a));
    int load_errno = (new_pfd < 0) ? errno : 0;

    /* Snapshot the fd_array (before freeing) so the failure context below
     * can report how many slots were -1. */
    uint32_t arr_neg1 = 0;
    if (fd_array) {
        for (uint32_t i = 0; i < fd_array_n; i++)
            if (fd_array[i] < 0) arr_neg1++;
    }
    free_full_fd_array(fd_array, fd_array_n);
    free(insns);
    /* Drop the per-reload BTF/prog fds — kernel held refs across the
     * syscall; our fds are not needed afterwards. */
    if (prog_btf_resolved >= 0) real_close(prog_btf_resolved);
    if (attach_btf_obj_resolved >= 0) real_close(attach_btf_obj_resolved);
    if (attach_prog_resolved >= 0) real_close(attach_prog_resolved);

    if (new_pfd < 0) {
        /* Always append the actual errno — verifier may have accepted (so the
         * log shows a success summary) yet PROG_LOAD still failed in a later
         * stage (JIT, attach validation, BTF resolution). The errno is the
         * only useful signal in those cases. */
        /* log_size includes the 128B reserved tail; lg is bounded by the
         * shrunk window passed to the kernel, so we always have room. */
        size_t lg = strnlen(log_buf, log_size);
        snprintf(log_buf + lg, log_size - lg,
                 "\nBPF_PROG_LOAD errno=%d (post-verifier)\n"
                 "ctx: prog_btf_fd=%u attach_btf_obj_fd=%u attach_prog_fd=%u "
                 "attach_btf_id=%u expected_attach=%u nr_map_fds=%u "
                 "prog_type=%u fd_array_n=%u fd_array_neg1=%u "
                 "prog_flags=0x%x insn_cnt=%u\n",
                 load_errno,
                 a.prog_btf_fd, a.attach_btf_obj_fd, a.attach_prog_fd,
                 a.attach_btf_id, a.expected_attach_type, nr_fds,
                 p->prog_type, fd_array_n, arr_neg1,
                 a.prog_flags, a.insn_cnt);
        clock_gettime(CLOCK_MONOTONIC, &t1);
        if (out_rejit_ms) *out_rejit_ms = (t1.tv_sec - t0.tv_sec) * 1000ULL
                                          + (t1.tv_nsec - t0.tv_nsec) / 1000000;
        free(owned_log);
        return RELOAD_FAILED_REJIT;
    }

    /* Swap attaches. BPF_LINK_UPDATE is atomic per-link. */
    int partial = 0;
    pthread_mutex_lock(&state_mutex);
    /* Snapshot lists locally — reattach syscalls release state_mutex
     * via real_syscall (kernel side, not shim re-entry, but be safe). */
    uint32_t nlinks = p->n_links, nperfs = p->n_perfs;
    int *links = NULL, *perfs = NULL;
    if (nlinks) {
        links = (int *)malloc(nlinks * sizeof(int));
        if (links) memcpy(links, p->attached_link_fds, nlinks * sizeof(int));
        else nlinks = 0;
    }
    if (nperfs) {
        perfs = (int *)malloc(nperfs * sizeof(int));
        if (perfs) memcpy(perfs, p->attached_perf_fds, nperfs * sizeof(int));
        else nperfs = 0;
    }
    int old_prog_fd = p->fd;
    pthread_mutex_unlock(&state_mutex);

    /* Append per-failure detail into verifier_log (which the caller exposes
     * to the runner) so partial-attach errors are diagnostic, not opaque. */
    char *partial_detail = verifier_log;
    size_t partial_cap = log_buf_sz;
    size_t partial_len = partial_detail ? strnlen(partial_detail, partial_cap) : 0;
#define APPEND_DETAIL(...) do {                                              \
    if (partial_detail && partial_len < partial_cap - 1) {                   \
        int _n = snprintf(partial_detail + partial_len,                       \
                          partial_cap - partial_len, __VA_ARGS__);            \
        if (_n > 0) partial_len += (size_t)_n;                                \
        if (partial_len >= partial_cap) partial_len = partial_cap - 1;        \
    }                                                                         \
} while (0)
    /* Track new fds replacing old ones so the prog's attached_link_fds list
     * stays consistent after fallback-recreate. */
    int *replaced_with = (int *)malloc(nlinks * sizeof(int));
    if (replaced_with) for (uint32_t i = 0; i < nlinks; i++) replaced_with[i] = -1;
    for (uint32_t i = 0; i < nlinks; i++) {
        union bpf_attr u;
        memset(&u, 0, sizeof(u));
        u.link_update.link_fd = (uint32_t)links[i];
        u.link_update.new_prog_fd = (uint32_t)new_pfd;
        u.link_update.flags = 0;
        long r = real_syscall(SYS_bpf, BPF_LINK_UPDATE, &u, sizeof(u));
        if (r >= 0) continue;
        int upd_err = errno;
        /* Most BPF link types don't implement update_prog (only cgroup, tcx,
         * netns, bpf_iter do — see kernel/bpf/syscall.c). Fall back to:
         *   1. close(old_link_fd) — destroys the kernel attach
         *   2. BPF_LINK_CREATE with saved attrs and new prog_fd → new link
         *   3. record new fd so attached_link_fds reflects new state
         * The loader's old fd value becomes EBADF on subsequent use; for
         * benchmarks this is OK since the loader doesn't operate on links
         * during measurement. */
        pthread_mutex_lock(&state_mutex);
        struct link_entry *le = link_find(links[i]);
        char saved_blob[80];
        int have_blob = 0;
        if (le) {
            memcpy(saved_blob, le->create_attr_blob, sizeof(saved_blob));
            have_blob = 1;
        }
        pthread_mutex_unlock(&state_mutex);
        if (!have_blob) {
            log_line("reload_and_reattach: LINK_UPDATE failed and no saved "
                     "create attrs for link_fd=%d (errno=%d)",
                     links[i], upd_err);
            APPEND_DETAIL("link_fd=%d: LINK_UPDATE errno=%d, no saved attrs; ",
                          links[i], upd_err);
            partial = 1;
            continue;
        }
        union bpf_attr c;
        memset(&c, 0, sizeof(c));
        memcpy(&c.link_create, saved_blob, sizeof(c.link_create));
        c.link_create.prog_fd = (uint32_t)new_pfd;
        real_close(links[i]);
        long new_link = real_syscall(SYS_bpf, BPF_LINK_CREATE, &c, sizeof(c));
        if (new_link < 0) {
            int cre_err = errno;
            log_line("reload_and_reattach: LINK_UPDATE failed (errno=%d) and "
                     "fallback BPF_LINK_CREATE failed (errno=%d) for old_link_fd=%d",
                     upd_err, cre_err, links[i]);
            APPEND_DETAIL("link_fd=%d: LINK_UPDATE errno=%d, "
                          "LINK_CREATE fallback errno=%d (target_fd=%u attach=%u); ",
                          links[i], upd_err, cre_err,
                          c.link_create.target_fd, c.link_create.attach_type);
            partial = 1;
            continue;
        }
        if (replaced_with) replaced_with[i] = (int)new_link;
        log_line("reload_and_reattach: LINK_UPDATE→CREATE fallback OK "
                 "old_fd=%d → new_fd=%ld (errno=%d on update)",
                 links[i], new_link, upd_err);
    }
    /* Update the prog's attached_link_fds: replace each old fd with the new
     * one returned by the fallback (or leave as-is if UPDATE succeeded). */
    if (replaced_with) {
        pthread_mutex_lock(&state_mutex);
        for (uint32_t i = 0; i < nlinks; i++) {
            if (replaced_with[i] < 0) continue;
            for (uint32_t k = 0; k < p->n_links; k++) {
                if (p->attached_link_fds[k] == links[i]) {
                    p->attached_link_fds[k] = replaced_with[i];
                    break;
                }
            }
        }
        pthread_mutex_unlock(&state_mutex);
        free(replaced_with);
    }
    int *perf_replaced = (int *)malloc(nperfs * sizeof(int));
    if (perf_replaced) for (uint32_t i = 0; i < nperfs; i++) perf_replaced[i] = -1;
    for (uint32_t i = 0; i < nperfs; i++) {
        int r = real_ioctl(perfs[i], PERF_EVENT_IOC_SET_BPF,
                           (void *)(intptr_t)new_pfd);
        if (r == 0) continue;
        int set_err = errno;
        /* SET_BPF returns EEXIST when the event already has a BPF prog
         * attached (kernel doesn't support replacement). Fallback: close
         * old event, perf_event_open a fresh one with saved attrs,
         * SET_BPF the new prog. */
        pthread_mutex_lock(&state_mutex);
        struct perf_entry *pe = perf_find(perfs[i]);
        char saved_attr[256];
        uint32_t saved_attr_size = 0;
        int32_t saved_pid = 0, saved_cpu = 0, saved_group = -1;
        uint32_t saved_flags = 0;
        if (pe && pe->attr_size > 0) {
            memcpy(saved_attr, pe->attr_blob, pe->attr_size);
            saved_attr_size = pe->attr_size;
            saved_pid = pe->pid;
            saved_cpu = pe->cpu;
            saved_group = pe->group_fd;
            saved_flags = pe->open_flags;
        }
        pthread_mutex_unlock(&state_mutex);
        if (saved_attr_size == 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF errno=%d, no saved attrs; ",
                          perfs[i], set_err);
            partial = 1;
            continue;
        }
        real_close(perfs[i]);
        long new_perf_fd = real_syscall(SYS_perf_event_open,
                                         (long)(intptr_t)saved_attr,
                                         (long)saved_pid, (long)saved_cpu,
                                         (long)saved_group, (long)saved_flags, 0);
        if (new_perf_fd < 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF errno=%d, "
                          "perf_event_open fallback errno=%d (type=%llu config=%llu); ",
                          perfs[i], set_err, errno,
                          (unsigned long long)((struct perf_event_attr *)saved_attr)->type,
                          (unsigned long long)((struct perf_event_attr *)saved_attr)->config);
            partial = 1;
            continue;
        }
        /* Enable + attach the new prog. */
        (void)real_ioctl((int)new_perf_fd, PERF_EVENT_IOC_ENABLE, NULL);
        int sr = real_ioctl((int)new_perf_fd, PERF_EVENT_IOC_SET_BPF,
                            (void *)(intptr_t)new_pfd);
        if (sr != 0) {
            APPEND_DETAIL("perf_fd=%d: SET_BPF on new event errno=%d; ",
                          perfs[i], errno);
            real_close((int)new_perf_fd);
            partial = 1;
            continue;
        }
        if (perf_replaced) perf_replaced[i] = (int)new_perf_fd;
        log_line("reload_and_reattach: perf SET_BPF→reopen fallback OK "
                 "old_fd=%d → new_fd=%ld (errno=%d on initial SET_BPF)",
                 perfs[i], new_perf_fd, set_err);
    }
    /* Update attached_perf_fds to the new fds. */
    if (perf_replaced) {
        pthread_mutex_lock(&state_mutex);
        for (uint32_t i = 0; i < nperfs; i++) {
            if (perf_replaced[i] < 0) continue;
            for (uint32_t k = 0; k < p->n_perfs; k++) {
                if (p->attached_perf_fds[k] == perfs[i]) {
                    p->attached_perf_fds[k] = perf_replaced[i];
                    break;
                }
            }
        }
        pthread_mutex_unlock(&state_mutex);
        free(perf_replaced);
    }
#undef APPEND_DETAIL
    free(links);
    free(perfs);

    clock_gettime(CLOCK_MONOTONIC, &t1);
    if (out_rejit_ms) *out_rejit_ms = (t1.tv_sec - t0.tv_sec) * 1000ULL
                                      + (t1.tv_nsec - t0.tv_nsec) / 1000000;

    /* Resolve the new kernel id and commit the swap into prog_entry. The
     * old fd is closed so the kernel can release the old prog when no
     * link/perf_event still references it (after BPF_LINK_UPDATE, no link
     * should). */
    uint32_t new_kid = resolve_kernel_id((int)new_pfd);
    pthread_mutex_lock(&state_mutex);
    /* Reload p in case state was swapped under us (shouldn't happen during a
     * single execute_plan, but cheap to defensively re-lookup). */
    p->fd = (int)new_pfd;
    if (new_kid) p->kernel_prog_id = new_kid;
    pthread_mutex_unlock(&state_mutex);
    if (old_prog_fd >= 0 && old_prog_fd != (int)new_pfd)
        real_close(old_prog_fd);

    free(owned_log);
    return partial ? RELOAD_PARTIAL_ATTACH : RELOAD_OK;
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
/* JSON-escape `raw` of length `n` into `out` (size out_sz). Truncates to fit;
 * always NUL-terminates. Drops control chars below 0x20 except \n \r \t.
 * Encodes non-ASCII bytes (>=0x80) as \uXXXX to keep the output pure ASCII —
 * verifier logs frequently contain stray high bytes (pointer formatting,
 * truncated register-state dumps) that would otherwise produce invalid
 * UTF-8 and break JSON parsing on the runner side. */
static void json_escape_into(const char *raw, size_t n, char *out, size_t out_sz) {
    size_t o = 0;
    for (size_t i = 0; i < n && o + 8 < out_sz; i++) {
        unsigned char c = (unsigned char)raw[i];
        if (c == '"' || c == '\\') { out[o++] = '\\'; out[o++] = c; }
        else if (c == '\n') { out[o++] = '\\'; out[o++] = 'n'; }
        else if (c == '\r') { out[o++] = '\\'; out[o++] = 'r'; }
        else if (c == '\t') { out[o++] = '\\'; out[o++] = 't'; }
        else if (c >= 0x20 && c < 0x7f) out[o++] = (char)c;
        else if (c >= 0x80) {
            /* \uXXXX (6 chars). Need room. */
            if (o + 6 >= out_sz) break;
            static const char hex[] = "0123456789abcdef";
            out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
            out[o++] = hex[(c >> 4) & 0xf]; out[o++] = hex[c & 0xf];
        }
        /* drop other control chars 0x00-0x1f except \n\r\t */
    }
    out[o < out_sz ? o : out_sz - 1] = 0;
}

/* Read the tail of `path` (up to 1024 bytes), JSON-escape, store into `out`. */
static void read_tail_escaped(const char *path, char *out, size_t out_sz) {
    out[0] = 0;
    int lfd = open(path, O_RDONLY);
    if (lfd < 0) return;
    struct stat st;
    if (fstat(lfd, &st) == 0 && st.st_size > 0) {
        off_t off = st.st_size > 1024 ? st.st_size - 1024 : 0;
        lseek(lfd, off, SEEK_SET);
        char raw[1025];
        ssize_t n = read(lfd, raw, sizeof(raw) - 1);
        if (n > 0) json_escape_into(raw, (size_t)n, out, out_sz);
    }
    real_close(lfd);
}

/* Per-step outcome from the inner execute_plan loop. */
struct step_result {
    int ok;
    int code;                       /* subprocess exit code */
    int failure_kind;               /* 0=none, 1=bpfopt, 2=rejit, 3=partial-reattach */
    uint64_t bpfopt_ms;
    uint64_t rejit_ms;              /* 0 if no reload attempted */
    char err_msg[2048];
    char report_path[320];
    char output_path[320];
};

/* Run one bpfopt pass on a prog. Updates `cur` (input bytecode path) and
 * `step_seq` on success and after successful reload_and_reattach. */
static void run_step(struct prog_entry *pd,
                     const char *workdir, const char *prog_type_name,
                     const char *prog_id_str, const char *target_json,
                     const char *map_ids_csv, const char *map_values_dir,
                     uint32_t *local_kernel_ids, uint32_t nr_maps,
                     char *cur, const char *nxt, const char *report,
                     int *step_seq, const char *step_name,
                     const char *command, struct step_result *out) {
    memset(out, 0, sizeof(*out));
    (void)step_name;
    snprintf(out->report_path, sizeof(out->report_path), "%s", report);
    snprintf(out->output_path, sizeof(out->output_path), "%s", cur);

    char verifier_states_in[320], verifier_log[320];
    if (*step_seq == 0)
        snprintf(verifier_states_in, sizeof(verifier_states_in),
                 "%s/verifier_log_initial.log", workdir);
    else
        snprintf(verifier_states_in, sizeof(verifier_states_in),
                 "%s/verifier_log_step%d.log", workdir, *step_seq - 1);
    snprintf(verifier_log, sizeof(verifier_log),
             "%s/verifier_log_step%d.log", workdir, *step_seq);
    unlink(nxt);

    const char *vars[10][2] = {
        {"PROG_ID", prog_id_str}, {"PROG_TYPE", prog_type_name},
        {"INPUT", cur}, {"OUTPUT", nxt}, {"REPORT", report},
        {"WORKDIR", workdir}, {"TARGET", target_json},
        {"MAP_IDS", map_ids_csv}, {"MAP_VALUES", map_values_dir},
        {"VERIFIER_STATES", verifier_states_in},
    };
    char resolved[4200];
    substitute_vars(resolved, sizeof(resolved), command, vars, 10);

    /* /bin/sh -c <resolved> with LD_PRELOAD stripped, stdout+stderr to log */
    size_t n_env = 0; while (environ[n_env]) n_env++;
    char **clean_env = (char **)calloc(n_env + 1, sizeof(char *));
    size_t j = 0;
    for (size_t i = 0; clean_env && i < n_env; i++)
        if (strncmp(environ[i], "LD_PRELOAD=", 11) != 0)
            clean_env[j++] = environ[i];
    if (clean_env) clean_env[j] = NULL;
    char subproc_log[320];
    snprintf(subproc_log, sizeof(subproc_log), "%s/step%d.log", workdir, *step_seq);
    char *const argv[] = {"/bin/sh", "-c", resolved, NULL};
    posix_spawn_file_actions_t fa;
    int fa_inited = (posix_spawn_file_actions_init(&fa) == 0);
    if (fa_inited) {
        posix_spawn_file_actions_addopen(&fa, STDOUT_FILENO, subproc_log,
                                         O_WRONLY | O_CREAT | O_TRUNC, 0644);
        posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, subproc_log,
                                         O_WRONLY | O_APPEND, 0);
    }
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    pid_t pid;
    int rc = posix_spawn(&pid, "/bin/sh", fa_inited ? &fa : NULL, NULL, argv,
                         clean_env ? clean_env : environ);
    if (fa_inited) posix_spawn_file_actions_destroy(&fa);
    free(clean_env);
    if (rc != 0) {
        out->failure_kind = 1;
        snprintf(out->err_msg, sizeof(out->err_msg), "spawn failed rc=%d", rc);
        return;
    }
    int status = 0;
    waitpid(pid, &status, 0);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    out->bpfopt_ms = (uint64_t)(t1.tv_sec - t0.tv_sec) * 1000ULL
                     + (uint64_t)((t1.tv_nsec - t0.tv_nsec) / 1000000);
    int bpfopt_ok = WIFEXITED(status) && WEXITSTATUS(status) == 0;
    out->code = WIFEXITED(status) ? WEXITSTATUS(status) : -1;

    if (!bpfopt_ok) {
        out->failure_kind = 1;
        read_tail_escaped(subproc_log, out->err_msg, sizeof(out->err_msg));
        return;
    }

    /* bpfopt produced output? If empty, this is a utility step; advance seq
     * but do nothing to kernel. */
    struct stat nst;
    if (stat(nxt, &nst) != 0 || nst.st_size == 0) {
        out->ok = 1;
        return;
    }

    /* New bytecode in nxt → reload + reattach + capture verifier states.
     * 16 MB matches daemon's REJIT_VERBOSE_LOG_BUF_SIZE — large progs (e.g.
     * katran balancer.bpf.o, 67939 insns) overflow a 1 MB buffer at
     * log_level=2 and the kernel returns -ENOSPC, masking the real cause. */
    const size_t verifier_buf_sz = 16 * 1024 * 1024;
    char *verifier_buf = (char *)malloc(verifier_buf_sz);
    if (!verifier_buf) {
        out->failure_kind = 2;
        snprintf(out->err_msg, sizeof(out->err_msg),
                 "verifier log buffer alloc failed");
        return;
    }
    enum reload_status rs = reload_and_reattach(pd, nxt, target_json,
                                                local_kernel_ids, nr_maps,
                                                verifier_buf,
                                                verifier_buf_sz,
                                                &out->rejit_ms);
    if (rs == RELOAD_FAILED_REJIT) {
        out->failure_kind = 2;
        size_t vl = strnlen(verifier_buf, verifier_buf_sz);
        /* Capture the tail of the verifier log — the actual error message
         * comes LAST, before the summary line. */
        const char *tail = verifier_buf;
        size_t tail_n = vl;
        if (vl > 1800) { tail = verifier_buf + (vl - 1800); tail_n = 1800; }
        json_escape_into(tail, tail_n, out->err_msg, sizeof(out->err_msg));
        free(verifier_buf);
        return;
    }
    if (rs == RELOAD_PARTIAL_ATTACH) {
        out->failure_kind = 3;
        size_t vl = strnlen(verifier_buf, verifier_buf_sz);
        if (vl > 0) {
            const char *tail = verifier_buf;
            size_t tail_n = vl;
            if (vl > 1800) { tail = verifier_buf + (vl - 1800); tail_n = 1800; }
            json_escape_into(tail, tail_n, out->err_msg, sizeof(out->err_msg));
        } else {
            snprintf(out->err_msg, sizeof(out->err_msg),
                     "BPF_PROG_LOAD ok but ≥1 reattach failed (no detail)");
        }
        free(verifier_buf);
        return;
    }
    if (rs != RELOAD_OK) {
        out->failure_kind = 2;
        snprintf(out->err_msg, sizeof(out->err_msg),
                 "reload_and_reattach internal error");
        free(verifier_buf);
        return;
    }
    free(verifier_buf);

    /* Write the new prog's verifier log for the next step. */
    capture_verifier_states(pd, nxt, target_json, local_kernel_ids, nr_maps,
                            verifier_log);
    rename(nxt, cur);
    pthread_mutex_lock(&state_mutex);
    pd->step_seq = *step_seq + 1;
    pthread_mutex_unlock(&state_mutex);
    (*step_seq)++;
    out->ok = 1;
}

/* Per-program setup performed before the step loop. Returns 0 on success or
 * fills `*err_out` and returns -1. */
struct prog_workdir {
    char workdir[280];
    char cur[320], nxt[320], report[320], target_json[320];
    char map_values_dir[320];
};

static int prog_workdir_init(struct prog_entry *pd, uint32_t want_id,
                             struct prog_workdir *w,
                             uint32_t **out_local_ids, uint32_t **out_local_types,
                             uint32_t **out_local_loader_fds, uint32_t *out_nr_maps,
                             char *map_ids_csv, size_t map_ids_csv_sz,
                             char *err_out, size_t err_sz) {
    pthread_mutex_lock(&state_mutex);
    (void)dedup_snapshot_by_kid(pd->snap_fds, pd->snap_kids, pd->snap_types,
                                pd->snap_n, out_local_ids, out_local_types,
                                out_local_loader_fds, out_nr_maps);
    uint32_t fd2id_n = pd->snap_n;
    uint32_t *fd2id_fds = NULL, *fd2id_kids = NULL;
    if (fd2id_n > 0) {
        fd2id_fds = (uint32_t *)malloc(fd2id_n * sizeof(uint32_t));
        fd2id_kids = (uint32_t *)malloc(fd2id_n * sizeof(uint32_t));
        if (fd2id_fds && fd2id_kids) {
            memcpy(fd2id_fds, pd->snap_fds, fd2id_n * sizeof(uint32_t));
            memcpy(fd2id_kids, pd->snap_kids, fd2id_n * sizeof(uint32_t));
        } else {
            free(fd2id_fds); free(fd2id_kids);
            fd2id_fds = fd2id_kids = NULL;
            fd2id_n = 0;
        }
    }
    int canonicalized = pd->canonicalized;
    char bytecode_path[256];
    snprintf(bytecode_path, sizeof(bytecode_path), "%s", pd->bytecode_path);
    pthread_mutex_unlock(&state_mutex);

    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    const char *arch = getenv("BPFREJIT_TARGET_ARCH");
    if (!arch) arch = "x86_64";
    snprintf(w->workdir, sizeof(w->workdir), "%s/work_%u", dir, want_id);
    mkdir(w->workdir, 0755);
    snprintf(w->cur, sizeof(w->cur), "%s/output.bin", w->workdir);
    snprintf(w->nxt, sizeof(w->nxt), "%s/output.next.bin", w->workdir);
    snprintf(w->report, sizeof(w->report), "%s/report.json", w->workdir);
    snprintf(w->target_json, sizeof(w->target_json), "%s/target.json", w->workdir);
    snprintf(w->map_values_dir, sizeof(w->map_values_dir), "%s/map-values", w->workdir);

    /* Per-prog target.json: copy from kinsnprober output once. */
    struct stat tst;
    if (stat(w->target_json, &tst) != 0) {
        char shared[320];
        snprintf(shared, sizeof(shared), "%s/target.json", dir);
        int sfd = open(shared, O_RDONLY);
        int wrote = 0;
        if (sfd >= 0) {
            int dfd = open(w->target_json, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (dfd >= 0) {
                char buf[4096]; ssize_t n;
                while ((n = read(sfd, buf, sizeof(buf))) > 0)
                    (void)!write(dfd, buf, n);
                close(dfd);
                wrote = 1;
            }
            real_close(sfd);
        }
        if (!wrote) {
            int fd = open(w->target_json, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd >= 0) {
                char buf[64];
                int n = snprintf(buf, sizeof(buf),
                                 "{\"arch\":\"%s\",\"kinsns\":{}}\n", arch);
                (void)!write(fd, buf, n);
                close(fd);
            }
        }
    }

    format_map_ids_csv(*out_local_ids, *out_nr_maps, map_ids_csv, map_ids_csv_sz);

    if (!canonicalized) {
        char canon_log[320], fd_to_id_path[320];
        snprintf(canon_log, sizeof(canon_log), "%s/canonicalize.log", w->workdir);
        snprintf(fd_to_id_path, sizeof(fd_to_id_path), "%s/fd-to-id.json", w->workdir);
        (void)write_fd_to_id_json(fd_to_id_path, fd2id_fds, fd2id_kids, fd2id_n);
        if (run_canonicalize(bytecode_path, w->cur, w->target_json, map_ids_csv,
                             fd_to_id_path, canon_log) != 0) {
            char err_tail[1024] = {0};
            read_tail_escaped(canon_log, err_tail, sizeof(err_tail));
            snprintf(err_out, err_sz,
                     "bpfopt --canonicalize-map-refs failed: %s", err_tail);
            free(fd2id_fds); free(fd2id_kids);
            return -1;
        }
        write_map_snapshots(w->map_values_dir, *out_local_ids, *out_local_types,
                            *out_nr_maps);
        pthread_mutex_lock(&state_mutex);
        pd->canonicalized = 1;
        pthread_mutex_unlock(&state_mutex);
    }
    free(fd2id_fds); free(fd2id_kids);
    return 0;
}

/* Append printf-style content to a growing heap buffer. Returns 0 on success,
 * -1 on OOM (in which case *buf is freed). */
static int buf_appendf(char **buf, size_t *cap, size_t *len, const char *fmt, ...) {
    for (;;) {
        va_list ap;
        va_start(ap, fmt);
        int n = vsnprintf(*buf + *len, *cap - *len, fmt, ap);
        va_end(ap);
        if (n < 0) return -1;
        if ((size_t)n < *cap - *len) { *len += (size_t)n; return 0; }
        size_t want = *cap * 2;
        if (want < *cap + (size_t)n + 1) want = *cap + (size_t)n + 1;
        char *nr = (char *)realloc(*buf, want);
        if (!nr) { free(*buf); *buf = NULL; return -1; }
        *buf = nr;
        *cap = want;
    }
}

/* execute_plan — replaces daemon's execute_plan RPC. Input plan JSON:
 *   {"cmd":"execute_plan",
 *    "programs":[{"prog_id":N,
 *                 "steps":[{"name":"...","command":"...","log_level":N}]}]}
 * Response (same shape as daemon's): {"status":"ok","per_program":{...}}. */
static void emit_execute_plan(int cli, const char *json) {
    const char *progs_end = NULL;
    const char *progs = json_array_at(json, "programs", &progs_end);
    if (!progs) {
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"missing programs\"}\n");
        return;
    }

    size_t cap = 65536, len = 0;
    char *resp = (char *)malloc(cap);
    if (!resp) {
        dprintf(cli, "{\"status\":\"error\",\"error_message\":\"oom\"}\n");
        return;
    }
    if (buf_appendf(&resp, &cap, &len, "{\"status\":\"ok\",\"per_program\":{") != 0)
        goto resp_oom;

    const char *cursor = progs;
    const char *po_s, *po_e;
    int first_prog = 1;
    while (json_array_next_obj(&cursor, progs_end, &po_s, &po_e)) {
        size_t plen = (size_t)(po_e - po_s);
        char *po = (char *)malloc(plen + 1);
        if (!po) continue;
        memcpy(po, po_s, plen); po[plen] = 0;

        long pid_l = json_get_int(po, "prog_id");
        if (pid_l <= 0) { free(po); continue; }
        uint32_t want_id = (uint32_t)pid_l;
        char prog_id_str[32];
        snprintf(prog_id_str, sizeof(prog_id_str), "%u", want_id);

        pthread_mutex_lock(&state_mutex);
        struct prog_entry *pd = prog_find_by_kernel_id(want_id);
        char prog_type_name[32] = "socket_filter";
        char prog_name[17] = {0};
        uint32_t orig_insn_count = 0, prog_type_num = 0;
        if (pd) {
            snprintf(prog_type_name, sizeof(prog_type_name), "%s",
                     prog_type_short_name(pd->prog_type));
            memcpy(prog_name, pd->name, sizeof(prog_name));
            prog_type_num = pd->prog_type;
            orig_insn_count = pd->insn_cnt;
        }
        pthread_mutex_unlock(&state_mutex);

        if (buf_appendf(&resp, &cap, &len, "%s\"%u\":{",
                        first_prog ? "" : ",", want_id) != 0) {
            free(po);
            goto resp_oom;
        }
        first_prog = 0;

        if (!pd) {
            buf_appendf(&resp, &cap, &len,
                        "\"status\":\"error\","
                        "\"error_message\":\"prog_id %u not tracked by shim pid=%d\","
                        "\"prog_id\":%u,"
                        "\"program\":{\"prog_id\":%u,\"prog_name\":\"\","
                        "\"prog_type\":0,\"orig_insn_count\":0,"
                        "\"final_insn_count\":0},"
                        "\"passes\":[]}",
                        want_id, getpid(), want_id, want_id);
            free(po);
            continue;
        }

        /* Per-prog setup (canonicalize + map snapshots) — once per prog. */
        struct prog_workdir w;
        uint32_t nr_maps = 0;
        uint32_t *local_ids = NULL, *local_types = NULL, *local_loader_fds = NULL;
        char map_ids_csv[1024];
        char setup_err[1024] = {0};
        int setup_rc = prog_workdir_init(pd, want_id, &w, &local_ids,
                                         &local_types, &local_loader_fds,
                                         &nr_maps, map_ids_csv,
                                         sizeof(map_ids_csv),
                                         setup_err, sizeof(setup_err));
        if (setup_rc != 0) {
            char escaped[1024];
            json_escape_into(setup_err, strlen(setup_err), escaped, sizeof(escaped));
            buf_appendf(&resp, &cap, &len,
                        "\"status\":\"error\","
                        "\"error_message\":\"%s\","
                        "\"prog_id\":%u,"
                        "\"program\":{\"prog_id\":%u,\"prog_name\":\"%s\","
                        "\"prog_type\":%u,\"orig_insn_count\":%u,"
                        "\"final_insn_count\":%u},"
                        "\"passes\":[]}",
                        escaped, want_id, want_id, prog_name, prog_type_num,
                        orig_insn_count, orig_insn_count);
            free(local_ids); free(local_types); free(local_loader_fds);
            free(po);
            continue;
        }

        /* Step loop. */
        int prog_any_failed = 0;
        uint32_t final_insn_count = orig_insn_count;
        int step_seq = 0;
        pthread_mutex_lock(&state_mutex);
        if (pd) step_seq = pd->step_seq;
        pthread_mutex_unlock(&state_mutex);

        const char *steps_end = NULL;
        const char *steps = json_array_at(po, "steps", &steps_end);
        const char *scur = steps;
        const char *so_s, *so_e;
        int first_step = 1;
        buf_appendf(&resp, &cap, &len, "\"prog_id\":%u,\"passes\":[", want_id);
        while (steps && json_array_next_obj(&scur, steps_end, &so_s, &so_e)) {
            size_t slen = (size_t)(so_e - so_s);
            char *so = (char *)malloc(slen + 1);
            if (!so) continue;
            memcpy(so, so_s, slen); so[slen] = 0;
            char name[64] = {0};
            char cmdbuf[4096] = {0};
            json_get_str(so, "name", name, sizeof(name));
            json_get_str(so, "command", cmdbuf, sizeof(cmdbuf));
            free(so);

            struct step_result sr;
            run_step(pd, w.workdir, prog_type_name, prog_id_str, w.target_json,
                     map_ids_csv, w.map_values_dir, local_ids, nr_maps,
                     w.cur, w.nxt, w.report, &step_seq, name, cmdbuf, &sr);

            /* On success-with-new-bytecode, compute final_insn_count from cur. */
            struct stat cst;
            if (stat(w.cur, &cst) == 0 && cst.st_size > 0)
                final_insn_count = (uint32_t)(cst.st_size / sizeof(struct bpf_insn));

            if (!sr.ok) prog_any_failed = 1;
            buf_appendf(&resp, &cap, &len,
                        "%s{\"step\":{\"name\":\"%s\"},"
                        "\"status\":\"%s\","
                        "\"bpfopt_ms\":%lu,\"rejit_syscall_ms\":%lu",
                        first_step ? "" : ",",
                        name, sr.ok ? "ok" : "error",
                        (unsigned long)sr.bpfopt_ms,
                        (unsigned long)sr.rejit_ms);
            if (!sr.ok) {
                const char *fk = (sr.failure_kind == 1) ? "bpfopt"
                               : (sr.failure_kind == 2) ? "rejit"
                               : (sr.failure_kind == 3) ? "rejit_partial"
                                                        : "internal";
                /* err_msg already json-escaped + bounded to 2 KB. We do NOT
                 * include workdir_tar_b64 — base64-encoded tarballs of large
                 * prog workdirs (verifier logs, map dumps, bytecode) explode
                 * to hundreds of MB per step and overflow the socket
                 * response buffer. Failure tar is left on-disk under
                 * /tmp/work_<prog_id>/ for KEEP_WORKDIRS=1 collection. */
                buf_appendf(&resp, &cap, &len,
                            ",\"failure_kind\":\"%s\","
                            "\"error\":\"%s\","
                            "\"exit_code\":%d",
                            fk, sr.err_msg, sr.code);
            }
            buf_appendf(&resp, &cap, &len, "}");
            first_step = 0;
        }
        buf_appendf(&resp, &cap, &len,
                    "],\"status\":\"%s\","
                    "\"program\":{\"prog_id\":%u,\"prog_name\":\"%s\","
                    "\"prog_type\":%u,\"orig_insn_count\":%u,"
                    "\"final_insn_count\":%u}}",
                    prog_any_failed ? "error" : "ok",
                    want_id, prog_name, prog_type_num,
                    orig_insn_count, final_insn_count);

        free(local_ids); free(local_types); free(local_loader_fds);
        free(po);
        log_line("execute_plan prog_id=%u step_seq=%d status=%s",
                 want_id, step_seq, prog_any_failed ? "error" : "ok");
    }
    buf_appendf(&resp, &cap, &len, "}}\n");
    if (resp) (void)!write(cli, resp, len);
    free(resp);
    return;

resp_oom:
    dprintf(cli, "{\"status\":\"error\",\"error_message\":\"response oom\"}\n");
    free(resp);
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
    /* The runner can send arbitrarily large execute_plan payloads (e.g. tracee
     * with 158 progs × 18 steps × per-step bash command can exceed 100 KB).
     * Read until newline so we never truncate a request mid-JSON. */
    size_t cap = 16 * 1024;
    size_t len = 0;
    char *buf = (char *)malloc(cap);
    if (!buf) {
        dprintf(cli, "{\"ok\":false,\"error\":\"shim oom on request buf\"}\n");
        return;
    }
    while (1) {
        if (len + 1 >= cap) {
            size_t ncap = cap * 2;
            char *nb = (char *)realloc(buf, ncap);
            if (!nb) {
                free(buf);
                dprintf(cli, "{\"ok\":false,\"error\":\"shim oom on request grow\"}\n");
                return;
            }
            buf = nb; cap = ncap;
        }
        ssize_t n = read(cli, buf + len, cap - len - 1);
        if (n < 0) {
            if (errno == EINTR) continue;
            free(buf);
            return;
        }
        if (n == 0) break;
        len += (size_t)n;
        buf[len] = 0;
        if (memchr(buf, '\n', len) != NULL) break;
    }
    if (len == 0) { free(buf); return; }
    char cmd[64] = {0};
    if (!json_get_str(buf, "cmd", cmd, sizeof(cmd))) {
        dprintf(cli, "{\"ok\":false,\"error\":\"missing cmd\"}\n");
        free(buf);
        return;
    }
    log_line("socket: cmd=%s len=%zu", cmd, len);
    if (strcmp(cmd, "list_progs") == 0)
        emit_list_progs(cli);
    else if (strcmp(cmd, "execute_plan") == 0)
        emit_execute_plan(cli, buf);
    else if (strcmp(cmd, "dump_state") == 0)
        emit_dump_state(cli);
    else
        dprintf(cli, "{\"ok\":false,\"error\":\"unknown cmd: %s\"}\n", cmd);
    free(buf);
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
