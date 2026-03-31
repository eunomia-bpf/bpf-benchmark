# Corpus Authoritative Summary

- Generated: 2026-03-31T04:09:26.152359+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.998x`
- All-comparable geomean (baseline/rejit): `0.998x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.156x | 1.156x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.112x | 1.112x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.007x | 1.007x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.875x | 0.875x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 1.056x | 1.056x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.965x | 0.965x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 0.998x | 0.998x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.837x | 0.837x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.057x | 1.057x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.980x | 0.980x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.034x | 1.034x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.093x | 1.093x |
| katran | katran | test_run | 1 | 1 | 1 | 1.006x | 1.006x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 0.996x | 0.996x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.997x | 0.997x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.980x | 0.980x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.970x | 0.970x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.958x | 0.958x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.969x | 0.969x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.136x | 1.136x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
