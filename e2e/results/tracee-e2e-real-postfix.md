# Tracee Real End-to-End Benchmark

- Generated: 2026-03-13T20:19:44.767199+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/tmp/tracee-bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `missing`

## Baseline

- exec_storm: app=156.30793835584007 bogo-ops/s, events/s=1565.3625893964163, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=8.649990502742927, bpf_avg_ns=92.47394162336583
- file_io: app=4258.16714606473 IOPS, events/s=5.564698101367404, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.09999986538684788, bpf_avg_ns=51.05900826732214
- network: app=4911.950783021641 req/s, events/s=4914.23239032236, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=21.26664334602001, bpf_avg_ns=43.40759692590352

## Recompile

- Applied programs: `11` / `13`
- Applied successfully: `True`

## Post-ReJIT

- exec_storm: app=165.64646365229828 bogo-ops/s, events/s=1658.0312697439622, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=8.566661563220817, bpf_avg_ns=85.89825503674702
- file_io: app=4322.605197414742 IOPS, events/s=5.634575679208565, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.09999984776856509, bpf_avg_ns=50.550947463393015
- network: app=5072.118731127758 req/s, events/s=5074.217952518253, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=21.699895768529007, bpf_avg_ns=43.029098232888224

## Comparison

- exec_storm: app_delta=5.974440834347621%, events_delta=5.919949855405561%, cpu_delta=-0.963341398995594%, bpf_ns_delta=-7.110853577974127%
- file_io: app_delta=1.513281398771853%, events_delta=1.2557298988778882%, cpu_delta=-1.7618306507567594e-05%, bpf_ns_delta=-0.9950463613964985%
- network: app_delta=3.2607808013823028%, events_delta=3.255555486365564%, cpu_delta=2.037239330437533%, bpf_ns_delta=-0.8719641717586675%
