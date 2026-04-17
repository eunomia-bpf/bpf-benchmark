# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-16T05:02:19.729859+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1857.868235438786` ops/s
- Events/s mean: `1474.487525588392`
- Agent CPU mean: `95.89978851858973`%
- BPF avg ns mean: `1925.3911858143883`

- exec_storm: ops/s=1857.868235438786, events/s=1474.487525588392, agent_cpu=95.89978851858973, bpf_avg_ns=1925.3911858143883

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=11, stock_avg_ns=1925.3911858143883, rejit_avg_ns=1920.1884422110552, speedup=1.0027094963645038

## Post-ReJIT

- Application throughput mean: `1815.4648647390723` ops/s
- Events/s mean: `1447.6368165939928`
- Agent CPU mean: `99.09969239455451`%
- BPF avg ns mean: `1920.1884422110552`

- exec_storm: ops/s=1815.4648647390723, events/s=1447.6368165939928, agent_cpu=99.09969239455451, bpf_avg_ns=1920.1884422110552

## Comparison

- exec_storm: baseline_ops/s=1857.868235438786, post_ops/s=1815.4648647390723, app_delta=-2.282366956432684%, baseline_cpu=95.89978851858973, post_cpu=99.09969239455451, cpu_delta=3.3367163008336482%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

