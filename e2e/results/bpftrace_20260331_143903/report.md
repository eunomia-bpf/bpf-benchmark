# bpftrace Real E2E Report

- Generated: `2026-03-31T14:45:33.993402+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.044x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=856.47, rejit_ns=614.50, speedup=1.394x, ops_stock=21.07, ops_rejit=22.83, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=267.94, rejit_ns=279.91, speedup=0.957x, ops_stock=278163.20, ops_rejit=291431.28, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=136.05, rejit_ns=134.68, speedup=1.010x, ops_stock=55.92, ops_rejit=57.58, cpu_stock=0.03, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=9133.21, rejit_ns=9635.68, speedup=0.948x, ops_stock=2.22, ops_rejit=2.39, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=110.08, rejit_ns=109.70, speedup=1.004x, ops_stock=368.28, ops_rejit=94.46, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.69, rejit_ns=33.29, speedup=1.012x, ops_stock=51281.83, ops_rejit=51865.70, cpu_stock=0.07, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-28.25%, ops=8.31%, cpu=-100.00%
- `biosnoop` delta: avg_ns=4.47%, ops=4.77%, cpu=n/a%
- `runqlat` delta: avg_ns=-1.00%, ops=2.97%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=5.50%, ops=7.53%, cpu=100.00%
- `capable` delta: avg_ns=-0.35%, ops=-74.35%, cpu=n/a%
- `vfsstat` delta: avg_ns=-1.21%, ops=1.14%, cpu=-50.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'capable', 'vfsstat'], regressed=['biosnoop', 'tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.044x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

