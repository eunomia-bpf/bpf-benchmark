# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T14:57:37.647741+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.998x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=751.06, rejit_ns=871.27, speedup=0.862x, ops_stock=30.10, ops_rejit=29.88, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop` (block_io): sites=50, stock_ns=326.96, rejit_ns=333.81, speedup=0.979x, ops_stock=295845.73, ops_rejit=289935.70, cpu_stock=27.00, cpu_rejit=27.70
- `runqlat` (hackbench): sites=62, stock_ns=159.16, rejit_ns=160.93, speedup=0.989x, ops_stock=64.61, ops_rejit=64.28, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=56.45, rejit_ns=54.22, speedup=1.041x, ops_stock=356582.41, ops_rejit=367831.15, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1705.39, rejit_ns=1728.35, speedup=0.987x, ops_stock=738.17, ops_rejit=462.31, cpu_stock=1.07, cpu_rejit=0.93
- `opensnoop` (file_open_storm): sites=129, stock_ns=55.56, rejit_ns=56.22, speedup=0.988x, ops_stock=450104.70, ops_rejit=449828.49, cpu_stock=2.60, cpu_rejit=2.73
- `capable` (exec_storm): sites=57, stock_ns=105.08, rejit_ns=104.15, speedup=1.009x, ops_stock=180.34, ops_rejit=1021.92, cpu_stock=2.17, cpu_rejit=1.67
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=23.41, rejit_ns=23.88, speedup=0.980x, ops_stock=52692.74, ops_rejit=53178.55, cpu_stock=0.00, cpu_rejit=0.03
- `tcpconnect` (network): sites=76, stock_ns=4039.50, rejit_ns=3507.73, speedup=1.152x, ops_stock=22.43, ops_rejit=22.68, cpu_stock=0.03, cpu_rejit=0.07
- `bindsnoop` (bind_storm): sites=106, stock_ns=483.12, rejit_ns=473.88, speedup=1.019x, ops_stock=327625.94, ops_rejit=330138.44, cpu_stock=40.30, cpu_rejit=40.10

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['syscount', 'capable', 'tcpconnect', 'bindsnoop']; regressed: ['tcplife', 'biosnoop', 'runqlat', 'execsnoop', 'opensnoop', 'vfsstat'].
- Geomean speedup: `0.998x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

