# Tracee Real End-to-End Benchmark

- Generated: 2026-03-23T13:23:22.039159+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Baseline

- exec_storm: app=5079.268110892902 bogo-ops/s, events/s=24788.564883075614, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.19999974149700078, bpf_avg_ns=127.40935256157785
- file_io: app=1156946.5558309145 IOPS, events/s=8.547985485415293, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.19999971937706046, bpf_avg_ns=22.668979424652285
- network: app=7672.857287871976 req/s, events/s=2.0293283669796676, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.06666641456761996, bpf_avg_ns=34.869514914675605

## Post-ReJIT

- exec_storm: app=162183.581417563 bogo-ops/s, events/s=48264.14331696598, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.21666595689065854, bpf_avg_ns=120.3250812407681
- file_io: app=1185066.356588912 IOPS, events/s=8.541216370491735, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.199999734567019, bpf_avg_ns=20.544203742523656
- network: app=7359.612001984583 req/s, events/s=1.8798965519192778, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.06666653944135395, bpf_avg_ns=34.976613685718505

## Comparison

- exec_storm: app_delta=3093.050216619736%, events_delta=94.70325750853898%, cpu_delta=8.333118467509463%, bpf_ns_delta=-5.56024434500275%
- file_io: app_delta=2.43051855907051%, events_delta=-0.0791895930930944%, cpu_delta=7.594989927139677e-06%, bpf_ns_delta=-9.373053997384446%
- network: app_delta=-4.082511561664531%, events_delta=-7.3636094331443855%, cpu_delta=0.00018731130930312642%, bpf_ns_delta=0.3071415570447886%
