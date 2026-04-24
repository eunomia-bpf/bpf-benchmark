# bpftrace Real E2E Report

- Generated: `2026-04-23T23:39:37.166276+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `25` (map_inline=1, const_prop=8, dce=3, wide_mem=13).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.050x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=576.97, rejit_ns=561.07, speedup=1.028x, ops_stock=401.57, ops_rejit=407.39, cpu_stock=0.83, cpu_rejit=0.73
- `biosnoop`: sites=5, stock_ns=253.69, rejit_ns=250.64, speedup=1.012x, ops_stock=953501.83, ops_rejit=965220.09, cpu_stock=87.30, cpu_rejit=87.53
- `runqlat`: sites=7, stock_ns=134.49, rejit_ns=134.57, speedup=0.999x, ops_stock=64.65, ops_rejit=63.51, cpu_stock=0.03, cpu_rejit=0.07
- `tcpretrans`: sites=5, stock_ns=11277.49, rejit_ns=10614.99, speedup=1.062x, ops_stock=0.40, ops_rejit=0.40, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=120.24, rejit_ns=120.31, speedup=0.999x, ops_stock=2386.44, ops_rejit=2380.07, cpu_stock=8.13, cpu_rejit=8.10
- `vfsstat`: sites=0, stock_ns=146.40, rejit_ns=120.47, speedup=1.215x, ops_stock=76.07, ops_rejit=77.80, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-2.76%, ops=1.45%, cpu=-12.00%
- `biosnoop` delta: avg_ns=-1.20%, ops=1.23%, cpu=0.27%
- `runqlat` delta: avg_ns=0.05%, ops=-1.76%, cpu=100.00%
- `tcpretrans` delta: avg_ns=-5.87%, ops=0.05%, cpu=100.00%
- `capable` delta: avg_ns=0.06%, ops=-0.27%, cpu=-0.38%
- `vfsstat` delta: avg_ns=-17.71%, ops=2.28%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'tcpretrans', 'vfsstat']; regressed: ['runqlat', 'capable']. The overall geomean across scripts with stock+ReJIT data is `1.050x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

