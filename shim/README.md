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
runner Python change.

| App | Binary type | shim loaded? | BPF events captured |
|---|---|:---:|---|
| `bpftool prog list` | glibc dynamic | ✅ | 92 lines: `PROG_GET_NEXT_ID` / `PROG_GET_FD_BY_ID` / `OBJ_GET_INFO_BY_FD` iteration |
| **`bpftrace -e tp:syscalls:sys_enter_openat`** | glibc dynamic | ✅ | **3 PROG_LOAD + 1 perf_event_open + 2 PERF_EVENT_IOC_SET_BPF** |
| **`execsnoop-bpfcc`** | python + libbcc (glibc) | ✅ | **4 PROG_LOAD + 26 perf_event_open + 4 SET_BPF** |
| **`opensnoop-bpfcc`** | python + libbcc (glibc) | ✅ | **5 PROG_LOAD + 24 perf_event_open + 3 RAW_TRACEPOINT_OPEN** |
| `capable-bpfcc` | python + libbcc (glibc) | ✅ (init only) | 0 BPF events — `timeout 3s` too short for clang compile + attach |
| `katran_server_grpc --help` | glibc dynamic | ✅ (init only) | 0 — `--help` does not exercise BPF; needs real workload |
| **`tracee --help`** | **musl** dynamic | ❌ | `Error loading shared library ld-linux-x86-64.so.2 ... __snprintf_chk: symbol not found` — glibc-built shim incompatible with musl interpreter |
| **`tetragon`** | **statically linked** | ❌ | LD_PRELOAD has no dynamic loader to hook |
| **`cilium-agent --help`** | **statically linked** | ❌ | LD_PRELOAD has no dynamic loader to hook |

Verification of binary types confirms PoC-C v2 §4's per-app prediction (see
`docs/tmp/poc_c_v2_shim_only_design.md` §4 "Injection mechanism per
loader-language"). Static linking on tetragon/cilium and musl-linking on tracee
are structural blockers for plain LD_PRELOAD.

### Remediation paths

| Issue | Apps | Fix |
|---|---|---|
| musl interpreter | tracee | Build a second shim variant against musl (`musl-gcc`) and select it at launch time. Tracee container has musl available; the runner can pick `libbpfrejit_shim_musl.so` for tracee. |
| Statically linked | tetragon, cilium-agent | Binary hotpatch / uprobe shim path per PoC-C v2 §4 "Go and static/raw-syscall binaries". Cannot be fixed by any LD_PRELOAD-only mechanism. |

`make docker-survey` is the canonical reproducer for this matrix. Edit the
target inside `Makefile` to add new apps or vary their command lines.

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
