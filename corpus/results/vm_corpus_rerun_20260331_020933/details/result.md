# Corpus Authoritative Summary

- Generated: 2026-03-31T02:13:03.030965+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.982x`
- All-comparable geomean (baseline/rejit): `0.982x`
- Sample count: `60`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.859x | 0.859x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.144x | 1.144x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.980x | 0.980x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.892x | 0.892x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.841x | 0.841x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.996x | 0.996x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.006x | 1.006x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.071x | 1.071x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.797x | 0.797x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.949x | 0.949x |
| scx/rusty | scx | hackbench | 13 | 13 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.170x | 1.170x |
| katran | katran | test_run | 1 | 1 | 1 | 1.002x | 1.002x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.007x | 1.007x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.024x | 1.024x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.853x | 0.853x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.133x | 1.133x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.007x | 1.007x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.084x | 1.084x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.503x | 0.503x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `44`
- `missing_rejit_exec_ns`: `10`
