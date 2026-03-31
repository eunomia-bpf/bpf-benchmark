# Corpus Authoritative Summary

- Generated: 2026-03-31T14:26:27.928863+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.005x`
- All-comparable geomean (baseline/rejit): `1.005x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.023x | 1.023x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.073x | 1.073x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.034x | 1.034x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 1.166x | 1.166x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.794x | 0.794x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 1.036x | 1.036x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.044x | 1.044x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.132x | 1.132x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.956x | 0.956x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 1.018x | 1.018x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.008x | 1.008x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.136x | 1.136x |
| katran | katran | test_run | 1 | 1 | 1 | 1.010x | 1.010x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.018x | 1.018x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.963x | 0.963x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.039x | 1.039x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.907x | 0.907x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.006x | 1.006x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.823x | 0.823x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.895x | 0.895x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `44`
- `missing_rejit_exec_ns`: `10`
