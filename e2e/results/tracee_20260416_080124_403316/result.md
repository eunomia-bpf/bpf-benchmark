# Tracee Real End-to-End Benchmark

- Generated: 2026-04-16T08:09:38.415094+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `8`
- Smoke: `False`
- Tracee binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/opt/bpf-benchmark/repo-artifacts/x86_64/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=9125.150624176982, bpf_avg_ns=121.62326808355284, target_runs=788866

## Control

- tracee_default: app_mean=36988.27414447149 ops/s, app_ci95=[36590.6092246467, 37430.38804682241]

## Baseline

- tracee_default: app_mean=6898.65835184435 ops/s, primary_events_mean=10518.901527690894/s, latency_p99_mean=1.081853166 ms, overhead_mean=81.33963489651747%, bpf_avg_ns_mean=111.32660955539735

## Post-ReJIT

- tracee_default: app_mean=6639.7357729827545 ops/s, primary_events_mean=10166.737831141823/s, latency_p99_mean=0.674228226 ms, overhead_mean=82.0427669315305%, bpf_avg_ns_mean=116.63294541178487

## Comparison

- tracee_default: app_delta_mean=-3.492442172644334%, event_delta_mean=-3.180245316662852%, overhead_delta_mean=0.8796089021405327%, latency_p99_delta_mean=-13.615822290738357%, app_p=0.375, overhead_p=0.375

