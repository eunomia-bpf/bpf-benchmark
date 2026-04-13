# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-12T08:03:41.832955+00:00`
- Mode: `smoke`
- Duration per phase: `10s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `1`
- Baseline successes: `1`
- ReJIT successes: `1`
- Tools with applied sites: `1`
- Aggregate applied sites: `57` (map_inline=11, const_prop=11, dce=33, extract=2)
- Geomean speedup: `0.990x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| capable | 57 | 110.39 | 111.46 | 0.990x | 6191.06 | 6203.45 | 22.07 | 22.08 | ok |

## Comparison

- capable: avg_ns_delta=0.97%, ops_delta=0.20%, cpu_delta=0.03%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

