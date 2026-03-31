# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-03-31T18:01:34.415384+00:00`
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
- Geomean speedup: `1.012x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 748.34 | 736.71 | 1.016x | 28.56 | 28.95 | 0.03 | 0.00 | ok |
| biosnoop | 50 | 319.62 | 320.56 | 0.997x | 291708.30 | 305017.88 | 25.63 | 28.17 | ok |
| runqlat | 62 | 158.16 | 160.45 | 0.986x | 62.66 | 62.31 | 0.00 | 0.00 | ok |
| syscount | 65 | 56.30 | 53.13 | 1.060x | 363393.42 | 376335.01 | 0.03 | 0.00 | ok |
| execsnoop | 432 | 1702.39 | 1681.56 | 1.012x | 606.59 | 421.56 | 1.10 | 0.97 | ok |
| opensnoop | 129 | 57.29 | 56.47 | 1.015x | 451705.52 | 450020.81 | 2.37 | 2.33 | ok |
| capable | 55 | 103.67 | 102.27 | 1.014x | 217.77 | 31.87 | 1.83 | 1.73 | ok |
| vfsstat | 0 | 25.00 | 25.29 | 0.988x | 52484.54 | 52560.09 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 3294.54 | 3118.43 | 1.056x | 22.45 | 23.66 | 0.07 | 0.00 | ok |
| bindsnoop | 100 | 476.21 | 485.83 | 0.980x | 327044.80 | 326372.61 | 39.97 | 39.97 | ok |

## Comparison

- tcplife: avg_ns_delta=-1.55%, ops_delta=1.38%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=0.29%, ops_delta=4.56%, cpu_delta=9.88%
- runqlat: avg_ns_delta=1.45%, ops_delta=-0.55%, cpu_delta=n/a%
- syscount: avg_ns_delta=-5.63%, ops_delta=3.56%, cpu_delta=-100.00%
- execsnoop: avg_ns_delta=-1.22%, ops_delta=-30.50%, cpu_delta=-12.12%
- opensnoop: avg_ns_delta=-1.44%, ops_delta=-0.37%, cpu_delta=-1.41%
- capable: avg_ns_delta=-1.36%, ops_delta=-85.37%, cpu_delta=-5.49%
- vfsstat: avg_ns_delta=1.16%, ops_delta=0.14%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=-5.35%, ops_delta=5.40%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=2.02%, ops_delta=-0.21%, cpu_delta=0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

