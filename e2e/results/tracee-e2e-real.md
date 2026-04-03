# Tracee Real End-to-End Benchmark

- Generated: 2026-04-03T04:47:37.622194+00:00
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

- tracee_default: primary_events/s=40512.64409635492, bpf_avg_ns=104.19349680480867, target_runs=3435788

## Control

- tracee_default: app_mean=170294.65275343347 ops/s, app_ci95=[167445.86744773865, 173144.77068180963]

## Baseline

- tracee_default: app_mean=37230.51965629501 ops/s, primary_events_mean=38593.91702892012/s, latency_p99_mean=48.172077083999994 ms, overhead_mean=78.13569229314378%, bpf_avg_ns_mean=101.99334823913621

## Post-ReJIT

- tracee_default: app_mean=35152.04596881491 ops/s, primary_events_mean=36489.53919255712/s, latency_p99_mean=47.061676288 ms, overhead_mean=79.3560177823048%, bpf_avg_ns_mean=105.12451596407219

## Comparison

- tracee_default: app_delta_mean=-5.434179094964811%, event_delta_mean=-5.316542163996992%, overhead_delta_mean=1.5748679606115243%, latency_p99_delta_mean=-2.0492485610372873%, app_p=0.0625, overhead_p=0.0625

