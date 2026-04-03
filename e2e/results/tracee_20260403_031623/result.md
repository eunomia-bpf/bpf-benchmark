# Tracee Real End-to-End Benchmark

- Generated: 2026-04-03T03:26:03.588822+00:00
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

- tracee_default: primary_events/s=40631.864136713964, bpf_avg_ns=102.96523982342106, target_runs=3417848

## Control

- tracee_default: app_mean=173790.88965628282 ops/s, app_ci95=[171549.83769999823, 176156.76878570675]

## Baseline

- tracee_default: app_mean=37570.25915111655 ops/s, primary_events_mean=38916.750998040574/s, latency_p99_mean=47.251157532 ms, overhead_mean=78.36998840386633%, bpf_avg_ns_mean=100.4470243517369

## Post-ReJIT

- tracee_default: app_mean=35285.13613871179 ops/s, primary_events_mean=36612.12774510466/s, latency_p99_mean=47.207090616 ms, overhead_mean=79.69278947729399%, bpf_avg_ns_mean=104.56552679062217

## Comparison

- tracee_default: app_delta_mean=-5.861071981348746%, event_delta_mean=-5.7199275562694885%, overhead_delta_mean=1.7098060197157257%, latency_p99_delta_mean=-0.05873666465810694%, app_p=0.125, overhead_p=0.125

