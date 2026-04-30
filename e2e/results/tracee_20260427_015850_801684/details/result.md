# Tracee Real End-to-End Benchmark

- Generated: 2026-04-27T02:04:42.173453+00:00
- Mode: `tracee_daemon_same_image_paired`
- Duration per workload: `6s`
- Warmup per workload: `2.0s`
- Cycles: `2`
- Tracee binary: `/artifacts/tracee/bin/tracee`
- Programs: `158`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Result

- Status: `ERROR`
- Reason: `cycle 0: prog 113: BPF_PROG_REJIT: Invalid argument (os error 22); cycle 1: prog 630: BPF_PROG_REJIT: Invalid argument (os error 22)`

## Limitations

- Cycle 0 ReJIT/apply reported errors: prog 113: BPF_PROG_REJIT: Invalid argument (os error 22)
- Cycle 1 ReJIT/apply reported errors: prog 630: BPF_PROG_REJIT: Invalid argument (os error 22)

