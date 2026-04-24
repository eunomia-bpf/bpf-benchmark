# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-23T22:14:15.212583+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `2437.288780699209` ops/s
- Events/s mean: `10047.832512364923`
- Agent CPU mean: `6.865787719279238`%
- BPF avg ns mean: `1492.9434597813186`

- exec_storm: ops/s=2437.288780699209, events/s=10047.832512364923, agent_cpu=6.865787719279238, bpf_avg_ns=1492.9434597813186

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1541.1131763451735, rejit_avg_ns=1446.3993662143496, speedup=1.0654824748566627
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=948.466723261312, rejit_avg_ns=481.3628993071178, speedup=1.9703777017849768
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=3413.5720485089064, rejit_avg_ns=3546.4762056102904, speedup=0.962525010913329
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=516.3116579482953, rejit_avg_ns=527.4299382767676, speedup=0.9789198914934593
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2459.286819206463` ops/s
- Events/s mean: `10143.100968979357`
- Agent CPU mean: `5.031250994643535`%
- BPF avg ns mean: `1326.1044992743107`

- exec_storm: ops/s=2459.286819206463, events/s=10143.100968979357, agent_cpu=5.031250994643535, bpf_avg_ns=1326.1044992743107

## Comparison

- exec_storm: baseline_ops/s=2437.288780699209, post_ops/s=2459.286819206463, app_delta=0.9025618417257568%, baseline_cpu=6.865787719279238, post_cpu=5.031250994643535, cpu_delta=-26.719974453685712%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

