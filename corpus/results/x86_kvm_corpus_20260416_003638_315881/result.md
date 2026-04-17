# Corpus Authoritative Summary

- Generated: 2026-04-16T01:16:15.887414+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Samples: `30`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `1.055x`
- All-comparable geomean (baseline/rejit): `1.055x`
- Sample count: `36`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.940x | 0.940x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.073x | 1.073x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.046x | 1.046x |
| bcc/biosnoop | bcc | block_io | 3 | 3 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 6 | 6 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 2 | 2 | 2 | 1.052x | 1.052x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.145x | 1.145x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.981x | 0.981x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.994x | 0.994x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 0 | n/a | n/a |
| scx/rusty | scx | hackbench | 11 | 11 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 6 | 6 | 4 | 1.399x | 1.399x |
| katran | katran | test_run | 0 | 0 | 0 | n/a | n/a |
| tracee/default | tracee | tracee_default | 5 | 5 | 3 | 1.032x | 1.032x |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.018x | 1.018x |
| bpftrace/biosnoop | bpftrace | block_io | 2 | 2 | 2 | 1.019x | 1.019x |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.025x | 1.025x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 1.033x | 1.033x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.989x | 0.989x |
| bpftrace/tcpretrans | bpftrace | tcp_retransmit | 1 | 1 | 1 | 0.800x | 0.800x |

## Comparison Exclusion Reasons

- `no_programs_changed_in_loader`: `27`
