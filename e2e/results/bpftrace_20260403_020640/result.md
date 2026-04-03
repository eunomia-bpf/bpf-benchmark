# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-03T02:13:18.955249+00:00`
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
- Eligible-site scripts: `4`
- Aggregate sites: `12` (cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `0.966x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 777.98 | 751.25 | 1.036x | 23.53 | 23.11 | 0.03 | 0.00 | ok |
| biosnoop | 1 | 265.37 | 255.28 | 1.040x | 303115.17 | 281653.65 | 0.03 | 0.00 | ok |
| runqlat | 7 | 139.63 | 136.34 | 1.024x | 54.53 | 54.42 | 0.00 | 0.03 | ok |
| tcpretrans | 2 | 6305.60 | 8406.75 | 0.750x | 1.91 | 2.52 | 0.03 | 0.03 | ok |
| capable | 0 | 110.68 | 110.70 | 1.000x | 309.64 | 119.45 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.42 | 33.93 | 0.985x | 52859.11 | 52696.30 | 0.03 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-3.44%, ops_delta=-1.76%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-3.80%, ops_delta=-7.08%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=-2.35%, ops_delta=-0.20%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=33.32%, ops_delta=31.92%, cpu_delta=0.00%
- capable: avg_ns_delta=0.02%, ops_delta=-61.42%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=1.53%, ops_delta=-0.31%, cpu_delta=-0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

