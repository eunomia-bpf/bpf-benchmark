# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-13T23:28:37.370622+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1572.392616122677` ops/s
- Events/s mean: `1280.129259117911`
- Agent CPU mean: `12.862065145387392`%
- BPF avg ns mean: `2280.86`

- exec_storm: ops/s=1572.392616122677, events/s=1280.129259117911, agent_cpu=12.862065145387392, bpf_avg_ns=2280.86

## Per-Program

- event_execve (tracepoint): sites=144, stock_avg_ns=2280.86, rejit_avg_ns=5089.056856187291, speedup=0.4481891368981118
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2594.746722453697` ops/s
- Events/s mean: `2155.2523573678814`
- Agent CPU mean: `15.617673888934348`%
- BPF avg ns mean: `5089.056856187291`

- exec_storm: ops/s=2594.746722453697, events/s=2155.2523573678814, agent_cpu=15.617673888934348, bpf_avg_ns=5089.056856187291

## Comparison

- exec_storm: baseline_ops/s=1572.392616122677, post_ops/s=2594.746722453697, app_delta=65.01900961936701%, baseline_cpu=12.862065145387392, post_cpu=15.617673888934348, cpu_delta=21.424310267431473%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

