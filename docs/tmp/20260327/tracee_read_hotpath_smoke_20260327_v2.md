# Tracee Real End-to-End Benchmark

- Generated: 2026-03-27T19:40:01.581012+00:00
- Mode: `tracee_daemon`
- Duration per workload: `5s`
- Smoke: `True`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Preflight

- read_hotpath: events/s=57079.46925723657, bpf_avg_ns=164.98621778688366, target_runs=3295552

## Baseline

- read_hotpath: app=13721.880229973474 reads/s, events/s=70222.9517490606, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=91.99448774549099, bpf_avg_ns=160.83389300161167

## Post-ReJIT

- read_hotpath: app=13629.51410585694 reads/s, events/s=70109.8275219205, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=92.39867814451047, bpf_avg_ns=159.8985951565933

## Comparison

- read_hotpath: app_delta=-0.6731302311965467%, events_delta=-0.1610929536889086%, cpu_delta=0.4393637150713901%, bpf_ns_delta=-0.5815303152607244%
