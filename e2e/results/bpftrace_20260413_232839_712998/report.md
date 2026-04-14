# bpftrace Real E2E Report

- Generated: `2026-04-13T23:35:10.514056+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.25.0-be6ee45`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `360` (map_inline=47, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.085x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=1072.84, rejit_ns=749.83, speedup=1.431x, ops_stock=11.36, ops_rejit=11.28, cpu_stock=0.10, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=168.98, rejit_ns=159.69, speedup=1.058x, ops_stock=59792.85, ops_rejit=60538.69, cpu_stock=0.03, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=116.61, rejit_ns=115.64, speedup=1.008x, ops_stock=16.93, ops_rejit=16.65, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=42, stock_ns=6151.67, rejit_ns=6741.00, speedup=0.913x, ops_stock=1.62, ops_rejit=1.42, cpu_stock=0.00, cpu_rejit=0.07
- `capable`: sites=244, stock_ns=101.23, rejit_ns=97.83, speedup=1.035x, ops_stock=4916.31, ops_rejit=4865.33, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=10, stock_ns=78.81, rejit_ns=69.65, speedup=1.132x, ops_stock=74.35, ops_rejit=63.82, cpu_stock=0.07, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-30.11%, ops=-0.67%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-5.50%, ops=1.25%, cpu=-100.00%
- `runqlat` delta: avg_ns=-0.83%, ops=-1.67%, cpu=n/a%
- `tcpretrans` delta: avg_ns=9.58%, ops=-12.40%, cpu=n/a%
- `capable` delta: avg_ns=-3.35%, ops=-1.04%, cpu=n/a%
- `vfsstat` delta: avg_ns=-11.63%, ops=-14.17%, cpu=-50.03%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'capable', 'vfsstat']; regressed: ['tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.085x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

