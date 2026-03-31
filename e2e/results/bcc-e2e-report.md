# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T04:39:43.567995+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.015x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=794.22, rejit_ns=803.37, speedup=0.989x, ops_stock=28.58, ops_rejit=28.92, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=50, stock_ns=339.41, rejit_ns=330.71, speedup=1.026x, ops_stock=292983.35, ops_rejit=293152.52, cpu_stock=28.23, cpu_rejit=27.47
- `runqlat` (hackbench): sites=62, stock_ns=164.98, rejit_ns=164.66, speedup=1.002x, ops_stock=61.12, ops_rejit=62.59, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=57.57, rejit_ns=54.16, speedup=1.063x, ops_stock=357729.74, ops_rejit=368591.11, cpu_stock=0.03, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1771.08, rejit_ns=1762.84, speedup=1.005x, ops_stock=315.08, ops_rejit=1066.97, cpu_stock=1.03, cpu_rejit=0.87
- `opensnoop` (file_open_storm): sites=129, stock_ns=54.85, rejit_ns=54.75, speedup=1.002x, ops_stock=449080.02, ops_rejit=450506.12, cpu_stock=2.83, cpu_rejit=2.70
- `capable` (exec_storm): sites=57, stock_ns=104.80, rejit_ns=104.15, speedup=1.006x, ops_stock=814.95, ops_rejit=565.53, cpu_stock=1.60, cpu_rejit=1.63
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.30, rejit_ns=24.60, speedup=0.987x, ops_stock=51697.09, ops_rejit=52280.79, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2975.52, rejit_ns=2851.64, speedup=1.043x, ops_stock=23.38, ops_rejit=24.63, cpu_stock=0.07, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=106, stock_ns=489.13, rejit_ns=476.11, speedup=1.027x, ops_stock=326534.25, ops_rejit=329940.84, cpu_stock=41.10, cpu_rejit=40.87

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['biosnoop', 'runqlat', 'syscount', 'execsnoop', 'opensnoop', 'capable', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'vfsstat'].
- Geomean speedup: `1.015x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

