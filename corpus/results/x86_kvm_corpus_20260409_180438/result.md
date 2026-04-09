# Corpus Authoritative Summary

- Generated: 2026-04-09T18:21:11.263852+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.187x`
- All-comparable geomean (baseline/rejit): `1.187x`
- Sample count: `22`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.007x | 1.007x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.047x | 1.047x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.299x | 1.299x |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.135x | 1.135x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.091x | 1.091x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.290x | 1.290x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.131x | 1.131x |
| bcc/runqlat | bcc | hackbench | 0 | 0 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 0 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.295x | 1.295x |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.016x | 1.016x |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcplife | bpftrace | network | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `12`
