# scx_rusty End-to-End Benchmark

- Generated: 2026-03-28T14:39:19.670199+00:00
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

- Programs: `13`; sites total=`3345`, cmov=`0`, lea=`0`
- Active ops: `['rusty_1.1.0_x86_64_unknown_linux_gnu']`

## Baseline

- hackbench: throughput=5.964505575792195 runs/s, lat_p50_ms=155.0, ctx/s=959809.5034643677, agent_cpu=0.13333301862740987
- stress-ng-cpu: throughput=11621.65 bogo-ops/s, lat_p50_ms=None, ctx/s=134.75881338371113, agent_cpu=0.2999988601843304
- sysbench-cpu: throughput=17651.11 events/s, lat_p50_ms=0.23, ctx/s=124.601219244538, agent_cpu=0.3666639835051909

## Comparison

- Comparable: `False`
- Reason: `post-ReJIT measurements are unavailable`

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

