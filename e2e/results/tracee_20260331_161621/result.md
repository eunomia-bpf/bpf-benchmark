# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T16:26:01.611073+00:00
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

- tracee_default: primary_events/s=41325.86489488725, bpf_avg_ns=103.20333550138729, target_runs=3493148

## Control

- tracee_default: app_mean=171970.28803981273 ops/s, app_ci95=[169836.74943954727, 174703.4875087202]

## Baseline

- tracee_default: app_mean=37480.91798820505 ops/s, primary_events_mean=38861.99532201046/s, latency_p99_mean=47.2657196 ms, overhead_mean=78.19606164403294%, bpf_avg_ns_mean=101.58235693013614

## Post-ReJIT

- tracee_default: app_mean=35880.946157511426 ops/s, primary_events_mean=37264.98072251816/s, latency_p99_mean=47.36926976 ms, overhead_mean=79.12712862264763%, bpf_avg_ns_mean=103.51935096648832

## Comparison

- tracee_default: app_delta_mean=-4.264985945024356%, event_delta_mean=-4.107233418623959%, overhead_delta_mean=1.191585327998886%, latency_p99_delta_mean=0.2447104581269815%, app_p=0.0625, overhead_p=0.0625

