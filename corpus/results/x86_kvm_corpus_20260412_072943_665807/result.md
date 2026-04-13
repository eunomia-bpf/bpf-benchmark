# Corpus Authoritative Summary

- Generated: 2026-04-12T07:30:46.379371+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.161x`
- All-comparable geomean (baseline/rejit): `1.161x`
- Sample count: `6`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.425x | 1.425x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.077x | 1.077x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.019x | 1.019x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `4`
