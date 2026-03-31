# Corpus Authoritative Summary

- Generated: 2026-03-31T15:04:23.086675+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.029x`
- All-comparable geomean (baseline/rejit): `1.029x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.012x | 1.012x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.961x | 0.961x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.011x | 1.011x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.887x | 0.887x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 1.086x | 1.086x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 1.027x | 1.027x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.013x | 1.013x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.920x | 0.920x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.815x | 0.815x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.984x | 0.984x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.009x | 1.009x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.287x | 1.287x |
| katran | katran | test_run | 1 | 1 | 1 | 1.018x | 1.018x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 0.997x | 0.997x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.103x | 1.103x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.135x | 1.135x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.008x | 1.008x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.039x | 1.039x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.240x | 1.240x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.159x | 1.159x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `44`
- `missing_rejit_exec_ns`: `10`
