# Tracee Real End-to-End Benchmark

- Generated: 2026-03-12T20:59:22.212741+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/tmp/tracee-bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `missing`

## Baseline

- exec_storm: app=167.0368712638319 bogo-ops/s, events/s=1673.8184414971051, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=4.59999504986866, bpf_avg_ns=61.85699006598996
- file_io: app=872275.5383599864 IOPS, events/s=5.863736488487441, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.06666659077453083, bpf_avg_ns=30.709953869264027
- network: app=4990.501303126027 req/s, events/s=4992.816895464134, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=13.416629624917544, bpf_avg_ns=41.57627291560031

## Recompile

- Applied programs: `13` / `15`
- Applied successfully: `True`

## Post-ReJIT

- exec_storm: app=189.74651394542136 bogo-ops/s, events/s=1899.0317773383479, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=4.683328344027537, bpf_avg_ns=60.616226300292695
- file_io: app=889503.4685890668 IOPS, events/s=5.863882723185166, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.06666624510377685, bpf_avg_ns=30.393977431501746
- network: app=5062.166886775152 req/s, events/s=5064.265974610201, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=13.616651226065008, bpf_avg_ns=41.47468619466781

## Comparison

- exec_storm: app_delta=13.59558671673152%, events_delta=13.455063599359454%, cpu_delta=1.811595300765722%, bpf_ns_delta=-2.0058586173908584%
- file_io: app_delta=1.975055985345131%, events_delta=0.0024938824930544456%, cpu_delta=-0.0005185067212271703%, bpf_ns_delta=-1.0289056086096073%
- network: app_delta=1.4360397742854902%, events_delta=1.4310374412283493%, cpu_delta=1.4908483482020032%, bpf_ns_delta=-0.2443382097734518%
