# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T01:07:53.538715+00:00`
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
- Geomean speedup: `0.999x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 610.35 | 557.39 | 1.095x | 22.41 | 22.46 | 0.00 | 0.00 | ok |
| biosnoop | 5 | 291.42 | 246.34 | 1.183x | 335713.33 | 286518.04 | 0.00 | 0.00 | ok |
| runqlat | 7 | 139.10 | 136.00 | 1.023x | 55.15 | 56.37 | 0.03 | 0.00 | ok |
| tcpretrans | 5 | 5519.05 | 7313.04 | 0.755x | 0.60 | 0.66 | 0.07 | 0.03 | ok |
| capable | 6 | 109.96 | 109.23 | 1.007x | 1078.91 | 875.15 | 0.03 | 0.00 | ok |
| vfsstat | 0 | 32.31 | 32.62 | 0.990x | 53421.66 | 53552.29 | 0.07 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-8.68%, ops_delta=0.18%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=-15.47%, ops_delta=-14.65%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-2.23%, ops_delta=2.22%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=32.51%, ops_delta=10.84%, cpu_delta=-50.00%
- capable: avg_ns_delta=-0.66%, ops_delta=-18.89%, cpu_delta=-100.00%
- vfsstat: avg_ns_delta=0.99%, ops_delta=0.24%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

