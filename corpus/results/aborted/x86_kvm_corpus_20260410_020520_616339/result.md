# Corpus Authoritative Summary

- Generated: 2026-04-10T02:34:16.884268+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.275x`
- All-comparable geomean (baseline/rejit): `1.275x`
- Sample count: `26`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.204x | 1.204x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.247x | 1.247x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.956x | 0.956x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.056x | 1.056x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.132x | 1.132x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 2.596x | 2.596x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.874x | 1.874x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.234x | 1.234x |
| katran | katran | test_run | 1 | 1 | 1 | 1.021x | 1.021x |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.964x | 0.964x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 0.985x | 0.985x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.026x | 1.026x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.043x | 1.043x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `32`
