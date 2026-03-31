# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T16:27:16.559266+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `629.6873980145714` ops/s
- Events/s mean: `1057.9620832692858`
- Agent CPU mean: `40.03612346573075`%
- BPF avg ns mean: `2421.7530146829117`

- exec_storm: ops/s=629.6873980145714, events/s=1057.9620832692858, agent_cpu=40.03612346573075, bpf_avg_ns=2421.7530146829117

## Per-Program

- event_execve (tracepoint): sites=13, stock_avg_ns=2421.7530146829117, rejit_avg_ns=2630.0607791721295, speedup=0.9207973571794081
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `431.259868953812` ops/s
- Events/s mean: `1057.4036465416314`
- Agent CPU mean: `45.595095992093476`%
- BPF avg ns mean: `2630.0607791721295`

- exec_storm: ops/s=431.259868953812, events/s=1057.4036465416314, agent_cpu=45.595095992093476, bpf_avg_ns=2630.0607791721295

## Comparison

- exec_storm: baseline_ops/s=629.6873980145714, post_ops/s=431.259868953812, app_delta=-31.51206927221492%, baseline_cpu=40.03612346573075, post_cpu=45.595095992093476, cpu_delta=13.884892055348393%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

