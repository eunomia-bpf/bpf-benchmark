# bpftrace Real E2E Report

- Generated: `2026-04-03T20:39:35.002599+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.030x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=605.59, rejit_ns=472.32, speedup=1.282x, ops_stock=19.26, ops_rejit=21.18, cpu_stock=0.00, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=239.93, rejit_ns=202.04, speedup=1.188x, ops_stock=352587.03, ops_rejit=334223.04, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=128.56, rejit_ns=132.32, speedup=0.972x, ops_stock=59.11, ops_rejit=53.31, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=5516.69, rejit_ns=6964.74, speedup=0.792x, ops_stock=2.52, ops_rejit=2.51, cpu_stock=0.00, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=109.33, rejit_ns=108.47, speedup=1.008x, ops_stock=209.11, ops_rejit=1067.62, cpu_stock=0.03, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=32.69, rejit_ns=32.29, speedup=1.012x, ops_stock=53693.20, ops_rejit=53829.33, cpu_stock=0.03, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-22.01%, ops=9.98%, cpu=n/a%
- `biosnoop` delta: avg_ns=-15.79%, ops=-5.21%, cpu=n/a%
- `runqlat` delta: avg_ns=2.93%, ops=-9.82%, cpu=n/a%
- `tcpretrans` delta: avg_ns=26.25%, ops=-0.72%, cpu=n/a%
- `capable` delta: avg_ns=-0.79%, ops=410.55%, cpu=-100.00%
- `vfsstat` delta: avg_ns=-1.21%, ops=0.25%, cpu=-0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'capable', 'vfsstat']; regressed: ['runqlat', 'tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.030x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

