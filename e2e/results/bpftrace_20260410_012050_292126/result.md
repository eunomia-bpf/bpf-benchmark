# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-10T01:27:24.264684+00:00`
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
- Geomean speedup: `1.058x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 1146.88 | 737.66 | 1.555x | 20.29 | 22.45 | 0.07 | 0.00 | ok |
| biosnoop | 5 | 257.92 | 256.49 | 1.006x | 322830.38 | 322390.86 | 0.00 | 0.00 | ok |
| runqlat | 7 | 142.98 | 141.84 | 1.008x | 17.35 | 16.56 | 0.03 | 0.03 | ok |
| tcpretrans | 5 | 6800.20 | 6456.73 | 1.053x | 1.47 | 1.39 | 0.00 | 0.03 | ok |
| capable | 6 | 113.47 | 125.22 | 0.906x | 1212.25 | 1053.50 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 110.26 | 118.38 | 0.931x | 79.15 | 73.76 | 0.03 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-35.68%, ops_delta=10.65%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-0.55%, ops_delta=-0.14%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.79%, ops_delta=-4.51%, cpu_delta=-0.00%
- tcpretrans: avg_ns_delta=-5.05%, ops_delta=-5.61%, cpu_delta=n/a%
- capable: avg_ns_delta=10.35%, ops_delta=-13.10%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=7.36%, ops_delta=-6.80%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

