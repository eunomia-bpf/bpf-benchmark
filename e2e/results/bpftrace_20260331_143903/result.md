# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T14:45:33.993402+00:00`
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
| tcplife | 10 | 856.47 | 614.50 | 1.394x | 21.07 | 22.83 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 267.94 | 279.91 | 0.957x | 278163.20 | 291431.28 | 0.00 | 0.00 | ok |
| runqlat | 7 | 136.05 | 134.68 | 1.010x | 55.92 | 57.58 | 0.03 | 0.00 | ok |
| tcpretrans | 5 | 9133.21 | 9635.68 | 0.948x | 2.22 | 2.39 | 0.03 | 0.07 | ok |
| capable | 6 | 110.08 | 109.70 | 1.004x | 368.28 | 94.46 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.69 | 33.29 | 1.012x | 51281.83 | 51865.70 | 0.07 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-28.25%, ops_delta=8.31%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=4.47%, ops_delta=4.77%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.00%, ops_delta=2.97%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=5.50%, ops_delta=7.53%, cpu_delta=100.00%
- capable: avg_ns_delta=-0.35%, ops_delta=-74.35%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-1.21%, ops_delta=1.14%, cpu_delta=-50.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

