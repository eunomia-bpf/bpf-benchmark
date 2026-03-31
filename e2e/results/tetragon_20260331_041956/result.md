# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T04:21:07.259717+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `620.4107184274535` ops/s
- Events/s mean: `1048.7236028009986`
- Agent CPU mean: `40.43312911503257`%
- BPF avg ns mean: `2288.026378670691`

- exec_storm: ops/s=620.4107184274535, events/s=1048.7236028009986, agent_cpu=40.43312911503257, bpf_avg_ns=2288.026378670691

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2288.026378670691, rejit_avg_ns=2431.847092673981, speedup=0.9408594749083712

## Post-ReJIT

- Application throughput mean: `428.5043229642284` ops/s
- Events/s mean: `1043.769733702222`
- Agent CPU mean: `40.36564250151204`%
- BPF avg ns mean: `2431.847092673981`

- exec_storm: ops/s=428.5043229642284, events/s=1043.769733702222, agent_cpu=40.36564250151204, bpf_avg_ns=2431.847092673981

## Comparison

- exec_storm: baseline_ops/s=620.4107184274535, post_ops/s=428.5043229642284, app_delta=-30.932153453062128%, baseline_cpu=40.43312911503257, post_cpu=40.36564250151204, cpu_delta=-0.16690920291756114%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

