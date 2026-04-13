# BCC libbpf-tools E2E Report

- Generated: `2026-04-13T07:57:17.591550+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.975x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=1290.94, rejit_ns=1218.74, speedup=1.059x, ops_stock=11.10, ops_rejit=11.25, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=23, stock_ns=292.08, rejit_ns=291.09, speedup=1.003x, ops_stock=55294.20, ops_rejit=55537.50, cpu_stock=5.03, cpu_rejit=5.13
- `runqlat` (hackbench): sites=26, stock_ns=147.95, rejit_ns=145.51, speedup=1.017x, ops_stock=16.42, ops_rejit=16.22, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=80.03, rejit_ns=83.15, speedup=0.962x, ops_stock=1296.85, ops_rejit=1304.66, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1421.38, rejit_ns=1514.28, speedup=0.939x, ops_stock=4734.58, ops_rejit=4616.66, cpu_stock=1.80, cpu_rejit=1.90
- `opensnoop` (file_open_storm): sites=129, stock_ns=799.42, rejit_ns=762.33, speedup=1.049x, ops_stock=1317.82, ops_rejit=1312.27, cpu_stock=1.83, cpu_rejit=1.63
- `capable` (exec_storm): sites=57, stock_ns=126.58, rejit_ns=167.84, speedup=0.754x, ops_stock=4046.26, ops_rejit=3120.47, cpu_stock=13.55, cpu_rejit=12.79
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=37.72, rejit_ns=43.56, speedup=0.866x, ops_stock=0.92, ops_rejit=0.25, cpu_stock=0.03, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=3883.57, rejit_ns=3286.99, speedup=1.181x, ops_stock=10.63, ops_rejit=11.27, cpu_stock=0.00, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=114, stock_ns=516.02, rejit_ns=523.45, speedup=0.986x, ops_stock=255401.28, ops_rejit=250644.90, cpu_stock=35.56, cpu_rejit=35.60

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'opensnoop', 'tcpconnect']; regressed: ['syscount', 'execsnoop', 'capable', 'vfsstat', 'bindsnoop'].
- Geomean speedup: `0.975x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

