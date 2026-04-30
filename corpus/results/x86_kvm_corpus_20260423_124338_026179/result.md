# Corpus Authoritative Summary

- Generated: 2026-04-23T12:50:07.654657+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.084x`
- All-comparable geomean (baseline/rejit): `1.084x`
- Sample count: `26`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 0.990x | 0.990x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 0.964x | 0.964x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 1.024x | 1.024x |
| bcc/vfsstat | bcc | vfs_create_fsync_exact | 5 | 5 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | open_family_storm | 3 | 3 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.094x | 1.094x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 0.935x | 0.935x |
| tetragon/default | tetragon | tetragon_exec_connect_mix | 35 | 35 | 7 | 1.211x | 1.211x |
| katran | katran | test_run | 3 | 3 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_system_edge_mix | 37 | 36 | 8 | 1.110x | 1.110x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.028x | 1.028x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 0.998x | 0.998x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.908x | 0.908x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.030x | 1.030x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.996x | 0.996x |

## Comparison Exclusion Reasons

- `all_sites_rolled_back`: `13`
- `missing_baseline_exec_ns`: `59`
- `zero_sites_found`: `26`
