# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T03:33:53.729974+00:00`
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
- Geomean speedup: `1.021x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 710.00 | 592.66 | 1.198x | 22.68 | 21.73 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 269.01 | 281.55 | 0.955x | 306926.14 | 318416.95 | 0.00 | 0.00 | ok |
| runqlat | 7 | 141.56 | 135.12 | 1.048x | 54.12 | 56.57 | 0.00 | 0.07 | ok |
| tcpretrans | 5 | 7497.64 | 8070.97 | 0.929x | 2.93 | 2.66 | 0.03 | 0.07 | ok |
| capable | 6 | 109.40 | 108.08 | 1.012x | 812.85 | 586.05 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 34.33 | 34.13 | 1.006x | 51395.65 | 52075.91 | 0.03 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-16.53%, ops_delta=-4.22%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=4.66%, ops_delta=3.74%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-4.55%, ops_delta=4.53%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=7.65%, ops_delta=-9.05%, cpu_delta=100.00%
- capable: avg_ns_delta=-1.21%, ops_delta=-27.90%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-0.56%, ops_delta=1.32%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

