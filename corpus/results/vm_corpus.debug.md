# Corpus Authoritative Summary

- Generated: 2026-03-30T18:22:46.787013+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.037x`
- All-comparable geomean (baseline/rejit): `1.037x`
- Sample count: `13`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| katran | katran | test_run | 1 | 1 | 1 | 1.025x | 1.025x |
| tracee/default | tracee | tracee_default | 43 | 42 | 12 | 1.038x | 1.038x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `31`
