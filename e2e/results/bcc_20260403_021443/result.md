# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-03T02:25:22.256527+00:00`
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
- Aggregate sites: `643` (map_inline=184, const_prop=116, dce=343, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.005x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 737.95 | 748.08 | 0.986x | 30.32 | 29.97 | 0.00 | 0.03 | ok |
| biosnoop | 50 | 319.01 | 312.68 | 1.020x | 314570.19 | 308054.77 | 27.30 | 27.13 | ok |
| runqlat | 62 | 156.39 | 157.81 | 0.991x | 65.79 | 65.58 | 0.00 | 0.00 | ok |
| syscount | 65 | 54.68 | 54.27 | 1.007x | 372626.14 | 374225.07 | 0.00 | 0.00 | ok |
| execsnoop | 67 | 1716.56 | 1728.90 | 0.993x | 362.76 | 109.86 | 1.03 | 0.90 | ok |
| opensnoop | 129 | 54.92 | 57.03 | 0.963x | 448849.84 | 449196.95 | 2.53 | 2.50 | ok |
| capable | 55 | 103.01 | 101.33 | 1.017x | 929.48 | 673.30 | 1.97 | 1.57 | ok |
| vfsstat | 0 | 24.27 | 24.43 | 0.993x | 52630.18 | 52914.76 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 3110.34 | 2829.96 | 1.099x | 23.14 | 23.73 | 0.03 | 0.03 | ok |
| bindsnoop | 100 | 482.47 | 487.17 | 0.990x | 295201.24 | 294830.55 | 37.00 | 37.07 | ok |

## Comparison

- tcplife: avg_ns_delta=1.37%, ops_delta=-1.16%, cpu_delta=n/a%
- biosnoop: avg_ns_delta=-1.98%, ops_delta=-2.07%, cpu_delta=-0.61%
- runqlat: avg_ns_delta=0.91%, ops_delta=-0.32%, cpu_delta=n/a%
- syscount: avg_ns_delta=-0.74%, ops_delta=0.43%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=0.72%, ops_delta=-69.72%, cpu_delta=-12.90%
- opensnoop: avg_ns_delta=3.84%, ops_delta=0.08%, cpu_delta=-1.32%
- capable: avg_ns_delta=-1.63%, ops_delta=-27.56%, cpu_delta=-20.33%
- vfsstat: avg_ns_delta=0.66%, ops_delta=0.54%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-9.01%, ops_delta=2.53%, cpu_delta=-0.00%
- bindsnoop: avg_ns_delta=0.97%, ops_delta=-0.13%, cpu_delta=0.18%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

