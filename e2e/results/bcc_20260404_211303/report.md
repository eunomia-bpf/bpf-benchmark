# BCC libbpf-tools E2E Report

- Generated: `2026-04-04T21:13:39.096154+00:00`
- Run mode: `smoke`
- Duration per phase: `10s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `1`; aggregate applied site count: `57` (map_inline=11, const_prop=11, dce=33, extract=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.026x`.

## Per-Tool

- `capable` (exec_storm): sites=57, stock_ns=105.06, rejit_ns=102.37, speedup=1.026x, ops_stock=119.57, ops_rejit=2073.19, cpu_stock=1.80, cpu_rejit=1.80

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['capable']; regressed: ['none'].
- Geomean speedup: `1.026x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

