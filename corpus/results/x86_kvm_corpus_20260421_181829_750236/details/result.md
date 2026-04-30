# Corpus Authoritative Summary

- Generated: 2026-04-21T18:58:16.455285+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.010x`
- All-comparable geomean (baseline/rejit): `1.010x`
- Sample count: `10`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 0.937x | 0.937x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 1 | 0.985x | 0.985x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 0.967x | 0.967x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 1 | 1 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.062x | 1.062x |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 1 | 1 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 3 | 3 | 1 | 0.991x | 0.991x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.999x | 0.999x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.002x | 1.002x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.062x | 1.062x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.995x | 0.995x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.107x | 1.107x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `38`
