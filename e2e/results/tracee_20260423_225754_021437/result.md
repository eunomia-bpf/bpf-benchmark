# Tracee Real End-to-End Benchmark

- Generated: 2026-04-23T23:26:01.831147+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `0`
- Smoke: `False`
- Tracee binary: `/artifacts/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Preflight

- tracee_default: events/s=16067.72686099431, bpf_avg_ns=213.0473031213723, program_runs=8631460

## Control

- tracee_default: app_mean=5658.715061690369 ops/s, app_ci95=[5637.920753154849, 5671.252549840322]

## Baseline

- tracee_default: app_mean=3206.991183941238 ops/s, events_mean=15398.575211483023/s, latency_p99_mean=None ms, overhead_mean=43.29240520252764%, bpf_avg_ns_mean=217.71262046695813

## Post-ReJIT

- tracee_default: app_mean=3475.753028113756 ops/s, events_mean=15257.797559378554/s, latency_p99_mean=None ms, overhead_mean=38.56796078690817%, bpf_avg_ns_mean=215.49554751294409

## Comparison

- tracee_default: app_delta_mean=12.550418495232984%, event_delta_mean=-0.9195999742448945%, overhead_delta_mean=-2.75226880758656%, latency_p99_delta_mean=None%, app_p=0.5, overhead_p=0.5

