# Corpus Authoritative Summary

- Generated: 2026-04-09T06:53:47.787825+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.033x`
- All-comparable geomean (baseline/rejit): `1.033x`
- Sample count: `21`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.027x | 1.027x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.887x | 0.887x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.033x | 1.033x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.934x | 0.934x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.764x | 0.764x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 5 | 5 | 4 | 1.276x | 1.276x |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.025x | 1.025x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.088x | 1.088x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.008x | 1.008x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.200x | 1.200x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_post_rejit_measurement`: `4`
- `no_programs_changed_in_loader`: `27`
