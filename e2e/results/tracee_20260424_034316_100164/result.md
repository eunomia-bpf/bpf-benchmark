# Tracee Real End-to-End Benchmark

- Generated: 2026-04-24T03:52:37.783760+00:00
- Mode: `tracee_daemon_same_image_paired`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `0`
- Smoke: `True`
- Tracee binary: `/artifacts/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Baseline

- tracee_default: app_mean=5023.115581763078 ops/s, events_mean=15600.882875051955/s, latency_p99_mean=None ms, bpf_avg_ns_mean=221.01292150253698

## Post-ReJIT

- tracee_default: app_mean=4700.215500960536 ops/s, events_mean=14967.84840829601/s, latency_p99_mean=None ms, bpf_avg_ns_mean=228.8396793634247

## Comparison

- tracee_default: app_delta_mean=-2.523735856289317%, event_delta_mean=-4.0584756682062615%, latency_p99_delta_mean=None%, app_p=1.0

