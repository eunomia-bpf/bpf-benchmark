# Corpus Authoritative Summary

- Generated: 2026-04-14T00:19:28.436155+00:00
- Manifest: `/var/tmp/bpf-benchmark-aws-arm64/corpus/run.aws-arm64.corpus.97666d69/corpus/config/macro_apps.yaml`
- Daemon: `/var/tmp/bpf-benchmark-aws-arm64/corpus/run.aws-arm64.corpus.97666d69/daemon/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.076x`
- All-comparable geomean (baseline/rejit): `1.076x`
- Sample count: `31`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.099x | 1.099x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.059x | 1.059x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.990x | 0.990x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 7 | 7 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.502x | 1.502x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.003x | 1.003x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.076x | 1.076x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.869x | 0.869x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 10 | 10 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.130x | 1.130x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.040x | 1.040x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 6 | 6 | 6 | 1.070x | 1.070x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.022x | 1.022x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.188x | 1.188x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.213x | 1.213x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `23`
