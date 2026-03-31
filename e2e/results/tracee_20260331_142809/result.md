# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T14:37:45.471102+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `8`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=38823.67179599897, bpf_avg_ns=99.96155045326793, target_runs=3560146

## Control

- tracee_default: app_mean=171724.91111920733 ops/s, app_ci95=[169166.63211948666, 174283.19011892797]

## Baseline

- tracee_default: app_mean=38173.627432849375 ops/s, primary_events_mean=39548.27544893248/s, latency_p99_mean=47.510323288 ms, overhead_mean=77.75004875897451%, bpf_avg_ns_mean=99.24321124372823

## Post-ReJIT

- tracee_default: app_mean=35939.67495400478 ops/s, primary_events_mean=37326.09859849741/s, latency_p99_mean=47.348467516 ms, overhead_mean=79.07018212492966%, bpf_avg_ns_mean=103.93942753349643

## Comparison

- tracee_default: app_delta_mean=-5.586035276557408%, event_delta_mean=-5.367542416959868%, overhead_delta_mean=1.7273235689214779%, latency_p99_delta_mean=-0.32334639276702376%, app_p=0.1875, overhead_p=0.1875

