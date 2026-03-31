# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T01:19:53.513981+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.011x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=735.50, rejit_ns=696.60, speedup=1.056x, ops_stock=30.13, ops_rejit=30.39, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=50, stock_ns=344.68, rejit_ns=341.77, speedup=1.009x, ops_stock=290041.06, ops_rejit=283603.19, cpu_stock=26.70, cpu_rejit=27.23
- `runqlat` (hackbench): sites=62, stock_ns=156.12, rejit_ns=157.16, speedup=0.993x, ops_stock=66.02, ops_rejit=65.87, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=56.23, rejit_ns=52.86, speedup=1.064x, ops_stock=364110.22, ops_rejit=378011.63, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1707.80, rejit_ns=1691.97, speedup=1.009x, ops_stock=241.07, ops_rejit=37.34, cpu_stock=0.93, cpu_rejit=1.00
- `opensnoop` (file_open_storm): sites=129, stock_ns=55.74, rejit_ns=55.65, speedup=1.002x, ops_stock=452147.21, ops_rejit=455579.13, cpu_stock=2.60, cpu_rejit=2.47
- `capable` (exec_storm): sites=57, stock_ns=102.08, rejit_ns=103.30, speedup=0.988x, ops_stock=906.90, ops_rejit=745.04, cpu_stock=1.70, cpu_rejit=1.67
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.33, rejit_ns=24.91, speedup=0.977x, ops_stock=53562.61, ops_rejit=53661.74, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2609.07, rejit_ns=2583.99, speedup=1.010x, ops_stock=22.88, ops_rejit=22.48, cpu_stock=0.07, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=106, stock_ns=478.17, rejit_ns=477.25, speedup=1.002x, ops_stock=330199.17, ops_rejit=330615.94, cpu_stock=39.73, cpu_rejit=39.63

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'syscount', 'execsnoop', 'opensnoop', 'tcpconnect', 'bindsnoop']; regressed: ['runqlat', 'capable', 'vfsstat'].
- Geomean speedup: `1.011x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

