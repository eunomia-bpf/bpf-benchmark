# bpftrace Real E2E Report

- Generated: `2026-04-24T02:16:03.836715+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `3`; aggregate applied site count: `13` (map_inline=1, const_prop=2, wide_mem=10).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.054x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=536.87, rejit_ns=509.50, speedup=1.054x, ops_stock=414.98, ops_rejit=424.24, cpu_stock=1.00, cpu_rejit=0.60
- `biosnoop`: sites=5, stock_ns=255.00, rejit_ns=269.86, speedup=0.945x, ops_stock=955514.04, ops_rejit=917295.47, cpu_stock=87.40, cpu_rejit=86.60
- `runqlat`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=3, last_program_ids=1097,1098,1099)
- `tcpretrans`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=1, last_program_ids=1105)
- `capable`: sites=6, stock_ns=120.40, rejit_ns=118.85, speedup=1.013x, ops_stock=2370.01, ops_rejit=2394.69, cpu_stock=7.98, cpu_rejit=7.97
- `vfsstat`: sites=0, stock_ns=102.02, rejit_ns=83.36, speedup=1.224x, ops_stock=71.74, ops_rejit=71.13, cpu_stock=0.00, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-5.10%, ops=2.23%, cpu=-40.00%
- `biosnoop` delta: avg_ns=5.83%, ops=-4.00%, cpu=-0.91%
- `runqlat` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `tcpretrans` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `capable` delta: avg_ns=-1.29%, ops=1.04%, cpu=-0.24%
- `vfsstat` delta: avg_ns=-18.29%, ops=-0.86%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'capable', 'vfsstat']; regressed: ['biosnoop']. The overall geomean across scripts with stock+ReJIT data is `1.054x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

