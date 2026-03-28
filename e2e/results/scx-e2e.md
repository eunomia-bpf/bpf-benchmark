# scx_rusty End-to-End Benchmark

- Generated: 2026-03-28T21:04:14.448338+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench', 'stress-ng-cpu', 'sysbench-cpu']`
- raw bpftool register usable: `False`
- runtime counters exposed via bpftool: `False`

## Loaded Programs

- Programs: `13`; sites total=`3421`, cmov=`0`, lea=`0`
- Active ops: `['rusty_1.1.0_x86_64_unknown_linux_gnu']`

## Baseline

- hackbench: throughput=5.77984013205148 runs/s, lat_p50_ms=156.0, ctx/s=953041.5265133631, agent_cpu=0.1999995172544985
- stress-ng-cpu: throughput=11616.64 bogo-ops/s, lat_p50_ms=None, ctx/s=135.37420698005386, agent_cpu=0.29999890490399617
- sysbench-cpu: throughput=17648.2 events/s, lat_p50_ms=0.23, ctx/s=118.10959697133089, agent_cpu=0.36666534477698626

## Comparison

- Comparable: `False`
- Reason: `post-ReJIT measurements are unavailable`

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

