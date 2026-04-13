# BCC libbpf-tools E2E Report

- Generated: `2026-04-13T08:37:28.032861+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- Tools dir: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/bcc/libbpf-tools/.output`

## Outcome

- Tools with applied sites: `9`; aggregate applied site count: `961` (map_inline=184, const_prop=304, dce=465, extract=6, endian_fusion=2).
- Geomean BPF speedup across tools with both baseline and ReJIT data: `0.934x`.

## Per-Tool

- `tcplife` (network): sites=39, stock_ns=1142.64, rejit_ns=1268.44, speedup=0.901x, ops_stock=12.02, ops_rejit=11.82, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop` (block_io): sites=23, stock_ns=294.92, rejit_ns=295.28, speedup=0.999x, ops_stock=61718.32, ops_rejit=61691.22, cpu_stock=5.49, cpu_rejit=5.39
- `runqlat` (hackbench): sites=26, stock_ns=144.00, rejit_ns=141.89, speedup=1.015x, ops_stock=17.77, ops_rejit=17.89, cpu_stock=0.00, cpu_rejit=0.00
- `syscount` (file_open_storm): sites=65, stock_ns=74.26, rejit_ns=77.61, speedup=0.957x, ops_stock=1070.34, ops_rejit=1072.35, cpu_stock=0.00, cpu_rejit=0.03
- `execsnoop` (exec_storm): sites=432, stock_ns=1396.29, rejit_ns=1385.77, speedup=1.008x, ops_stock=4763.05, ops_rejit=4802.61, cpu_stock=1.90, cpu_rejit=1.83
- `opensnoop` (file_open_storm): sites=129, stock_ns=696.37, rejit_ns=868.31, speedup=0.802x, ops_stock=1096.20, ops_rejit=1084.23, cpu_stock=1.53, cpu_rejit=1.40
- `capable` (exec_storm): sites=57, stock_ns=108.38, rejit_ns=106.99, speedup=1.013x, ops_stock=4737.06, ops_rejit=4709.02, cpu_stock=15.45, cpu_rejit=15.82
- `vfsstat` (vfs_create_write_fsync): sites=0, stock_ns=28.48, rejit_ns=36.29, speedup=0.785x, ops_stock=77.23, ops_rejit=72.88, cpu_stock=0.00, cpu_rejit=0.00
- `tcpconnect` (network): sites=76, stock_ns=2339.52, rejit_ns=2516.61, speedup=0.930x, ops_stock=10.58, ops_rejit=11.32, cpu_stock=0.03, cpu_rejit=0.00
- `bindsnoop` (bind_storm): sites=114, stock_ns=500.41, rejit_ns=516.37, speedup=0.969x, ops_stock=259764.75, ops_rejit=242668.62, cpu_stock=35.76, cpu_rejit=35.63

## Interpretation

- BCC libbpf-tools are production observability tools with diverse BPF program shapes, exercising the full range of kprobes, tracepoints, and helper calls.
- Tools improved by ReJIT: ['runqlat', 'execsnoop', 'capable']; regressed: ['tcplife', 'biosnoop', 'syscount', 'opensnoop', 'vfsstat', 'tcpconnect', 'bindsnoop'].
- Geomean speedup: `0.934x`.
- Tools with zero applied sites are still measured for baseline overhead but their ReJIT columns remain `n/a`.

