# bpftrace Real E2E Report

- Generated: `2026-03-31T04:27:40.254588+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.027x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=713.20, rejit_ns=529.79, speedup=1.346x, ops_stock=21.38, ops_rejit=22.56, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=244.85, rejit_ns=256.84, speedup=0.953x, ops_stock=291449.62, ops_rejit=321880.99, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=137.92, rejit_ns=136.12, speedup=1.013x, ops_stock=53.99, ops_rejit=54.40, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=7532.31, rejit_ns=8424.13, speedup=0.894x, ops_stock=2.33, ops_rejit=2.32, cpu_stock=0.00, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=111.32, rejit_ns=111.25, speedup=1.001x, ops_stock=182.24, ops_rejit=983.04, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.35, rejit_ns=33.06, speedup=1.009x, ops_stock=51153.11, ops_rejit=52011.22, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-25.72%, ops=5.55%, cpu=-100.00%
- `biosnoop` delta: avg_ns=4.89%, ops=10.44%, cpu=n/a%
- `runqlat` delta: avg_ns=-1.30%, ops=0.75%, cpu=n/a%
- `tcpretrans` delta: avg_ns=11.84%, ops=-0.44%, cpu=n/a%
- `capable` delta: avg_ns=-0.06%, ops=439.40%, cpu=n/a%
- `vfsstat` delta: avg_ns=-0.88%, ops=1.68%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'capable', 'vfsstat'], regressed=['biosnoop', 'tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.027x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

