# bpftrace Real E2E Report

- Generated: `2026-04-10T01:08:46.599403+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `1`; aggregate applied site count: `6` (wide_mem=6).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.001x`.

## Per-Script

- `capable`: sites=6, stock_ns=106.55, rejit_ns=106.44, speedup=1.001x, ops_stock=1251.55, ops_rejit=1271.60, cpu_stock=0.00, cpu_rejit=0.00

## Comparison

- `capable` delta: avg_ns=-0.10%, ops=1.60%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['capable']; regressed: ['none']. The overall geomean across scripts with stock+ReJIT data is `1.001x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

