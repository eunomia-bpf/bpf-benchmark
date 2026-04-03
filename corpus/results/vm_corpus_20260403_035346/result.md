# Corpus Authoritative Summary

- Generated: 2026-04-03T04:36:58.267108+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.033x`
- All-comparable geomean (baseline/rejit): `1.033x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.016x | 1.016x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.004x | 1.004x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.003x | 1.003x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 1.021x | 1.021x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 1.001x | 1.001x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 1.003x | 1.003x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.025x | 1.025x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.984x | 0.984x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.072x | 1.072x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.985x | 0.985x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 0.971x | 0.971x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.419x | 1.419x |
| katran | katran | test_run | 1 | 1 | 1 | 1.014x | 1.014x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 0.993x | 0.993x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.954x | 0.954x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.936x | 0.936x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.064x | 1.064x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.994x | 0.994x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.227x | 1.227x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.941x | 0.941x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
