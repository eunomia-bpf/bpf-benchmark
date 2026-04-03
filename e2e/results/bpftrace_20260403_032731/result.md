# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-03T03:34:07.379134+00:00`
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
- Aggregate sites: `12` (cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.047x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 810.74 | 670.61 | 1.209x | 21.86 | 21.57 | 0.03 | 0.00 | ok |
| biosnoop | 1 | 245.11 | 250.49 | 0.979x | 315425.37 | 289748.70 | 0.00 | 0.00 | ok |
| runqlat | 7 | 139.03 | 136.85 | 1.016x | 54.04 | 56.32 | 0.00 | 0.03 | ok |
| tcpretrans | 2 | 7565.48 | 7065.51 | 1.071x | 2.36 | 2.53 | 0.03 | 0.03 | ok |
| capable | 0 | 112.05 | 112.08 | 1.000x | 674.65 | 438.22 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.56 | 32.79 | 1.023x | 51342.49 | 52594.48 | 0.03 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-17.28%, ops_delta=-1.32%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=2.20%, ops_delta=-8.14%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.57%, ops_delta=4.20%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=-6.61%, ops_delta=7.14%, cpu_delta=-0.00%
- capable: avg_ns_delta=0.03%, ops_delta=-35.05%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-2.29%, ops_delta=2.44%, cpu_delta=0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

