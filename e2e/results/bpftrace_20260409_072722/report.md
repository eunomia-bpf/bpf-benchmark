# bpftrace Real E2E Report

- Generated: `2026-04-09T07:33:52.805172+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.072x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=1333.61, rejit_ns=909.83, speedup=1.466x, ops_stock=11.44, ops_rejit=12.43, cpu_stock=0.03, cpu_rejit=0.03
- `biosnoop`: sites=5, stock_ns=207.29, rejit_ns=208.75, speedup=0.993x, ops_stock=216395.03, ops_rejit=186154.56, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=126.10, rejit_ns=126.88, speedup=0.994x, ops_stock=40.31, ops_rejit=42.53, cpu_stock=0.00, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=8616.04, rejit_ns=8734.94, speedup=0.986x, ops_stock=1.59, ops_rejit=1.30, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=112.14, rejit_ns=105.79, speedup=1.060x, ops_stock=1273.90, ops_rejit=1320.50, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=34.64, rejit_ns=34.52, speedup=1.003x, ops_stock=52484.51, ops_rejit=52826.74, cpu_stock=0.03, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-31.78%, ops=8.66%, cpu=-0.00%
- `biosnoop` delta: avg_ns=0.71%, ops=-13.97%, cpu=n/a%
- `runqlat` delta: avg_ns=0.62%, ops=5.51%, cpu=n/a%
- `tcpretrans` delta: avg_ns=1.38%, ops=-18.23%, cpu=100.00%
- `capable` delta: avg_ns=-5.67%, ops=3.66%, cpu=n/a%
- `vfsstat` delta: avg_ns=-0.33%, ops=0.65%, cpu=0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'capable', 'vfsstat']; regressed: ['biosnoop', 'runqlat', 'tcpretrans']. The overall geomean across scripts with stock+ReJIT data is `1.072x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

