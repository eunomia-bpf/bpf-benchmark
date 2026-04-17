# scx_rusty End-to-End Benchmark

- Generated: 2026-04-16T03:57:37.950193+00:00
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

- hackbench: throughput=3.408939969548306 runs/s, avg_ns=153.01134637450443, lat_p50_ms=288.0, ctx/s=104917.40879385204, agent_cpu=0.06666596130301866

## Post-ReJIT

- hackbench: throughput=3.409254420641585 runs/s, avg_ns=160.32208133694985, lat_p50_ms=287.0, ctx/s=101332.044461103, agent_cpu=0.0666665028848468

## Comparison

- hackbench: throughput_delta=0.009224307147912777%, bpf_avg_ns_delta=4.777903819336353%, bpf_speedup=0.9543997002691076, ctx_delta=-3.4173207039394%, lat_p50_delta=-0.3472222222222222%, agent_cpu_delta=0.000812381337564986%

