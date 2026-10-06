# Corpus Authoritative Summary

- Generated: 2026-04-10T00:51:08.422568+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.075x`
- All-comparable geomean (baseline/rejit): `1.075x`
- Sample count: `19`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.987x | 0.987x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.915x | 0.915x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.069x | 1.069x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.047x | 1.047x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.031x | 1.031x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.290x | 1.290x |
| katran | katran | test_run | 1 | 1 | 1 | 1.063x | 1.063x |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.009x | 1.009x |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcplife | bpftrace | network | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_post_rejit_measurement`: `4`
- `no_programs_changed_in_loader`: `25`
