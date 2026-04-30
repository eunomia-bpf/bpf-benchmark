# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-23T19:57:59.144783+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools in suite: `10`
- Baseline successes: `10`
- ReJIT successes: `4`
- Tools with applied sites: `4`
- Aggregate applied sites: `14` (const_prop=4, dce=5, extract=3, endian_fusion=2)
- Geomean speedup: `1.001x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 0 | 548.19 | n/a | n/a | 396.54 | n/a | 1.37 | n/a | ok |
| biosnoop | 3 | 149.63 | 149.85 | 0.999x | 891859.38 | 909921.51 | 73.23 | 73.93 | ok |
| runqlat | 6 | 156.80 | 156.46 | 1.002x | 64.23 | 63.25 | 0.00 | 0.00 | ok |
| syscount | 0 | 69.74 | n/a | n/a | 1254.10 | n/a | 0.07 | n/a | ok |
| execsnoop | 0 | 2047.55 | n/a | n/a | 2417.70 | n/a | 1.90 | n/a | ok |
| opensnoop | 0 | 1226.27 | n/a | n/a | 1114.63 | n/a | 2.67 | n/a | ok |
| capable | 1 | 41.28 | 41.11 | 1.004x | 2420.03 | 2412.44 | 2.43 | 2.47 | ok |
| vfsstat | 0 | 59.43 | n/a | n/a | 77.34 | n/a | 0.00 | n/a | ok |
| tcpconnect | 0 | 2432.01 | n/a | n/a | 372.33 | n/a | 1.13 | n/a | ok |
| bindsnoop | 4 | 434.23 | 434.49 | 0.999x | 195714.91 | 196253.81 | 74.60 | 74.80 | ok |

## Comparison

- tcplife: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=0.15%, ops_delta=2.03%, cpu_delta=0.96%
- runqlat: avg_ns_delta=-0.21%, ops_delta=-1.52%, cpu_delta=n/a%
- syscount: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- opensnoop: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- capable: avg_ns_delta=-0.41%, ops_delta=-0.31%, cpu_delta=1.38%
- vfsstat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- bindsnoop: avg_ns_delta=0.06%, ops_delta=0.28%, cpu_delta=0.27%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

