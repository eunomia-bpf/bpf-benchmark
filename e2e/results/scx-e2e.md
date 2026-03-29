# scx_rusty End-to-End Benchmark

- Generated: 2026-03-29T01:55:23.639334+00:00
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

- Programs: `13`; sites total=`411`, cmov=`0`, lea=`0`
- Active ops: `[]`

## Baseline

- hackbench: throughput=5.643627797967676 runs/s, lat_p50_ms=164.0, ctx/s=871206.4911941644, agent_cpu=0.19999949709459883
- stress-ng-cpu: throughput=10309.47 bogo-ops/s, lat_p50_ms=None, ctx/s=138.40713920004754, agent_cpu=0.39999619416954496
- sysbench-cpu: throughput=17477.97 events/s, lat_p50_ms=0.23, ctx/s=124.14086227847042, agent_cpu=0.39999584920307174

## Comparison

- Comparable: `False`
- Reason: `post-ReJIT measurements are unavailable`

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

