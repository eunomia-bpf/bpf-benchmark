# BCC libbpf-tools E2E Report

- Generated: `2026-04-16T03:03:58.046886+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/opt/bpf-benchmark/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.006x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=623.35, rejit_ns=655.49, speedup=0.951x, ops_stock=387.03, ops_rejit=361.77, cpu_stock=0.33, cpu_rejit=0.37
- `biosnoop` (block_io): sites=23, stock_ns=286.19, rejit_ns=288.86, speedup=0.991x, ops_stock=653991.11, ops_rejit=618941.69, cpu_stock=47.07, cpu_rejit=45.83
- `runqlat` (hackbench): sites=26, stock_ns=154.93, rejit_ns=155.74, speedup=0.995x, ops_stock=69.09, ops_rejit=67.97, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=77.75, rejit_ns=76.03, speedup=1.023x, ops_stock=1132.71, ops_rejit=1149.75, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1696.04, rejit_ns=1687.45, speedup=1.005x, ops_stock=2633.84, ops_rejit=2642.46, cpu_stock=0.83, cpu_rejit=0.87
- `opensnoop` (file_open_storm): sites=129, stock_ns=1167.37, rejit_ns=936.03, speedup=1.247x, ops_stock=1066.13, ops_rejit=1109.08, cpu_stock=0.83, cpu_rejit=0.97
- `capable` (exec_storm): sites=57, stock_ns=92.35, rejit_ns=92.89, speedup=0.994x, ops_stock=2510.63, ops_rejit=2519.59, cpu_stock=12.17, cpu_rejit=12.23
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=52.33, rejit_ns=60.07, speedup=0.871x, ops_stock=69.22, ops_rejit=69.11, cpu_stock=0.00, cpu_rejit=0.03
- `tcpconnect` (network): sites=76, stock_ns=2084.13, rejit_ns=2054.07, speedup=1.015x, ops_stock=385.39, ops_rejit=422.11, cpu_stock=0.40, cpu_rejit=0.43
- `bindsnoop` (bind_storm): sites=114, stock_ns=499.83, rejit_ns=497.73, speedup=1.004x, ops_stock=286698.86, ops_rejit=287189.90, cpu_stock=35.30, cpu_rejit=35.27

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['syscount', 'execsnoop', 'opensnoop', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'biosnoop', 'runqlat', 'capable', 'vfsstat'].
- Geomean speedup: `1.006x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

