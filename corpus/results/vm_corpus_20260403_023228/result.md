# Corpus Authoritative Summary

- Generated: 2026-04-03T03:15:48.450768+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.032x`
- All-comparable geomean (baseline/rejit): `1.032x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.019x | 1.019x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.010x | 1.010x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.953x | 0.953x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 1.018x | 1.018x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 1.007x | 1.007x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.978x | 0.978x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.011x | 1.011x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.991x | 0.991x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.051x | 1.051x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 1.001x | 1.001x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.013x | 1.013x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.405x | 1.405x |
| katran | katran | test_run | 1 | 1 | 1 | 1.042x | 1.042x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.005x | 1.005x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.951x | 0.951x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.995x | 0.995x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.006x | 1.006x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.992x | 0.992x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.176x | 1.176x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.051x | 1.051x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
