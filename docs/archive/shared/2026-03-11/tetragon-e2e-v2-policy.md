# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-12T04:42:23.194335+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `339334.2353207032` ops/s
- Events/s mean: `180.9870838826364`
- Agent CPU mean: `32.84158969357762`%
- BPF avg ns mean: `3886.728192968988`

- stress_exec: ops/s=180.57394368553324, events/s=723.0290022727866, agent_cpu=10.333312329842691, bpf_avg_ns=3373.595464183645
- file_io: ops/s=1144689.1576471261, events/s=0.42478976829076354, agent_cpu=0.06666616227714948, bpf_avg_ns=4743.692307692308
- open_storm: ops/s=209978.92488518127, events/s=0.2666666559377782, agent_cpu=112.49975268054371, bpf_avg_ns=2698.625
- connect_storm: ops/s=2488.2848068197522, events/s=0.22787683353051263, agent_cpu=8.466627601646916, bpf_avg_ns=4731.0

## Recompile

- Applied programs: `2` / `5`
- Applied successfully: `True`

## Per-Program

- event_exit_acct (kprobe): sites=6, stock_avg_ns=3030.2225699558176, rejit_avg_ns=3132.6710618846696, speedup=0.9672967605263934
- event_wake_up_n (kprobe): sites=13, stock_avg_ns=4253.413850110213, rejit_avg_ns=4463.493857493858, speedup=0.952933729923043
- event_execve (tracepoint): sites=29, stock_avg_ns=5738.8434445878665, rejit_avg_ns=5918.553367328996, speedup=0.9696361743169968
- tg_kp_bprm_comm (kprobe): sites=3, stock_avg_ns=473.1056610732067, rejit_avg_ns=465.90909090909093, speedup=1.0154462969376143
- execve_map_upda (socket_filter): sites=1, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `336992.2878474` ops/s
- Events/s mean: `189.6434821838211`
- Agent CPU mean: `33.7066107908285`%
- BPF avg ns mean: `3958.060422521527`

- stress_exec: ops/s=189.37946211296637, events/s=757.7178267645508, agent_cpu=11.499973685760217, bpf_avg_ns=3494.6739245183426
- file_io: ops/s=1137485.5263742355, events/s=0.4288406446998975, agent_cpu=0.099998154580723, bpf_avg_ns=4711.615384615385
- open_storm: ops/s=207708.3684421752, events/s=0.19999996961333794, agent_cpu=112.69318483081364, bpf_avg_ns=2490.6666666666665
- connect_storm: ops/s=2585.8771110762527, events/s=0.2272613564204669, agent_cpu=10.533286492159412, bpf_avg_ns=5135.285714285715

## Comparison

- connect_storm: baseline_ops/s=2488.2848068197522, post_ops/s=2585.8771110762527, app_delta=3.9220712994358577%, baseline_cpu=8.466627601646916, post_cpu=10.533286492159412, cpu_delta=24.409469599330112%
- file_io: baseline_ops/s=1144689.1576471261, post_ops/s=1137485.5263742355, app_delta=-0.6293089459934652%, baseline_cpu=0.06666616227714948, post_cpu=0.099998154580723, cpu_delta=49.99836673514114%
- open_storm: baseline_ops/s=209978.92488518127, post_ops/s=207708.3684421752, app_delta=-1.0813258731787616%, baseline_cpu=112.49975268054371, post_cpu=112.69318483081364, cpu_delta=0.17194006712103715%
- stress_exec: baseline_ops/s=180.57394368553324, post_ops/s=189.37946211296637, app_delta=4.876405890967195%, baseline_cpu=10.333312329842691, post_cpu=11.499973685760217, cpu_delta=11.290294134903853%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
