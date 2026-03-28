# Tracee Real End-to-End Benchmark

- Generated: 2026-03-28T21:47:45.991773+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=2.5138534937575483 bogo-ops/s, events/s=6875.0200022074505, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=16.016646929085713, bpf_avg_ns=None
- file_io: app=5296.9956356014045 IOPS, events/s=7.7108316526966485, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.14999976337287332, bpf_avg_ns=None
- network: app=6045.42865358594 req/s, events/s=6047.677597824052, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=19.933310016343942, bpf_avg_ns=None

## Post-ReJIT

- exec_storm: app=195.48474255526972 bogo-ops/s, events/s=6601.854195079897, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=10.246720524970698, bpf_avg_ns=None
- file_io: app=6092.111455744814 IOPS, events/s=7.747659094127942, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.13333288615927746, bpf_avg_ns=None
- network: app=5937.0002003032305 req/s, events/s=5939.062998785773, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=19.766645493624324, bpf_avg_ns=None

## Comparison

- exec_storm: app_delta=7676.2981430978925%, events_delta=-3.973309270952586%, cpu_delta=-36.02455888340159%, bpf_ns_delta=None%
- file_io: app_delta=15.010694265998467%, events_delta=0.47760660704367125%, cpu_delta=-11.11126900391496%, bpf_ns_delta=None%
- network: app_delta=-1.793561044151825%, events_delta=-1.7959720451592638%, cpu_delta=-0.8361106237898488%, bpf_ns_delta=None%

