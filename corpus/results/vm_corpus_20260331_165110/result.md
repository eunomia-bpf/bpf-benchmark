# Corpus Authoritative Summary

- Generated: 2026-03-31T16:55:03.471053+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.984x`
- All-comparable geomean (baseline/rejit): `0.984x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.101x | 1.101x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.958x | 0.958x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.880x | 0.880x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.823x | 0.823x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.934x | 0.934x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.999x | 0.999x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.003x | 1.003x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.904x | 0.904x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.930x | 0.930x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 1.031x | 1.031x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 0.999x | 0.999x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.129x | 1.129x |
| katran | katran | test_run | 1 | 1 | 1 | 1.001x | 1.001x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.018x | 1.018x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.098x | 1.098x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.797x | 0.797x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.087x | 1.087x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.958x | 0.958x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.800x | 0.800x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.434x | 1.434x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `44`
- `missing_rejit_exec_ns`: `10`
