# bpftrace Real E2E Report

- Generated: `2026-03-29T08:46:51.733840+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `22`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.140x`.

## Per-Script

- `tcplife`: sites=8, stock_ns=988.14, rejit_ns=508.97, speedup=1.941x, ops_stock=19.80, ops_rejit=26.96, cpu_stock=0.10, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=3639.07, rejit_ns=3782.60, speedup=0.962x, ops_stock=12939.53, ops_rejit=13248.63, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=0, stock_ns=186.26, rejit_ns=189.78, speedup=0.981x, ops_stock=61.53, ops_rejit=60.74, cpu_stock=0.00, cpu_rejit=0.07
- `tcpretrans`: sites=3, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=21.29, ops_rejit=21.42, cpu_stock=0.07, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=254.40, rejit_ns=242.13, speedup=1.051x, ops_stock=466.34, ops_rejit=23.42, cpu_stock=0.03, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=34.67, rejit_ns=34.70, speedup=0.999x, ops_stock=11401.92, ops_rejit=12553.50, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-48.49%, ops=36.15%, cpu=-100.00%
- `biosnoop` delta: avg_ns=3.94%, ops=2.39%, cpu=n/a%
- `runqlat` delta: avg_ns=1.89%, ops=-1.28%, cpu=n/a%
- `tcpretrans` delta: avg_ns=n/a%, ops=0.64%, cpu=-100.00%
- `capable` delta: avg_ns=-4.82%, ops=-94.98%, cpu=-100.00%
- `vfsstat` delta: avg_ns=0.09%, ops=10.10%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'capable'], regressed=['biosnoop', 'runqlat', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.140x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

