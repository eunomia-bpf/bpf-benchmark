# scx_rusty End-to-End Benchmark

- Generated: 2026-04-23T19:49:59.857214+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2`
- Scheduler binary: `/artifacts/scx/bin/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench', 'stress-ng-cpu', 'sysbench-cpu']`
- runtime counters available for live scheduler programs: `True`

## Loaded Programs

- Programs: `13`; applied sites total=`2`, breakdown=`extract=2`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.2414591315861805 runs/s, avg_ns=174.15365034065508, lat_p50_ms=302.0, ctx/s=86505.67982359367, agent_cpu=0.09999449696618372
- stress-ng-cpu: throughput=11631.02 bogo-ops/s, avg_ns=188.10380170095223, lat_p50_ms=None, ctx/s=269.08876519847587, agent_cpu=0.06666300411455892
- sysbench-cpu: throughput=17655.4 events/s, avg_ns=174.17846423211606, lat_p50_ms=0.23, ctx/s=261.9294824937772, agent_cpu=0.03333112267217581

## Post-ReJIT

- hackbench: throughput=3.2487098430673047 runs/s, avg_ns=175.59392889423194, lat_p50_ms=302.0, ctx/s=83856.89187286909, agent_cpu=0.09999951100572385
- stress-ng-cpu: throughput=11626.22 bogo-ops/s, avg_ns=191.93545215446255, lat_p50_ms=None, ctx/s=265.08957495821454, agent_cpu=0.06664630192496326
- sysbench-cpu: throughput=17650.28 events/s, avg_ns=177.2342133472939, lat_p50_ms=0.23, ctx/s=262.0191185288628, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.22368665427461806%, bpf_avg_ns_delta=0.8270160003879266%, bpf_speedup=0.9917976745400782, ctx_delta=-3.0619815440166596%, lat_p50_delta=0.0%, agent_cpu_delta=0.005014315479609184%
- stress-ng-cpu: throughput_delta=-0.04126895147632015%, bpf_avg_ns_delta=2.0369872479248907%, bpf_speedup=0.9800367758509421, ctx_delta=-1.48619740304341%, lat_p50_delta=None%, agent_cpu_delta=-0.025054660853491863%
- sysbench-cpu: throughput_delta=-0.028999626176708652%, bpf_avg_ns_delta=1.7543782629209765%, bpf_speedup=0.9827586950766101, ctx_delta=0.034221437858851185%, lat_p50_delta=0.0%, agent_cpu_delta=-100.0%

