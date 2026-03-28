# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-28T21:02:27.973219+00:00`
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
- Aggregate sites: `21` (cmov=0, wide=21, rotate=0, lea=0)
- Geomean speedup: `1.057x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 8 | 937.30 | 761.20 | 1.231x | 20.42 | 21.09 | 0.07 | 0.00 | ok |
| biosnoop | 4 | 3944.31 | 3971.93 | 0.993x | 12315.76 | 14375.33 | 0.07 | 0.00 | ok |
| runqlat | 0 | 192.89 | 186.76 | 1.033x | 60.87 | 61.92 | 0.03 | 0.03 | ok |
| tcpretrans | 3 | n/a | n/a | n/a | 22.29 | 20.65 | 0.00 | 0.03 | ok |
| capable | 6 | 249.66 | 246.72 | 1.012x | 378.71 | 630.14 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 36.22 | 35.03 | 1.034x | 13605.24 | 13783.43 | 0.03 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-18.79%, ops_delta=3.24%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=0.70%, ops_delta=16.72%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=-3.18%, ops_delta=1.73%, cpu_delta=0.00%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=-7.36%, cpu_delta=n/a%
- capable: avg_ns_delta=-1.18%, ops_delta=66.39%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-3.31%, ops_delta=1.31%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

