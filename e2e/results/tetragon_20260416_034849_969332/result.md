# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-16T03:50:00.573746+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1891.842557592719` ops/s
- Events/s mean: `1511.703508385025`
- Agent CPU mean: `90.92999063776159`%
- BPF avg ns mean: `1877.7251115706977`

- exec_storm: ops/s=1891.842557592719, events/s=1511.703508385025, agent_cpu=90.92999063776159, bpf_avg_ns=1877.7251115706977

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=11, stock_avg_ns=1877.7251115706977, rejit_avg_ns=1920.900394319969, speedup=0.9775234140838645

## Post-ReJIT

- Application throughput mean: `1839.861254451731` ops/s
- Events/s mean: `1455.5725767556405`
- Agent CPU mean: `102.93302187516448`%
- BPF avg ns mean: `1920.900394319969`

- exec_storm: ops/s=1839.861254451731, events/s=1455.5725767556405, agent_cpu=102.93302187516448, bpf_avg_ns=1920.900394319969

## Comparison

- exec_storm: baseline_ops/s=1891.842557592719, post_ops/s=1839.861254451731, app_delta=-2.7476548157967144%, baseline_cpu=90.92999063776159, post_cpu=102.93302187516448, cpu_delta=13.200299651651179%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

