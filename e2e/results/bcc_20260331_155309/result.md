# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T16:03:50.697613+00:00`
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
- Aggregate sites: `1008` (map_inline=184, const_prop=301, dce=523, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.002x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 809.67 | 679.49 | 1.192x | 29.09 | 29.77 | 0.03 | 0.03 | ok |
| biosnoop | 50 | 346.49 | 338.42 | 1.024x | 284788.90 | 289958.94 | 27.27 | 27.13 | ok |
| runqlat | 62 | 160.31 | 161.24 | 0.994x | 63.58 | 64.69 | 0.00 | 0.00 | ok |
| syscount | 65 | 60.16 | 61.02 | 0.986x | 363706.32 | 354098.75 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1753.26 | 1721.40 | 1.019x | 443.46 | 233.55 | 1.10 | 1.03 | ok |
| opensnoop | 129 | 55.03 | 54.99 | 1.001x | 450000.72 | 452143.00 | 2.67 | 2.77 | ok |
| capable | 55 | 104.81 | 103.67 | 1.011x | 1080.64 | 859.09 | 2.23 | 2.07 | ok |
| vfsstat | 0 | 25.59 | 25.20 | 1.015x | 52644.49 | 52982.14 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2297.05 | 2944.48 | 0.780x | 22.84 | 21.30 | 0.07 | 0.00 | ok |
| bindsnoop | 100 | 494.69 | 475.74 | 1.040x | 327039.37 | 330036.41 | 39.43 | 39.73 | ok |

## Comparison

- tcplife: avg_ns_delta=-16.08%, ops_delta=2.36%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=-2.33%, ops_delta=1.82%, cpu_delta=-0.49%
- runqlat: avg_ns_delta=0.58%, ops_delta=1.75%, cpu_delta=n/a%
- syscount: avg_ns_delta=1.42%, ops_delta=-2.64%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-1.82%, ops_delta=-47.34%, cpu_delta=-6.06%
- opensnoop: avg_ns_delta=-0.08%, ops_delta=0.48%, cpu_delta=3.75%
- capable: avg_ns_delta=-1.09%, ops_delta=-20.50%, cpu_delta=-7.45%
- vfsstat: avg_ns_delta=-1.52%, ops_delta=0.64%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=28.19%, ops_delta=-6.76%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=-3.83%, ops_delta=0.92%, cpu_delta=0.76%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

