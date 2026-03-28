# bpftrace Real E2E Report

- Generated: `2026-03-28T21:58:07.837079+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `21`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.035x`.

## Per-Script

- `tcplife`: sites=8, stock_ns=1087.03, rejit_ns=921.53, speedup=1.180x, ops_stock=21.81, ops_rejit=22.00, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop`: sites=4, stock_ns=4116.73, rejit_ns=4207.60, speedup=0.978x, ops_stock=13515.18, ops_rejit=13668.94, cpu_stock=0.03, cpu_rejit=0.00
- `runqlat`: sites=0, stock_ns=187.90, rejit_ns=187.99, speedup=1.000x, ops_stock=61.12, ops_rejit=61.49, cpu_stock=0.07, cpu_rejit=0.00
- `tcpretrans`: sites=3, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=21.48, ops_rejit=21.86, cpu_stock=0.03, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=253.78, rejit_ns=246.98, speedup=1.028x, ops_stock=121.77, ops_rejit=377.18, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=37.03, rejit_ns=36.87, speedup=1.004x, ops_stock=13079.11, ops_rejit=12696.76, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-15.23%, ops=0.85%, cpu=-100.00%
- `biosnoop` delta: avg_ns=2.21%, ops=1.14%, cpu=-100.00%
- `runqlat` delta: avg_ns=0.05%, ops=0.60%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=n/a%, ops=1.77%, cpu=-100.00%
- `capable` delta: avg_ns=-2.68%, ops=209.74%, cpu=n/a%
- `vfsstat` delta: avg_ns=-0.43%, ops=-2.92%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'capable', 'vfsstat'], regressed=['biosnoop', 'runqlat']. The overall geomean across scripts with stock+ReJIT data is `1.035x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

