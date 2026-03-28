# BCC libbpf-tools E2E Report

- Generated: `2026-03-28T22:12:19.615920+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `3180` (map_inline=`184`, const_prop=`301`, dce=`2687`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.049x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=52, stock_ns=1215.96, rejit_ns=1079.68, speedup=1.126x, ops_stock=23.73, ops_rejit=22.61, cpu_stock=0.07, cpu_rejit=0.07
- `biosnoop` (dd_read): sites=149, stock_ns=5538.60, rejit_ns=4961.58, speedup=1.116x, ops_stock=13433.90, ops_rejit=13564.83, cpu_stock=0.03, cpu_rejit=0.03
- `runqlat` (scheduler): sites=116, stock_ns=208.20, rejit_ns=200.65, speedup=1.038x, ops_stock=61.00, ops_rejit=61.65, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=78, stock_ns=71.31, rejit_ns=68.88, speedup=1.035x, ops_stock=6801.81, ops_rejit=6374.89, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_loop): sites=1759, stock_ns=2148.58, rejit_ns=2308.47, speedup=0.931x, ops_stock=45.82, ops_rejit=48.44, cpu_stock=0.20, cpu_rejit=0.20
- `opensnoop` (file_open): sites=498, stock_ns=763.59, rejit_ns=730.64, speedup=1.045x, ops_stock=6651.41, ops_rejit=6505.45, cpu_stock=0.00, cpu_rejit=0.03
- `capable` (exec_storm): sites=101, stock_ns=261.20, rejit_ns=234.54, speedup=1.114x, ops_stock=124.47, ops_rejit=375.63, cpu_stock=0.30, cpu_rejit=0.30
- `vfsstat` (dd_read): sites=0, stock_ns=22.76, rejit_ns=22.96, speedup=0.991x, ops_stock=12632.60, ops_rejit=13587.12, cpu_stock=0.03, cpu_rejit=0.03
- `tcpconnect` (tcp_connect): sites=219, stock_ns=3275.68, rejit_ns=2687.51, speedup=1.219x, ops_stock=21.30, ops_rejit=22.38, cpu_stock=0.03, cpu_rejit=0.07
- `bindsnoop` (bind_storm): sites=208, stock_ns=216.86, rejit_ns=236.53, speedup=0.917x, ops_stock=395183.51, ops_rejit=393021.82, cpu_stock=6.60, cpu_rejit=7.67

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'syscount', 'opensnoop', 'capable', 'tcpconnect']; regressed: ['execsnoop', 'vfsstat', 'bindsnoop'].
- Geomean speedup: `1.049x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

