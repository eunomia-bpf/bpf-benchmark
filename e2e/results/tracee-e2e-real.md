# Tracee Real End-to-End Benchmark

- Generated: 2026-03-28T18:44:02.536762+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=2.445495564328929 bogo-ops/s, events/s=6703.908029312058, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.64998771958646, bpf_avg_ns=None
- file_io: app=5352.025521669283 IOPS, events/s=7.718442959356406, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.14999851241475293, bpf_avg_ns=None
- network: app=6215.461979869563 req/s, events/s=6217.70580495843, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=20.28328796705536, bpf_avg_ns=None

## Post-ReJIT

- exec_storm: app=71.59703134276546 bogo-ops/s, events/s=7586.173028647651, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=10.683257642987096, bpf_avg_ns=None
- file_io: app=6129.987782098649 IOPS, events/s=7.693212500207147, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.18333224827836642, bpf_avg_ns=None
- network: app=6309.372323718108 req/s, events/s=6311.438468281649, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=20.14997822559767, bpf_avg_ns=None

## Comparison

- exec_storm: app_delta=2827.7105379830236%, events_delta=13.160457981792002%, cpu_delta=10.707473972256167%, bpf_ns_delta=None%
- file_io: app_delta=14.535847358715918%, events_delta=-0.3268853482770753%, cpu_delta=22.222710963588856%, bpf_ns_delta=None%
- network: app_delta=1.5109149432930191%, events_delta=1.5075120352022735%, cpu_delta=-0.6572393079180042%, bpf_ns_delta=None%

