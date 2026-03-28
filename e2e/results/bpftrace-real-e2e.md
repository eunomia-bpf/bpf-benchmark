# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-28T18:53:28.152101+00:00`
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
- Geomean speedup: `1.037x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 8 | 1072.90 | 850.22 | 1.262x | 21.89 | 24.22 | 0.03 | 0.00 | ok |
| biosnoop | 4 | 3758.27 | 4022.94 | 0.934x | 14129.56 | 14128.85 | 0.00 | 0.00 | ok |
| runqlat | 0 | 193.52 | 189.15 | 1.023x | 61.21 | 62.10 | 0.03 | 0.03 | ok |
| tcpretrans | 3 | n/a | n/a | n/a | 19.69 | 21.95 | 0.03 | 0.00 | ok |
| capable | 6 | 252.16 | 255.34 | 0.988x | 611.56 | 231.07 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 34.94 | 34.73 | 1.006x | 13534.61 | 14038.38 | 0.00 | 0.07 | ok |

## Comparison

- tcplife: avg_ns_delta=-20.76%, ops_delta=10.66%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=7.04%, ops_delta=-0.00%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-2.26%, ops_delta=1.46%, cpu_delta=0.00%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=11.48%, cpu_delta=-100.00%
- capable: avg_ns_delta=1.26%, ops_delta=-62.22%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-0.62%, ops_delta=3.72%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

