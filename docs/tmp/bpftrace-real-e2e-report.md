# bpftrace Real E2E Report

- Generated: `2026-03-23T13:31:58.980303+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `0`; aggregate site count: `0`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.568x`.

## Per-Script

- `tcplife`: sites=0, stock_ns=1142.84, rejit_ns=785.41, speedup=1.455x, ops_stock=28.81, ops_rejit=29.32, cpu_stock=0.10, cpu_rejit=0.00
- `biosnoop`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=467148.37, ops_rejit=504738.87, cpu_stock=0.03, cpu_rejit=0.03
- `runqlat`: sites=0, stock_ns=189.02, rejit_ns=189.30, speedup=0.999x, ops_stock=81.90, ops_rejit=82.28, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=28.76, ops_rejit=28.53, cpu_stock=0.00, cpu_rejit=0.03
- `capable`: sites=0, stock_ns=982.65, rejit_ns=235.54, speedup=4.172x, ops_stock=261240.11, ops_rejit=246274.22, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=25.13, rejit_ns=25.22, speedup=0.997x, ops_stock=444197.32, ops_rejit=437419.99, cpu_stock=0.07, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-31.28%, ops=1.79%, cpu=-100.00%
- `biosnoop` delta: avg_ns=n/a%, ops=8.05%, cpu=-0.00%
- `runqlat` delta: avg_ns=0.15%, ops=0.47%, cpu=n/a%
- `tcpretrans` delta: avg_ns=n/a%, ops=-0.78%, cpu=n/a%
- `capable` delta: avg_ns=-76.03%, ops=-5.73%, cpu=n/a%
- `vfsstat` delta: avg_ns=0.35%, ops=-1.53%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'capable'], regressed=['runqlat', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.568x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

