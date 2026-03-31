# Corpus Authoritative Summary

- Generated: 2026-03-31T01:58:52.626999+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.028x`
- All-comparable geomean (baseline/rejit): `1.028x`
- Sample count: `59`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.301x | 1.301x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.968x | 0.968x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.008x | 1.008x |
| bcc/biosnoop | bcc | block_io | 4 | 4 | 3 | 0.961x | 0.961x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 8 | 8 | 6 | 0.662x | 0.662x |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 2 | 1.030x | 1.030x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.051x | 1.051x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.127x | 1.127x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.855x | 0.855x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.977x | 0.977x |
| scx/rusty | scx | hackbench | 13 | 13 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 8 | 8 | 5 | 1.131x | 1.131x |
| katran | katran | test_run | 1 | 1 | 1 | 0.991x | 0.991x |
| tracee/default | tracee | tracee_default | 44 | 44 | 13 | 1.153x | 1.153x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.029x | 1.029x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 0.989x | 0.989x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.085x | 1.085x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.394x | 1.394x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.636x | 0.636x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `missing_baseline_exec_ns`: `43`
- `missing_rejit_exec_ns`: `11`
