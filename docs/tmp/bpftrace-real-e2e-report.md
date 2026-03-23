# bpftrace Real E2E Report

- Generated: `2026-03-23T12:05:40.833907+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `0`; aggregate site count: `0`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `4.474x`.

## Per-Script

- `tcplife`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: bpftrace did not attach any programs
- `biosnoop`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: bpftrace did not attach any programs
- `runqlat`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: bpftrace did not attach any programs
- `tcpretrans`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: bpftrace did not attach any programs
- `capable`: sites=0, stock_ns=850.93, rejit_ns=190.17, speedup=4.474x, ops_stock=13548.33, ops_rejit=14667.87, cpu_stock=0.03, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: bpftrace did not attach any programs

## Comparison

- `tcplife` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `biosnoop` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `runqlat` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `tcpretrans` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `capable` delta: avg_ns=-77.65%, ops=8.26%, cpu=-100.00%
- `vfsstat` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['capable'], regressed=['none']. The overall geomean across scripts with stock+ReJIT data is `4.474x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

