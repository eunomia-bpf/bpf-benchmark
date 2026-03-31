# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T15:34:41.032587+00:00`
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
- Geomean speedup: `0.980x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 797.78 | 772.73 | 1.032x | 30.08 | 30.26 | 0.03 | 0.03 | ok |
| biosnoop | 50 | 324.22 | 339.93 | 0.954x | 291118.55 | 288511.18 | 26.37 | 27.30 | ok |
| runqlat | 62 | 154.88 | 154.64 | 1.002x | 64.34 | 64.28 | 0.00 | 0.00 | ok |
| syscount | 65 | 57.62 | 56.12 | 1.027x | 367585.83 | 370221.07 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1702.88 | 1721.04 | 0.989x | 919.04 | 674.22 | 1.03 | 0.93 | ok |
| opensnoop | 129 | 56.96 | 62.61 | 0.910x | 444000.41 | 443866.57 | 2.43 | 2.83 | ok |
| capable | 57 | 99.59 | 97.94 | 1.017x | 404.24 | 152.73 | 1.83 | 1.63 | ok |
| vfsstat | 0 | 24.53 | 23.93 | 1.025x | 52970.01 | 53857.55 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2081.78 | 2283.79 | 0.912x | 22.04 | 22.99 | 0.00 | 0.00 | ok |
| bindsnoop | 106 | 484.92 | 512.14 | 0.947x | 326357.89 | 323598.02 | 39.77 | 39.57 | ok |

## Comparison

- tcplife: avg_ns_delta=-3.14%, ops_delta=0.59%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=4.85%, ops_delta=-0.90%, cpu_delta=3.54%
- runqlat: avg_ns_delta=-0.16%, ops_delta=-0.10%, cpu_delta=n/a%
- syscount: avg_ns_delta=-2.59%, ops_delta=0.72%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=1.07%, ops_delta=-26.64%, cpu_delta=-9.68%
- opensnoop: avg_ns_delta=9.91%, ops_delta=-0.03%, cpu_delta=16.44%
- capable: avg_ns_delta=-1.66%, ops_delta=-62.22%, cpu_delta=-10.91%
- vfsstat: avg_ns_delta=-2.48%, ops_delta=1.68%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=9.70%, ops_delta=4.30%, cpu_delta=n/a%
- bindsnoop: avg_ns_delta=5.61%, ops_delta=-0.85%, cpu_delta=-0.50%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

