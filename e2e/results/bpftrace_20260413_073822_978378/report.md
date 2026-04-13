# bpftrace Real E2E Report

- Generated: `2026-04-13T07:45:17.391039+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.25.0-be6ee45`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `360` (map_inline=47, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.037x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=1147.23, rejit_ns=941.01, speedup=1.219x, ops_stock=10.79, ops_rejit=11.39, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=190.08, rejit_ns=206.69, speedup=0.920x, ops_stock=59518.24, ops_rejit=56658.97, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=137.10, rejit_ns=135.93, speedup=1.009x, ops_stock=15.97, ops_rejit=16.40, cpu_stock=0.03, cpu_rejit=0.03
- `tcpretrans`: sites=42, stock_ns=11532.60, rejit_ns=10802.67, speedup=1.068x, ops_stock=1.52, ops_rejit=1.72, cpu_stock=0.03, cpu_rejit=0.03
- `capable`: sites=244, stock_ns=109.95, rejit_ns=100.44, speedup=1.095x, ops_stock=4610.67, ops_rejit=4787.66, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=10, stock_ns=145.98, rejit_ns=155.56, speedup=0.938x, ops_stock=3.53, ops_rejit=44.74, cpu_stock=0.07, cpu_rejit=0.07

## Comparison

- `tcplife` delta: avg_ns=-17.98%, ops=5.55%, cpu=-100.00%
- `biosnoop` delta: avg_ns=8.74%, ops=-4.80%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.85%, ops=2.66%, cpu=0.00%
- `tcpretrans` delta: avg_ns=-6.33%, ops=12.98%, cpu=0.04%
- `capable` delta: avg_ns=-8.65%, ops=3.84%, cpu=n/a%
- `vfsstat` delta: avg_ns=6.57%, ops=1167.08%, cpu=-0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'runqlat', 'tcpretrans', 'capable']; regressed: ['biosnoop', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.037x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

