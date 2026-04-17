# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-16T03:43:08.393177+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1897.660004917299` ops/s
- Events/s mean: `1501.4087667157423`
- Agent CPU mean: `93.28514727877797`%
- BPF avg ns mean: `1853.841639373285`

- exec_storm: ops/s=1897.660004917299, events/s=1501.4087667157423, agent_cpu=93.28514727877797, bpf_avg_ns=1853.841639373285

## Per-Program

- event_execve (tracepoint): sites=11, stock_avg_ns=1853.841639373285, rejit_avg_ns=1896.4660110577358, speedup=0.9775243155237581
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `1835.3539252320322` ops/s
- Events/s mean: `1460.0782231336646`
- Agent CPU mean: `102.29976003545292`%
- BPF avg ns mean: `1896.4660110577358`

- exec_storm: ops/s=1835.3539252320322, events/s=1460.0782231336646, agent_cpu=102.29976003545292, bpf_avg_ns=1896.4660110577358

## Comparison

- exec_storm: baseline_ops/s=1897.660004917299, post_ops/s=1835.3539252320322, app_delta=-3.283311000064104%, baseline_cpu=93.28514727877797, post_cpu=102.29976003545292, cpu_delta=9.663502732900483%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

