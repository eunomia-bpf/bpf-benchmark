# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-13T07:57:17.591550+00:00`
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
- Geomean speedup: `0.975x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 1290.94 | 1218.74 | 1.059x | 11.10 | 11.25 | 0.03 | 0.03 | ok |
| biosnoop | 23 | 292.08 | 291.09 | 1.003x | 55294.20 | 55537.50 | 5.03 | 5.13 | ok |
| runqlat | 26 | 147.95 | 145.51 | 1.017x | 16.42 | 16.22 | 0.00 | 0.00 | ok |
| syscount | 65 | 80.03 | 83.15 | 0.962x | 1296.85 | 1304.66 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1421.38 | 1514.28 | 0.939x | 4734.58 | 4616.66 | 1.80 | 1.90 | ok |
| opensnoop | 129 | 799.42 | 762.33 | 1.049x | 1317.82 | 1312.27 | 1.83 | 1.63 | ok |
| capable | 57 | 126.58 | 167.84 | 0.754x | 4046.26 | 3120.47 | 13.55 | 12.79 | ok |
| vfsstat | 0 | 37.72 | 43.56 | 0.866x | 0.92 | 0.25 | 0.03 | 0.00 | ok |
| tcpconnect | 76 | 3883.57 | 3286.99 | 1.181x | 10.63 | 11.27 | 0.00 | 0.03 | ok |
| bindsnoop | 114 | 516.02 | 523.45 | 0.986x | 255401.28 | 250644.90 | 35.56 | 35.60 | ok |

## Comparison

- tcplife: avg_ns_delta=-5.59%, ops_delta=1.38%, cpu_delta=-0.00%
- biosnoop: avg_ns_delta=-0.34%, ops_delta=0.44%, cpu_delta=1.99%
- runqlat: avg_ns_delta=-1.65%, ops_delta=-1.18%, cpu_delta=n/a%
- syscount: avg_ns_delta=3.90%, ops_delta=0.60%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=6.54%, ops_delta=-2.49%, cpu_delta=5.56%
- opensnoop: avg_ns_delta=-4.64%, ops_delta=-0.42%, cpu_delta=-10.91%
- capable: avg_ns_delta=32.59%, ops_delta=-22.88%, cpu_delta=-5.64%
- vfsstat: avg_ns_delta=15.48%, ops_delta=-72.39%, cpu_delta=-100.00%
- tcpconnect: avg_ns_delta=-15.36%, ops_delta=6.09%, cpu_delta=n/a%
- bindsnoop: avg_ns_delta=1.44%, ops_delta=-1.86%, cpu_delta=0.11%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

