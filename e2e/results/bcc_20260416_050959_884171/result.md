# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-16T05:20:27.064964+00:00`
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
- Geomean speedup: `1.008x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 610.24 | 610.84 | 0.999x | 398.01 | 399.56 | 0.37 | 0.40 | ok |
| biosnoop | 23 | 288.83 | 291.86 | 0.990x | 640868.78 | 623893.16 | 46.23 | 46.73 | ok |
| runqlat | 26 | 155.81 | 155.59 | 1.001x | 68.16 | 68.04 | 0.00 | 0.00 | ok |
| syscount | 65 | 76.32 | 76.51 | 0.998x | 1055.95 | 1065.47 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1705.27 | 1712.29 | 0.996x | 2637.83 | 2611.95 | 0.83 | 0.87 | ok |
| opensnoop | 129 | 953.50 | 758.31 | 1.257x | 1050.90 | 1035.00 | 0.93 | 1.03 | ok |
| capable | 57 | 89.51 | 90.23 | 0.992x | 2502.79 | 2511.30 | 12.06 | 11.63 | ok |
| vfsstat | 0 | 49.64 | 55.44 | 0.895x | 73.62 | 70.88 | 0.00 | 0.07 | ok |
| tcpconnect | 76 | 2210.42 | 2225.07 | 0.993x | 374.43 | 380.89 | 0.40 | 0.37 | ok |
| bindsnoop | 114 | 476.00 | 479.99 | 0.992x | 288345.09 | 288000.98 | 34.97 | 34.83 | ok |

## Comparison

- tcplife: avg_ns_delta=0.10%, ops_delta=0.39%, cpu_delta=9.09%
- biosnoop: avg_ns_delta=1.05%, ops_delta=-2.65%, cpu_delta=1.08%
- runqlat: avg_ns_delta=-0.14%, ops_delta=-0.18%, cpu_delta=n/a%
- syscount: avg_ns_delta=0.24%, ops_delta=0.90%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=0.41%, ops_delta=-0.98%, cpu_delta=4.01%
- opensnoop: avg_ns_delta=-20.47%, ops_delta=-1.51%, cpu_delta=10.71%
- capable: avg_ns_delta=0.80%, ops_delta=0.34%, cpu_delta=-3.56%
- vfsstat: avg_ns_delta=11.69%, ops_delta=-3.72%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=0.66%, ops_delta=1.73%, cpu_delta=-8.33%
- bindsnoop: avg_ns_delta=0.84%, ops_delta=-0.12%, cpu_delta=-0.38%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

