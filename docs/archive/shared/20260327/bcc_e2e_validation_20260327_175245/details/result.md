# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-27T17:53:25.033030+00:00`
- Mode: `full`
- Duration per phase: `5s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `3`
- Baseline successes: `2`
- ReJIT successes: `2`
- Tools with eligible sites: `3`
- Aggregate sites: `2036` (map_inline=92, const_prop=220, dce=1718, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `0.937x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| syscount | 78 | 68.11 | 69.10 | 0.986x | 5504.04 | 5886.72 | 0.00 | 0.00 | ok |
| execsnoop | 1750 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | exec_storm failed: aborting: temp-path '.' must be readable and writeable |
| bindsnoop | 208 | 205.51 | 230.78 | 0.890x | 423573.58 | 413837.38 | 6.60 | 8.00 | ok |

## Comparison

- syscount: avg_ns_delta=1.45%, ops_delta=6.95%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- bindsnoop: avg_ns_delta=12.30%, ops_delta=-2.30%, cpu_delta=21.21%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

