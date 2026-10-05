# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-21T01:00:23.957446+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `10s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `1430.164642677993` ops/s
- Events/s mean: `212.86995348565827`
- Agent CPU mean: `2.799968187895162`%
- BPF avg ns mean: `2863.470015476751`

- stress_exec: ops/s=211.91084842795163, events/s=848.8428890802667, agent_cpu=6.699962411870876, bpf_avg_ns=2161.4943476212907
- file_io: ops/s=3771.3150443655227, events/s=1.271429790427322, agent_cpu=0.0, bpf_avg_ns=3426.1
- open_storm: ops/s=627.7275328737859, events/s=0.6999191988079805, agent_cpu=2.0999877768111466, bpf_avg_ns=2552.285714285714
- connect_storm: ops/s=1109.705145044712, events/s=0.6655758731310928, agent_cpu=2.3999225628986247, bpf_avg_ns=3314.0

## Recompile

- Applied programs: `2` / `7`
- Applied successfully: `True`

## Per-Program

- event_exit_acct (kprobe): sites=6, stock_avg_ns=1934.5311767463666, rejit_avg_ns=1996.4648305084745, speedup=0.9689783397054211
- event_wake_up_n (kprobe): sites=13, stock_avg_ns=2810.9132057862807, rejit_avg_ns=3057.6257383966245, speedup=0.9193123836209869
- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=29, stock_avg_ns=3648.9750588235293, rejit_avg_ns=3850.360322170411, speedup=0.9476970344340753
- execve_send (tracepoint): sites=14, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=3, stock_avg_ns=263.8974117647059, rejit_avg_ns=296.91903348876644, speedup=0.888785769857661
- execve_map_upda (socket_filter): sites=1, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `1544.0774452697283` ops/s
- Events/s mean: `236.04669062044346`
- Agent CPU mean: `3.249962453453391`%
- BPF avg ns mean: `2906.4451270621403`

- stress_exec: ops/s=235.3438889569789, events/s=941.9754128091143, agent_cpu=8.099952339070438, bpf_avg_ns=2298.8665888346422
- file_io: ops/s=4288.387137467012, events/s=0.9276817170658316, agent_cpu=0.199998644369189, bpf_avg_ns=3255.4615384615386
- open_storm: ops/s=663.3711917129201, events/s=0.5999739448714985, agent_cpu=2.499989132047245, bpf_avg_ns=3080.1666666666665
- connect_storm: ops/s=989.2075629420023, events/s=0.683694010722158, agent_cpu=2.199909698326692, bpf_avg_ns=2991.285714285714

## Comparison

- connect_storm: baseline_ops/s=1109.705145044712, post_ops/s=989.2075629420023, app_delta=-10.858522431907325%, baseline_cpu=2.3999225628986247, post_cpu=2.199909698326692, cpu_delta=-8.334138261959477%
- file_io: baseline_ops/s=3771.3150443655227, post_ops/s=4288.387137467012, app_delta=13.710657609313568%, baseline_cpu=0.0, post_cpu=0.199998644369189, cpu_delta=None%
- open_storm: baseline_ops/s=627.7275328737859, post_ops/s=663.3711917129201, app_delta=5.67820542711497%, baseline_cpu=2.0999877768111466, post_cpu=2.499989132047245, cpu_delta=19.04779445161841%
- stress_exec: baseline_ops/s=211.91084842795163, post_ops/s=235.3438889569789, app_delta=11.057971171775263%, baseline_cpu=6.699962411870876, post_cpu=8.099952339070438, cpu_delta=20.89548927497091%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
