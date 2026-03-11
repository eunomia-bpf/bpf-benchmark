# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-11T16:38:36.319564+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2-g2a6783cc77b6`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`

## Summary

- Scripts selected: `5`
- Baseline successes: `5`
- ReJIT successes: `2`
- Eligible-site scripts: `2`
- Aggregate sites: `9` (cmov=9, wide=0, rotate=0, lea=0)
- Geomean speedup: `0.992x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| open_latency | 5 | 277.17 | 273.77 | 1.012x | 95367.05 | 96082.49 | 0.03 | 0.03 | ok |
| exec_trace | 0 | 467.11 | n/a | n/a | 198.84 | n/a | 0.00 | n/a | no eligible directive sites |
| scheduler_latency | 4 | 158.59 | 163.27 | 0.971x | 41.72 | 38.09 | 0.00 | 0.00 | ok |
| vfs_read_count | 0 | 58.42 | n/a | n/a | 286499.06 | n/a | 0.03 | n/a | no eligible directive sites |
| tcp_connect | 0 | 305.59 | n/a | n/a | 18.93 | n/a | 0.00 | n/a | no eligible directive sites |

## Comparison

- open_latency: avg_ns_delta=-1.23%, ops_delta=0.75%, cpu_delta=0.00%
- exec_trace: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- scheduler_latency: avg_ns_delta=2.95%, ops_delta=-8.70%, cpu_delta=n/a%
- vfs_read_count: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcp_connect: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.

