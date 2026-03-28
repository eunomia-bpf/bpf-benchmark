# BCC libbpf-tools E2E Report

- Generated: `2026-03-28T21:18:27.209096+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `3186` (map_inline=`184`, const_prop=`301`, dce=`2693`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.023x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=52, stock_ns=1046.63, rejit_ns=960.38, speedup=1.090x, ops_stock=27.06, ops_rejit=27.58, cpu_stock=0.07, cpu_rejit=0.07
- `biosnoop` (dd_read): sites=149, stock_ns=4889.89, rejit_ns=4456.98, speedup=1.097x, ops_stock=15395.38, ops_rejit=15408.10, cpu_stock=0.03, cpu_rejit=0.00
- `runqlat` (scheduler): sites=116, stock_ns=238.04, rejit_ns=251.53, speedup=0.946x, ops_stock=57.56, ops_rejit=47.39, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=78, stock_ns=69.40, rejit_ns=70.48, speedup=0.985x, ops_stock=7451.98, ops_rejit=7426.41, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_loop): sites=1759, stock_ns=2436.96, rejit_ns=2169.79, speedup=1.123x, ops_stock=53.66, ops_rejit=54.92, cpu_stock=0.23, cpu_rejit=0.23
- `opensnoop` (file_open): sites=501, stock_ns=821.90, rejit_ns=619.10, speedup=1.328x, ops_stock=7374.77, ops_rejit=7573.37, cpu_stock=0.03, cpu_rejit=0.03
- `capable` (exec_storm): sites=102, stock_ns=255.69, rejit_ns=260.88, speedup=0.980x, ops_stock=323.03, ops_rejit=528.39, cpu_stock=0.30, cpu_rejit=0.30
- `vfsstat` (dd_read): sites=0, stock_ns=23.29, rejit_ns=22.99, speedup=1.013x, ops_stock=12649.33, ops_rejit=12595.46, cpu_stock=0.00, cpu_rejit=0.03
- `tcpconnect` (tcp_connect): sites=221, stock_ns=3456.05, rejit_ns=4180.93, speedup=0.827x, ops_stock=21.16, ops_rejit=22.33, cpu_stock=0.07, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=208, stock_ns=226.53, rejit_ns=246.39, speedup=0.919x, ops_stock=392193.56, ops_rejit=387943.94, cpu_stock=6.83, cpu_rejit=7.97

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'execsnoop', 'opensnoop', 'vfsstat']; regressed: ['runqlat', 'syscount', 'capable', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `1.023x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

