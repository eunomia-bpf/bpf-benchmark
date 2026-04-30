# Corpus Authoritative Summary

- Generated: 2026-04-23T12:19:30.057055+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.081x`
- All-comparable geomean (baseline/rejit): `1.081x`
- Sample count: `18`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 0.968x | 0.968x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 0.840x | 0.840x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 0.987x | 0.987x |
| bcc/vfsstat | bcc | vfs_create_fsync_exact | 5 | 5 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | open_family_storm | 3 | 3 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.063x | 1.063x |
| scx/rusty | scx | hackbench | 13 | 13 | 1 | 1.034x | 1.034x |
| tetragon/default | tetragon | tetragon_exec_connect_mix | 35 | 35 | 7 | 1.351x | 1.351x |
| katran | katran | test_run | 3 | 3 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_system_edge_mix | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.985x | 0.985x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 0.955x | 0.955x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.929x | 0.929x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.957x | 0.957x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.801x | 0.801x |

## Comparison Exclusion Reasons

- `all_sites_rolled_back`: `12`
- `missing_baseline_exec_ns`: `33`
- `zero_sites_found`: `24`
