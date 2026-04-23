# Tracee Real End-to-End Benchmark

- Generated: 2026-04-23T10:59:37.947838+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `3`
- Smoke: `True`
- Tracee binary: `/artifacts/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=15884.778025925021, bpf_avg_ns=73.39525222954475, program_runs=3685730

## Control

- tracee_default: app_mean=6156.8483821497075 ops/s, app_ci95=[6153.239790879735, 6160.45697341968]

## Baseline

- tracee_default: app_mean=6093.42433402972 ops/s, primary_events_mean=16041.248903871998/s, latency_p99_mean=1757.3816697500001 ms, overhead_mean=1.0300671331474767%, bpf_avg_ns_mean=70.02971186156881

## Post-ReJIT

- tracee_default: app_mean=1553.7332655627092 ops/s, primary_events_mean=15650.020179237657/s, latency_p99_mean=1019.2218685800001 ms, overhead_mean=74.75988008282485%, bpf_avg_ns_mean=77.54911895812037

## Comparison

- tracee_default: app_delta_mean=-74.5061576671441%, event_delta_mean=-2.4188186113551957%, overhead_delta_mean=7175.429807228876%, latency_p99_delta_mean=-16.389881879687643%, app_p=0.5, overhead_p=0.5

