# PoC-B: BCC perf_event fd acquisition and BPF replacement test

This is a design for a one-shot proof of concept. Do not treat it as a
benchmark entrypoint. It is meant to answer one narrow question: can a
userspace controller borrow a BCC tool's app-owned perf event fd with
`pidfd_getfd()` and use `PERF_EVENT_IOC_SET_BPF` to replace the BPF program
that BCC attached?

Important kernel finding: in this repo's Linux `7.0.0-rc2` tree,
`PERF_EVENT_IOC_SET_BPF` is not a replacement primitive for an event that
already has `event->prog`. The ioctl handler calls
`__perf_event_set_bpf_prog()` in `vendor/linux-framework/kernel/events/core.c`,
and the tracing attach path in `vendor/linux-framework/kernel/trace/bpf_trace.c`
returns `-EEXIST` when `event->prog` is already set. This PoC therefore has
two possible outcomes:

- Positive: the target kernel has been changed to support replacement, and the
  checks below prove that the new program is active.
- Negative: `PERF_EVENT_IOC_SET_BPF` returns `EEXIST`, which proves that stock
  app-owned perf_event fd handoff is not enough for userspace swap on that
  kernel.

## 1. Goal and success criteria

Goal: verify whether a controller can:

1. find a live BCC kprobe tool's perf event fd,
2. duplicate that fd from the BCC process with `pidfd_open()` and
   `pidfd_getfd()`,
3. query the currently attached BPF program ids with
   `PERF_EVENT_IOC_QUERY_BPF`,
4. load a dummy `BPF_PROG_TYPE_KPROBE` program that returns `0`,
5. call `PERF_EVENT_IOC_SET_BPF` on the duplicated perf event fd, and
6. observe that execution moved from the old program to the dummy program.

Positive success criteria:

- Before replacement, `PERF_EVENT_IOC_QUERY_BPF` on the duplicated fd returns
  the old BCC program id. For the recommended `capable-bpfcc` target, the old
  program should be named `cap_capable` and have type `kprobe` in `bpftool`.
- The dummy program loads successfully as `BPF_PROG_TYPE_KPROBE`; its program
  id is recorded with `BPF_OBJ_GET_INFO_BY_FD`.
- `PERF_EVENT_IOC_SET_BPF` returns `0`.
- A second `PERF_EVENT_IOC_QUERY_BPF` shows the dummy program id in place of
  the old BCC program id for that event.
- The BCC tool's output stops producing trace events while the workload still
  exercises the hook. For `opensnoop-bpfcc`, the output should go silent during
  continued open activity. For the recommended `capable-bpfcc` target, the
  capability-event output should go silent during continued `stress-ng --cap`
  activity.
- Counter behavior matches replacement: the old program id keeps its existing
  `run_cnt` baseline and stops growing, while the new dummy program starts near
  `0` and then grows as the hook fires.

Decisive negative criterion:

- If `PERF_EVENT_IOC_SET_BPF` returns `EEXIST` and the second
  `PERF_EVENT_IOC_QUERY_BPF` still reports the old program id, the PoC has
  falsified the userspace-swap premise for the current kernel. That is the
  expected result for the repo kernel as inspected in:
  `vendor/linux-framework/kernel/events/core.c`,
  `vendor/linux-framework/kernel/trace/bpf_trace.c`.

## 2. Prerequisites

- Kernel: `pidfd_getfd()` requires Linux `>= 5.6`. `pidfd_open()` is older
  (`>= 5.3`). The repo kernel inspected here is Linux `7.0.0-rc2`
  (`vendor/linux-framework/Makefile`).
- Target attachment: the BCC process must already have opened and attached a
  perf event fd. The PoC does not load the original BCC program and does not
  create the original kprobe.
- Privilege: run as root in the benchmark VM/container. Use `CAP_SYS_ADMIN`
  for BPF/perf operations on older kernels, and `CAP_SYS_PTRACE` for
  `pidfd_getfd()`. Newer kernels may split BPF/perf privilege into
  `CAP_BPF`/`CAP_PERFMON`, but `CAP_SYS_ADMIN` is the simple PoC requirement.
- PID namespace: the container must run with `--pid=host`, otherwise the
  controller may not see the host PID or may fail `pidfd_open()`/`pidfd_getfd()`
  against the BCC process.
- BPF stats: enable BPF runtime counters if using `bpftool prog show` for
  `run_cnt`/`run_time_ns` checks:

```bash
sysctl -w kernel.bpf_stats_enabled=1
```

API references, verified against this repo's Linux `7.0.0-rc2` tree:

| API | Kernel surface |
| --- | --- |
| `pidfd_open` | `vendor/linux-framework/include/uapi/asm-generic/unistd.h` defines syscall `434`; `vendor/linux-framework/kernel/pid.c` implements `SYSCALL_DEFINE2(pidfd_open, ...)`. |
| `pidfd_getfd` | `vendor/linux-framework/include/uapi/asm-generic/unistd.h` defines syscall `438`; `vendor/linux-framework/kernel/pid.c` implements `SYSCALL_DEFINE3(pidfd_getfd, ...)` and documents the ptrace permission requirement. |
| `struct perf_event_query_bpf` | `vendor/linux-framework/include/uapi/linux/perf_event.h`; layout is `__u32 ids_len`, `__u32 prog_cnt`, flexible `__u32 ids[]`. |
| `PERF_EVENT_IOC_ID` | `vendor/linux-framework/include/uapi/linux/perf_event.h`: `_IOR('$', 7, __u64 *)`; handler copies `primary_event_id(event)` in `vendor/linux-framework/kernel/events/core.c`. |
| `PERF_EVENT_IOC_SET_BPF` | `vendor/linux-framework/include/uapi/linux/perf_event.h`: `_IOW('$', 8, __u32)`; handler calls `bpf_prog_get(arg)` and `__perf_event_set_bpf_prog()` in `vendor/linux-framework/kernel/events/core.c`. Pass the new BPF program fd as the ioctl argument value, not as a pointer. |
| `PERF_EVENT_IOC_QUERY_BPF` | `vendor/linux-framework/include/uapi/linux/perf_event.h`: `_IOWR('$', 10, struct perf_event_query_bpf *)`. This corrects the common mistaken `nr=4`; `nr=4` is `PERF_EVENT_IOC_PERIOD`. |
| `BPF_PROG_LOAD`, `BPF_PROG_TYPE_KPROBE`, `struct bpf_insn` | `vendor/linux-framework/include/uapi/linux/bpf.h`; `BPF_PROG_LOAD` attr fields include `prog_type`, `insn_cnt`, `insns`, `license`, and verifier log fields. |
| perf-event BPF link limitation | `vendor/linux-framework/kernel/bpf/syscall.c`: `bpf_perf_link_lops` has release/dealloc/fill/show ops but no `update_prog`; generic `BPF_LINK_UPDATE` returns `-EINVAL` when link ops lack `update_prog`. |

## 3. Decision: target tool

The requested `corpus/apps/bcc/` path is not present in this repo. The live BCC
corpus runner is:

- `runner/libs/app_runners/bcc_set.py`
- `runner/libs/app_runners/bcc.py`
- app entry `bcc/set` in `corpus/config/macro_apps.yaml`

`bcc/set` starts these BCC tools:

```text
capable
biosnoop
vfsstat
opensnoop
syscount -L -i 1
tcpconnect
tcplife
runqlat
```

The runner resolves `tool` to `tool-bpfcc` first, then `tool`, and spawns:

```python
command = [str(tool_binary), *child.tool_args]
```

Recommended target: `capable-bpfcc`.

Reasons:

- It is the simplest BCC kprobe target in this corpus. `/usr/sbin/capable-bpfcc`
  contains `int kprobe__cap_capable(...)`, so BCC auto-attaches a kprobe to
  `cap_capable`.
- It has one high-signal kprobe program in observed `bcc/set` results:
  `cap_capable`, type `kprobe`, with millions of `run_cnt_delta` under
  `stress_ng_os_io_network`.
- It submits events through `BPF_PERF_OUTPUT(events)`. Replacing it with a
  dummy program that only returns `0` should make user-visible events stop.

Why not default to `opensnoop-bpfcc`:

- `opensnoop-bpfcc` is a valid variant, but the current script first checks
  `BPF.support_kfunc()`. On kernels where kfunc/fentry is available it builds
  `KRETFUNC_PROBE` programs and does not use the legacy `attach_kprobe()` path.
- Only when kfunc support is unavailable does it call `b.attach_kprobe()` and
  `b.attach_kretprobe()`.
- Therefore `opensnoop-bpfcc` may exercise tracing/fentry instead of a
  perf_event kprobe on exactly the newer kernels where this PoC is likely to
  run. `capable-bpfcc` avoids that ambiguity.

Use `opensnoop-bpfcc` only as a secondary variant after confirming it has live
`anon_inode:[perf_event]` fds whose `PERF_EVENT_IOC_QUERY_BPF` result contains
the expected kprobe program ids.

## 4. Step-by-step execution

Run these commands inside the benchmark VM/container as root. The commands are
shown from project root for repeatability.

### 4a. Start the BCC app

The exact runner command for the recommended child tool is no args:

```bash
cd /home/yunwei37/workspace/bpf-benchmark
mkdir -p docs/tmp/poc-b
/usr/sbin/capable-bpfcc > docs/tmp/poc-b/capable.out 2> docs/tmp/poc-b/capable.err &
CAPABLE_PID=$!
```

The exact runner command for the `opensnoop` variant is also no args:

```bash
/usr/sbin/opensnoop-bpfcc > docs/tmp/poc-b/opensnoop.out 2> docs/tmp/poc-b/opensnoop.err &
OPENSNOOP_PID=$!
```

For the full `bcc/set` app, the runner would start all eight tools listed in
section 3. This PoC should start one tool to keep fd ownership and output
verification unambiguous.

Start a workload in another shell. For `capable-bpfcc`:

```bash
stress-ng --cap 4 --timeout 120s --metrics-brief
```

For `opensnoop-bpfcc`:

```bash
stress-ng --open 4 --open-max 1024 --timeout 120s --metrics-brief
```

Watch output:

```bash
tail -f docs/tmp/poc-b/capable.out
```

### 4b. Discover the Python/BCC host PID

If the tool was started by this shell, `$CAPABLE_PID` is the first candidate.
When using a separate container or `bcc/set`, discover it from the host PID
namespace:

```bash
pgrep -af 'python3 .*capable-bpfcc|capable-bpfcc'
pgrep -af 'python3 .*opensnoop-bpfcc|opensnoop-bpfcc'
```

Use the Python process that owns the BCC object, not `tail`, `stress-ng`, or a
shell wrapper.

### 4c. Walk `/proc/$pid/fd` and filter perf event fds

Manual inspection:

```bash
PID=$CAPABLE_PID
for fdpath in /proc/$PID/fd/*; do
    link=$(readlink "$fdpath" 2>/dev/null || true)
    if [ "$link" = 'anon_inode:[perf_event]' ]; then
        printf '%s -> %s\n' "${fdpath##*/}" "$link"
    fi
done
```

The one-shot C program in section 5 performs this walk automatically.

### 4d. Duplicate candidate fds with `pidfd_open` and `pidfd_getfd`

The controller opens a pidfd:

```c
pidfd = syscall(SYS_pidfd_open, target_pid, 0);
```

Then for each candidate numeric fd:

```c
dup_fd = syscall(SYS_pidfd_getfd, pidfd, remote_fd, 0);
```

The duplicated fd references the same kernel `struct file` as the BCC process's
perf event fd. Duplicating it does not close, pause, or otherwise change the
remote process.

### 4e. Get the unique perf event id

For every duplicated perf fd:

```c
__u64 event_id = 0;
ioctl(dup_fd, PERF_EVENT_IOC_ID, &event_id);
```

Record this id in logs so retries can distinguish fds even if the process has
multiple perf events.

### 4f. Query attached BPF program ids

Call:

```c
struct perf_event_query_bpf query = { .ids_len = 64 };
ioctl(dup_fd, PERF_EVENT_IOC_QUERY_BPF, &query);
```

The actual allocation must include space for the flexible `ids[]` array; see
section 5. A useful target fd has `prog_cnt > 0` and contains the expected BCC
program id. If `QUERY_BPF` returns `EINVAL`, the fd is not a queryable tracing
perf event for this ioctl path.

Confirm the candidate program names:

```bash
bpftool prog show id <old_prog_id>
```

### 4g. Load the dummy kprobe program

The dummy bytecode is exactly:

```c
static struct bpf_insn dummy_prog[] = {
    {
        .code = BPF_ALU64 | BPF_MOV | BPF_K,
        .dst_reg = BPF_REG_0,
        .src_reg = 0,
        .off = 0,
        .imm = 0,
    },
    {
        .code = BPF_JMP | BPF_EXIT,
        .dst_reg = 0,
        .src_reg = 0,
        .off = 0,
        .imm = 0,
    },
};
```

Load it with `BPF_PROG_LOAD` and `prog_type = BPF_PROG_TYPE_KPROBE`.

### 4h. Attempt `PERF_EVENT_IOC_SET_BPF`

Call:

```c
ioctl(dup_fd, PERF_EVENT_IOC_SET_BPF, new_prog_fd);
```

This is the decisive call. On the repo kernel, expect `-1` with `errno=EEXIST`
when the event already has BCC's original program attached. If a patched kernel
supports replacement here, this call returns `0`.

### 4i. Verify the result

If `SET_BPF` returned `0`:

```bash
bpftool prog show id <old_prog_id>
bpftool prog show id <new_prog_id>
tail -f docs/tmp/poc-b/capable.out
```

Expected positive result:

- `QUERY_BPF` after `SET_BPF` contains `<new_prog_id>` in place of
  `<old_prog_id>`.
- `capable.out` or `opensnoop.out` goes quiet while workload continues.
- `bpftool prog show id <old_prog_id>` no longer grows `run_cnt`.
- `bpftool prog show id <new_prog_id>` starts near `0` and grows.

If `SET_BPF` returned `EEXIST`:

- Re-query the fd and confirm the old id is still present.
- Record this as a negative PoC result: pidfd fd acquisition works, but
  `PERF_EVENT_IOC_SET_BPF` cannot replace BCC's already attached tracing
  program on this kernel.

## 5. Concrete code: one-shot C binary

Save this future implementation under `docs/tmp/`, for example
`docs/tmp/poc_b_perf_event_swap.c`, then compile with the commands in section 6.
The code intentionally uses UAPI headers directly so the ioctl definitions come
from the target build environment.

```c
// SPDX-License-Identifier: MIT
#define _GNU_SOURCE
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <linux/bpf.h>
#include <linux/perf_event.h>
#include <linux/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef SYS_pidfd_open
# ifdef __NR_pidfd_open
#  define SYS_pidfd_open __NR_pidfd_open
# else
#  error "pidfd_open syscall number unavailable"
# endif
#endif

#ifndef SYS_pidfd_getfd
# ifdef __NR_pidfd_getfd
#  define SYS_pidfd_getfd __NR_pidfd_getfd
# else
#  error "pidfd_getfd syscall number unavailable"
# endif
#endif

#ifndef SYS_bpf
# ifdef __NR_bpf
#  define SYS_bpf __NR_bpf
# else
#  error "bpf syscall number unavailable"
# endif
#endif

#define MAX_QUERY_IDS 64

struct query_bpf_64 {
    __u32 ids_len;
    __u32 prog_cnt;
    __u32 ids[MAX_QUERY_IDS];
};

_Static_assert(offsetof(struct perf_event_query_bpf, ids_len) == 0,
               "perf_event_query_bpf.ids_len offset");
_Static_assert(offsetof(struct perf_event_query_bpf, prog_cnt) == 4,
               "perf_event_query_bpf.prog_cnt offset");
_Static_assert(offsetof(struct perf_event_query_bpf, ids) == 8,
               "perf_event_query_bpf.ids offset");

static __u64 ptr_to_u64(const void *ptr)
{
    return (__u64)(uintptr_t)ptr;
}

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, size_t size)
{
    return (int)syscall(SYS_bpf, cmd, attr, size);
}

static int load_dummy_kprobe(void)
{
    static const char license[] = "GPL";
    static char log_buf[1 << 20];
    static struct bpf_insn insns[] = {
        {
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = BPF_REG_0,
            .src_reg = 0,
            .off = 0,
            .imm = 0,
        },
        {
            .code = BPF_JMP | BPF_EXIT,
            .dst_reg = 0,
            .src_reg = 0,
            .off = 0,
            .imm = 0,
        },
    };
    union bpf_attr attr;

    memset(&attr, 0, sizeof(attr));
    attr.prog_type = BPF_PROG_TYPE_KPROBE;
    attr.insn_cnt = sizeof(insns) / sizeof(insns[0]);
    attr.insns = ptr_to_u64(insns);
    attr.license = ptr_to_u64(license);
    attr.log_level = 1;
    attr.log_size = sizeof(log_buf);
    attr.log_buf = ptr_to_u64(log_buf);
    memcpy(attr.prog_name, "poc_b_dummy", sizeof("poc_b_dummy"));

    int fd = sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
    if (fd < 0) {
        int saved = errno;
        fprintf(stderr, "BPF_PROG_LOAD failed: errno=%d (%s)\n",
                saved, strerror(saved));
        if (log_buf[0] != '\0')
            fprintf(stderr, "verifier log:\n%s\n", log_buf);
        errno = saved;
        return -1;
    }
    return fd;
}

static int get_prog_id(int prog_fd, __u32 *id_out)
{
    struct bpf_prog_info info;
    union bpf_attr attr;

    memset(&info, 0, sizeof(info));
    memset(&attr, 0, sizeof(attr));
    attr.info.bpf_fd = (__u32)prog_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);

    if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
        return -1;
    *id_out = info.id;
    return 0;
}

static int query_bpf(int fd, struct query_bpf_64 *query)
{
    memset(query, 0, sizeof(*query));
    query->ids_len = MAX_QUERY_IDS;
    return ioctl(fd, PERF_EVENT_IOC_QUERY_BPF, query);
}

static int query_contains(const struct query_bpf_64 *query, __u32 prog_id)
{
    __u32 limit = query->prog_cnt < query->ids_len ? query->prog_cnt : query->ids_len;
    for (__u32 i = 0; i < limit; i++) {
        if (query->ids[i] == prog_id)
            return 1;
    }
    return 0;
}

static void print_query(const char *label, const struct query_bpf_64 *query)
{
    __u32 limit = query->prog_cnt < query->ids_len ? query->prog_cnt : query->ids_len;

    printf("%s: prog_cnt=%u ids_len=%u ids=", label, query->prog_cnt, query->ids_len);
    for (__u32 i = 0; i < limit; i++)
        printf("%s%u", i ? "," : "", query->ids[i]);
    printf("\n");
}

static int parse_fd_name(const char *name, int *fd_out)
{
    char *end = NULL;
    errno = 0;
    long value = strtol(name, &end, 10);
    if (errno || end == name || *end != '\0' || value < 0 || value > INT32_MAX)
        return -1;
    *fd_out = (int)value;
    return 0;
}

static int is_perf_event_fd(pid_t pid, int remote_fd)
{
    char path[128];
    char link[256];
    ssize_t len;

    snprintf(path, sizeof(path), "/proc/%d/fd/%d", pid, remote_fd);
    len = readlink(path, link, sizeof(link) - 1);
    if (len < 0)
        return 0;
    link[len] = '\0';
    return strcmp(link, "anon_inode:[perf_event]") == 0;
}

static int try_remote_fd(int pidfd, pid_t target_pid, int remote_fd, __u32 requested_old_id)
{
    int dup_fd = -1;
    __u64 event_id = 0;
    struct query_bpf_64 before;
    struct query_bpf_64 after;
    int dummy_fd = -1;
    __u32 dummy_id = 0;

    if (!is_perf_event_fd(target_pid, remote_fd))
        return 0;

    dup_fd = (int)syscall(SYS_pidfd_getfd, pidfd, remote_fd, 0);
    if (dup_fd < 0) {
        fprintf(stderr, "remote fd %d: pidfd_getfd failed: errno=%d (%s)\n",
                remote_fd, errno, strerror(errno));
        return 0;
    }

    if (ioctl(dup_fd, PERF_EVENT_IOC_ID, &event_id) < 0) {
        fprintf(stderr, "remote fd %d: PERF_EVENT_IOC_ID failed: errno=%d (%s)\n",
                remote_fd, errno, strerror(errno));
        close(dup_fd);
        return 0;
    }

    if (query_bpf(dup_fd, &before) < 0) {
        fprintf(stderr,
                "remote fd %d event_id=%llu: QUERY_BPF failed: errno=%d (%s)\n",
                remote_fd, (unsigned long long)event_id, errno, strerror(errno));
        close(dup_fd);
        return 0;
    }

    if (before.prog_cnt == 0) {
        close(dup_fd);
        return 0;
    }

    if (requested_old_id && !query_contains(&before, requested_old_id)) {
        close(dup_fd);
        return 0;
    }

    printf("candidate remote_fd=%d dup_fd=%d event_id=%llu\n",
           remote_fd, dup_fd, (unsigned long long)event_id);
    print_query("before", &before);

    dummy_fd = load_dummy_kprobe();
    if (dummy_fd < 0) {
        close(dup_fd);
        return -1;
    }
    if (get_prog_id(dummy_fd, &dummy_id) < 0) {
        fprintf(stderr, "BPF_OBJ_GET_INFO_BY_FD(dummy) failed: errno=%d (%s)\n",
                errno, strerror(errno));
        close(dummy_fd);
        close(dup_fd);
        return -1;
    }
    printf("dummy prog_fd=%d prog_id=%u\n", dummy_fd, dummy_id);

    if (ioctl(dup_fd, PERF_EVENT_IOC_SET_BPF, dummy_fd) < 0) {
        int saved = errno;
        fprintf(stderr,
                "remote fd %d event_id=%llu: SET_BPF(dummy_fd=%d,id=%u) failed: errno=%d (%s)\n",
                remote_fd, (unsigned long long)event_id, dummy_fd, dummy_id,
                saved, strerror(saved));
        if (query_bpf(dup_fd, &after) == 0)
            print_query("after_failed_set", &after);
        close(dummy_fd);
        close(dup_fd);
        errno = saved;
        return saved == EEXIST ? 2 : -1;
    }

    if (query_bpf(dup_fd, &after) < 0) {
        fprintf(stderr, "remote fd %d: QUERY_BPF after SET_BPF failed: errno=%d (%s)\n",
                remote_fd, errno, strerror(errno));
        close(dummy_fd);
        close(dup_fd);
        return -1;
    }
    print_query("after", &after);

    if (!query_contains(&after, dummy_id)) {
        fprintf(stderr, "SET_BPF returned success but dummy id %u is absent after query\n",
                dummy_id);
        close(dummy_fd);
        close(dup_fd);
        return -1;
    }
    if (requested_old_id && query_contains(&after, requested_old_id)) {
        fprintf(stderr,
                "SET_BPF returned success but old id %u is still present after query\n",
                requested_old_id);
        close(dummy_fd);
        close(dup_fd);
        return -1;
    }

    printf("success: perf event now reports dummy prog_id=%u\n", dummy_id);
    close(dummy_fd);
    close(dup_fd);
    return 1;
}

int main(int argc, char **argv)
{
    pid_t target_pid;
    __u32 requested_old_id = 0;
    char fd_dir_path[128];
    DIR *dir;
    struct dirent *de;
    int pidfd;
    int saw_eexist = 0;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "usage: %s <target-pid> [old-prog-id]\n", argv[0]);
        return 2;
    }

    target_pid = (pid_t)strtol(argv[1], NULL, 10);
    if (target_pid <= 0) {
        fprintf(stderr, "invalid pid: %s\n", argv[1]);
        return 2;
    }
    if (argc == 3)
        requested_old_id = (__u32)strtoul(argv[2], NULL, 10);

    if (_IOC_NR(PERF_EVENT_IOC_QUERY_BPF) != 10 ||
        _IOC_NR(PERF_EVENT_IOC_SET_BPF) != 8 ||
        _IOC_NR(PERF_EVENT_IOC_ID) != 7) {
        fprintf(stderr,
                "unexpected perf ioctl numbers: QUERY=%u SET_BPF=%u ID=%u\n",
                _IOC_NR(PERF_EVENT_IOC_QUERY_BPF),
                _IOC_NR(PERF_EVENT_IOC_SET_BPF),
                _IOC_NR(PERF_EVENT_IOC_ID));
        return 2;
    }

    pidfd = (int)syscall(SYS_pidfd_open, target_pid, 0);
    if (pidfd < 0) {
        fprintf(stderr, "pidfd_open(%d) failed: errno=%d (%s)\n",
                target_pid, errno, strerror(errno));
        return 1;
    }

    snprintf(fd_dir_path, sizeof(fd_dir_path), "/proc/%d/fd", target_pid);
    dir = opendir(fd_dir_path);
    if (!dir) {
        fprintf(stderr, "opendir(%s) failed: errno=%d (%s)\n",
                fd_dir_path, errno, strerror(errno));
        close(pidfd);
        return 1;
    }

    while ((de = readdir(dir)) != NULL) {
        int remote_fd;
        int ret;

        if (parse_fd_name(de->d_name, &remote_fd) < 0)
            continue;
        ret = try_remote_fd(pidfd, target_pid, remote_fd, requested_old_id);
        if (ret == 1) {
            closedir(dir);
            close(pidfd);
            return 0;
        }
        if (ret == 2)
            saw_eexist = 1;
        else if (ret < 0) {
            closedir(dir);
            close(pidfd);
            return 1;
        }
    }

    closedir(dir);
    close(pidfd);

    if (saw_eexist) {
        fprintf(stderr, "no replacement succeeded; at least one target returned EEXIST\n");
        return 3;
    }

    fprintf(stderr, "no matching queryable perf_event fd found for pid %d", target_pid);
    if (requested_old_id)
        fprintf(stderr, " and old prog id %u", requested_old_id);
    fprintf(stderr, "\n");
    return 1;
}
```

## 6. How to run it

Commands from project root, inside the privileged VM/container:

```bash
cd /home/yunwei37/workspace/bpf-benchmark
mkdir -p docs/tmp/poc-b

# Future engineer creates docs/tmp/poc_b_perf_event_swap.c from section 5.
cc -O2 -Wall -Wextra \
    -o docs/tmp/poc-b/poc_b_perf_event_swap \
    docs/tmp/poc_b_perf_event_swap.c

sysctl -w kernel.bpf_stats_enabled=1

/usr/sbin/capable-bpfcc > docs/tmp/poc-b/capable.out 2> docs/tmp/poc-b/capable.err &
CAPABLE_PID=$!

stress-ng --cap 4 --timeout 120s --metrics-brief &
WORKLOAD_PID=$!

sleep 5
OLD_ID=$(bpftool -j prog show | jq -r '.[] | select(.name=="cap_capable" and .type=="kprobe") | .id' | head -1)
bpftool prog show id "$OLD_ID"

docs/tmp/poc-b/poc_b_perf_event_swap "$CAPABLE_PID" "$OLD_ID"

bpftool prog show id "$OLD_ID"
bpftool -j prog show | jq '.[] | select(.name=="poc_b_dummy")'
tail -n 40 docs/tmp/poc-b/capable.out

kill "$WORKLOAD_PID" "$CAPABLE_PID" 2>/dev/null || true
```

Expected current-kernel result:

```text
SET_BPF(dummy_fd=...,id=...) failed: errno=17 (File exists)
after_failed_set: prog_cnt=... ids=...,<old id>,...
no replacement succeeded; at least one target returned EEXIST
```

Expected patched-kernel result:

```text
before: prog_cnt=... ids=...,<old id>,...
dummy prog_fd=... prog_id=<new id>
after: prog_cnt=... ids=...,<new id>,...
success: perf event now reports dummy prog_id=<new id>
```

For the `opensnoop-bpfcc` variant, substitute:

```bash
/usr/sbin/opensnoop-bpfcc > docs/tmp/poc-b/opensnoop.out 2> docs/tmp/poc-b/opensnoop.err &
OPENSNOOP_PID=$!
stress-ng --open 4 --open-max 1024 --timeout 120s --metrics-brief &
OLD_ID=$(bpftool -j prog show | jq -r '.[] | select(.type=="kprobe" and (.name|test("open|trace_return|syscall"))) | .id' | head -1)
docs/tmp/poc-b/poc_b_perf_event_swap "$OPENSNOOP_PID" "$OLD_ID"
tail -n 40 docs/tmp/poc-b/opensnoop.out
```

If `opensnoop-bpfcc` uses kfunc/fentry on the target kernel, this variant will
not find the intended kprobe perf_event fd. Use `capable-bpfcc` for the primary
PoC.

## 7. Failure modes

- BCC tool attached through tracefs but has no userspace perf_event fd.
  Legacy BCC kprobe attach usually creates tracefs kprobe events and still
  opens perf_event fds that remain in the Python process. This should not
  affect `capable-bpfcc`; its `kprobe__cap_capable` auto-attach path should
  leave `anon_inode:[perf_event]` fds. It can affect tools or versions that
  use BPF links, fentry/kfunc, raw tracepoints, or another attach path with no
  app-owned perf_event fd.
- `PERF_EVENT_IOC_QUERY_BPF` returns `EINVAL`.
  In the repo kernel, `perf_event_query_prog_array()` rejects events whose
  `event->attr.type != PERF_TYPE_TRACEPOINT`. Legacy BCC kprobes created via
  tracefs normally appear as tracepoint perf events with kprobe flags. Direct
  `PERF_TYPE_KPROBE` perf events or non-tracing perf events can fail query.
- `PERF_EVENT_IOC_SET_BPF` returns `EEXIST`.
  This is expected on the inspected repo kernel because
  `perf_event_attach_bpf_prog()` rejects `event->prog` that is already set.
  That means the ioctl can attach to an empty event, but it cannot replace BCC's
  existing program.
- BPF link case on Linux `>= 5.7`.
  If BCC or another tool uses `BPF_LINK_TYPE_PERF_EVENT`, `BPF_LINK_UPDATE`
  does not help on this kernel because `bpf_perf_link_lops` has no
  `update_prog`. A duplicated perf fd may still exist, but query/set semantics
  do not become a generic link-update mechanism.
- The duplicated fd is bound to an event that is not enabled.
  `QUERY_BPF` may still show programs on the tracepoint's program array, but
  no counter/output change will be visible until the underlying event fires and
  the BPF program actually runs.
- BCC dynamically loads or unloads probes.
  The remote fd can close between `/proc/$pid/fd` enumeration and
  `pidfd_getfd()`, producing `EBADF`, or `QUERY_BPF` can stop showing the old
  id. Re-run discovery against the live process.
- Mismatched program type.
  A dummy `BPF_PROG_TYPE_KPROBE` only matches kprobe/uprobe tracing events.
  Trying to set it on a tracepoint event returns `EINVAL`; a tracepoint target
  would need a `BPF_PROG_TYPE_TRACEPOINT` dummy that satisfies that tracepoint's
  context constraints.
- Permission failure.
  `pidfd_getfd()` can return `EPERM` if ptrace access is denied by missing
  `CAP_SYS_PTRACE`, Yama `ptrace_scope`, user namespace mismatch, or container
  restrictions. `BPF_PROG_LOAD`/`QUERY_BPF` can fail without BPF/perfmon
  privilege.
- Multiple programs on the same tracepoint.
  `QUERY_BPF` reports the tracepoint program array, not just the program owned
  by one fd. Always filter by the expected old program id when possible.

## 8. What this PoC explicitly does not prove

- It does not prove a stock-kernel replacement path exists. On the inspected
  repo kernel, the expected result is `EEXIST`, which proves the opposite.
- It does not prove general userspace ReJIT or transparent optimization for the
  corpus. It touches one BCC kprobe/perf_event attach path only.
- It does not prove `BPF_LINK_UPDATE` coverage for perf-event, kprobe,
  tracepoint, raw tracepoint, tracing, LSM, or freplace programs.
- It does not preserve or reconstruct original BPF load attributes, map fd
  arrays, BTF metadata, func/line info, or verifier logs. The dummy program has
  no maps and no metadata.
- It does not prove benchmark-runner compatibility. A successful userspace
  replacement creates a new program id, while the current benchmark accounting
  model assumes in-place ReJIT keeps the old program id.
- It does not prove semantic equivalence of an optimized program. The dummy is
  intentionally behavior-changing so the swap is easy to observe.
- It does not prove `opensnoop-bpfcc` is always a kprobe target. On kernels
  where BCC reports kfunc support, the script can use kfunc/fentry instead of
  legacy kprobes.
- It does not prove safety for remote fd manipulation in a production daemon.
  It is a one-shot root-only diagnostic that should fail loudly when any syscall
  or ioctl does not do exactly what is expected.
