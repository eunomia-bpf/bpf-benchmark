# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-12T04:50:30.701645+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`

## Summary

- Scripts selected: `5`
- Baseline successes: `5`
- ReJIT successes: `3`
- Eligible-site scripts: `3`
- Aggregate sites: `13` (cmov=12, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.056x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| open_latency | 6 | 324.05 | 269.18 | 1.204x | 95143.99 | 96220.93 | 0.07 | 0.03 | ok |
| exec_trace | 0 | 551.71 | n/a | n/a | 193.18 | n/a | 0.03 | n/a | no eligible directive sites |
| scheduler_latency | 6 | 164.85 | 168.55 | 0.978x | 41.18 | 39.44 | 0.03 | 0.07 | ok |
| vfs_read_count | 0 | 59.60 | n/a | n/a | 347574.27 | n/a | 0.03 | n/a | no eligible directive sites |
| tcp_connect | 1 | 947.26 | 947.81 | 0.999x | 18.61 | 18.68 | 0.03 | 0.00 | ok |

## Comparison

- open_latency: avg_ns_delta=-16.93%, ops_delta=1.13%, cpu_delta=-50.00%
- exec_trace: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- scheduler_latency: avg_ns_delta=2.24%, ops_delta=-4.22%, cpu_delta=100.00%
- vfs_read_count: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcp_connect: avg_ns_delta=0.06%, ops_delta=0.37%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.

