# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-30T21:39:41.154892+00:00`
- Mode: `smoke`
- Duration per phase: `5s`
- Host kernel: `7.0.0-rc2+`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `1`
- Baseline successes: `1`
- ReJIT successes: `1`
- Eligible-site scripts: `1`
- Aggregate sites: `6` (cmov=0, wide=6, rotate=0, lea=0)
- Geomean speedup: `1.014x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| capable | 6 | 2012.03 | 1983.60 | 1.014x | 351.87 | 417.02 | 0.00 | 0.00 | ok |

## Comparison

- capable: avg_ns_delta=-1.41%, ops_delta=18.52%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

