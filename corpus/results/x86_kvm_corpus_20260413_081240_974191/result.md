# Corpus Authoritative Summary

- Generated: 2026-04-13T08:55:17.226984+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.916x`
- All-comparable geomean (baseline/rejit): `0.916x`
- Sample count: `44`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.031x | 1.031x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.004x | 1.004x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.007x | 1.007x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 4 | 0.971x | 0.971x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.115x | 1.115x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.147x | 1.147x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.047x | 1.047x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.320x | 1.320x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 12 | 12 | 9 | 0.787x | 0.787x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.985x | 0.985x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.744x | 0.744x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.480x | 0.480x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.956x | 0.956x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.908x | 0.908x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.170x | 1.170x |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `2`
- `no_programs_changed_in_loader`: `29`
