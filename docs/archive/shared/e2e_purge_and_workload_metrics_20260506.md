# E2E Purge and Workload Metrics Audit - 2026-05-06

## E2E cleanup

Edited source/docs references to the removed e2e suite in:

- `CLAUDE.md`
- `README.md`
- `docs/benchmark-runtime-architecture.md`
- `docs/docker-build-cache-gc.md`
- `docs/bpfrejit-story.md`
- `docs/kernel-jit-optimization-plan.md`
- `docs/kernel-jit-optimization-plan-record-old.md`
- `docs/kernel-jit-optimization-plan-task-archive.md`
- `docs/paper/documents/eval-spec.md`
- `docs/paper/documents/draft-v0.md`
- `docs/paper/sections/6-evaluation.tex`
- `docs/paper/figures-next/tab-rq2-e2e.tex` renamed to `docs/paper/figures-next/tab-rq2-app-workloads.tex`

No Makefile, runner allowlist, config, or active Python e2e references were present after the earlier suite removal. `docs/tmp/`, `memory/`, and generated `corpus/results/` artifacts were not edited.

## Workload metric surfacing

Touched app/workload code:

- `runner/libs/workload.py`
  - Added `WorkloadResult.extra_fields` and merged those raw fields into `WorkloadResult.to_dict()`.
  - Surfaced structured stress-ng rows under `stressor_metrics`, plus raw stress-ng info counts when emitted.
  - Persisted raw fio JSON under `fio_json`.
  - Parsed raw wrk output into `request_count`, `bytes_total`, `requests_per_sec`, `bytes_per_sec`, `latency_ms`, `req_per_sec_thread`, and `socket_errors`.
  - Preserved raw UDP burst fields: `packet_count`, target host/port, and namespace.
  - Preserved Cilium `network_lossy_multi` components under `component_workloads`, including wrk and endpoint-matrix/UDP sub-workloads, plus raw `netem` settings.
- `runner/libs/app_runners/katran.py`
  - Added raw `error_count` to the parallel HTTP client summary.
  - Persisted Katran `last_request_summary` fields in workload JSON, including `request_count`, `success_count`, `error_count`, `bytes_total`, `latency_ms`, `failure_preview`, `concurrency`, and `driver`.
- `corpus/driver.py`
  - Writes `runner.run_workload(...).to_dict()` for each phase sample and merges non-colliding `runner.last_workload_details` fields.

Audited app runners:

- `tracee.py`, `tetragon.py`, `bcc.py`, `bcc_set.py`, `bpftrace.py`, `bpftrace_set.py`, `cilium.py`, `otel_profiler.py`, and `process_support.py` all route workload execution through the shared workload helpers, so their raw helper output now reaches `.baseline.workloads[]` and `.post_rejit.workloads[]`.
- Katran is runner-specific and was updated directly.

## Post-change workload fragment

Expected shape for a Katran `.baseline.workloads[N]` or `.post_rejit.workloads[N]` entry after the next corpus run:

```json
{
  "ops_total": 17799.0,
  "ops_per_sec": 5931.95,
  "duration_s": 3.0005,
  "stdout": "",
  "stderr": "",
  "driver": "python_parallel",
  "request_count": 17799,
  "success_count": 17799,
  "error_count": 0,
  "bytes_total": 284784,
  "latency_ms": {
    "count": 17799,
    "mean": 0.61,
    "median": 0.55,
    "min": 0.20,
    "max": 6.20,
    "p50": 0.55,
    "p90": 0.90,
    "p99": 1.80
  },
  "failure_preview": [],
  "concurrency": 4
}
```

Expected shape for Cilium `network_lossy_multi` now includes the raw top-level workload payload plus raw component payloads:

```json
{
  "ops_total": 77445.0,
  "ops_per_sec": 77410.33,
  "duration_s": 1.0004,
  "workload_name": "network_lossy_multi",
  "network_device": "eth0",
  "netem": {"loss_pct": 20.0, "delay_ms": 50},
  "component_workloads": [
    {
      "workload_tool": "wrk",
      "workload_name": "network_lossy_multi_wrk",
      "request_count": 77445,
      "bytes_total": 11765022.72,
      "requests_per_sec": 77410.33,
      "latency_ms": {"avg": 0.10126, "p50": 0.095, "p90": 0.145, "p99": 0.22}
    },
    {
      "workload_tool": "python-udp-client",
      "workload_name": "udp_burst",
      "packet_count": 100000.0,
      "target_host": "10.244.0.2",
      "target_port": 12345,
      "namespace": "bpfbench"
    }
  ]
}
```

## Existing artifact inspection

Inspected `corpus/results/x86_kvm_corpus_20260507_025319_683029/details/apps/`.

- `katran.json` is pre-change and currently shows only `duration_s`, `ops_per_sec`, `ops_total`, `stdout`, and `stderr` in each workload entry. This confirmed the missing raw request/latency fields fixed in source.
- `cilium__agent.json` has `status: "error"` with `baseline: null` and `post_rejit: null`, so that artifact cannot demonstrate Cilium workload metrics.

## Ambiguous spots

- Broad literal `e2e` grep still finds non-suite false positives in checksum/SWH identifiers such as Cargo lock hashes and `docs/paper/resources/software.bib`; these were not edited.
- Generated historical result artifacts under `corpus/results/` were left untouched, so old workload names or paths there may still contain removed-suite strings.
