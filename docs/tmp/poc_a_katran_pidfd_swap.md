# PoC-A: Katran pidfd XDP Link Swap

This is a design-only document. Do not run it as part of a benchmark result.
It is a one-shot proof-of-capability plan for a future engineer to implement
and execute inside the existing runner runtime image.

Important repo finding: the requested `corpus/apps/katran/` directory does not
exist in this tree. The current Katran corpus wiring is:

- `runner/libs/app_runners/katran.py`
- `runner/containers/katran-artifacts.Dockerfile`
- `runner/mk/katran-artifacts.mk`
- `corpus/config/macro_apps.yaml`

The current upstream Katran code in `runner/repos/katran` attaches standalone
XDP through legacy netlink (`KatranLb::attachBpfProgs()` ->
`BaseBpfAdapter::modifyXdpProg()` -> `NetlinkMessage::XDP()`), not through a
`bpf_link` FD. The corpus runner then calls `session.reattach_xdpgeneric()`,
which detaches and re-attaches by program id using `bpftool net attach`.
Therefore this PoC has two outcomes:

- Primary success: Katran exposes an `anon_inode:bpf-link` FD and the tool
  swaps that link with `BPF_LINK_UPDATE`.
- Expected fallback on the current code path: no `bpf-link` FD exists because
  Katran is attached as legacy ifindex XDP; use the fallback section to test
  netlink replace or to convert a clean interface to link ownership.

## 1. Goal And Success Criteria

Goal: verify that a userspace process can take ownership of Katran's live XDP
link FD through `pidfd_getfd(2)` and atomically replace the attached
`balancer_ingress` program with a minimal `XDP_PASS` program using
`BPF_LINK_UPDATE`.

Concrete observable signals for "verified":

1. Katran is running from the real upstream `katran_server_grpc` binary with the
   real `balancer.bpf.o` and `healthchecking_ipip.bpf.o` artifacts. This is the
   app-level loader path, not a framework-side `.bpf.o` loader.
2. `/proc/$KATRAN_PID/fd/*` contains at least one symlink whose target is
   `anon_inode:bpf-link` or `anon_inode:[bpf-link]`.
3. `pidfd_open($KATRAN_PID, 0)` followed by `pidfd_getfd(pidfd, remote_fd, 0)`
   returns a local duplicate of that link FD.
4. `BPF_OBJ_GET_INFO_BY_FD` on the duplicated link FD returns:
   - `struct bpf_link_info.type == BPF_LINK_TYPE_XDP`
   - `struct bpf_link_info.prog_id == OLD_PROG_ID`
   - `struct bpf_link_info.xdp.ifindex == if_nametoindex("katran0")`
5. `OLD_PROG_ID` matches the live `balancer_ingress` program id from
   `bpftool prog show name balancer_ingress` or the Katran runner metadata.
6. A new dummy `BPF_PROG_TYPE_XDP` program is loaded from the exact
   two-instruction `XDP_PASS` bytecode in section 3.f.
7. `BPF_LINK_UPDATE` on the duplicated link FD succeeds, preferably with
   `BPF_F_REPLACE` and `old_prog_fd` set to the current `OLD_PROG_ID` fd.
8. A second `BPF_OBJ_GET_INFO_BY_FD` on the same link FD returns the same link
   id and ifindex, but a different `prog_id == NEW_PROG_ID`.
9. Runtime counters show object identity changed:
   - `bpftool prog show id $OLD_PROG_ID` stops increasing.
   - `bpftool prog show id $NEW_PROG_ID` starts at `run_cnt == 0` or near-zero
     immediately after load, then increments from that baseline after XDP
     traffic reaches `katran0`.
10. Traffic behavior changes:
    - Before the swap, `ip netns exec katran-client wrk ... http://10.100.1.1:8080/`
      reaches the real server through Katran.
    - After the swap, `XDP_PASS` lets packets continue into the host stack
      without Katran DSR/load-balancing, so the same VIP request should fail,
      time out, or otherwise stop producing the prior `katran-ok` response.

This PoC is not a performance measurement. It only proves link-FD discovery,
link metadata readback, atomic link update, counter identity reset on a new
program object, and a visible traffic-path change.

## 2. Prerequisites

Kernel and UAPI requirements:

- `pidfd_open(2)`: Linux >= 5.3. UAPI/prototype references:
  `include/uapi/linux/pidfd.h` for pidfd flags,
  `include/uapi/asm-generic/unistd.h` for `__NR_pidfd_open`,
  `include/linux/syscalls.h` for `sys_pidfd_open`, and `kernel/pid.c` for the
  syscall implementation.
- `pidfd_getfd(2)`: Linux >= 5.6. UAPI/prototype references:
  `include/uapi/asm-generic/unistd.h` for `__NR_pidfd_getfd`,
  `include/linux/syscalls.h` for `sys_pidfd_getfd`, and `kernel/pid.c` for the
  ptrace-gated implementation.
- `BPF_LINK_UPDATE`: Linux >= 5.7. UAPI references:
  `include/uapi/linux/bpf.h` `enum bpf_cmd` and
  `union bpf_attr.link_update`.
- XDP `bpf_link`: Linux >= 5.9. UAPI and implementation references:
  `include/uapi/linux/bpf.h` `BPF_LINK_TYPE_XDP`,
  `include/uapi/linux/bpf.h` `struct bpf_link_info.xdp.ifindex`, and
  `net/core/dev.c` `bpf_xdp_link_attach()` / `bpf_xdp_link_update()`.
- `BPF_OBJ_GET_INFO_BY_FD`: current target UAPI reference
  `include/uapi/linux/bpf.h` `enum bpf_cmd`, `union bpf_attr.info`,
  `struct bpf_prog_info`, and `struct bpf_link_info`.
- `BPF_PROG_LOAD`: current target UAPI reference
  `include/uapi/linux/bpf.h` `enum bpf_cmd`, `union bpf_attr` program-load
  fields, `struct bpf_insn`, `BPF_PROG_TYPE_XDP`, `BPF_XDP`, and `enum
  xdp_action`.
- Legacy netlink fallback uses XDP replace flags from
  `include/uapi/linux/if_link.h` (`XDP_FLAGS_REPLACE`,
  `XDP_FLAGS_SKB_MODE`, `XDP_FLAGS_DRV_MODE`, `XDP_FLAGS_HW_MODE`).

Runtime and privilege requirements:

- Run in the runner runtime image or an equivalent privileged container with
  `--pid=host`, `--network=host`, `--ipc=host`, and `--cgroupns=host`.
  `runner/libs/suite_commands.py` already uses these flags for suites.
- The process running the PoC needs `CAP_SYS_PTRACE` for `pidfd_getfd(2)`;
  `kernel/pid.c` documents that `pidfd_getfd` requires ptrace permission over
  the target task.
- The process needs the usual BPF/XDP privileges to load and update programs:
  root in the privileged runtime container is the expected setup.
- Enable BPF runtime counters before checking `run_cnt`:
  `sysctl -q -w kernel.bpf_stats_enabled=1`. The corpus suite does this in
  `runner/suites/_common.py::ensure_bpf_stats_enabled()`.
- A kinsn-only kernel is sufficient. This PoC does not use any kinsn program,
  kfunc, `BPF_PROG_REJIT`, verifier-state side input, or daemon pass.

External version references used while preparing this plan:

- KernelNewbies Linux 5.6 notes list `pidfd_getfd(2)`:
  <https://kernelnewbies.org/Linux_5.6>
- Linux man-pages history for `pidfd_getfd(2)` says Linux 5.6:
  <https://man7.org/linux/man-pages/man2/pidfd_getfd.2.html>
- eBPF docs list `BPF_LINK_UPDATE` as v5.7:
  <https://docs.ebpf.io/linux/syscall/BPF_LINK_UPDATE/>
- KernelNewbies Linux 5.9 notes list XDP link support:
  <https://kernelnewbies.org/Linux_5.9>
- eBPF docs list XDP link info fields as v5.9:
  <https://docs.ebpf.io/linux/syscall/BPF_OBJ_GET_INFO_BY_FD/>

## 3. Step-by-Step Execution

### 3.a. Start Katran

There is no docker compose file for Katran in this repo. The benchmark entry is
`make corpus` with `BPFREJIT_CORPUS_APPS=katran`, and the actual app startup
logic is `runner/libs/app_runners/katran.py`.

For a normal suite smoke, use only the Makefile:

```bash
BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=30 make corpus
```

For this PoC, the process has to stay alive while a second command runs the
swap tool. Use the same runtime image and mount policy as the suite container.
This is a debug PoC shell, not a benchmark run:

```bash
make image-runner-runtime-image-tar
docker load -i .cache/container-images/x86_64-runner-runtime.image.tar
docker run --rm -it --privileged \
  --pid=host --network=host --ipc=host --cgroupns=host \
  -e BPFREJIT_INSIDE_RUNTIME_CONTAINER=1 \
  -e HOME=/root \
  -w /home/yunwei37/workspace/bpf-benchmark \
  -v /sys:/sys \
  -v /sys/fs/bpf:/sys/fs/bpf \
  -v /sys/kernel/debug:/sys/kernel/debug \
  -v /lib/modules:/lib/modules:ro \
  -v /boot:/boot:ro \
  bpf-benchmark/runner-runtime:x86_64 bash
```

Inside that shell, start the real upstream Katran binary and keep it alive. This
uses the same Python runner helpers as the corpus but intentionally does not
call `session.reattach_xdpgeneric()`, because that helper forces a legacy
`bpftool net attach` rebind and can destroy the original attach shape being
tested.

```bash
sysctl -q -w kernel.bpf_stats_enabled=1
python3 - <<'PY'
import os
import signal
import time
from pathlib import Path

from runner.libs.app_runners.katran import (
    DEFAULT_HC_V4_TUN_IFACE,
    DEFAULT_HC_V6_TUN_IFACE,
    DEFAULT_INTERFACE,
    REAL_NS,
    ROUTER_LB_MAC,
    TCP_PROTO,
    VIP_IP,
    VIP_PORT,
    KatranDsrTopology,
    KatranServerSession,
    NamespaceHttpServer,
    configure_katran_maps,
    resolve_katran_server_binary,
)

katran_root = Path(os.environ["BPFREJIT_REPO_ARTIFACT_ROOT"]) / "katran"
topology = KatranDsrTopology(DEFAULT_INTERFACE)
http_server = NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT)
session = KatranServerSession(
    server_binary=resolve_katran_server_binary(None),
    balancer_prog_path=katran_root / "bpf" / "balancer.bpf.o",
    healthchecking_prog_path=katran_root / "bpf" / "healthchecking_ipip.bpf.o",
    iface=DEFAULT_INTERFACE,
    default_router_mac=ROUTER_LB_MAC,
)

stop = False
def handle_stop(_signum, _frame):
    global stop
    stop = True

signal.signal(signal.SIGTERM, handle_stop)
signal.signal(signal.SIGINT, handle_stop)

try:
    topology.__enter__()
    http_server.__enter__()
    session.__enter__()
    configure_katran_maps(session, proto=TCP_PROTO)
    meta = session.metadata()
    print(f"KATRAN_PID={meta['pid']}", flush=True)
    print(f"KATRAN_IFACE={meta['iface']}", flush=True)
    print(f"KATRAN_IFINDEX={meta['ifindex']}", flush=True)
    print(f"KATRAN_BALANCER_PROG_ID={meta['balancer_prog_id']}", flush=True)
    print(f"KATRAN_ATTACHED_PROG_ID={meta['attached_prog_id']}", flush=True)
    print(f"KATRAN_ATTACH_MODE={meta['attach_mode']}", flush=True)
    print("Katran PoC session is live; press Ctrl-C to clean up.", flush=True)
    while not stop:
        time.sleep(1)
finally:
    try:
        session.close()
    finally:
        try:
            http_server.close()
        finally:
            topology.close()
PY
```

The equivalent real Katran binary arguments, as constructed by
`KatranServerSession.__enter__()`, are:

```text
katran_server_grpc
  -balancer_prog=/artifacts/user/repo-artifacts/x86_64/katran/bpf/balancer.bpf.o
  -healthchecker_prog=/artifacts/user/repo-artifacts/x86_64/katran/bpf/healthchecking_ipip.bpf.o
  -default_mac=02:00:00:00:00:0b
  -intf=katran0
  -ipip_intf=ipip0
  -ipip6_intf=ipip60
  -hc_forwarding=false
  -logtostderr
  -alsologtostderr
```

Baseline traffic check before the swap:

```bash
ip netns exec katran-client wrk -t1 -c1 -d5s --latency http://10.100.1.1:8080/
bpftool prog show name balancer_ingress
bpftool net show dev katran0
bpftool link show
```

If `bpftool link show` has no XDP link and `/proc/$KATRAN_PID/fd` has no
`bpf-link`, that is not a PoC tool bug. It means the current Katran path is
legacy netlink XDP; use the fallback section below.

### 3.b. Discover Katran's Host PID

With `--pid=host`, the PID printed by the launcher and the PID seen by `pgrep`
are host PIDs:

```bash
pgrep -af 'katran_server_grpc'
cat /proc/$KATRAN_PID/status | grep -E '^(Name|Pid|NSpid):'
```

If the PoC is run from a container that does not use `--pid=host`, fix the
container launch first. Do not try to translate namespace-local PIDs by hand for
the primary PoC.

### 3.c. Walk `/proc/$pid/fd` And Filter BPF Links

Manual inspection:

```bash
for f in /proc/$KATRAN_PID/fd/*; do
  printf '%s -> ' "$f"
  readlink "$f" || true
done | grep -E 'bpf-link|bpf-prog|bpf-map'
```

Expected primary-path signal:

```text
/proc/12345/fd/NN -> anon_inode:bpf-link
```

or:

```text
/proc/12345/fd/NN -> anon_inode:[bpf-link]
```

Kernel reference: BPF links are exposed as anon inode FDs by current
`kernel/bpf/syscall.c` `bpf_link_new_fd()` and described to userspace through
Linux >= 5.7 `include/uapi/linux/bpf.h`.

### 3.d. Duplicate The Link FD With `pidfd_open` + `pidfd_getfd`

The one-shot C tool in section 4 does:

```text
pidfd = pidfd_open(katran_pid, 0)
local_link_fd = pidfd_getfd(pidfd, remote_link_fd, 0)
```

Kernel references:

- Linux >= 5.3 `pidfd_open(2)`: `include/uapi/asm-generic/unistd.h`,
  `include/uapi/linux/pidfd.h`, `include/linux/syscalls.h`, `kernel/pid.c`.
- Linux >= 5.6 `pidfd_getfd(2)`: `include/uapi/asm-generic/unistd.h`,
  `include/linux/syscalls.h`, `kernel/pid.c`.

### 3.e. Read Link Metadata With `BPF_OBJ_GET_INFO_BY_FD`

Call Linux `BPF_OBJ_GET_INFO_BY_FD` (current target UAPI:
`include/uapi/linux/bpf.h` `union bpf_attr.info`) on the duplicated link FD and
interpret the output as `struct bpf_link_info` (Linux >= 5.9 XDP fields:
`include/uapi/linux/bpf.h` `struct bpf_link_info.xdp.ifindex`).

Required checks:

```text
info.type == BPF_LINK_TYPE_XDP
info.prog_id > 0
info.xdp.ifindex == if_nametoindex("katran0")
```

Then open the current program with `BPF_PROG_GET_FD_BY_ID` (current target UAPI:
`include/uapi/linux/bpf.h` `enum bpf_cmd`) so `BPF_LINK_UPDATE` can use
`BPF_F_REPLACE`.

### 3.f. Load Dummy XDP Program

Load a minimal XDP program through Linux `BPF_PROG_LOAD` (current target UAPI:
`include/uapi/linux/bpf.h` `union bpf_attr` program-load fields,
`BPF_PROG_TYPE_XDP`, `BPF_XDP`, `struct bpf_insn`, and `enum xdp_action`).

Exact instruction array:

```c
static struct bpf_insn xdp_pass_prog[] = {
    {
        .code = BPF_ALU64 | BPF_MOV | BPF_K,
        .dst_reg = BPF_REG_0,
        .src_reg = 0,
        .off = 0,
        .imm = XDP_PASS,
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

Load attributes:

```text
prog_type = BPF_PROG_TYPE_XDP
expected_attach_type = BPF_XDP
license = "GPL"
prog_name = "poc_xdp_pass"
```

If `BPF_LINK_UPDATE` returns `EINVAL` because the old Katran program was loaded
with `expected_attach_type == 0`, rerun the tool with `--expected-attach-type=0`.
Do not silently retry in automation; the mismatch is an important observation.

### 3.g. Swap With `BPF_LINK_UPDATE`

Use Linux >= 5.7 `BPF_LINK_UPDATE` (UAPI:
`include/uapi/linux/bpf.h` `enum bpf_cmd`,
`union bpf_attr.link_update`) with:

```text
link_update.link_fd = duplicated katran link fd
link_update.new_prog_fd = dummy XDP_PASS prog fd
link_update.flags = BPF_F_REPLACE
link_update.old_prog_fd = fd opened from OLD_PROG_ID
```

`BPF_F_REPLACE` is preferred because it makes the update conditional on the link
still pointing at the program observed in step 3.e. A force mode
(`flags = 0`, `old_prog_fd = 0`) is useful only for manual debugging after the
race has already been understood.

XDP link implementation reference: Linux >= 5.9 `net/core/dev.c`
`bpf_xdp_link_update()` checks the old program, validates program type and
expected attach type, installs the new XDP program, and swaps `link->prog`.

### 3.h. Verify The Swap

Immediately after the tool exits:

```bash
bpftool link show
bpftool prog show id $OLD_PROG_ID
bpftool prog show id $NEW_PROG_ID
bpftool net show dev katran0
ip -details link show dev katran0
```

Expected primary-path output:

```text
old link: type=xdp prog_id=OLD_PROG_ID ifindex=KATRAN_IFINDEX
BPF_LINK_UPDATE: ok
new link: type=xdp prog_id=NEW_PROG_ID ifindex=KATRAN_IFINDEX
new prog: run_cnt=0 run_time_ns=0
```

Then drive traffic:

```bash
ip netns exec katran-client wrk -t1 -c1 -d5s --latency http://10.100.1.1:8080/ || true
bpftool prog show id $OLD_PROG_ID
bpftool prog show id $NEW_PROG_ID
```

Expected counter behavior:

- `NEW_PROG_ID` has a fresh counter baseline because it is a new BPF program
  object. Its `run_cnt` increments after traffic hits the XDP hook.
- `OLD_PROG_ID` no longer receives XDP traffic through that link.

Expected traffic behavior:

- Before swap: VIP request reaches the real namespace server.
- After swap: dummy `XDP_PASS` does not perform Katran forwarding, so the VIP
  request should stop producing the previous successful response.

## 4. Concrete Code: One-Shot C Tool

Save this as `docs/tmp/poc_a_katran_pidfd_swap.c` when implementing the PoC.
The design task does not create this source file; it is included here so the
future implementation can be copied without redoing the syscall details.

```c
// SPDX-License-Identifier: MIT
#define _GNU_SOURCE
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/if_link.h>
#include <linux/unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef SYS_pidfd_open
#define SYS_pidfd_open __NR_pidfd_open
#endif

#ifndef SYS_pidfd_getfd
#define SYS_pidfd_getfd __NR_pidfd_getfd
#endif

#ifndef BPF_LINK_TYPE_XDP
#error "Need Linux UAPI headers with BPF_LINK_TYPE_XDP (Linux >= 5.9)."
#endif

static __u64 ptr_to_u64(const void *ptr)
{
    return (__u64)(uintptr_t)ptr;
}

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, size_t size)
{
    return (int)syscall(SYS_bpf, cmd, attr, size);
}

static int xpidfd_open(pid_t pid)
{
    return (int)syscall(SYS_pidfd_open, pid, 0);
}

static int xpidfd_getfd(int pidfd, int target_fd)
{
    return (int)syscall(SYS_pidfd_getfd, pidfd, target_fd, 0);
}

static int obj_get_info(int fd, void *info, __u32 *info_len)
{
    union bpf_attr attr;

    memset(&attr, 0, sizeof(attr));
    attr.info.bpf_fd = (__u32)fd;
    attr.info.info_len = *info_len;
    attr.info.info = ptr_to_u64(info);

    if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
        return -1;

    *info_len = attr.info.info_len;
    return 0;
}

static int get_link_info(int fd, struct bpf_link_info *info)
{
    __u32 len = sizeof(*info);

    memset(info, 0, sizeof(*info));
    return obj_get_info(fd, info, &len);
}

static int get_prog_info(int fd, struct bpf_prog_info *info)
{
    __u32 len = sizeof(*info);

    memset(info, 0, sizeof(*info));
    return obj_get_info(fd, info, &len);
}

static int prog_get_fd_by_id(__u32 prog_id)
{
    union bpf_attr attr;

    memset(&attr, 0, sizeof(attr));
    attr.prog_id = prog_id;
    return sys_bpf(BPF_PROG_GET_FD_BY_ID, &attr, sizeof(attr));
}

static int load_xdp_pass_prog(__u32 expected_attach_type)
{
    static struct bpf_insn insns[] = {
        {
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = BPF_REG_0,
            .src_reg = 0,
            .off = 0,
            .imm = XDP_PASS,
        },
        {
            .code = BPF_JMP | BPF_EXIT,
            .dst_reg = 0,
            .src_reg = 0,
            .off = 0,
            .imm = 0,
        },
    };
    char license[] = "GPL";
    char log_buf[65536];
    union bpf_attr attr;
    int fd;

    memset(log_buf, 0, sizeof(log_buf));
    memset(&attr, 0, sizeof(attr));
    attr.prog_type = BPF_PROG_TYPE_XDP;
    attr.insn_cnt = sizeof(insns) / sizeof(insns[0]);
    attr.insns = ptr_to_u64(insns);
    attr.license = ptr_to_u64(license);
    attr.log_level = 1;
    attr.log_size = sizeof(log_buf);
    attr.log_buf = ptr_to_u64(log_buf);
    attr.expected_attach_type = expected_attach_type;
    snprintf(attr.prog_name, sizeof(attr.prog_name), "poc_xdp_pass");

    fd = sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
    if (fd < 0) {
        fprintf(stderr, "BPF_PROG_LOAD failed: %s\n", strerror(errno));
        if (log_buf[0] != '\0')
            fprintf(stderr, "verifier log:\n%s\n", log_buf);
        return -1;
    }
    return fd;
}

static int link_update(int link_fd, int new_prog_fd, int old_prog_fd, int force)
{
    union bpf_attr attr;

    memset(&attr, 0, sizeof(attr));
    attr.link_update.link_fd = (__u32)link_fd;
    attr.link_update.new_prog_fd = (__u32)new_prog_fd;
    if (!force) {
        attr.link_update.flags = BPF_F_REPLACE;
        attr.link_update.old_prog_fd = (__u32)old_prog_fd;
    }

    return sys_bpf(BPF_LINK_UPDATE, &attr, sizeof(attr));
}

static int is_number(const char *s)
{
    if (*s == '\0')
        return 0;
    for (; *s; s++) {
        if (!isdigit((unsigned char)*s))
            return 0;
    }
    return 1;
}

static int is_bpf_link_target(const char *target)
{
    return strstr(target, "anon_inode:bpf-link") != NULL ||
           strstr(target, "anon_inode:[bpf-link]") != NULL;
}

static int find_xdp_link_fd(pid_t pid, int want_ifindex, int *remote_fd_out,
                            struct bpf_link_info *info_out)
{
    char fd_dir_path[64];
    DIR *dir;
    struct dirent *de;
    int pidfd;

    snprintf(fd_dir_path, sizeof(fd_dir_path), "/proc/%d/fd", pid);
    dir = opendir(fd_dir_path);
    if (!dir) {
        fprintf(stderr, "opendir(%s): %s\n", fd_dir_path, strerror(errno));
        return -1;
    }

    pidfd = xpidfd_open(pid);
    if (pidfd < 0) {
        fprintf(stderr, "pidfd_open(%d): %s\n", pid, strerror(errno));
        closedir(dir);
        return -1;
    }

    while ((de = readdir(dir)) != NULL) {
        char link_path[PATH_MAX];
        char target[PATH_MAX];
        ssize_t n;
        int remote_fd;
        int local_fd;
        struct bpf_link_info info;

        if (!is_number(de->d_name))
            continue;

        snprintf(link_path, sizeof(link_path), "%s/%s", fd_dir_path, de->d_name);
        n = readlink(link_path, target, sizeof(target) - 1);
        if (n < 0)
            continue;
        target[n] = '\0';

        if (!is_bpf_link_target(target))
            continue;

        remote_fd = atoi(de->d_name);
        local_fd = xpidfd_getfd(pidfd, remote_fd);
        if (local_fd < 0) {
            fprintf(stderr, "pidfd_getfd(pid=%d, fd=%d): %s\n",
                    pid, remote_fd, strerror(errno));
            close(pidfd);
            closedir(dir);
            return -1;
        }

        if (get_link_info(local_fd, &info) < 0) {
            fprintf(stderr, "BPF_OBJ_GET_INFO_BY_FD(link fd %d): %s\n",
                    local_fd, strerror(errno));
            close(local_fd);
            continue;
        }

        printf("candidate remote_fd=%d local_fd=%d link_id=%u type=%u prog_id=%u ifindex=%u\n",
               remote_fd, local_fd, info.id, info.type, info.prog_id,
               info.xdp.ifindex);

        if (info.type == BPF_LINK_TYPE_XDP &&
            (want_ifindex == 0 || info.xdp.ifindex == (__u32)want_ifindex)) {
            *remote_fd_out = remote_fd;
            *info_out = info;
            close(pidfd);
            closedir(dir);
            return local_fd;
        }

        close(local_fd);
    }

    fprintf(stderr, "no XDP bpf-link fd found in /proc/%d/fd\n", pid);
    close(pidfd);
    closedir(dir);
    return -1;
}

static void usage(const char *argv0)
{
    fprintf(stderr,
            "usage: %s --pid PID [--ifindex IFINDEX] [--force] "
            "[--expected-attach-type=xdp|0]\n",
            argv0);
}

int main(int argc, char **argv)
{
    pid_t pid = 0;
    int want_ifindex = 0;
    int force = 0;
    __u32 expected_attach_type = BPF_XDP;
    int remote_fd = -1;
    int link_fd = -1;
    int old_prog_fd = -1;
    int new_prog_fd = -1;
    struct bpf_link_info before_link;
    struct bpf_link_info after_link;
    struct bpf_prog_info old_prog;
    struct bpf_prog_info new_prog;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--pid") == 0 && i + 1 < argc) {
            pid = (pid_t)atoi(argv[++i]);
        } else if (strcmp(argv[i], "--ifindex") == 0 && i + 1 < argc) {
            want_ifindex = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--force") == 0) {
            force = 1;
        } else if (strcmp(argv[i], "--expected-attach-type=0") == 0) {
            expected_attach_type = 0;
        } else if (strcmp(argv[i], "--expected-attach-type=xdp") == 0) {
            expected_attach_type = BPF_XDP;
        } else {
            usage(argv[0]);
            return 2;
        }
    }

    if (pid <= 0) {
        usage(argv[0]);
        return 2;
    }

    link_fd = find_xdp_link_fd(pid, want_ifindex, &remote_fd, &before_link);
    if (link_fd < 0)
        return 1;

    printf("selected remote_fd=%d local_link_fd=%d link_id=%u old_prog_id=%u ifindex=%u\n",
           remote_fd, link_fd, before_link.id, before_link.prog_id,
           before_link.xdp.ifindex);

    old_prog_fd = prog_get_fd_by_id(before_link.prog_id);
    if (old_prog_fd < 0) {
        fprintf(stderr, "BPF_PROG_GET_FD_BY_ID(%u): %s\n",
                before_link.prog_id, strerror(errno));
        return 1;
    }
    if (get_prog_info(old_prog_fd, &old_prog) < 0) {
        fprintf(stderr, "BPF_OBJ_GET_INFO_BY_FD(old prog): %s\n", strerror(errno));
        return 1;
    }
    printf("old prog id=%u name=%.*s type=%u run_cnt=%llu run_time_ns=%llu\n",
           old_prog.id, (int)sizeof(old_prog.name), old_prog.name, old_prog.type,
           (unsigned long long)old_prog.run_cnt,
           (unsigned long long)old_prog.run_time_ns);

    new_prog_fd = load_xdp_pass_prog(expected_attach_type);
    if (new_prog_fd < 0)
        return 1;
    if (get_prog_info(new_prog_fd, &new_prog) < 0) {
        fprintf(stderr, "BPF_OBJ_GET_INFO_BY_FD(new prog): %s\n", strerror(errno));
        return 1;
    }
    printf("new prog id=%u name=%.*s type=%u run_cnt=%llu run_time_ns=%llu expected_attach_type=%u\n",
           new_prog.id, (int)sizeof(new_prog.name), new_prog.name, new_prog.type,
           (unsigned long long)new_prog.run_cnt,
           (unsigned long long)new_prog.run_time_ns,
           expected_attach_type);

    if (link_update(link_fd, new_prog_fd, old_prog_fd, force) < 0) {
        fprintf(stderr, "BPF_LINK_UPDATE failed: %s\n", strerror(errno));
        if (errno == EINVAL && expected_attach_type == BPF_XDP) {
            fprintf(stderr,
                    "hint: old program may have expected_attach_type=0; rerun with "
                    "--expected-attach-type=0 after confirming this is acceptable\n");
        }
        return 1;
    }
    printf("BPF_LINK_UPDATE ok\n");

    if (get_link_info(link_fd, &after_link) < 0) {
        fprintf(stderr, "BPF_OBJ_GET_INFO_BY_FD(link after update): %s\n",
                strerror(errno));
        return 1;
    }
    printf("after link_id=%u type=%u prog_id=%u ifindex=%u\n",
           after_link.id, after_link.type, after_link.prog_id,
           after_link.xdp.ifindex);

    if (after_link.id != before_link.id ||
        after_link.type != BPF_LINK_TYPE_XDP ||
        after_link.xdp.ifindex != before_link.xdp.ifindex ||
        after_link.prog_id != new_prog.id) {
        fprintf(stderr, "post-update link info did not match expected new program\n");
        return 1;
    }

    printf("success: link %u moved from prog %u to prog %u\n",
           after_link.id, before_link.prog_id, after_link.prog_id);
    return 0;
}
```

## 5. How To Run It

From project root, prepare the runtime image:

```bash
make image-runner-runtime-image-tar
docker load -i .cache/container-images/x86_64-runner-runtime.image.tar
```

Start the debug runtime shell and Katran session using section 3.a. In a second
shell attached to the same container, or in the same shell after backgrounding
the Python launcher, create and compile the one-shot tool:

```bash
cc -O2 -Wall -Wextra -o /tmp/poc_a_katran_pidfd_swap docs/tmp/poc_a_katran_pidfd_swap.c
```

Discover the target:

```bash
KATRAN_PID=$(pgrep -n -f 'katran_server_grpc')
KATRAN_IFINDEX=$(cat /sys/class/net/katran0/ifindex)
for f in /proc/$KATRAN_PID/fd/*; do printf '%s -> ' "$f"; readlink "$f" || true; done | grep bpf-link || true
```

Run the swap:

```bash
/tmp/poc_a_katran_pidfd_swap --pid "$KATRAN_PID" --ifindex "$KATRAN_IFINDEX"
```

Expected primary-path stdout shape:

```text
candidate remote_fd=17 local_fd=5 link_id=42 type=6 prog_id=530 ifindex=123
selected remote_fd=17 local_link_fd=5 link_id=42 old_prog_id=530 ifindex=123
old prog id=530 name=balancer_ingress type=6 run_cnt=12345 run_time_ns=67890
new prog id=777 name=poc_xdp_pass type=6 run_cnt=0 run_time_ns=0 expected_attach_type=35
BPF_LINK_UPDATE ok
after link_id=42 type=6 prog_id=777 ifindex=123
success: link 42 moved from prog 530 to prog 777
```

Then verify:

```bash
OLD_PROG_ID=530
NEW_PROG_ID=777
bpftool link show
bpftool prog show id "$OLD_PROG_ID"
bpftool prog show id "$NEW_PROG_ID"
ip netns exec katran-client wrk -t1 -c1 -d5s --latency http://10.100.1.1:8080/ || true
bpftool prog show id "$OLD_PROG_ID"
bpftool prog show id "$NEW_PROG_ID"
```

If `BPF_LINK_UPDATE` fails with `EINVAL` and the link was otherwise valid,
rerun once with:

```bash
/tmp/poc_a_katran_pidfd_swap --pid "$KATRAN_PID" --ifindex "$KATRAN_IFINDEX" --expected-attach-type=0
```

Treat that as a recorded compatibility observation, not as a default policy.

## 6. Failure Modes And Manifestations

### Katran Binary Missing Or Katran Failed To Attach

Manifestation:

- The Python launcher fails before printing `KATRAN_PID`, or
  `Katran server did not expose an attached XDP program on katran0`.
- `bpftool prog show name balancer_ingress` returns nothing.
- `/sys/class/net/katran0/ifindex` is absent or `bpftool net show dev katran0`
  shows no XDP attachment.

Likely causes:

- `make image-runner-runtime-image-tar` was not run, or the runtime image was
  not loaded.
- Katran artifacts are missing under
  `/artifacts/user/repo-artifacts/x86_64/katran`.
- The topology setup failed before the upstream binary loaded BPF.

Action:

- Re-run the Katran startup script from section 3.a and inspect the exception.
- For an official smoke, use
  `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=30 make corpus`.

### Kernel Older Than Linux 5.6

Manifestation:

- `pidfd_open` or `pidfd_getfd` returns `ENOSYS`.
- The C tool prints `pidfd_open(...): Function not implemented` or
  `pidfd_getfd(...): Function not implemented`.

Kernel API reference:

- `pidfd_getfd(2)` is Linux >= 5.6:
  `include/uapi/asm-generic/unistd.h`, `include/linux/syscalls.h`,
  `kernel/pid.c`.

Action:

- Do not add `/proc/$pid/fd/$n` open fallbacks for the primary PoC. The goal is
  specifically to verify `pidfd_getfd`.
- Re-run on the project runtime kernel.

### Kernel Has `pidfd_getfd` But No XDP Link Support

Manifestation:

- `pidfd_getfd` works for other FDs, but there are no `bpf-link` FDs.
- `BPF_LINK_CREATE` with XDP returns `EINVAL` on a clean interface.
- Headers or `bpftool link` lack `BPF_LINK_TYPE_XDP`.

Kernel API reference:

- XDP `bpf_link` is Linux >= 5.9:
  `include/uapi/linux/bpf.h` `BPF_LINK_TYPE_XDP` and
  `struct bpf_link_info.xdp.ifindex`; implementation in `net/core/dev.c`.

Action:

- Use legacy netlink XDP replace only as a fallback experiment.

### Katran Uses Legacy Or Pinned XDP, Not A Link FD

Manifestation:

- `/proc/$KATRAN_PID/fd` has `anon_inode:bpf-prog` and `anon_inode:bpf-map`
  entries but no `anon_inode:bpf-link`.
- `bpftool net show dev katran0` shows an XDP program id, while
  `bpftool link show` does not show an XDP link for `katran0`.
- The one-shot tool exits with `no XDP bpf-link fd found`.

This is likely with the current repo. Evidence:

- `runner/repos/katran/katran/lib/KatranLb.cpp` attaches standalone mode through
  `bpfAdapter_->modifyXdpProg(main_fd, interface_index, config_.xdpAttachFlags)`.
- `runner/repos/katran/katran/lib/BaseBpfAdapter.cpp` implements
  `modifyXdpProg()` as a netlink operation.
- `runner/repos/katran/katran/lib/Netlink.cpp` writes `IFLA_XDP_FD` and
  `IFLA_XDP_FLAGS`.
- `runner/libs/app_runners/katran.py` later calls `session.reattach_xdpgeneric()`,
  which uses `bpftool net detach` and `bpftool net attach ... overwrite`.

Fallback A: legacy netlink replace.

- Open `OLD_PROG_ID` with `BPF_PROG_GET_FD_BY_ID` (current target UAPI:
  `include/uapi/linux/bpf.h`).
- Load the dummy XDP program with `BPF_PROG_LOAD` (current target UAPI:
  `include/uapi/linux/bpf.h`).
- Replace the XDP attachment through netlink with `XDP_FLAGS_REPLACE` and the
  old program fd as expected fd (UAPI:
  `include/uapi/linux/if_link.h`).
- This verifies userspace candidate swap for legacy XDP, but it does not verify
  `pidfd_getfd` or `BPF_LINK_UPDATE`.

Fallback B: convert a clean interface to link ownership for a link-update
mechanism test.

- Open the current Katran program by id.
- Detach the legacy XDP attachment from `katran0`.
- Call Linux >= 5.9 `BPF_LINK_CREATE` (UAPI:
  `include/uapi/linux/bpf.h` `union bpf_attr.link_create`) with the Katran
  program fd, `target_ifindex = katran0`, `attach_type = BPF_XDP`, and the same
  XDP mode flags.
- Then run `BPF_LINK_UPDATE` against the newly returned link FD.
- This verifies XDP link update mechanics, but not pidfd takeover from the
  Katran process, because the PoC process created the link.

### Permission Denied On `pidfd_getfd`

Manifestation:

- `pidfd_getfd(pid=..., fd=...): Operation not permitted`.
- Manual `/proc/$pid/fd` readlink works, but duplicating the FD fails.

Kernel API reference:

- Linux >= 5.6 `pidfd_getfd(2)` implementation in `kernel/pid.c` documents that
  the caller needs ptrace permission over the process represented by the pidfd.

Likely causes:

- Container was not started with `--privileged` or lacks `CAP_SYS_PTRACE`.
- Container was not started with `--pid=host`.
- A host LSM/Yama ptrace policy blocks cross-process fd duplication.

Action:

- Re-run in the runner-style privileged container.
- Confirm `CapEff` includes `CAP_SYS_PTRACE` and the target is visible in the
  same host PID namespace.

### `BPF_LINK_UPDATE` Returns `EINVAL`

Manifestation:

- The tool prints `BPF_LINK_UPDATE failed: Invalid argument`.

Likely causes:

- The duplicated link is not an XDP link.
- The new program type differs from the old program type.
- The new XDP program was loaded with a different `expected_attach_type` than
  the old Katran program.
- The kernel link ops do not support update for that link type.

Kernel API reference:

- Linux >= 5.7 `BPF_LINK_UPDATE` dispatcher:
  `include/uapi/linux/bpf.h` `union bpf_attr.link_update`,
  `kernel/bpf/syscall.c` `link_update()`.
- Linux >= 5.9 XDP update implementation:
  `net/core/dev.c` `bpf_xdp_link_update()`.

Action:

- Confirm `struct bpf_link_info.type == BPF_LINK_TYPE_XDP`.
- If the old program was loaded by old libbpf behavior, rerun with
  `--expected-attach-type=0` and record the observation.

### `BPF_LINK_UPDATE` Returns `EPERM`

Manifestation:

- The tool prints `BPF_LINK_UPDATE failed: Operation not permitted`.

Likely causes:

- `BPF_F_REPLACE` old program fd no longer matches `link->prog`.
- Another actor updated or detached the link between info readback and update.

Action:

- Rerun from a quiescent Katran session.
- Use `--force` only for manual debugging after confirming this is a race, not
  a type or permission issue.

## 7. What This PoC Does Not Prove

- It does not prove optimization correctness. The replacement program is a
  dummy `XDP_PASS`, not an optimized Katran program.
- It does not prove performance under traffic. Counters are used only as raw
  identity and execution signals.
- It does not prove the benchmark runner can consume new program ids. A
  userspace swap creates a new `prog_id`; the current corpus runner's in-place
  ReJIT assumptions still need separate design work.
- It does not prove correctness if Katran closes and reopens the link FD during
  the operation.
- It does not prove safety against concurrent app attach/detach operations.
- It does not prove coverage for non-XDP program types. Most tracing,
  perf-event, raw-tracepoint, and LSM links do not support `BPF_LINK_UPDATE`.
- It does not prove a transparent fallback for legacy netlink XDP. Netlink
  replace can be atomic with expected old fd, but discovering and owning that
  attach path is a separate mechanism from pidfd link-FD takeover.
- It does not require, exercise, or validate kinsn support.

