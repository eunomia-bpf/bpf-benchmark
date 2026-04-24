# bpftrace Real E2E Report

- Generated: `2026-04-23T19:46:42.768075+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `25` (map_inline=1, const_prop=8, dce=3, wide_mem=13).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.035x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=527.23, rejit_ns=562.37, speedup=0.938x, ops_stock=428.86, ops_rejit=407.43, cpu_stock=0.73, cpu_rejit=0.73
- `biosnoop`: sites=5, stock_ns=245.31, rejit_ns=249.38, speedup=0.984x, ops_stock=955207.32, ops_rejit=950065.33, cpu_stock=86.43, cpu_rejit=86.60
- `runqlat`: sites=7, stock_ns=135.55, rejit_ns=134.58, speedup=1.007x, ops_stock=64.44, ops_rejit=63.56, cpu_stock=0.03, cpu_rejit=0.00
- `tcpretrans`: sites=5, stock_ns=10325.80, rejit_ns=8111.27, speedup=1.273x, ops_stock=0.40, ops_rejit=0.40, cpu_stock=0.03, cpu_rejit=0.07
- `capable`: sites=6, stock_ns=123.88, rejit_ns=123.08, speedup=1.006x, ops_stock=2384.82, ops_rejit=2375.13, cpu_stock=8.20, cpu_rejit=7.90
- `vfsstat`: sites=0, stock_ns=162.92, rejit_ns=n/a, speedup=n/a, ops_stock=72.83, ops_rejit=n/a, cpu_stock=0.07, cpu_rejit=n/a

## Comparison

- `tcplife` delta: avg_ns=6.66%, ops=-5.00%, cpu=0.00%
- `biosnoop` delta: avg_ns=1.66%, ops=-0.54%, cpu=0.20%
- `runqlat` delta: avg_ns=-0.71%, ops=-1.36%, cpu=-100.00%
- `tcpretrans` delta: avg_ns=-21.45%, ops=0.07%, cpu=100.00%
- `capable` delta: avg_ns=-0.64%, ops=-0.41%, cpu=-3.65%
- `vfsstat` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['runqlat', 'tcpretrans', 'capable']; regressed: ['tcplife', 'biosnoop']. The overall geomean across scripts with stock+ReJIT data is `1.035x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

