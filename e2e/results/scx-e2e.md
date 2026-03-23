# scx_rusty End-to-End Benchmark

- Generated: 2026-03-23T01:18:38.241899+00:00
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

- hackbench: throughput=6.5738368295320955 runs/s, lat_p50_ms=144.0, ctx/s=924659.221441538, agent_cpu=0.1999951876491297
- stress-ng-cpu: throughput=11624.48 bogo-ops/s, lat_p50_ms=None, ctx/s=120.73708202412386, agent_cpu=0.29999635193436125
- sysbench-cpu: throughput=17624.04 events/s, lat_p50_ms=0.23, ctx/s=113.09783113356384, agent_cpu=0.23333240699589985

## Post-ReJIT

- hackbench: throughput=6.518979315769334 runs/s, lat_p50_ms=145.0, ctx/s=910122.6181780116, agent_cpu=0.16666626765651082
- stress-ng-cpu: throughput=11623.24 bogo-ops/s, lat_p50_ms=None, ctx/s=100.862983305679, agent_cpu=0.3333310115383948
- sysbench-cpu: throughput=17625.07 events/s, lat_p50_ms=0.23, ctx/s=84.46834269734012, agent_cpu=0.26666548444079685

## Comparison

- hackbench: throughput_delta=-0.8344824367456342%, ctx_delta=-1.5721038547437904%, lat_p50_delta=0.6944444444444444%, agent_cpu_delta=-16.664860982100695%
- stress-ng-cpu: throughput_delta=-0.010667143820624937%, ctx_delta=-16.460641904923566%, lat_p50_delta=None%, agent_cpu_delta=11.111688321905696%
- sysbench-cpu: throughput_delta=0.0058442899584819135%, ctx_delta=-25.313914642990355%, lat_p50_delta=0.0%, agent_cpu_delta=14.285661333568092%

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.
