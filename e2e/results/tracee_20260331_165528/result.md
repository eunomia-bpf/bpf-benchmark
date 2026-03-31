# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T17:05:07.390316+00:00
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

- tracee_default: primary_events/s=40942.637247157065, bpf_avg_ns=98.85293798752622, target_runs=3596986

## Control

- tracee_default: app_mean=172497.79198627896 ops/s, app_ci95=[168514.3864057828, 178029.57470993066]

## Baseline

- tracee_default: app_mean=37234.73443313106 ops/s, primary_events_mean=38621.80892614916/s, latency_p99_mean=47.77660872 ms, overhead_mean=78.39658537730567%, bpf_avg_ns_mean=100.79170060176668

## Post-ReJIT

- tracee_default: app_mean=35567.06610990159 ops/s, primary_events_mean=36915.46582531997/s, latency_p99_mean=48.038801484000004 ms, overhead_mean=79.37012188955177%, bpf_avg_ns_mean=103.24226535572755

## Comparison

- tracee_default: app_delta_mean=-4.471277340507935%, event_delta_mean=-4.412736101952747%, overhead_delta_mean=1.2447702833545156%, latency_p99_delta_mean=0.6083391214306993%, app_p=0.0625, overhead_p=0.0625

