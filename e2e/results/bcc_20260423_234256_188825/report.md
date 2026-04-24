# BCC libbpf-tools E2E Report

- Generated: `2026-04-23T23:54:10.986855+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- Tools dir: `/usr/sbin`

## Outcome

- Tools with applied sites: `4`; aggregate applied site count: `14` (const_prop=4, dce=5, extract=3, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.076x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=0, stock_ns=541.74, rejit_ns=558.25, speedup=0.970x, ops_stock=391.92, ops_rejit=372.07, cpu_stock=1.37, cpu_rejit=1.33
- `biosnoop` (block_io): sites=3, stock_ns=148.35, rejit_ns=148.09, speedup=1.002x, ops_stock=933863.67, ops_rejit=934329.41, cpu_stock=75.57, cpu_rejit=76.17
- `runqlat` (scheduler): sites=6, stock_ns=157.55, rejit_ns=157.30, speedup=1.002x, ops_stock=64.46, ops_rejit=63.75, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=0, stock_ns=101.08, rejit_ns=98.31, speedup=1.028x, ops_stock=1147.35, ops_rejit=1100.33, cpu_stock=0.03, cpu_rejit=0.03
- `execsnoop` (exec_loop): sites=0, stock_ns=1129.88, rejit_ns=1162.97, speedup=0.972x, ops_stock=1603.88, ops_rejit=1555.30, cpu_stock=3.83, cpu_rejit=3.60
- `opensnoop` (file_open): sites=0, stock_ns=1939.10, rejit_ns=1477.55, speedup=1.312x, ops_stock=1103.69, ops_rejit=1130.02, cpu_stock=2.00, cpu_rejit=2.30
- `capable` (exec_storm): sites=1, stock_ns=40.48, rejit_ns=46.00, speedup=0.880x, ops_stock=2400.58, ops_rejit=1967.69, cpu_stock=2.40, cpu_rejit=3.30
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=500.80, rejit_ns=417.61, speedup=1.199x, ops_stock=51.67, ops_rejit=31.48, cpu_stock=0.03, cpu_rejit=0.03
- `tcpconnect` (tcp_connect): sites=0, stock_ns=17132.58, rejit_ns=11196.00, speedup=1.530x, ops_stock=192.52, ops_rejit=206.42, cpu_stock=2.40, cpu_rejit=2.40
- `bindsnoop` (bind_storm): sites=4, stock_ns=452.19, rejit_ns=448.37, speedup=1.009x, ops_stock=162301.92, ops_rejit=173262.32, cpu_stock=76.07, cpu_rejit=74.60

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['biosnoop', 'runqlat', 'syscount', 'opensnoop', 'vfsstat', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'execsnoop', 'capable'].
- Geomean speedup: `1.076x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

