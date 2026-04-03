# Tracee Real End-to-End Benchmark

- Generated: 2026-04-03T02:05:18.528730+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `8`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=41497.276549541166, bpf_avg_ns=101.15401696588724, target_runs=3591442

## Control

- tracee_default: app_mean=174362.18721513622 ops/s, app_ci95=[171981.477250494, 176688.87611103692]

## Baseline

- tracee_default: app_mean=36577.497558502684 ops/s, primary_events_mean=37900.78327859796/s, latency_p99_mean=47.003616468 ms, overhead_mean=79.01665362025662%, bpf_avg_ns_mean=101.94876839341279

## Post-ReJIT

- tracee_default: app_mean=36757.862379281294 ops/s, primary_events_mean=38114.873611685565/s, latency_p99_mean=47.651735607999996 ms, overhead_mean=78.91177916628463%, bpf_avg_ns_mean=102.50239891237584

## Comparison

- tracee_default: app_delta_mean=0.7914858750291801%, event_delta_mean=0.8374531176788683%, overhead_delta_mean=-0.11079305245985287%, latency_p99_delta_mean=1.4188302612764654%, app_p=0.9375, overhead_p=0.9375

