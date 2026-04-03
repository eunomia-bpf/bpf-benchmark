# Corpus Authoritative Summary

- Generated: 2026-04-03T01:54:55.649748+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.034x`
- All-comparable geomean (baseline/rejit): `1.034x`
- Sample count: `61`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.011x | 1.011x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.979x | 0.979x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.001x | 1.001x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.979x | 0.979x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.993x | 0.993x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 0.995x | 0.995x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.014x | 1.014x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.068x | 1.068x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.979x | 0.979x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.998x | 0.998x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.027x | 1.027x |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.342x | 1.342x |
| katran | katran | test_run | 1 | 1 | 1 | 0.989x | 0.989x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 0.990x | 0.990x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.993x | 0.993x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.077x | 1.077x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.043x | 1.043x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.994x | 0.994x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.333x | 1.333x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.979x | 0.979x |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
