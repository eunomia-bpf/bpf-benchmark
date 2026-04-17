# scx_rusty End-to-End Benchmark

- Generated: 2026-04-16T08:18:58.290817+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2`
- Scheduler binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/scx/bin/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters available for live scheduler programs: `True`

## Loaded Programs

- Programs: `13`; applied sites total=`135`, breakdown=`const_prop=128, extract=6, bulk_memory=1`
- Active ops: `[]`

## Baseline

- hackbench: throughput=0.31848802908079027 runs/s, avg_ns=421.2453210835617, lat_p50_ms=3101.4999999999995, ctx/s=13102.724911595344, agent_cpu=0.13333275266475078

## Post-ReJIT

- hackbench: throughput=0.3180331207250282 runs/s, avg_ns=437.0346951575705, lat_p50_ms=3135.0, ctx/s=10870.753706126334, agent_cpu=0.09998400569525338

## Comparison

- hackbench: throughput_delta=-0.14283373760546172%, bpf_avg_ns_delta=3.7482609975095067%, bpf_speedup=0.9638715775910742, ctx_delta=-17.034404832034685%, lat_p50_delta=1.0801225213606467%, agent_cpu_delta=-25.011669153301607%

