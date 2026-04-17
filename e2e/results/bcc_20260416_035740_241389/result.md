# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-16T04:08:08.491421+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- Tools dir: `/opt/bpf-benchmark/repo-artifacts/x86_64/bcc/libbpf-tools/.output`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with applied sites: `9`
- Aggregate applied sites: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2)
- Geomean speedup: `1.011x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 530.40 | 540.53 | 0.981x | 453.46 | 452.83 | 0.40 | 0.33 | ok |
| biosnoop | 23 | 280.00 | 278.92 | 1.004x | 724057.54 | 706203.84 | 51.07 | 50.80 | ok |
| runqlat | 26 | 149.88 | 149.37 | 1.003x | 70.70 | 69.35 | 0.00 | 0.00 | ok |
| syscount | 65 | 72.28 | 70.38 | 1.027x | 1094.57 | 1043.99 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1681.54 | 1711.74 | 0.982x | 2640.81 | 2647.97 | 0.80 | 0.87 | ok |
| opensnoop | 129 | 992.80 | 609.19 | 1.630x | 1014.43 | 1128.06 | 0.90 | 0.97 | ok |
| capable | 57 | 91.85 | 92.57 | 0.992x | 2529.12 | 2507.90 | 11.86 | 11.57 | ok |
| vfsstat | 0 | 34.79 | 47.08 | 0.739x | 78.40 | 64.25 | 0.00 | 0.03 | ok |
| tcpconnect | 76 | 2039.86 | 2162.64 | 0.943x | 389.38 | 390.26 | 0.43 | 0.30 | ok |
| bindsnoop | 114 | 476.75 | 479.34 | 0.995x | 292792.32 | 292824.02 | 35.80 | 35.60 | ok |

## Comparison

- tcplife: avg_ns_delta=1.91%, ops_delta=-0.14%, cpu_delta=-16.67%
- biosnoop: avg_ns_delta=-0.39%, ops_delta=-2.47%, cpu_delta=-0.52%
- runqlat: avg_ns_delta=-0.34%, ops_delta=-1.90%, cpu_delta=n/a%
- syscount: avg_ns_delta=-2.63%, ops_delta=-4.62%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=1.80%, ops_delta=0.27%, cpu_delta=8.36%
- opensnoop: avg_ns_delta=-38.64%, ops_delta=11.20%, cpu_delta=7.41%
- capable: avg_ns_delta=0.79%, ops_delta=-0.84%, cpu_delta=-2.49%
- vfsstat: avg_ns_delta=35.33%, ops_delta=-18.04%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=6.02%, ops_delta=0.23%, cpu_delta=-30.77%
- bindsnoop: avg_ns_delta=0.54%, ops_delta=0.01%, cpu_delta=-0.56%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

