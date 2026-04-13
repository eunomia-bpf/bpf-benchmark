# Tracee Real End-to-End Benchmark

- Generated: 2026-04-13T07:37:05.135669+00:00
- Mode: `error`
- Duration per workload: `20s`
- Warmup per workload: `Nones`
- Paired cycles: `None`
- Latency probes per phase: `None`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee`

## Result

- Status: `ERROR`
- Reason: `Tracee case could not run: Command '['/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tracee/bin/tracee', '--events', 'execve,sched_process_exec,security_file_open,security_socket_connect', '--output', 'json:/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260413/vm-tmp/tracee/events.json', '--server', 'healthz', '--server', 'http-address=:3366', '--signatures-dir', '/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260413/vm-tmp/tracee/signatures']' timed out after 3 seconds`

## Preflight

- tracee_default: primary_events/s=6360.419130792505, bpf_avg_ns=28.479705741286175, target_runs=1524101


