# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T01:00:07.290599+00:00
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

- tracee_default: primary_events/s=34824.47752746483, bpf_avg_ns=108.79776329706056, target_runs=3099294

## Control

- tracee_default: app_mean=176481.07609761404 ops/s, app_ci95=[173157.84826779473, 181801.94314351553]

## Baseline

- tracee_default: app_mean=37974.39578041771 ops/s, primary_events_mean=39353.998142093595/s, latency_p99_mean=47.104532542 ms, overhead_mean=78.46417870576464%, bpf_avg_ns_mean=102.42086895118423

## Post-ReJIT

- tracee_default: app_mean=35650.38152494974 ops/s, primary_events_mean=37008.733693613634/s, latency_p99_mean=47.379569206 ms, overhead_mean=79.7970920178395%, bpf_avg_ns_mean=104.78131226008702

## Comparison

- tracee_default: app_delta_mean=-6.095322012906029%, event_delta_mean=-5.9364435580804%, overhead_delta_mean=1.7064303769856872%, latency_p99_delta_mean=0.5921197756570775%, app_p=0.0625, overhead_p=0.0625

