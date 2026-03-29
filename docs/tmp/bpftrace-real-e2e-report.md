# bpftrace Real E2E Report

- Generated: `2026-03-29T01:53:15.402563+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `22`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.037x`.

## Per-Script

- `tcplife`: sites=8, stock_ns=1392.03, rejit_ns=1462.92, speedup=0.952x, ops_stock=21.07, ops_rejit=12.62, cpu_stock=0.13, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=8226.75, rejit_ns=6990.53, speedup=1.177x, ops_stock=9330.44, ops_rejit=10427.45, cpu_stock=0.07, cpu_rejit=0.03
- `runqlat`: sites=0, stock_ns=197.75, rejit_ns=186.32, speedup=1.061x, ops_stock=55.46, ops_rejit=58.14, cpu_stock=0.07, cpu_rejit=0.00
- `tcpretrans`: sites=3, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=21.52, ops_rejit=24.41, cpu_stock=0.03, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=311.84, rejit_ns=300.57, speedup=1.038x, ops_stock=32.87, ops_rejit=230.01, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=37.09, rejit_ns=38.18, speedup=0.972x, ops_stock=14816.57, ops_rejit=14101.33, cpu_stock=0.03, cpu_rejit=0.07

## Comparison

- `tcplife` delta: avg_ns=5.09%, ops=-40.12%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-15.03%, ops=11.76%, cpu=-50.00%
- `runqlat` delta: avg_ns=-5.78%, ops=4.85%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=n/a%, ops=13.44%, cpu=0.00%
- `capable` delta: avg_ns=-3.61%, ops=599.83%, cpu=n/a%
- `vfsstat` delta: avg_ns=2.93%, ops=-4.83%, cpu=100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['biosnoop', 'runqlat', 'capable'], regressed=['tcplife', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.037x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

