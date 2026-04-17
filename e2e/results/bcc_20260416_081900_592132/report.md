# BCC libbpf-tools E2E Report

- Generated: `2026-04-16T08:29:28.263609+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/opt/bpf-benchmark/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.012x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=2247.26, rejit_ns=2230.10, speedup=1.008x, ops_stock=139.88, ops_rejit=139.76, cpu_stock=0.47, cpu_rejit=0.50
- `biosnoop` (block_io): sites=23, stock_ns=876.83, rejit_ns=844.60, speedup=1.038x, ops_stock=150383.88, ops_rejit=154585.14, cpu_stock=49.77, cpu_rejit=51.93
- `runqlat` (hackbench): sites=26, stock_ns=491.71, rejit_ns=502.32, speedup=0.979x, ops_stock=14.80, ops_rejit=14.82, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=131.40, rejit_ns=122.34, speedup=1.074x, ops_stock=94522.42, ops_rejit=96305.81, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=7363.44, rejit_ns=7096.76, speedup=1.038x, ops_stock=324.09, ops_rejit=333.91, cpu_stock=0.77, cpu_rejit=0.77
- `opensnoop` (file_open_storm): sites=129, stock_ns=2333.50, rejit_ns=2235.14, speedup=1.044x, ops_stock=40521.40, ops_rejit=41191.67, cpu_stock=50.37, cpu_rejit=50.30
- `capable` (exec_storm): sites=57, stock_ns=314.92, rejit_ns=321.66, speedup=0.979x, ops_stock=315.47, ops_rejit=314.01, cpu_stock=7.26, cpu_rejit=7.43
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=105.66, rejit_ns=108.87, speedup=0.971x, ops_stock=356.32, ops_rejit=360.45, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=9942.93, rejit_ns=9894.86, speedup=1.005x, ops_stock=143.33, ops_rejit=143.01, cpu_stock=0.47, cpu_rejit=0.50
- `bindsnoop` (bind_storm): sites=114, stock_ns=2673.92, rejit_ns=2689.25, speedup=0.994x, ops_stock=39937.97, ops_rejit=39384.65, cpu_stock=28.07, cpu_rejit=27.73

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'syscount', 'execsnoop', 'opensnoop', 'tcpconnect']; regressed: ['runqlat', 'capable', 'vfsstat', 'bindsnoop'].
- Geomean speedup: `1.012x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

