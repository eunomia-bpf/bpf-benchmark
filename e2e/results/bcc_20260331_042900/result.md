# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T04:39:43.567995+00:00`
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
- Geomean speedup: `1.015x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 794.22 | 803.37 | 0.989x | 28.58 | 28.92 | 0.03 | 0.00 | ok |
| biosnoop | 50 | 339.41 | 330.71 | 1.026x | 292983.35 | 293152.52 | 28.23 | 27.47 | ok |
| runqlat | 62 | 164.98 | 164.66 | 1.002x | 61.12 | 62.59 | 0.00 | 0.00 | ok |
| syscount | 65 | 57.57 | 54.16 | 1.063x | 357729.74 | 368591.11 | 0.03 | 0.00 | ok |
| execsnoop | 432 | 1771.08 | 1762.84 | 1.005x | 315.08 | 1066.97 | 1.03 | 0.87 | ok |
| opensnoop | 129 | 54.85 | 54.75 | 1.002x | 449080.02 | 450506.12 | 2.83 | 2.70 | ok |
| capable | 57 | 104.80 | 104.15 | 1.006x | 814.95 | 565.53 | 1.60 | 1.63 | ok |
| vfsstat | 0 | 24.30 | 24.60 | 0.987x | 51697.09 | 52280.79 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2975.52 | 2851.64 | 1.043x | 23.38 | 24.63 | 0.07 | 0.00 | ok |
| bindsnoop | 106 | 489.13 | 476.11 | 1.027x | 326534.25 | 329940.84 | 41.10 | 40.87 | ok |

## Comparison

- tcplife: avg_ns_delta=1.15%, ops_delta=1.18%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-2.56%, ops_delta=0.06%, cpu_delta=-2.72%
- runqlat: avg_ns_delta=-0.19%, ops_delta=2.40%, cpu_delta=n/a%
- syscount: avg_ns_delta=-5.92%, ops_delta=3.04%, cpu_delta=-100.00%
- execsnoop: avg_ns_delta=-0.47%, ops_delta=238.63%, cpu_delta=-16.25%
- opensnoop: avg_ns_delta=-0.20%, ops_delta=0.32%, cpu_delta=-4.71%
- capable: avg_ns_delta=-0.62%, ops_delta=-30.61%, cpu_delta=2.07%
- vfsstat: avg_ns_delta=1.27%, ops_delta=1.13%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-4.16%, ops_delta=5.36%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=-2.66%, ops_delta=1.04%, cpu_delta=-0.57%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

