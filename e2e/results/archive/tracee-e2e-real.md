# Tracee Real End-to-End Benchmark

- Generated: 2026-03-13T22:29:19.047527+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/tmp/tracee-bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `missing`

## Baseline

- exec_storm: app=160.50696123606414 bogo-ops/s, events/s=1608.1860905821288, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.199984401119782, bpf_avg_ns=95.63331080014508
- file_io: app=4332.315321477536 IOPS, events/s=5.56385123652973, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.11666655643427079, bpf_avg_ns=46.86608838549948
- network: app=4871.188601990146 req/s, events/s=4873.536772728782, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=21.633286774534092, bpf_avg_ns=44.19007399472078

## Recompile

- Applied programs: `11` / `13`
- Applied successfully: `True`

## Post-ReJIT

- exec_storm: app=170.58279252902014 bogo-ops/s, events/s=1707.3945869900283, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.249978189013932, bpf_avg_ns=91.59464585621754
- file_io: app=4635.565527283639 IOPS, events/s=5.631057062237587, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.11666635397167141, bpf_avg_ns=48.117391848422166
- network: app=4941.133277442105 req/s, events/s=4943.2325480820455, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=21.799974375220124, bpf_avg_ns=44.03372239889718

## Comparison

- exec_storm: app_delta=6.27750423742498%, events_delta=6.168968690183617%, cpu_delta=0.5434116593509172%, bpf_ns_delta=-4.223073435539174%
- file_io: app_delta=6.999726088789866%, events_delta=1.2079011974046703%, cpu_delta=-0.00017353953486596405%, bpf_ns_delta=2.6699549845722617%
- network: app_delta=1.4358851846422713%, events_delta=1.4300861695199523%, cpu_delta=0.770514450361979%, bpf_ns_delta=-0.3538160987064033%
