# BCC libbpf-tools Real End-to-End Benchmark

- Generated: `2026-04-13T08:37:28.032861+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`
- Setup rc: `0`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Tools selected: `10`
- Baseline successes: `10`
- ReJIT successes: `10`
- Tools with applied sites: `9`
- Aggregate applied sites: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2)
- Geomean speedup: `0.934x`

## Per-Tool

| Tool | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 39 | 1142.64 | 1268.44 | 0.901x | 12.02 | 11.82 | 0.07 | 0.00 | ok |
| biosnoop | 23 | 294.92 | 295.28 | 0.999x | 61718.32 | 61691.22 | 5.49 | 5.39 | ok |
| runqlat | 26 | 144.00 | 141.89 | 1.015x | 17.77 | 17.89 | 0.00 | 0.00 | ok |
| syscount | 65 | 74.26 | 77.61 | 0.957x | 1070.34 | 1072.35 | 0.00 | 0.03 | ok |
| execsnoop | 432 | 1396.29 | 1385.77 | 1.008x | 4763.05 | 4802.61 | 1.90 | 1.83 | ok |
| opensnoop | 129 | 696.37 | 868.31 | 0.802x | 1096.20 | 1084.23 | 1.53 | 1.40 | ok |
| capable | 57 | 108.38 | 106.99 | 1.013x | 4737.06 | 4709.02 | 15.45 | 15.82 | ok |
| vfsstat | 0 | 28.48 | 36.29 | 0.785x | 77.23 | 72.88 | 0.00 | 0.00 | ok |
| tcpconnect | 76 | 2339.52 | 2516.61 | 0.930x | 10.58 | 11.32 | 0.03 | 0.00 | ok |
| bindsnoop | 114 | 500.41 | 516.37 | 0.969x | 259764.75 | 242668.62 | 35.76 | 35.63 | ok |

## Comparison

- tcplife: avg_ns_delta=11.01%, ops_delta=-1.69%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=0.12%, ops_delta=-0.04%, cpu_delta=-1.82%
- runqlat: avg_ns_delta=-1.46%, ops_delta=0.69%, cpu_delta=n/a%
- syscount: avg_ns_delta=4.50%, ops_delta=0.19%, cpu_delta=n/a%
- execsnoop: avg_ns_delta=-0.75%, ops_delta=0.83%, cpu_delta=-3.52%
- opensnoop: avg_ns_delta=24.69%, ops_delta=-1.09%, cpu_delta=-8.70%
- capable: avg_ns_delta=-1.28%, ops_delta=-0.59%, cpu_delta=2.37%
- vfsstat: avg_ns_delta=27.41%, ops_delta=-5.63%, cpu_delta=n/a%
- tcpconnect: avg_ns_delta=7.57%, ops_delta=6.94%, cpu_delta=-100.00%
- bindsnoop: avg_ns_delta=3.19%, ops_delta=-6.58%, cpu_delta=-0.37%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the libbpf-tool-owned BPF programs.
- `Ops/s` is application workload throughput while the tool is tracing; `CPU%` is the tool process CPU from `/proc/<pid>/stat`.
- Tools that fail to attach or have no applicable ReJIT passes show `n/a` ReJIT columns.

