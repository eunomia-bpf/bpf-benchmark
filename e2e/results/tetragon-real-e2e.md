# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-28T21:50:33.254482+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `63.69105471410505` ops/s
- Events/s mean: `147.0858946934899`
- Agent CPU mean: `15.998155966153316`%
- BPF avg ns mean: `5595.878217200251`

- stress_exec: ops/s=63.69105471410505, events/s=147.0858946934899, agent_cpu=15.998155966153316, bpf_avg_ns=5595.878217200251

## Per-Program

- execve_rate (tracepoint): sites=54, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=295, stock_avg_ns=5595.878217200251, rejit_avg_ns=6285.436690557022, speedup=0.8902926706122528

## Post-ReJIT

- Application throughput mean: `278.0064345687955` ops/s
- Events/s mean: `141.59367109354022`
- Agent CPU mean: `30.41993035866123`%
- BPF avg ns mean: `6285.436690557022`

- stress_exec: ops/s=278.0064345687955, events/s=141.59367109354022, agent_cpu=30.41993035866123, bpf_avg_ns=6285.436690557022

## Comparison

- stress_exec: baseline_ops/s=63.69105471410505, post_ops/s=278.0064345687955, app_delta=336.49211936700436%, baseline_cpu=15.998155966153316, post_cpu=30.41993035866123, cpu_delta=90.14647952563725%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

