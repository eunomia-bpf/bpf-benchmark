# Corpus Authoritative Summary

- Generated: 2026-04-23T04:50:16.342061+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.979x`
- All-comparable geomean (baseline/rejit): `0.979x`
- Sample count: `17`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 1.119x | 1.119x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 0.995x | 0.995x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 1.031x | 1.031x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 5 | 5 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 3 | 3 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.112x | 1.112x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 0.979x | 0.979x |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 37 | 36 | 6 | 0.946x | 0.946x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.013x | 1.013x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 0.960x | 0.960x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.994x | 0.994x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.995x | 0.995x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.812x | 0.812x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `34`
- `no_programs_changed_in_loader`: `36`
