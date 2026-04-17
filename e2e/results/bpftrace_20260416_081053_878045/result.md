# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-16T08:17:18.677973+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- bpftrace: `bpftrace v0.25.0`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features:`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with applied sites: `6`
- Aggregate applied sites: `363` (map_inline=50, const_prop=90, dce=83, wide_mem=137, bulk_memory=3)
- Geomean speedup: `1.015x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 1349.71 | 1175.97 | 1.148x | 137.40 | 141.84 | 0.17 | 0.00 | ok |
| biosnoop | 18 | 370.84 | 360.05 | 1.030x | 286718.45 | 289469.56 | 0.07 | 0.00 | ok |
| runqlat | 13 | 428.77 | 424.25 | 1.011x | 14.89 | 14.81 | 0.03 | 0.07 | ok |
| tcpretrans | 42 | 14457.62 | 14311.87 | 1.010x | 0.40 | 0.40 | 0.07 | 0.10 | ok |
| capable | 244 | 330.44 | 303.11 | 1.090x | 335.91 | 331.09 | 0.03 | 0.00 | ok |
| vfsstat | 13 | 353.72 | 425.27 | 0.832x | 353.42 | 354.44 | 0.57 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-12.87%, ops_delta=3.23%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-2.91%, ops_delta=0.96%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=-1.06%, ops_delta=-0.54%, cpu_delta=100.00%
- tcpretrans: avg_ns_delta=-1.01%, ops_delta=0.00%, cpu_delta=50.00%
- capable: avg_ns_delta=-8.27%, ops_delta=-1.44%, cpu_delta=-100.00%
- vfsstat: avg_ns_delta=20.23%, ops_delta=0.29%, cpu_delta=-94.12%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

