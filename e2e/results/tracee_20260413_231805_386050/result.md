# Tracee Real End-to-End Benchmark

- Generated: 2026-04-13T23:27:20.145519+00:00
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

- tracee_default: primary_events/s=3315.408365835961, bpf_avg_ns=65.43559414474517, target_runs=821416

## Control

- tracee_default: app_mean=4604.317883862047 ops/s, app_ci95=[4397.3286414435825, 4786.475235976444]

## Baseline

- tracee_default: app_mean=5959.274302829369 ops/s, primary_events_mean=6264.000445881336/s, latency_p99_mean=80.45927638999999 ms, overhead_mean=-30.730298367085016%, bpf_avg_ns_mean=55.39417920676971

## Post-ReJIT

- tracee_default: app_mean=4531.714546437982 ops/s, primary_events_mean=4837.972410859028/s, latency_p99_mean=65.75842118999999 ms, overhead_mean=1.4882876617476406%, bpf_avg_ns_mean=56.79025529927261

## Comparison

- tracee_default: app_delta_mean=-18.781134256493477%, event_delta_mean=-18.01605987118325%, overhead_delta_mean=-208.39923997387527%, latency_p99_delta_mean=-17.66080258354484%, app_p=0.1875, overhead_p=0.1875

