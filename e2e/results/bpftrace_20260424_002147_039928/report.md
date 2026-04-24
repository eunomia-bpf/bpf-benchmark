# bpftrace Real E2E Report

- Generated: `2026-04-24T00:29:25.386336+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `25` (map_inline=1, const_prop=8, dce=3, wide_mem=13).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.025x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=619.80, rejit_ns=689.42, speedup=0.899x, ops_stock=370.57, ops_rejit=333.11, cpu_stock=0.57, cpu_rejit=0.63
- `biosnoop`: sites=5, stock_ns=248.42, rejit_ns=253.16, speedup=0.981x, ops_stock=914799.14, ops_rejit=949562.97, cpu_stock=83.30, cpu_rejit=87.40
- `runqlat`: sites=7, stock_ns=135.64, rejit_ns=136.22, speedup=0.996x, ops_stock=65.05, ops_rejit=63.92, cpu_stock=0.03, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=11531.85, rejit_ns=10346.87, speedup=1.115x, ops_stock=0.40, ops_rejit=0.40, cpu_stock=0.07, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=123.77, rejit_ns=122.28, speedup=1.012x, ops_stock=2357.61, ops_rejit=2366.05, cpu_stock=8.40, cpu_rejit=8.37
- `vfsstat`: sites=0, stock_ns=264.98, rejit_ns=227.07, speedup=1.167x, ops_stock=73.54, ops_rejit=80.69, cpu_stock=0.07, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=11.23%, ops=-10.11%, cpu=11.76%
- `biosnoop` delta: avg_ns=1.91%, ops=3.80%, cpu=4.92%
- `runqlat` delta: avg_ns=0.43%, ops=-1.74%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=-10.28%, ops=0.03%, cpu=-100.00%
- `capable` delta: avg_ns=-1.21%, ops=0.36%, cpu=-0.37%
- `vfsstat` delta: avg_ns=-14.31%, ops=9.73%, cpu=-50.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcpretrans', 'capable', 'vfsstat']; regressed: ['tcplife', 'biosnoop', 'runqlat']. The overall geomean across scripts with stock+ReJIT data is `1.025x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

