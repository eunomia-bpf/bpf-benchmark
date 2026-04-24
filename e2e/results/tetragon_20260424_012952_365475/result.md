# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-24T01:31:03.345510+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `2433.111146744662` ops/s
- Events/s mean: `10051.498536261532`
- Agent CPU mean: `6.599016525250725`%
- BPF avg ns mean: `1497.1337515658865`

- exec_storm: ops/s=2433.111146744662, events/s=10051.498536261532, agent_cpu=6.599016525250725, bpf_avg_ns=1497.1337515658865

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1586.4243079703201, rejit_avg_ns=1459.983549291198, speedup=1.0866042351919016
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=951.3807800306323, rejit_avg_ns=468.3001793487567, speedup=2.0315618528134523
- event_execve (tracepoint): sites=0, stock_avg_ns=3381.3458306725374, rejit_avg_ns=3537.5529670916494, speedup=0.9558431667674688
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=509.30580109568785, rejit_avg_ns=516.143999065483, speedup=0.9867513756196408
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2459.4647244271964` ops/s
- Events/s mean: `10145.903915527311`
- Agent CPU mean: `4.8994320537534755`%
- BPF avg ns mean: `1321.8088406168147`

- exec_storm: ops/s=2459.4647244271964, events/s=10145.903915527311, agent_cpu=4.8994320537534755, bpf_avg_ns=1321.8088406168147

## Comparison

- exec_storm: baseline_ops/s=2433.111146744662, post_ops/s=2459.4647244271964, app_delta=1.0831226398265261%, baseline_cpu=6.599016525250725, post_cpu=4.8994320537534755, cpu_delta=-25.755117675397475%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

