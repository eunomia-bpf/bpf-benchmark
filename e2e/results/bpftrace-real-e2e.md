# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-28T14:37:43.148790+00:00`
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
- ReJIT successes: `0`
- Eligible-site scripts: `4`
- Aggregate sites: `21` (cmov=0, wide=21, rotate=0, lea=0)
- Geomean speedup: `n/a`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 8 | 924.48 | n/a | n/a | 23.21 | n/a | 0.07 | n/a | ok |
| biosnoop | 4 | 3943.93 | n/a | n/a | 13620.78 | n/a | 0.03 | n/a | ok |
| runqlat | 0 | 180.07 | n/a | n/a | 61.63 | n/a | 0.03 | n/a | ok |
| tcpretrans | 3 | n/a | n/a | n/a | 21.69 | n/a | 0.03 | n/a | ok |
| capable | 6 | 257.26 | n/a | n/a | 336.14 | n/a | 0.00 | n/a | ok |
| vfsstat | 0 | 35.37 | n/a | n/a | 13133.30 | n/a | 0.03 | n/a | ok |

## Comparison

- tcplife: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- runqlat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- capable: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

