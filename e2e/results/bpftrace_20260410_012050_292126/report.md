# bpftrace Real E2E Report

- Generated: `2026-04-10T01:27:24.264684+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.058x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=1146.88, rejit_ns=737.66, speedup=1.555x, ops_stock=20.29, ops_rejit=22.45, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=257.92, rejit_ns=256.49, speedup=1.006x, ops_stock=322830.38, ops_rejit=322390.86, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=142.98, rejit_ns=141.84, speedup=1.008x, ops_stock=17.35, ops_rejit=16.56, cpu_stock=0.03, cpu_rejit=0.03
- `tcpretrans`: sites=5, stock_ns=6800.20, rejit_ns=6456.73, speedup=1.053x, ops_stock=1.47, ops_rejit=1.39, cpu_stock=0.00, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=113.47, rejit_ns=125.22, speedup=0.906x, ops_stock=1212.25, ops_rejit=1053.50, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=110.26, rejit_ns=118.38, speedup=0.931x, ops_stock=79.15, ops_rejit=73.76, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `tcplife` delta: avg_ns=-35.68%, ops=10.65%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-0.55%, ops=-0.14%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.79%, ops=-4.51%, cpu=-0.00%
- `tcpretrans` delta: avg_ns=-5.05%, ops=-5.61%, cpu=n/a%
- `capable` delta: avg_ns=10.35%, ops=-13.10%, cpu=n/a%
- `vfsstat` delta: avg_ns=7.36%, ops=-6.80%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'biosnoop', 'runqlat', 'tcpretrans']; regressed: ['capable', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.058x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

