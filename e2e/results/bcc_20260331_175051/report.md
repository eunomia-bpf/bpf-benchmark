# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T18:01:34.415384+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1008` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.012x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=748.34, rejit_ns=736.71, speedup=1.016x, ops_stock=28.56, ops_rejit=28.95, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=50, stock_ns=319.62, rejit_ns=320.56, speedup=0.997x, ops_stock=291708.30, ops_rejit=305017.88, cpu_stock=25.63, cpu_rejit=28.17
- `runqlat` (hackbench): sites=62, stock_ns=158.16, rejit_ns=160.45, speedup=0.986x, ops_stock=62.66, ops_rejit=62.31, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=56.30, rejit_ns=53.13, speedup=1.060x, ops_stock=363393.42, ops_rejit=376335.01, cpu_stock=0.03, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1702.39, rejit_ns=1681.56, speedup=1.012x, ops_stock=606.59, ops_rejit=421.56, cpu_stock=1.10, cpu_rejit=0.97
- `opensnoop` (file_open_storm): sites=129, stock_ns=57.29, rejit_ns=56.47, speedup=1.015x, ops_stock=451705.52, ops_rejit=450020.81, cpu_stock=2.37, cpu_rejit=2.33
- `capable` (exec_storm): sites=55, stock_ns=103.67, rejit_ns=102.27, speedup=1.014x, ops_stock=217.77, ops_rejit=31.87, cpu_stock=1.83, cpu_rejit=1.73
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=25.00, rejit_ns=25.29, speedup=0.988x, ops_stock=52484.54, ops_rejit=52560.09, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=3294.54, rejit_ns=3118.43, speedup=1.056x, ops_stock=22.45, ops_rejit=23.66, cpu_stock=0.07, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=100, stock_ns=476.21, rejit_ns=485.83, speedup=0.980x, ops_stock=327044.80, ops_rejit=326372.61, cpu_stock=39.97, cpu_rejit=39.97

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'syscount', 'execsnoop', 'opensnoop', 'capable', 'tcpconnect']; regressed: ['biosnoop', 'runqlat', 'vfsstat', 'bindsnoop'].
- Geomean speedup: `1.012x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

