# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T03:27:23.539551+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `611.8767539820536` ops/s
- Events/s mean: `1059.8191987027146`
- Agent CPU mean: `41.566525377890216`%
- BPF avg ns mean: `2438.298349568778`

- exec_storm: ops/s=611.8767539820536, events/s=1059.8191987027146, agent_cpu=41.566525377890216, bpf_avg_ns=2438.298349568778

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2438.298349568778, rejit_avg_ns=2428.4835967883578, speedup=1.0040415149574822

## Post-ReJIT

- Application throughput mean: `436.29049395834767` ops/s
- Events/s mean: `1051.1323945419342`
- Agent CPU mean: `43.49780051776747`%
- BPF avg ns mean: `2428.4835967883578`

- exec_storm: ops/s=436.29049395834767, events/s=1051.1323945419342, agent_cpu=43.49780051776747, bpf_avg_ns=2428.4835967883578

## Comparison

- exec_storm: baseline_ops/s=611.8767539820536, post_ops/s=436.29049395834767, app_delta=-28.69634430152839%, baseline_cpu=41.566525377890216, post_cpu=43.49780051776747, cpu_delta=4.646227035624509%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

