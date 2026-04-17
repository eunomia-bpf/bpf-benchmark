# BCC libbpf-tools E2E Report

- Generated: `2026-04-16T04:08:08.491421+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/opt/bpf-benchmark/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.011x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=530.40, rejit_ns=540.53, speedup=0.981x, ops_stock=453.46, ops_rejit=452.83, cpu_stock=0.40, cpu_rejit=0.33
- `biosnoop` (block_io): sites=23, stock_ns=280.00, rejit_ns=278.92, speedup=1.004x, ops_stock=724057.54, ops_rejit=706203.84, cpu_stock=51.07, cpu_rejit=50.80
- `runqlat` (hackbench): sites=26, stock_ns=149.88, rejit_ns=149.37, speedup=1.003x, ops_stock=70.70, ops_rejit=69.35, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=72.28, rejit_ns=70.38, speedup=1.027x, ops_stock=1094.57, ops_rejit=1043.99, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1681.54, rejit_ns=1711.74, speedup=0.982x, ops_stock=2640.81, ops_rejit=2647.97, cpu_stock=0.80, cpu_rejit=0.87
- `opensnoop` (file_open_storm): sites=129, stock_ns=992.80, rejit_ns=609.19, speedup=1.630x, ops_stock=1014.43, ops_rejit=1128.06, cpu_stock=0.90, cpu_rejit=0.97
- `capable` (exec_storm): sites=57, stock_ns=91.85, rejit_ns=92.57, speedup=0.992x, ops_stock=2529.12, ops_rejit=2507.90, cpu_stock=11.86, cpu_rejit=11.57
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=34.79, rejit_ns=47.08, speedup=0.739x, ops_stock=78.40, ops_rejit=64.25, cpu_stock=0.00, cpu_rejit=0.03
- `tcpconnect` (network): sites=76, stock_ns=2039.86, rejit_ns=2162.64, speedup=0.943x, ops_stock=389.38, ops_rejit=390.26, cpu_stock=0.43, cpu_rejit=0.30
- `bindsnoop` (bind_storm): sites=114, stock_ns=476.75, rejit_ns=479.34, speedup=0.995x, ops_stock=292792.32, ops_rejit=292824.02, cpu_stock=35.80, cpu_rejit=35.60

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['biosnoop', 'runqlat', 'syscount', 'opensnoop']; regressed: ['tcplife', 'execsnoop', 'capable', 'vfsstat', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `1.011x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

