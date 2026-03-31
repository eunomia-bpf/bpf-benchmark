# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T15:45:13.695017+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `411.48699813163597` ops/s
- Events/s mean: `1055.8220224043525`
- Agent CPU mean: `44.96215561958834`%
- BPF avg ns mean: `2511.2278540383354`

- exec_storm: ops/s=411.48699813163597, events/s=1055.8220224043525, agent_cpu=44.96215561958834, bpf_avg_ns=2511.2278540383354

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2511.2278540383354, rejit_avg_ns=2284.322433148335, speedup=1.099331608181631

## Post-ReJIT

- Application throughput mean: `215.63587702832004` ops/s
- Events/s mean: `1046.7235469649602`
- Agent CPU mean: `44.56649025615718`%
- BPF avg ns mean: `2284.322433148335`

- exec_storm: ops/s=215.63587702832004, events/s=1046.7235469649602, agent_cpu=44.56649025615718, bpf_avg_ns=2284.322433148335

## Comparison

- exec_storm: baseline_ops/s=411.48699813163597, post_ops/s=215.63587702832004, app_delta=-47.595943976986256%, baseline_cpu=44.96215561958834, post_cpu=44.56649025615718, cpu_delta=-0.8799964280600011%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

