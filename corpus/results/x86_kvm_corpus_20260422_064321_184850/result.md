# Corpus Authoritative Summary

- Generated: 2026-04-22T07:24:36.710874+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.091x`
- All-comparable geomean (baseline/rejit): `1.091x`
- Sample count: `16`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 1 | 1 | 1 | 1.020x | 1.020x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/bindsnoop | bcc | bind_storm | 3 | 3 | 2 | 0.983x | 0.983x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 1 | 1.003x | 1.003x |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 3 | 3 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 1 | 1 | 0 | n/a | n/a |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 0 | n/a | n/a |
| bcc/tcpconnect | bcc | network | 3 | 3 | 0 | n/a | n/a |
| bcc/tcplife | bcc | network | 1 | 1 | 0 | n/a | n/a |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 1 | 1.047x | 1.047x |
| scx/rusty | scx | hackbench | 11 | 11 | 1 | 0.987x | 0.987x |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.432x | 1.432x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 3 | 3 | 1 | 0.962x | 0.962x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.000x | 1.000x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 1.044x | 1.044x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 2 | 2 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 0.971x | 0.971x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.959x | 0.959x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 1.002x | 1.002x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `37`
