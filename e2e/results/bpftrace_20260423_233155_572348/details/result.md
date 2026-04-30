# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-23T23:39:37.166276+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features:`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts in suite: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with applied sites: `5`
- Aggregate applied sites: `25` (map_inline=1, const_prop=8, dce=3, wide_mem=13)
- Geomean speedup: `1.050x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 576.97 | 561.07 | 1.028x | 401.57 | 407.39 | 0.83 | 0.73 | ok |
| biosnoop | 5 | 253.69 | 250.64 | 1.012x | 953501.83 | 965220.09 | 87.30 | 87.53 | ok |
| runqlat | 7 | 134.49 | 134.57 | 0.999x | 64.65 | 63.51 | 0.03 | 0.07 | ok |
| tcpretrans | 5 | 11277.49 | 10614.99 | 1.062x | 0.40 | 0.40 | 0.03 | 0.07 | ok |
| capable | 6 | 120.24 | 120.31 | 0.999x | 2386.44 | 2380.07 | 8.13 | 8.10 | ok |
| vfsstat | 0 | 146.40 | 120.47 | 1.215x | 76.07 | 77.80 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-2.76%, ops_delta=1.45%, cpu_delta=-12.00%
- biosnoop: avg_ns_delta=-1.20%, ops_delta=1.23%, cpu_delta=0.27%
- runqlat: avg_ns_delta=0.05%, ops_delta=-1.76%, cpu_delta=100.00%
- tcpretrans: avg_ns_delta=-5.87%, ops_delta=0.05%, cpu_delta=100.00%
- capable: avg_ns_delta=0.06%, ops_delta=-0.27%, cpu_delta=-0.38%
- vfsstat: avg_ns_delta=-17.71%, ops_delta=2.28%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

