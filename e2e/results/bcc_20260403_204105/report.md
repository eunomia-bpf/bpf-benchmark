# BCC libbpf-tools E2E Report

- Generated: `2026-04-03T20:51:39.117900+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.012x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=632.44, rejit_ns=574.31, speedup=1.101x, ops_stock=31.33, ops_rejit=31.56, cpu_stock=0.00, cpu_rejit=0.03
- `biosnoop` (block_io): sites=23, stock_ns=309.25, rejit_ns=310.74, speedup=0.995x, ops_stock=309990.43, ops_rejit=317133.19, cpu_stock=24.40, cpu_rejit=26.57
- `runqlat` (hackbench): sites=26, stock_ns=156.79, rejit_ns=156.93, speedup=0.999x, ops_stock=64.69, ops_rejit=67.63, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=53.29, rejit_ns=55.47, speedup=0.961x, ops_stock=378212.95, ops_rejit=374721.63, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1733.44, rejit_ns=1665.84, speedup=1.041x, ops_stock=523.51, ops_rejit=325.03, cpu_stock=1.07, cpu_rejit=1.03
- `opensnoop` (file_open_storm): sites=129, stock_ns=54.81, rejit_ns=54.59, speedup=1.004x, ops_stock=455331.12, ops_rejit=450313.92, cpu_stock=2.20, cpu_rejit=2.17
- `capable` (exec_storm): sites=57, stock_ns=103.93, rejit_ns=104.07, speedup=0.999x, ops_stock=136.14, ops_rejit=1012.81, cpu_stock=1.73, cpu_rejit=1.73
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=23.94, rejit_ns=23.84, speedup=1.004x, ops_stock=53186.83, ops_rejit=53568.46, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=1720.64, rejit_ns=1660.45, speedup=1.036x, ops_stock=22.22, ops_rejit=22.34, cpu_stock=0.03, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=114, stock_ns=490.85, rejit_ns=496.05, speedup=0.990x, ops_stock=297408.18, ops_rejit=296600.38, cpu_stock=36.80, cpu_rejit=36.77

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'execsnoop', 'opensnoop', 'vfsstat', 'tcpconnect']; regressed: ['biosnoop', 'runqlat', 'syscount', 'capable', 'bindsnoop'].
- Geomean speedup: `1.012x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

