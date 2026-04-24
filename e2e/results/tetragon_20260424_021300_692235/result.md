# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-24T02:13:27.531874+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `2432.4611984303015` ops/s
- Events/s mean: `10038.667456371451`
- Agent CPU mean: `6.2461157264516585`%
- BPF avg ns mean: `1543.77314073688`

- exec_storm: ops/s=2432.4611984303015, events/s=10038.667456371451, agent_cpu=6.2461157264516585, bpf_avg_ns=1543.77314073688

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1683.519942655266, rejit_avg_ns=1548.3824119310877, speedup=1.0872765859925002
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=942.0042521089089, rejit_avg_ns=451.9783308229495, speedup=2.0841801207454655
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=3523.5082470994043, rejit_avg_ns=3617.9746157722348, speedup=0.9738897093802116
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=493.4447162119787, rejit_avg_ns=502.18890148652054, speedup=0.982587856385001
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2423.2192253418316` ops/s
- Events/s mean: `10022.562352271558`
- Agent CPU mean: `5.123079936239945`%
- BPF avg ns mean: `1352.1272867465084`

- exec_storm: ops/s=2423.2192253418316, events/s=10022.562352271558, agent_cpu=5.123079936239945, bpf_avg_ns=1352.1272867465084

## Comparison

- exec_storm: baseline_ops/s=2432.4611984303015, post_ops/s=2423.2192253418316, app_delta=-0.3799432893085341%, baseline_cpu=6.2461157264516585, post_cpu=5.123079936239945, cpu_delta=-17.979746764149315%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

