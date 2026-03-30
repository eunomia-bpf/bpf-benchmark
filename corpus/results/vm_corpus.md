# Corpus Authoritative Summary

- Generated: 2026-03-30T07:06:35.797319+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Repeat: `5`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.981x`
- All-comparable geomean (baseline/rejit): `0.981x`
- Sample count: `34`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | bcc | exec_storm | 2 | 2 | 2 | 0.995x | 0.995x |
| bcc/execsnoop | bcc | exec_storm | 2 | 2 | 2 | 1.077x | 1.077x |
| bcc/bindsnoop | bcc | bind_storm | 4 | 4 | 4 | 1.011x | 1.011x |
| bcc/biosnoop | bcc | fio | 0 | 0 | 0 | n/a | n/a |
| bcc/vfsstat | bcc | vfs_create_write_fsync | 0 | 0 | 0 | n/a | n/a |
| bcc/opensnoop | bcc | file_open_storm | 6 | 6 | 6 | 0.983x | 0.983x |
| bcc/syscount | bcc | file_open_storm | 2 | 2 | 2 | 1.036x | 1.036x |
| bcc/tcpconnect | bcc | network | 4 | 4 | 4 | 0.764x | 0.764x |
| bcc/tcplife | bcc | network | 1 | 1 | 1 | 0.860x | 0.860x |
| bcc/runqlat | bcc | hackbench | 3 | 3 | 3 | 0.971x | 0.971x |
| scx/rusty | scx | hackbench | 0 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 1 | 1.084x | 1.084x |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.095x | 1.095x |
| bpftrace/biosnoop | bpftrace | fio | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 1.134x | 1.134x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.986x | 0.986x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.895x | 0.895x |
| bpftrace/tcpretrans | bpftrace | network | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- none
