# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T16:03:50.697613+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1008` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.002x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=809.67, rejit_ns=679.49, speedup=1.192x, ops_stock=29.09, ops_rejit=29.77, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=50, stock_ns=346.49, rejit_ns=338.42, speedup=1.024x, ops_stock=284788.90, ops_rejit=289958.94, cpu_stock=27.27, cpu_rejit=27.13
- `runqlat` (hackbench): sites=62, stock_ns=160.31, rejit_ns=161.24, speedup=0.994x, ops_stock=63.58, ops_rejit=64.69, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=60.16, rejit_ns=61.02, speedup=0.986x, ops_stock=363706.32, ops_rejit=354098.75, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1753.26, rejit_ns=1721.40, speedup=1.019x, ops_stock=443.46, ops_rejit=233.55, cpu_stock=1.10, cpu_rejit=1.03
- `opensnoop` (file_open_storm): sites=129, stock_ns=55.03, rejit_ns=54.99, speedup=1.001x, ops_stock=450000.72, ops_rejit=452143.00, cpu_stock=2.67, cpu_rejit=2.77
- `capable` (exec_storm): sites=55, stock_ns=104.81, rejit_ns=103.67, speedup=1.011x, ops_stock=1080.64, ops_rejit=859.09, cpu_stock=2.23, cpu_rejit=2.07
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=25.59, rejit_ns=25.20, speedup=1.015x, ops_stock=52644.49, ops_rejit=52982.14, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2297.05, rejit_ns=2944.48, speedup=0.780x, ops_stock=22.84, ops_rejit=21.30, cpu_stock=0.07, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=100, stock_ns=494.69, rejit_ns=475.74, speedup=1.040x, ops_stock=327039.37, ops_rejit=330036.41, cpu_stock=39.43, cpu_rejit=39.73

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'execsnoop', 'opensnoop', 'capable', 'vfsstat', 'bindsnoop']; regressed: ['runqlat', 'syscount', 'tcpconnect'].
- Geomean speedup: `1.002x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

