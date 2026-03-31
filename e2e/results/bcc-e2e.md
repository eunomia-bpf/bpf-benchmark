# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T01:19:53.513981+00:00`
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
- Geomean speedup: `1.011x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 735.50 | 696.60 | 1.056x | 30.13 | 30.39 | 0.03 | 0.03 | ok |
| biosnoop | 50 | 344.68 | 341.77 | 1.009x | 290041.06 | 283603.19 | 26.70 | 27.23 | ok |
| runqlat | 62 | 156.12 | 157.16 | 0.993x | 66.02 | 65.87 | 0.00 | 0.00 | ok |
| syscount | 65 | 56.23 | 52.86 | 1.064x | 364110.22 | 378011.63 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1707.80 | 1691.97 | 1.009x | 241.07 | 37.34 | 0.93 | 1.00 | ok |
| opensnoop | 129 | 55.74 | 55.65 | 1.002x | 452147.21 | 455579.13 | 2.60 | 2.47 | ok |
| capable | 57 | 102.08 | 103.30 | 0.988x | 906.90 | 745.04 | 1.70 | 1.67 | ok |
| vfsstat | 0 | 24.33 | 24.91 | 0.977x | 53562.61 | 53661.74 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2609.07 | 2583.99 | 1.010x | 22.88 | 22.48 | 0.07 | 0.00 | ok |
| bindsnoop | 106 | 478.17 | 477.25 | 1.002x | 330199.17 | 330615.94 | 39.73 | 39.63 | ok |

## Comparison

- tcplife: avg_ns_delta=-5.29%, ops_delta=0.87%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=-0.84%, ops_delta=-2.22%, cpu_delta=2.00%
- runqlat: avg_ns_delta=0.67%, ops_delta=-0.22%, cpu_delta=n/a%
- syscount: avg_ns_delta=-5.99%, ops_delta=3.82%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.93%, ops_delta=-84.51%, cpu_delta=7.14%
- opensnoop: avg_ns_delta=-0.17%, ops_delta=0.76%, cpu_delta=-5.13%
- capable: avg_ns_delta=1.20%, ops_delta=-17.85%, cpu_delta=-1.96%
- vfsstat: avg_ns_delta=2.38%, ops_delta=0.19%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-0.96%, ops_delta=-1.71%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=-0.19%, ops_delta=0.13%, cpu_delta=-0.25%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

