# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-10T03:20:00.397844+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `957.7766853134821` ops/s
- Events/s mean: `798.1637711063984`
- Agent CPU mean: `49.0630941652674`%
- BPF avg ns mean: `3328.985914325959`

- exec_storm: ops/s=957.7766853134821, events/s=798.1637711063984, agent_cpu=49.0630941652674, bpf_avg_ns=3328.985914325959

## Per-Program

- event_execve (tracepoint): sites=144, stock_avg_ns=3328.985914325959, rejit_avg_ns=6680.791202480763, speedup=0.49829216531865483
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `1052.7777998915365` ops/s
- Events/s mean: `865.2028980294117`
- Agent CPU mean: `47.97831267997603`%
- BPF avg ns mean: `6680.791202480763`

- exec_storm: ops/s=1052.7777998915365, events/s=865.2028980294117, agent_cpu=47.97831267997603, bpf_avg_ns=6680.791202480763

## Comparison

- exec_storm: baseline_ops/s=957.7766853134821, post_ops/s=1052.7777998915365, app_delta=9.91892118849817%, baseline_cpu=49.0630941652674, post_cpu=47.97831267997603, cpu_delta=-2.210992811903225%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

