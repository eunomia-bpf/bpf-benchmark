# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-29T01:23:22.002996+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `528.9868221323154` ops/s
- Events/s mean: `145.64715713810514`
- Agent CPU mean: `7.3322514295726755`%
- BPF avg ns mean: `6345.500940438871`

- stress_exec: ops/s=528.9868221323154, events/s=145.64715713810514, agent_cpu=7.3322514295726755, bpf_avg_ns=6345.500940438871

## Per-Program

- execve_rate (tracepoint): sites=10, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=65, stock_avg_ns=6345.500940438871, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `rejit did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

