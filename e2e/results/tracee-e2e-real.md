# Tracee Real End-to-End Benchmark

- Generated: 2026-03-23T01:12:28.464251+00:00
- Mode: `manual_fallback`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `unavailable`

## Setup

- Setup return code: `1`
- Setup tracee binary: `missing`

## Baseline

- exec_storm: app=4013.2096642668357 bogo-ops/s, events/s=55323.203163236685, drops={}, agent_cpu=None, bpf_avg_ns=107.60080106809079
- file_io: app=1549997.3343521105 IOPS, events/s=15.841139398920077, drops={}, agent_cpu=None, bpf_avg_ns=232.0855949895616
- network: app=7837.094558144813 req/s, events/s=2.7990158947946044, drops={}, agent_cpu=None, bpf_avg_ns=715.0833333333334

## Post-ReJIT

- exec_storm: app=391009.6084743565 bogo-ops/s, events/s=107894.53659726084, drops={}, agent_cpu=None, bpf_avg_ns=119.25756901157614
- file_io: app=1566050.044185538 IOPS, events/s=15.81998563053624, drops={}, agent_cpu=None, bpf_avg_ns=178.58490566037736
- network: app=7809.8864697099725 req/s, events/s=2.4953839953489028, drops={}, agent_cpu=None, bpf_avg_ns=881.5733333333334

## Comparison

- exec_storm: app_delta=9643.06455892055%, events_delta=95.0258308053985%, cpu_delta=None%, bpf_ns_delta=10.833346803904217%
- file_io: app_delta=1.0356604800315674%, events_delta=-0.13353691203096418%, cpu_delta=None%, bpf_ns_delta=-23.052137006430975%
- network: app_delta=-0.3471706029955227%, events_delta=-10.847809046399954%, cpu_delta=None%, bpf_ns_delta=23.28260109544342%

## Limitations

- Tracee daemon was unavailable, so this result uses manual BPF program loading with corpus/build/tracee/tracee.bpf.o.
- Agent event counts and drop counters are unavailable in manual fallback mode; events_total is estimated from BPF run_cnt deltas.
- Agent CPU is unavailable in manual fallback mode; only host busy CPU is reported.
