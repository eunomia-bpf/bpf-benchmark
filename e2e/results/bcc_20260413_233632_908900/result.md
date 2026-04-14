# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-13T23:47:06.957143+00:00`
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
- Geomean speedup: `1.012x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 1149.91 | 1175.75 | 0.978x | 12.08 | 12.03 | 0.03 | 0.03 | ok |
| biosnoop | 23 | 288.51 | 285.37 | 1.011x | 62297.90 | 62613.41 | 5.03 | 5.23 | ok |
| runqlat | 26 | 136.47 | 136.58 | 0.999x | 18.09 | 18.07 | 0.00 | 0.00 | ok |
| syscount | 65 | 75.11 | 75.05 | 1.001x | 1083.06 | 1091.43 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1417.06 | 1436.67 | 0.986x | 4803.24 | 4801.19 | 1.83 | 1.83 | ok |
| opensnoop | 129 | 797.58 | 739.11 | 1.079x | 1083.46 | 1074.68 | 1.37 | 1.10 | ok |
| capable | 57 | 107.22 | 108.55 | 0.988x | 4680.48 | 4678.85 | 16.18 | 16.12 | ok |
| vfsstat | 0 | 34.29 | 34.64 | 0.990x | 76.33 | 72.80 | 0.03 | 0.00 | ok |
| tcpconnect | 76 | 3224.51 | 2971.34 | 1.085x | 11.21 | 11.40 | 0.00 | 0.03 | ok |
| bindsnoop | 114 | 505.48 | 501.88 | 1.007x | 259141.33 | 259986.80 | 36.00 | 35.96 | ok |

## Comparison

- tcplife: avg_ns_delta=2.25%, ops_delta=-0.42%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=-1.09%, ops_delta=0.51%, cpu_delta=4.08%
- runqlat: avg_ns_delta=0.08%, ops_delta=-0.16%, cpu_delta=n/a%
- syscount: avg_ns_delta=-0.08%, ops_delta=0.77%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=1.38%, ops_delta=-0.04%, cpu_delta=0.00%
- opensnoop: avg_ns_delta=-7.33%, ops_delta=-0.81%, cpu_delta=-19.51%
- capable: avg_ns_delta=1.24%, ops_delta=-0.03%, cpu_delta=-0.41%
- vfsstat: avg_ns_delta=1.01%, ops_delta=-4.63%, cpu_delta=-100.00%
- tcpconnect: avg_ns_delta=-7.85%, ops_delta=1.75%, cpu_delta=n/a%
- bindsnoop: avg_ns_delta=-0.71%, ops_delta=0.33%, cpu_delta=-0.09%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

