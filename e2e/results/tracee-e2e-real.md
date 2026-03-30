# Tracee Real End-to-End Benchmark

- Generated: 2026-03-30T21:38:20.400647+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Paired cycles: `2`
- Latency probes per phase: `3`
- Smoke: `True`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Preflight

- tracee_default: primary_events/s=726.6164590141551, bpf_avg_ns=2087.6653219751265, target_runs=146502

## Control

- tracee_default: app_mean=906.3533239949796 ops/s, app_ci95=[881.3728340685004, 931.3338139214588]

## Baseline

- tracee_default: app_mean=344.19700170184115 ops/s, primary_events_mean=665.0419862645832/s, latency_p99_mean=51.74139764 ms, overhead_mean=62.02559179901624%, bpf_avg_ns_mean=2131.2591082132258

## Post-ReJIT

- tracee_default: app_mean=338.7691244964897 ops/s, primary_events_mean=662.6529300035004/s, latency_p99_mean=47.515688420000004 ms, overhead_mean=62.45847837284297%, bpf_avg_ns_mean=2198.8942496665018

## Comparison

- tracee_default: app_delta_mean=-1.1153860190791312%, event_delta_mean=-0.4749324503804928%, overhead_delta_mean=0.7071224936149658%, latency_p99_delta_mean=-7.296953862477329%, app_p=1.0, overhead_p=1.0

