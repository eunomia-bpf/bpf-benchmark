# Corpus Authoritative Summary

- Generated: 2026-04-12T07:04:36.036928+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.146x`
- All-comparable geomean (baseline/rejit): `1.146x`
- Sample count: `35`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.063x | 1.063x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.029x | 1.029x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.825x | 1.825x |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 7 | 7 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 4 | 4 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.155x | 1.155x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.105x | 1.105x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 3 | 1.268x | 1.268x |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 10 | 10 | 8 | 1.090x | 1.090x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.009x | 1.009x |
| bpftrace/biosnoop | bpftrace | block_io | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 5 | 5 | 5 | 1.049x | 1.049x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.045x | 1.045x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.119x | 1.119x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.689x | 0.689x |

## Comparison Exclusion Reasons

- `missing_post_rejit_measurement`: `6`
- `missing_rejit_exec_ns`: `1`
- `no_programs_changed_in_loader`: `25`
