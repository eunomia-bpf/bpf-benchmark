# BCC libbpf-tools E2E Report

- Generated: `2026-04-16T05:20:27.064964+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/opt/bpf-benchmark/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.008x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=610.24, rejit_ns=610.84, speedup=0.999x, ops_stock=398.01, ops_rejit=399.56, cpu_stock=0.37, cpu_rejit=0.40
- `biosnoop` (block_io): sites=23, stock_ns=288.83, rejit_ns=291.86, speedup=0.990x, ops_stock=640868.78, ops_rejit=623893.16, cpu_stock=46.23, cpu_rejit=46.73
- `runqlat` (hackbench): sites=26, stock_ns=155.81, rejit_ns=155.59, speedup=1.001x, ops_stock=68.16, ops_rejit=68.04, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=76.32, rejit_ns=76.51, speedup=0.998x, ops_stock=1055.95, ops_rejit=1065.47, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1705.27, rejit_ns=1712.29, speedup=0.996x, ops_stock=2637.83, ops_rejit=2611.95, cpu_stock=0.83, cpu_rejit=0.87
- `opensnoop` (file_open_storm): sites=129, stock_ns=953.50, rejit_ns=758.31, speedup=1.257x, ops_stock=1050.90, ops_rejit=1035.00, cpu_stock=0.93, cpu_rejit=1.03
- `capable` (exec_storm): sites=57, stock_ns=89.51, rejit_ns=90.23, speedup=0.992x, ops_stock=2502.79, ops_rejit=2511.30, cpu_stock=12.06, cpu_rejit=11.63
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=49.64, rejit_ns=55.44, speedup=0.895x, ops_stock=73.62, ops_rejit=70.88, cpu_stock=0.00, cpu_rejit=0.07
- `tcpconnect` (network): sites=76, stock_ns=2210.42, rejit_ns=2225.07, speedup=0.993x, ops_stock=374.43, ops_rejit=380.89, cpu_stock=0.40, cpu_rejit=0.37
- `bindsnoop` (bind_storm): sites=114, stock_ns=476.00, rejit_ns=479.99, speedup=0.992x, ops_stock=288345.09, ops_rejit=288000.98, cpu_stock=34.97, cpu_rejit=34.83

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['runqlat', 'opensnoop']; regressed: ['tcplife', 'biosnoop', 'syscount', 'execsnoop', 'capable', 'vfsstat', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `1.008x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

