# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-27T17:55:00.429174+00:00`
- Mode: `full`
- Duration per phase: `5s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `1`
- Baseline successes: `0`
- ReJIT successes: `0`
- Tools with eligible sites: `1`
- Aggregate sites: `1750` (map_inline=67, const_prop=185, dce=1498, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `n/a`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| execsnoop | 1750 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | exec_storm failed: aborting: temp-path '/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260327/vm-tmp' must be readable and writeable |

## Comparison

- execsnoop: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

