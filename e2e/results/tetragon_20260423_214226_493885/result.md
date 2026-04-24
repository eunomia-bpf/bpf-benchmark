# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-23T21:43:37.438383+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `2445.8114460869183` ops/s
- Events/s mean: `10096.932626586025`
- Agent CPU mean: `6.66363117187503`%
- BPF avg ns mean: `1487.839387621806`

- exec_storm: ops/s=2445.8114460869183, events/s=10096.932626586025, agent_cpu=6.66363117187503, bpf_avg_ns=1487.839387621806

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1601.8066752001744, rejit_avg_ns=1459.9080766073134, speedup=1.097196940592739
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=933.766352766135, rejit_avg_ns=490.1696752519597, speedup=1.9049859669228932
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=3358.4748083425397, rejit_avg_ns=3473.0928906327936, speedup=0.9669982675673928
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=499.3966054032339, rejit_avg_ns=525.1403750872876, speedup=0.950977355950255
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2475.057153152005` ops/s
- Events/s mean: `10201.045147501252`
- Agent CPU mean: `4.89794390959552`%
- BPF avg ns mean: `1318.229359475929`

- exec_storm: ops/s=2475.057153152005, events/s=10201.045147501252, agent_cpu=4.89794390959552, bpf_avg_ns=1318.229359475929

## Comparison

- exec_storm: baseline_ops/s=2445.8114460869183, post_ops/s=2475.057153152005, app_delta=1.1957465941161247%, baseline_cpu=6.66363117187503, post_cpu=4.89794390959552, cpu_delta=-26.497373830230703%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

