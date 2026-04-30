# Corpus Authoritative Summary

- Generated: 2026-04-13T22:03:30.965566+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.169x`
- All-comparable geomean (baseline/rejit): `1.169x`
- Sample count: `44`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.006x | 1.006x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.016x | 1.016x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.028x | 1.028x |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 4 | 1.780x | 1.780x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.148x | 1.148x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.255x | 1.255x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.059x | 1.059x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.284x | 1.284x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 12 | 12 | 9 | 1.132x | 1.132x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.013x | 1.013x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.250x | 1.250x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.102x | 1.102x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.041x | 1.041x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.134x | 1.134x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.951x | 0.951x |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `2`
- `no_programs_changed_in_loader`: `26`
