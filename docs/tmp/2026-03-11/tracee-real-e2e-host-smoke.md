# Tracee Real End-to-End Benchmark

- Generated: 2026-03-11T16:40:56.762422+00:00
- Mode: `tracee_daemon`
- Duration per workload: `10s`
- Smoke: `True`
- Tracee binary: `/tmp/tracee-bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/tmp/tracee-bin/tracee`

## Baseline

- exec_storm: app=28665.52427802389 bogo-ops/s, events/s=39168.77697405858, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=60.66843913150348, bpf_avg_ns=46.33731631807887
- file_io: app=14296.534062794684 IOPS, events/s=28017.743551605185, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=49.09687757599018, bpf_avg_ns=36.87701107737035
- network: app=4380.9112847603665 req/s, events/s=5095.459232981798, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=29.59981560208225, bpf_avg_ns=39.18859733990089

## Recompile

- Applied programs: `0` / `15`
- Applied successfully: `False`
- Errors: `['BPF_PROG_JIT_RECOMPILE: Invalid argument']`

## Comparison

- Comparable: `False`
- Reason: `recompile did not apply successfully`

## Limitations

- BPF_PROG_JIT_RECOMPILE did not apply on this kernel; post-ReJIT measurement was skipped.
