# scx_rusty End-to-End Benchmark

- Generated: 2026-03-31T17:14:15.720270+00:00
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

- hackbench: throughput=3.2824313396723346 runs/s, lat_p50_ms=294.0, ctx/s=156839.6754138503, agent_cpu=0.06666651519812204

## Post-ReJIT

- hackbench: throughput=3.2664583738711412 runs/s, lat_p50_ms=295.0, ctx/s=421886.6308182329, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=-0.48661995174552003%, ctx_delta=168.99228763704565%, lat_p50_delta=0.3401360544217687%, agent_cpu_delta=-100.0%

## Limitations

- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

