# bpftrace Real E2E Report

- Generated: `2026-04-16T08:17:18.677973+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.25.0`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `363` (map_inline=50, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.015x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=1349.71, rejit_ns=1175.97, speedup=1.148x, ops_stock=137.40, ops_rejit=141.84, cpu_stock=0.17, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=370.84, rejit_ns=360.05, speedup=1.030x, ops_stock=286718.45, ops_rejit=289469.56, cpu_stock=0.07, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=428.77, rejit_ns=424.25, speedup=1.011x, ops_stock=14.89, ops_rejit=14.81, cpu_stock=0.03, cpu_rejit=0.07
- `tcpretrans`: sites=42, stock_ns=14457.62, rejit_ns=14311.87, speedup=1.010x, ops_stock=0.40, ops_rejit=0.40, cpu_stock=0.07, cpu_rejit=0.10
- `capable`: sites=244, stock_ns=330.44, rejit_ns=303.11, speedup=1.090x, ops_stock=335.91, ops_rejit=331.09, cpu_stock=0.03, cpu_rejit=0.00
- `vfsstat`: sites=13, stock_ns=353.72, rejit_ns=425.27, speedup=0.832x, ops_stock=353.42, ops_rejit=354.44, cpu_stock=0.57, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-12.87%, ops=3.23%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-2.91%, ops=0.96%, cpu=-100.00%
- `runqlat` delta: avg_ns=-1.06%, ops=-0.54%, cpu=100.00%
- `tcpretrans` delta: avg_ns=-1.01%, ops=0.00%, cpu=50.00%
- `capable` delta: avg_ns=-8.27%, ops=-1.44%, cpu=-100.00%
- `vfsstat` delta: avg_ns=20.23%, ops=0.29%, cpu=-94.12%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'tcpretrans', 'capable']; regressed: ['vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.015x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

