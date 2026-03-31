# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T01:09:11.106977+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench']`
- runtime counters exposed via bpftool: `False`

## Loaded Programs

- Programs: `13`; sites total=`733`, cmov=`0`, lea=`0`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.255900457246884 runs/s, lat_p50_ms=297.0, ctx/s=167638.2744629211, agent_cpu=0.06666651794033172

## Post-ReJIT

- hackbench: throughput=3.278726817122443 runs/s, lat_p50_ms=295.0, ctx/s=423783.6876077976, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=0.7010767121197672%, ctx_delta=152.79649827315046%, lat_p50_delta=-0.6734006734006733%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

