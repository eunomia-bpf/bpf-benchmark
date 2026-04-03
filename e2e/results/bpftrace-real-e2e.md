# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-03T04:55:39.775240+00:00`
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
- Geomean speedup: `1.074x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 647.18 | 524.75 | 1.233x | 22.39 | 21.82 | 0.00 | 0.00 | ok |
| biosnoop | 5 | 243.77 | 243.39 | 1.002x | 299321.86 | 332983.20 | 0.00 | 0.00 | ok |
| runqlat | 7 | 134.49 | 132.67 | 1.014x | 54.83 | 55.84 | 0.00 | 0.03 | ok |
| tcpretrans | 5 | 7275.50 | 5787.59 | 1.257x | 2.46 | 2.41 | 0.00 | 0.07 | ok |
| capable | 6 | 112.30 | 111.98 | 1.003x | 796.59 | 590.37 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.80 | 34.69 | 0.974x | 52444.24 | 52038.43 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-18.92%, ops_delta=-2.53%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=-0.16%, ops_delta=11.25%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.35%, ops_delta=1.84%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=-20.45%, ops_delta=-2.02%, cpu_delta=n/a%
- capable: avg_ns_delta=-0.29%, ops_delta=-25.89%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=2.64%, ops_delta=-0.77%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

