# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-10T03:01:13.300777+00:00`
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
- Geomean speedup: `1.037x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 1049.39 | 876.60 | 1.197x | 26.83 | 26.73 | 0.10 | 0.00 | ok |
| biosnoop | 5 | 256.85 | 266.12 | 0.965x | 385948.15 | 373115.95 | 0.00 | 0.00 | ok |
| runqlat | 7 | 150.18 | 149.03 | 1.008x | 19.56 | 19.01 | 0.00 | 0.03 | ok |
| tcpretrans | 5 | 13001.50 | 9978.62 | 1.303x | 1.69 | 1.55 | 0.00 | 0.03 | ok |
| capable | 6 | 141.15 | 120.37 | 1.173x | 938.81 | 1129.94 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 76.04 | 108.99 | 0.698x | 81.64 | 75.48 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-16.47%, ops_delta=-0.36%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=3.61%, ops_delta=-3.32%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.77%, ops_delta=-2.81%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=-23.25%, ops_delta=-8.15%, cpu_delta=n/a%
- capable: avg_ns_delta=-14.72%, ops_delta=20.36%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=43.32%, ops_delta=-7.55%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

