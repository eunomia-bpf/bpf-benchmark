# scx_rusty End-to-End Benchmark

- Generated: 2026-03-28T18:55:04.482633+00:00
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

- hackbench: throughput=5.7184761406482565 runs/s, lat_p50_ms=161.0, ctx/s=930073.0406754334, agent_cpu=0.16666625156214532
- stress-ng-cpu: throughput=11570.64 bogo-ops/s, lat_p50_ms=None, ctx/s=132.7675225698794, agent_cpu=0.39999737743052954
- sysbench-cpu: throughput=17641.13 events/s, lat_p50_ms=0.23, ctx/s=117.97755843060109, agent_cpu=0.3666637804482731

## Comparison

- Comparable: `False`
- Reason: `post-ReJIT measurements are unavailable`

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

