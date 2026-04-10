# bpftrace Real E2E Report

- Generated: `2026-04-10T03:26:36.349402+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.881x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=782.40, rejit_ns=668.13, speedup=1.171x, ops_stock=26.99, ops_rejit=27.32, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=279.12, rejit_ns=261.05, speedup=1.069x, ops_stock=335435.51, ops_rejit=343855.91, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=145.96, rejit_ns=157.23, speedup=0.928x, ops_stock=17.74, ops_rejit=19.07, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=5, stock_ns=6371.00, rejit_ns=29319.00, speedup=0.217x, ops_stock=1.78, ops_rejit=1.52, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=357.68, rejit_ns=140.68, speedup=2.543x, ops_stock=177.83, ops_rejit=882.82, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=64.33, rejit_ns=88.45, speedup=0.727x, ops_stock=33.02, ops_rejit=55.39, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-14.61%, ops=1.23%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-6.47%, ops=2.51%, cpu=n/a%
- `runqlat` delta: avg_ns=7.72%, ops=7.52%, cpu=n/a%
- `tcpretrans` delta: avg_ns=360.19%, ops=-14.79%, cpu=100.00%
- `capable` delta: avg_ns=-60.67%, ops=396.45%, cpu=n/a%
- `vfsstat` delta: avg_ns=37.48%, ops=67.75%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'capable']; regressed: ['runqlat', 'tcpretrans', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `0.881x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

