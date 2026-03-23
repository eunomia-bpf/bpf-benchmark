# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-23T11:04:41.088144+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `674900.7014927142` ops/s
- Events/s mean: `0.0`
- Agent CPU mean: `0.008333261253401239`%
- BPF avg ns mean: `None`

- stress_exec: ops/s=638443.241163636, events/s=0.0, agent_cpu=0.033333045013604956, bpf_avg_ns=None
- file_io: ops/s=1526503.4770933718, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None
- open_storm: ops/s=515265.1539009436, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None
- connect_storm: ops/s=19390.933812905336, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None

## Per-Program

- event_exit_acct (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_wake_up_n (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_rate (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_map_upda (socket_filter): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `recompile did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
