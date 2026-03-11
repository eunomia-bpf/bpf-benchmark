# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-11T17:29:08.953023+00:00
- Mode: `tetragon_daemon`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `320198.9370160906` ops/s
- Events/s mean: `162.40248320572738`
- Agent CPU mean: `32.37411715567919`%
- BPF avg ns mean: `3627.4069358753404`

- stress_exec: ops/s=160.18061932649977, events/s=644.845691376026, agent_cpu=10.499912223358791, bpf_avg_ns=3006.054059290835
- file_io: ops/s=1072690.3311578599, events/s=2.191798572483781, agent_cpu=0.2499976650843075, bpf_avg_ns=4451.473684210527
- open_storm: ops/s=207608.02149397894, events/s=1.3749471599213021, agent_cpu=112.24672127327159, bpf_avg_ns=3042.0
- connect_storm: ops/s=337.2147931971113, events/s=1.1974957144783782, agent_cpu=6.499837461002051, bpf_avg_ns=4010.1

## Recompile

- Applied programs: `1` / `5`
- Applied successfully: `True`

## Per-Program

- event_exit_acct (kprobe): sites=0, stock_avg_ns=2717.84662110858, rejit_avg_ns=2685.5058224163026, speedup=1.0120427214948946
- event_wake_up_n (kprobe): sites=0, stock_avg_ns=3776.9801526717556, rejit_avg_ns=3719.8453757225434, speedup=1.0153594494335976
- event_execve (tracepoint): sites=9, stock_avg_ns=5208.947163947164, rejit_avg_ns=5142.2396212672975, speedup=1.0129724687282127
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=342.83061383061386, rejit_avg_ns=353.53678077203205, speedup=0.9697169643338418
- execve_map_upda (socket_filter): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Post-ReJIT

- Application throughput mean: `332335.6893404929` ops/s
- Events/s mean: `171.94444251093563`
- Agent CPU mean: `31.715739578695846`%
- BPF avg ns mean: `3100.4774412334655`

- stress_exec: ops/s=170.96890101335916, events/s=684.6254676543724, agent_cpu=7.624942269655845, bpf_avg_ns=2975.0379700620665
- file_io: ops/s=1115911.7529087388, events/s=1.5624610888972161, agent_cpu=0.6249851298850513, bpf_avg_ns=3867.5384615384614
- open_storm: ops/s=212957.08480672713, events/s=0.749977847623073, agent_cpu=111.61321067325123, bpf_avg_ns=2599.3333333333335
- connect_storm: ops/s=302.9507454922439, events/s=0.8398634528497851, agent_cpu=6.999820241991254, bpf_avg_ns=2960.0

## Comparison

- connect_storm: baseline_ops/s=337.2147931971113, post_ops/s=302.9507454922439, app_delta=-10.160896970151336%, baseline_cpu=6.499837461002051, post_cpu=6.999820241991254, cpu_delta=7.692235136478676%
- file_io: baseline_ops/s=1072690.3311578599, post_ops/s=1115911.7529087388, app_delta=4.02925434260471%, baseline_cpu=0.2499976650843075, post_cpu=0.6249851298850513, cpu_delta=149.99638683596726%
- open_storm: baseline_ops/s=207608.02149397894, post_ops/s=212957.08480672713, app_delta=2.5765205382024794%, baseline_cpu=112.24672127327159, post_cpu=111.61321067325123, cpu_delta=-0.5643911847349531%
- stress_exec: baseline_ops/s=160.18061932649977, post_ops/s=170.96890101335916, app_delta=6.73507302707414%, baseline_cpu=10.499912223358791, post_cpu=7.624942269655845, cpu_delta=-27.380895121266825%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
