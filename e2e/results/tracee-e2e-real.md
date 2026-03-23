# Tracee Real End-to-End Benchmark

- Generated: 2026-03-23T08:40:34.580785+00:00
- Mode: `manual_fallback`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `unavailable`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=5210.657268164439 bogo-ops/s, events/s=56400.656502637736, drops={}, agent_cpu=None, bpf_avg_ns=93.94723953695458
- file_io: app=1577123.0724232877 IOPS, events/s=15.843891837587627, drops={}, agent_cpu=None, bpf_avg_ns=289.24112734864303
- network: app=7635.00013212228 req/s, events/s=2.799010221656046, drops={}, agent_cpu=None, bpf_avg_ns=577.172619047619

## Post-ReJIT

- exec_storm: app=115981.11476403479 bogo-ops/s, events/s=121300.85390455047, drops={}, agent_cpu=None, bpf_avg_ns=126.01536064113981
- file_io: app=1571288.6059416337 IOPS, events/s=15.824114489999918, drops={}, agent_cpu=None, bpf_avg_ns=219.13836477987422
- network: app=7791.108332509961 req/s, events/s=2.49523069834421, drops={}, agent_cpu=None, bpf_avg_ns=590.7466666666667

## Comparison

- exec_storm: app_delta=2125.8442418127324%, events_delta=115.06993256164935%, cpu_delta=None%, bpf_ns_delta=34.134181336505456%
- file_io: app_delta=-0.3699436387478103%, events_delta=-0.1248263229163807%, cpu_delta=None%, bpf_ns_delta=-24.236789287668948%
- network: app_delta=2.0446391314506487%, events_delta=-10.85310517844782%, cpu_delta=None%, bpf_ns_delta=2.3518176661682078%

## Limitations

- Tracee daemon was unavailable, so this result uses manual BPF program loading with corpus/build/tracee/tracee.bpf.o.
- Agent event counts and drop counters are unavailable in manual fallback mode; events_total is estimated from BPF run_cnt deltas.
- Agent CPU is unavailable in manual fallback mode; only host busy CPU is reported.
- Tracee binary (/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee) was present but failed to start: failed to launch Tracee: Error: invalid output flag: format, use 'tracee man output' for more info
