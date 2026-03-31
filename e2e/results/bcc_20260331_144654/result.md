# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T14:57:37.647741+00:00`
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
- Geomean speedup: `0.998x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 751.06 | 871.27 | 0.862x | 30.10 | 29.88 | 0.03 | 0.03 | ok |
| biosnoop | 50 | 326.96 | 333.81 | 0.979x | 295845.73 | 289935.70 | 27.00 | 27.70 | ok |
| runqlat | 62 | 159.16 | 160.93 | 0.989x | 64.61 | 64.28 | 0.00 | 0.00 | ok |
| syscount | 65 | 56.45 | 54.22 | 1.041x | 356582.41 | 367831.15 | 0.00 | 0.00 | ok |
| execsnoop | 432 | 1705.39 | 1728.35 | 0.987x | 738.17 | 462.31 | 1.07 | 0.93 | ok |
| opensnoop | 129 | 55.56 | 56.22 | 0.988x | 450104.70 | 449828.49 | 2.60 | 2.73 | ok |
| capable | 57 | 105.08 | 104.15 | 1.009x | 180.34 | 1021.92 | 2.17 | 1.67 | ok |
| vfsstat | 0 | 23.41 | 23.88 | 0.980x | 52692.74 | 53178.55 | 0.00 | 0.03 | ok |
| tcpconnect | 76 | 4039.50 | 3507.73 | 1.152x | 22.43 | 22.68 | 0.03 | 0.07 | ok |
| bindsnoop | 106 | 483.12 | 473.88 | 1.019x | 327625.94 | 330138.44 | 40.30 | 40.10 | ok |

## Comparison

- tcplife: avg_ns_delta=16.01%, ops_delta=-0.74%, cpu_delta=0.00%
- biosnoop: avg_ns_delta=2.10%, ops_delta=-2.00%, cpu_delta=2.59%
- runqlat: avg_ns_delta=1.12%, ops_delta=-0.51%, cpu_delta=n/a%
- syscount: avg_ns_delta=-3.95%, ops_delta=3.15%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=1.35%, ops_delta=-37.37%, cpu_delta=-12.50%
- opensnoop: avg_ns_delta=1.19%, ops_delta=-0.06%, cpu_delta=5.13%
- capable: avg_ns_delta=-0.89%, ops_delta=466.67%, cpu_delta=-23.08%
- vfsstat: avg_ns_delta=2.03%, ops_delta=0.92%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-13.16%, ops_delta=1.13%, cpu_delta=100.00%
- bindsnoop: avg_ns_delta=-1.91%, ops_delta=0.77%, cpu_delta=-0.50%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

