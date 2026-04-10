# BCC libbpf-tools E2E Report

- Generated: `2026-04-10T01:38:57.813878+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.042x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=1191.96, rejit_ns=1151.51, speedup=1.035x, ops_stock=11.68, ops_rejit=12.37, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=23, stock_ns=325.40, rejit_ns=338.22, speedup=0.962x, ops_stock=215134.93, ops_rejit=205555.57, cpu_stock=20.27, cpu_rejit=21.07
- `runqlat` (hackbench): sites=26, stock_ns=178.80, rejit_ns=159.01, speedup=1.124x, ops_stock=11.98, ops_rejit=11.86, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=77.81, rejit_ns=79.26, speedup=0.982x, ops_stock=1097.73, ops_rejit=1306.60, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1918.30, rejit_ns=1807.21, speedup=1.061x, ops_stock=1047.17, ops_rejit=1120.05, cpu_stock=0.97, cpu_rejit=1.03
- `opensnoop` (file_open_storm): sites=129, stock_ns=700.34, rejit_ns=721.08, speedup=0.971x, ops_stock=1357.45, ops_rejit=1325.12, cpu_stock=1.63, cpu_rejit=1.33
- `capable` (exec_storm): sites=57, stock_ns=125.50, rejit_ns=132.50, speedup=0.947x, ops_stock=1076.16, ops_rejit=1044.76, cpu_stock=1.97, cpu_rejit=1.80
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=62.85, rejit_ns=44.52, speedup=1.412x, ops_stock=76.23, ops_rejit=77.01, cpu_stock=0.03, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=5584.94, rejit_ns=5592.82, speedup=0.999x, ops_stock=13.98, ops_rejit=14.63, cpu_stock=0.07, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=114, stock_ns=501.76, rejit_ns=504.49, speedup=0.995x, ops_stock=285630.33, ops_rejit=287358.78, cpu_stock=36.97, cpu_rejit=36.93

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'runqlat', 'execsnoop', 'vfsstat']; regressed: ['biosnoop', 'syscount', 'opensnoop', 'capable', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `1.042x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

