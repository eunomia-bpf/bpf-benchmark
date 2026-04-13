# scx_rusty End-to-End Benchmark

- Generated: 2026-04-13T07:46:38.406212+00:00
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

- hackbench: throughput=2.554184464587789 runs/s, avg_ns=159.12760338841113, lat_p50_ms=339.0, ctx/s=121116.7072701543, agent_cpu=0.06660061542861474

## Post-ReJIT

- hackbench: throughput=2.539303037425395 runs/s, avg_ns=164.36600199259095, lat_p50_ms=340.0, ctx/s=119763.1278317854, agent_cpu=0.09989857733999433

## Comparison

- hackbench: throughput_delta=-0.5826293037451188%, bpf_avg_ns_delta=3.29194840658382%, bpf_speedup=0.9681296707307151, ctx_delta=-1.1175827587103189%, lat_p50_delta=0.2949852507374631%, agent_cpu_delta=49.99647780592913%

