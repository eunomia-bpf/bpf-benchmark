# Corpus Authoritative Summary

- Generated: 2026-04-22T06:11:00.482451+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `n/a`
- All-comparable geomean (baseline/rejit): `n/a`
- Sample count: `0`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/execsnoop | bcc | exec_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 0 | 0 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 0 | 0 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 0 | 0 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 0 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 0 | 0 | 0 | n/a | n/a |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcplife | bpftrace | network | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- none
