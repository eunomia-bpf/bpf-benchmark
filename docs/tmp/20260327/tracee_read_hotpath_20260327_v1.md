# Tracee Real End-to-End Benchmark

- Generated: 2026-03-27T19:52:35.704448+00:00
- Mode: `tracee_daemon`
- Duration per workload: `30s`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Preflight

- read_hotpath: events/s=70467.078286882, bpf_avg_ns=160.50707239987977, target_runs=4391720

## Baseline

- read_hotpath: app=13944.328018621436 reads/s, events/s=56813.56475775671, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=89.86618057750039, bpf_avg_ns=164.75783976841103

## Post-ReJIT

- read_hotpath: app=13955.636708604496 reads/s, events/s=57063.042729559296, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=89.9331072924637, bpf_avg_ns=165.8576888054882

## Comparison

- read_hotpath: app_delta=0.08109885229290234%, events_delta=0.4391169131286174%, cpu_delta=0.0744737503399271%, bpf_ns_delta=0.6675549027731615%
