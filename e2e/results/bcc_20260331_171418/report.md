# BCC libbpf-tools E2E Report

- Generated: `2026-03-31T17:25:01.284225+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/runner/repos/bcc/libbpf-tools`

## Outcome

- Tools with detected sites: `9`; aggregate site count: `1016` (map_inline=`184`, const_prop=`301`, dce=`523`).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.988x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=664.76, rejit_ns=675.56, speedup=0.984x, ops_stock=30.00, ops_rejit=29.64, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop` (block_io): sites=50, stock_ns=312.41, rejit_ns=335.70, speedup=0.931x, ops_stock=306181.55, ops_rejit=284142.22, cpu_stock=27.10, cpu_rejit=27.67
- `runqlat` (hackbench): sites=62, stock_ns=159.10, rejit_ns=161.82, speedup=0.983x, ops_stock=63.83, ops_rejit=62.23, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=56.57, rejit_ns=58.25, speedup=0.971x, ops_stock=353458.51, ops_rejit=355333.13, cpu_stock=0.00, cpu_rejit=0.00
- `execsnoop` (exec_storm): sites=432, stock_ns=1725.43, rejit_ns=1711.67, speedup=1.008x, ops_stock=338.03, ops_rejit=80.43, cpu_stock=1.03, cpu_rejit=0.93
- `opensnoop` (file_open_storm): sites=129, stock_ns=54.24, rejit_ns=53.90, speedup=1.006x, ops_stock=453468.45, ops_rejit=453286.70, cpu_stock=2.60, cpu_rejit=2.70
- `capable` (exec_storm): sites=57, stock_ns=103.71, rejit_ns=101.35, speedup=1.023x, ops_stock=895.78, ops_rejit=649.84, cpu_stock=2.27, cpu_rejit=2.07
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=24.09, rejit_ns=24.25, speedup=0.994x, ops_stock=52661.31, ops_rejit=52407.60, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2288.92, rejit_ns=2334.82, speedup=0.980x, ops_stock=18.18, ops_rejit=22.26, cpu_stock=0.07, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=106, stock_ns=494.50, rejit_ns=493.05, speedup=1.003x, ops_stock=321643.18, ops_rejit=322054.89, cpu_stock=40.13, cpu_rejit=40.23

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['execsnoop', 'opensnoop', 'capable', 'bindsnoop']; regressed: ['tcplife', 'biosnoop', 'runqlat', 'syscount', 'vfsstat', 'tcpconnect'].
- Geomean speedup: `0.988x`.
- Tools with zero eligible sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

