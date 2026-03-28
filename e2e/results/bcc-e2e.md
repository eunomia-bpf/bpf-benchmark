# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-28T14:52:41.601221+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `9`
- Tools with eligible sites: `9`
- Aggregate sites: `3165` (map_inline=183, const_prop=300, dce=2674, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `0.983x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 52 | 1360.82 | 1392.38 | 0.977x | 26.32 | 27.02 | 0.07 | 0.10 | ok |
| biosnoop | 149 | 5705.07 | 5721.13 | 0.997x | 15059.01 | 15394.32 | 0.00 | 0.07 | ok |
| runqlat | 104 | 222.17 | 204.42 | 1.087x | 53.92 | 59.57 | 0.00 | 0.00 | ok |
| syscount | 78 | 68.50 | 68.31 | 1.003x | 7604.24 | 7570.73 | 0.00 | 0.00 | ok |
| execsnoop | 1750 | 1904.80 | 2128.06 | 0.895x | 55.45 | 55.35 | 0.23 | 0.27 | ok |
| opensnoop | 501 | 634.70 | 758.61 | 0.837x | 7537.81 | 7621.79 | 0.07 | 0.03 | ok |
| capable | 102 | 257.98 | 252.10 | 1.023x | 132.63 | 362.32 | 0.20 | 0.23 | ok |
| vfsstat | 0 | 23.22 | n/a | n/a | 13783.47 | n/a | 0.03 | n/a | ok |
| tcpconnect | 221 | 3190.61 | 3021.98 | 1.056x | 23.88 | 22.24 | 0.07 | 0.07 | ok |
| bindsnoop | 208 | 221.80 | 223.35 | 0.993x | 389260.18 | 394178.80 | 6.80 | 6.97 | ok |

## Comparison

- tcplife: avg_ns_delta=2.32%, ops_delta=2.64%, cpu_delta=50.00%
- biosnoop: avg_ns_delta=0.28%, ops_delta=2.23%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-7.99%, ops_delta=10.47%, cpu_delta=n/a%
- syscount: avg_ns_delta=-0.27%, ops_delta=-0.44%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=11.72%, ops_delta=-0.17%, cpu_delta=14.29%
- opensnoop: avg_ns_delta=19.52%, ops_delta=1.11%, cpu_delta=-50.00%
- capable: avg_ns_delta=-2.28%, ops_delta=173.17%, cpu_delta=16.67%
- vfsstat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-5.29%, ops_delta=-6.87%, cpu_delta=-0.00%
- bindsnoop: avg_ns_delta=0.70%, ops_delta=1.26%, cpu_delta=2.45%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

