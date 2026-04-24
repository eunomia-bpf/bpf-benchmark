# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-24T02:53:40.201021+00:00`
- Mode: `smoke`
- Duration per phase: `5s`
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
- Geomean speedup: `1.001x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 571.10 | 626.49 | 0.912x | 396.51 | 374.34 | 0.80 | 0.80 | ok |
| biosnoop | 5 | 291.02 | 272.26 | 1.069x | 846380.09 | 889983.77 | 82.00 | 85.20 | ok |
| runqlat | 7 | 138.66 | 138.99 | 0.998x | 65.83 | 65.00 | 0.00 | 0.00 | ok |
| tcpretrans | 5 | 10482.73 | 9334.84 | 1.123x | 0.49 | 0.49 | 0.00 | 0.00 | ok |
| capable | 6 | 125.29 | 122.91 | 1.019x | 2392.27 | 2397.84 | 8.20 | 7.97 | ok |
| vfsstat | 0 | 139.62 | 154.06 | 0.906x | 66.91 | 70.96 | 0.00 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=9.70%, ops_delta=-5.59%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=-6.44%, ops_delta=5.15%, cpu_delta=3.90%
- runqlat: avg_ns_delta=0.24%, ops_delta=-1.27%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=-10.95%, ops_delta=-0.08%, cpu_delta=n/a%
- capable: avg_ns_delta=-1.90%, ops_delta=0.23%, cpu_delta=-2.77%
- vfsstat: avg_ns_delta=10.34%, ops_delta=6.06%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

