# Tracee Real End-to-End Benchmark

- Generated: 2026-03-11T16:39:51.842923+00:00
- Mode: `tracee_daemon`
- Duration per workload: `10s`
- Smoke: `True`
- Tracee binary: `/tmp/tracee-bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `missing`

## Baseline

- exec_storm: app=159.16212500084035 bogo-ops/s, events/s=1605.8178717107398, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=4.199973097492322, bpf_avg_ns=59.15254441178766
- file_io: app=826273.7659960858 IOPS, events/s=37.91495004963292, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.19999370119838075, bpf_avg_ns=30.440662288831184
- network: app=5005.820995939112 req/s, events/s=5021.227472459059, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=13.299856670104639, bpf_avg_ns=41.25552695413081

## Recompile

- Applied programs: `8` / `15`
- Applied successfully: `True`
- Errors: `['BPF_PROG_JIT_RECOMPILE: Invalid argument']`

## Post-ReJIT

- exec_storm: app=193.6252225780035 bogo-ops/s, events/s=1945.6485969325038, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=4.299970607980907, bpf_avg_ns=57.594425646771796
- file_io: app=868049.867819251 IOPS, events/s=34.10333705763801, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.09999942675328613, bpf_avg_ns=30.383980294009092
- network: app=5072.0096672818445 req/s, events/s=5084.460196574789, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=13.499874027275487, bpf_avg_ns=42.02283103002686

## Comparison

- exec_storm: app_delta=21.652825744178266%, events_delta=21.162469991676524%, cpu_delta=2.3809083574437744%, bpf_ns_delta=-2.6340688815836764%
- file_io: app_delta=5.055963718369233%, events_delta=-10.053060829581169%, cpu_delta=-49.998711882384136%, bpf_ns_delta=-0.18620486730635075%
- network: app_delta=1.3222340830090906%, events_delta=1.2593080967264536%, cpu_delta=1.5039061106609253%, bpf_ns_delta=1.8598818935197758%
