# Tracee Real End-to-End Benchmark

- Generated: 2026-04-16T04:49:37.920377+00:00
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

- tracee_default: primary_events/s=22404.74180549431, bpf_avg_ns=43.614572340606834, target_runs=1983319

## Control

- tracee_default: app_mean=5756.525715798379 ops/s, app_ci95=[5717.836645215008, 5795.214786381749]

## Baseline

- tracee_default: app_mean=4032.3849713772092 ops/s, primary_events_mean=24442.079354311798/s, latency_p99_mean=2.2607057779999993 ms, overhead_mean=29.884787282859577%, bpf_avg_ns_mean=38.24905396108666

## Post-ReJIT

- tracee_default: app_mean=4882.978743307667 ops/s, primary_events_mean=25143.417770546246/s, latency_p99_mean=1.4838123759999997 ms, overhead_mean=15.114907661791113%, bpf_avg_ns_mean=37.40127621455057

## Comparison

- tracee_default: app_delta_mean=25.861754426397155%, event_delta_mean=2.944481114928014%, overhead_delta_mean=-45.780651942481%, latency_p99_delta_mean=-33.11110496346336%, app_p=0.125, overhead_p=0.125

