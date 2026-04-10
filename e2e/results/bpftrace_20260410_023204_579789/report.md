# bpftrace Real E2E Report

- Generated: `2026-04-10T02:38:32.532354+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.076x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=885.06, rejit_ns=797.14, speedup=1.110x, ops_stock=25.23, ops_rejit=27.33, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=288.17, rejit_ns=267.95, speedup=1.075x, ops_stock=354806.11, ops_rejit=338721.87, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=152.41, rejit_ns=152.32, speedup=1.001x, ops_stock=17.78, ops_rejit=17.12, cpu_stock=0.00, cpu_rejit=0.07
- `tcpretrans`: sites=5, stock_ns=9335.80, rejit_ns=9402.78, speedup=0.993x, ops_stock=1.62, ops_rejit=1.54, cpu_stock=0.07, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=112.90, rejit_ns=113.54, speedup=0.994x, ops_stock=1162.09, ops_rejit=1146.80, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=116.44, rejit_ns=88.54, speedup=1.315x, ops_stock=63.86, ops_rejit=72.65, cpu_stock=0.07, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-9.93%, ops=8.35%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-7.02%, ops=-4.53%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.06%, ops=-3.69%, cpu=n/a%
- `tcpretrans` delta: avg_ns=0.72%, ops=-4.59%, cpu=-50.00%
- `capable` delta: avg_ns=0.56%, ops=-1.32%, cpu=n/a%
- `vfsstat` delta: avg_ns=-23.96%, ops=13.77%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'vfsstat']; regressed: ['tcpretrans', 'capable']. The overall geomean across scripts with stock+ReJIT data is `1.076x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

