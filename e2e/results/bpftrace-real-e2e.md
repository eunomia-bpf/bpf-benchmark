# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-29T01:53:15.402563+00:00`
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
- Aggregate sites: `22` (cmov=0, wide=21, rotate=0, lea=0)
- Geomean speedup: `1.037x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 8 | 1392.03 | 1462.92 | 0.952x | 21.07 | 12.62 | 0.13 | 0.00 | ok |
| biosnoop | 5 | 8226.75 | 6990.53 | 1.177x | 9330.44 | 10427.45 | 0.07 | 0.03 | ok |
| runqlat | 0 | 197.75 | 186.32 | 1.061x | 55.46 | 58.14 | 0.07 | 0.00 | ok |
| tcpretrans | 3 | n/a | n/a | n/a | 21.52 | 24.41 | 0.03 | 0.03 | ok |
| capable | 6 | 311.84 | 300.57 | 1.038x | 32.87 | 230.01 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 37.09 | 38.18 | 0.972x | 14816.57 | 14101.33 | 0.03 | 0.07 | ok |

## Comparison

- tcplife: avg_ns_delta=5.09%, ops_delta=-40.12%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-15.03%, ops_delta=11.76%, cpu_delta=-50.00%
- runqlat: avg_ns_delta=-5.78%, ops_delta=4.85%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=13.44%, cpu_delta=0.00%
- capable: avg_ns_delta=-3.61%, ops_delta=599.83%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=2.93%, ops_delta=-4.83%, cpu_delta=100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

