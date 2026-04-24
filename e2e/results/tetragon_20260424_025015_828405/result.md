# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-24T02:50:42.720330+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/artifacts/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `2432.817621396059` ops/s
- Events/s mean: `10035.4506032479`
- Agent CPU mean: `6.2410324360217135`%
- BPF avg ns mean: `1450.9587204968943`

- exec_storm: ops/s=2432.817621396059, events/s=10035.4506032479, agent_cpu=6.2410324360217135, bpf_avg_ns=1450.9587204968943

## Per-Program

- event_exit_acct (kprobe): sites=8, stock_avg_ns=1542.5462882319791, rejit_avg_ns=1424.1994694418936, speedup=1.0830970810826537
- event_wake_up_n (kprobe): sites=28, stock_avg_ns=891.0568645608258, rejit_avg_ns=424.1545145960625, speedup=2.100783638739319
- execve_rate (tracepoint): sites=6, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=3359.2944947209653, rejit_avg_ns=3482.796758183075, speedup=0.9645393423627341
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=456.2328431372549, rejit_avg_ns=473.1304265879249, speedup=0.9642855701068936
- execve_map_upda (socket_filter): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `2445.828087451939` ops/s
- Events/s mean: `10095.811254337792`
- Agent CPU mean: `4.8726113082854035`%
- BPF avg ns mean: `1277.9277467365507`

- exec_storm: ops/s=2445.828087451939, events/s=10095.811254337792, agent_cpu=4.8726113082854035, bpf_avg_ns=1277.9277467365507

## Comparison

- exec_storm: baseline_ops/s=2432.817621396059, post_ops/s=2445.828087451939, app_delta=0.5347900287081119%, baseline_cpu=6.2410324360217135, post_cpu=4.8726113082854035, cpu_delta=-21.926197977086577%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

