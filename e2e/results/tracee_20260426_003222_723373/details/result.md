# Tracee Real End-to-End Benchmark

- Generated: 2026-04-26T00:38:02.925338+00:00
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

- cycle=0 workload=tracee_default throughput=859.2968785306114 ops/s
- cycle=1 workload=tracee_default throughput=611.8860610117189 ops/s

## Post-ReJIT

- cycle=0 workload=tracee_default throughput=721.4588390831237 ops/s
- cycle=1 workload=tracee_default throughput=1006.322708934067 ops/s

## ReJIT Result

- cycle=0 applied=True changed=True exit_code=1 requested=158 applied_programs=157 error=prog 113: BPF_PROG_REJIT: Invalid argument (os error 22)
- cycle=1 applied=True changed=True exit_code=1 requested=158 applied_programs=157 error=prog 630: BPF_PROG_REJIT: Invalid argument (os error 22)

