# Tracee Real End-to-End Benchmark

- Generated: 2026-04-23T11:32:10.880093+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `3`
- Smoke: `True`
- Tracee binary: `/artifacts/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=16448.00422728744, bpf_avg_ns=72.11704731939525, program_runs=3866385

## Control

- tracee_default: app_mean=6153.107278287753 ops/s, app_ci95=[6149.476480941687, 6156.738075633818]

## Baseline

- tracee_default: app_mean=4035.816276531612 ops/s, primary_events_mean=16116.463876542217/s, latency_p99_mean=2937.32656788 ms, overhead_mean=34.414568515821884%, bpf_avg_ns_mean=73.28639378672293

## Post-ReJIT

- tracee_default: app_mean=2629.036071448025 ops/s, primary_events_mean=15627.808697047172/s, latency_p99_mean=315.35212881999996 ms, overhead_mean=57.2626125500393%, bpf_avg_ns_mean=75.99872161052247

## Comparison

- tracee_default: app_delta_mean=-30.816929801310657%, event_delta_mean=-3.026730241554425%, overhead_delta_mean=86.65295450868216%, latency_p99_delta_mean=-77.73449013422459%, app_p=1.0, overhead_p=1.0

