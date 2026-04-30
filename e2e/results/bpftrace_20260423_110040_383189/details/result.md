# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-23T11:01:00.414999+00:00`
- Mode: `smoke`
- Duration per phase: `5s`
- Host kernel: `7.0.0-rc2`
- bpftrace: `bpftrace v0.20.2`
- bpftool: `bpftool v7.7.0
using libbpf v1.7
features:`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`

## Summary

- Scripts selected: `1`
- Baseline successes: `0`
- ReJIT successes: `0`
- Scripts with applied sites: `0`
- Aggregate applied sites: `0` (none)
- Geomean speedup: `n/a`

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Ops/s Stock | Ops/s ReJIT | CPU% Stock | CPU% ReJIT | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| capable | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=1, last_program_ids=309) |

## Comparison

- capable: avg_ns_delta=n/a%, ops_delta=n/a%, cpu_delta=n/a%

## Notes

- `Stock ns` and `ReJIT ns` are weighted averages of `delta(run_time_ns) / delta(run_cnt)` across the attached bpftrace-owned programs.
- `Ops/s` is application throughput while the bpftrace script is attached; `CPU%` is bpftrace process CPU from `/proc/<pid>/stat` over the same interval.
- Scripts that fail to attach or have no applicable ReJIT passes are marked with `n/a` ReJIT fields instead of a fake comparison.

