# Corpus Authoritative Summary

- Generated: 2026-04-20T20:51:07.889726+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.985x`
- All-comparable geomean (baseline/rejit): `0.985x`
- Sample count: `7`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 0 | n/a | n/a |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 0 | n/a | n/a |
| bcc/biosnoop | bcc | block_io | 2 | 2 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 0.887x | 0.887x |
| scx/rusty | scx | hackbench | 10 | 10 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 3 | 3 | 1 | 1.032x | 1.032x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.906x | 0.906x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.003x | 1.003x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.041x | 1.041x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.033x | 1.033x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.007x | 1.007x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `39`
