# scx_rusty End-to-End Benchmark

- Generated: 2026-03-23T13:35:00.805205+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench', 'stress-ng-cpu', 'sysbench-cpu']`
- raw bpftool register usable: `False`
- runtime counters exposed via bpftool: `False`

## Loaded Programs

- Programs: `13`; sites total=`0`, cmov=`0`, lea=`0`
- Active ops: `['rusty_1.1.0_gf33d9a7_x86_64_unknown_linux_gnu']`

## Baseline

- hackbench: throughput=6.758737113072927 runs/s, lat_p50_ms=142.0, ctx/s=926578.8764696561, agent_cpu=0.19999951938782173
- stress-ng-cpu: throughput=11596.27 bogo-ops/s, lat_p50_ms=None, ctx/s=124.21938451389859, agent_cpu=0.2666643347492817
- sysbench-cpu: throughput=17604.26 events/s, lat_p50_ms=0.23, ctx/s=111.85889830776259, agent_cpu=0.3333314321663985

## Post-ReJIT

- hackbench: throughput=6.7315065864403 runs/s, lat_p50_ms=143.0, ctx/s=934324.2832610552, agent_cpu=0.16666625481768438
- stress-ng-cpu: throughput=11579.59 bogo-ops/s, lat_p50_ms=None, ctx/s=91.60995308516227, agent_cpu=0.23333253734271553
- sysbench-cpu: throughput=17650.67 events/s, lat_p50_ms=0.23, ctx/s=86.89272309272175, agent_cpu=0.29999668382665723

## Comparison

- hackbench: throughput_delta=-0.40289370894388987%, ctx_delta=0.8359144578073883%, lat_p50_delta=0.7042253521126761%, agent_cpu_delta=-16.666672336097157%
- stress-ng-cpu: throughput_delta=-0.14383935524095498%, ctx_delta=-26.25148366041673%, lat_p50_delta=None%, agent_cpu_delta=-12.499533332008866%
- sysbench-cpu: throughput_delta=0.26362937152711824%, ctx_delta=-22.31934659891807%, lat_p50_delta=0.0%, agent_cpu_delta=-10.000481539676885%

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.
