# bpftrace Real E2E Report

- Generated: `2026-04-03T04:55:39.775240+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.074x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=647.18, rejit_ns=524.75, speedup=1.233x, ops_stock=22.39, ops_rejit=21.82, cpu_stock=0.00, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=243.77, rejit_ns=243.39, speedup=1.002x, ops_stock=299321.86, ops_rejit=332983.20, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=134.49, rejit_ns=132.67, speedup=1.014x, ops_stock=54.83, ops_rejit=55.84, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=5, stock_ns=7275.50, rejit_ns=5787.59, speedup=1.257x, ops_stock=2.46, ops_rejit=2.41, cpu_stock=0.00, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=112.30, rejit_ns=111.98, speedup=1.003x, ops_stock=796.59, ops_rejit=590.37, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.80, rejit_ns=34.69, speedup=0.974x, ops_stock=52444.24, ops_rejit=52038.43, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-18.92%, ops=-2.53%, cpu=n/a%
- `biosnoop` delta: avg_ns=-0.16%, ops=11.25%, cpu=n/a%
- `runqlat` delta: avg_ns=-1.35%, ops=1.84%, cpu=n/a%
- `tcpretrans` delta: avg_ns=-20.45%, ops=-2.02%, cpu=n/a%
- `capable` delta: avg_ns=-0.29%, ops=-25.89%, cpu=n/a%
- `vfsstat` delta: avg_ns=2.64%, ops=-0.77%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'tcpretrans', 'capable']; regressed: ['vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.074x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

