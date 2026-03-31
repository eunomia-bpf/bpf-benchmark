# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T15:23:57.072487+00:00
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

- Programs: `13`; sites total=`733`, cmov=`0`, lea=`0`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.2652605798292664 runs/s, lat_p50_ms=294.5, ctx/s=164006.50883409914, agent_cpu=0.09999975607059475

## Post-ReJIT

- hackbench: throughput=3.262917721036492 runs/s, lat_p50_ms=297.0, ctx/s=418419.22180967225, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=-0.07175105127128313%, ctx_delta=155.1235464885875%, lat_p50_delta=0.8488964346349746%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

