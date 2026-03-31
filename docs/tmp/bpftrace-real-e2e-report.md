# bpftrace Real E2E Report

- Generated: `2026-03-31T01:07:53.538715+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `5`; aggregate site count: `33`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.999x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=610.35, rejit_ns=557.39, speedup=1.095x, ops_stock=22.41, ops_rejit=22.46, cpu_stock=0.00, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=291.42, rejit_ns=246.34, speedup=1.183x, ops_stock=335713.33, ops_rejit=286518.04, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=139.10, rejit_ns=136.00, speedup=1.023x, ops_stock=55.15, ops_rejit=56.37, cpu_stock=0.03, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=5519.05, rejit_ns=7313.04, speedup=0.755x, ops_stock=0.60, ops_rejit=0.66, cpu_stock=0.07, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=109.96, rejit_ns=109.23, speedup=1.007x, ops_stock=1078.91, ops_rejit=875.15, cpu_stock=0.03, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=32.31, rejit_ns=32.62, speedup=0.990x, ops_stock=53421.66, ops_rejit=53552.29, cpu_stock=0.07, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-8.68%, ops=0.18%, cpu=n/a%
- `biosnoop` delta: avg_ns=-15.47%, ops=-14.65%, cpu=n/a%
- `runqlat` delta: avg_ns=-2.23%, ops=2.22%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=32.51%, ops=10.84%, cpu=-50.00%
- `capable` delta: avg_ns=-0.66%, ops=-18.89%, cpu=-100.00%
- `vfsstat` delta: avg_ns=0.99%, ops=0.24%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'biosnoop', 'runqlat', 'capable'], regressed=['tcpretrans', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `0.999x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

