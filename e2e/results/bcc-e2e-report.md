# BCC libbpf-tools E2E Report

- Generated: `2026-04-03T05:07:44.071403+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.002x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=695.44, rejit_ns=738.77, speedup=0.941x, ops_stock=30.08, ops_rejit=28.92, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=23, stock_ns=316.05, rejit_ns=308.99, speedup=1.023x, ops_stock=298297.59, ops_rejit=305415.74, cpu_stock=25.17, cpu_rejit=25.37
- `runqlat` (hackbench): sites=26, stock_ns=162.05, rejit_ns=161.68, speedup=1.002x, ops_stock=63.49, ops_rejit=63.56, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=54.33, rejit_ns=53.38, speedup=1.018x, ops_stock=373860.52, ops_rejit=378406.84, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1703.82, rejit_ns=1701.09, speedup=1.002x, ops_stock=815.35, ops_rejit=528.89, cpu_stock=1.07, cpu_rejit=1.07
- `opensnoop` (file_open_storm): sites=129, stock_ns=55.89, rejit_ns=55.91, speedup=1.000x, ops_stock=446855.38, ops_rejit=447496.02, cpu_stock=2.37, cpu_rejit=2.77
- `capable` (exec_storm): sites=57, stock_ns=103.33, rejit_ns=103.37, speedup=1.000x, ops_stock=228.01, ops_rejit=1059.00, cpu_stock=1.63, cpu_rejit=1.73
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.50, rejit_ns=24.53, speedup=0.999x, ops_stock=53513.10, ops_rejit=53766.25, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2436.95, rejit_ns=2358.90, speedup=1.033x, ops_stock=21.79, ops_rejit=23.45, cpu_stock=0.03, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=114, stock_ns=492.69, rejit_ns=488.31, speedup=1.009x, ops_stock=294124.98, ops_rejit=295953.83, cpu_stock=37.13, cpu_rejit=37.20

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['biosnoop', 'runqlat', 'syscount', 'execsnoop', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'opensnoop', 'capable', 'vfsstat'].
- Geomean speedup: `1.002x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

