# Corpus Authoritative Summary

- Generated: 2026-04-10T03:47:30.669736+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.116x`
- All-comparable geomean (baseline/rejit): `1.116x`
- Sample count: `29`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.991x | 0.991x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.006x | 1.006x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.570x | 1.570x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 0.981x | 0.981x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 0.901x | 0.901x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.812x | 0.812x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 1.032x | 1.032x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.082x | 1.082x |
| katran | katran | test_run | 1 | 1 | 1 | 0.963x | 0.963x |
| tracee/default | tracee | tracee_default | 4 | 4 | 2 | 1.133x | 1.133x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.103x | 1.103x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.069x | 1.069x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.071x | 1.071x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 1.638x | 1.638x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 3.253x | 3.253x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `34`
