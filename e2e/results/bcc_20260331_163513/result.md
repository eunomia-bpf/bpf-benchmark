# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T16:45:55.970296+00:00`
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
- Geomean speedup: `1.025x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 881.45 | 699.14 | 1.261x | 30.00 | 30.74 | 0.03 | 0.00 | ok |
| biosnoop | 50 | 331.78 | 327.43 | 1.013x | 289142.92 | 290431.35 | 27.07 | 27.03 | ok |
| runqlat | 62 | 162.30 | 164.07 | 0.989x | 65.07 | 64.59 | 0.00 | 0.00 | ok |
| syscount | 65 | 55.77 | 52.71 | 1.058x | 362243.17 | 378767.43 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1689.33 | 1689.31 | 1.000x | 253.93 | 81.00 | 1.10 | 0.97 | ok |
| opensnoop | 129 | 54.97 | 55.14 | 0.997x | 451554.43 | 450142.91 | 2.43 | 2.47 | ok |
| capable | 57 | 102.40 | 101.87 | 1.005x | 965.09 | 823.56 | 1.73 | 1.83 | ok |
| vfsstat | 0 | 24.18 | 23.36 | 1.035x | 52548.33 | 52940.35 | 0.00 | 0.03 | ok |
| tcpconnect | 76 | 2142.19 | 2328.21 | 0.920x | 22.24 | 22.75 | 0.03 | 0.03 | ok |
| bindsnoop | 106 | 476.39 | 476.73 | 0.999x | 333315.47 | 333316.05 | 39.60 | 39.63 | ok |

## Comparison

- tcplife: avg_ns_delta=-20.68%, ops_delta=2.49%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-1.31%, ops_delta=0.45%, cpu_delta=-0.12%
- runqlat: avg_ns_delta=1.09%, ops_delta=-0.74%, cpu_delta=n/a%
- syscount: avg_ns_delta=-5.48%, ops_delta=4.56%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.00%, ops_delta=-68.10%, cpu_delta=-12.10%
- opensnoop: avg_ns_delta=0.30%, ops_delta=-0.31%, cpu_delta=1.37%
- capable: avg_ns_delta=-0.51%, ops_delta=-14.66%, cpu_delta=5.78%
- vfsstat: avg_ns_delta=-3.41%, ops_delta=0.75%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=8.68%, ops_delta=2.33%, cpu_delta=0.00%
- bindsnoop: avg_ns_delta=0.07%, ops_delta=0.00%, cpu_delta=0.08%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

