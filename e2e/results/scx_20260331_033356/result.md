# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T03:35:09.923199+00:00
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

- hackbench: throughput=3.2486119199800614 runs/s, lat_p50_ms=294.5, ctx/s=160508.77685552507, agent_cpu=0.09999963853797295

## Post-ReJIT

- hackbench: throughput=3.2464577431643784 runs/s, lat_p50_ms=298.0, ctx/s=428122.93776950147, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=-0.06631068495544382%, ctx_delta=166.72867749460053%, lat_p50_delta=1.1884550084889642%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

