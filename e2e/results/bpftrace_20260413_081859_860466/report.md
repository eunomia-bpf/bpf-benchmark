# bpftrace Real E2E Report

- Generated: `2026-04-13T08:25:30.281565+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.25.0-be6ee45`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `360` (map_inline=47, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.039x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=999.56, rejit_ns=765.10, speedup=1.306x, ops_stock=11.74, ops_rejit=11.35, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=184.17, rejit_ns=177.46, speedup=1.038x, ops_stock=61138.87, ops_rejit=62599.50, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=131.24, rejit_ns=130.54, speedup=1.005x, ops_stock=17.02, ops_rejit=17.35, cpu_stock=0.03, cpu_rejit=0.00
- `tcpretrans`: sites=42, stock_ns=7522.15, rejit_ns=8562.25, speedup=0.879x, ops_stock=1.51, ops_rejit=1.52, cpu_stock=0.03, cpu_rejit=0.00
- `capable`: sites=244, stock_ns=107.87, rejit_ns=100.50, speedup=1.073x, ops_stock=4600.28, ops_rejit=4802.30, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=10, stock_ns=104.83, rejit_ns=106.90, speedup=0.981x, ops_stock=76.56, ops_rejit=72.25, cpu_stock=0.03, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-23.46%, ops=-3.35%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-3.64%, ops=2.39%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.53%, ops=1.98%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=13.83%, ops=0.31%, cpu=-100.00%
- `capable` delta: avg_ns=-6.83%, ops=4.39%, cpu=n/a%
- `vfsstat` delta: avg_ns=1.98%, ops=-5.63%, cpu=0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'capable']; regressed: ['tcpretrans', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.039x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

