# scx_rusty End-to-End Benchmark

- Generated: 2026-04-16T02:53:27.131685+00:00
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

- hackbench: throughput=3.435812638777652 runs/s, avg_ns=153.50860259698618, lat_p50_ms=285.0, ctx/s=101418.64783803863, agent_cpu=0.09999977737716254

## Post-ReJIT

- hackbench: throughput=3.4236106684137013 runs/s, avg_ns=159.3612257223444, lat_p50_ms=287.0, ctx/s=102928.99336530034, agent_cpu=0.0666627644550889

## Comparison

- hackbench: throughput_delta=-0.35514073806689617%, bpf_avg_ns_delta=3.812570127241267%, bpf_speedup=0.9632744847510445, ctx_delta=1.4892187575540081%, lat_p50_delta=0.7017543859649122%, agent_cpu_delta=-33.33708713804295%

