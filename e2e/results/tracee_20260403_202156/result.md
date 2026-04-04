# Tracee Real End-to-End Benchmark

- Generated: 2026-04-03T20:31:32.132681+00:00
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

- tracee_default: primary_events/s=42916.068478803936, bpf_avg_ns=98.11630649076528, target_runs=4000499

## Control

- tracee_default: app_mean=174071.26945294414 ops/s, app_ci95=[171398.52221081997, 176874.26233791834]

## Baseline

- tracee_default: app_mean=37070.066405057885 ops/s, primary_events_mean=38459.21840001968/s, latency_p99_mean=46.91318674 ms, overhead_mean=78.69005080696353%, bpf_avg_ns_mean=103.9985616414647

## Post-ReJIT

- tracee_default: app_mean=36108.91484008043 ops/s, primary_events_mean=37492.536928665606/s, latency_p99_mean=47.200220602 ms, overhead_mean=79.25161051389796%, bpf_avg_ns_mean=105.21651330770301

## Comparison

- tracee_default: app_delta_mean=-2.506716105986788%, event_delta_mean=-2.4316978354291585%, overhead_delta_mean=0.723452729599817%, latency_p99_delta_mean=0.6316421418457082%, app_p=0.25, overhead_p=0.25

