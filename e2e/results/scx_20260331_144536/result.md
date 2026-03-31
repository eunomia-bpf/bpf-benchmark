# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T14:46:52.405645+00:00
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

- hackbench: throughput=3.2676679350099676 runs/s, lat_p50_ms=296.0, ctx/s=150875.32500997614, agent_cpu=0.09999905516559365

## Post-ReJIT

- hackbench: throughput=3.2516850058913356 runs/s, lat_p50_ms=298.0, ctx/s=430617.5263670207, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=-0.4891234187963233%, ctx_delta=185.4128243558365%, lat_p50_delta=0.6756756756756757%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

