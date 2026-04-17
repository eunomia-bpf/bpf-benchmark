# Corpus Authoritative Summary

- Generated: 2026-04-16T05:53:44.618770+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.039x`
- All-comparable geomean (baseline/rejit): `1.039x`
- Sample count: `30`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.145x | 1.145x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.062x | 1.062x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.982x | 0.982x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 0.999x | 0.999x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.073x | 1.073x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.186x | 1.186x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.984x | 0.984x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 4 | 4 | 2 | 1.106x | 1.106x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.042x | 1.042x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.036x | 1.036x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.885x | 0.885x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.073x | 1.073x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.980x | 0.980x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `1`
- `no_programs_changed_in_loader`: `26`
