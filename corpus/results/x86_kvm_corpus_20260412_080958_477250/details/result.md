# Corpus Authoritative Summary

- Generated: 2026-04-12T08:54:06.826133+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `0.931x`
- All-comparable geomean (baseline/rejit): `0.931x`
- Sample count: `36`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.023x | 1.023x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.087x | 1.087x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.215x | 1.215x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 4 | 4 | 2 | 1.352x | 1.352x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.144x | 1.144x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.168x | 1.168x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 2.100x | 2.100x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.261x | 1.261x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 5 | 5 | 3 | 0.550x | 0.550x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.538x | 0.538x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.020x | 1.020x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.786x | 0.786x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.625x | 0.625x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.275x | 0.275x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.498x | 0.498x |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `2`
- `no_programs_changed_in_loader`: `28`
