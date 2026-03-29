# BCC libbpf-tools E2E Report

- Generated: `2026-03-29T02:09:35.482743+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `624` (map_inline=`184`, const_prop=`301`, dce=`131`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.077x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=24, stock_ns=1253.23, rejit_ns=1270.62, speedup=0.986x, ops_stock=26.70, ops_rejit=26.54, cpu_stock=0.03, cpu_rejit=0.13
- `biosnoop` (dd_read): sites=29, stock_ns=5310.20, rejit_ns=6805.31, speedup=0.780x, ops_stock=15212.24, ops_rejit=15115.33, cpu_stock=0.03, cpu_rejit=0.00
- `runqlat` (scheduler): sites=38, stock_ns=226.16, rejit_ns=224.77, speedup=1.006x, ops_stock=63.56, ops_rejit=62.47, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=36, stock_ns=72.63, rejit_ns=71.19, speedup=1.020x, ops_stock=7713.11, ops_rejit=7758.20, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_loop): sites=277, stock_ns=2826.90, rejit_ns=2940.43, speedup=0.961x, ops_stock=54.22, ops_rejit=52.79, cpu_stock=0.27, cpu_rejit=0.30
- `opensnoop` (file_open): sites=72, stock_ns=650.05, rejit_ns=592.45, speedup=1.097x, ops_stock=7587.97, ops_rejit=7702.64, cpu_stock=0.03, cpu_rejit=0.10
- `capable` (exec_storm): sites=30, stock_ns=294.61, rejit_ns=255.78, speedup=1.152x, ops_stock=443.20, ops_rejit=89.66, cpu_stock=0.30, cpu_rejit=0.17
- `vfsstat` (dd_read): sites=0, stock_ns=22.40, rejit_ns=23.21, speedup=0.965x, ops_stock=14033.83, ops_rejit=13869.08, cpu_stock=0.03, cpu_rejit=0.00
- `tcpconnect` (tcp_connect): sites=50, stock_ns=18440.18, rejit_ns=8419.95, speedup=2.190x, ops_stock=7.13, ops_rejit=10.16, cpu_stock=0.10, cpu_rejit=0.07
- `bindsnoop` (bind_storm): sites=68, stock_ns=250.60, rejit_ns=241.14, speedup=1.039x, ops_stock=240604.10, ops_rejit=370069.83, cpu_stock=8.87, cpu_rejit=7.93

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['runqlat', 'syscount', 'opensnoop', 'capable', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'biosnoop', 'execsnoop', 'vfsstat'].
- Geomean speedup: `1.077x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

