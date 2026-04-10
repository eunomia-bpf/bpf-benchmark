# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-10T03:26:36.349402+00:00`
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
- Geomean speedup: `0.881x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 782.40 | 668.13 | 1.171x | 26.99 | 27.32 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 279.12 | 261.05 | 1.069x | 335435.51 | 343855.91 | 0.00 | 0.00 | ok |
| runqlat | 7 | 145.96 | 157.23 | 0.928x | 17.74 | 19.07 | 0.00 | 0.03 | ok |
| tcpretrans | 5 | 6371.00 | 29319.00 | 0.217x | 1.78 | 1.52 | 0.03 | 0.07 | ok |
| capable | 6 | 357.68 | 140.68 | 2.543x | 177.83 | 882.82 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 64.33 | 88.45 | 0.727x | 33.02 | 55.39 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-14.61%, ops_delta=1.23%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-6.47%, ops_delta=2.51%, cpu_delta=n/a%
- runqlat: avg_ns_delta=7.72%, ops_delta=7.52%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=360.19%, ops_delta=-14.79%, cpu_delta=100.00%
- capable: avg_ns_delta=-60.67%, ops_delta=396.45%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=37.48%, ops_delta=67.75%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

