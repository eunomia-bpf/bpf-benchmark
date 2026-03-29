# Tracee E2E Enhancement Report (2026-03-28)

## Goal

Bring `e2e/cases/tracee/case.py` up from a single-shot demonstration benchmark to a Katran-grade E2E methodology:

- real workload generators
- same-image paired baseline vs post-ReJIT comparison
- workload-level correctness gates
- repeated cycles with warmup
- application throughput, event throughput, event detection latency, and application overhead
- CI + paired significance reporting

## 1. Katran Methodology Baseline

`e2e/cases/katran/case.py` is the current publication-grade reference in this repository.

Key properties:

- Real traffic generator: `wrk` when available, otherwise an explicit Python parallel HTTP client.
- Real application metrics: request throughput (`req/s`), request latency (`p50/p90/p99`), packet rate, system CPU, BPF runtime.
- Warmup before every timed phase:
  - warmup duration defaults to 2s
  - warmup has retry logic to tolerate topology/ARP settling
- Same-image paired comparison:
  - each cycle loads Katran once
  - runs `baseline`
  - applies ReJIT
  - runs `post_rejit`
- Multiple paired cycles:
  - default `sample_count = 3`
  - aggregate summaries are built from all cycle samples
- Correctness gating:
  - request count must be non-zero
  - success rate must stay above threshold
  - packet-path counters and BPF runtime counters must move

This is the core methodology I mirrored for Tracee.

## 2. Tracee Before This Change

Previous `e2e/cases/tracee/case.py` had several methodological gaps:

- Single lifecycle only: one `baseline` and one `post_rejit`, no repeated paired cycles.
- No no-Tracee control phase, so it could not quantify true application slowdown.
- No event detection latency metric.
- No warmup period per measured workload phase.
- No confidence intervals or significance test.
- `preflight` / `require_program_activity` were optional and disabled by default, so invalid BPF runtime measurements could still look “successful”.
- The old `file_io` workload mostly measured storage throughput, not high-rate file security events.
- Output markdown only printed point estimates from one run.

The old authoritative result also showed a serious validity issue: `bpf_avg_ns_per_run = None`, which means the selected target-program runtime path was not actually being measured.

## 3. New Tracee Methodology

### 3.1 Measurement structure

Tracee now runs as:

1. `control`
2. `baseline`
3. apply ReJIT
4. `post_rejit`

within each outer paired cycle.

The `baseline -> post_rejit` pair remains same-image. The new `control` phase runs without Tracee so we can compute actual application overhead.

### 3.2 Repeated cycles

Default configuration now uses:

- `sample_count: 5`
- `smoke_sample_count: 2`

This is intentionally stronger than the old single-shot Tracee path and at least matches the “3-5 rounds” requirement.

### 3.3 Warmup

Every workload phase now has per-workload warmup:

- default `warmup_duration_s: 4`
- smoke `warmup_duration_s: 2`

Warmup happens before the timed measurement and before latency probes are excluded from timed throughput.

### 3.4 Workloads

The workload set is now aligned with Tracee’s observability semantics:

- `exec_storm`
  - workload kind: `exec_storm`
  - app metric: `execs/s`
  - primary events: `execve`, `sched_process_exec`
- `file_io`
  - workload kind changed to `file_open`
  - app metric: `opens/s`
  - primary event: `security_file_open`
  - this replaces the old storage-centric `fio randread` interpretation
- `network`
  - workload kind remains `network`
  - app metric reported as `connects/s`
  - primary event: `security_socket_connect`

### 3.5 Latency probes

For each instrumented phase and workload, Tracee now runs marker probes before the timed run:

- `exec`: execute a uniquely named temporary file
- `file_open`: open a uniquely named temporary file
- `tcp_connect`: connect to a unique loopback port

The Tracee collector waits for the matching JSON event line and records end-to-end marker-to-detection latency.

Default configuration:

- `latency_probe_count: 8`
- `smoke_latency_probe_count: 3`
- `latency_probe_timeout_s: 5`

### 3.6 Correctness gates

Timed instrumented phases now fail loudly if:

- primary Tracee event count is zero
- Tracee reports lost events or lost writes
- selected BPF programs report zero runtime events
- latency probes are not detected

This is the Tracee analogue of Katran’s “all HTTP requests must succeed” gate.

### 3.7 Statistics

Tracee now computes:

- per-workload sample distributions
- mean / median / min / max / stdev / p95 / p99
- bootstrap mean CI (`95%`, default `2000` iterations, seed `20260328`)
- paired significance test:
  - exact paired permutation test on signed deltas

Paired comparison is reported for:

- application throughput
- primary event throughput
- detection latency p99
- application overhead percent
- agent CPU percent
- BPF avg ns/run
- lost event count

## 4. Implementation Summary

Files changed:

- `e2e/cases/tracee/case.py`
- `e2e/cases/tracee/config.yaml`
- `runner/libs/workload.py`

Main code changes:

- extended `TraceeOutputCollector` with recent-event storage and a blocking `wait_for_event()` API
- added bootstrap CI and paired significance helpers
- added marker-probe emitters for exec / file-open / tcp-connect
- changed phase execution from single-shot to repeated paired cycles with a new control phase
- added aggregated phase summaries (`control`, `baseline`, `post_rejit`) plus `paired_cycles`
- moved workload-level overhead computation to explicit control-phase annotation after each measured phase
- switched Tracee’s default file workload from generic file I/O to file-open churn
- switched Tracee’s `exec_storm` path from a fragile `stress-ng --exec` fallback chain to an explicit execve loop generator
- turned Tracee’s default methodology into `require_program_activity: true`
- changed markdown output from one-run point estimates to workload-level summaries and paired deltas

## 5. Config Changes

New default config in `e2e/cases/tracee/config.yaml`:

- `require_program_activity: true`
- `preflight_duration_s: 5`
- `measurement_duration_s: 20`
- `sample_count: 5`
- `warmup_duration_s: 4`
- `latency_probe_count: 8`
- workload-level `primary_events`
- workload-level `latency_probe_kind`
- `statistics.bootstrap_iterations: 2000`

This makes Tracee much slower to run than before, but it materially improves validity.

## 6. Validation

Validation command:

```bash
make vm-e2e TARGET=x86 E2E_CASE=tracee
```

Host-side checks completed:

```bash
python3 -m py_compile e2e/cases/tracee/case.py
python3 -m py_compile runner/libs/workload.py
```

Additional host-side sanity check passed:

- `run_phase(..., phase_name="control")` produced the expected three workload rows (`exec_storm`, `file_io`, `network`) with non-zero application throughput.

Validation chronology:

1. `make vm-e2e TARGET=x86 E2E_CASE=tracee` was launched first.
2. That run failed before Tracee case execution because virtme hostfs modules no longer matched the booted kernel image.
3. Root cause was confirmed with `runner/scripts/vng-wrapper.sh --verbose ... --exec ...`:
   - guest boot reached virtme initramfs
   - hostfs modules (`netfs.ko`, `9p*.ko`, `virtiofs.ko`, `overlay.ko`) failed to load
   - failure mode was hostfs-module / kernel mismatch (`module_layout` disagreement / invalid module format)
   - root mount then failed, ending in kernel panic before the guest command ran
4. A serial `make virtme-hostfs-modules TARGET=x86` rebuild temporarily repaired the VM backend.
5. After that rebuild, a minimal guest probe succeeded:

```bash
python3 runner/scripts/run_vm_shell.py \
  --action vm-e2e --target x86 \
  --kernel-image vendor/linux-framework/arch/x86/boot/bzImage \
  --timeout 600 \
  --command 'echo hello-from-guest'
```

6. The repaired backend then surfaced two real Tracee smoke issues, both fixed in this change set:
   - `exec_storm` fell back from `stress-ng --exec` to `rapid exec loop`, which now fails closed instead of silently degrading; Tracee was changed to use an explicit first-class exec loop generator.
   - control/baseline overhead coupling was too eager; overhead is now attached after phase measurement instead of during the measurement loop.
7. Full VM validation could not be completed in this shared workspace because concurrent external tasks kept rebuilding the kernel tree after the repair. During this report run the booted kernel advanced to `#25`, while `.virtme_mods` still contained modules built for an earlier image, reintroducing the same hostfs mismatch and causing subsequent VM launches to fail before guest command execution.

Current validation status:

- Tracee methodology/code changes are implemented and pass local syntax checks.
- VM backend health was restored once and verified with a successful minimal guest boot.
- Tracee smoke validation reached real case logic and exposed two implementation bugs, both fixed.
- Final `make vm-e2e TARGET=x86 E2E_CASE=tracee` completion is still blocked by concurrent kernel rebuild churn in the shared workspace, not by a remaining Tracee case exception.

Deterministic next step once the workspace is idle:

```bash
make virtme-hostfs-modules TARGET=x86
make vm-e2e TARGET=x86 E2E_CASE=tracee
```

## 7. Remaining Risk

The remaining risk is now mostly environmental, not methodological:

- As long as other tasks in this shared workspace keep rebuilding `vendor/linux-framework`, `bzImage` can advance independently of `.virtme_mods`, and any virtme-based validation may fail before Tracee starts.

The main case-local integration risk after the VM backend is stable is still marker matching against real Tracee JSON payload shape:

- exec probe path must appear in the emitted event payload
- file-open probe path must appear in the emitted event payload
- tcp-connect probe port must appear in the emitted event payload

If any of those assumptions are wrong in the guest run, the fix should be localized to the probe token matching logic in `TraceeOutputCollector.wait_for_event()` and the corresponding probe emitters.
