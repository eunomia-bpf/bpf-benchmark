# bpftrace Real E2E Report

- Generated: `2026-04-24T02:53:40.201021+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `25` (map_inline=1, const_prop=8, dce=3, wide_mem=13).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.001x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=571.10, rejit_ns=626.49, speedup=0.912x, ops_stock=396.51, ops_rejit=374.34, cpu_stock=0.80, cpu_rejit=0.80
- `biosnoop`: sites=5, stock_ns=291.02, rejit_ns=272.26, speedup=1.069x, ops_stock=846380.09, ops_rejit=889983.77, cpu_stock=82.00, cpu_rejit=85.20
- `runqlat`: sites=7, stock_ns=138.66, rejit_ns=138.99, speedup=0.998x, ops_stock=65.83, ops_rejit=65.00, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=10482.73, rejit_ns=9334.84, speedup=1.123x, ops_stock=0.49, ops_rejit=0.49, cpu_stock=0.00, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=125.29, rejit_ns=122.91, speedup=1.019x, ops_stock=2392.27, ops_rejit=2397.84, cpu_stock=8.20, cpu_rejit=7.97
- `vfsstat`: sites=0, stock_ns=139.62, rejit_ns=154.06, speedup=0.906x, ops_stock=66.91, ops_rejit=70.96, cpu_stock=0.00, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=9.70%, ops=-5.59%, cpu=-0.00%
- `biosnoop` delta: avg_ns=-6.44%, ops=5.15%, cpu=3.90%
- `runqlat` delta: avg_ns=0.24%, ops=-1.27%, cpu=n/a%
- `tcpretrans` delta: avg_ns=-10.95%, ops=-0.08%, cpu=n/a%
- `capable` delta: avg_ns=-1.90%, ops=0.23%, cpu=-2.77%
- `vfsstat` delta: avg_ns=10.34%, ops=6.06%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['biosnoop', 'tcpretrans', 'capable']; regressed: ['tcplife', 'runqlat', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.001x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

