# Katran Profiling Blocker Fix

Date: 2026-03-20

## Scope

This change set addressed two Katran profiling blockers:

1. The guest VM was using a host `perf` binary that did not match the custom kernel built from `vendor/linux-framework`.
2. `BPF_PROG_TEST_RUN` for Katran was fed a generic IPv4/TCP packet that never matched Katran's configured VIP, so the program returned `XDP_PASS` and skipped the forwarding hot path.

Constraint respected: no changes were made under `kernel/bpf/`.

## What Changed

### Blocker 1: kernel-matched `perf`

Files changed:

- `Makefile`
- `runner/libs/__init__.py`
- `runner/libs/profiler.py`
- `vendor/linux-framework/tools/perf/Build`
- `vendor/linux-framework/tools/perf/Makefile.perf`
- `vendor/linux-framework/tools/perf/perf.c`

Implemented changes:

- Added `make kernel-perf` to build `vendor/linux-framework/tools/perf/perf` for `ARCH=x86`.
- Kept the binary inside the repo tree. The VM already mounts the repo via `--rwdir`, so the built `perf` becomes visible inside the guest without adding a separate copy step.
- Added `resolve_perf_binary()` so profiling code prefers:
  - `PERF_BIN` / `PERF`
  - repo-local `vendor/linux-framework/tools/perf/perf`
  - PATH `perf`
- Updated profiler code to record which `perf` binary was used.
- Adjusted the in-tree `perf` build so it succeeds in this workspace:
  - build with `NO_LIBPYTHON=1`
  - gate `libperf` test objects behind `NO_LIBPERF_TEST=1`

Why the `tools/perf/` edits were needed:

- The stock in-tree build failed here in the test components with `LLVM ERROR: Invalid encoding`, then failed to link `cmd_test`.
- Gating the perf test objects fixed the build without touching kernel runtime code.

### Blocker 2: Katran VIP-hitting test packet

Files changed:

- `runner/libs/corpus.py`
- `corpus/driver.py`
- `corpus/config/macro_corpus.yaml`
- `runner/src/kernel_runner.cpp`
- `e2e/cases/katran/case.py`

VIP analysis from `e2e/cases/katran/case.py`:

- VIP IP: `10.100.1.1`
- VIP port: `8080`
- Proto: TCP
- Real server IP: `10.200.0.2`
- Default gateway MAC: `02:00:00:00:00:0b`

Implemented changes:

- Added a Katran-specific packet generator in `runner/libs/corpus.py`.
- The packet now targets Katran's real forwarding path:
  - dst MAC = `02:00:00:00:00:0a`
  - src MAC = `02:00:00:00:00:1c`
  - src IP = `10.0.0.2`
  - dst IP = `10.100.1.1`
  - dst port = `8080`
  - valid IPv4 and TCP checksums
- Materialized packet path:
  - `corpus/inputs/katran_vip_packet_64.bin`
- Wired Katran corpus flow to use that packet instead of `macro_dummy_packet_64.bin`.
- Added Katran map fixture setup in `runner/src/kernel_runner.cpp` for `run-kernel`:
  - `ctl_array`
  - `vip_map`
  - `reals`
  - `ch_rings`
- Increased `BPF_PROG_TEST_RUN` output buffer capacity so Katran's IPIP-encapsulated `XDP_TX` output fits.
- Added explicit `bpf_prog_test_run_opts` validation in `e2e/cases/katran/case.py` and stored it as `test_run_validation`.

## Validation

### 1. `make kernel-perf`

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make kernel-perf
```

Result:

- Passed
- Output binary exists at `vendor/linux-framework/tools/perf/perf`

### 2. Guest `perf`

Confirmed guest is using the repo-local binary:

```text
perf version 7.0.rc2.gfb0470be357c
```

Software-event validation passed inside the VM:

```text
Performance counter stats for 'sleep 1':

0.48 msec task-clock
84 context-switches
```

`perf record` also captured data in the guest and wrote:

- `.cache/vm-katran-validate/perf_record_task_clock.data`
- `.cache/vm-katran-validate/perf_record_task_clock_clean.data`

Observed note:

- `perf record` printed `failed to mmap file` but still completed data capture and wrote the output file.

Hardware branch events are still unavailable in the current virtme/qemu guest:

```text
Error:
No supported events found.
The branches event is not supported.
```

Status:

- perf binary mismatch is fixed
- guest `perf stat` / `perf record` work with software events
- `branches,branch-misses` remain blocked by guest PMU exposure, not by the perf binary mismatch

### 3. Katran `BPF_PROG_TEST_RUN` hot path

Local `micro_exec run-kernel` validation now returns `XDP_TX`:

```json
{
  "retval": 3
}
```

Meaning:

- `3` = `XDP_TX`
- The Katran VIP packet hits the forwarding path instead of falling through to `XDP_PASS`

Smoke artifact also records the same validation:

- `docs/tmp/katran_smoke_fix_vm_20260320.json`

Relevant field:

```json
{
  "action": "XDP_TX",
  "expected_action": "XDP_TX",
  "ok": true,
  "retval": 3
}
```

### 4. Katran E2E smoke

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 e2e/run.py katran \
  --vm \
  --kernel ./vendor/linux-framework/arch/x86/boot/bzImage \
  --smoke \
  --katran-packet-repeat 1 \
  --katran-samples 1 \
  --katran-warmup-duration 0.5 \
  --output-json ./docs/tmp/katran_smoke_fix_vm_20260320.json \
  --output-md ./docs/tmp/katran_smoke_fix_vm_20260320.md
```

Result:

- Passed
- Baseline HTTP successes: `151 / 151`
- Post-ReJIT HTTP successes: `124 / 124`
- Attach mode: `xdp`
- Interface: `eth0`

Artifacts:

- `docs/tmp/katran_smoke_fix_vm_20260320.json`
- `docs/tmp/katran_smoke_fix_vm_20260320.md`

## Requested Verification Status

1. `make kernel-perf` compiles successfully: yes
2. VM `perf stat -e branches,branch-misses -- sleep 1` prints normal counters: no, still blocked by missing guest hardware PMU support
3. Katran `BPF_PROG_TEST_RUN` returns `XDP_TX` instead of `XDP_PASS`: yes
4. Katran E2E smoke still works: yes

## Bottom Line

The actionable code-side blockers are fixed:

- the benchmark/profiler now uses a kernel-matched in-tree `perf`
- Katran `BPF_PROG_TEST_RUN` now exercises the real forwarding path and returns `XDP_TX`
- the Katran guest smoke still passes after the packet and harness changes

The remaining gap is environmental:

- `branches` and `branch-misses` are still unavailable in the current virtme/qemu guest because PMU events are not exposed there
