# Corpus Authoritative Summary

- Generated: 2026-04-15T23:59:18.603630+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.098x`
- All-comparable geomean (baseline/rejit): `1.098x`
- Sample count: `26`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.036x | 1.036x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.069x | 1.069x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.631x | 1.631x |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 7 | 7 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.991x | 0.991x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.991x | 0.991x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 5 | 5 | 3 | 1.006x | 1.006x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.017x | 1.017x |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 5 | 5 | 5 | 1.051x | 1.051x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.011x | 1.011x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.995x | 0.995x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_post_rejit_measurement`: `4`
- `no_programs_changed_in_loader`: `23`
