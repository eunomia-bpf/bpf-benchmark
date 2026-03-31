# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T17:42:55.819644+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `617.6002275036964` ops/s
- Events/s mean: `1059.7308807752656`
- Agent CPU mean: `42.70853664876009`%
- BPF avg ns mean: `2518.17064305685`

- exec_storm: ops/s=617.6002275036964, events/s=1059.7308807752656, agent_cpu=42.70853664876009, bpf_avg_ns=2518.17064305685

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2518.17064305685, rejit_avg_ns=2260.3658795934325, speedup=1.1140544395006478

## Post-ReJIT

- Application throughput mean: `442.4864863184627` ops/s
- Events/s mean: `1054.8352642982811`
- Agent CPU mean: `43.4664534695079`%
- BPF avg ns mean: `2260.3658795934325`

- exec_storm: ops/s=442.4864863184627, events/s=1054.8352642982811, agent_cpu=43.4664534695079, bpf_avg_ns=2260.3658795934325

## Comparison

- exec_storm: baseline_ops/s=617.6002275036964, post_ops/s=442.4864863184627, app_delta=-28.353898426014684%, baseline_cpu=42.70853664876009, post_cpu=43.4664534695079, cpu_delta=1.7746260589094964%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

