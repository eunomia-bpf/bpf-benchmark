# Tracee Real End-to-End Benchmark

- Generated: 2026-04-09T07:25:54.244710+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `8`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/x86_64/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/x86_64/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=41857.238869133216, bpf_avg_ns=24.860189465432768, target_runs=3707167

## Control

- tracee_default: app_mean=170477.1126725278 ops/s, app_ci95=[169686.42681460304, 171262.73226407453]

## Baseline

- tracee_default: app_mean=36929.33441545613 ops/s, primary_events_mean=37977.06751670699/s, latency_p99_mean=46.964315078 ms, overhead_mean=78.33808914665536%, bpf_avg_ns_mean=24.824558330224107

## Post-ReJIT

- tracee_default: app_mean=36121.927480415965 ops/s, primary_events_mean=37172.281682499335/s, latency_p99_mean=46.966073768 ms, overhead_mean=78.81049174781622%, bpf_avg_ns_mean=24.762935299578377

## Comparison

- tracee_default: app_delta_mean=-2.1321163641643364%, event_delta_mean=-2.0659346341990563%, overhead_delta_mean=0.6067302815052702%, latency_p99_delta_mean=0.03776155075656601%, app_p=0.3125, overhead_p=0.3125

