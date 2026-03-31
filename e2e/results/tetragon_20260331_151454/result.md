# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T15:16:05.380111+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `618.5410987465239` ops/s
- Events/s mean: `1064.9727089612154`
- Agent CPU mean: `41.064244938410454`%
- BPF avg ns mean: `2324.810456708485`

- exec_storm: ops/s=618.5410987465239, events/s=1064.9727089612154, agent_cpu=41.064244938410454, bpf_avg_ns=2324.810456708485

## Per-Program

- event_execve (tracepoint): sites=13, stock_avg_ns=2324.810456708485, rejit_avg_ns=2470.1086888331242, speedup=0.9411773932128963
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `453.63626680514295` ops/s
- Events/s mean: `1052.6950200719143`
- Agent CPU mean: `44.16028562462664`%
- BPF avg ns mean: `2470.1086888331242`

- exec_storm: ops/s=453.63626680514295, events/s=1052.6950200719143, agent_cpu=44.16028562462664, bpf_avg_ns=2470.1086888331242

## Comparison

- exec_storm: baseline_ops/s=618.5410987465239, post_ops/s=453.63626680514295, app_delta=-26.660286968086883%, baseline_cpu=41.064244938410454, post_cpu=44.16028562462664, cpu_delta=7.539504722075692%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

