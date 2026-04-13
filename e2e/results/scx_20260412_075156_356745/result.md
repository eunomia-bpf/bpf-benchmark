# scx_rusty End-to-End Benchmark

- Generated: 2026-04-12T07:52:33.284419+00:00
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

- hackbench: throughput=2.482271453449547 runs/s, avg_ns=150.688113583438, lat_p50_ms=335.0, ctx/s=132677.50847773644, agent_cpu=0.09990202191120719

## Post-ReJIT

- hackbench: throughput=2.4879311658328263 runs/s, avg_ns=158.66253743023566, lat_p50_ms=331.0, ctx/s=125944.8476147624, agent_cpu=0.09990600904610672

## Comparison

- hackbench: throughput_delta=0.22800537690646047%, bpf_avg_ns_delta=5.29200589028684%, bpf_speedup=0.9497397181719469, ctx_delta=-5.074455301596044%, lat_p50_delta=-1.1940298507462688%, agent_cpu_delta=0.003991045249391161%

