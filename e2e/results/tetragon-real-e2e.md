# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-29T08:39:31.354337+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `13.738183401934092` ops/s
- Events/s mean: `157.6244658038263`
- Agent CPU mean: `13.561372246367585`%
- BPF avg ns mean: `5740.139302238339`

- stress_exec: ops/s=13.738183401934092, events/s=157.6244658038263, agent_cpu=13.561372246367585, bpf_avg_ns=5740.139302238339

## Per-Program

- execve_rate (tracepoint): sites=12, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=87, stock_avg_ns=5740.139302238339, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `rejit did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

