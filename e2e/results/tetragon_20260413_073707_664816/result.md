# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-13T07:38:20.517008+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `3003.339990971003` ops/s
- Events/s mean: `2507.78087170811`
- Agent CPU mean: `39.32714718482497`%
- BPF avg ns mean: `1618.4672538503173`

- exec_storm: ops/s=3003.339990971003, events/s=2507.78087170811, agent_cpu=39.32714718482497, bpf_avg_ns=1618.4672538503173

## Per-Program

- event_execve (tracepoint): sites=144, stock_avg_ns=1618.4672538503173, rejit_avg_ns=4847.548762260626, speedup=0.3338733312907521
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2818.289564584081` ops/s
- Events/s mean: `2406.748018736595`
- Agent CPU mean: `35.23386043096394`%
- BPF avg ns mean: `4847.548762260626`

- exec_storm: ops/s=2818.289564584081, events/s=2406.748018736595, agent_cpu=35.23386043096394, bpf_avg_ns=4847.548762260626

## Comparison

- exec_storm: baseline_ops/s=3003.339990971003, post_ops/s=2818.289564584081, app_delta=-6.161487775051862%, baseline_cpu=39.32714718482497, post_cpu=35.23386043096394, cpu_delta=-10.408298203334969%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

