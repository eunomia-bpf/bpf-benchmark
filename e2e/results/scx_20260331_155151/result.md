# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T15:53:07.292542+00:00
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

- Programs: `13`; sites total=`727`, cmov=`0`, lea=`0`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.2656350472213793 runs/s, lat_p50_ms=295.0, ctx/s=165281.88718187885, agent_cpu=0.09999975933391261

## Post-ReJIT

- hackbench: throughput=3.1551420854124035 runs/s, lat_p50_ms=305.0, ctx/s=438049.9635320726, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=-3.3835061239617277%, ctx_delta=165.03204374114836%, lat_p50_delta=3.389830508474576%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

