# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-28T14:33:36.995618+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `250.91068352620184` ops/s
- Events/s mean: `151.18081443256062`
- Agent CPU mean: `13.29786900097839`%
- BPF avg ns mean: `4620.2683901586115`

- stress_exec: ops/s=250.91068352620184, events/s=151.18081443256062, agent_cpu=13.29786900097839, bpf_avg_ns=4620.2683901586115

## Per-Program

- execve_rate (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=224, stock_avg_ns=4620.2683901586115, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `rejit did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

