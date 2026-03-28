# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-28T21:58:07.837079+00:00`
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
- Geomean speedup: `1.035x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 8 | 1087.03 | 921.53 | 1.180x | 21.81 | 22.00 | 0.07 | 0.00 | ok |
| biosnoop | 4 | 4116.73 | 4207.60 | 0.978x | 13515.18 | 13668.94 | 0.03 | 0.00 | ok |
| runqlat | 0 | 187.90 | 187.99 | 1.000x | 61.12 | 61.49 | 0.07 | 0.00 | ok |
| tcpretrans | 3 | n/a | n/a | n/a | 21.48 | 21.86 | 0.03 | 0.00 | ok |
| capable | 6 | 253.78 | 246.98 | 1.028x | 121.77 | 377.18 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 37.03 | 36.87 | 1.004x | 13079.11 | 12696.76 | 0.03 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-15.23%, ops_delta=0.85%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=2.21%, ops_delta=1.14%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=0.05%, ops_delta=0.60%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=1.77%, cpu_delta=-100.00%
- capable: avg_ns_delta=-2.68%, ops_delta=209.74%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-0.43%, ops_delta=-2.92%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

