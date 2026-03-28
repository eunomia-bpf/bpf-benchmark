# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-28T21:18:27.209096+00:00`
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
- Aggregate sites: `3186` (map_inline=184, const_prop=301, dce=2693, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.023x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 52 | 1046.63 | 960.38 | 1.090x | 27.06 | 27.58 | 0.07 | 0.07 | ok |
| biosnoop | 149 | 4889.89 | 4456.98 | 1.097x | 15395.38 | 15408.10 | 0.03 | 0.00 | ok |
| runqlat | 116 | 238.04 | 251.53 | 0.946x | 57.56 | 47.39 | 0.00 | 0.00 | ok |
| syscount | 78 | 69.40 | 70.48 | 0.985x | 7451.98 | 7426.41 | 0.00 | 0.00 | ok |
| execsnoop | 1759 | 2436.96 | 2169.79 | 1.123x | 53.66 | 54.92 | 0.23 | 0.23 | ok |
| opensnoop | 501 | 821.90 | 619.10 | 1.328x | 7374.77 | 7573.37 | 0.03 | 0.03 | ok |
| capable | 102 | 255.69 | 260.88 | 0.980x | 323.03 | 528.39 | 0.30 | 0.30 | ok |
| vfsstat | 0 | 23.29 | 22.99 | 1.013x | 12649.33 | 12595.46 | 0.00 | 0.03 | ok |
| tcpconnect | 221 | 3456.05 | 4180.93 | 0.827x | 21.16 | 22.33 | 0.07 | 0.03 | ok |
| bindsnoop | 208 | 226.53 | 246.39 | 0.919x | 392193.56 | 387943.94 | 6.83 | 7.97 | ok |

## Comparison

- tcplife: avg_ns_delta=-8.24%, ops_delta=1.93%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=-8.85%, ops_delta=0.08%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=5.67%, ops_delta=-17.66%, cpu_delta=n/a%
- syscount: avg_ns_delta=1.54%, ops_delta=-0.34%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-10.96%, ops_delta=2.35%, cpu_delta=0.00%
- opensnoop: avg_ns_delta=-24.67%, ops_delta=2.69%, cpu_delta=0.00%
- capable: avg_ns_delta=2.03%, ops_delta=63.57%, cpu_delta=-0.00%
- vfsstat: avg_ns_delta=-1.28%, ops_delta=-0.43%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=20.97%, ops_delta=5.52%, cpu_delta=-50.00%
- bindsnoop: avg_ns_delta=8.77%, ops_delta=-1.08%, cpu_delta=16.59%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

