# BCC libbpf-tools E2E Report

- Generated: `2026-04-23T11:02:04.624404+00:00`
- Run mode: `smoke`
- Duration per phase: `10s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`

## Outcome

- Tools with applied sites: `1`; aggregate applied site count: `1` (extract=1).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.999x`.

## Per-Tool

- `capable` (exec_storm): sites=1, stock_ns=43.21, rejit_ns=43.24, speedup=0.999x, ops_stock=2376.48, ops_rejit=2358.82, cpu_stock=2.50, cpu_rejit=2.50

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['none']; regressed: ['capable'].
- Geomean speedup: `0.999x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

