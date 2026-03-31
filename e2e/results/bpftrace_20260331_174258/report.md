# bpftrace Real E2E Report

- Generated: `2026-03-31T17:49:29.774918+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.129x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=729.38, rejit_ns=481.13, speedup=1.516x, ops_stock=20.88, ops_rejit=22.17, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=251.42, rejit_ns=241.98, speedup=1.039x, ops_stock=360141.00, ops_rejit=385984.99, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=133.96, rejit_ns=132.75, speedup=1.009x, ops_stock=57.24, ops_rejit=54.88, cpu_stock=0.07, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=8140.97, rejit_ns=6313.02, speedup=1.290x, ops_stock=2.70, ops_rejit=2.16, cpu_stock=0.03, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=108.98, rejit_ns=108.78, speedup=1.002x, ops_stock=154.78, ops_rejit=945.05, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.83, rejit_ns=33.50, speedup=1.010x, ops_stock=52649.97, ops_rejit=53217.56, cpu_stock=0.03, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-34.04%, ops=6.18%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-3.76%, ops=7.18%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.90%, ops=-4.13%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=-22.45%, ops=-20.03%, cpu=0.00%
- `capable` delta: avg_ns=-0.18%, ops=510.57%, cpu=n/a%
- `vfsstat` delta: avg_ns=-0.97%, ops=1.08%, cpu=0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'biosnoop', 'runqlat', 'tcpretrans', 'capable', 'vfsstat'], regressed=['none']. The overall geomean across scripts with stock+ReJIT data is `1.129x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

