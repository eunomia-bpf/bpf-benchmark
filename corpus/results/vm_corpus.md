# Corpus Authoritative Summary

- Generated: 2026-03-31T02:13:39.854456+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.947x`
- All-comparable geomean (baseline/rejit): `0.947x`
- Sample count: `3`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.034x | 1.034x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.795x | 0.795x |

## Comparison Exclusion Reasons

- none
