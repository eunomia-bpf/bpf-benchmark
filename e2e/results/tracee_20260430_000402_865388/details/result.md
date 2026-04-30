# Tracee Real End-to-End Benchmark

- Generated: 2026-04-30T00:11:14.810130+00:00
- Mode: `tracee_daemon_same_image_paired`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Cycles: `2`
- Tracee binary: `/artifacts/tracee/bin/tracee`
- Programs: `158`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Baseline

- Status: `ok`
- cycle=0 workload=stress_ng_os throughput=3952.474860581925 ops/s
- cycle=1 workload=stress_ng_os throughput=3830.8991080876403 ops/s

## Post-ReJIT

- Status: `ok`
- cycle=0 workload=stress_ng_os throughput=4361.1273914542935 ops/s
- cycle=1 workload=stress_ng_os throughput=4164.338316020862 ops/s

## ReJIT Result

- cycle=0 applied=True changed=True exit_code=0 requested=158 applied_programs=126 error=
- cycle=1 applied=True changed=True exit_code=0 requested=158 applied_programs=126 error=

