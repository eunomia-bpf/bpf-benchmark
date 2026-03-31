# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T14:39:00.618774+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `618.1516611667557` ops/s
- Events/s mean: `1032.8847411959282`
- Agent CPU mean: `43.547313344992986`%
- BPF avg ns mean: `2528.6803631151456`

- exec_storm: ops/s=618.1516611667557, events/s=1032.8847411959282, agent_cpu=43.547313344992986, bpf_avg_ns=2528.6803631151456

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2528.6803631151456, rejit_avg_ns=2489.6278288431063, speedup=1.0156860932463896

## Post-ReJIT

- Application throughput mean: `383.27270711351554` ops/s
- Events/s mean: `1043.6052394434637`
- Agent CPU mean: `44.01298356800702`%
- BPF avg ns mean: `2489.6278288431063`

- exec_storm: ops/s=383.27270711351554, events/s=1043.6052394434637, agent_cpu=44.01298356800702, bpf_avg_ns=2489.6278288431063

## Comparison

- exec_storm: baseline_ops/s=618.1516611667557, post_ops/s=383.27270711351554, app_delta=-37.99697854243541%, baseline_cpu=43.547313344992986, post_cpu=44.01298356800702, cpu_delta=1.0693431746865252%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

