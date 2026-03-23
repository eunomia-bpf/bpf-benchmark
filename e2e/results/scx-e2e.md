# scx_rusty End-to-End Benchmark

- Generated: 2026-03-23T12:08:42.781607+00:00
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

- hackbench: throughput=6.621168992947409 runs/s, lat_p50_ms=144.0, ctx/s=917778.7334589735, agent_cpu=0.16666400597025424
- stress-ng-cpu: throughput=11587.24 bogo-ops/s, lat_p50_ms=None, ctx/s=119.6372690436867, agent_cpu=0.29999922989197714
- sysbench-cpu: throughput=17631.87 events/s, lat_p50_ms=0.23, ctx/s=116.44801500471395, agent_cpu=0.2999991416324563

## Post-ReJIT

- hackbench: throughput=6.703951298487613 runs/s, lat_p50_ms=142.0, ctx/s=946304.6088832034, agent_cpu=0.1666659771250752
- stress-ng-cpu: throughput=11598.98 bogo-ops/s, lat_p50_ms=None, ctx/s=95.87872558234442, agent_cpu=0.29999850294747055
- sysbench-cpu: throughput=17635.74 events/s, lat_p50_ms=0.23, ctx/s=86.29268638357276, agent_cpu=0.2666643729708404

## Comparison

- hackbench: throughput_delta=1.2502672206128682%, ctx_delta=3.108142996157696%, lat_p50_delta=-1.3888888888888888%, agent_cpu_delta=0.0011827117735925068%
- stress-ng-cpu: throughput_delta=0.10131834673312869%, ctx_delta=-19.858814607901675%, lat_p50_delta=None%, agent_cpu_delta=-0.00024231545756042607%
- sysbench-cpu: throughput_delta=0.021948891410852166%, ctx_delta=-25.895957625315013%, lat_p50_delta=0.0%, agent_cpu_delta=-11.11162134672237%

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.
