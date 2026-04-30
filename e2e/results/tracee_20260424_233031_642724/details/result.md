# Tracee Real End-to-End Benchmark

- Generated: 2026-04-24T23:36:12.306872+00:00
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

- cycle=0 workload=tracee_default throughput=754.2749527608377 ops/s
- cycle=1 workload=tracee_default throughput=748.4811654210769 ops/s

## Post-ReJIT

- cycle=0 workload=tracee_default throughput=732.4891625059305 ops/s
- cycle=1 workload=tracee_default throughput=1456.9402921232358 ops/s

## ReJIT Result

- cycle=0 applied=True changed=True exit_code=1 requested=158 applied_programs=157 error=prog 113: BPF_PROG_REJIT: Invalid argument (os error 22)
- cycle=1 applied=True changed=True exit_code=1 requested=158 applied_programs=157 error=prog 630: BPF_PROG_REJIT: Invalid argument (os error 22)

