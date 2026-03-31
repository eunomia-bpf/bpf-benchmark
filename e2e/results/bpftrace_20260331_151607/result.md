# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T15:22:39.206326+00:00`
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
- Eligible-site scripts: `5`
- Aggregate sites: `33` (cmov=0, wide=21, rotate=0, lea=0)
- Geomean speedup: `1.044x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 594.23 | 457.81 | 1.298x | 20.48 | 21.29 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 231.32 | 264.70 | 0.874x | 307198.37 | 300553.00 | 0.00 | 0.00 | ok |
| runqlat | 7 | 135.42 | 134.26 | 1.009x | 57.13 | 56.25 | 0.03 | 0.03 | ok |
| tcpretrans | 5 | 7844.14 | 6876.74 | 1.141x | 2.32 | 2.08 | 0.07 | 0.00 | ok |
| capable | 6 | 109.44 | 110.16 | 0.993x | 414.50 | 246.27 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 32.87 | 32.91 | 0.999x | 53209.63 | 52995.48 | 0.03 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-22.96%, ops_delta=3.96%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=14.43%, ops_delta=-2.16%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.86%, ops_delta=-1.54%, cpu_delta=0.00%
- tcpretrans: avg_ns_delta=-12.33%, ops_delta=-10.30%, cpu_delta=-100.00%
- capable: avg_ns_delta=0.66%, ops_delta=-40.59%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=0.11%, ops_delta=-0.40%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

