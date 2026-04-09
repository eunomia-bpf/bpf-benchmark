# Corpus Authoritative Summary

- Generated: 2026-04-09T06:13:01.459230+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.966x`
- All-comparable geomean (baseline/rejit): `0.966x`
- Sample count: `24`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.970x | 0.970x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.999x | 0.999x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.979x | 0.979x |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.007x | 1.007x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.015x | 1.015x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.794x | 0.794x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.780x | 0.780x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.131x | 1.131x |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.994x | 0.994x |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.012x | 1.012x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.956x | 0.956x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `28`
