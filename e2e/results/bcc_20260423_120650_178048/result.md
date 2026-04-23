# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-23T12:07:15.592858+00:00`
- Mode: `smoke`
- Duration per phase: `10s`
- Host kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `1`
- Baseline successes: `1`
- ReJIT successes: `1`
- Tools with applied sites: `1`
- Aggregate applied sites: `1` (extract=1)
- Geomean speedup: `1.018x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| capable | 1 | 39.99 | 39.28 | 1.018x | 2449.65 | 2447.34 | 2.70 | 2.40 | ok |

## Comparison

- capable: avg_ns_delta=-1.76%, ops_delta=-0.09%, cpu_delta=-11.18%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

