# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-23T19:46:42.768075+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features:`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts in suite: `6`
- Baseline successes: `6`
- ReJIT successes: `5`
- Scripts with applied sites: `5`
- Aggregate applied sites: `25` (map_inline=1, const_prop=8, dce=3, wide_mem=13)
- Geomean speedup: `1.035x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 527.23 | 562.37 | 0.938x | 428.86 | 407.43 | 0.73 | 0.73 | ok |
| biosnoop | 5 | 245.31 | 249.38 | 0.984x | 955207.32 | 950065.33 | 86.43 | 86.60 | ok |
| runqlat | 7 | 135.55 | 134.58 | 1.007x | 64.44 | 63.56 | 0.03 | 0.00 | ok |
| tcpretrans | 5 | 10325.80 | 8111.27 | 1.273x | 0.40 | 0.40 | 0.03 | 0.07 | ok |
| capable | 6 | 123.88 | 123.08 | 1.006x | 2384.82 | 2375.13 | 8.20 | 7.90 | ok |
| vfsstat | 0 | 162.92 | n/a | n/a | 72.83 | n/a | 0.07 | n/a | ok |

## Comparison

- tcplife: avg_ns_delta=6.66%, ops_delta=-5.00%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=1.66%, ops_delta=-0.54%, cpu_delta=0.20%
- runqlat: avg_ns_delta=-0.71%, ops_delta=-1.36%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=-21.45%, ops_delta=0.07%, cpu_delta=100.00%
- capable: avg_ns_delta=-0.64%, ops_delta=-0.41%, cpu_delta=-3.65%
- vfsstat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

