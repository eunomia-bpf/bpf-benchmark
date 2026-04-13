# Tracee Real End-to-End Benchmark

- Generated: 2026-04-13T08:18:50.376732+00:00
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

- tracee_default: primary_events/s=6278.472497720532, bpf_avg_ns=28.193045435750186, target_runs=1557452

## Control

- tracee_default: app_mean=6137.780130812397 ops/s, app_ci95=[4488.227126689691, 8172.924582604759]

## Baseline

- tracee_default: app_mean=4672.78979773537 ops/s, primary_events_mean=5003.172943649069/s, latency_p99_mean=63.83724614 ms, overhead_mean=17.997444754358078%, bpf_avg_ns_mean=36.260402537733924

## Post-ReJIT

- tracee_default: app_mean=4507.186522550641 ops/s, primary_events_mean=4834.133524855713/s, latency_p99_mean=70.50920468599999 ms, overhead_mean=19.061608633774803%, bpf_avg_ns_mean=36.141872052665796

## Comparison

- tracee_default: app_delta_mean=3.276543131314931%, event_delta_mean=2.4678205924389074%, overhead_delta_mean=-51.36984751059917%, latency_p99_delta_mean=9.55043319062877%, app_p=0.625, overhead_p=0.9375

