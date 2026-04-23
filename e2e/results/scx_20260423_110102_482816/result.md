# scx_rusty End-to-End Benchmark

- Generated: 2026-04-23T11:01:36.967831+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `10s`
- Smoke: `True`
- Kernel: `7.0.0-rc2`
- Scheduler binary: `/artifacts/scx/bin/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters available for live scheduler programs: `True`

## Loaded Programs

- Programs: `13`; applied sites total=`130`, breakdown=`const_prop=123, extract=6, bulk_memory=1`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.233678481524902 runs/s, avg_ns=171.11277479344426, lat_p50_ms=302.0, ctx/s=98424.64782525763, agent_cpu=0.0999987508756042

## Post-ReJIT

- hackbench: throughput=3.2636289105724474 runs/s, avg_ns=177.11927278266728, lat_p50_ms=299.0, ctx/s=87750.57508840224, agent_cpu=0.09999888268248372

## Comparison

- hackbench: throughput_delta=0.9262030600340242%, bpf_avg_ns_delta=3.510256903070889%, bpf_speedup=0.9660878350793973, ctx_delta=-10.8449183946343%, lat_p50_delta=-0.9933774834437087%, agent_cpu_delta=0.00013180852597442105%

## Limitations

- Partial ReJIT/apply errors were reported: prog 316: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 319: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 320: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 321: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 322: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 323: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 324: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 325: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 326: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 327: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 328: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree; prog 329: daemon response fields 'summary.total_sites_applied' and 'passes[].sites_applied' disagree

