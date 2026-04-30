# Tracee Real End-to-End Benchmark

- Generated: 2026-04-24T02:12:56.231351+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `0`
- Smoke: `True`
- Tracee binary: `/artifacts/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Preflight

- tracee_default: events/s=15880.004168899286, bpf_avg_ns=200.58978956150267, program_runs=7937426

## Control

- tracee_default: app_mean=6157.437146426275 ops/s, app_ci95=[6156.758548665374, 6158.1157441871765]

## Baseline

- tracee_default: app_mean=4587.635783762443 ops/s, events_mean=15856.751669150073/s, latency_p99_mean=None ms, overhead_mean=25.49631586805041%, bpf_avg_ns_mean=220.96180989073844

## Post-ReJIT

- tracee_default: app_mean=4858.485452015635 ops/s, events_mean=15833.397740399363/s, latency_p99_mean=None ms, overhead_mean=21.094283988720534%, bpf_avg_ns_mean=226.4612328745891

## Comparison

- tracee_default: app_delta_mean=16.170361377732824%, event_delta_mean=-0.14499205260563913%, overhead_delta_mean=117.87784337931825%, latency_p99_delta_mean=None%, app_p=1.0, overhead_p=1.0

