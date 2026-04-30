# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-23T11:00:37.787504+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1680.1164033078244` ops/s
- Events/s mean: `102179.16030875423`
- Agent CPU mean: `67.99938095063548`%
- BPF avg ns mean: `841.5714746331591`

- exec_storm: ops/s=1680.1164033078244, events/s=102179.16030875423, agent_cpu=67.99938095063548, bpf_avg_ns=841.5714746331591

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1717.3945046999277, rejit_avg_ns=1441.6384929501503, speedup=1.1912795843744945
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=1014.1654021982298, rejit_avg_ns=448.84024609074595, speedup=2.259524209406986
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=1, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=8, stock_avg_ns=2915.395662317463, rejit_avg_ns=3987.292691817022, speedup=0.731171721679882
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=258.25602695930183, rejit_avg_ns=269.7084928011664, speedup=0.9575376150638774
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_cgroup_rmdir (raw_tracepoint): sites=5, stock_avg_ns=1048.0, rejit_avg_ns=890.0, speedup=1.1775280898876404
- generic_kprobe_ (kprobe): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_filter (kprobe): sites=13, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_filter_arg (kprobe): sites=48, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_event (kprobe): sites=24, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_actions (kprobe): sites=9, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=6, stock_avg_ns=1350.6790019838243, rejit_avg_ns=1369.6981519507187, speedup=0.9861143493989479
- generic_kprobe_ (kprobe): sites=8, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_actions (kprobe): sites=9, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_event (kprobe): sites=24, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_filter (kprobe): sites=13, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=6, stock_avg_ns=772.1902860944778, rejit_avg_ns=747.7067112604394, speedup=1.0327448910987644
- generic_kprobe_filter_arg (kprobe): sites=48, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=8, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_actions (kprobe): sites=9, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=8, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_event (kprobe): sites=24, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_process_filter (kprobe): sites=13, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_filter_arg (kprobe): sites=48, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_kprobe_ (kprobe): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_actions (tracepoint): sites=9, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepo (tracepoint): sites=39, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_process_event (tracepoint): sites=22, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_filter (tracepoint): sites=13, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepoint_arg (tracepoint): sites=48, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- generic_tracepo (tracepoint): sites=35, stock_avg_ns=1771.8878768163088, rejit_avg_ns=1802.9952241565245, speedup=0.9827468498399554

## Post-ReJIT

- Application throughput mean: `1562.7312159355693` ops/s
- Events/s mean: `95913.90866327721`
- Agent CPU mean: `86.87127839099801`%
- BPF avg ns mean: `816.4964440195331`

- exec_storm: ops/s=1562.7312159355693, events/s=95913.90866327721, agent_cpu=86.87127839099801, bpf_avg_ns=816.4964440195331

## Comparison

- exec_storm: baseline_ops/s=1680.1164033078244, post_ops/s=1562.7312159355693, app_delta=-6.986729439766577%, baseline_cpu=67.99938095063548, post_cpu=86.87127839099801, cpu_delta=27.753043007939564%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

