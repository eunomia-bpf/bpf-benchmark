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

## Empirical per-app coverage

| App | Binary | Result |
|---|---|---|
| `bpftrace` | glibc dyn | ✅ Captured |
| `bcc/*-bpfcc` | py+libbcc glibc | ✅ Captured |
| `tracee` | **musl** dyn | ✅ Captured (use `libbpfrejit_shim_musl.so`) |
| `katran` | glibc dyn | ✅ Shim loads (needs real workload to exercise BPF) |
| `tetragon` | **static** Go | ❌ LD_PRELOAD impossible; see PoC-E vendor-replace |
| `cilium-agent` | **static** Go | ❌ same |

**5 of 7 corpus apps reachable via stock LD_PRELOAD**. The 2 static Go
binaries need the vendor-replace path documented in
`docs/tmp/poc_e_vendor_replace_x_sys_design.md`.

### Lessons learned

- **musl-linked apps need a musl-built shim**. `make musl` builds it inside
  an alpine container. Glibc shim into musl app fails with
  `__snprintf_chk: symbol not found`.
- **Don't wrap musl-target apps in glibc `timeout(1)`**. `timeout` itself
  inherits `LD_PRELOAD`, fails to load the musl shim, and segfaults before
  forking the target. Use bash background-pid + `sleep N && kill -TERM`.
- **Forward all 6 syscall args via `va_arg`** even for short-arg syscalls.
  x86_64 sysv ABI puts syscall args in registers, so reading 6 longs always
  works.
- **Skip `<sys/ioctl.h>`** — glibc and musl have conflicting signatures.
  Include only `<linux/ioctl.h>` for IOC macros and self-declare the function.

## Phase 2 (active — app-level shim socket, runner-driven)

The shim is a **dumb shell executor** for BPF apps launched under
`LD_PRELOAD`:

- the **runner** parses `runner/config/passes/<pass>/default.yaml` and ships
  pass steps to the shim over the socket
- the **shim** substitutes shim-owned vars (`${INPUT}`, `${OUTPUT}`,
  `${REPORT}`, `${PROG_ID}`, `${PROG_TYPE}`, `${WORKDIR}`, `${TARGET}`) and
  runs `/bin/sh -c <command>` with `LD_PRELOAD` stripped from the subprocess
  env (so bpfopt is not itself shimmed)

The shim ships **no** auto-tick / hardcoded pass logic. Optimization is
runner-driven over the socket; the shim is responsible only for interception
+ state tracking + executing whatever shell command the runner sends.

### Socket — app-level plan

Each shim instance binds a per-pid unix socket:

```
${BPFREJIT_SHIM_SOCK_DIR:-/var/run/bpfrejit}/shim-<pid>.sock
```

Line-delimited JSON. Commands:

```json
// list_progs — enumerate all tracked BPF programs
{"cmd": "list_progs"}
// → {"ok": true, "progs": [{"id": <kernel_prog_id>, "name": "...",
//                            "type": <prog_type>, "insn_cnt": ...,
//                            "hash": "...", "bytecode_path": "..."}]}

// execute_plan — run runner-supplied pass steps against every tracked prog
{"cmd": "execute_plan",
 "steps": [{"name": "noop",
            "command": "bpfopt --pass noop --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE} --target ${TARGET}",
            "log_level": 1}]}
// → {"status": "ok", "per_program": {"4669": {"status": "ok", "passes": [...]}}}

// dump_state — write state JSON to disk and return path
{"cmd": "dump_state"}
// → {"ok": true, "path": "/tmp/dumps/state_<pid>.json"}
```

The runner is expected to enumerate `${BPFREJIT_SHIM_SOCK_DIR}/shim-*.sock`
or use a small `bpfrejit-router` process at the existing daemon path
`/var/tmp/bpfrejit-daemon.sock` that routes by `app_pid` (see
`docs/tmp/poc_c_v2_shim_only_design.md` §6 / Socket Plan A). Routing is out
of scope for this directory.

### What Phase 2 in this directory does NOT yet do

- Submit a candidate `BPF_PROG_LOAD` with rewritten bytecode (the bpfopt
  output exists on disk but is not re-loaded into the kernel).
- Apply per-attach swap recipes (`BPF_LINK_UPDATE`,
  `PERF_EVENT_IOC_SET_BPF` with detach-and-reopen, `BPF_MAP_UPDATE_ELEM` for
  PROG_ARRAY).
- Emit `.swaps.jsonl` swap log mapping `logical_id ↔ {old, new}` prog ids.
- Cover static Go binaries (tetragon, cilium-agent, otel-profiler). See
  `docs/tmp/poc_e_vendor_replace_x_sys_design.md` for the planned
  vendor-replace path.

## Environment variables

| variable | default | purpose |
|---|---|---|
| `BPFREJIT_SHIM_LOG` | `/tmp/bpfrejit_shim.log` | append-only structured log |
| `BPFREJIT_SHIM_DIR` | `/tmp` | dir for per-load bytecode dumps + workdirs |
| `BPFREJIT_TARGET` | `x86` | substituted as `${TARGET}` in runner commands |
| `BPFREJIT_SHIM_PERIODIC_DUMP_MS` | `0` | periodic state JSON dump (0=off) |
| `BPFREJIT_SHIM_SOCK_DIR` | `/var/run/bpfrejit` | per-pid socket dir |
| `BPFREJIT_SHIM_SOCK_DISABLE` | (unset) | set to `1` to disable socket server |

Design references:
- `docs/tmp/poc_c_bpf_syscall_shim_design.md` (v1: daemon + shim).
- `docs/tmp/poc_c_v2_shim_only_design.md` (v2: shim-only, daemon eliminated).
- `docs/tmp/poc_e_vendor_replace_x_sys_design.md` (Tier 4: static Go).
- `docs/rejit-speculative-optimization-ebpf_idea.md` (idea #1 paper-line hub).

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
  (for Go binaries) the planned vendor-replace path.

## Files

| file | purpose |
|---|---|
| `libbpfrejit_shim.c` | LD_PRELOAD library (intercept + state + execute_plan socket) |
| `selftest.c` | synthetic-load PoC, exercises capture path without root |
| `Makefile` | `all` / `musl` / `smoke` / `selftest-run` |
