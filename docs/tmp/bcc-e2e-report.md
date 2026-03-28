# BCC libbpf-tools E2E Report

- Generated: `2026-03-28T19:09:09.097438+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `3174` (map_inline=`183`, const_prop=`300`, dce=`2683`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.031x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=52, stock_ns=1145.45, rejit_ns=1301.68, speedup=0.880x, ops_stock=25.67, ops_rejit=27.16, cpu_stock=0.07, cpu_rejit=0.07
- `biosnoop` (dd_read): sites=149, stock_ns=9826.25, rejit_ns=10724.56, speedup=0.916x, ops_stock=15153.27, ops_rejit=15158.97, cpu_stock=0.03, cpu_rejit=0.07
- `runqlat` (scheduler): sites=104, stock_ns=219.10, rejit_ns=221.63, speedup=0.989x, ops_stock=63.48, ops_rejit=63.58, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=78, stock_ns=68.51, rejit_ns=66.68, speedup=1.027x, ops_stock=7396.02, ops_rejit=7329.65, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_loop): sites=1759, stock_ns=1564.28, rejit_ns=1406.32, speedup=1.112x, ops_stock=52.22, ops_rejit=55.98, cpu_stock=0.23, cpu_rejit=0.37
- `opensnoop` (file_open): sites=501, stock_ns=835.08, rejit_ns=589.58, speedup=1.416x, ops_stock=7400.88, ops_rejit=7466.69, cpu_stock=0.03, cpu_rejit=0.07
- `capable` (exec_storm): sites=102, stock_ns=265.41, rejit_ns=263.31, speedup=1.008x, ops_stock=85.71, ops_rejit=309.66, cpu_stock=0.20, cpu_rejit=0.33
- `vfsstat` (dd_read): sites=0, stock_ns=22.49, rejit_ns=22.68, speedup=0.992x, ops_stock=13504.78, ops_rejit=14275.57, cpu_stock=0.00, cpu_rejit=0.03
- `tcpconnect` (tcp_connect): sites=221, stock_ns=2891.93, rejit_ns=2626.42, speedup=1.101x, ops_stock=25.95, ops_rejit=22.13, cpu_stock=0.07, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=208, stock_ns=225.32, rejit_ns=236.08, speedup=0.954x, ops_stock=396250.82, ops_rejit=394780.60, cpu_stock=6.77, cpu_rejit=7.30

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['syscount', 'execsnoop', 'opensnoop', 'capable', 'tcpconnect']; regressed: ['tcplife', 'biosnoop', 'runqlat', 'vfsstat', 'bindsnoop'].
- Geomean speedup: `1.031x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

