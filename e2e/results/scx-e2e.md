# scx_rusty End-to-End Benchmark

- Generated: 2026-03-23T08:46:45.054949+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2+`
- Scheduler binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/repos/scx/target/release/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench', 'stress-ng-cpu', 'sysbench-cpu']`
- raw bpftool register usable: `False`
- runtime counters exposed via bpftool: `False`

## Loaded Programs

- Programs: `13`; sites total=`0`, cmov=`0`, lea=`0`
- Active ops: `['rusty_1.1.0_gf33d9a7_x86_64_unknown_linux_gnu']`

## Baseline

- hackbench: throughput=6.773842637085024 runs/s, lat_p50_ms=139.5, ctx/s=968359.0572591372, agent_cpu=0.19999952878777688
- stress-ng-cpu: throughput=11606.3 bogo-ops/s, lat_p50_ms=None, ctx/s=120.32911166801237, agent_cpu=0.3666645796852133
- sysbench-cpu: throughput=17619.38 events/s, lat_p50_ms=0.23, ctx/s=111.08352173622029, agent_cpu=0.2666658194338032

## Post-ReJIT

- hackbench: throughput=6.8322647766907565 runs/s, lat_p50_ms=141.0, ctx/s=954185.9729608336, agent_cpu=0.19999951799449545
- stress-ng-cpu: throughput=11599.18 bogo-ops/s, lat_p50_ms=None, ctx/s=96.87759213652535, agent_cpu=0.2999983069095559
- sysbench-cpu: throughput=17619.8 events/s, lat_p50_ms=0.23, ctx/s=83.77778442192158, agent_cpu=0.2333324464367038

## Comparison

- hackbench: throughput_delta=0.8624667376517798%, ctx_delta=-1.4636187054850671%, lat_p50_delta=1.0752688172043012%, agent_cpu_delta=-5.396653432481764e-06%
- stress-ng-cpu: throughput_delta=-0.06134599312441503%, ctx_delta=-19.489481145834176%, lat_p50_delta=None%, agent_cpu_delta=-18.181814243658696%
- sysbench-cpu: throughput_delta=0.002383738814863257%, ctx_delta=-24.581267219038217%, lat_p50_delta=0.0%, agent_cpu_delta=-12.500054588126176%

## Limitations

- Raw `bpftool struct_ops register` returned success but did not leave sched_ext enabled, so the standalone bpftool path is not a usable end-to-end loader here.
- bpftool does not expose per-program run_cnt/run_time_ns for these struct_ops programs on this kernel, so BPF runtime deltas are unavailable.
