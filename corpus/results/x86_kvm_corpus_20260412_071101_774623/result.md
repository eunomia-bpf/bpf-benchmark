# Corpus Authoritative Summary

- Generated: 2026-04-12T07:11:50.745255+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.027x`
- All-comparable geomean (baseline/rejit): `1.027x`
- Sample count: `6`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.092x | 1.092x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 0.992x | 0.992x |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.000x | 1.000x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `3`
