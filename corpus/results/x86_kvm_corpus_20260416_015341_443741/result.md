# Corpus Authoritative Summary

- Generated: 2026-04-16T02:34:19.507879+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.052x`
- All-comparable geomean (baseline/rejit): `1.052x`
- Sample count: `36`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.985x | 0.985x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.023x | 1.023x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.072x | 1.072x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.013x | 1.013x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 0.960x | 0.960x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.983x | 0.983x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.976x | 0.976x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.397x | 1.397x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 5 | 5 | 3 | 1.023x | 1.023x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.009x | 1.009x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.012x | 1.012x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.093x | 1.093x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.027x | 1.027x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.993x | 0.993x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.829x | 0.829x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `28`
