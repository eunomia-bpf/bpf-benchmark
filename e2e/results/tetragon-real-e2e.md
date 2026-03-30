# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-30T04:44:39.551975+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `228.91162211026983` ops/s
- Events/s mean: `156.80524940869637`
- Agent CPU mean: `37.48101673645662`%
- BPF avg ns mean: `5565.828201583511`

- stress_exec: ops/s=228.91162211026983, events/s=156.80524940869637, agent_cpu=37.48101673645662, bpf_avg_ns=5565.828201583511

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=5565.828201583511, rejit_avg_ns=5927.0968510851835, speedup=0.9390479591310326

## Post-ReJIT

- Application throughput mean: `474.5344106469795` ops/s
- Events/s mean: `158.44980677224672`
- Agent CPU mean: `47.07701725036083`%
- BPF avg ns mean: `5927.0968510851835`

- stress_exec: ops/s=474.5344106469795, events/s=158.44980677224672, agent_cpu=47.07701725036083, bpf_avg_ns=5927.0968510851835

## Comparison

- stress_exec: baseline_ops/s=228.91162211026983, post_ops/s=474.5344106469795, app_delta=107.30026997859892%, baseline_cpu=37.48101673645662, post_cpu=47.07701725036083, cpu_delta=25.602295106819994%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

