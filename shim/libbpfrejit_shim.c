/*
 * libbpfrejit_shim.so — LD_PRELOAD observation shim for BPF-related syscalls.
 *
 * Phase 1 (this file): observe and log BPF_PROG_LOAD, perf_event_open, and
 * PERF_EVENT_IOC_SET_BPF; pass everything through to the real kernel.
 *
 * Phase 2 (later): record original bytecode per prog, expose a per-pid control
 * socket, run bpfopt subprocess pipeline, submit candidate prog, swap.
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

static FILE *log_file;
static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Recursion guard: shim-internal syscalls must not re-enter the logger. */
static __thread int in_shim;

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

static void on_prog_load(const union bpf_attr *attr) {
    char name[17] = {0};
    memcpy(name, attr->prog_name, 16);
    uint64_t hash = 0;
    uint32_t insn_cnt = attr->insn_cnt;
    const struct bpf_insn *insns = (const struct bpf_insn *)(uintptr_t)attr->insns;
    if (insns && insn_cnt > 0) {
        hash = fnv1a64(insns, (size_t)insn_cnt * sizeof(struct bpf_insn));
        dump_bytecode(hash, insns, insn_cnt);
    }
    log_line("BPF_PROG_LOAD type=%u (%s) name=%s insn_cnt=%u hash=%016lx "
             "license=%s expected_attach=%u attach_btf_id=%u",
             attr->prog_type, prog_type_name(attr->prog_type), name, insn_cnt,
             hash, (const char *)(uintptr_t)attr->license,
             attr->expected_attach_type, attr->attach_btf_id);
}

static void on_link_create(const union bpf_attr *attr) {
    log_line("BPF_LINK_CREATE prog_fd=%u target_fd=%u attach_type=%u flags=%u",
             attr->link_create.prog_fd, attr->link_create.target_fd,
             attr->link_create.attach_type, attr->link_create.flags);
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

__attribute__((constructor)) static void shim_init(void) {
    real_syscall = dlsym(RTLD_NEXT, "syscall");
    real_ioctl = dlsym(RTLD_NEXT, "ioctl");
    const char *log_path = getenv("BPFREJIT_SHIM_LOG");
    if (!log_path)
        log_path = "/tmp/bpfrejit_shim.log";
    log_file = fopen(log_path, "a");
    if (log_file) {
        setvbuf(log_file, NULL, _IOLBF, 0);
        log_line("shim_init pid=%d exe=%s", getpid(),
                 ({
                     static char buf[256];
                     ssize_t n = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
                     if (n > 0) buf[n] = 0; else buf[0] = 0;
                     buf;
                 }));
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
            const struct perf_event_attr *pa = (const struct perf_event_attr *)a0;
            pid_t pid = (pid_t)a1;
            int cpu = (int)a2;
            int group_fd = (int)a3;
            unsigned long flags = (unsigned long)a4;
            in_shim = 1;
            long ret = real_syscall(number, a0, a1, a2, a3, a4, a5);
            int saved_errno = errno;
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

    if (!in_shim && attr) {
        in_shim = 1;
        switch (cmd) {
        case BPF_PROG_LOAD: on_prog_load(attr); break;
        case BPF_LINK_CREATE: on_link_create(attr); break;
        case BPF_LINK_UPDATE: on_link_update(attr); break;
        case BPF_PROG_ATTACH: on_prog_attach(attr); break;
        case BPF_RAW_TRACEPOINT_OPEN: on_raw_tp_open(attr); break;
        default:
            log_line("bpf cmd=%d (%s) size=%u", cmd, bpf_cmd_name(cmd), size);
            break;
        }
        in_shim = 0;
    }

    in_shim = 1;
    long ret = real_syscall(number, a0, a1, a2, a3, a4, a5);
    int saved_errno = errno;
    in_shim = 0;

    if (!in_shim) {
        if (cmd == BPF_PROG_LOAD)
            log_line("  PROG_LOAD -> fd=%ld errno=%d", ret,
                     ret < 0 ? saved_errno : 0);
        else if (cmd == BPF_LINK_CREATE)
            log_line("  LINK_CREATE -> fd=%ld errno=%d", ret,
                     ret < 0 ? saved_errno : 0);
        else if (cmd == BPF_LINK_UPDATE)
            log_line("  LINK_UPDATE -> ret=%ld errno=%d", ret,
                     ret < 0 ? saved_errno : 0);
    }

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

    if (!in_shim && request == PERF_EVENT_IOC_SET_BPF)
        log_line("  PERF_EVENT_IOC_SET_BPF -> ret=%d errno=%d", ret,
                 ret < 0 ? saved_errno : 0);

    errno = saved_errno;
    return ret;
}
