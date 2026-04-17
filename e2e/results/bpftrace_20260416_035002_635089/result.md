# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-16T03:56:23.398922+00:00`
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
- Geomean speedup: `0.883x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 387.38 | 360.85 | 1.074x | 373.04 | 383.97 | 0.03 | 0.00 | ok |
| biosnoop | 18 | 233.25 | 215.84 | 1.081x | 822223.49 | 850960.06 | 0.00 | 0.00 | ok |
| runqlat | 13 | 123.54 | 122.05 | 1.012x | 70.94 | 69.71 | 0.00 | 0.03 | ok |
| tcpretrans | 42 | 10581.67 | 14277.25 | 0.741x | 1.66 | 1.52 | 0.00 | 0.07 | ok |
| capable | 244 | 97.02 | 94.49 | 1.027x | 2645.16 | 2638.40 | 0.00 | 0.00 | ok |
| vfsstat | 13 | 107.12 | 202.46 | 0.529x | 72.71 | 62.70 | 0.20 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-6.85%, ops_delta=2.93%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-7.46%, ops_delta=3.49%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.21%, ops_delta=-1.74%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=34.92%, ops_delta=-8.05%, cpu_delta=n/a%
- capable: avg_ns_delta=-2.60%, ops_delta=-0.26%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=89.00%, ops_delta=-13.77%, cpu_delta=-83.33%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

