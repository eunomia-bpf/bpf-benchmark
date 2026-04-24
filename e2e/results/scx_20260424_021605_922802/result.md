# scx_rusty End-to-End Benchmark

- Generated: 2026-04-24T02:17:20.649878+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `10s`
- Smoke: `True`
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

- hackbench: throughput=3.21632306207062 runs/s, avg_ns=176.84694993322972, lat_p50_ms=305.0, ctx/s=85437.91849916788, agent_cpu=0.09999904104919648
- stress-ng-cpu: throughput=11632.27 bogo-ops/s, avg_ns=199.94174337431272, lat_p50_ms=None, ctx/s=319.77902147094363, agent_cpu=0.0999131157144353
- sysbench-cpu: throughput=17668.01 events/s, avg_ns=173.12392523364485, lat_p50_ms=0.23, ctx/s=317.1694048315009, agent_cpu=0.0999731339098071

## Post-ReJIT

- hackbench: throughput=3.2232183544144197 runs/s, avg_ns=181.37153902251006, lat_p50_ms=304.0, ctx/s=78095.35750910698, agent_cpu=0.0999987539255288
- stress-ng-cpu: throughput=11619.0 bogo-ops/s, avg_ns=278.99233576642337, lat_p50_ms=None, ctx/s=323.0130486502607, agent_cpu=0.0999725375939087
- sysbench-cpu: throughput=17648.12 events/s, avg_ns=222.02080616478958, lat_p50_ms=0.23, ctx/s=332.3601249119891, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.21438432056513768%, bpf_avg_ns_delta=2.558477311024387%, bpf_speedup=0.9750534779951402, ctx_delta=-8.594030752437408%, lat_p50_delta=-0.32786885245901637%, agent_cpu_delta=-0.0002871264210760376%
- stress-ng-cpu: throughput_delta=-0.11407919520437916%, bpf_avg_ns_delta=39.53681260251859%, bpf_speedup=0.716656759853457, ctx_delta=1.0113318767569428%, lat_p50_delta=None%, agent_cpu_delta=0.059473552644716134%
- sysbench-cpu: throughput_delta=-0.11257634560994374%, bpf_avg_ns_delta=28.243861075327626%, bpf_speedup=0.7797644203901675, ctx_delta=4.789465770999691%, lat_p50_delta=0.0%, agent_cpu_delta=-100.0%

