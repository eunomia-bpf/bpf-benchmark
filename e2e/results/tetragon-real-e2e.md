# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-28T04:02:59.652444+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `5s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `261.55826440823324` ops/s
- Events/s mean: `161.26780529561543`
- Agent CPU mean: `42.19483581623932`%
- BPF avg ns mean: `5624.81441806601`

- stress_exec: ops/s=261.55826440823324, events/s=161.26780529561543, agent_cpu=42.19483581623932, bpf_avg_ns=5624.81441806601

## Per-Program

- execve_rate (tracepoint): sites=54, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=293, stock_avg_ns=5624.81441806601, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `rejit did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

