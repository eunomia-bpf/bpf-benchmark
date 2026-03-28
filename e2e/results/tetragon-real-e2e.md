# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-28T20:54:51.282653+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `503.76835983329386` ops/s
- Events/s mean: `143.57121194269652`
- Agent CPU mean: `29.857786360861464`%
- BPF avg ns mean: `5437.363421314741`

- stress_exec: ops/s=503.76835983329386, events/s=143.57121194269652, agent_cpu=29.857786360861464, bpf_avg_ns=5437.363421314741

## Per-Program

- execve_rate (tracepoint): sites=54, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=295, stock_avg_ns=5437.363421314741, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `rejit did not apply successfully`

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

