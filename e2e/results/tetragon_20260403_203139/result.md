# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-03T20:32:52.579226+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `621.2567537072781` ops/s
- Events/s mean: `1063.2559086048943`
- Agent CPU mean: `40.86596817055452`%
- BPF avg ns mean: `2510.1645538155603`

- exec_storm: ops/s=621.2567537072781, events/s=1063.2559086048943, agent_cpu=40.86596817055452, bpf_avg_ns=2510.1645538155603

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=8, stock_avg_ns=2510.1645538155603, rejit_avg_ns=2318.95224047449, speedup=1.0824563395501177

## Post-ReJIT

- Application throughput mean: `435.15362995866354` ops/s
- Events/s mean: `1062.4954390445705`
- Agent CPU mean: `41.45345365881462`%
- BPF avg ns mean: `2318.95224047449`

- exec_storm: ops/s=435.15362995866354, events/s=1062.4954390445705, agent_cpu=41.45345365881462, bpf_avg_ns=2318.95224047449

## Comparison

- exec_storm: baseline_ops/s=621.2567537072781, post_ops/s=435.15362995866354, app_delta=-29.955911567651476%, baseline_cpu=40.86596817055452, post_cpu=41.45345365881462, cpu_delta=1.4375910190313455%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

