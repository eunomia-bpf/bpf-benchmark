# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T16:45:55.970296+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.025x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=881.45, rejit_ns=699.14, speedup=1.261x, ops_stock=30.00, ops_rejit=30.74, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=50, stock_ns=331.78, rejit_ns=327.43, speedup=1.013x, ops_stock=289142.92, ops_rejit=290431.35, cpu_stock=27.07, cpu_rejit=27.03
- `runqlat` (hackbench): sites=62, stock_ns=162.30, rejit_ns=164.07, speedup=0.989x, ops_stock=65.07, ops_rejit=64.59, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=55.77, rejit_ns=52.71, speedup=1.058x, ops_stock=362243.17, ops_rejit=378767.43, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1689.33, rejit_ns=1689.31, speedup=1.000x, ops_stock=253.93, ops_rejit=81.00, cpu_stock=1.10, cpu_rejit=0.97
- `opensnoop` (file_open_storm): sites=129, stock_ns=54.97, rejit_ns=55.14, speedup=0.997x, ops_stock=451554.43, ops_rejit=450142.91, cpu_stock=2.43, cpu_rejit=2.47
- `capable` (exec_storm): sites=57, stock_ns=102.40, rejit_ns=101.87, speedup=1.005x, ops_stock=965.09, ops_rejit=823.56, cpu_stock=1.73, cpu_rejit=1.83
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.18, rejit_ns=23.36, speedup=1.035x, ops_stock=52548.33, ops_rejit=52940.35, cpu_stock=0.00, cpu_rejit=0.03
- `tcpconnect` (network): sites=76, stock_ns=2142.19, rejit_ns=2328.21, speedup=0.920x, ops_stock=22.24, ops_rejit=22.75, cpu_stock=0.03, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=106, stock_ns=476.39, rejit_ns=476.73, speedup=0.999x, ops_stock=333315.47, ops_rejit=333316.05, cpu_stock=39.60, cpu_rejit=39.63

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'syscount', 'execsnoop', 'capable', 'vfsstat']; regressed: ['runqlat', 'opensnoop', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `1.025x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

