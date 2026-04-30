# Corpus Authoritative Summary

- Generated: 2026-04-22T22:47:36.682061+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.133x`
- All-comparable geomean (baseline/rejit): `1.133x`
- Sample count: `23`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 1.003x | 1.003x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 0.975x | 0.975x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 1.014x | 1.014x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 5 | 5 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 3 | 3 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.148x | 1.148x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.027x | 1.027x |
| tetragon/default | tetragon | exec_storm | 35 | 35 | 6 | 1.635x | 1.635x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 37 | 36 | 6 | 1.007x | 1.007x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.030x | 1.030x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 0.981x | 0.981x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.885x | 0.885x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.985x | 0.985x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.887x | 0.887x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `61`
- `no_programs_changed_in_loader`: `38`
