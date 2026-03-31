# bpftrace Real E2E Report

- Generated: `2026-03-31T17:12:56.987501+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.087x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=734.29, rejit_ns=549.74, speedup=1.336x, ops_stock=21.87, ops_rejit=21.40, cpu_stock=0.00, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=212.57, rejit_ns=230.03, speedup=0.924x, ops_stock=369849.73, ops_rejit=338761.71, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=136.01, rejit_ns=132.43, speedup=1.027x, ops_stock=54.60, ops_rejit=55.45, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=8198.05, rejit_ns=6462.66, speedup=1.269x, ops_stock=2.86, ops_rejit=2.49, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=111.01, rejit_ns=109.41, speedup=1.015x, ops_stock=621.97, ops_rejit=382.07, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.43, rejit_ns=33.05, speedup=1.012x, ops_stock=52635.38, ops_rejit=53855.59, cpu_stock=0.00, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-25.13%, ops=-2.15%, cpu=n/a%
- `biosnoop` delta: avg_ns=8.21%, ops=-8.41%, cpu=n/a%
- `runqlat` delta: avg_ns=-2.63%, ops=1.56%, cpu=n/a%
- `tcpretrans` delta: avg_ns=-21.17%, ops=-12.78%, cpu=100.00%
- `capable` delta: avg_ns=-1.45%, ops=-38.57%, cpu=n/a%
- `vfsstat` delta: avg_ns=-1.16%, ops=2.32%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'tcpretrans', 'capable', 'vfsstat'], regressed=['biosnoop']. The overall geomean across scripts with stock+ReJIT data is `1.087x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

