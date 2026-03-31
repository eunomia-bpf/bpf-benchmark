# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T01:01:21.093974+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `628.8419679612899` ops/s
- Events/s mean: `1057.8689968864023`
- Agent CPU mean: `42.39960755205918`%
- BPF avg ns mean: `2424.9517118913363`

- exec_storm: ops/s=628.8419679612899, events/s=1057.8689968864023, agent_cpu=42.39960755205918, bpf_avg_ns=2424.9517118913363

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2424.9517118913363, rejit_avg_ns=2321.7659522049767, speedup=1.044442791310797

## Post-ReJIT

- Application throughput mean: `439.5621968616885` ops/s
- Events/s mean: `1065.4223823611815`
- Agent CPU mean: `42.796655850766584`%
- BPF avg ns mean: `2321.7659522049767`

- exec_storm: ops/s=439.5621968616885, events/s=1065.4223823611815, agent_cpu=42.796655850766584, bpf_avg_ns=2321.7659522049767

## Comparison

- exec_storm: baseline_ops/s=628.8419679612899, post_ops/s=439.5621968616885, app_delta=-30.0997358228567%, baseline_cpu=42.39960755205918, post_cpu=42.796655850766584, cpu_delta=0.9364433343395898%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

