# BCC libbpf-tools E2E Report

- Generated: `2026-03-29T09:03:47.908621+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.015x`.

## Per-Tool

- `tcplife` (tcp_connect): sites=39, stock_ns=1036.89, rejit_ns=1024.20, speedup=1.012x, ops_stock=28.10, ops_rejit=27.76, cpu_stock=0.10, cpu_rejit=0.07
- `biosnoop` (dd_read): sites=50, stock_ns=7087.69, rejit_ns=5491.82, speedup=1.291x, ops_stock=15328.01, ops_rejit=15162.61, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat` (scheduler): sites=62, stock_ns=216.86, rejit_ns=213.41, speedup=1.016x, ops_stock=66.42, ops_rejit=66.68, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open): sites=65, stock_ns=68.12, rejit_ns=68.39, speedup=0.996x, ops_stock=7636.94, ops_rejit=7693.66, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_loop): sites=432, stock_ns=1733.25, rejit_ns=1739.47, speedup=0.996x, ops_stock=57.23, ops_rejit=56.46, cpu_stock=0.17, cpu_rejit=0.17
- `opensnoop` (file_open): sites=129, stock_ns=619.05, rejit_ns=711.88, speedup=0.870x, ops_stock=7514.38, ops_rejit=7619.87, cpu_stock=0.03, cpu_rejit=0.03
- `capable` (exec_storm): sites=57, stock_ns=252.87, rejit_ns=249.65, speedup=1.013x, ops_stock=569.25, ops_rejit=137.89, cpu_stock=0.20, cpu_rejit=0.30
- `vfsstat` (dd_read): sites=0, stock_ns=22.95, rejit_ns=22.78, speedup=1.008x, ops_stock=11978.08, ops_rejit=12567.92, cpu_stock=0.03, cpu_rejit=0.00
- `tcpconnect` (tcp_connect): sites=76, stock_ns=3873.62, rejit_ns=4072.91, speedup=0.951x, ops_stock=22.88, ops_rejit=21.79, cpu_stock=0.07, cpu_rejit=0.07
- `bindsnoop` (bind_storm): sites=106, stock_ns=222.34, rejit_ns=212.30, speedup=1.047x, ops_stock=394154.99, ops_rejit=400315.67, cpu_stock=6.40, cpu_rejit=6.07

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'capable', 'vfsstat', 'bindsnoop']; regressed: ['syscount', 'execsnoop', 'opensnoop', 'tcpconnect'].
- Geomean speedup: `1.015x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

