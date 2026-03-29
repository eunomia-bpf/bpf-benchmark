# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-29T02:09:35.482743+00:00`
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
- Aggregate sites: `624` (map_inline=184, const_prop=301, dce=131, cmov=0, wide=0, rotate=0, lea=0)
- Geomean speedup: `1.077x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 24 | 1253.23 | 1270.62 | 0.986x | 26.70 | 26.54 | 0.03 | 0.13 | ok |
| biosnoop | 29 | 5310.20 | 6805.31 | 0.780x | 15212.24 | 15115.33 | 0.03 | 0.00 | ok |
| runqlat | 38 | 226.16 | 224.77 | 1.006x | 63.56 | 62.47 | 0.00 | 0.00 | ok |
| syscount | 36 | 72.63 | 71.19 | 1.020x | 7713.11 | 7758.20 | 0.00 | 0.00 | ok |
| execsnoop | 277 | 2826.90 | 2940.43 | 0.961x | 54.22 | 52.79 | 0.27 | 0.30 | ok |
| opensnoop | 72 | 650.05 | 592.45 | 1.097x | 7587.97 | 7702.64 | 0.03 | 0.10 | ok |
| capable | 30 | 294.61 | 255.78 | 1.152x | 443.20 | 89.66 | 0.30 | 0.17 | ok |
| vfsstat | 0 | 22.40 | 23.21 | 0.965x | 14033.83 | 13869.08 | 0.03 | 0.00 | ok |
| tcpconnect | 50 | 18440.18 | 8419.95 | 2.190x | 7.13 | 10.16 | 0.10 | 0.07 | ok |
| bindsnoop | 68 | 250.60 | 241.14 | 1.039x | 240604.10 | 370069.83 | 8.87 | 7.93 | ok |

## Comparison

- tcplife: avg_ns_delta=1.39%, ops_delta=-0.62%, cpu_delta=300.00%
- biosnoop: avg_ns_delta=28.16%, ops_delta=-0.64%, cpu_delta=-100.00%
- runqlat: avg_ns_delta=-0.61%, ops_delta=-1.70%, cpu_delta=n/a%
- syscount: avg_ns_delta=-1.99%, ops_delta=0.58%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=4.02%, ops_delta=-2.64%, cpu_delta=12.50%
- opensnoop: avg_ns_delta=-8.86%, ops_delta=1.51%, cpu_delta=200.00%
- capable: avg_ns_delta=-13.18%, ops_delta=-79.77%, cpu_delta=-44.44%
- vfsstat: avg_ns_delta=3.59%, ops_delta=-1.17%, cpu_delta=-100.00%
- tcpconnect: avg_ns_delta=-54.34%, ops_delta=42.39%, cpu_delta=-33.33%
- bindsnoop: avg_ns_delta=-3.77%, ops_delta=53.81%, cpu_delta=-10.53%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

