# BCC libbpf-tools E2E Report

- Generated: `2026-03-28T14:52:41.601221+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `3165` (map_inline=`183`, const_prop=`300`, dce=`2674`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.983x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=52, stock_ns=1360.82, rejit_ns=1392.38, speedup=0.977x, ops_stock=26.32, ops_rejit=27.02, cpu_stock=0.07, cpu_rejit=0.10
- `biosnoop` (dd_read): sites=149, stock_ns=5705.07, rejit_ns=5721.13, speedup=0.997x, ops_stock=15059.01, ops_rejit=15394.32, cpu_stock=0.00, cpu_rejit=0.07
- `runqlat` (scheduler): sites=104, stock_ns=222.17, rejit_ns=204.42, speedup=1.087x, ops_stock=53.92, ops_rejit=59.57, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=78, stock_ns=68.50, rejit_ns=68.31, speedup=1.003x, ops_stock=7604.24, ops_rejit=7570.73, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_loop): sites=1750, stock_ns=1904.80, rejit_ns=2128.06, speedup=0.895x, ops_stock=55.45, ops_rejit=55.35, cpu_stock=0.23, cpu_rejit=0.27
- `opensnoop` (file_open): sites=501, stock_ns=634.70, rejit_ns=758.61, speedup=0.837x, ops_stock=7537.81, ops_rejit=7621.79, cpu_stock=0.07, cpu_rejit=0.03
- `capable` (exec_storm): sites=102, stock_ns=257.98, rejit_ns=252.10, speedup=1.023x, ops_stock=132.63, ops_rejit=362.32, cpu_stock=0.20, cpu_rejit=0.23
- `vfsstat` (dd_read): sites=0, stock_ns=23.22, rejit_ns=n/a, speedup=n/a, ops_stock=13783.47, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- `tcpconnect` (tcp_connect): sites=221, stock_ns=3190.61, rejit_ns=3021.98, speedup=1.056x, ops_stock=23.88, ops_rejit=22.24, cpu_stock=0.07, cpu_rejit=0.07
- `bindsnoop` (bind_storm): sites=208, stock_ns=221.80, rejit_ns=223.35, speedup=0.993x, ops_stock=389260.18, ops_rejit=394178.80, cpu_stock=6.80, cpu_rejit=6.97

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['runqlat', 'syscount', 'capable', 'tcpconnect']; regressed: ['tcplife', 'biosnoop', 'execsnoop', 'opensnoop', 'bindsnoop'].
- Geomean speedup: `0.983x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

