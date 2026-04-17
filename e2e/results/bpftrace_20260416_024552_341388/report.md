# bpftrace Real E2E Report

- Generated: `2026-04-16T02:52:12.024040+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.25.0`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `363` (map_inline=50, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.812x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=273.12, rejit_ns=365.90, speedup=0.746x, ops_stock=451.76, ops_rejit=380.05, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=199.40, rejit_ns=265.31, speedup=0.752x, ops_stock=916269.66, ops_rejit=719345.38, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=125.82, rejit_ns=122.99, speedup=1.023x, ops_stock=69.31, ops_rejit=68.84, cpu_stock=0.00, cpu_rejit=0.07
- `tcpretrans`: sites=42, stock_ns=10846.50, rejit_ns=14139.88, speedup=0.767x, ops_stock=1.54, ops_rejit=1.51, cpu_stock=0.07, cpu_rejit=0.03
- `capable`: sites=244, stock_ns=97.48, rejit_ns=94.84, speedup=1.028x, ops_stock=2624.41, ops_rejit=2635.07, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=13, stock_ns=115.93, rejit_ns=183.13, speedup=0.633x, ops_stock=75.00, ops_rejit=71.54, cpu_stock=0.17, cpu_rejit=0.07

## Comparison

- `tcplife` delta: avg_ns=33.97%, ops=-15.87%, cpu=-100.00%
- `biosnoop` delta: avg_ns=33.05%, ops=-21.49%, cpu=n/a%
- `runqlat` delta: avg_ns=-2.25%, ops=-0.68%, cpu=n/a%
- `tcpretrans` delta: avg_ns=30.36%, ops=-1.53%, cpu=-50.00%
- `capable` delta: avg_ns=-2.71%, ops=0.41%, cpu=n/a%
- `vfsstat` delta: avg_ns=57.97%, ops=-4.61%, cpu=-60.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['runqlat', 'capable']; regressed: ['tcplife', 'biosnoop', 'tcpretrans', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `0.812x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

