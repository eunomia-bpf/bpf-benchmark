# BCC libbpf-tools E2E Report

- Generated: `2026-04-23T12:07:15.592858+00:00`
- Run mode: `smoke`
- Duration per phase: `10s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`

## Outcome

- Tools with applied sites: `1`; aggregate applied site count: `1` (extract=1).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.018x`.

## Per-Tool

- `capable` (exec_storm): sites=1, stock_ns=39.99, rejit_ns=39.28, speedup=1.018x, ops_stock=2449.65, ops_rejit=2447.34, cpu_stock=2.70, cpu_rejit=2.40

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['capable']; regressed: ['none'].
- Geomean speedup: `1.018x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

