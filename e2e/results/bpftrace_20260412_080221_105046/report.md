# bpftrace Real E2E Report

- Generated: `2026-04-12T08:02:37.467175+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.25.0-be6ee45`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `1`; aggregate applied site count: `244` (map_inline=6, const_prop=70, dce=75, wide_mem=92, bulk_memory=1).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.076x`.

## Per-Script

- `capable`: sites=244, stock_ns=103.74, rejit_ns=96.41, speedup=1.076x, ops_stock=6560.20, ops_rejit=6488.88, cpu_stock=0.00, cpu_rejit=0.00

## Comparison

- `capable` delta: avg_ns=-7.07%, ops=-1.09%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['capable']; regressed: ['none']. The overall geomean across scripts with stock+ReJIT data is `1.076x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

