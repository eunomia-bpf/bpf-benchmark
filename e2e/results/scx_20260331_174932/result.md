# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T17:50:48.737461+00:00
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

- hackbench: throughput=3.2295162692315285 runs/s, lat_p50_ms=296.0, ctx/s=164127.51267047276, agent_cpu=0.06666651899366034

## Post-ReJIT

- hackbench: throughput=3.2538351864810244 runs/s, lat_p50_ms=295.0, ctx/s=413514.47473393753, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.7530204285139807%, ctx_delta=151.94707944192868%, lat_p50_delta=-0.33783783783783783%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

