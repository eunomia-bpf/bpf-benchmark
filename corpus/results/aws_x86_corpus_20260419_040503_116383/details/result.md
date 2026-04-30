# Corpus Authoritative Summary

- Generated: 2026-04-19T04:08:15.472746+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.124x`
- All-comparable geomean (baseline/rejit): `1.124x`
- Sample count: `11`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 0.973x | 0.973x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 1 | 0.972x | 0.972x |
| bcc/biosnoop | bcc | block_io | 2 | 2 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 1 | 1 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 0.899x | 0.899x |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 5 | 5 | 3 | 1.629x | 1.629x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 2 | 2 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.217x | 1.217x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.020x | 1.020x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.922x | 0.922x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.950x | 0.950x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.908x | 0.908x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `39`
