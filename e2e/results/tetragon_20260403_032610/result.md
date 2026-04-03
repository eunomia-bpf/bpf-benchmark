# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-03T03:27:23.531959+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `612.3325019176879` ops/s
- Events/s mean: `1039.6816956111668`
- Agent CPU mean: `43.09765750009259`%
- BPF avg ns mean: `2502.3474156168104`

- exec_storm: ops/s=612.3325019176879, events/s=1039.6816956111668, agent_cpu=43.09765750009259, bpf_avg_ns=2502.3474156168104

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2502.3474156168104, rejit_avg_ns=2437.80845724324, speedup=1.0264741711687035

## Post-ReJIT

- Application throughput mean: `388.76309174599646` ops/s
- Events/s mean: `1048.5650087722206`
- Agent CPU mean: `45.30076395949799`%
- BPF avg ns mean: `2437.80845724324`

- exec_storm: ops/s=388.76309174599646, events/s=1048.5650087722206, agent_cpu=45.30076395949799, bpf_avg_ns=2437.80845724324

## Comparison

- exec_storm: baseline_ops/s=612.3325019176879, post_ops/s=388.76309174599646, app_delta=-36.51111274863285%, baseline_cpu=43.09765750009259, post_cpu=45.30076395949799, cpu_delta=5.1118937482870646%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

