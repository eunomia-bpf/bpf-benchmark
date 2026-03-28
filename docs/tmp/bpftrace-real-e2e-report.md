# bpftrace Real E2E Report

- Generated: `2026-03-28T14:37:43.148790+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `21`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `n/a`.

## Per-Script

- `tcplife`: sites=8, stock_ns=924.48, rejit_ns=n/a, speedup=n/a, ops_stock=23.21, ops_rejit=n/a, cpu_stock=0.07, cpu_rejit=n/a
- `biosnoop`: sites=4, stock_ns=3943.93, rejit_ns=n/a, speedup=n/a, ops_stock=13620.78, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- `runqlat`: sites=0, stock_ns=180.07, rejit_ns=n/a, speedup=n/a, ops_stock=61.63, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- `tcpretrans`: sites=3, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=21.69, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- `capable`: sites=6, stock_ns=257.26, rejit_ns=n/a, speedup=n/a, ops_stock=336.14, ops_rejit=n/a, cpu_stock=0.00, cpu_rejit=n/a
- `vfsstat`: sites=0, stock_ns=35.37, rejit_ns=n/a, speedup=n/a, ops_stock=13133.30, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a

## Comparison

- `tcplife` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `biosnoop` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `runqlat` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `tcpretrans` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `capable` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `vfsstat` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['none'], regressed=['none']. The overall geomean across scripts with stock+ReJIT data is `n/a`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

