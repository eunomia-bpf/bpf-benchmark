# scx_rusty End-to-End Benchmark

- Generated: 2026-04-23T23:42:53.900261+00:00
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

- hackbench: throughput=3.206383140199271 runs/s, avg_ns=175.91549761925887, lat_p50_ms=307.0, ctx/s=87322.86982866099, agent_cpu=0.13333127200075776
- stress-ng-cpu: throughput=11609.67 bogo-ops/s, avg_ns=179.04061143043597, lat_p50_ms=None, ctx/s=260.15233990257605, agent_cpu=0.033326076254744035
- sysbench-cpu: throughput=17662.87 events/s, avg_ns=161.259742873676, lat_p50_ms=0.23, ctx/s=261.6957257471677, agent_cpu=0.03333042084894345

## Post-ReJIT

- hackbench: throughput=3.262119748984707 runs/s, avg_ns=175.6972968269358, lat_p50_ms=300.0, ctx/s=83594.18194020432, agent_cpu=0.13332764912233702
- stress-ng-cpu: throughput=11617.54 bogo-ops/s, avg_ns=188.35861516910145, lat_p50_ms=None, ctx/s=261.14051207907056, agent_cpu=0.03332597319772935
- sysbench-cpu: throughput=17664.42 events/s, avg_ns=167.09249142421547, lat_p50_ms=0.23, ctx/s=258.1888179320555, agent_cpu=0.0333306768217286

## Comparison

- hackbench: throughput_delta=1.7383015799531654%, bpf_avg_ns_delta=-0.12403727657658403%, bpf_speedup=1.001241913201078, ctx_delta=-4.270001542291094%, lat_p50_delta=-2.2801302931596092%, agent_cpu_delta=-0.0027172008234595795%
- stress-ng-cpu: throughput_delta=0.06778831784194383%, bpf_avg_ns_delta=5.2044079073567495%, bpf_speedup=0.9505305147295752, ctx_delta=0.3798436627033892%, lat_p50_delta=None%, agent_cpu_delta=-0.00030923836907222545%
- sysbench-cpu: throughput_delta=0.008775470804004516%, bpf_avg_ns_delta=3.6169898615729466%, bpf_speedup=0.9650926950647277, ctx_delta=-1.3400707272156116%, lat_p50_delta=0.0%, agent_cpu_delta=0.0007679854578157109%

