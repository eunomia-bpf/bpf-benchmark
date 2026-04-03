# BCC libbpf-tools E2E Report

- Generated: `2026-04-03T02:25:22.256527+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `643` (map_inline=`184`, const_prop=`116`, dce=`343`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `1.005x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=737.95, rejit_ns=748.08, speedup=0.986x, ops_stock=30.32, ops_rejit=29.97, cpu_stock=0.00, cpu_rejit=0.03
- `biosnoop` (block_io): sites=50, stock_ns=319.01, rejit_ns=312.68, speedup=1.020x, ops_stock=314570.19, ops_rejit=308054.77, cpu_stock=27.30, cpu_rejit=27.13
- `runqlat` (hackbench): sites=62, stock_ns=156.39, rejit_ns=157.81, speedup=0.991x, ops_stock=65.79, ops_rejit=65.58, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=54.68, rejit_ns=54.27, speedup=1.007x, ops_stock=372626.14, ops_rejit=374225.07, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=67, stock_ns=1716.56, rejit_ns=1728.90, speedup=0.993x, ops_stock=362.76, ops_rejit=109.86, cpu_stock=1.03, cpu_rejit=0.90
- `opensnoop` (file_open_storm): sites=129, stock_ns=54.92, rejit_ns=57.03, speedup=0.963x, ops_stock=448849.84, ops_rejit=449196.95, cpu_stock=2.53, cpu_rejit=2.50
- `capable` (exec_storm): sites=55, stock_ns=103.01, rejit_ns=101.33, speedup=1.017x, ops_stock=929.48, ops_rejit=673.30, cpu_stock=1.97, cpu_rejit=1.57
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.27, rejit_ns=24.43, speedup=0.993x, ops_stock=52630.18, ops_rejit=52914.76, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=3110.34, rejit_ns=2829.96, speedup=1.099x, ops_stock=23.14, ops_rejit=23.73, cpu_stock=0.03, cpu_rejit=0.03
- `bindsnoop` (bind_storm): sites=100, stock_ns=482.47, rejit_ns=487.17, speedup=0.990x, ops_stock=295201.24, ops_rejit=294830.55, cpu_stock=37.00, cpu_rejit=37.07

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['biosnoop', 'syscount', 'capable', 'tcpconnect']; regressed: ['tcplife', 'runqlat', 'execsnoop', 'opensnoop', 'vfsstat', 'bindsnoop'].
- Geomean speedup: `1.005x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

