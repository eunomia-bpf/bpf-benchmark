# scx_rusty End-to-End Benchmark

- Generated: 2026-04-03T20:40:58.710792+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters available for live scheduler programs: `False`

## Loaded Programs

- Programs: `13`; applied sites total=`359`, breakdown=`map_inline=145, const_prop=150, dce=57, extract=6, bulk_memory=1`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.2697120670488764 runs/s, avg_ns=None, lat_p50_ms=296.0, ctx/s=164660.15658719593, agent_cpu=0.0666664846760524

## Post-ReJIT

- hackbench: throughput=3.292725659107397 runs/s, avg_ns=None, lat_p50_ms=294.0, ctx/s=420599.0061143499, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.7038415489377277%, bpf_avg_ns_delta=None%, bpf_speedup=None, ctx_delta=155.4345962203803%, lat_p50_delta=-0.6756756756756757%, agent_cpu_delta=-100.0%

## Limitations

- selected scx workloads did not accumulate measurable per-program run_cnt/run_time_ns during this run.

