# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-09T07:33:52.805172+00:00`
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
- Geomean speedup: `1.072x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 1333.61 | 909.83 | 1.466x | 11.44 | 12.43 | 0.03 | 0.03 | ok |
| biosnoop | 5 | 207.29 | 208.75 | 0.993x | 216395.03 | 186154.56 | 0.00 | 0.00 | ok |
| runqlat | 7 | 126.10 | 126.88 | 0.994x | 40.31 | 42.53 | 0.00 | 0.00 | ok |
| tcpretrans | 5 | 8616.04 | 8734.94 | 0.986x | 1.59 | 1.30 | 0.03 | 0.07 | ok |
| capable | 6 | 112.14 | 105.79 | 1.060x | 1273.90 | 1320.50 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 34.64 | 34.52 | 1.003x | 52484.51 | 52826.74 | 0.03 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-31.78%, ops_delta=8.66%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=0.71%, ops_delta=-13.97%, cpu_delta=n/a%
- runqlat: avg_ns_delta=0.62%, ops_delta=5.51%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=1.38%, ops_delta=-18.23%, cpu_delta=100.00%
- capable: avg_ns_delta=-5.67%, ops_delta=3.66%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-0.33%, ops_delta=0.65%, cpu_delta=0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

