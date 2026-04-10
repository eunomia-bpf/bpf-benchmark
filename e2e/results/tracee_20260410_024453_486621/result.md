# Tracee Real End-to-End Benchmark

- Generated: 2026-04-10T02:53:19.078447+00:00
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

- tracee_default: primary_events/s=3840.9897184228157, bpf_avg_ns=31.474926159604603, target_runs=877907

## Control

- tracee_default: app_mean=4773.3331676746975 ops/s, app_ci95=[4500.81113335251, 4936.909729286375]

## Baseline

- tracee_default: app_mean=3826.1101497759028 ops/s, primary_events_mean=5084.098667741618/s, latency_p99_mean=3.388286318 ms, overhead_mean=18.602459429201403%, bpf_avg_ns_mean=32.46392688858469

## Post-ReJIT

- tracee_default: app_mean=3800.8253443366207 ops/s, primary_events_mean=5021.258206909816/s, latency_p99_mean=3.436329346 ms, overhead_mean=20.372333588575618%, bpf_avg_ns_mean=32.13676870617718

## Comparison

- tracee_default: app_delta_mean=15.768497014160529%, event_delta_mean=6.17222865263662%, overhead_delta_mean=-122.61340199086243%, latency_p99_delta_mean=7.555568154539634%, app_p=1.0, overhead_p=0.9375

