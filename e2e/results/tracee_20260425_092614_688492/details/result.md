# Tracee Real End-to-End Benchmark

- Generated: 2026-04-25T09:31:55.723126+00:00
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

- cycle=0 workload=tracee_default throughput=1689.1961202239868 ops/s
- cycle=1 workload=tracee_default throughput=603.5789109399537 ops/s

## Post-ReJIT

- cycle=0 workload=tracee_default throughput=764.6583940030959 ops/s
- cycle=1 workload=tracee_default throughput=663.1908124185481 ops/s

## ReJIT Result

- cycle=0 applied=True changed=True exit_code=0 requested=157 applied_programs=157 error=
- cycle=1 applied=True changed=True exit_code=0 requested=157 applied_programs=157 error=

