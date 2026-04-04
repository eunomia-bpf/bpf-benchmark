# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-03T20:51:39.117900+00:00`
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
- Tools with applied sites: `9`
- Aggregate applied sites: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2)
- Geomean speedup: `1.012x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 632.44 | 574.31 | 1.101x | 31.33 | 31.56 | 0.00 | 0.03 | ok |
| biosnoop | 23 | 309.25 | 310.74 | 0.995x | 309990.43 | 317133.19 | 24.40 | 26.57 | ok |
| runqlat | 26 | 156.79 | 156.93 | 0.999x | 64.69 | 67.63 | 0.00 | 0.00 | ok |
| syscount | 65 | 53.29 | 55.47 | 0.961x | 378212.95 | 374721.63 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1733.44 | 1665.84 | 1.041x | 523.51 | 325.03 | 1.07 | 1.03 | ok |
| opensnoop | 129 | 54.81 | 54.59 | 1.004x | 455331.12 | 450313.92 | 2.20 | 2.17 | ok |
| capable | 57 | 103.93 | 104.07 | 0.999x | 136.14 | 1012.81 | 1.73 | 1.73 | ok |
| vfsstat | 0 | 23.94 | 23.84 | 1.004x | 53186.83 | 53568.46 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 1720.64 | 1660.45 | 1.036x | 22.22 | 22.34 | 0.03 | 0.03 | ok |
| bindsnoop | 114 | 490.85 | 496.05 | 0.990x | 297408.18 | 296600.38 | 36.80 | 36.77 | ok |

## Comparison

- tcplife: avg_ns_delta=-9.19%, ops_delta=0.71%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=0.48%, ops_delta=2.30%, cpu_delta=8.88%
- runqlat: avg_ns_delta=0.09%, ops_delta=4.55%, cpu_delta=n/a%
- syscount: avg_ns_delta=4.09%, ops_delta=-0.92%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-3.90%, ops_delta=-37.91%, cpu_delta=-3.13%
- opensnoop: avg_ns_delta=-0.39%, ops_delta=-1.10%, cpu_delta=-1.52%
- capable: avg_ns_delta=0.13%, ops_delta=643.96%, cpu_delta=0.01%
- vfsstat: avg_ns_delta=-0.43%, ops_delta=0.72%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-3.50%, ops_delta=0.55%, cpu_delta=-0.00%
- bindsnoop: avg_ns_delta=1.06%, ops_delta=-0.27%, cpu_delta=-0.09%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

