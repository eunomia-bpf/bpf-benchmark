# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-03T20:39:35.002599+00:00`
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
- Geomean speedup: `1.030x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 605.59 | 472.32 | 1.282x | 19.26 | 21.18 | 0.00 | 0.00 | ok |
| biosnoop | 5 | 239.93 | 202.04 | 1.188x | 352587.03 | 334223.04 | 0.00 | 0.00 | ok |
| runqlat | 7 | 128.56 | 132.32 | 0.972x | 59.11 | 53.31 | 0.00 | 0.00 | ok |
| tcpretrans | 5 | 5516.69 | 6964.74 | 0.792x | 2.52 | 2.51 | 0.00 | 0.07 | ok |
| capable | 6 | 109.33 | 108.47 | 1.008x | 209.11 | 1067.62 | 0.03 | 0.00 | ok |
| vfsstat | 0 | 32.69 | 32.29 | 1.012x | 53693.20 | 53829.33 | 0.03 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-22.01%, ops_delta=9.98%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=-15.79%, ops_delta=-5.21%, cpu_delta=n/a%
- runqlat: avg_ns_delta=2.93%, ops_delta=-9.82%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=26.25%, ops_delta=-0.72%, cpu_delta=n/a%
- capable: avg_ns_delta=-0.79%, ops_delta=410.55%, cpu_delta=-100.00%
- vfsstat: avg_ns_delta=-1.21%, ops_delta=0.25%, cpu_delta=-0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

