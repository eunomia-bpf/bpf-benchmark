# BCC libbpf-tools E2E Report

- Generated: `2026-03-27T17:53:25.033030+00:00`
- Run mode: `full`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `3`; aggregate site count: `2036` (map_inline=`92`, const_prop=`220`, dce=`1718`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.937x`.

## Per-Tool

- `syscount` (file_open): sites=78, stock_ns=68.11, rejit_ns=69.10, speedup=0.986x, ops_stock=5504.04, ops_rejit=5886.72, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=1750, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
  - Note: exec_storm failed: aborting: temp-path '.' must be readable and writeable
- `bindsnoop` (bind_storm): sites=208, stock_ns=205.51, rejit_ns=230.78, speedup=0.890x, ops_stock=423573.58, ops_rejit=413837.38, cpu_stock=6.60, cpu_rejit=8.00

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['none']; regressed: ['syscount', 'bindsnoop'].
- Geomean speedup: `0.937x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

