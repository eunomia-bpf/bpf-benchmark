# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-23T13:31:58.980303+00:00`
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
- Eligible-site scripts: `0`
- Aggregate sites: `0` (cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.568x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 0 | 1142.84 | 785.41 | 1.455x | 28.81 | 29.32 | 0.10 | 0.00 | ok |
| biosnoop | 0 | n/a | n/a | n/a | 467148.37 | 504738.87 | 0.03 | 0.03 | ok |
| runqlat | 0 | 189.02 | 189.30 | 0.999x | 81.90 | 82.28 | 0.00 | 0.00 | ok |
| tcpretrans | 0 | n/a | n/a | n/a | 28.76 | 28.53 | 0.00 | 0.03 | ok |
| capable | 0 | 982.65 | 235.54 | 4.172x | 261240.11 | 246274.22 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 25.13 | 25.22 | 0.997x | 444197.32 | 437419.99 | 0.07 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-31.28%, ops_delta=1.79%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=n/a%, ops_delta=8.05%, cpu_delta=-0.00%
- runqlat: avg_ns_delta=0.15%, ops_delta=0.47%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=-0.78%, cpu_delta=n/a%
- capable: avg_ns_delta=-76.03%, ops_delta=-5.73%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=0.35%, ops_delta=-1.53%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.

