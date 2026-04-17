# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-16T08:29:28.263609+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- Tools dir: `/opt/bpf-benchmark/repo-artifacts/x86_64/bcc/libbpf-tools/.output`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with applied sites: `9`
- Aggregate applied sites: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2)
- Geomean speedup: `1.012x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 2247.26 | 2230.10 | 1.008x | 139.88 | 139.76 | 0.47 | 0.50 | ok |
| biosnoop | 23 | 876.83 | 844.60 | 1.038x | 150383.88 | 154585.14 | 49.77 | 51.93 | ok |
| runqlat | 26 | 491.71 | 502.32 | 0.979x | 14.80 | 14.82 | 0.00 | 0.00 | ok |
| syscount | 65 | 131.40 | 122.34 | 1.074x | 94522.42 | 96305.81 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 7363.44 | 7096.76 | 1.038x | 324.09 | 333.91 | 0.77 | 0.77 | ok |
| opensnoop | 129 | 2333.50 | 2235.14 | 1.044x | 40521.40 | 41191.67 | 50.37 | 50.30 | ok |
| capable | 57 | 314.92 | 321.66 | 0.979x | 315.47 | 314.01 | 7.26 | 7.43 | ok |
| vfsstat | 0 | 105.66 | 108.87 | 0.971x | 356.32 | 360.45 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 9942.93 | 9894.86 | 1.005x | 143.33 | 143.01 | 0.47 | 0.50 | ok |
| bindsnoop | 114 | 2673.92 | 2689.25 | 0.994x | 39937.97 | 39384.65 | 28.07 | 27.73 | ok |

## Comparison

- tcplife: avg_ns_delta=-0.76%, ops_delta=-0.09%, cpu_delta=7.14%
- biosnoop: avg_ns_delta=-3.68%, ops_delta=2.79%, cpu_delta=4.35%
- runqlat: avg_ns_delta=2.16%, ops_delta=0.14%, cpu_delta=n/a%
- syscount: avg_ns_delta=-6.89%, ops_delta=1.89%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-3.62%, ops_delta=3.03%, cpu_delta=0.05%
- opensnoop: avg_ns_delta=-4.22%, ops_delta=1.65%, cpu_delta=-0.13%
- capable: avg_ns_delta=2.14%, ops_delta=-0.46%, cpu_delta=2.30%
- vfsstat: avg_ns_delta=3.04%, ops_delta=1.16%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-0.48%, ops_delta=-0.22%, cpu_delta=7.14%
- bindsnoop: avg_ns_delta=0.57%, ops_delta=-1.39%, cpu_delta=-1.19%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

