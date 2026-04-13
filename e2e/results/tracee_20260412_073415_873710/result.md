# Tracee Real End-to-End Benchmark

- Generated: 2026-04-12T07:35:51.722594+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `3`
- Smoke: `True`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=3525.6920371356728, bpf_avg_ns=27.748754954895674, target_runs=820653

## Control

- tracee_default: app_mean=11648.679864576443 ops/s, app_ci95=[5379.802070606474, 17917.55765854641]

## Baseline

- tracee_default: app_mean=4019.3562117978163 ops/s, primary_events_mean=4299.5264971742845/s, latency_p99_mean=67.61447482 ms, overhead_mean=44.11425037267833%, bpf_avg_ns_mean=28.06383936176524

## Post-ReJIT

- tracee_default: app_mean=1789.7322570792824 ops/s, primary_events_mean=2037.4617113036884/s, latency_p99_mean=106.11726336 ms, overhead_mean=68.93256948801753%, bpf_avg_ns_mean=33.39905608234373

## Comparison

- tracee_default: app_delta_mean=-62.65182691989589%, event_delta_mean=-58.4994376259249%, overhead_delta_mean=411.82515312218754%, latency_p99_delta_mean=74.26070682435109%, app_p=0.5, overhead_p=0.5

