# BCC libbpf-tools E2E Report

- Generated: `2026-04-09T07:45:16.923322+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `953` (map_inline=184, const_prop=304, dce=465).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.992x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=730.10, rejit_ns=758.71, speedup=0.962x, ops_stock=20.52, ops_rejit=20.48, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=23, stock_ns=307.97, rejit_ns=315.98, speedup=0.975x, ops_stock=286032.54, ops_rejit=260846.67, cpu_stock=22.43, cpu_rejit=22.83
- `runqlat` (hackbench): sites=26, stock_ns=151.17, rejit_ns=157.63, speedup=0.959x, ops_stock=56.64, ops_rejit=51.08, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=55.59, rejit_ns=55.13, speedup=1.008x, ops_stock=364284.57, ops_rejit=362956.22, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1707.79, rejit_ns=1705.51, speedup=1.001x, ops_stock=1259.74, ops_rejit=1251.37, cpu_stock=1.00, cpu_rejit=0.90
- `opensnoop` (file_open_storm): sites=129, stock_ns=54.58, rejit_ns=53.53, speedup=1.020x, ops_stock=444567.25, ops_rejit=458571.75, cpu_stock=2.50, cpu_rejit=2.30
- `capable` (exec_storm): sites=55, stock_ns=102.02, rejit_ns=101.43, speedup=1.006x, ops_stock=1279.96, ops_rejit=1291.38, cpu_stock=2.13, cpu_rejit=2.33
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.53, rejit_ns=24.11, speedup=1.018x, ops_stock=53237.22, ops_rejit=53649.47, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=1829.44, rejit_ns=1952.87, speedup=0.937x, ops_stock=15.89, ops_rejit=15.21, cpu_stock=0.00, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=108, stock_ns=505.57, rejit_ns=484.89, speedup=1.043x, ops_stock=294335.18, ops_rejit=296651.31, cpu_stock=37.00, cpu_rejit=36.93

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['syscount', 'execsnoop', 'opensnoop', 'capable', 'vfsstat', 'bindsnoop']; regressed: ['tcplife', 'biosnoop', 'runqlat', 'tcpconnect'].
- Geomean speedup: `0.992x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

