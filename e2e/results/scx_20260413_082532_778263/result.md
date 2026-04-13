# scx_rusty End-to-End Benchmark

- Generated: 2026-04-13T08:26:50.604338+00:00
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

- hackbench: throughput=2.636110190559921 runs/s, avg_ns=154.96640143717516, lat_p50_ms=333.0, ctx/s=129546.09948366715, agent_cpu=0.0999016537084782

## Post-ReJIT

- hackbench: throughput=2.664523372027625 runs/s, avg_ns=159.6438821280988, lat_p50_ms=332.0, ctx/s=133485.75979090107, agent_cpu=0.06660219234332648

## Comparison

- hackbench: throughput_delta=1.077844984229165%, bpf_avg_ns_delta=3.0183837577333983%, bpf_speedup=0.9707005327822684, ctx_delta=3.041126149638047%, lat_p50_delta=-0.3003003003003003%, agent_cpu_delta=-33.332242389422774%

