# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-24T02:16:03.836715+00:00`
- Mode: `smoke`
- Duration per phase: `5s`
- Host kernel: `7.0.0-rc2`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features:`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts in suite: `6`
- Baseline successes: `4`
- ReJIT successes: `4`
- Scripts with applied sites: `3`
- Aggregate applied sites: `13` (map_inline=1, const_prop=2, wide_mem=10)
- Geomean speedup: `1.054x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 2 | 536.87 | 509.50 | 1.054x | 414.98 | 424.24 | 1.00 | 0.60 | ok |
| biosnoop | 5 | 255.00 | 269.86 | 0.945x | 955514.04 | 917295.47 | 87.40 | 86.60 | ok |
| runqlat | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=3, last_program_ids=1097,1098,1099) |
| tcpretrans | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=1, last_program_ids=1105) |
| capable | 6 | 120.40 | 118.85 | 1.013x | 2370.01 | 2394.69 | 7.98 | 7.97 | ok |
| vfsstat | 0 | 102.02 | 83.36 | 1.224x | 71.74 | 71.13 | 0.00 | 0.00 | ok |

## Comparison

- tcplife: avg_ns_delta=-5.10%, ops_delta=2.23%, cpu_delta=-40.00%
- biosnoop: avg_ns_delta=5.83%, ops_delta=-4.00%, cpu_delta=-0.91%
- runqlat: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%
- capable: avg_ns_delta=-1.29%, ops_delta=1.04%, cpu_delta=-0.24%
- vfsstat: avg_ns_delta=-18.29%, ops_delta=-0.86%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

