# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-12T07:36:45.861046+00:00`
- Mode: `smoke`
- Duration per phase: `5s`
- Host kernel: `7.0.0-rc2+`
- bpftrace: `bpftrace v0.25.0-be6ee45`
- bpftool: `bpftool v7.5.0
using libbpf v1.5
features: llvm, skeletons`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `1`
- Baseline successes: `1`
- ReJIT successes: `1`
- Scripts with applied sites: `1`
- Aggregate applied sites: `244` (map_inline=6, const_prop=70, dce=75, wide_mem=92, bulk_memory=1)
- Geomean speedup: `1.042x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| capable | 244 | 102.99 | 98.83 | 1.042x | 6578.84 | 6522.07 | 0.00 | 0.00 | ok |

## Comparison

- capable: avg_ns_delta=-4.04%, ops_delta=-0.86%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

