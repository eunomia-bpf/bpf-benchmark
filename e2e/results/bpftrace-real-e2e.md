# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-12T23:28:12.307982+00:00`
- Mode: `full`
- Duration per phase: `5s`
- Host kernel: `6.15.11-061511-generic`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`

## Summary

- Scripts selected: `2`
- Baseline successes: `2`
- ReJIT successes: `0`
- Eligible-site scripts: `2`
- Aggregate sites: `12` (cmov=12, wide=0, rotate=0, lea=0)
- Geomean speedup: `n/a`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| open_latency | 6 | 196.67 | n/a | n/a | 43191.06 | n/a | 0.00 | n/a | policy filtered all live sites |
| scheduler_latency | 6 | 145.22 | n/a | n/a | 41.75 | n/a | 0.00 | n/a | policy filtered all live sites |

## Comparison

- open_latency: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- scheduler_latency: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.

