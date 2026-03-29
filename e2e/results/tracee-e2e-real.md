# Tracee Real End-to-End Benchmark

- Generated: 2026-03-29T01:21:28.501972+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=2.1995210466901303 bogo-ops/s, events/s=6051.324571201357, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=12.5812198444066, bpf_avg_ns=None
- file_io: app=5807.000831563887 IOPS, events/s=7.691411688171029, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.14999990673255795, bpf_avg_ns=None
- network: app=6254.794854646906 req/s, events/s=6257.040311479103, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=20.399911898560482, bpf_avg_ns=None

## Post-ReJIT

- exec_storm: app=69.27215294483146 bogo-ops/s, events/s=6087.116136032174, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=10.105212966587322, bpf_avg_ns=None
- file_io: app=5856.11755008097 IOPS, events/s=7.794881076607696, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.1333331539913524, bpf_avg_ns=None
- network: app=6149.509595174974 req/s, events/s=6151.5757274922325, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=19.983149395104213, bpf_avg_ns=None

## Comparison

- exec_storm: app_delta=3049.4198725251185%, events_delta=0.5914666187490837%, cpu_delta=-19.680181321369005%, bpf_ns_delta=None%
- file_io: app_delta=0.845819037085548%, events_delta=1.3452587461388599%, cpu_delta=-11.11117540287642%, bpf_ns_delta=None%
- network: app_delta=-1.6832727838181996%, events_delta=-1.6855346735322538%, cpu_delta=-2.0429622712521507%, bpf_ns_delta=None%

