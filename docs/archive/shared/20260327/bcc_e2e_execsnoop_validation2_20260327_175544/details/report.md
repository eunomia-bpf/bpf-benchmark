# BCC libbpf-tools E2E Report

- Generated: `2026-03-27T17:56:30.760645+00:00`
- Run mode: `full`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `1`; aggregate site count: `1750` (map_inline=`67`, const_prop=`185`, dce=`1498`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `n/a`.

## Per-Tool

- `execsnoop` (exec_storm): sites=1750, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
  - Note: Command '['/bin/setpriv', '--reuid', '65534', '--regid', '65534', '--clear-groups', '/bin/stress-ng', '--exec', '2', '--exec-method', 'execve', '--temp-path', '/tmp', '--timeout', '5s', '--metrics-brief']' timed out after 35.0 seconds

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['none']; regressed: ['none'].
- Geomean speedup: `n/a`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

