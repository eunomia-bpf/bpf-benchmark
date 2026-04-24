# BCC libbpf-tools E2E Report

- Generated: `2026-04-23T19:57:59.144783+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`

## Outcome

- Tools with applied sites: `4`; aggregate applied site count: `14` (const_prop=4, dce=5, extract=3, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.001x`.

## Per-Tool

- `tcplife` (network): sites=0, stock_ns=548.19, rejit_ns=n/a, speedup=n/a, ops_stock=396.54, ops_rejit=n/a, cpu_stock=1.37, cpu_rejit=n/a
- `biosnoop` (block_io): sites=3, stock_ns=149.63, rejit_ns=149.85, speedup=0.999x, ops_stock=891859.38, ops_rejit=909921.51, cpu_stock=73.23, cpu_rejit=73.93
- `runqlat` (hackbench): sites=6, stock_ns=156.80, rejit_ns=156.46, speedup=1.002x, ops_stock=64.23, ops_rejit=63.25, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=0, stock_ns=69.74, rejit_ns=n/a, speedup=n/a, ops_stock=1254.10, ops_rejit=n/a, cpu_stock=0.07, cpu_rejit=n/a
- `execsnoop` (exec_storm): sites=0, stock_ns=2047.55, rejit_ns=n/a, speedup=n/a, ops_stock=2417.70, ops_rejit=n/a, cpu_stock=1.90, cpu_rejit=n/a
- `opensnoop` (open_family_storm): sites=0, stock_ns=1226.27, rejit_ns=n/a, speedup=n/a, ops_stock=1114.63, ops_rejit=n/a, cpu_stock=2.67, cpu_rejit=n/a
- `capable` (exec_storm): sites=1, stock_ns=41.28, rejit_ns=41.11, speedup=1.004x, ops_stock=2420.03, ops_rejit=2412.44, cpu_stock=2.43, cpu_rejit=2.47
- `vfsstat` (vfs_create_fsync_exact): sites=0, stock_ns=59.43, rejit_ns=n/a, speedup=n/a, ops_stock=77.34, ops_rejit=n/a, cpu_stock=0.00, cpu_rejit=n/a
- `tcpconnect` (network): sites=0, stock_ns=2432.01, rejit_ns=n/a, speedup=n/a, ops_stock=372.33, ops_rejit=n/a, cpu_stock=1.13, cpu_rejit=n/a
- `bindsnoop` (bind_storm): sites=4, stock_ns=434.23, rejit_ns=434.49, speedup=0.999x, ops_stock=195714.91, ops_rejit=196253.81, cpu_stock=74.60, cpu_rejit=74.80

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['runqlat', 'capable']; regressed: ['biosnoop', 'bindsnoop'].
- Geomean speedup: `1.001x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

