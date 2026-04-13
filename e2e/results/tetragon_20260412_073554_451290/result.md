# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-12T07:36:27.456742+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `3512.578887250803` ops/s
- Events/s mean: `2760.5763570874365`
- Agent CPU mean: `82.94532309300457`%
- BPF avg ns mean: `1776.939427146312`

- exec_storm: ops/s=3512.578887250803, events/s=2760.5763570874365, agent_cpu=82.94532309300457, bpf_avg_ns=1776.939427146312

## Per-Program

- event_execve (tracepoint): sites=144, stock_avg_ns=1776.939427146312, rejit_avg_ns=5100.009053749474, speedup=0.34841887699001717
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `3477.871367440651` ops/s
- Events/s mean: `2723.3910313049723`
- Agent CPU mean: `94.53855595338052`%
- BPF avg ns mean: `5100.009053749474`

- exec_storm: ops/s=3477.871367440651, events/s=2723.3910313049723, agent_cpu=94.53855595338052, bpf_avg_ns=5100.009053749474

## Comparison

- exec_storm: baseline_ops/s=3512.578887250803, post_ops/s=3477.871367440651, app_delta=-0.9880922514260345%, baseline_cpu=82.94532309300457, post_cpu=94.53855595338052, cpu_delta=13.97695786581811%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

