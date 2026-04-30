# Corpus Authoritative Summary

- Generated: 2026-04-22T19:17:17.472641+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `5`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.013x`
- All-comparable geomean (baseline/rejit): `1.013x`
- Sample count: `8`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/biosnoop | bcc | block_io | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 0 | 0 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 0 | 0 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.044x | 1.044x |
| scx/rusty | scx | hackbench | 10 | 10 | 1 | 1.002x | 1.002x |
| tetragon/default | tetragon | exec_storm | 2 | 2 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 3 | 3 | 1 | 0.984x | 0.984x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.000x | 1.000x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.043x | 1.043x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.044x | 1.044x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.025x | 1.025x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.968x | 0.968x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `1`
- `no_programs_changed_in_loader`: `23`
