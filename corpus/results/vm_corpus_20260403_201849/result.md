# Corpus Authoritative Summary

- Generated: 2026-04-03T20:21:15.698532+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.067x`
- All-comparable geomean (baseline/rejit): `1.067x`
- Sample count: `35`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.034x | 1.034x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.949x | 0.949x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.985x | 0.985x |
| bcc/biosnoop | bcc | block_io | 3 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 0 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 0.991x | 0.991x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.027x | 1.027x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.994x | 0.994x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.085x | 1.085x |
| bcc/runqlat | bcc | hackbench | 3 | 0 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 5 | 3 | 3 | 1.765x | 1.765x |
| katran | katran | test_run | 1 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 13 | 10 | 10 | 0.994x | 0.994x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.989x | 0.989x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 1 | 1 | 1.052x | 1.052x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 0 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 1 | 1 | 1.006x | 1.006x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.630x | 1.630x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.123x | 1.123x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `36`
