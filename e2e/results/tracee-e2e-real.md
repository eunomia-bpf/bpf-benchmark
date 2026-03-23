# Tracee Real End-to-End Benchmark

- Generated: 2026-03-23T11:02:38.741951+00:00
- Mode: `manual_fallback`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `unavailable`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=5312.335157893916 bogo-ops/s, events/s=56547.41594611249, drops={}, agent_cpu=None, bpf_avg_ns=105.983303650935
- file_io: app=1545799.4852790493 IOPS, events/s=15.843745230200602, drops={}, agent_cpu=None, bpf_avg_ns=219.24321503131523
- network: app=7759.545495381501 req/s, events/s=2.79445236137444, drops={}, agent_cpu=None, bpf_avg_ns=473.9166666666667

## Post-ReJIT

- exec_storm: app=300549.21946342464 bogo-ops/s, events/s=107919.03228055185, drops={}, agent_cpu=None, bpf_avg_ns=119.94479073909172
- file_io: app=1538327.3810723838 IOPS, events/s=15.823455983765555, drops={}, agent_cpu=None, bpf_avg_ns=177.32075471698113
- network: app=7845.385858509152 req/s, events/s=2.495425815813813, drops={}, agent_cpu=None, bpf_avg_ns=625.1333333333333

## Comparison

- exec_storm: app_delta=5557.572621652469%, events_delta=90.84697412768523%, cpu_delta=None%, bpf_ns_delta=13.173289194815116%
- file_io: app_delta=-0.4833812068009938%, events_delta=-0.1280583986945977%, cpu_delta=None%, bpf_ns_delta=-19.121440227167888%
- network: app_delta=1.106255040050269%, events_delta=-10.700720817210566%, cpu_delta=None%, bpf_ns_delta=31.907860031651126%

## Limitations

- Tracee daemon was unavailable, so this result uses manual BPF program loading with corpus/build/tracee/tracee.bpf.o.
- Agent event counts and drop counters are unavailable in manual fallback mode; events_total is estimated from BPF run_cnt deltas.
- Agent CPU is unavailable in manual fallback mode; only host busy CPU is reported.
- Tracee binary (/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee) was present but failed to start: failed to launch Tracee: Error: invalid output flag: format, use 'tracee man output' for more info
