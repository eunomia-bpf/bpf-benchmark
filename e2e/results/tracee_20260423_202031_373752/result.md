# Tracee Real End-to-End Benchmark

- Generated: 2026-04-23T20:22:03.997008+00:00
- Mode: `error`
- Duration per workload: `20s`
- Warmup per workload: `Nones`
- Paired cycles: `None`
- Latency probes per phase: `None`
- Smoke: `False`
- Tracee binary: `/artifacts/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/artifacts/tracee/bin/tracee`

## Result

- Status: `ERROR`
- Reason: `Tracee case could not run: Tracee latency probe was not detected for workload tracee_default: tokens=['tracee-exec-probe-123733ca0cf14e83bd54675e726b3080'], attempts=[{'attempt': 0, 'marker': 'tracee-exec-probe-8ef77b04a9684ee3aff785c5b17768e7', 'marker_tokens': ['tracee-exec-probe-8ef77b04a9684ee3aff785c5b17768e7']}, {'attempt': 1, 'marker': 'tracee-exec-probe-9a0349e1032345c1b190f019993b24bb', 'marker_tokens': ['tracee-exec-probe-9a0349e1032345c1b190f019993b24bb']}, {'attempt': 2, 'marker': 'tracee-exec-probe-123733ca0cf14e83bd54675e726b3080', 'marker_tokens': ['tracee-exec-probe-123733ca0cf14e83bd54675e726b3080']}]`

## Preflight

- tracee_default: events/s=16277.314412942718, bpf_avg_ns=216.20381391289908, program_runs=10489647


