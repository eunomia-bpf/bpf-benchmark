# bpftrace Real End-to-End Benchmark

- Generated: `2026-03-31T04:27:40.254588+00:00`
- Mode: `full`
- Duration per phase: `30s`
- Host kernel: `7.0.0-rc2+`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features: llvm, skeletons`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `6`
- Baseline successes: `6`
- ReJIT successes: `6`
- Eligible-site scripts: `5`
- Aggregate sites: `33` (cmov=0, wide=21, rotate=0, lea=0)
- Geomean speedup: `1.027x`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tcplife | 10 | 713.20 | 529.79 | 1.346x | 21.38 | 22.56 | 0.03 | 0.00 | ok |
| biosnoop | 5 | 244.85 | 256.84 | 0.953x | 291449.62 | 321880.99 | 0.00 | 0.00 | ok |
| runqlat | 7 | 137.92 | 136.12 | 1.013x | 53.99 | 54.40 | 0.00 | 0.00 | ok |
| tcpretrans | 5 | 7532.31 | 8424.13 | 0.894x | 2.33 | 2.32 | 0.00 | 0.07 | ok |
| capable | 6 | 111.32 | 111.25 | 1.001x | 182.24 | 983.04 | 0.00 | 0.00 | ok |
| vfsstat | 0 | 33.35 | 33.06 | 1.009x | 51153.11 | 52011.22 | 0.00 | 0.03 | ok |

## Comparison

- tcplife: avg_ns_delta=-25.72%, ops_delta=5.55%, cpu_delta=-100.00%
- biosnoop: avg_ns_delta=4.89%, ops_delta=10.44%, cpu_delta=n/a%
- runqlat: avg_ns_delta=-1.30%, ops_delta=0.75%, cpu_delta=n/a%
- tcpretrans: avg_ns_delta=11.84%, ops_delta=-0.44%, cpu_delta=n/a%
- capable: avg_ns_delta=-0.06%, ops_delta=439.40%, cpu_delta=n/a%
- vfsstat: avg_ns_delta=-0.88%, ops_delta=1.68%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

