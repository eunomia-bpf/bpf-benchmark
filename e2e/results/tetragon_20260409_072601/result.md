# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-09T07:27:14.144817+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1282.7760424580335` ops/s
- Events/s mean: `1037.6880147080483`
- Agent CPU mean: `42.76656536550324`%
- BPF avg ns mean: `2481.2434884309014`

- exec_storm: ops/s=1282.7760424580335, events/s=1037.6880147080483, agent_cpu=42.76656536550324, bpf_avg_ns=2481.2434884309014

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=144, stock_avg_ns=2481.2434884309014, rejit_avg_ns=5933.101804939835, speedup=0.41820342377490394

## Post-ReJIT

- Application throughput mean: `1275.9835431577344` ops/s
- Events/s mean: `1036.9952208791306`
- Agent CPU mean: `45.729779609662415`%
- BPF avg ns mean: `5933.101804939835`

- exec_storm: ops/s=1275.9835431577344, events/s=1036.9952208791306, agent_cpu=45.729779609662415, bpf_avg_ns=5933.101804939835

## Comparison

- exec_storm: baseline_ops/s=1282.7760424580335, post_ops/s=1275.9835431577344, app_delta=-0.5295156033069865%, baseline_cpu=42.76656536550324, post_cpu=45.729779609662415, cpu_delta=6.928810435989304%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

