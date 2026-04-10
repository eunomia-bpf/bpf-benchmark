# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-10T01:20:26.906328+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `524.1344811438614` ops/s
- Events/s mean: `449.2438921876`
- Agent CPU mean: `45.67404627989006`%
- BPF avg ns mean: `3981.145898948676`

- exec_storm: ops/s=524.1344811438614, events/s=449.2438921876, agent_cpu=45.67404627989006, bpf_avg_ns=3981.145898948676

## Per-Program

- event_execve (tracepoint): sites=144, stock_avg_ns=3981.145898948676, rejit_avg_ns=25921.411701748126, speedup=0.15358522694503515
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `80.5902461459815` ops/s
- Events/s mean: `74.50344985065504`
- Agent CPU mean: `47.79788872423681`%
- BPF avg ns mean: `25921.411701748126`

- exec_storm: ops/s=80.5902461459815, events/s=74.50344985065504, agent_cpu=47.79788872423681, bpf_avg_ns=25921.411701748126

## Comparison

- exec_storm: baseline_ops/s=524.1344811438614, post_ops/s=80.5902461459815, app_delta=-84.62412814930572%, baseline_cpu=45.67404627989006, post_cpu=47.79788872423681, cpu_delta=4.6499984506121335%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

