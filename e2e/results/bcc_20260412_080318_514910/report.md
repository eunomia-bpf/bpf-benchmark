# BCC libbpf-tools E2E Report

- Generated: `2026-04-12T08:03:41.832955+00:00`
- Run mode: `smoke`
- Duration per phase: `10s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `1`; aggregate applied site count: `57` (map_inline=11, const_prop=11, dce=33, extract=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.990x`.

## Per-Tool

- `capable` (exec_storm): sites=57, stock_ns=110.39, rejit_ns=111.46, speedup=0.990x, ops_stock=6191.06, ops_rejit=6203.45, cpu_stock=22.07, cpu_rejit=22.08

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['none']; regressed: ['capable'].
- Geomean speedup: `0.990x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

