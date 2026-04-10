# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-10T03:38:04.054626+00:00`
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
- Geomean speedup: `1.031x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 917.36 | 858.89 | 1.068x | 21.96 | 23.03 | 0.03 | 0.03 | ok |
| biosnoop | 23 | 326.95 | 332.87 | 0.982x | 320738.37 | 312860.04 | 30.27 | 31.13 | ok |
| runqlat | 26 | 186.46 | 165.11 | 1.129x | 17.85 | 18.17 | 0.00 | 0.00 | ok |
| syscount | 65 | 78.36 | 72.69 | 1.078x | 1033.46 | 1031.07 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1823.63 | 1813.68 | 1.005x | 1120.86 | 1122.70 | 1.00 | 1.00 | ok |
| opensnoop | 129 | 660.59 | 699.36 | 0.945x | 1064.98 | 1045.10 | 1.33 | 1.40 | ok |
| capable | 57 | 133.78 | 123.80 | 1.081x | 953.27 | 1043.56 | 1.93 | 1.60 | ok |
| vfsstat | 0 | 35.34 | 36.64 | 0.965x | 79.08 | 70.02 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 3153.17 | 2965.10 | 1.063x | 27.41 | 27.69 | 0.03 | 0.07 | ok |
| bindsnoop | 114 | 490.72 | 485.76 | 1.010x | 293577.75 | 295056.96 | 37.00 | 37.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-6.37%, ops_delta=4.87%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=1.81%, ops_delta=-2.46%, cpu_delta=2.86%
- runqlat: avg_ns_delta=-11.45%, ops_delta=1.80%, cpu_delta=n/a%
- syscount: avg_ns_delta=-7.23%, ops_delta=-0.23%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.55%, ops_delta=0.16%, cpu_delta=-0.01%
- opensnoop: avg_ns_delta=5.87%, ops_delta=-1.87%, cpu_delta=5.00%
- capable: avg_ns_delta=-7.46%, ops_delta=9.47%, cpu_delta=-17.24%
- vfsstat: avg_ns_delta=3.68%, ops_delta=-11.45%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-5.96%, ops_delta=1.03%, cpu_delta=100.00%
- bindsnoop: avg_ns_delta=-1.01%, ops_delta=0.50%, cpu_delta=0.09%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

