# Corpus Authoritative Summary

- Generated: 2026-04-10T01:41:58.351321+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.998x`
- All-comparable geomean (baseline/rejit): `0.998x`
- Sample count: `28`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 1.000x | 1.000x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 0.959x | 0.959x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 0.991x | 0.991x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 0.892x | 0.892x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 0.770x | 0.770x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.817x | 0.817x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.811x | 0.811x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 1 | 3.247x | 3.247x |
| tetragon/default | tetragon | exec_storm | 7 | 7 | 5 | 1.154x | 1.154x |
| katran | katran | test_run | 1 | 1 | 1 | 0.975x | 0.975x |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 0.930x | 0.930x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 1 | 0.952x | 0.952x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 0 | n/a | n/a |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 1 | 1.290x | 1.290x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.844x | 0.844x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `31`
