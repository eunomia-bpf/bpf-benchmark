# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T03:50:23.656988+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with eligible sites: `9`
- Aggregate sites: `1016` (map_inline=184, const_prop=301, dce=523, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.010x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 940.57 | 846.85 | 1.111x | 24.44 | 25.55 | 0.03 | 0.03 | ok |
| biosnoop | 50 | 339.03 | 332.52 | 1.020x | 270668.88 | 276924.39 | 25.93 | 25.90 | ok |
| runqlat | 62 | 161.46 | 162.97 | 0.991x | 59.52 | 59.76 | 0.00 | 0.00 | ok |
| syscount | 65 | 55.18 | 55.14 | 1.001x | 365732.80 | 364858.38 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1707.32 | 1698.24 | 1.005x | 602.62 | 409.29 | 1.07 | 1.00 | ok |
| opensnoop | 129 | 57.07 | 56.37 | 1.012x | 451103.15 | 448718.05 | 2.83 | 2.63 | ok |
| capable | 57 | 103.08 | 101.46 | 1.016x | 202.03 | 35.36 | 2.40 | 1.87 | ok |
| vfsstat | 0 | 25.01 | 25.24 | 0.991x | 52155.46 | 52564.54 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 3123.06 | 3199.54 | 0.976x | 23.70 | 23.97 | 0.03 | 0.03 | ok |
| bindsnoop | 106 | 482.14 | 489.90 | 0.984x | 329039.84 | 329029.09 | 40.13 | 39.73 | ok |

## Comparison

- tcplife: avg_ns_delta=-9.96%, ops_delta=4.55%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=-1.92%, ops_delta=2.31%, cpu_delta=-0.13%
- runqlat: avg_ns_delta=0.93%, ops_delta=0.40%, cpu_delta=n/a%
- syscount: avg_ns_delta=-0.07%, ops_delta=-0.24%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.53%, ops_delta=-32.08%, cpu_delta=-6.25%
- opensnoop: avg_ns_delta=-1.23%, ops_delta=-0.53%, cpu_delta=-7.06%
- capable: avg_ns_delta=-1.58%, ops_delta=-82.50%, cpu_delta=-22.23%
- vfsstat: avg_ns_delta=0.91%, ops_delta=0.78%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=2.45%, ops_delta=1.15%, cpu_delta=-0.00%
- bindsnoop: avg_ns_delta=1.61%, ops_delta=-0.00%, cpu_delta=-1.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

