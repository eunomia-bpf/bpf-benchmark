# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T16:35:10.974951+00:00
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

- hackbench: throughput=3.2784088115538035 runs/s, lat_p50_ms=294.0, ctx/s=155935.46197664438, agent_cpu=0.06666566199069648

## Post-ReJIT

- hackbench: throughput=3.3059029709381735 runs/s, lat_p50_ms=292.0, ctx/s=416939.39174674207, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.8386434079689771%, ctx_delta=167.37945715592917%, lat_p50_delta=-0.6802721088435374%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

