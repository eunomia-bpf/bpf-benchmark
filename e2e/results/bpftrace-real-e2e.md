# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-29T08:46:51.733840+00:00`
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
- Geomean speedup: `1.140x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 8 | 988.14 | 508.97 | 1.941x | 19.80 | 26.96 | 0.10 | 0.00 | ok |
| biosnoop | 5 | 3639.07 | 3782.60 | 0.962x | 12939.53 | 13248.63 | 0.00 | 0.00 | ok |
| runqlat | 0 | 186.26 | 189.78 | 0.981x | 61.53 | 60.74 | 0.00 | 0.07 | ok |
| tcpretrans | 3 | n/a | n/a | n/a | 21.29 | 21.42 | 0.07 | 0.00 | ok |
| capable | 6 | 254.40 | 242.13 | 1.051x | 466.34 | 23.42 | 0.03 | 0.00 | ok |
| vfsstat | 0 | 34.67 | 34.70 | 0.999x | 11401.92 | 12553.50 | 0.03 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-48.49%, ops_delta=36.15%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=3.94%, ops_delta=2.39%, cpu_delta=n/a%
- runqlat: avg_ns_delta=1.89%, ops_delta=-1.28%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=0.64%, cpu_delta=-100.00%
- capable: avg_ns_delta=-4.82%, ops_delta=-94.98%, cpu_delta=-100.00%
- vfsstat: avg_ns_delta=0.09%, ops_delta=10.10%, cpu_delta=-100.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

