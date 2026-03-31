# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T17:25:01.284225+00:00`
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
- Geomean speedup: `0.988x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 664.76 | 675.56 | 0.984x | 30.00 | 29.64 | 0.03 | 0.00 | ok |
| biosnoop | 50 | 312.41 | 335.70 | 0.931x | 306181.55 | 284142.22 | 27.10 | 27.67 | ok |
| runqlat | 62 | 159.10 | 161.82 | 0.983x | 63.83 | 62.23 | 0.00 | 0.00 | ok |
| syscount | 65 | 56.57 | 58.25 | 0.971x | 353458.51 | 355333.13 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1725.43 | 1711.67 | 1.008x | 338.03 | 80.43 | 1.03 | 0.93 | ok |
| opensnoop | 129 | 54.24 | 53.90 | 1.006x | 453468.45 | 453286.70 | 2.60 | 2.70 | ok |
| capable | 57 | 103.71 | 101.35 | 1.023x | 895.78 | 649.84 | 2.27 | 2.07 | ok |
| vfsstat | 0 | 24.09 | 24.25 | 0.994x | 52661.31 | 52407.60 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2288.92 | 2334.82 | 0.980x | 18.18 | 22.26 | 0.07 | 0.00 | ok |
| bindsnoop | 106 | 494.50 | 493.05 | 1.003x | 321643.18 | 322054.89 | 40.13 | 40.23 | ok |

## Comparison

- tcplife: avg_ns_delta=1.62%, ops_delta=-1.20%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=7.45%, ops_delta=-7.20%, cpu_delta=2.09%
- runqlat: avg_ns_delta=1.71%, ops_delta=-2.52%, cpu_delta=n/a%
- syscount: avg_ns_delta=2.97%, ops_delta=0.53%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.80%, ops_delta=-76.21%, cpu_delta=-9.68%
- opensnoop: avg_ns_delta=-0.64%, ops_delta=-0.04%, cpu_delta=3.85%
- capable: avg_ns_delta=-2.28%, ops_delta=-27.46%, cpu_delta=-8.80%
- vfsstat: avg_ns_delta=0.65%, ops_delta=-0.48%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=2.01%, ops_delta=22.38%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=-0.29%, ops_delta=0.13%, cpu_delta=0.25%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

