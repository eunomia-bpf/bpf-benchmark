# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-10T02:54:39.012331+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1084.6798185082635` ops/s
- Events/s mean: `900.4889059313884`
- Agent CPU mean: `41.59955847753951`%
- BPF avg ns mean: `2644.5640529085063`

- exec_storm: ops/s=1084.6798185082635, events/s=900.4889059313884, agent_cpu=41.59955847753951, bpf_avg_ns=2644.5640529085063

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=144, stock_avg_ns=2644.5640529085063, rejit_avg_ns=6545.600625810883, speedup=0.4040216023080223

## Post-ReJIT

- Application throughput mean: `1034.830793365411` ops/s
- Events/s mean: `863.655279329107`
- Agent CPU mean: `49.326652732082444`%
- BPF avg ns mean: `6545.600625810883`

- exec_storm: ops/s=1034.830793365411, events/s=863.655279329107, agent_cpu=49.326652732082444, bpf_avg_ns=6545.600625810883

## Comparison

- exec_storm: baseline_ops/s=1084.6798185082635, post_ops/s=1034.830793365411, app_delta=-4.595736390800447%, baseline_cpu=41.59955847753951, post_cpu=49.326652732082444, cpu_delta=18.57494294973096%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

