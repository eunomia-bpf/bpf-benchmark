# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-23T08:43:42.948531+00:00`
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
- Baseline successes: `1`
- ReJIT successes: `1`
- Eligible-site scripts: `0`
- Aggregate sites: `0` (cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `4.721x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | bpftrace did not attach any programs |
| biosnoop | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | bpftrace did not attach any programs |
| runqlat | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | bpftrace did not attach any programs |
| tcpretrans | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | bpftrace did not attach any programs |
| capable | 0 | 1075.94 | 227.88 | 4.721x | 396930.35 | 463429.54 | 0.00 | 0.00 | ok |
| vfsstat | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | bpftrace did not attach any programs |

## Comparison

- tcplife: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- runqlat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- capable: avg_ns_delta=-78.82%, ops_delta=16.75%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no eligible directive sites are marked with `n/a` ReJIT fields instead of a fake comparison.

