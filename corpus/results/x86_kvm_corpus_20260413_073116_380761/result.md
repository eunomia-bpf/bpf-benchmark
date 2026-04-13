# Corpus Authoritative Summary

- Generated: 2026-04-13T08:03:32.246740+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.990x`
- All-comparable geomean (baseline/rejit): `0.990x`
- Sample count: `34`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.910x | 0.910x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.960x | 0.960x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.907x | 0.907x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 4 | 0.726x | 0.726x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.153x | 1.153x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.155x | 1.155x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.227x | 1.227x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 0 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.348x | 1.348x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.042x | 1.042x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.177x | 1.177x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.784x | 0.784x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.984x | 0.984x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.994x | 0.994x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_rejit_exec_ns`: `2`
- `no_programs_changed_in_loader`: `15`
