# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T03:50:23.656988+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.010x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=940.57, rejit_ns=846.85, speedup=1.111x, ops_stock=24.44, ops_rejit=25.55, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=50, stock_ns=339.03, rejit_ns=332.52, speedup=1.020x, ops_stock=270668.88, ops_rejit=276924.39, cpu_stock=25.93, cpu_rejit=25.90
- `runqlat` (hackbench): sites=62, stock_ns=161.46, rejit_ns=162.97, speedup=0.991x, ops_stock=59.52, ops_rejit=59.76, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=55.18, rejit_ns=55.14, speedup=1.001x, ops_stock=365732.80, ops_rejit=364858.38, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1707.32, rejit_ns=1698.24, speedup=1.005x, ops_stock=602.62, ops_rejit=409.29, cpu_stock=1.07, cpu_rejit=1.00
- `opensnoop` (file_open_storm): sites=129, stock_ns=57.07, rejit_ns=56.37, speedup=1.012x, ops_stock=451103.15, ops_rejit=448718.05, cpu_stock=2.83, cpu_rejit=2.63
- `capable` (exec_storm): sites=57, stock_ns=103.08, rejit_ns=101.46, speedup=1.016x, ops_stock=202.03, ops_rejit=35.36, cpu_stock=2.40, cpu_rejit=1.87
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=25.01, rejit_ns=25.24, speedup=0.991x, ops_stock=52155.46, ops_rejit=52564.54, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=3123.06, rejit_ns=3199.54, speedup=0.976x, ops_stock=23.70, ops_rejit=23.97, cpu_stock=0.03, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=106, stock_ns=482.14, rejit_ns=489.90, speedup=0.984x, ops_stock=329039.84, ops_rejit=329029.09, cpu_stock=40.13, cpu_rejit=39.73

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'syscount', 'execsnoop', 'opensnoop', 'capable']; regressed: ['runqlat', 'vfsstat', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `1.010x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

