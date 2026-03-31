# Corpus Authoritative Summary

- Generated: 2026-03-31T16:15:43.387037+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.032x`
- All-comparable geomean (baseline/rejit): `1.032x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.098x | 1.098x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.986x | 0.986x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.052x | 1.052x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.922x | 0.922x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.954x | 0.954x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.991x | 0.991x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.008x | 1.008x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.056x | 1.056x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.963x | 0.963x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 1.020x | 1.020x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.022x | 1.022x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.324x | 1.324x |
| katran | katran | test_run | 1 | 1 | 1 | 1.038x | 1.038x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.034x | 1.034x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.010x | 1.010x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.655x | 0.655x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.266x | 1.266x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.010x | 1.010x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.022x | 1.022x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.797x | 0.797x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `44`
- `missing_rejit_exec_ns`: `10`
