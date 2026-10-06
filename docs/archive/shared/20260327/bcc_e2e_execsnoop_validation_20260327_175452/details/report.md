# BCC libbpf-tools E2E Report

- Generated: `2026-03-27T17:55:00.429174+00:00`
- Run mode: `full`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `1`; aggregate site count: `1750` (map_inline=`67`, const_prop=`185`, dce=`1498`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `n/a`.

## Per-Tool

- `execsnoop` (exec_storm): sites=1750, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
  - Note: exec_storm failed: aborting: temp-path '/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260327/vm-tmp' must be readable and writeable

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['none']; regressed: ['none'].
- Geomean speedup: `n/a`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

