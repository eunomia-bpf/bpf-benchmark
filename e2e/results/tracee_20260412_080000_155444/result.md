# Tracee Real End-to-End Benchmark

- Generated: 2026-04-12T08:01:42.277645+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `3`
- Smoke: `True`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=6381.379085979312, bpf_avg_ns=60.74714717749673, target_runs=1563364

## Control

- tracee_default: app_mean=11618.701067371761 ops/s, app_ci95=[5297.78986284366, 17939.612271899863]

## Baseline

- tracee_default: app_mean=2675.364930597799 ops/s, primary_events_mean=2922.079640191935/s, latency_p99_mean=72.99881333 ms, overhead_mean=65.65372151289066%, bpf_avg_ns_mean=46.842747670711574

## Post-ReJIT

- tracee_default: app_mean=5403.605602333042 ops/s, primary_events_mean=5634.689688074737/s, latency_p99_mean=50.3431252 ms, overhead_mean=21.318282089049717%, bpf_avg_ns_mean=43.54852428509868

## Comparison

- tracee_default: app_delta_mean=97.11265247858354%, event_delta_mean=88.57987569448147%, overhead_delta_mean=-95.63977311418061%, latency_p99_delta_mean=-29.47329615183543%, app_p=0.5, overhead_p=0.5

