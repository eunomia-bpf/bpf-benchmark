# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T17:41:40.180776+00:00
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

- tracee_default: primary_events/s=42329.96412451099, bpf_avg_ns=96.16044812119257, target_runs=3949021

## Control

- tracee_default: app_mean=173653.95969490323 ops/s, app_ci95=[170919.37521515644, 176220.408415969]

## Baseline

- tracee_default: app_mean=37109.64293656338 ops/s, primary_events_mean=38515.64235676636/s, latency_p99_mean=46.704988344 ms, overhead_mean=78.62121170850534%, bpf_avg_ns_mean=102.50350167759062

## Post-ReJIT

- tracee_default: app_mean=35914.40562936659 ops/s, primary_events_mean=37307.61587273136/s, latency_p99_mean=47.49791367 ms, overhead_mean=79.3066030765282%, bpf_avg_ns_mean=104.73982104494733

## Comparison

- tracee_default: app_delta_mean=-3.0793353719384515%, event_delta_mean=-3.0004160793940136%, overhead_delta_mean=0.8825394106815154%, latency_p99_delta_mean=1.7120421738557812%, app_p=0.3125, overhead_p=0.3125

