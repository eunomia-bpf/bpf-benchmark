# BCC libbpf-tools E2E Report

- Generated: `2026-04-13T23:47:06.957143+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.012x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=1149.91, rejit_ns=1175.75, speedup=0.978x, ops_stock=12.08, ops_rejit=12.03, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=23, stock_ns=288.51, rejit_ns=285.37, speedup=1.011x, ops_stock=62297.90, ops_rejit=62613.41, cpu_stock=5.03, cpu_rejit=5.23
- `runqlat` (hackbench): sites=26, stock_ns=136.47, rejit_ns=136.58, speedup=0.999x, ops_stock=18.09, ops_rejit=18.07, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=75.11, rejit_ns=75.05, speedup=1.001x, ops_stock=1083.06, ops_rejit=1091.43, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1417.06, rejit_ns=1436.67, speedup=0.986x, ops_stock=4803.24, ops_rejit=4801.19, cpu_stock=1.83, cpu_rejit=1.83
- `opensnoop` (file_open_storm): sites=129, stock_ns=797.58, rejit_ns=739.11, speedup=1.079x, ops_stock=1083.46, ops_rejit=1074.68, cpu_stock=1.37, cpu_rejit=1.10
- `capable` (exec_storm): sites=57, stock_ns=107.22, rejit_ns=108.55, speedup=0.988x, ops_stock=4680.48, ops_rejit=4678.85, cpu_stock=16.18, cpu_rejit=16.12
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=34.29, rejit_ns=34.64, speedup=0.990x, ops_stock=76.33, ops_rejit=72.80, cpu_stock=0.03, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=3224.51, rejit_ns=2971.34, speedup=1.085x, ops_stock=11.21, ops_rejit=11.40, cpu_stock=0.00, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=114, stock_ns=505.48, rejit_ns=501.88, speedup=1.007x, ops_stock=259141.33, ops_rejit=259986.80, cpu_stock=36.00, cpu_rejit=35.96

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['biosnoop', 'syscount', 'opensnoop', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'runqlat', 'execsnoop', 'capable', 'vfsstat'].
- Geomean speedup: `1.012x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

