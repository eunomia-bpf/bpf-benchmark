# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-28T19:09:09.097438+00:00`
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
- Aggregate sites: `3174` (map_inline=183, const_prop=300, dce=2683, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.031x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 52 | 1145.45 | 1301.68 | 0.880x | 25.67 | 27.16 | 0.07 | 0.07 | ok |
| biosnoop | 149 | 9826.25 | 10724.56 | 0.916x | 15153.27 | 15158.97 | 0.03 | 0.07 | ok |
| runqlat | 104 | 219.10 | 221.63 | 0.989x | 63.48 | 63.58 | 0.00 | 0.00 | ok |
| syscount | 78 | 68.51 | 66.68 | 1.027x | 7396.02 | 7329.65 | 0.00 | 0.00 | ok |
| execsnoop | 1759 | 1564.28 | 1406.32 | 1.112x | 52.22 | 55.98 | 0.23 | 0.37 | ok |
| opensnoop | 501 | 835.08 | 589.58 | 1.416x | 7400.88 | 7466.69 | 0.03 | 0.07 | ok |
| capable | 102 | 265.41 | 263.31 | 1.008x | 85.71 | 309.66 | 0.20 | 0.33 | ok |
| vfsstat | 0 | 22.49 | 22.68 | 0.992x | 13504.78 | 14275.57 | 0.00 | 0.03 | ok |
| tcpconnect | 221 | 2891.93 | 2626.42 | 1.101x | 25.95 | 22.13 | 0.07 | 0.00 | ok |
| bindsnoop | 208 | 225.32 | 236.08 | 0.954x | 396250.82 | 394780.60 | 6.77 | 7.30 | ok |

## Comparison

- tcplife: avg_ns_delta=13.64%, ops_delta=5.83%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=9.14%, ops_delta=0.04%, cpu_delta=100.00%
- runqlat: avg_ns_delta=1.15%, ops_delta=0.16%, cpu_delta=n/a%
- syscount: avg_ns_delta=-2.67%, ops_delta=-0.90%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-10.10%, ops_delta=7.21%, cpu_delta=57.14%
- opensnoop: avg_ns_delta=-29.40%, ops_delta=0.89%, cpu_delta=100.00%
- capable: avg_ns_delta=-0.79%, ops_delta=261.29%, cpu_delta=66.65%
- vfsstat: avg_ns_delta=0.84%, ops_delta=5.71%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-9.18%, ops_delta=-14.71%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=4.78%, ops_delta=-0.37%, cpu_delta=7.88%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

