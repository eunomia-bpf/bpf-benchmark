# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-23T08:42:37.476013+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `628856.9349163972` ops/s
- Events/s mean: `0.0`
- Agent CPU mean: `0.016666529710014307`%
- BPF avg ns mean: `None`

- stress_exec: ops/s=387915.31156575726, events/s=0.0, agent_cpu=0.06666611884005723, bpf_avg_ns=None
- file_io: ops/s=1567175.1500199665, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None
- open_storm: ops/s=552010.3997711014, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None
- connect_storm: ops/s=8326.878308763798, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None

## Per-Program

- event_exit_acct (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_wake_up_n (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_rate (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_map_upda (socket_filter): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `recompile did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
