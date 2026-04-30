# Corpus Authoritative Summary

- Generated: 2026-04-22T01:23:00.735148+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.983x`
- All-comparable geomean (baseline/rejit): `0.983x`
- Sample count: `10`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 0.876x | 0.876x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 1.010x | 1.010x |
| bcc/biosnoop | bcc | block_io | 2 | 2 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 1 | 1 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 0.927x | 0.927x |
| scx/rusty | scx | hackbench | 11 | 11 | 1 | 0.943x | 0.943x |
| tetragon/default | tetragon | exec_storm | 1 | 1 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 2 | 2 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.882x | 0.882x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.085x | 1.085x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.078x | 1.078x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.012x | 1.012x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.037x | 1.037x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `36`
