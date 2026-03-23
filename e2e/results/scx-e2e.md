# scx_rusty End-to-End Benchmark

- Generated: 2026-03-23T11:08:48.611979+00:00
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

- hackbench: throughput=6.208756528781374 runs/s, lat_p50_ms=153.0, ctx/s=761472.911270485, agent_cpu=0.23333277493689136
- stress-ng-cpu: throughput=11423.96 bogo-ops/s, lat_p50_ms=None, ctx/s=123.63939254859733, agent_cpu=0.1666658832481267
- sysbench-cpu: throughput=17363.59 events/s, lat_p50_ms=0.23, ctx/s=112.03108704796946, agent_cpu=0.13333298492979934

## Post-ReJIT

- hackbench: throughput=6.234853241545056 runs/s, lat_p50_ms=150.0, ctx/s=774497.1508812684, agent_cpu=0.23333280380009086
- stress-ng-cpu: throughput=11416.01 bogo-ops/s, lat_p50_ms=None, ctx/s=98.54606598126442, agent_cpu=0.23333200089094233
- sysbench-cpu: throughput=17354.63 events/s, lat_p50_ms=0.23, ctx/s=88.02697727968206, agent_cpu=0.2333321580781419

## Comparison

- hackbench: throughput_delta=0.4203210843058117%, ctx_delta=1.7104009109205236%, lat_p50_delta=-1.9607843137254901%, agent_cpu_delta=1.2369972244549717e-05%
- stress-ng-cpu: throughput_delta=-0.06959057979893932%, ctx_delta=-20.295575746596946%, lat_p50_delta=None%, agent_cpu_delta=39.999858605474344%
- sysbench-cpu: throughput_delta=-0.051602232026897246%, ctx_delta=-21.42629371971489%, lat_p50_delta=0.0%, agent_cpu_delta=74.99957583713645%

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.
