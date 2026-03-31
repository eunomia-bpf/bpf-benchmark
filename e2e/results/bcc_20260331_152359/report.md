# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T15:34:41.032587+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.980x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=797.78, rejit_ns=772.73, speedup=1.032x, ops_stock=30.08, ops_rejit=30.26, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=50, stock_ns=324.22, rejit_ns=339.93, speedup=0.954x, ops_stock=291118.55, ops_rejit=288511.18, cpu_stock=26.37, cpu_rejit=27.30
- `runqlat` (hackbench): sites=62, stock_ns=154.88, rejit_ns=154.64, speedup=1.002x, ops_stock=64.34, ops_rejit=64.28, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=57.62, rejit_ns=56.12, speedup=1.027x, ops_stock=367585.83, ops_rejit=370221.07, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1702.88, rejit_ns=1721.04, speedup=0.989x, ops_stock=919.04, ops_rejit=674.22, cpu_stock=1.03, cpu_rejit=0.93
- `opensnoop` (file_open_storm): sites=129, stock_ns=56.96, rejit_ns=62.61, speedup=0.910x, ops_stock=444000.41, ops_rejit=443866.57, cpu_stock=2.43, cpu_rejit=2.83
- `capable` (exec_storm): sites=57, stock_ns=99.59, rejit_ns=97.94, speedup=1.017x, ops_stock=404.24, ops_rejit=152.73, cpu_stock=1.83, cpu_rejit=1.63
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.53, rejit_ns=23.93, speedup=1.025x, ops_stock=52970.01, ops_rejit=53857.55, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2081.78, rejit_ns=2283.79, speedup=0.912x, ops_stock=22.04, ops_rejit=22.99, cpu_stock=0.00, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=106, stock_ns=484.92, rejit_ns=512.14, speedup=0.947x, ops_stock=326357.89, ops_rejit=323598.02, cpu_stock=39.77, cpu_rejit=39.57

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'runqlat', 'syscount', 'capable', 'vfsstat']; regressed: ['biosnoop', 'execsnoop', 'opensnoop', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `0.980x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

