# BCC libbpf-tools E2E Report

- Generated: `2026-04-10T03:38:04.054626+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.031x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=917.36, rejit_ns=858.89, speedup=1.068x, ops_stock=21.96, ops_rejit=23.03, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=23, stock_ns=326.95, rejit_ns=332.87, speedup=0.982x, ops_stock=320738.37, ops_rejit=312860.04, cpu_stock=30.27, cpu_rejit=31.13
- `runqlat` (hackbench): sites=26, stock_ns=186.46, rejit_ns=165.11, speedup=1.129x, ops_stock=17.85, ops_rejit=18.17, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=78.36, rejit_ns=72.69, speedup=1.078x, ops_stock=1033.46, ops_rejit=1031.07, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1823.63, rejit_ns=1813.68, speedup=1.005x, ops_stock=1120.86, ops_rejit=1122.70, cpu_stock=1.00, cpu_rejit=1.00
- `opensnoop` (file_open_storm): sites=129, stock_ns=660.59, rejit_ns=699.36, speedup=0.945x, ops_stock=1064.98, ops_rejit=1045.10, cpu_stock=1.33, cpu_rejit=1.40
- `capable` (exec_storm): sites=57, stock_ns=133.78, rejit_ns=123.80, speedup=1.081x, ops_stock=953.27, ops_rejit=1043.56, cpu_stock=1.93, cpu_rejit=1.60
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=35.34, rejit_ns=36.64, speedup=0.965x, ops_stock=79.08, ops_rejit=70.02, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=3153.17, rejit_ns=2965.10, speedup=1.063x, ops_stock=27.41, ops_rejit=27.69, cpu_stock=0.03, cpu_rejit=0.07
- `bindsnoop` (bind_storm): sites=114, stock_ns=490.72, rejit_ns=485.76, speedup=1.010x, ops_stock=293577.75, ops_rejit=295056.96, cpu_stock=37.00, cpu_rejit=37.03

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'runqlat', 'syscount', 'execsnoop', 'capable', 'tcpconnect', 'bindsnoop']; regressed: ['biosnoop', 'opensnoop', 'vfsstat'].
- Geomean speedup: `1.031x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

