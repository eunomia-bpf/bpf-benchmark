# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-28T18:45:54.064487+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `64.21846551004046` ops/s
- Events/s mean: `142.56076157294817`
- Agent CPU mean: `10.033189764073278`%
- BPF avg ns mean: `5142.128756957329`

- stress_exec: ops/s=64.21846551004046, events/s=142.56076157294817, agent_cpu=10.033189764073278, bpf_avg_ns=5142.128756957329

## Per-Program

- execve_rate (tracepoint): sites=54, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=293, stock_avg_ns=5142.128756957329, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `rejit did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

