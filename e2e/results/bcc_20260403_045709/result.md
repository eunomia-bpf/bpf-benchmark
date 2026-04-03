# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-03T05:07:44.071403+00:00`
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
- Tools with applied sites: `9`
- Aggregate applied sites: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2)
- Geomean speedup: `1.002x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 695.44 | 738.77 | 0.941x | 30.08 | 28.92 | 0.03 | 0.00 | ok |
| biosnoop | 23 | 316.05 | 308.99 | 1.023x | 298297.59 | 305415.74 | 25.17 | 25.37 | ok |
| runqlat | 26 | 162.05 | 161.68 | 1.002x | 63.49 | 63.56 | 0.00 | 0.00 | ok |
| syscount | 65 | 54.33 | 53.38 | 1.018x | 373860.52 | 378406.84 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1703.82 | 1701.09 | 1.002x | 815.35 | 528.89 | 1.07 | 1.07 | ok |
| opensnoop | 129 | 55.89 | 55.91 | 1.000x | 446855.38 | 447496.02 | 2.37 | 2.77 | ok |
| capable | 57 | 103.33 | 103.37 | 1.000x | 228.01 | 1059.00 | 1.63 | 1.73 | ok |
| vfsstat | 0 | 24.50 | 24.53 | 0.999x | 53513.10 | 53766.25 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2436.95 | 2358.90 | 1.033x | 21.79 | 23.45 | 0.03 | 0.03 | ok |
| bindsnoop | 114 | 492.69 | 488.31 | 1.009x | 294124.98 | 295953.83 | 37.13 | 37.20 | ok |

## Comparison

- tcplife: avg_ns_delta=6.23%, ops_delta=-3.86%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-2.23%, ops_delta=2.39%, cpu_delta=0.79%
- runqlat: avg_ns_delta=-0.23%, ops_delta=0.11%, cpu_delta=n/a%
- syscount: avg_ns_delta=-1.76%, ops_delta=1.22%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.16%, ops_delta=-35.13%, cpu_delta=0.01%
- opensnoop: avg_ns_delta=0.05%, ops_delta=0.14%, cpu_delta=16.90%
- capable: avg_ns_delta=0.05%, ops_delta=364.45%, cpu_delta=6.09%
- vfsstat: avg_ns_delta=0.14%, ops_delta=0.47%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-3.20%, ops_delta=7.58%, cpu_delta=-0.00%
- bindsnoop: avg_ns_delta=-0.89%, ops_delta=0.62%, cpu_delta=0.18%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

