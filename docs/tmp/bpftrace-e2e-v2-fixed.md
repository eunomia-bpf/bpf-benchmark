# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-12T21:08:52.584223+00:00`
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
- ReJIT successes: `0`
- Eligible-site scripts: `3`
- Aggregate sites: `13` (cmov=12, wide=0, rotate=0, lea=0)
- Geomean speedup: `n/a`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| open_latency | 6 | 233.29 | n/a | n/a | 95489.31 | n/a | 0.03 | n/a | BPF_PROG_JIT_RECOMPILE did not apply |
| exec_trace | 0 | 2100.67 | n/a | n/a | 708.79 | n/a | 0.03 | n/a | no eligible directive sites |
| scheduler_latency | 6 | 147.32 | n/a | n/a | 42.53 | n/a | 0.03 | n/a | BPF_PROG_JIT_RECOMPILE did not apply |
| vfs_read_count | 0 | 57.65 | n/a | n/a | 360769.65 | n/a | 0.03 | n/a | no eligible directive sites |
| tcp_connect | 1 | 519.95 | n/a | n/a | 20.06 | n/a | 0.03 | n/a | BPF_PROG_JIT_RECOMPILE did not apply |

## Comparison

- open_latency: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- exec_trace: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- scheduler_latency: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- vfs_read_count: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcp_connect: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.

