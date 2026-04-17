# Tracee Real End-to-End Benchmark

- Generated: 2026-04-16T05:01:07.071433+00:00
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

- tracee_default: primary_events/s=24133.924032791416, bpf_avg_ns=37.9868373433416, target_runs=2760385

## Control

- tracee_default: app_mean=5748.111003307423 ops/s, app_ci95=[5730.521027278193, 5760.983988833009]

## Baseline

- tracee_default: app_mean=3719.8278733275306 ops/s, primary_events_mean=24477.349462619703/s, latency_p99_mean=1.6793665799999997 ms, overhead_mean=35.299904289588895%, bpf_avg_ns_mean=38.42351688456855

## Post-ReJIT

- tracee_default: app_mean=4139.132148861117 ops/s, primary_events_mean=24211.77651921629/s, latency_p99_mean=1.1273179179999997 ms, overhead_mean=27.97172240811727%, bpf_avg_ns_mean=38.097534201654604

## Comparison

- tracee_default: app_delta_mean=14.33835321076817%, event_delta_mean=-1.0054180419433196%, overhead_delta_mean=-12.562983728606392%, latency_p99_delta_mean=-14.114732817068415%, app_p=0.4375, overhead_p=0.4375

