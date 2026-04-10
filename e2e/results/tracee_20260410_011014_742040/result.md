# Tracee Real End-to-End Benchmark

- Generated: 2026-04-10T01:18:36.578008+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `8`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=5799.523735681191, bpf_avg_ns=32.40756378799178, target_runs=1580901

## Control

- tracee_default: app_mean=4928.093594186984 ops/s, app_ci95=[4912.139625626121, 4942.956214580434]

## Baseline

- tracee_default: app_mean=4232.656847765696 ops/s, primary_events_mean=5204.957124034998/s, latency_p99_mean=49.387960696 ms, overhead_mean=14.175047995871578%, bpf_avg_ns_mean=30.225639354497552

## Post-ReJIT

- tracee_default: app_mean=4742.585938188501 ops/s, primary_events_mean=5731.6083382130255/s, latency_p99_mean=49.994016268 ms, overhead_mean=3.7565609196967693%, bpf_avg_ns_mean=30.001314266897612

## Comparison

- tracee_default: app_delta_mean=19.4147772326345%, event_delta_mean=14.47913940881207%, overhead_delta_mean=-132.06145389880032%, latency_p99_delta_mean=1.2306531572439667%, app_p=0.5, overhead_p=0.5

