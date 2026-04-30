# Tracee Real End-to-End Benchmark

- Generated: 2026-04-25T08:29:59.920608+00:00
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

- cycle=0 workload=tracee_default throughput=919.6760765649599 ops/s
- cycle=1 workload=tracee_default throughput=604.6319035283035 ops/s

## Post-ReJIT

- cycle=0 workload=tracee_default throughput=1262.1802294127751 ops/s
- cycle=1 workload=tracee_default throughput=592.1768421615105 ops/s

## ReJIT Result

- cycle=0 applied=True changed=True exit_code=1 requested=158 applied_programs=157 error=prog 113: BPF_PROG_REJIT: Invalid argument (os error 22)
- cycle=1 applied=True changed=True exit_code=1 requested=158 applied_programs=157 error=prog 630: BPF_PROG_REJIT: Invalid argument (os error 22)

