# Corpus Authoritative Summary

- Generated: 2026-04-16T07:09:43.706999+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.039x`
- All-comparable geomean (baseline/rejit): `1.039x`
- Sample count: `31`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.047x | 1.047x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.047x | 1.047x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.048x | 1.048x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.074x | 1.074x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.024x | 1.024x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.046x | 1.046x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.946x | 0.946x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 4 | 4 | 2 | 1.003x | 1.003x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.022x | 1.022x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.026x | 1.026x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.148x | 1.148x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.999x | 0.999x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.986x | 0.986x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.895x | 0.895x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `26`
