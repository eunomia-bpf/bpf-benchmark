# Corpus Authoritative Summary

- Generated: 2026-04-13T23:16:06.922491+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `2.921x`
- All-comparable geomean (baseline/rejit): `2.921x`
- Sample count: `44`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.034x | 1.034x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.995x | 0.995x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.039x | 1.039x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 4 | 4.803x | 4.803x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 2.869x | 2.869x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 4.045x | 4.045x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 3.872x | 3.872x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 7 | 7 | 5 | 2.509x | 2.509x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 10 | 10 | 8 | 9.334x | 9.334x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.941x | 1.941x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 2.175x | 2.175x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 3.755x | 3.755x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.124x | 1.124x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 2.178x | 2.178x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.687x | 1.687x |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `2`
- `no_programs_changed_in_loader`: `28`
