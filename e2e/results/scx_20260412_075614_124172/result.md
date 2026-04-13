# scx_rusty End-to-End Benchmark

- Generated: 2026-04-12T07:56:49.390704+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `10s`
- Smoke: `True`
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

- hackbench: throughput=2.557567898167222 runs/s, avg_ns=151.72334642318035, lat_p50_ms=329.0, ctx/s=124010.95877434792, agent_cpu=0.19981831294101146

## Post-ReJIT

- hackbench: throughput=2.5545337971993223 runs/s, avg_ns=157.8906623380949, lat_p50_ms=336.0, ctx/s=135558.49747697965, agent_cpu=0.09990758736993617

## Comparison

- hackbench: throughput_delta=-0.11863227443830783%, bpf_avg_ns_delta=4.064843058307544%, bpf_speedup=0.9609393245706428, ctx_delta=9.311708268979515%, lat_p50_delta=2.127659574468085%, agent_cpu_delta=-50.000785263645994%

