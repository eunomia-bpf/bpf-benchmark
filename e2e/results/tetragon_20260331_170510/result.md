# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-31T17:06:22.993278+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `620.407137379605` ops/s
- Events/s mean: `1046.895855199035`
- Agent CPU mean: `44.63323502119431`%
- BPF avg ns mean: `2435.243964621825`

- exec_storm: ops/s=620.407137379605, events/s=1046.895855199035, agent_cpu=44.63323502119431, bpf_avg_ns=2435.243964621825

## Per-Program

- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=13, stock_avg_ns=2435.243964621825, rejit_avg_ns=2594.272191957679, speedup=0.9387002536476912

## Post-ReJIT

- Application throughput mean: `392.37251796522315` ops/s
- Events/s mean: `1044.9995012597778`
- Agent CPU mean: `44.26553761658465`%
- BPF avg ns mean: `2594.272191957679`

- exec_storm: ops/s=392.37251796522315, events/s=1044.9995012597778, agent_cpu=44.26553761658465, bpf_avg_ns=2594.272191957679

## Comparison

- exec_storm: baseline_ops/s=620.407137379605, post_ops/s=392.37251796522315, app_delta=-36.755640880845576%, baseline_cpu=44.63323502119431, post_cpu=44.26553761658465, cpu_delta=-0.8238197487478884%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

