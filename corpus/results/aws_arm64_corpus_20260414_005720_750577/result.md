# Corpus Authoritative Summary

- Generated: 2026-04-14T01:00:12.322787+00:00
- Manifest: `/var/tmp/bpf-benchmark-aws-arm64/corpus/run.aws-arm64.corpus.4b3478d3/corpus/config/macro_apps.yaml`
- Daemon: `/var/tmp/bpf-benchmark-aws-arm64/corpus/run.aws-arm64.corpus.4b3478d3/daemon/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.006x`
- All-comparable geomean (baseline/rejit): `1.006x`
- Sample count: `32`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.083x | 1.083x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.126x | 1.126x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.028x | 1.028x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 7 | 7 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 0.763x | 0.763x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.052x | 1.052x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.009x | 1.009x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.861x | 0.861x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 4 | 4 | 2 | 0.958x | 0.958x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.040x | 1.040x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.004x | 1.004x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 6 | 6 | 6 | 1.045x | 1.045x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.007x | 1.007x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.005x | 1.005x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `27`
