# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-23T12:05:41.988347+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1750.304631031802` ops/s
- Events/s mean: `105530.08432274849`
- Agent CPU mean: `70.99934598064966`%
- BPF avg ns mean: `829.9153930941662`

- exec_storm: ops/s=1750.304631031802, events/s=105530.08432274849, agent_cpu=70.99934598064966, bpf_avg_ns=829.9153930941662

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1765.4607479902131, rejit_avg_ns=1490.3486500714446, speedup=1.1845957977051746
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=1004.0072542277073, rejit_avg_ns=476.7966187231895, speedup=2.1057348454280813
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_rate (tracepoint): sites=5, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=2578.7483331926746, rejit_avg_ns=3921.729631645799, speedup=0.6575538283883362
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=265.06245252763944, rejit_avg_ns=277.96670295772094, speedup=0.9535762726514613
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_cgroup_rmdir (raw_tracepoint): sites=5, stock_avg_ns=1496.0, rejit_avg_ns=820.0, speedup=1.824390243902439
- generic_kprobe_process_filter (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_filter_arg (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=6, stock_avg_ns=1313.281752470866, rejit_avg_ns=1378.0828986881618, speedup=0.9529773235855535
- generic_kprobe_ (kprobe): sites=3, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_actions (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_event (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_filter_arg (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=6, stock_avg_ns=764.6981314719901, rejit_avg_ns=746.3570911907991, speedup=1.024574081894135
- generic_kprobe_ (kprobe): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_actions (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=3, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_filter (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_event (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=3, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_filter_arg (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_event (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_filter (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_actions (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_actions (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepo (tracepoint): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_process_event (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_filter (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_arg (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepo (tracepoint): sites=17, stock_avg_ns=1729.2162426614482, rejit_avg_ns=1773.236015037594, speedup=0.9751754577490845

## Post-ReJIT

- Application throughput mean: `1639.4702332046757` ops/s
- Events/s mean: `98882.99308559956`
- Agent CPU mean: `87.87421344889975`%
- BPF avg ns mean: `816.2845349092579`

- exec_storm: ops/s=1639.4702332046757, events/s=98882.99308559956, agent_cpu=87.87421344889975, bpf_avg_ns=816.2845349092579

## Comparison

- exec_storm: baseline_ops/s=1750.304631031802, post_ops/s=1639.4702332046757, app_delta=-6.332291868632586%, baseline_cpu=70.99934598064966, post_cpu=87.87421344889975, cpu_delta=23.767637905917056%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

