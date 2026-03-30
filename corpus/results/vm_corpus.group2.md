# Corpus Authoritative Summary

- Generated: 2026-03-30T13:17:28.621744+00:00
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Repeat: `1`
- Workload seconds: `1.0`
- Status: `error`
- Applied-only geomean (baseline/rejit): `0.794x`
- All-comparable geomean (baseline/rejit): `0.794x`
- Sample count: `10`

## Per-App Breakdown

| App | Runner | Workload | Programs | Applied | Comparable | Applied-only | All-comparable |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| scx/rusty | scx | hackbench | 0 | 0 | 0 | n/a | n/a |
| tetragon/default | tetragon | exec_storm | 0 | 0 | 0 | n/a | n/a |
| katran | katran | test_run | 1 | 1 | 1 | 0.968x | 0.968x |
| tracee/default | tracee | tracee_default | 0 | 0 | 0 | n/a | n/a |
| bpftrace/capable | bpftrace | exec_storm | 1 | 1 | 1 | 1.042x | 1.042x |
| bpftrace/biosnoop | bpftrace | fio | 0 | 0 | 0 | n/a | n/a |
| bpftrace/vfsstat | bpftrace | vfs_create_write_fsync | 4 | 4 | 4 | 0.575x | 0.575x |
| bpftrace/runqlat | bpftrace | hackbench | 3 | 3 | 3 | 0.989x | 0.989x |
| bpftrace/tcplife | bpftrace | network | 1 | 1 | 1 | 0.939x | 0.939x |
| bpftrace/tcpretrans | bpftrace | network | 0 | 0 | 0 | n/a | n/a |

## Comparison Exclusion Reasons

- none
