# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-10T02:38:32.532354+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with applied sites: `5`
- Aggregate applied sites: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21)
- Geomean speedup: `1.076x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 885.06 | 797.14 | 1.110x | 25.23 | 27.33 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 288.17 | 267.95 | 1.075x | 354806.11 | 338721.87 | 0.00 | 0.00 | ok |
| runqlat | 7 | 152.41 | 152.32 | 1.001x | 17.78 | 17.12 | 0.00 | 0.07 | ok |
| tcpretrans | 5 | 9335.80 | 9402.78 | 0.993x | 1.62 | 1.54 | 0.07 | 0.03 | ok |
| capable | 6 | 112.90 | 113.54 | 0.994x | 1162.09 | 1146.80 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 116.44 | 88.54 | 1.315x | 63.86 | 72.65 | 0.07 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-9.93%, ops_delta=8.35%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-7.02%, ops_delta=-4.53%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.06%, ops_delta=-3.69%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=0.72%, ops_delta=-4.59%, cpu_delta=-50.00%
- capable: avg_ns_delta=0.56%, ops_delta=-1.32%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-23.96%, ops_delta=13.77%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

