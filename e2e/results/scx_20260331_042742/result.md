# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T04:28:58.402120+00:00
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

- hackbench: throughput=3.293821515806483 runs/s, lat_p50_ms=292.0, ctx/s=158710.66039997365, agent_cpu=0.09999955403198871

## Post-ReJIT

- hackbench: throughput=3.269968752490717 runs/s, lat_p50_ms=294.0, ctx/s=418333.113963844, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=-0.7241668439319205%, ctx_delta=163.58224010257692%, lat_p50_delta=0.684931506849315%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

