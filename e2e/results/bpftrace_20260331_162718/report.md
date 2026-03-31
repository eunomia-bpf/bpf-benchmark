# bpftrace Real E2E Report

- Generated: `2026-03-31T16:33:51.992618+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.066x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=740.28, rejit_ns=621.82, speedup=1.191x, ops_stock=22.38, ops_rejit=21.21, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=256.58, rejit_ns=200.57, speedup=1.279x, ops_stock=312085.53, ops_rejit=292851.99, cpu_stock=0.03, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=136.57, rejit_ns=134.02, speedup=1.019x, ops_stock=53.23, ops_rejit=56.81, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=7762.70, rejit_ns=8120.42, speedup=0.956x, ops_stock=2.92, ops_rejit=2.23, cpu_stock=0.07, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=109.96, rejit_ns=110.25, speedup=0.997x, ops_stock=642.45, ops_rejit=430.01, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.39, rejit_ns=33.62, speedup=0.993x, ops_stock=53210.53, ops_rejit=52709.63, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-16.00%, ops=-5.24%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-21.83%, ops=-6.16%, cpu=-100.00%
- `runqlat` delta: avg_ns=-1.87%, ops=6.72%, cpu=n/a%
- `tcpretrans` delta: avg_ns=4.61%, ops=-23.65%, cpu=-100.00%
- `capable` delta: avg_ns=0.27%, ops=-33.07%, cpu=n/a%
- `vfsstat` delta: avg_ns=0.67%, ops=-0.94%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'biosnoop', 'runqlat'], regressed=['tcpretrans', 'capable', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.066x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

