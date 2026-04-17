# bpftrace Real E2E Report

- Generated: `2026-04-16T03:56:23.398922+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.25.0`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `363` (map_inline=50, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.883x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=387.38, rejit_ns=360.85, speedup=1.074x, ops_stock=373.04, ops_rejit=383.97, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=233.25, rejit_ns=215.84, speedup=1.081x, ops_stock=822223.49, ops_rejit=850960.06, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=123.54, rejit_ns=122.05, speedup=1.012x, ops_stock=70.94, ops_rejit=69.71, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=42, stock_ns=10581.67, rejit_ns=14277.25, speedup=0.741x, ops_stock=1.66, ops_rejit=1.52, cpu_stock=0.00, cpu_rejit=0.07
- `capable`: sites=244, stock_ns=97.02, rejit_ns=94.49, speedup=1.027x, ops_stock=2645.16, ops_rejit=2638.40, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=13, stock_ns=107.12, rejit_ns=202.46, speedup=0.529x, ops_stock=72.71, ops_rejit=62.70, cpu_stock=0.20, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-6.85%, ops=2.93%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-7.46%, ops=3.49%, cpu=n/a%
- `runqlat` delta: avg_ns=-1.21%, ops=-1.74%, cpu=n/a%
- `tcpretrans` delta: avg_ns=34.92%, ops=-8.05%, cpu=n/a%
- `capable` delta: avg_ns=-2.60%, ops=-0.26%, cpu=n/a%
- `vfsstat` delta: avg_ns=89.00%, ops=-13.77%, cpu=-83.33%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'capable']; regressed: ['tcpretrans', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `0.883x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

