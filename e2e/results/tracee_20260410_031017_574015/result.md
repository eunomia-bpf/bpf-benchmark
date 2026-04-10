# Tracee Real End-to-End Benchmark

- Generated: 2026-04-10T03:18:40.743927+00:00
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

- tracee_default: primary_events/s=4944.854854689219, bpf_avg_ns=30.92387480374484, target_runs=963032

## Control

- tracee_default: app_mean=4879.915006129777 ops/s, app_ci95=[4871.673804875141, 4886.412191610355]

## Baseline

- tracee_default: app_mean=3611.2094508557843 ops/s, primary_events_mean=4944.379342967153/s, latency_p99_mean=2.618333618 ms, overhead_mean=26.001782556933808%, bpf_avg_ns_mean=31.27372282272187

## Post-ReJIT

- tracee_default: app_mean=3581.7637999852705 ops/s, primary_events_mean=4930.09849662226/s, latency_p99_mean=2.5758538 ms, overhead_mean=26.60895577148309%, bpf_avg_ns_mean=31.968604902543778

## Comparison

- tracee_default: app_delta_mean=10.408570866007365%, event_delta_mean=5.3287070925940645%, overhead_delta_mean=72.56955197862891%, latency_p99_delta_mean=-1.8472120550179403%, app_p=1.0, overhead_p=1.0

