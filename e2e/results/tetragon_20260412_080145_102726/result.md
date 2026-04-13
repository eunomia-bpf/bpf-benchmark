# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-12T08:02:18.795272+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `4111.212035321192` ops/s
- Events/s mean: `3218.339750082225`
- Agent CPU mean: `79.30188757518644`%
- BPF avg ns mean: `1776.371595716552`

- exec_storm: ops/s=4111.212035321192, events/s=3218.339750082225, agent_cpu=79.30188757518644, bpf_avg_ns=1776.371595716552

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=144, stock_avg_ns=1776.371595716552, rejit_avg_ns=5079.712024109254, speedup=0.3496992717865823

## Post-ReJIT

- Application throughput mean: `3525.5575791806114` ops/s
- Events/s mean: `2753.924919712761`
- Agent CPU mean: `101.90324644685032`%
- BPF avg ns mean: `5079.712024109254`

- exec_storm: ops/s=3525.5575791806114, events/s=2753.924919712761, agent_cpu=101.90324644685032, bpf_avg_ns=5079.712024109254

## Comparison

- exec_storm: baseline_ops/s=4111.212035321192, post_ops/s=3525.5575791806114, app_delta=-14.245299223415655%, baseline_cpu=79.30188757518644, post_cpu=101.90324644685032, cpu_delta=28.500404672253783%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

