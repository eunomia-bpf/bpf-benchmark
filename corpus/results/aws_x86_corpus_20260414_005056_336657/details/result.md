# Corpus Authoritative Summary

- Generated: 2026-04-14T00:54:00.237094+00:00
- Manifest: `/var/tmp/bpf-benchmark-aws-x86/corpus/run.aws-x86.corpus.02c3029f/corpus/config/macro_apps.yaml`
- Daemon: `/var/tmp/bpf-benchmark-aws-x86/corpus/run.aws-x86.corpus.02c3029f/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.020x`
- All-comparable geomean (baseline/rejit): `1.020x`
- Sample count: `35`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.071x | 1.071x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.022x | 1.022x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.971x | 0.971x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 7 | 7 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 4 | 4 | 4 | 1.099x | 1.099x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.036x | 1.036x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.004x | 1.004x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.961x | 0.961x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 4 | 4 | 2 | 1.038x | 1.038x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.041x | 1.041x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.015x | 1.015x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 6 | 6 | 6 | 1.125x | 1.125x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.080x | 1.080x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.970x | 0.970x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.430x | 0.430x |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `1`
- `no_programs_changed_in_loader`: `26`
