# bpftrace Real E2E Report

- Generated: `2026-03-31T03:33:53.729974+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.021x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=710.00, rejit_ns=592.66, speedup=1.198x, ops_stock=22.68, ops_rejit=21.73, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=269.01, rejit_ns=281.55, speedup=0.955x, ops_stock=306926.14, ops_rejit=318416.95, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=141.56, rejit_ns=135.12, speedup=1.048x, ops_stock=54.12, ops_rejit=56.57, cpu_stock=0.00, cpu_rejit=0.07
- `tcpretrans`: sites=5, stock_ns=7497.64, rejit_ns=8070.97, speedup=0.929x, ops_stock=2.93, ops_rejit=2.66, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=109.40, rejit_ns=108.08, speedup=1.012x, ops_stock=812.85, ops_rejit=586.05, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=34.33, rejit_ns=34.13, speedup=1.006x, ops_stock=51395.65, ops_rejit=52075.91, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-16.53%, ops=-4.22%, cpu=-100.00%
- `biosnoop` delta: avg_ns=4.66%, ops=3.74%, cpu=n/a%
- `runqlat` delta: avg_ns=-4.55%, ops=4.53%, cpu=n/a%
- `tcpretrans` delta: avg_ns=7.65%, ops=-9.05%, cpu=100.00%
- `capable` delta: avg_ns=-1.21%, ops=-27.90%, cpu=n/a%
- `vfsstat` delta: avg_ns=-0.56%, ops=1.32%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'capable', 'vfsstat'], regressed=['biosnoop', 'tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.021x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

