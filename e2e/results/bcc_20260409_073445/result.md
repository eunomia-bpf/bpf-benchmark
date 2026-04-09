# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-09T07:45:16.923322+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/x86_64/bcc/libbpf-tools/.output`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with applied sites: `9`
- Aggregate applied sites: `953` (map_inline=184, const_prop=304, dce=465)
- Geomean speedup: `0.992x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 730.10 | 758.71 | 0.962x | 20.52 | 20.48 | 0.03 | 0.00 | ok |
| biosnoop | 23 | 307.97 | 315.98 | 0.975x | 286032.54 | 260846.67 | 22.43 | 22.83 | ok |
| runqlat | 26 | 151.17 | 157.63 | 0.959x | 56.64 | 51.08 | 0.00 | 0.00 | ok |
| syscount | 65 | 55.59 | 55.13 | 1.008x | 364284.57 | 362956.22 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1707.79 | 1705.51 | 1.001x | 1259.74 | 1251.37 | 1.00 | 0.90 | ok |
| opensnoop | 129 | 54.58 | 53.53 | 1.020x | 444567.25 | 458571.75 | 2.50 | 2.30 | ok |
| capable | 55 | 102.02 | 101.43 | 1.006x | 1279.96 | 1291.38 | 2.13 | 2.33 | ok |
| vfsstat | 0 | 24.53 | 24.11 | 1.018x | 53237.22 | 53649.47 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 1829.44 | 1952.87 | 0.937x | 15.89 | 15.21 | 0.00 | 0.03 | ok |
| bindsnoop | 108 | 505.57 | 484.89 | 1.043x | 294335.18 | 296651.31 | 37.00 | 36.93 | ok |

## Comparison

- tcplife: avg_ns_delta=3.92%, ops_delta=-0.19%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=2.60%, ops_delta=-8.81%, cpu_delta=1.78%
- runqlat: avg_ns_delta=4.27%, ops_delta=-9.81%, cpu_delta=n/a%
- syscount: avg_ns_delta=-0.83%, ops_delta=-0.36%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.13%, ops_delta=-0.66%, cpu_delta=-10.00%
- opensnoop: avg_ns_delta=-1.92%, ops_delta=3.15%, cpu_delta=-8.00%
- capable: avg_ns_delta=-0.57%, ops_delta=0.89%, cpu_delta=9.37%
- vfsstat: avg_ns_delta=-1.72%, ops_delta=0.77%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=6.75%, ops_delta=-4.27%, cpu_delta=n/a%
- bindsnoop: avg_ns_delta=-4.09%, ops_delta=0.79%, cpu_delta=-0.18%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

