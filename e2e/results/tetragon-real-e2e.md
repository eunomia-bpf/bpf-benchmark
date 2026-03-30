# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-30T21:39:14.810371+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `119.64095970058044` ops/s
- Events/s mean: `28.696171145895676`
- Agent CPU mean: `6.239726870781842`%
- BPF avg ns mean: `39895.838461538464`

- exec_storm: ops/s=119.64095970058044, events/s=28.696171145895676, agent_cpu=6.239726870781842, bpf_avg_ns=39895.838461538464

## Per-Program

- execve_rate (tracepoint): sites=19, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=39895.838461538464, rejit_avg_ns=44816.64940239044, speedup=0.8902012754976389

## Post-ReJIT

- Application throughput mean: `170.29559359272127` ops/s
- Events/s mean: `26.95094198724656`
- Agent CPU mean: `6.617541246009917`%
- BPF avg ns mean: `44816.64940239044`

- exec_storm: ops/s=170.29559359272127, events/s=26.95094198724656, agent_cpu=6.617541246009917, bpf_avg_ns=44816.64940239044

## Comparison

- exec_storm: baseline_ops/s=119.64095970058044, post_ops/s=170.29559359272127, app_delta=42.33887292354701%, baseline_cpu=6.239726870781842, post_cpu=6.617541246009917, cpu_delta=6.0549825826067725%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

