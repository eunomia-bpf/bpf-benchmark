# bpftrace Real E2E Report

- Generated: `2026-03-30T21:39:41.154892+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `1`; aggregate site count: `6`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.014x`.

## Per-Script

- `capable`: sites=6, stock_ns=2012.03, rejit_ns=1983.60, speedup=1.014x, ops_stock=351.87, ops_rejit=417.02, cpu_stock=0.00, cpu_rejit=0.00

## Comparison

- `capable` delta: avg_ns=-1.41%, ops=18.52%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['capable'], regressed=['none']. The overall geomean across scripts with stock+ReJIT data is `1.014x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

