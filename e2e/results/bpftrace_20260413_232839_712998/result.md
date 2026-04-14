# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-13T23:35:10.514056+00:00`
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
- Geomean speedup: `1.085x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 1072.84 | 749.83 | 1.431x | 11.36 | 11.28 | 0.10 | 0.00 | ok |
| biosnoop | 18 | 168.98 | 159.69 | 1.058x | 59792.85 | 60538.69 | 0.03 | 0.00 | ok |
| runqlat | 13 | 116.61 | 115.64 | 1.008x | 16.93 | 16.65 | 0.00 | 0.03 | ok |
| tcpretrans | 42 | 6151.67 | 6741.00 | 0.913x | 1.62 | 1.42 | 0.00 | 0.07 | ok |
| capable | 244 | 101.23 | 97.83 | 1.035x | 4916.31 | 4865.33 | 0.00 | 0.00 | ok |
| vfsstat | 10 | 78.81 | 69.65 | 1.132x | 74.35 | 63.82 | 0.07 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-30.11%, ops_delta=-0.67%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-5.50%, ops_delta=1.25%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=-0.83%, ops_delta=-1.67%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=9.58%, ops_delta=-12.40%, cpu_delta=n/a%
- capable: avg_ns_delta=-3.35%, ops_delta=-1.04%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-11.63%, ops_delta=-14.17%, cpu_delta=-50.03%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

