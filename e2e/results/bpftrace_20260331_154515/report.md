# bpftrace Real E2E Report

- Generated: `2026-03-31T15:51:49.130858+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.092x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=692.64, rejit_ns=429.96, speedup=1.611x, ops_stock=19.87, ops_rejit=23.17, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=250.23, rejit_ns=245.81, speedup=1.018x, ops_stock=296564.08, ops_rejit=303030.45, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=141.42, rejit_ns=137.97, speedup=1.025x, ops_stock=53.47, ops_rejit=55.76, cpu_stock=0.03, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=7621.65, rejit_ns=7735.70, speedup=0.985x, ops_stock=2.44, ops_rejit=2.66, cpu_stock=0.00, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=111.35, rejit_ns=110.96, speedup=1.004x, ops_stock=185.61, ops_rejit=1023.41, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=34.72, rejit_ns=34.02, speedup=1.020x, ops_stock=52144.61, ops_rejit=52699.32, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-37.92%, ops=16.62%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-1.77%, ops=2.18%, cpu=n/a%
- `runqlat` delta: avg_ns=-2.43%, ops=4.28%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=1.50%, ops=9.11%, cpu=n/a%
- `capable` delta: avg_ns=-0.35%, ops=451.37%, cpu=n/a%
- `vfsstat` delta: avg_ns=-2.00%, ops=1.06%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'biosnoop', 'runqlat', 'capable', 'vfsstat'], regressed=['tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.092x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

