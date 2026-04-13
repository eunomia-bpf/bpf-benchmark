# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-12T07:37:39.808377+00:00`
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
- Geomean speedup: `0.998x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| capable | 57 | 105.01 | 105.25 | 0.998x | 6147.80 | 6183.09 | 21.78 | 20.57 | ok |

## Comparison

- capable: avg_ns_delta=0.23%, ops_delta=0.57%, cpu_delta=-5.55%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

