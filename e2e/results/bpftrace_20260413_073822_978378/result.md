# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-13T07:45:17.391039+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- bpftrace: `bpftrace v0.25.0-be6ee45`
- bpftool: `bpftool v7.5.0
using libbpf v1.5
features: llvm, skeletons`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with applied sites: `6`
- Aggregate applied sites: `360` (map_inline=47, const_prop=90, dce=83, wide_mem=137, bulk_memory=3)
- Geomean speedup: `1.037x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 1147.23 | 941.01 | 1.219x | 10.79 | 11.39 | 0.07 | 0.00 | ok |
| biosnoop | 18 | 190.08 | 206.69 | 0.920x | 59518.24 | 56658.97 | 0.00 | 0.00 | ok |
| runqlat | 13 | 137.10 | 135.93 | 1.009x | 15.97 | 16.40 | 0.03 | 0.03 | ok |
| tcpretrans | 42 | 11532.60 | 10802.67 | 1.068x | 1.52 | 1.72 | 0.03 | 0.03 | ok |
| capable | 244 | 109.95 | 100.44 | 1.095x | 4610.67 | 4787.66 | 0.00 | 0.00 | ok |
| vfsstat | 10 | 145.98 | 155.56 | 0.938x | 3.53 | 44.74 | 0.07 | 0.07 | ok |

## Comparison

- tcplife: avg_ns_delta=-17.98%, ops_delta=5.55%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=8.74%, ops_delta=-4.80%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.85%, ops_delta=2.66%, cpu_delta=0.00%
- tcpretrans: avg_ns_delta=-6.33%, ops_delta=12.98%, cpu_delta=0.04%
- capable: avg_ns_delta=-8.65%, ops_delta=3.84%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=6.57%, ops_delta=1167.08%, cpu_delta=-0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

