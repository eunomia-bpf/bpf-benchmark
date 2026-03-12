# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-12T21:04:40.938740+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `339180.69464919943` ops/s
- Events/s mean: `37.38000165237911`
- Agent CPU mean: `28.983286114048056`%
- BPF avg ns mean: `4738.604178975147`

- stress_exec: ops/s=920.1396118248254, events/s=148.5642081592166, agent_cpu=0.09999968293433864, bpf_avg_ns=5774.4838709677415
- file_io: ops/s=1137097.545875518, events/s=0.42467982521222064, agent_cpu=0.03333326244015077, bpf_avg_ns=5731.615384615385
- open_storm: ops/s=217196.02043912953, events/s=0.29999998219000096, agent_cpu=110.23316822609397, bpf_avg_ns=3019.8888888888887
- connect_storm: ops/s=1509.072670325385, events/s=0.23111864289759979, agent_cpu=5.566643284723767, bpf_avg_ns=4428.428571428572

## Recompile

- Applied programs: `3` / `5`
- Applied successfully: `True`

## Per-Program

- event_exit_acct (kprobe): sites=6, stock_avg_ns=6623.058823529412, rejit_avg_ns=4918.5, speedup=1.3465607041840828
- event_wake_up_n (kprobe): sites=13, stock_avg_ns=4599.862068965517, rejit_avg_ns=3845.277777777778, speedup=1.1962366140486789
- event_execve (tracepoint): sites=29, stock_avg_ns=8366.42857142857, rejit_avg_ns=10338.285714285714, speedup=0.8092665266416095
- tg_kp_bprm_comm (kprobe): sites=3, stock_avg_ns=1020.7142857142857, rejit_avg_ns=970.0, speedup=1.0522827687776142
- execve_map_upda (socket_filter): sites=1, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `339046.512061614` ops/s
- Events/s mean: `26.1021956356016`
- Agent CPU mean: `28.524888259223022`%
- BPF avg ns mean: `4498.626373626374`

- stress_exec: ops/s=1767.7830823350394, events/s=103.55214708238725, agent_cpu=0.033333190459501276, bpf_avg_ns=4726.285714285715
- file_io: ops/s=1137006.9344213677, events/s=0.428940586402628, agent_cpu=0.033333250943536966, bpf_avg_ns=5371.076923076923
- open_storm: ops/s=216664.49143042066, events/s=0.19999996132000744, agent_cpu=110.09957515876937, bpf_avg_ns=3551.0
- connect_storm: ops/s=746.8393123325569, events/s=0.22769491229651123, agent_cpu=3.933311436719676, bpf_avg_ns=4346.142857142857

## Comparison

- connect_storm: baseline_ops/s=1509.072670325385, post_ops/s=746.8393123325569, app_delta=-50.51004984594121%, baseline_cpu=5.566643284723767, post_cpu=3.933311436719676, cpu_delta=-29.341413926887565%
- file_io: baseline_ops/s=1137097.545875518, post_ops/s=1137006.9344213677, app_delta=-0.007968661481931769%, baseline_cpu=0.03333326244015077, post_cpu=0.033333250943536966, cpu_delta=-3.4489914773343454e-05%
- open_storm: baseline_ops/s=217196.02043912953, post_ops/s=216664.49143042066, app_delta=-0.24472318030238924%, baseline_cpu=110.23316822609397, post_cpu=110.09957515876937, cpu_delta=-0.12119135236192298%
- stress_exec: baseline_ops/s=920.1396118248254, post_ops/s=1767.7830823350394, app_delta=92.12118026623844%, baseline_cpu=0.09999968293433864, post_cpu=0.033333190459501276, cpu_delta=-66.66670385206284%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
