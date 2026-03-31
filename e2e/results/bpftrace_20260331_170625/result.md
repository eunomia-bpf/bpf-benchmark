# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T17:12:56.987501+00:00`
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
- Geomean speedup: `1.087x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 734.29 | 549.74 | 1.336x | 21.87 | 21.40 | 0.00 | 0.00 | ok |
| biosnoop | 5 | 212.57 | 230.03 | 0.924x | 369849.73 | 338761.71 | 0.00 | 0.00 | ok |
| runqlat | 7 | 136.01 | 132.43 | 1.027x | 54.60 | 55.45 | 0.00 | 0.00 | ok |
| tcpretrans | 5 | 8198.05 | 6462.66 | 1.269x | 2.86 | 2.49 | 0.03 | 0.07 | ok |
| capable | 6 | 111.01 | 109.41 | 1.015x | 621.97 | 382.07 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.43 | 33.05 | 1.012x | 52635.38 | 53855.59 | 0.00 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-25.13%, ops_delta=-2.15%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=8.21%, ops_delta=-8.41%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-2.63%, ops_delta=1.56%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=-21.17%, ops_delta=-12.78%, cpu_delta=100.00%
- capable: avg_ns_delta=-1.45%, ops_delta=-38.57%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-1.16%, ops_delta=2.32%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

