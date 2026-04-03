# scx_rusty End-to-End Benchmark

- Generated: 2026-04-03T04:57:03.135809+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters exposed via bpftool: `False`

## Loaded Programs

- Programs: `13`; applied sites total=`359`, breakdown=`map_inline=145, const_prop=150, dce=57, extract=6, bulk_memory=1`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.231404578385113 runs/s, lat_p50_ms=296.0, ctx/s=169742.2179038468, agent_cpu=0.06666501693638108

## Post-ReJIT

- hackbench: throughput=3.270831218904767 runs/s, lat_p50_ms=295.0, ctx/s=430887.11349851626, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=1.2201084563467852%, ctx_delta=153.8479341318606%, lat_p50_delta=-0.33783783783783783%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

