# Corpus Authoritative Summary

- Generated: 2026-03-31T03:15:56.265310+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.979x`
- All-comparable geomean (baseline/rejit): `0.979x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.169x | 1.169x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.004x | 1.004x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.989x | 0.989x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.903x | 0.903x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.933x | 0.933x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.991x | 0.991x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.021x | 1.021x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.888x | 0.888x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.949x | 0.949x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 1.065x | 1.065x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.006x | 1.006x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.223x | 1.223x |
| katran | katran | test_run | 1 | 1 | 1 | 0.994x | 0.994x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 0.949x | 0.949x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.011x | 1.011x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.873x | 0.873x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.869x | 0.869x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.989x | 0.989x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.995x | 0.995x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.008x | 1.008x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
