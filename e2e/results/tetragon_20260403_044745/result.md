# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-03T04:48:58.084367+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `629.795684181138` ops/s
- Events/s mean: `1051.5851514619012`
- Agent CPU mean: `42.69966943196924`%
- BPF avg ns mean: `2565.294835975514`

- exec_storm: ops/s=629.795684181138, events/s=1051.5851514619012, agent_cpu=42.69966943196924, bpf_avg_ns=2565.294835975514

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=8, stock_avg_ns=2565.294835975514, rejit_avg_ns=2510.4222824887265, speedup=1.0218578977208526

## Post-ReJIT

- Application throughput mean: `431.7070395265208` ops/s
- Events/s mean: `1046.945696728778`
- Agent CPU mean: `43.15969855491477`%
- BPF avg ns mean: `2510.4222824887265`

- exec_storm: ops/s=431.7070395265208, events/s=1046.945696728778, agent_cpu=43.15969855491477, bpf_avg_ns=2510.4222824887265

## Comparison

- exec_storm: baseline_ops/s=629.795684181138, post_ops/s=431.7070395265208, app_delta=-31.452842505926746%, baseline_cpu=42.69966943196924, post_cpu=43.15969855491477, cpu_delta=1.077359916517537%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

