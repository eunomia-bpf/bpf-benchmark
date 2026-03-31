# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T15:51:49.130858+00:00`
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
- Geomean speedup: `1.092x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 692.64 | 429.96 | 1.611x | 19.87 | 23.17 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 250.23 | 245.81 | 1.018x | 296564.08 | 303030.45 | 0.00 | 0.00 | ok |
| runqlat | 7 | 141.42 | 137.97 | 1.025x | 53.47 | 55.76 | 0.03 | 0.00 | ok |
| tcpretrans | 5 | 7621.65 | 7735.70 | 0.985x | 2.44 | 2.66 | 0.00 | 0.07 | ok |
| capable | 6 | 111.35 | 110.96 | 1.004x | 185.61 | 1023.41 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 34.72 | 34.02 | 1.020x | 52144.61 | 52699.32 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-37.92%, ops_delta=16.62%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-1.77%, ops_delta=2.18%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-2.43%, ops_delta=4.28%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=1.50%, ops_delta=9.11%, cpu_delta=n/a%
- capable: avg_ns_delta=-0.35%, ops_delta=451.37%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-2.00%, ops_delta=1.06%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

