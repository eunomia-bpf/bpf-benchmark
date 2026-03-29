# scx_rusty End-to-End Benchmark

- Generated: 2026-03-29T08:50:02.109678+00:00
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

- Programs: `13`; sites total=`732`, cmov=`0`, lea=`0`
- Active ops: `[]`

## Baseline

- hackbench: throughput=5.760678813755709 runs/s, lat_p50_ms=158.0, ctx/s=959337.9635893521, agent_cpu=0.16666186575496367
- stress-ng-cpu: throughput=11617.69 bogo-ops/s, lat_p50_ms=None, ctx/s=127.47279709247879, agent_cpu=0.3333283578853763
- sysbench-cpu: throughput=17674.09 events/s, lat_p50_ms=0.23, ctx/s=120.06176179235939, agent_cpu=0.43332892442819115

## Post-ReJIT

- hackbench: throughput=8.90541268629789 runs/s, lat_p50_ms=101.0, ctx/s=1219302.7875196699, agent_cpu=0.0
- stress-ng-cpu: throughput=11635.67 bogo-ops/s, lat_p50_ms=None, ctx/s=59.42049178922513, agent_cpu=0.0
- sysbench-cpu: throughput=17640.2 events/s, lat_p50_ms=0.23, ctx/s=55.808178501301846, agent_cpu=0.0

## Comparison

- hackbench: throughput_delta=54.58964080818026%, ctx_delta=27.098356762372077%, lat_p50_delta=-36.075949367088604%, agent_cpu_delta=-100.0%
- stress-ng-cpu: throughput_delta=0.15476398492298868%, ctx_delta=-53.38574727742357%, lat_p50_delta=None%, agent_cpu_delta=-100.0%
- sysbench-cpu: throughput_delta=-0.19174961766065138%, ctx_delta=-53.517108471372254%, lat_p50_delta=0.0%, agent_cpu_delta=-100.0%

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.

