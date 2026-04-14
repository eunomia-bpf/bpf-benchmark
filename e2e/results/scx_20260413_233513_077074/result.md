# scx_rusty End-to-End Benchmark

- Generated: 2026-04-13T23:36:30.533802+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/scx/bin/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters available for live scheduler programs: `True`

## Loaded Programs

- Programs: `13`; applied sites total=`139`, breakdown=`const_prop=132, extract=6, bulk_memory=1`
- Active ops: `[]`

## Baseline

- hackbench: throughput=2.5982111401175247 runs/s, avg_ns=153.47582691863, lat_p50_ms=332.0, ctx/s=134604.72508648701, agent_cpu=0.09990159336072274

## Post-ReJIT

- hackbench: throughput=2.6421673022011496 runs/s, avg_ns=159.6092978233732, lat_p50_ms=332.0, ctx/s=136958.3274099779, agent_cpu=0.09990072676967512

## Comparison

- hackbench: throughput_delta=1.6917856060626613%, bpf_avg_ns_delta=3.9963758644513168%, bpf_speedup=0.9615719698765255, ctx_delta=1.748528754825392%, lat_p50_delta=0.0%, agent_cpu_delta=-0.0008674446707638608%

