#ifndef BPFREJIT_SHIM_STATE_H
#define BPFREJIT_SHIM_STATE_H

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
    uint64_t measure_run_cnt;
    uint64_t measure_run_time_ns;
    uint32_t measure_bytes_jited;
    uint32_t measure_bytes_xlated;
    uint32_t measure_prog_id;
    uint32_t measure_generation;
    int measure_active;
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
    /* Per-prog execute_plan state. */
    int canonicalized;            /* 1 once --canonicalize-map-refs has run */
    int step_seq;                 /* incremented per successful execute_plan step */
    int discovered_from_fd;       /* raw-syscall loader: discovered via /proc/self/fd */
    int map_refs_are_kernel_ids;  /* bytecode map refs carry kernel map ids */
    /* Snapshot of map_table at PROG_LOAD time — libbpf may close the map fds
     * shortly after load (especially when handling map-in-map relocations or
     * temporary metadata fds), but the bytecode still references those fd
     * VALUES. We freeze them here so the fd-to-id mapping survives the close. */
    uint32_t *snap_fds;
    uint32_t *snap_kids;
    uint32_t *snap_types;
    uint32_t snap_n;
    /* Live attach points for this prog. Populated by BPF_LINK_CREATE post-call,
     * BPF_PROG_ATTACH post-call, BPF_RAW_TRACEPOINT_OPEN post-call, and
     * PERF_EVENT_IOC_SET_BPF post-ioctl; fd-backed entries are pruned by
     * close() intercept. Used by reload_and_reattach to know what kernel attach
     * object must be pointed at the new prog fd. */
    int *attached_link_fds;
    uint32_t n_links;
    int *attached_perf_fds;
    uint32_t n_perfs;
    struct prog_attach_point *prog_attaches;
    uint32_t n_prog_attaches;
    int *attached_raw_tp_fds;
    uint32_t n_raw_tps;
    /* XDP netlink attachments captured by intercepting sendmsg/sendto on
     * AF_NETLINK / NETLINK_ROUTE sockets when the message carries an
     * RTM_SETLINK IFLA_XDP attribute. reload_and_reattach() iterates
     * this list and re-issues RTM_SETLINK with the new prog_fd; without
     * this path the netdev keeps dispatching to the original prog and
     * any ReJIT bytecode change is invisible to the workload. */
    struct xdp_nl_attach *xdp_attaches;
    uint32_t n_xdp;
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

/* ---- legacy BPF_PROG_ATTACH points (cgroup, flow dissector, etc.) ---- */
struct prog_attach_point {
    int target_fd;
    uint32_t attach_type;
    uint32_t attach_flags;
};

/* ---- BPF_RAW_TRACEPOINT_OPEN fd table ---- */
struct raw_tp_entry {
    int fd;
    struct raw_tp_entry *next;
    uint32_t prog_fd;
    char name[128];
};
static struct raw_tp_entry *raw_tp_table[BPF_STATE_BUCKETS];

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
DECLARE_FD_TABLE_OPS(raw_tp, struct raw_tp_entry, raw_tp_table)
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
    free(e->prog_attaches);
    free(e->attached_raw_tp_fds);
    free(e->func_info_buf);
    free(e->line_info_buf);
    free(e->xdp_attaches);
    free(e);
}

/* Append a legacy BPF_PROG_ATTACH point to a prog. Caller holds state_mutex. */
static int prog_attach_point_append(struct prog_attach_point **items,
                                    uint32_t *n,
                                    struct prog_attach_point point) {
    for (uint32_t i = 0; i < *n; i++)
        if ((*items)[i].target_fd == point.target_fd &&
            (*items)[i].attach_type == point.attach_type)
            return 0;
    if (*n == 0 || ((*n) & ((*n) - 1)) == 0) {
        uint32_t cap = (*n == 0) ? 4 : (*n) * 2;
        struct prog_attach_point *ni =
            (struct prog_attach_point *)realloc(*items, cap * sizeof(*ni));
        if (!ni) return -1;
        *items = ni;
    }
    (*items)[(*n)++] = point;
    return 0;
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

/* Walk every prog_entry and drop `fd` from its fd-backed attach lists. Cheap
 * since we usually have few progs. Caller holds mutex. */
static void prog_table_drop_attach_fd(int fd) {
    for (int b = 0; b < BPF_STATE_BUCKETS; b++)
        for (struct prog_entry *e = prog_table[b]; e; e = e->next) {
            prog_attach_drop(e->attached_link_fds, &e->n_links, fd);
            prog_attach_drop(e->attached_perf_fds, &e->n_perfs, fd);
            prog_attach_drop(e->attached_raw_tp_fds, &e->n_raw_tps, fd);
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

static void prog_forget_loader_fd(int fd) {
    if (fd < 0) return;
    struct prog_entry *e = prog_find(fd);
    if (!e) return;
    if (e->kernel_prog_id) {
        e->fd = -(int)e->kernel_prog_id;
    } else {
        prog_remove(fd);
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
#define ATTR_HAS_FIELD(ATTR_SIZE, FIELD) \
    ((ATTR_SIZE) >= (offsetof(union bpf_attr, FIELD) + sizeof(((union bpf_attr *)0)->FIELD)))

static struct prog_entry *capture_prog_load(const union bpf_attr *attr,
                                            unsigned int attr_size) {
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
    e->expected_attach_type = ATTR_HAS_FIELD(attr_size, expected_attach_type)
                                  ? attr->expected_attach_type
                                  : 0;
    e->attach_btf_id = ATTR_HAS_FIELD(attr_size, attach_btf_id)
                           ? attr->attach_btf_id
                           : 0;
    memset(&e->load_attr, 0, sizeof(e->load_attr));
    memcpy(&e->load_attr, attr,
           attr_size < sizeof(e->load_attr) ? attr_size : sizeof(e->load_attr));
    /* Resolve fd-typed attr fields to kernel IDs while the originals are
     * still valid (just before the syscall fires). dup() doesn't survive
     * because long-lived loaders (tracee) call close_range() after init.
     * Reload re-resolves these IDs back to fresh fds via *_GET_FD_BY_ID. */
    e->prog_btf_kid = 0;
    e->attach_btf_obj_kid = 0;
    e->attach_prog_kid = 0;
    if (ATTR_HAS_FIELD(attr_size, prog_btf_fd) && attr->prog_btf_fd) {
        struct bpf_btf_info bi = {0};
        union bpf_attr ia = {0};
        ia.info.bpf_fd = attr->prog_btf_fd;
        ia.info.info_len = sizeof(bi);
        ia.info.info = (uintptr_t)&bi;
        if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) >= 0)
            e->prog_btf_kid = bi.id;
    }
    if (ATTR_HAS_FIELD(attr_size, attach_btf_obj_fd) &&
        attr->attach_btf_obj_fd) {
        struct bpf_btf_info bi = {0};
        union bpf_attr ia = {0};
        ia.info.bpf_fd = attr->attach_btf_obj_fd;
        ia.info.info_len = sizeof(bi);
        ia.info.info = (uintptr_t)&bi;
        if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) >= 0)
            e->attach_btf_obj_kid = bi.id;
    }
    if (ATTR_HAS_FIELD(attr_size, attach_prog_fd) && attr->attach_prog_fd) {
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
    if (ATTR_HAS_FIELD(attr_size, func_info) &&
        ATTR_HAS_FIELD(attr_size, func_info_cnt) &&
        ATTR_HAS_FIELD(attr_size, func_info_rec_size) &&
        attr->func_info && attr->func_info_cnt && attr->func_info_rec_size) {
        size_t n = (size_t)attr->func_info_cnt * attr->func_info_rec_size;
        e->func_info_buf = malloc(n);
        if (e->func_info_buf) {
            memcpy(e->func_info_buf, (void *)(uintptr_t)attr->func_info, n);
            e->func_info_cnt = attr->func_info_cnt;
            e->func_info_rec_size = attr->func_info_rec_size;
        }
    }
    if (ATTR_HAS_FIELD(attr_size, line_info) &&
        ATTR_HAS_FIELD(attr_size, line_info_cnt) &&
        ATTR_HAS_FIELD(attr_size, line_info_rec_size) &&
        attr->line_info && attr->line_info_cnt && attr->line_info_rec_size) {
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

#undef ATTR_HAS_FIELD

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

static struct raw_tp_entry *capture_raw_tp_open(const union bpf_attr *attr) {
    struct raw_tp_entry *e = (struct raw_tp_entry *)calloc(1, sizeof(*e));
    if (!e) return NULL;
    e->fd = -1;
    e->prog_fd = attr->raw_tracepoint.prog_fd;
    const char *name = (const char *)(uintptr_t)attr->raw_tracepoint.name;
    if (name)
        snprintf(e->name, sizeof(e->name), "%s", name);
    log_line("BPF_RAW_TRACEPOINT_OPEN name=%s prog_fd=%u", e->name, e->prog_fd);
    return e;
}

/* Host linux/bpf.h may not have the fork-only bpf_prog_info tail. The fork
 * UAPI places orig_prog_len in host struct tail padding, so do not append to
 * struct bpf_prog_info directly. */
#define BPF_PROG_INFO_FORK_SIZE 240U
#define BPF_PROG_INFO_ORIG_PROG_LEN_OFF 228U
#define BPF_PROG_INFO_ORIG_PROG_INSNS_OFF 232U

struct bpf_prog_info_fork {
    uint8_t raw[BPF_PROG_INFO_FORK_SIZE];
};

static struct bpf_prog_info *prog_info_fork_base(struct bpf_prog_info_fork *info) {
    return (struct bpf_prog_info *)(void *)info->raw;
}

static uint32_t prog_info_fork_orig_len(const struct bpf_prog_info_fork *info) {
    uint32_t value = 0;
    memcpy(&value, info->raw + BPF_PROG_INFO_ORIG_PROG_LEN_OFF, sizeof(value));
    return value;
}

static void prog_info_fork_set_orig_len(struct bpf_prog_info_fork *info,
                                        uint32_t value) {
    memcpy(info->raw + BPF_PROG_INFO_ORIG_PROG_LEN_OFF, &value, sizeof(value));
}

static void prog_info_fork_set_orig_insns(struct bpf_prog_info_fork *info,
                                          uint64_t value) {
    memcpy(info->raw + BPF_PROG_INFO_ORIG_PROG_INSNS_OFF, &value,
           sizeof(value));
}

static int query_prog_info_fork(int fd, struct bpf_prog_info_fork *info) {
    memset(info, 0, sizeof(*info));
    union bpf_attr ia = {0};
    ia.info.bpf_fd = (uint32_t)fd;
    ia.info.info_len = sizeof(info->raw);
    ia.info.info = (uintptr_t)info->raw;
    return real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) < 0
               ? -1
               : 0;
}

static int scan_open_map_fds_for_prog(const uint32_t *want_ids,
                                      uint32_t want_n,
                                      uint32_t **fds_out,
                                      uint32_t **kids_out,
                                      uint32_t **types_out,
                                      uint32_t *n_out) {
    *fds_out = NULL;
    *kids_out = NULL;
    *types_out = NULL;
    *n_out = 0;
    if (want_n == 0)
        return 0;

    uint32_t *fds = (uint32_t *)calloc(want_n, sizeof(uint32_t));
    uint32_t *kids = (uint32_t *)calloc(want_n, sizeof(uint32_t));
    uint32_t *types = (uint32_t *)calloc(want_n, sizeof(uint32_t));
    if (!fds || !kids || !types) {
        free(fds);
        free(kids);
        free(types);
        return -1;
    }

    DIR *fd_dir = opendir("/proc/self/fd");
    if (!fd_dir) {
        free(fds);
        free(kids);
        free(types);
        return -1;
    }

    uint32_t n = 0;
    struct dirent *de;
    while ((de = readdir(fd_dir)) != NULL && n < want_n) {
        if (de->d_name[0] < '0' || de->d_name[0] > '9')
            continue;
        int probe_fd = atoi(de->d_name);
        if (probe_fd < 0)
            continue;
        char fdpath[64], link_target[64];
        snprintf(fdpath, sizeof(fdpath), "/proc/self/fd/%d", probe_fd);
        ssize_t lr = readlink(fdpath, link_target, sizeof(link_target) - 1);
        if (lr <= 0)
            continue;
        link_target[lr] = 0;
        if (strcmp(link_target, "anon_inode:bpf-map") != 0)
            continue;

        struct bpf_map_info mi;
        memset(&mi, 0, sizeof(mi));
        union bpf_attr ia = {0};
        ia.info.bpf_fd = (uint32_t)probe_fd;
        ia.info.info_len = sizeof(mi);
        ia.info.info = (uintptr_t)&mi;
        if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD,
                         &ia, sizeof(ia)) < 0 || mi.id == 0)
            continue;

        int wanted = 0;
        for (uint32_t i = 0; i < want_n; i++) {
            if (want_ids[i] == mi.id) {
                wanted = 1;
                break;
            }
        }
        if (!wanted)
            continue;

        int dup = 0;
        for (uint32_t i = 0; i < n; i++) {
            if (kids[i] == mi.id) {
                dup = 1;
                break;
            }
        }
        if (dup)
            continue;

        fds[n] = (uint32_t)probe_fd;
        kids[n] = mi.id;
        types[n] = mi.type;
        n++;
    }
    closedir(fd_dir);

    *fds_out = fds;
    *kids_out = kids;
    *types_out = types;
    *n_out = n;
    return 0;
}

static int prog_id_is_tracked(uint32_t prog_id) {
    int tracked = 0;
    pthread_mutex_lock(&state_mutex);
    tracked = prog_find_by_kernel_id(prog_id) != NULL;
    pthread_mutex_unlock(&state_mutex);
    return tracked;
}

static struct prog_entry *discover_prog_from_fd(int fd) {
    struct bpf_prog_info_fork info;
    struct bpf_prog_info *ibase = prog_info_fork_base(&info);
    if (query_prog_info_fork(fd, &info) != 0 || ibase->id == 0)
        return NULL;
    if (prog_id_is_tracked(ibase->id))
        return NULL;
    uint32_t orig_prog_len = prog_info_fork_orig_len(&info);
    if (orig_prog_len == 0 ||
        (orig_prog_len % sizeof(struct bpf_insn)) != 0)
        return NULL;
    if (orig_prog_len > 16U * 1024U * 1024U) {
        log_line("discover prog fd=%d id=%u skipped: orig_prog_len=%u",
                 fd, ibase->id, orig_prog_len);
        return NULL;
    }

    uint32_t map_n = ibase->nr_map_ids;
    uint32_t *map_ids = NULL;
    if (map_n) {
        map_ids = (uint32_t *)calloc(map_n, sizeof(uint32_t));
        if (!map_ids) {
            free(map_ids);
            return NULL;
        }
    }
    size_t insn_bytes = orig_prog_len;
    struct bpf_insn *insns = (struct bpf_insn *)malloc(insn_bytes);
    if (!insns) {
        free(map_ids);
        return NULL;
    }

    struct bpf_prog_info_fork full;
    memset(&full, 0, sizeof(full));
    struct bpf_prog_info *fbase = prog_info_fork_base(&full);
    fbase->nr_map_ids = map_n;
    fbase->map_ids = (uintptr_t)map_ids;
    prog_info_fork_set_orig_len(&full, orig_prog_len);
    prog_info_fork_set_orig_insns(&full, (uintptr_t)insns);
    union bpf_attr ia = {0};
    ia.info.bpf_fd = (uint32_t)fd;
    ia.info.info_len = sizeof(full);
    ia.info.info = (uintptr_t)full.raw;
    if (real_syscall(SYS_bpf, BPF_OBJ_GET_INFO_BY_FD, &ia, sizeof(ia)) < 0 ||
        prog_info_fork_orig_len(&full) != orig_prog_len) {
        free(insns);
        free(map_ids);
        return NULL;
    }
    if (fbase->nr_map_ids < map_n)
        map_n = fbase->nr_map_ids;

    uint64_t hash = fnv1a64(insns, insn_bytes);
    dump_bytecode(hash, insns, (uint32_t)(insn_bytes / sizeof(*insns)));
    free(insns);

    uint32_t *snap_fds = NULL;
    uint32_t *snap_kids = NULL;
    uint32_t *snap_types = NULL;
    uint32_t snap_n = 0;
    if (scan_open_map_fds_for_prog(map_ids, map_n, &snap_fds, &snap_kids,
                                   &snap_types, &snap_n) != 0) {
        free(map_ids);
        return NULL;
    }
    free(map_ids);

    struct prog_entry *e = (struct prog_entry *)calloc(1, sizeof(*e));
    if (!e) {
        free(snap_fds);
        free(snap_kids);
        free(snap_types);
        return NULL;
    }
    e->fd = fd;
    e->prog_type = fbase->type;
    memcpy(e->name, fbase->name, sizeof(e->name) - 1);
    e->name[sizeof(e->name) - 1] = 0;
    e->insn_cnt = (uint32_t)(insn_bytes / sizeof(struct bpf_insn));
    e->hash = hash;
    e->attach_btf_id = fbase->attach_btf_id;
    e->kernel_prog_id = fbase->id;
    e->prog_btf_kid = fbase->btf_id;
    e->attach_btf_obj_kid = fbase->attach_btf_obj_id;
    e->load_attr.prog_type = fbase->type;
    e->load_attr.attach_btf_id = fbase->attach_btf_id;
    snprintf(e->license, sizeof(e->license), "GPL");
    const char *dir = getenv("BPFREJIT_SHIM_DIR");
    if (!dir) dir = "/tmp";
    snprintf(e->bytecode_path, sizeof(e->bytecode_path),
             "%s/bpfrejit_%d_%016lx.bpf", dir, getpid(), hash);
    e->snap_n = snap_n;
    e->snap_fds = snap_fds;
    e->snap_kids = snap_kids;
    e->snap_types = snap_types;
    e->discovered_from_fd = 1;
    e->map_refs_are_kernel_ids = 0;
    log_line("discovered BPF prog fd=%d id=%u type=%u name=%s insn_cnt=%u maps=%u",
             fd, e->kernel_prog_id, e->prog_type, e->name, e->insn_cnt,
             e->snap_n);
    return e;
}

static void discover_proc_bpf_fds(void) {
    int saved_in_shim = in_shim;
    in_shim = 1;
    DIR *fd_dir = opendir("/proc/self/fd");
    if (!fd_dir) {
        in_shim = saved_in_shim;
        return;
    }
    struct dirent *de;
    while ((de = readdir(fd_dir)) != NULL) {
        if (de->d_name[0] < '0' || de->d_name[0] > '9')
            continue;
        int fd = atoi(de->d_name);
        if (fd < 0)
            continue;
        char fdpath[64], link_target[64];
        snprintf(fdpath, sizeof(fdpath), "/proc/self/fd/%d", fd);
        ssize_t lr = readlink(fdpath, link_target, sizeof(link_target) - 1);
        if (lr <= 0)
            continue;
        link_target[lr] = 0;
        if (strcmp(link_target, "anon_inode:bpf-prog") != 0)
            continue;
        struct prog_entry *e = discover_prog_from_fd(fd);
        if (!e)
            continue;
        pthread_mutex_lock(&state_mutex);
        if (prog_find_by_kernel_id(e->kernel_prog_id))
            prog_free(e);
        else
            prog_insert(e);
        pthread_mutex_unlock(&state_mutex);
    }
    closedir(fd_dir);
    in_shim = saved_in_shim;
}

static void discover_kernel_bpf_progs(void) {
    int saved_in_shim = in_shim;
    in_shim = 1;
    uint32_t id = 0;
    for (uint32_t iter = 0; iter < 1000000; iter++) {
        union bpf_attr next = {0};
        next.start_id = id;
        if (real_syscall(SYS_bpf, BPF_PROG_GET_NEXT_ID, &next,
                         sizeof(next)) < 0)
            break;
        id = next.next_id;
        if (id == 0 || prog_id_is_tracked(id))
            continue;
        union bpf_attr get = {0};
        get.prog_id = id;
        long fd = real_syscall(SYS_bpf, BPF_PROG_GET_FD_BY_ID, &get,
                               sizeof(get));
        if (fd < 0)
            continue;
        struct prog_entry *e = discover_prog_from_fd((int)fd);
        real_close((int)fd);
        if (!e)
            continue;
        e->fd = -(int)e->kernel_prog_id;
        pthread_mutex_lock(&state_mutex);
        if (prog_find_by_kernel_id(e->kernel_prog_id))
            prog_free(e);
        else
            prog_insert(e);
        pthread_mutex_unlock(&state_mutex);
    }
    in_shim = saved_in_shim;
}

static void discover_bpf_programs(void) {
    discover_proc_bpf_fds();
    discover_kernel_bpf_progs();
}

#endif /* BPFREJIT_SHIM_STATE_H */
