# Corpus Authoritative Summary

- Generated: 2026-03-31T17:31:25.763358+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.949x`
- All-comparable geomean (baseline/rejit): `0.949x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.985x | 0.985x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.966x | 0.966x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.055x | 1.055x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 1.035x | 1.035x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.935x | 0.935x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.998x | 0.998x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.027x | 1.027x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.731x | 0.731x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.977x | 0.977x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.998x | 0.998x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.040x | 1.040x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 0.978x | 0.978x |
| katran | katran | test_run | 1 | 1 | 1 | 0.960x | 0.960x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 0.970x | 0.970x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.060x | 1.060x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.731x | 0.731x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.958x | 0.958x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.958x | 0.958x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.856x | 0.856x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.782x | 0.782x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `44`
- `missing_rejit_exec_ns`: `10`
