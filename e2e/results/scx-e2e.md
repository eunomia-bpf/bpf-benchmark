# scx_rusty End-to-End Benchmark

- Generated: 2026-03-11T16:36:43.475678+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2-g2a6783cc77b6`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench', 'stress-ng-cpu', 'sysbench-cpu']`
- raw bpftool register usable: `False`
- runtime counters exposed via bpftool: `False`

## Loaded Programs

- Programs: `13`; sites total=`28`, cmov=`27`, lea=`1`
- Active ops: `['rusty_1.1.0_gf33d9a7_x86_64_unknown_linux_gnu']`

## Baseline

- hackbench: throughput=2.5242041916991598 runs/s, lat_p50_ms=381.5, ctx/s=194764.50660269364, agent_cpu=0.1333329980052878
- stress-ng-cpu: throughput=7927.96 bogo-ops/s, lat_p50_ms=None, ctx/s=354.94740763867884, agent_cpu=0.06666171008854241
- sysbench-cpu: throughput=12047.28 events/s, lat_p50_ms=0.33, ctx/s=340.40403937972525, agent_cpu=0.0666473922230631

## Recompile

- Applied programs: `0` / `13`
- Site-bearing programs: `7`
- Errors: `['BPF_PROG_JIT_RECOMPILE: Invalid argument']`

## Comparison

- Comparable: `False`
- Reason: `post-ReJIT measurements are unavailable`

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.
- BPF_PROG_JIT_RECOMPILE did not apply to any loaded scx_rusty struct_ops program on this kernel, so post-ReJIT workload measurement was skipped.
