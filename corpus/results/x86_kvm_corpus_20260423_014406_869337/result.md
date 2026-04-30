# Corpus Authoritative Summary

- Generated: 2026-04-23T01:50:21.680727+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.047x`
- All-comparable geomean (baseline/rejit): `1.047x`
- Sample count: `23`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 0.973x | 0.973x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 0.988x | 0.988x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 1.018x | 1.018x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 5 | 5 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 3 | 3 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.011x | 1.011x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 0.942x | 0.942x |
| tetragon/default | tetragon | exec_storm | 35 | 35 | 6 | 1.273x | 1.273x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 37 | 36 | 6 | 0.974x | 0.974x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.077x | 1.077x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.029x | 1.029x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.928x | 0.928x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.936x | 0.936x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.894x | 0.894x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `61`
- `no_programs_changed_in_loader`: `38`
