# Tracee Real End-to-End Benchmark

- Generated: 2026-03-28T20:53:00.351516+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=2.4956019278541657 bogo-ops/s, events/s=6496.909281430887, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.91161600218772, bpf_avg_ns=None
- file_io: app=5293.52816692509 IOPS, events/s=7.637043561596746, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.1666664589502588, bpf_avg_ns=None
- network: app=6154.716383713467 req/s, events/s=6156.9600890372585, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=19.899856142944948, bpf_avg_ns=None

## Post-ReJIT

- exec_storm: app=38.228668549115156 bogo-ops/s, events/s=6186.296679070551, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=17.594194747938598, bpf_avg_ns=None
- file_io: app=5374.877031241992 IOPS, events/s=7.568313124106949, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.1333331143892483, bpf_avg_ns=None
- network: app=6225.689135232274 req/s, events/s=6227.751960267663, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=20.149961666041264, bpf_avg_ns=None

## Comparison

- exec_storm: app_delta=1431.8416019170947%, events_delta=-4.780928729420798%, cpu_delta=77.51085942045329%, bpf_ns_delta=None%
- file_io: app_delta=1.5367607718644882%, events_delta=-0.8999613127180799%, cpu_delta=-20.000031662614706%, bpf_ns_delta=None%
- network: app_delta=1.1531441433534475%, events_delta=1.149786099092189%, cpu_delta=1.2568207594052654%, bpf_ns_delta=None%

