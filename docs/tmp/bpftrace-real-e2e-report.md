# bpftrace Real E2E Report

- Generated: `2026-03-28T21:02:27.973219+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `21`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.057x`.

## Per-Script

- `tcplife`: sites=8, stock_ns=937.30, rejit_ns=761.20, speedup=1.231x, ops_stock=20.42, ops_rejit=21.09, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop`: sites=4, stock_ns=3944.31, rejit_ns=3971.93, speedup=0.993x, ops_stock=12315.76, ops_rejit=14375.33, cpu_stock=0.07, cpu_rejit=0.00
- `runqlat`: sites=0, stock_ns=192.89, rejit_ns=186.76, speedup=1.033x, ops_stock=60.87, ops_rejit=61.92, cpu_stock=0.03, cpu_rejit=0.03
- `tcpretrans`: sites=3, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=22.29, ops_rejit=20.65, cpu_stock=0.00, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=249.66, rejit_ns=246.72, speedup=1.012x, ops_stock=378.71, ops_rejit=630.14, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=36.22, rejit_ns=35.03, speedup=1.034x, ops_stock=13605.24, ops_rejit=13783.43, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-18.79%, ops=3.24%, cpu=-100.00%
- `biosnoop` delta: avg_ns=0.70%, ops=16.72%, cpu=-100.00%
- `runqlat` delta: avg_ns=-3.18%, ops=1.73%, cpu=0.00%
- `tcpretrans` delta: avg_ns=n/a%, ops=-7.36%, cpu=n/a%
- `capable` delta: avg_ns=-1.18%, ops=66.39%, cpu=n/a%
- `vfsstat` delta: avg_ns=-3.31%, ops=1.31%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'capable', 'vfsstat'], regressed=['biosnoop']. The overall geomean across scripts with stock+ReJIT data is `1.057x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

