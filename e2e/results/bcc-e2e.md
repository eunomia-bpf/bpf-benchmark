# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-29T09:03:47.908621+00:00`
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
- Geomean speedup: `1.015x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 1036.89 | 1024.20 | 1.012x | 28.10 | 27.76 | 0.10 | 0.07 | ok |
| biosnoop | 50 | 7087.69 | 5491.82 | 1.291x | 15328.01 | 15162.61 | 0.00 | 0.00 | ok |
| runqlat | 62 | 216.86 | 213.41 | 1.016x | 66.42 | 66.68 | 0.00 | 0.00 | ok |
| syscount | 65 | 68.12 | 68.39 | 0.996x | 7636.94 | 7693.66 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1733.25 | 1739.47 | 0.996x | 57.23 | 56.46 | 0.17 | 0.17 | ok |
| opensnoop | 129 | 619.05 | 711.88 | 0.870x | 7514.38 | 7619.87 | 0.03 | 0.03 | ok |
| capable | 57 | 252.87 | 249.65 | 1.013x | 569.25 | 137.89 | 0.20 | 0.30 | ok |
| vfsstat | 0 | 22.95 | 22.78 | 1.008x | 11978.08 | 12567.92 | 0.03 | 0.00 | ok |
| tcpconnect | 76 | 3873.62 | 4072.91 | 0.951x | 22.88 | 21.79 | 0.07 | 0.07 | ok |
| bindsnoop | 106 | 222.34 | 212.30 | 1.047x | 394154.99 | 400315.67 | 6.40 | 6.07 | ok |

## Comparison

- tcplife: avg_ns_delta=-1.22%, ops_delta=-1.21%, cpu_delta=-33.33%
- biosnoop: avg_ns_delta=-22.52%, ops_delta=-1.08%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.59%, ops_delta=0.40%, cpu_delta=n/a%
- syscount: avg_ns_delta=0.39%, ops_delta=0.74%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=0.36%, ops_delta=-1.35%, cpu_delta=0.00%
- opensnoop: avg_ns_delta=15.00%, ops_delta=1.40%, cpu_delta=0.00%
- capable: avg_ns_delta=-1.27%, ops_delta=-75.78%, cpu_delta=49.97%
- vfsstat: avg_ns_delta=-0.76%, ops_delta=4.92%, cpu_delta=-100.00%
- tcpconnect: avg_ns_delta=5.14%, ops_delta=-4.75%, cpu_delta=0.00%
- bindsnoop: avg_ns_delta=-4.52%, ops_delta=1.56%, cpu_delta=-5.21%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

