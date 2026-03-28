# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-28T22:12:19.615920+00:00`
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
- Aggregate sites: `3180` (map_inline=184, const_prop=301, dce=2687, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.049x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 52 | 1215.96 | 1079.68 | 1.126x | 23.73 | 22.61 | 0.07 | 0.07 | ok |
| biosnoop | 149 | 5538.60 | 4961.58 | 1.116x | 13433.90 | 13564.83 | 0.03 | 0.03 | ok |
| runqlat | 116 | 208.20 | 200.65 | 1.038x | 61.00 | 61.65 | 0.00 | 0.00 | ok |
| syscount | 78 | 71.31 | 68.88 | 1.035x | 6801.81 | 6374.89 | 0.00 | 0.00 | ok |
| execsnoop | 1759 | 2148.58 | 2308.47 | 0.931x | 45.82 | 48.44 | 0.20 | 0.20 | ok |
| opensnoop | 498 | 763.59 | 730.64 | 1.045x | 6651.41 | 6505.45 | 0.00 | 0.03 | ok |
| capable | 101 | 261.20 | 234.54 | 1.114x | 124.47 | 375.63 | 0.30 | 0.30 | ok |
| vfsstat | 0 | 22.76 | 22.96 | 0.991x | 12632.60 | 13587.12 | 0.03 | 0.03 | ok |
| tcpconnect | 219 | 3275.68 | 2687.51 | 1.219x | 21.30 | 22.38 | 0.03 | 0.07 | ok |
| bindsnoop | 208 | 216.86 | 236.53 | 0.917x | 395183.51 | 393021.82 | 6.60 | 7.67 | ok |

## Comparison

- tcplife: avg_ns_delta=-11.21%, ops_delta=-4.73%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=-10.42%, ops_delta=0.97%, cpu_delta=-0.00%
- runqlat: avg_ns_delta=-3.63%, ops_delta=1.06%, cpu_delta=n/a%
- syscount: avg_ns_delta=-3.40%, ops_delta=-6.28%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=7.44%, ops_delta=5.72%, cpu_delta=-0.00%
- opensnoop: avg_ns_delta=-4.32%, ops_delta=-2.19%, cpu_delta=n/a%
- capable: avg_ns_delta=-10.21%, ops_delta=201.78%, cpu_delta=0.01%
- vfsstat: avg_ns_delta=0.88%, ops_delta=7.56%, cpu_delta=0.00%
- tcpconnect: avg_ns_delta=-17.96%, ops_delta=5.10%, cpu_delta=100.00%
- bindsnoop: avg_ns_delta=9.07%, ops_delta=-0.55%, cpu_delta=16.16%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

