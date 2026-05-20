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
 * Per-pid socket implements app-level shim RPCs. Optimization is runner-driven:
 * the runner reads its yaml and sends pass steps; the shim applies them to
 * every BPF program tracked in this process, substitutes ${VAR}s, and runs
 * /bin/sh -c.
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

#include "shim_netlink.h"

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
/* sendto/sendmsg are intercepted to catch katran-style rtnetlink XDP
 * attach (RTM_SETLINK + IFLA_XDP_FD). libbpf < v0.8, iproute2-style ip-link
 * xdp, and Cilium's pre-link path all attach via these. Without intercept,
 * the netdev keeps dispatching to the original prog after ReJIT reload. */
static ssize_t (*real_sendto)(int, const void *, size_t, int,
                              const struct sockaddr *, socklen_t);
static ssize_t (*real_sendmsg)(int, const struct msghdr *, int);

/* Resolve any not-yet-resolved real symbols. Called at the top of every
 * interceptor so that apps which call syscall(3)/ioctl(2)/close(2) from a
 * constructor that runs before ours (folly/grpc/etc.) don't see NULL. */
static void ensure_syms_resolved(void) {
    if (!real_syscall)
        real_syscall = (long (*)(long, ...))dlsym(RTLD_NEXT, "syscall");
    if (!real_ioctl)
        real_ioctl = (int (*)(int, unsigned long, ...))dlsym(RTLD_NEXT, "ioctl");
    if (!real_sendto)
        real_sendto = (ssize_t (*)(int, const void *, size_t, int,
                                   const struct sockaddr *, socklen_t))
                      dlsym(RTLD_NEXT, "sendto");
    if (!real_sendmsg)
        real_sendmsg = (ssize_t (*)(int, const struct msghdr *, int))
                       dlsym(RTLD_NEXT, "sendmsg");
    if (!real_close)
        real_close = (int (*)(int))dlsym(RTLD_NEXT, "close");
}

static FILE *log_file;
static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Recursion guard: shim-internal syscalls must not re-enter the logger. */
static __thread int in_shim;

#include "shim_state.h"

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
     * target.json once. Subsequent execute_plan RPCs reuse this file for the
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

    /* Socket server thread — per-pid app-level shim socket.
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

/* Drop or insert an XDP attach record for `prog_fd`. Holds state_mutex
 * for the duration; safe to call without external locking. `prog_fd<0`
 * variant (detach) is dispatched via prog_xdp_detach_by_ifindex below. */
static void prog_xdp_attach_set(int prog_fd, uint32_t ifindex,
                                uint32_t xdp_flags, int old_prog_fd) {
    pthread_mutex_lock(&state_mutex);
    struct prog_entry *p = prog_find(prog_fd);
    if (!p) {
        pthread_mutex_unlock(&state_mutex);
        log_line("netlink RTM_SETLINK IFLA_XDP_FD=%d ifindex=%u: no known "
                 "prog_entry — attach won't survive reload",
                 prog_fd, ifindex);
        return;
    }
    /* Dedup by ifindex; newest flags + old_prog_fd win. */
    for (uint32_t i = 0; i < p->n_xdp; i++) {
        if (p->xdp_attaches[i].ifindex == ifindex) {
            p->xdp_attaches[i].xdp_flags = xdp_flags;
            uint32_t kid = p->kernel_prog_id;
            pthread_mutex_unlock(&state_mutex);
            log_line("netlink RTM_SETLINK update: prog_fd=%d kid=%u "
                     "ifindex=%u flags=0x%x", prog_fd, kid, ifindex, xdp_flags);
            return;
        }
    }
    struct xdp_nl_attach *grown =
        (struct xdp_nl_attach *)realloc(p->xdp_attaches,
                                        (p->n_xdp + 1) * sizeof(*grown));
    if (!grown) { pthread_mutex_unlock(&state_mutex); return; }
    grown[p->n_xdp].ifindex = ifindex;
    grown[p->n_xdp].xdp_flags = xdp_flags;
    p->xdp_attaches = grown;
    p->n_xdp++;
    uint32_t kid = p->kernel_prog_id;
    pthread_mutex_unlock(&state_mutex);
    log_line("netlink RTM_SETLINK captured: prog_fd=%d kid=%u ifindex=%u "
             "flags=0x%x (old_prog_fd=%d)", prog_fd, kid, ifindex,
             xdp_flags, old_prog_fd);
}

/* Drop the (ifindex) attach from any prog_entry that holds it. Called on
 * observed detach (IFLA_XDP_FD == -1). */
static void prog_xdp_detach_by_ifindex(uint32_t ifindex) {
    pthread_mutex_lock(&state_mutex);
    for (unsigned b = 0; b < BPF_STATE_BUCKETS; b++) {
        for (struct prog_entry *p = prog_table[b]; p; p = p->next) {
            for (uint32_t i = 0; i < p->n_xdp; ) {
                if (p->xdp_attaches[i].ifindex == ifindex) {
                    p->xdp_attaches[i] = p->xdp_attaches[p->n_xdp - 1];
                    p->n_xdp--;
                } else {
                    i++;
                }
            }
        }
    }
    pthread_mutex_unlock(&state_mutex);
    log_line("netlink RTM_SETLINK detach observed: ifindex=%u dropped from "
             "all prog_entry xdp_attaches", ifindex);
}

/* Decide whether `sock_fd` is the kind of socket we want to inspect.
 * Cached lookup via getsockopt; the cost is one syscall per send call
 * which is dwarfed by netlink RTT. */
static int sock_is_rtnetlink(int sock_fd) {
    int domain = -1, protocol = -1;
    socklen_t slen = sizeof(domain);
    if (getsockopt(sock_fd, SOL_SOCKET, SO_DOMAIN, &domain, &slen) != 0)
        return 0;
    if (domain != AF_NETLINK) return 0;
    slen = sizeof(protocol);
    if (getsockopt(sock_fd, SOL_SOCKET, SO_PROTOCOL, &protocol, &slen) != 0)
        return 0;
    return protocol == NETLINK_ROUTE;
}

/* Inspect an outgoing rtnetlink message AFTER it succeeded. Records or
 * removes XDP attach state per IFLA_XDP_FD value. */
static void netlink_observe_xdp_post(int sock_fd, const void *buf, size_t len) {
    if (!buf || len < sizeof(struct nlmsghdr)) return;
    if (!sock_is_rtnetlink(sock_fd)) return;
    uint32_t ifindex = 0, flags = 0;
    int prog_fd = -1;
    if (!nl_parse_setlink_xdp_attach(buf, len, &ifindex, &prog_fd, &flags))
        return;
    if (prog_fd < 0) {
        /* Detach: drop attach record from whichever prog held this ifindex. */
        prog_xdp_detach_by_ifindex(ifindex);
        return;
    }
    /* Attach succeeded — record. old_prog_fd not known here; replay falls
     * back to non-EXPECTED replace mode. */
    prog_xdp_attach_set(prog_fd, ifindex, flags, -1);
}

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen) {
    ensure_syms_resolved();
    ssize_t ret = real_sendto(sockfd, buf, len, flags, dest_addr, addrlen);
    int saved_errno = errno;
    /* Only observe AFTER kernel accepted the message — pre-syscall observe
     * would record attaches that the kernel later rejects, leading to
     * phantom replay attempts during reload. */
    if (!in_shim && ret >= 0 && buf && (size_t)ret >= sizeof(struct nlmsghdr)) {
        in_shim = 1;
        netlink_observe_xdp_post(sockfd, buf, (size_t)ret);
        in_shim = 0;
    }
    errno = saved_errno;
    return ret;
}

ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags) {
    ensure_syms_resolved();
    ssize_t ret = real_sendmsg(sockfd, msg, flags);
    int saved_errno = errno;
    if (!in_shim && ret >= 0 && msg && msg->msg_iovlen > 0) {
        in_shim = 1;
        /* Linearise iovecs if the netlink message spans multiple iovs.
         * sendmsg lets the app scatter the request across iovecs and the
         * kernel reassembles; our parser needs a flat view. */
        size_t total = 0;
        const struct iovec *iov = msg->msg_iov;
        for (size_t i = 0; i < (size_t)msg->msg_iovlen; i++)
            total += iov[i].iov_len;
        if (total >= sizeof(struct nlmsghdr) && total <= (size_t)ret) {
            char stack_buf[4096];
            char *flat = (total <= sizeof(stack_buf))
                         ? stack_buf
                         : (char *)malloc(total);
            if (flat) {
                size_t off = 0;
                for (size_t i = 0; i < (size_t)msg->msg_iovlen && off < total; i++) {
                    size_t take = iov[i].iov_len;
                    if (off + take > total) take = total - off;
                    if (iov[i].iov_base) memcpy(flat + off, iov[i].iov_base, take);
                    off += take;
                }
                netlink_observe_xdp_post(sockfd, flat, total);
                if (flat != stack_buf) free(flat);
            }
        }
        in_shim = 0;
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
 * Socket server thread: per-pid JSON control socket.
 *
 * Path: $BPFREJIT_SHIM_SOCK_DIR/shim-<pid>.sock (default /var/run/bpfrejit/)
 *
 * Protocol: line-delimited JSON, one request per line, one response per line.
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

#include "shim_json.h"

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

#include "shim_snapshot.h"

#include "shim_reload.h"

#include "shim_measure.h"

#include "shim_execute_plan.h"

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
    else if (strcmp(cmd, "has_programs") == 0)
        emit_has_programs(cli);
    else if (strcmp(cmd, "measure_start") == 0)
        emit_measure_start(cli);
    else if (strcmp(cmd, "measure_finish") == 0)
        emit_measure_finish(cli);
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
 * by the runner over the socket via execute_plan, not by this thread. */
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
