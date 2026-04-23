# bpftrace Real E2E Report

- Generated: `2026-04-23T12:06:11.212542+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `1`; aggregate applied site count: `6` (wide_mem=6).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.030x`.

## Per-Script

- `capable`: sites=6, stock_ns=123.28, rejit_ns=119.70, speedup=1.030x, ops_stock=2377.17, ops_rejit=2385.53, cpu_stock=8.39, cpu_rejit=7.80

## Comparison

- `capable` delta: avg_ns=-2.90%, ops=0.35%, cpu=-7.12%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['capable']; regressed: ['none']. The overall geomean across scripts with stock+ReJIT data is `1.030x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

