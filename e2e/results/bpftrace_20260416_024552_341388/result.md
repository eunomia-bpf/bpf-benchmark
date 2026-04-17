# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-16T02:52:12.024040+00:00`
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
- Geomean speedup: `0.812x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 273.12 | 365.90 | 0.746x | 451.76 | 380.05 | 0.03 | 0.00 | ok |
| biosnoop | 18 | 199.40 | 265.31 | 0.752x | 916269.66 | 719345.38 | 0.00 | 0.00 | ok |
| runqlat | 13 | 125.82 | 122.99 | 1.023x | 69.31 | 68.84 | 0.00 | 0.07 | ok |
| tcpretrans | 42 | 10846.50 | 14139.88 | 0.767x | 1.54 | 1.51 | 0.07 | 0.03 | ok |
| capable | 244 | 97.48 | 94.84 | 1.028x | 2624.41 | 2635.07 | 0.00 | 0.00 | ok |
| vfsstat | 13 | 115.93 | 183.13 | 0.633x | 75.00 | 71.54 | 0.17 | 0.07 | ok |

## Comparison

- tcplife: avg_ns_delta=33.97%, ops_delta=-15.87%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=33.05%, ops_delta=-21.49%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-2.25%, ops_delta=-0.68%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=30.36%, ops_delta=-1.53%, cpu_delta=-50.00%
- capable: avg_ns_delta=-2.71%, ops_delta=0.41%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=57.97%, ops_delta=-4.61%, cpu_delta=-60.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

