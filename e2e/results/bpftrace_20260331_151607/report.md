# bpftrace Real E2E Report

- Generated: `2026-03-31T15:22:39.206326+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.044x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=594.23, rejit_ns=457.81, speedup=1.298x, ops_stock=20.48, ops_rejit=21.29, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=231.32, rejit_ns=264.70, speedup=0.874x, ops_stock=307198.37, ops_rejit=300553.00, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=135.42, rejit_ns=134.26, speedup=1.009x, ops_stock=57.13, ops_rejit=56.25, cpu_stock=0.03, cpu_rejit=0.03
- `tcpretrans`: sites=5, stock_ns=7844.14, rejit_ns=6876.74, speedup=1.141x, ops_stock=2.32, ops_rejit=2.08, cpu_stock=0.07, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=109.44, rejit_ns=110.16, speedup=0.993x, ops_stock=414.50, ops_rejit=246.27, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=32.87, rejit_ns=32.91, speedup=0.999x, ops_stock=53209.63, ops_rejit=52995.48, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-22.96%, ops=3.96%, cpu=-100.00%
- `biosnoop` delta: avg_ns=14.43%, ops=-2.16%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.86%, ops=-1.54%, cpu=0.00%
- `tcpretrans` delta: avg_ns=-12.33%, ops=-10.30%, cpu=-100.00%
- `capable` delta: avg_ns=0.66%, ops=-40.59%, cpu=n/a%
- `vfsstat` delta: avg_ns=0.11%, ops=-0.40%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'tcpretrans'], regressed=['biosnoop', 'capable', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.044x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

