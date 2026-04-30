# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-24T00:29:25.386336+00:00`
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
- Geomean speedup: `1.025x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 619.80 | 689.42 | 0.899x | 370.57 | 333.11 | 0.57 | 0.63 | ok |
| biosnoop | 5 | 248.42 | 253.16 | 0.981x | 914799.14 | 949562.97 | 83.30 | 87.40 | ok |
| runqlat | 7 | 135.64 | 136.22 | 0.996x | 65.05 | 63.92 | 0.03 | 0.00 | ok |
| tcpretrans | 5 | 11531.85 | 10346.87 | 1.115x | 0.40 | 0.40 | 0.07 | 0.00 | ok |
| capable | 6 | 123.77 | 122.28 | 1.012x | 2357.61 | 2366.05 | 8.40 | 8.37 | ok |
| vfsstat | 0 | 264.98 | 227.07 | 1.167x | 73.54 | 80.69 | 0.07 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=11.23%, ops_delta=-10.11%, cpu_delta=11.76%
- biosnoop: avg_ns_delta=1.91%, ops_delta=3.80%, cpu_delta=4.92%
- runqlat: avg_ns_delta=0.43%, ops_delta=-1.74%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=-10.28%, ops_delta=0.03%, cpu_delta=-100.00%
- capable: avg_ns_delta=-1.21%, ops_delta=0.36%, cpu_delta=-0.37%
- vfsstat: avg_ns_delta=-14.31%, ops_delta=9.73%, cpu_delta=-50.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

