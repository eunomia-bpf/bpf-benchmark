# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-10T01:38:57.813878+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with applied sites: `9`
- Aggregate applied sites: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2)
- Geomean speedup: `1.042x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 1191.96 | 1151.51 | 1.035x | 11.68 | 12.37 | 0.03 | 0.00 | ok |
| biosnoop | 23 | 325.40 | 338.22 | 0.962x | 215134.93 | 205555.57 | 20.27 | 21.07 | ok |
| runqlat | 26 | 178.80 | 159.01 | 1.124x | 11.98 | 11.86 | 0.00 | 0.00 | ok |
| syscount | 65 | 77.81 | 79.26 | 0.982x | 1097.73 | 1306.60 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1918.30 | 1807.21 | 1.061x | 1047.17 | 1120.05 | 0.97 | 1.03 | ok |
| opensnoop | 129 | 700.34 | 721.08 | 0.971x | 1357.45 | 1325.12 | 1.63 | 1.33 | ok |
| capable | 57 | 125.50 | 132.50 | 0.947x | 1076.16 | 1044.76 | 1.97 | 1.80 | ok |
| vfsstat | 0 | 62.85 | 44.52 | 1.412x | 76.23 | 77.01 | 0.03 | 0.00 | ok |
| tcpconnect | 76 | 5584.94 | 5592.82 | 0.999x | 13.98 | 14.63 | 0.07 | 0.03 | ok |
| bindsnoop | 114 | 501.76 | 504.49 | 0.995x | 285630.33 | 287358.78 | 36.97 | 36.93 | ok |

## Comparison

- tcplife: avg_ns_delta=-3.39%, ops_delta=5.88%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=3.94%, ops_delta=-4.45%, cpu_delta=3.95%
- runqlat: avg_ns_delta=-11.07%, ops_delta=-0.98%, cpu_delta=n/a%
- syscount: avg_ns_delta=1.86%, ops_delta=19.03%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-5.79%, ops_delta=6.96%, cpu_delta=6.90%
- opensnoop: avg_ns_delta=2.96%, ops_delta=-2.38%, cpu_delta=-18.37%
- capable: avg_ns_delta=5.58%, ops_delta=-2.92%, cpu_delta=-8.48%
- vfsstat: avg_ns_delta=-29.16%, ops_delta=1.03%, cpu_delta=-100.00%
- tcpconnect: avg_ns_delta=0.14%, ops_delta=4.63%, cpu_delta=-50.00%
- bindsnoop: avg_ns_delta=0.54%, ops_delta=0.61%, cpu_delta=-0.09%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

