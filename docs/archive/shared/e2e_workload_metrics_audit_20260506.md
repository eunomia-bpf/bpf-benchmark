# E2E Workload Metrics Audit 20260506

## Scope

Audit target: current `HEAD` is `0d5c5f87` (`refactor: unify timeout handling and improve workdir retention in benchmarks`).

Result: the current checkout has no `e2e/` directory, no `e2e/driver.py`, no `e2e/cases/`, no `e2e/results/`, no `runner/suites/e2e.py`, and no Makefile or `runner.libs.run_target_suite` e2e dispatch path. The e2e suite was removed by `f591080b` (`Remove e2e benchmark results and related scripts`), which deleted `e2e/driver.py`, all `e2e/cases/*`, all tracked `e2e/results/*`, and `runner/suites/e2e.py`.

The tables below separate current behavior from the last pre-removal implementation (`f591080b^`). Current behavior is authoritative for this checkout.

## Current E2E Cases

There are no current e2e cases under `e2e/cases/`.

| case name | workload generator | metrics captured | where they land in `result.json` | baseline vs post_rejit comparison |
| --- | --- | --- | --- | --- |
| none | n/a | none | n/a: `e2e/driver.py` and `e2e/results/` do not exist | none |

Current dispatch evidence:

- `find e2e ...` returns `find: 'e2e': No such file or directory`.
- `runner/suites/` contains only `_common.py`, `corpus.py`, `micro.py`, and `test.py`.
- `runner/libs/run_target_suite.py` allows benchmark suites `micro` and `corpus` only.
- `Makefile` has `test`, `micro`, `corpus`, and `all`; no `e2e` target.

## Last Pre-Removal E2E Implementation

For provenance only, the last deleted `e2e/driver.py` (`f591080b^`) had `CASE_SPECS` for `tracee`, `tetragon`, `bpftrace`, `bcc`, and driver-only simple cases for `katran`, `cilium`, and `otel`. The only actual `e2e/cases/*/case.py` modules left at that point were `tracee`, `tetragon`, `bpftrace`, and `bcc`.

| case name | workload generator | metrics captured | where they landed in `result.json` | baseline vs post_rejit comparison |
| --- | --- | --- | --- | --- |
| `tracee` | `stress-ng` class workload from `TRACEE_E2E_WORKLOADS`; at `f591080b^` this was only `stress_ng_os` | app throughput as `app_throughput` in `ops/s`; per-program BPF counter deltas | `.baseline.measurement.records[].app_throughput`, `.baseline.measurement.records[].bpf`, `.post_rejit.measurement.records[].app_throughput`, `.post_rejit.measurement.records[].bpf` | raw per-phase values only; no app-throughput delta computed in the case payload |
| `tetragon` | `stress-ng` class workload from `TETRAGON_E2E_WORKLOADS`; at `f591080b^` this was `stress_ng_os_io_network` | throughput as `throughput` in `ops/s`; per-program BPF counter deltas | `.baseline.measurement.records[].throughput`, `.baseline.measurement.records[].bpf`, `.post_rejit.measurement.records[].throughput`, `.post_rejit.measurement.records[].bpf` | raw per-phase values only; no delta |
| `bpftrace` | per-script workload specs: stress-ng classes and `fio` via `run_named_workload()` / `run_file_io()` | throughput as `throughput` in `ops/s`; per-program BPF counter deltas; bpftrace process output | `.records[].baseline.measurement.throughput`, `.records[].baseline.measurement.bpf`, `.records[].post_rejit.measurement.throughput`, `.records[].post_rejit.measurement.bpf` | raw per-phase values only; no delta |
| `bcc` | per-tool workload specs: stress-ng classes and `fio` via `run_named_workload()` / `run_file_io()` | throughput as `throughput` in `ops/s`; per-program BPF counter deltas; tool process output | `.records[].baseline.measurement.throughput`, `.records[].baseline.measurement.bpf`, `.records[].post_rejit.measurement.throughput`, `.records[].post_rejit.measurement.bpf` | raw per-phase values only; no delta |
| `katran` (driver-only simple case, not under `e2e/cases/`) | Katran runner's Python parallel network client in the old `network` workload | throughput as `throughput` in `ops/s`; BPF deltas. The runner produced `latency_ms` internally, but the simple e2e wrapper did not persist that structured latency field in `measurement` | `.baseline.measurement.throughput`, `.baseline.measurement.bpf`, `.post_rejit.measurement.throughput`, `.post_rejit.measurement.bpf` | raw per-phase values only; no delta in `result.json` |
| `cilium` (driver-only simple case, not under `e2e/cases/`) | old generic `network` workload, backed by `wrk` HTTP load in `runner.libs.workload` | throughput as `throughput` in `ops/s`; BPF deltas | `.baseline.measurement.throughput`, `.baseline.measurement.bpf`, `.post_rejit.measurement.throughput`, `.post_rejit.measurement.bpf` | raw per-phase values only; no delta |
| `otel` (driver-only simple case, not under `e2e/cases/`) | `stress_ng_cpu` through the native process runner | throughput as `throughput` in `ops/s`; BPF deltas | `.baseline.measurement.throughput`, `.baseline.measurement.bpf`, `.post_rejit.measurement.throughput`, `.post_rejit.measurement.bpf` | raw per-phase values only; no delta |

The older, richer Tracee E2E harness did exist before later simplification. Around `47f3295c`, `e2e/cases/tracee/case.py` included `exec_storm`, `file_io`, and `network` handling, latency probes, `app_throughput` distributions, paired metric reports, and p-values. That code path is no longer present in current `HEAD`.

## Schema Example

There is no current `e2e/results/` fragment to paste because the directory no longer exists. The latest deleted e2e result visible in `f591080b^` is `e2e/results/tracee_20260430_000402_865388/details/result.json`; a representative fragment was:

```json
{
  "status": "ok",
  "mode": "tracee_daemon_same_image_paired",
  "duration_s": 6,
  "sample_count": 2,
  "baseline": {
    "phase": "baseline",
    "status": "ok",
    "measurement": {
      "records": [
        {
          "cycle_index": 0,
          "name": "stress_ng_os",
          "kind": "stress_ng_os",
          "metric": "ops/s",
          "app_throughput": 3952.474860581925,
          "bpf_keys": ["100", "101", "102"]
        }
      ]
    }
  },
  "post_rejit": {
    "phase": "post_rejit",
    "status": "ok",
    "measurement": {
      "records": [
        {
          "cycle_index": 0,
          "name": "stress_ng_os",
          "kind": "stress_ng_os",
          "metric": "ops/s",
          "app_throughput": 4361.1273914542935,
          "bpf_keys": ["100", "101", "102"]
        }
      ]
    }
  }
}
```

That example is historical and deleted from the working tree. It shows raw per-phase app throughput plus BPF deltas, not a stored app speedup.

## Current Corpus Comparison

Current `corpus/driver.py` is the active macro benchmark path. It uses app runners and stores raw workload samples plus BPF deltas per phase in per-app detail files:

- `.baseline.workloads[]`: `ops_total`, `ops_per_sec`, `duration_s`, `stdout`, `stderr`
- `.baseline.bpf`: per-program `run_cnt_delta`, `run_time_ns_delta`, `id`, `name`, `type`, `bytes_jited`, `bytes_xlated`
- same shape under `.post_rejit`

The suite-level `corpus/results/.../details/result.json` does not copy every app result into a top-level array; per-app payloads are under `details/apps/<safe-name>.json`. Corpus does not compute app-level speedup. The raw `ops_per_sec` fields are workload-run diagnostics, not an e2e paper metric path.

## Verdict

Current e2e does not produce paper-quotable workload-side speedup numbers. Current e2e produces no result at all because the suite and result directory were removed.

The quoted historical Tracee numbers:

- `exec_storm +6.28%`
- `file_io +7.00%`
- `network +1.44%`

come from older March 2026 E2E artifacts and reports, not from current code. The relevant historical reports are `docs/tmp/20260318/benchmark_framework_analysis_20260318.md` and `docs/tmp/20260319/tracee_revert_rerun_20260319.md`; the latter explicitly identifies those as "old authoritative" numbers and compares later reruns against them. That older code measured application workload throughput and other agent metrics in `e2e/cases/tracee/case.py`, but that implementation was simplified, then the entire e2e tree was deleted by `f591080b`.

Current code still has generic workload helpers for stress-ng classes, `fio` file I/O, `wrk`-based network workloads, Cilium network matrix traffic, and Katran's XDP traffic client. However, without `e2e/driver.py` and `runner/suites/e2e.py`, those helpers are only reachable through corpus/app-runner measurements, not through an e2e result schema.

## Gaps

Current cases with no workload metric capture:

- All e2e cases: there are no current e2e cases.

Historical pre-removal cases with capture but no baseline-vs-postrejit comparison in `result.json`:

- `tracee`, `tetragon`, `bpftrace`, `bcc`, `katran`, `cilium`, and `otel` all stored raw per-phase workload throughput fields.
- The last pre-removal implementation did not store app-level percent delta, ratio, win/loss, or paper-rollup fields in `result.json`.

Fields specifically requested:

- `workload_metrics`: no live source hit.
- `workload_throughput`: no live source hit.
- `workload_latency`: no live source hit.
- `app_throughput`: no live source hit outside docs/history; deleted Tracee e2e used it.
- `latency_ms`: live source hit only inside Katran's Python traffic summary print in `runner/libs/app_runners/katran.py`; no current e2e driver writes it to an e2e result.

## What Would Need To Change

To surface workload-side metrics again without violating the framework's raw-data-only rule:

1. Reintroduce an e2e suite entrypoint: `runner/suites/e2e.py`, Makefile targets, and `runner.libs.run_target_suite` dispatch.
2. Reintroduce `e2e/driver.py` and case definitions or an e2e manifest that select app runners and workloads.
3. For each phase, write raw app workload measurements under stable per-phase keys, for example `.baseline.workload` and `.post_rejit.workload`, containing raw `WorkloadResult` fields and any structured tool details that are already measured.
4. For latency-capable workloads, carry structured raw latency data explicitly. For Katran, that means persisting the existing `last_request_summary` / `latency_ms` shape instead of only `ops_per_sec`.
5. Restore or replace old Tracee workload coverage if those paper claims matter: current live workload dispatch no longer has the old `exec_storm` Tracee E2E path, and current Tracee macro workload is `stress_ng_os_io_network`.
6. Keep app-level speedup, percent delta, ratios, confidence intervals, and rollups out of the framework result writer. Compute paper numbers in external analysis scripts from the raw `.baseline` and `.post_rejit` workload fields.

## Grep Double-Check

The final live-source grep for:

`exec_storm`, `file_io`, `workload_`, `throughput`, `requests_per_sec`, `latency_ms`, `workload_metrics`, `workload_throughput`, `workload_latency`, and `app_throughput`

found:

- no `e2e/` files, because there is no `e2e/` directory;
- no live `workload_metrics`, `workload_throughput`, `workload_latency`, or `app_throughput` result schema fields;
- `file_io` still exists as a `fio` workload helper;
- network workload helpers still exist for current corpus/app runners;
- Katran still prints a structured traffic summary containing `ops_per_sec` and `latency_ms`, but no current e2e result writer consumes it.
