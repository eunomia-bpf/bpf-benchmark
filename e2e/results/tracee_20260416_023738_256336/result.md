# Tracee Real End-to-End Benchmark

- Generated: 2026-04-16T02:45:45.826899+00:00
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

- tracee_default: primary_events/s=28102.68522512976, bpf_avg_ns=37.59287643602305, target_runs=2742644

## Control

- tracee_default: app_mean=5631.249649487019 ops/s, app_ci95=[5517.652677011344, 5724.086012411916]

## Baseline

- tracee_default: app_mean=3830.6308126409626 ops/s, primary_events_mean=24128.40231699387/s, latency_p99_mean=1.1109713899999998 ms, overhead_mean=31.70343434078418%, bpf_avg_ns_mean=38.308279202593

## Post-ReJIT

- tracee_default: app_mean=3625.03026207997 ops/s, primary_events_mean=23605.16937612412/s, latency_p99_mean=1.1630529379999999 ms, overhead_mean=35.58749396926411%, bpf_avg_ns_mean=38.98042573335901

## Comparison

- tracee_default: app_delta_mean=-2.2179903646486783%, event_delta_mean=-1.9833947020935416%, overhead_delta_mean=37.05141174046244%, latency_p99_delta_mean=143.49170414070846%, app_p=0.6875, overhead_p=0.6875

