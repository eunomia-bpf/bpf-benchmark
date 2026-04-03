# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-03T02:06:37.937346+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `616.9796423108305` ops/s
- Events/s mean: `1035.7234711021563`
- Agent CPU mean: `45.232861976756226`%
- BPF avg ns mean: `2674.0661391698304`

- exec_storm: ops/s=616.9796423108305, events/s=1035.7234711021563, agent_cpu=45.232861976756226, bpf_avg_ns=2674.0661391698304

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2674.0661391698304, rejit_avg_ns=2252.0023165539696, speedup=1.1874171351926963

## Post-ReJIT

- Application throughput mean: `387.8138853325092` ops/s
- Events/s mean: `1053.966883874568`
- Agent CPU mean: `41.25693896119912`%
- BPF avg ns mean: `2252.0023165539696`

- exec_storm: ops/s=387.8138853325092, events/s=1053.966883874568, agent_cpu=41.25693896119912, bpf_avg_ns=2252.0023165539696

## Comparison

- exec_storm: baseline_ops/s=616.9796423108305, post_ops/s=387.8138853325092, app_delta=-37.14316344701516%, baseline_cpu=45.232861976756226, post_cpu=41.25693896119912, cpu_delta=-8.789899294013745%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

