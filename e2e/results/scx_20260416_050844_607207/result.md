# scx_rusty End-to-End Benchmark

- Generated: 2026-04-16T05:09:57.606460+00:00
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

- hackbench: throughput=3.398093691979478 runs/s, avg_ns=152.84505648102706, lat_p50_ms=289.0, ctx/s=101674.394672362, agent_cpu=0.06666649467155478

## Post-ReJIT

- hackbench: throughput=3.410293372438828 runs/s, avg_ns=159.25929024341437, lat_p50_ms=286.0, ctx/s=102821.5371262288, agent_cpu=0.06666649411155803

## Comparison

- hackbench: throughput_delta=0.3590154235048009%, bpf_avg_ns_delta=4.19655951593274%, bpf_speedup=0.959724586536938, ctx_delta=1.128251077927114%, lat_p50_delta=-1.0380622837370241%, agent_cpu_delta=-8.399972822630625e-07%

