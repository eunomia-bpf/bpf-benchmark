# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T03:26:10.715956+00:00
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

- tracee_default: primary_events/s=32481.86934696746, bpf_avg_ns=110.85965266917158, target_runs=2987987

## Control

- tracee_default: app_mean=170771.19562327585 ops/s, app_ci95=[169810.0366036416, 171734.60961173574]

## Baseline

- tracee_default: app_mean=37286.01928343948 ops/s, primary_events_mean=38645.805100239566/s, latency_p99_mean=47.744632226 ms, overhead_mean=78.16605793493324%, bpf_avg_ns_mean=101.41541259076486

## Post-ReJIT

- tracee_default: app_mean=35262.14050963447 ops/s, primary_events_mean=36614.55150568986/s, latency_p99_mean=47.776629428 ms, overhead_mean=79.35200769904516%, bpf_avg_ns_mean=105.55819927029889

## Comparison

- tracee_default: app_delta_mean=-5.307011136139127%, event_delta_mean=-5.141691362572713%, overhead_delta_mean=1.5282824394762966%, latency_p99_delta_mean=0.07936633401381377%, app_p=0.0625, overhead_p=0.0625

