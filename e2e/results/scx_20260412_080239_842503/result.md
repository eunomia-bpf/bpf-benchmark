# scx_rusty End-to-End Benchmark

- Generated: 2026-04-12T08:03:16.050218+00:00
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

- hackbench: throughput=2.432607777299376 runs/s, avg_ns=150.911075570542, lat_p50_ms=330.0, ctx/s=118495.73048314083, agent_cpu=0.19980267190416748

## Post-ReJIT

- hackbench: throughput=2.607275647481502 runs/s, avg_ns=158.66079478823764, lat_p50_ms=332.0, ctx/s=132453.85178570807, agent_cpu=0.099976134896791

## Comparison

- hackbench: throughput_delta=7.180272619864697%, bpf_avg_ns_delta=5.135288572026042%, bpf_speedup=0.9511554241989076, ctx_delta=11.779429727683869%, lat_p50_delta=0.6060606060606061%, agent_cpu_delta=-49.96256359137023%

