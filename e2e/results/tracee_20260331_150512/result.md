# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T15:14:50.750895+00:00
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

- tracee_default: primary_events/s=38657.99211157674, bpf_avg_ns=107.59253794272972, target_runs=3227957

## Control

- tracee_default: app_mean=171383.42640328876 ops/s, app_ci95=[170497.33368832193, 172442.9798016621]

## Baseline

- tracee_default: app_mean=36762.43908359723 ops/s, primary_events_mean=38101.52375851295/s, latency_p99_mean=47.188200578 ms, overhead_mean=78.5499269426794%, bpf_avg_ns_mean=103.17616890038244

## Post-ReJIT

- tracee_default: app_mean=35653.478740808 ops/s, primary_events_mean=36996.71268632491/s, latency_p99_mean=47.167389722 ms, overhead_mean=79.19713453383999%, bpf_avg_ns_mean=105.2410704999366

## Comparison

- tracee_default: app_delta_mean=-2.9529999994984975%, event_delta_mean=-2.8383991208239467%, overhead_delta_mean=0.8289774447314834%, latency_p99_delta_mean=0.06964445241641826%, app_p=0.125, overhead_p=0.125

