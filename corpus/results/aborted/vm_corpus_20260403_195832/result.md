# Corpus Authoritative Summary

- Generated: 2026-04-03T20:00:58.852353+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.117x`
- All-comparable geomean (baseline/rejit): `1.117x`
- Sample count: `60`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.011x | 1.011x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.147x | 1.147x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.268x | 1.268x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 3 | 1.125x | 1.125x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 6 | 1.124x | 1.124x |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.081x | 1.081x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.096x | 1.096x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.862x | 0.862x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.827x | 0.827x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 1.006x | 1.006x |
| scx/rusty | scx | hackbench | 0 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 5 | 5 | 5 | 1.129x | 1.129x |
| katran | katran | test_run | 1 | 1 | 1 | 0.986x | 0.986x |
| tracee/default | tracee | tracee_default | 13 | 13 | 13 | 1.321x | 1.321x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.054x | 1.054x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.035x | 1.035x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.949x | 0.949x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.025x | 1.025x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.857x | 0.857x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 2.031x | 2.031x |

## Comparison Exclusion Reasons

- none
