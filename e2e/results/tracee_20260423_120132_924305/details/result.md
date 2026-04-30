# Tracee Real End-to-End Benchmark

- Generated: 2026-04-23T12:04:42.084918+00:00
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

- tracee_default: primary_events/s=16306.423205173836, bpf_avg_ns=74.93606965906915, program_runs=3530452

## Control

- tracee_default: app_mean=6190.666744316497 ops/s, app_ci95=[6178.58630205172, 6202.747186581273]

## Baseline

- tracee_default: app_mean=2169.308146417871 ops/s, primary_events_mean=15648.10596292487/s, latency_p99_mean=2643.5869075799997 ms, overhead_mean=64.98376757265723%, bpf_avg_ns_mean=75.34721815709868

## Post-ReJIT

- tracee_default: app_mean=3510.6105836543434 ops/s, primary_events_mean=15720.205953883682/s, latency_p99_mean=3136.7211755199996 ms, overhead_mean=43.294137582075%, bpf_avg_ns_mean=72.4490889685921

## Comparison

- tracee_default: app_delta_mean=86.38833653363488%, event_delta_mean=0.5046892266991581%, overhead_delta_mean=-30.972155370123144%, latency_p99_delta_mean=123.53673983410154%, app_p=0.5, overhead_p=0.5

