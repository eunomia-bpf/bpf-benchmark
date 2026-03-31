# Corpus Authoritative Summary

- Generated: 2026-03-31T15:41:07.079988+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.003x`
- All-comparable geomean (baseline/rejit): `1.003x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.132x | 1.132x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.131x | 1.131x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.024x | 1.024x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.958x | 0.958x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 1.000x | 1.000x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.970x | 0.970x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.080x | 1.080x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.844x | 0.844x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.105x | 1.105x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.958x | 0.958x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.043x | 1.043x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 0.967x | 0.967x |
| katran | katran | test_run | 1 | 1 | 1 | 0.980x | 0.980x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.011x | 1.011x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.017x | 1.017x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.745x | 0.745x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.145x | 1.145x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.961x | 0.961x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.922x | 0.922x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.796x | 1.796x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
