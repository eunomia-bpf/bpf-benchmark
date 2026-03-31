# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T04:19:52.386188+00:00
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

- tracee_default: primary_events/s=33119.740979130554, bpf_avg_ns=104.18108952141255, target_runs=3375684

## Control

- tracee_default: app_mean=169520.75743180813 ops/s, app_ci95=[168276.2365383497, 170667.8187143221]

## Baseline

- tracee_default: app_mean=36757.15440336602 ops/s, primary_events_mean=38130.481843138725/s, latency_p99_mean=47.36245856 ms, overhead_mean=78.31468500531072%, bpf_avg_ns_mean=101.63490447103348

## Post-ReJIT

- tracee_default: app_mean=34872.06853859256 ops/s, primary_events_mean=36247.49055979833/s, latency_p99_mean=47.684995148 ms, overhead_mean=79.42951898662784%, bpf_avg_ns_mean=104.87054742997434

## Comparison

- tracee_default: app_delta_mean=-4.833634255566181%, event_delta_mean=-4.658792502334001%, overhead_delta_mean=1.4488544848771325%, latency_p99_delta_mean=0.7022486775937431%, app_p=0.1875, overhead_p=0.1875

