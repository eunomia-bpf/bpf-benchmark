# scx_rusty End-to-End Benchmark

- Generated: 2026-04-23T12:06:47.899078+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `10s`
- Smoke: `True`
- Kernel: `7.0.0-rc2`
- Scheduler binary: `/artifacts/scx/bin/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters available for live scheduler programs: `True`

## Loaded Programs

- Programs: `13`; applied sites total=`2`, breakdown=`extract=2`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.258481376884559 runs/s, avg_ns=173.04650103661666, lat_p50_ms=300.0, ctx/s=89171.89758540256, agent_cpu=0.0

## Post-ReJIT

- hackbench: throughput=3.2453325305961984 runs/s, avg_ns=175.0210607135101, lat_p50_ms=302.0, ctx/s=90475.34715616118, agent_cpu=0.0999990114397725

## Comparison

- hackbench: throughput_delta=-0.403526820243241%, bpf_avg_ns_delta=1.1410572678817887%, bpf_speedup=0.9887181595812313, ctx_delta=1.461726851231651%, lat_p50_delta=0.6666666666666667%, agent_cpu_delta=None%

