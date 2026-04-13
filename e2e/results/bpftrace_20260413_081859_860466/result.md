# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-13T08:25:30.281565+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- bpftrace: `bpftrace v0.25.0-be6ee45`
- bpftool: `bpftool v7.5.0
using libbpf v1.5
features: llvm, skeletons`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Scripts with applied sites: `6`
- Aggregate applied sites: `360` (map_inline=47, const_prop=90, dce=83, wide_mem=137, bulk_memory=3)
- Geomean speedup: `1.039x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 33 | 999.56 | 765.10 | 1.306x | 11.74 | 11.35 | 0.07 | 0.00 | ok |
| biosnoop | 18 | 184.17 | 177.46 | 1.038x | 61138.87 | 62599.50 | 0.00 | 0.00 | ok |
| runqlat | 13 | 131.24 | 130.54 | 1.005x | 17.02 | 17.35 | 0.03 | 0.00 | ok |
| tcpretrans | 42 | 7522.15 | 8562.25 | 0.879x | 1.51 | 1.52 | 0.03 | 0.00 | ok |
| capable | 244 | 107.87 | 100.50 | 1.073x | 4600.28 | 4802.30 | 0.00 | 0.00 | ok |
| vfsstat | 10 | 104.83 | 106.90 | 0.981x | 76.56 | 72.25 | 0.03 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-23.46%, ops_delta=-3.35%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=-3.64%, ops_delta=2.39%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-0.53%, ops_delta=1.98%, cpu_delta=-100.00%
- tcpretrans: avg_ns_delta=13.83%, ops_delta=0.31%, cpu_delta=-100.00%
- capable: avg_ns_delta=-6.83%, ops_delta=4.39%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=1.98%, ops_delta=-5.63%, cpu_delta=0.00%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

