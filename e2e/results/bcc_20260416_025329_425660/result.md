# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-16T03:03:58.046886+00:00`
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
- Geomean speedup: `1.006x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 623.35 | 655.49 | 0.951x | 387.03 | 361.77 | 0.33 | 0.37 | ok |
| biosnoop | 23 | 286.19 | 288.86 | 0.991x | 653991.11 | 618941.69 | 47.07 | 45.83 | ok |
| runqlat | 26 | 154.93 | 155.74 | 0.995x | 69.09 | 67.97 | 0.00 | 0.00 | ok |
| syscount | 65 | 77.75 | 76.03 | 1.023x | 1132.71 | 1149.75 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1696.04 | 1687.45 | 1.005x | 2633.84 | 2642.46 | 0.83 | 0.87 | ok |
| opensnoop | 129 | 1167.37 | 936.03 | 1.247x | 1066.13 | 1109.08 | 0.83 | 0.97 | ok |
| capable | 57 | 92.35 | 92.89 | 0.994x | 2510.63 | 2519.59 | 12.17 | 12.23 | ok |
| vfsstat | 0 | 52.33 | 60.07 | 0.871x | 69.22 | 69.11 | 0.00 | 0.03 | ok |
| tcpconnect | 76 | 2084.13 | 2054.07 | 1.015x | 385.39 | 422.11 | 0.40 | 0.43 | ok |
| bindsnoop | 114 | 499.83 | 497.73 | 1.004x | 286698.86 | 287189.90 | 35.30 | 35.27 | ok |

## Comparison

- tcplife: avg_ns_delta=5.16%, ops_delta=-6.53%, cpu_delta=10.00%
- biosnoop: avg_ns_delta=0.93%, ops_delta=-5.36%, cpu_delta=-2.62%
- runqlat: avg_ns_delta=0.53%, ops_delta=-1.62%, cpu_delta=n/a%
- syscount: avg_ns_delta=-2.22%, ops_delta=1.50%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.51%, ops_delta=0.33%, cpu_delta=3.99%
- opensnoop: avg_ns_delta=-19.82%, ops_delta=4.03%, cpu_delta=16.00%
- capable: avg_ns_delta=0.59%, ops_delta=0.36%, cpu_delta=0.51%
- vfsstat: avg_ns_delta=14.79%, ops_delta=-0.16%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-1.44%, ops_delta=9.53%, cpu_delta=8.33%
- bindsnoop: avg_ns_delta=-0.42%, ops_delta=0.17%, cpu_delta=-0.09%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

