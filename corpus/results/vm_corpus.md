# Corpus Authoritative Summary

- Generated: 2026-03-30T20:36:46.402412+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `5.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.040x`
- All-comparable geomean (baseline/rejit): `1.040x`
- Sample count: `5`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| katran | katran | test_run | 1 | 1 | 1 | 1.044x | 1.044x |
| tracee/default | tracee | tracee_default | 13 | 13 | 4 | 1.040x | 1.040x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `9`
