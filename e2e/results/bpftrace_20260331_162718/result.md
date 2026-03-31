# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T16:33:51.992618+00:00`
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
- Geomean speedup: `1.066x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 740.28 | 621.82 | 1.191x | 22.38 | 21.21 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 256.58 | 200.57 | 1.279x | 312085.53 | 292851.99 | 0.03 | 0.00 | ok |
| runqlat | 7 | 136.57 | 134.02 | 1.019x | 53.23 | 56.81 | 0.00 | 0.00 | ok |
| tcpretrans | 5 | 7762.70 | 8120.42 | 0.956x | 2.92 | 2.23 | 0.07 | 0.00 | ok |
| capable | 6 | 109.96 | 110.25 | 0.997x | 642.45 | 430.01 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.39 | 33.62 | 0.993x | 53210.53 | 52709.63 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-16.00%, ops_delta=-5.24%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-21.83%, ops_delta=-6.16%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=-1.87%, ops_delta=6.72%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=4.61%, ops_delta=-23.65%, cpu_delta=-100.00%
- capable: avg_ns_delta=0.27%, ops_delta=-33.07%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=0.67%, ops_delta=-0.94%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

