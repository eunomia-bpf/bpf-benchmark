# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-24T00:21:44.978300+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `2422.6368827346596` ops/s
- Events/s mean: `9999.144174298792`
- Agent CPU mean: `6.63175080858552`%
- BPF avg ns mean: `1586.91139413403`

- exec_storm: ops/s=2422.6368827346596, events/s=9999.144174298792, agent_cpu=6.63175080858552, bpf_avg_ns=1586.91139413403

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1744.2777907632235, rejit_avg_ns=1466.4321949759951, speedup=1.1894704690330238
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=980.9769923338309, rejit_avg_ns=474.95688506611805, speedup=2.065402193711268
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=3578.0164383561646, rejit_avg_ns=3561.0238619368497, speedup=1.0047718232390817
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=521.0745476069677, rejit_avg_ns=506.6337864860777, speedup=1.0285033519399656
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2449.1249764781724` ops/s
- Events/s mean: `10089.170390568337`
- Agent CPU mean: `5.131764729559265`%
- BPF avg ns mean: `1328.2180184760862`

- exec_storm: ops/s=2449.1249764781724, events/s=10089.170390568337, agent_cpu=5.131764729559265, bpf_avg_ns=1328.2180184760862

## Comparison

- exec_storm: baseline_ops/s=2422.6368827346596, post_ops/s=2449.1249764781724, app_delta=1.0933579824646746%, baseline_cpu=6.63175080858552, post_cpu=5.131764729559265, cpu_delta=-22.618251534487097%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

