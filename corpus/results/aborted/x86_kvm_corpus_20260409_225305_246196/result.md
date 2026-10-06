# Corpus Authoritative Summary

- Generated: 2026-04-09T23:10:43.566652+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.990x`
- All-comparable geomean (baseline/rejit): `0.990x`
- Sample count: `20`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.989x | 0.989x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.900x | 0.900x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.966x | 0.966x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.847x | 0.847x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.826x | 0.826x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 7 | 7 | 5 | 1.209x | 1.209x |
| katran | katran | test_run | 1 | 1 | 1 | 1.079x | 1.079x |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.004x | 1.004x |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcplife | bpftrace | network | 0 | 0 | 0 | n/a | n/a |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_post_rejit_measurement`: `4`
- `no_programs_changed_in_loader`: `25`
