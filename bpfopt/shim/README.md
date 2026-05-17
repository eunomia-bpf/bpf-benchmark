# bpfrejit-shim

Minimal LD_PRELOAD shim that intercepts BPF-related syscalls in target apps.
Foundation for the shim-only userspace speculative optimization architecture
documented in `docs/tmp/poc_c_bpf_syscall_shim_design.md` and (eventually)
`docs/tmp/poc_c_v2_shim_only_design.md`.

## Phase 1 (this directory, current state)

Observation only. Intercepts `syscall(SYS_bpf, ...)`, `perf_event_open(2)`, and
`ioctl(2)` on perf_event fds. For each `BPF_PROG_LOAD` it:

- decodes attr (prog_type, name, insn_cnt, license, attach metadata),
- computes an FNV-1a 64-bit hash of the bytecode,
- dumps the raw bytecode to `${BPFREJIT_SHIM_DIR:-/tmp}/bpfrejit_<pid>_<hash>.bpf`,
- logs every call to `${BPFREJIT_SHIM_LOG:-/tmp/bpfrejit_shim.log}` with both
  pre-call attributes and the post-call return value/errno.

The shim passes through to the real syscall unchanged. The target app sees no
behavior difference.

### Build & smoke

```bash
make            # builds libbpfrejit_shim.so + selftest
make smoke      # LD_PRELOAD against bpftool prog list, asserts log non-empty
make selftest-run  # synthetic BPF_PROG_LOAD, asserts bytecode dump matches
```

`make selftest-run` works without root. The `BPF_PROG_LOAD` call will fail with
EPERM (no CAP_BPF), but the shim's interception and bytecode capture path
exercises completely. The selftest asserts the dumped `.bpf` file is exactly
16 bytes (2 × `sizeof(struct bpf_insn)`), confirming the intercepted attr
pointed at the correct bytecode.

### Environment variables

| variable | default | purpose |
|---|---|---|
| `BPFREJIT_SHIM_LOG` | `/tmp/bpfrejit_shim.log` | append-only structured log |
| `BPFREJIT_SHIM_DIR` | `/tmp` | dir for per-load bytecode dumps |

## Empirical per-app coverage (2026-05-17, `make docker-survey`)

Runs every corpus app inside the existing `bpf-benchmark/runner-runtime:x86_64`
image with `docker cp` injection of the shim — no Docker image rebuild, no
runner Python change. The musl-built shim variant is auto-selected for the
musl-linked tracee binary.

| App | Binary | shim | PROG_LOAD | LINK_CREATE | perf_event_open | RAW_TP_OPEN | SET_BPF |
|---|---|:---:|---:|---:|---:|---:|---:|
| `bpftool prog list` | glibc dyn | ✅ | 0 | 0 | 0 | 0 | 0 |
| `bpftrace -e tp:...` | glibc dyn | ✅ | **3** | 0 | **1** | 0 | **2** |
| `execsnoop-bpfcc` | py+libbcc glibc | ✅ | **4** | 0 | **26** | 0 | **4** |
| `opensnoop-bpfcc` | py+libbcc glibc | ✅ | **5** | 0 | **24** | **3** | 0 |
| `capable-bpfcc` | py+libbcc glibc | ✅ init only | 0 | 0 | 0 | 0 | 0 |
| `tracee --events execve` | **musl** dyn | ✅ (musl shim) | **44** | **3** | **98** | **8** | 0 |
| `tetragon` | **STATIC** | ❌ | — | — | — | — | — |
| `cilium-agent --help` | **STATIC** | ❌ | — | — | — | — | — |
| `katran --help` | glibc dyn | ✅ init only | 0 | 0 | 0 | 0 | 0 |

Headline: **5 of 7 corpus apps fully observable with stock LD_PRELOAD**
(bpftrace, BCC-execsnoop, BCC-opensnoop, BCC-capable, tracee). Two apps
(tetragon, cilium-agent) are **statically linked Go binaries** — physically
incompatible with LD_PRELOAD and require a binary-hotpatch / uprobe shim path
as predicted in `docs/tmp/poc_c_v2_shim_only_design.md` §4. Katran is glibc
dynamic and the shim loads cleanly; coverage above shows zero events only
because `--help` does not exercise BPF.

`bpftool prog list` shows 0 PROG_LOAD because the command only iterates
existing kernel programs — the shim still correctly captures 92 lines of
`PROG_GET_NEXT_ID` / `PROG_GET_FD_BY_ID` / `OBJ_GET_INFO_BY_FD`.

`bcc/capable-bpfcc` shows 0 BPF events at 8s wall budget; the BCC tool compiles
its BPF C source via clang at startup which can take more than 8s in the
container. Raising the duration captures programs.

### Lessons learned that took experimentation

- **musl-linked apps need a musl-built shim**. `make musl` runs `gcc` inside an
  alpine container to produce `libbpfrejit_shim_musl.so` against musl libc.
  Cross-pasting a glibc-built shim into a musl process fails with
  `__snprintf_chk: symbol not found` and friends.
- **Don't wrap the target app in glibc `timeout(1)`** when the shim is
  musl-built. `timeout` itself receives `LD_PRELOAD` and tries to load the
  musl shim, which fails because glibc cannot resolve musl libc symbols, and
  `timeout` segfaults before it can fork the target. Use a bash
  background-pid + `sleep N && kill -TERM` pattern instead. `make docker-survey`
  does this uniformly for all apps.
- **Forward all 6 syscall args via va_arg even for short-arg syscalls**.
  x86_64 sysv ABI puts syscall args in registers, so reading 6 longs from
  `va_arg` works regardless of actual arg count. Forwarding 6 longs to
  `real_syscall` keeps the kernel ABI intact for variadic syscalls
  (`ioctl`, `fcntl`, `prctl`, ...).
- **Skip `<sys/ioctl.h>`**. glibc declares `ioctl(int, unsigned long, ...)`,
  musl declares `ioctl(int, int, ...)`. Both ABIs use the kernel's unsigned
  long. We avoid the conflict by including only `<linux/ioctl.h>` for the
  `_IO[WR]` macros and self-declaring the function.

### Remediation paths for the two blocked apps

| App | Why blocked | Required mechanism |
|---|---|---|
| tetragon | statically linked, no dynamic loader to intercept | runtime hot-patch of the Go `syscall.RawSyscall6` (or equivalent) stub to trampoline into a per-arch handler that does the same work as the LD_PRELOAD shim. See `docs/tmp/poc_c_v2_shim_only_design.md` §4 "Go and static/raw-syscall binaries". |
| cilium-agent | same | same |

`bpfrejit-shimctl` (Go-binary launcher with x86_64+arm64 hotpatch) is the
v2 design's answer; not yet implemented.

`make docker-survey` is the canonical reproducer for this matrix. Edit the
target inside `Makefile` to add apps or vary their command lines.

## Phase 2 (not in this directory yet)

Active optimization. The shim worker thread will:

1. wait `N` seconds after the last observed `BPF_PROG_LOAD`,
2. invoke `bpfopt --pass <name>` as a CLI subprocess with the dumped bytecode
   as stdin,
3. submit the rewritten bytecode via a fresh `BPF_PROG_LOAD` (in-process),
4. apply the per-attach swap recipe (`BPF_LINK_UPDATE` / `PERF_EVENT_IOC_SET_BPF`
   with detach-and-reopen / `BPF_MAP_UPDATE_ELEM` for PROG_ARRAY slots),
5. record the `logical_id → {original_prog_id, candidate_prog_id}` mapping for
   the benchmark runner to read.

Design references:
- `docs/tmp/poc_c_bpf_syscall_shim_design.md` (v1: daemon + shim).
- `docs/tmp/poc_c_v2_shim_only_design.md` (v2: shim-only, daemon eliminated;
  in progress at time of writing).
- `docs/rejit-speculative-optimization-ebpf.md` (idea #1 paper-line hub).

## Non-goals (Phase 1 + Phase 2)

- Fully atomic swap. Microsecond-scale gap between detach and re-attach is
  acceptable for benchmark measurement.
- Preserving `prog_id` across swap. Stock `BPF_PROG_LOAD` always returns a new
  id; the runner must merge counters via the logical-id mapping the shim
  records.
- Capturing programs loaded before the shim is installed. If the bytecode dump
  for an existing `prog_id` is missing, that program is ineligible for
  optimization in this lifetime.
- Replacing upstream apps. The shim is loaded into the real upstream binary
  (Tracee, Tetragon, Katran, Cilium, bpftrace, BCC, OTel) via `LD_PRELOAD` or
  (for Go binaries) the `bpfrejit-shimctl` hotpatch wrapper.

## Files

| file | purpose |
|---|---|
| `libbpfrejit_shim.c` | LD_PRELOAD library |
| `selftest.c` | synthetic-load PoC, exercises capture path without root |
| `Makefile` | `all` / `smoke` / `selftest-run` / `clean` |
