# Tracee Real End-to-End Benchmark

- Generated: 2026-03-28T14:31:49.331201+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=2.541761316729036 bogo-ops/s, events/s=6480.799325951943, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.94870586753221, bpf_avg_ns=None
- file_io: app=5109.362720668877 IOPS, events/s=7.763585965384045, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.19999905755777436, bpf_avg_ns=None
- network: app=6179.781049213797 req/s, events/s=6182.026071378609, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=19.349940399926073, bpf_avg_ns=None

## Post-ReJIT

- exec_storm: app=47.673964150923425 bogo-ops/s, events/s=6514.598052807035, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.531160002964167, bpf_avg_ns=None
- file_io: app=5541.476231717004 IOPS, events/s=7.72459448743151, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.13333309146266104, bpf_avg_ns=None
- network: app=6492.228526743261 req/s, events/s=6494.29464555979, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=19.9666160985492, bpf_avg_ns=None

## Comparison

- exec_storm: app_delta=1775.627103030843%, events_delta=0.5215209599184399%, cpu_delta=-4.196986724984115%, bpf_ns_delta=None%
- file_io: app_delta=8.45728781987039%, events_delta=-0.5022354119138791%, cpu_delta=-33.33314012035047%, bpf_ns_delta=None%
- network: app_delta=5.055963553420942%, events_delta=5.05123353696152%, cpu_delta=3.186964331039915%, bpf_ns_delta=None%

