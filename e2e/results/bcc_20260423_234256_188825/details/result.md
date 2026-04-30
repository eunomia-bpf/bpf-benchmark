# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-23T23:54:10.986855+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools in suite: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with applied sites: `4`
- Aggregate applied sites: `14` (const_prop=4, dce=5, extract=3, endian_fusion=2)
- Geomean speedup: `1.076x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 0 | 541.74 | 558.25 | 0.970x | 391.92 | 372.07 | 1.37 | 1.33 | ok |
| biosnoop | 3 | 148.35 | 148.09 | 1.002x | 933863.67 | 934329.41 | 75.57 | 76.17 | ok |
| runqlat | 6 | 157.55 | 157.30 | 1.002x | 64.46 | 63.75 | 0.00 | 0.00 | ok |
| syscount | 0 | 101.08 | 98.31 | 1.028x | 1147.35 | 1100.33 | 0.03 | 0.03 | ok |
| execsnoop | 0 | 1129.88 | 1162.97 | 0.972x | 1603.88 | 1555.30 | 3.83 | 3.60 | ok |
| opensnoop | 0 | 1939.10 | 1477.55 | 1.312x | 1103.69 | 1130.02 | 2.00 | 2.30 | ok |
| capable | 1 | 40.48 | 46.00 | 0.880x | 2400.58 | 1967.69 | 2.40 | 3.30 | ok |
| vfsstat | 0 | 500.80 | 417.61 | 1.199x | 51.67 | 31.48 | 0.03 | 0.03 | ok |
| tcpconnect | 0 | 17132.58 | 11196.00 | 1.530x | 192.52 | 206.42 | 2.40 | 2.40 | ok |
| bindsnoop | 4 | 452.19 | 448.37 | 1.009x | 162301.92 | 173262.32 | 76.07 | 74.60 | ok |

## Comparison

- tcplife: avg_ns_delta=3.05%, ops_delta=-5.07%, cpu_delta=-2.44%
- biosnoop: avg_ns_delta=-0.18%, ops_delta=0.05%, cpu_delta=0.79%
- runqlat: avg_ns_delta=-0.16%, ops_delta=-1.10%, cpu_delta=n/a%
- syscount: avg_ns_delta=-2.74%, ops_delta=-4.10%, cpu_delta=-0.00%
- execsnoop: avg_ns_delta=2.93%, ops_delta=-3.03%, cpu_delta=-6.09%
- opensnoop: avg_ns_delta=-23.80%, ops_delta=2.39%, cpu_delta=15.00%
- capable: avg_ns_delta=13.65%, ops_delta=-18.03%, cpu_delta=37.50%
- vfsstat: avg_ns_delta=-16.61%, ops_delta=-39.09%, cpu_delta=0.00%
- tcpconnect: avg_ns_delta=-34.65%, ops_delta=7.22%, cpu_delta=-0.00%
- bindsnoop: avg_ns_delta=-0.84%, ops_delta=6.75%, cpu_delta=-1.93%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

