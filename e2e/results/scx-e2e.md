# scx_rusty End-to-End Benchmark

- Generated: 2026-03-28T21:59:55.567837+00:00
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
- Active ops: `[]`

## Baseline

- hackbench: throughput=5.7717115875090705 runs/s, lat_p50_ms=161.0, ctx/s=917175.8551952789, agent_cpu=0.16666625556212486
- stress-ng-cpu: throughput=11613.87 bogo-ops/s, lat_p50_ms=None, ctx/s=136.5235049476974, agent_cpu=0.3666641253176143
- sysbench-cpu: throughput=17650.52 events/s, lat_p50_ms=0.23, ctx/s=124.55269715308557, agent_cpu=0.33333063612182656

## Comparison

- Comparable: `False`
- Reason: `post-ReJIT measurements are unavailable`

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

