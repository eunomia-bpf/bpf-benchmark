# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T17:49:29.774918+00:00`
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
- Geomean speedup: `1.129x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 729.38 | 481.13 | 1.516x | 20.88 | 22.17 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 251.42 | 241.98 | 1.039x | 360141.00 | 385984.99 | 0.00 | 0.00 | ok |
| runqlat | 7 | 133.96 | 132.75 | 1.009x | 57.24 | 54.88 | 0.07 | 0.00 | ok |
| tcpretrans | 5 | 8140.97 | 6313.02 | 1.290x | 2.70 | 2.16 | 0.03 | 0.03 | ok |
| capable | 6 | 108.98 | 108.78 | 1.002x | 154.78 | 945.05 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.83 | 33.50 | 1.010x | 52649.97 | 53217.56 | 0.03 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-34.04%, ops_delta=6.18%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-3.76%, ops_delta=7.18%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.90%, ops_delta=-4.13%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=-22.45%, ops_delta=-20.03%, cpu_delta=0.00%
- capable: avg_ns_delta=-0.18%, ops_delta=510.57%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-0.97%, ops_delta=1.08%, cpu_delta=0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

