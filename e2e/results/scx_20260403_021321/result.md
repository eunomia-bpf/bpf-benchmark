# scx_rusty End-to-End Benchmark

- Generated: 2026-04-03T02:14:41.657168+00:00
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

- Programs: `13`; sites total=`727`, cmov=`0`, lea=`0`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.2516727475265426 runs/s, lat_p50_ms=295.5, ctx/s=166055.22937865576, agent_cpu=0.09999920807960477

## Post-ReJIT

- hackbench: throughput=3.272108516790395 runs/s, lat_p50_ms=296.0, ctx/s=426930.37487589876, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.6284694325220003%, ctx_delta=157.10143334442625%, lat_p50_delta=0.1692047377326565%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

