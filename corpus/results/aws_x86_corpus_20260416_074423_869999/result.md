# Corpus Authoritative Summary

- Generated: 2026-04-16T07:47:04.811372+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `1`
- Workload seconds: `1.0`
- Status: `ok`
- Applied-only geomean (baseline/rejit): `1.027x`
- All-comparable geomean (baseline/rejit): `1.027x`
- Sample count: `30`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.021x | 1.021x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.924x | 0.924x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.977x | 0.977x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 0.993x | 0.993x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 0.992x | 0.992x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 1.158x | 1.158x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.900x | 0.900x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 2 | 2 | 2 | 1.539x | 1.539x |
| katran | katran | test_run | 1 | 1 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 2 | 2 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.013x | 1.013x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.009x | 1.009x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 3 | 3 | 3 | 0.972x | 0.972x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.078x | 1.078x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.980x | 0.980x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.635x | 0.635x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `26`
