# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-16T08:10:51.822206+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `319.38971365633256` ops/s
- Events/s mean: `246.52955761022469`
- Agent CPU mean: `7.851604244350444`%
- BPF avg ns mean: `10663.077285579642`

- exec_storm: ops/s=319.38971365633256, events/s=246.52955761022469, agent_cpu=7.851604244350444, bpf_avg_ns=10663.077285579642

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=11, stock_avg_ns=10663.077285579642, rejit_avg_ns=10757.191921967304, speedup=0.9912510033222082

## Post-ReJIT

- Application throughput mean: `314.169471687508` ops/s
- Events/s mean: `241.840057573326`
- Agent CPU mean: `8.7852731567048`%
- BPF avg ns mean: `10757.191921967304`

- exec_storm: ops/s=314.169471687508, events/s=241.840057573326, agent_cpu=8.7852731567048, bpf_avg_ns=10757.191921967304

## Comparison

- exec_storm: baseline_ops/s=319.38971365633256, post_ops/s=314.169471687508, app_delta=-1.6344427342583738%, baseline_cpu=7.851604244350444, post_cpu=8.7852731567048, cpu_delta=11.891441332211441%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

