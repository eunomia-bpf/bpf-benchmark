# Corpus Authoritative Summary

- Generated: 2026-04-10T01:07:45.453347+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.966x`
- All-comparable geomean (baseline/rejit): `0.966x`
- Sample count: `2`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| tracee/default | tracee | tracee_default | 4 | 4 | 2 | 0.966x | 0.966x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `2`
