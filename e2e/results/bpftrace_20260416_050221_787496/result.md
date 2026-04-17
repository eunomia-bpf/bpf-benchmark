# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-16T05:08:42.461931+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- bpftrace: `bpftrace v0.25.0`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features:`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with applied sites: `6`
- Aggregate applied sites: `363` (map_inline=50, const_prop=90, dce=83, wide_mem=137, bulk_memory=3)
- Geomean speedup: `0.832x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 282.73 | 271.67 | 1.041x | 452.40 | 453.65 | 0.07 | 0.00 | ok |
| biosnoop | 18 | 175.69 | 212.25 | 0.828x | 1057810.71 | 896053.24 | 0.00 | 0.00 | ok |
| runqlat | 13 | 126.39 | 125.13 | 1.010x | 69.46 | 68.55 | 0.03 | 0.03 | ok |
| tcpretrans | 42 | 9559.00 | 11185.27 | 0.855x | 1.62 | 1.60 | 0.07 | 0.03 | ok |
| capable | 244 | 97.38 | 93.77 | 1.039x | 2611.69 | 2626.11 | 0.00 | 0.00 | ok |
| vfsstat | 13 | 61.43 | 143.31 | 0.429x | 75.76 | 75.98 | 0.17 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-3.91%, ops_delta=0.28%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=20.81%, ops_delta=-15.29%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.00%, ops_delta=-1.31%, cpu_delta=-0.00%
- tcpretrans: avg_ns_delta=17.01%, ops_delta=-0.80%, cpu_delta=-50.00%
- capable: avg_ns_delta=-3.71%, ops_delta=0.55%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=133.27%, ops_delta=0.29%, cpu_delta=-80.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

