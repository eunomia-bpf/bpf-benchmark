# bpftrace Real E2E Report

- Generated: `2026-04-16T05:08:42.461931+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.25.0`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `6`; aggregate applied site count: `363` (map_inline=50, const_prop=90, dce=83, wide_mem=137, bulk_memory=3).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.832x`.

## Per-Script

- `tcplife`: sites=33, stock_ns=282.73, rejit_ns=271.67, speedup=1.041x, ops_stock=452.40, ops_rejit=453.65, cpu_stock=0.07, cpu_rejit=0.00
- `biosnoop`: sites=18, stock_ns=175.69, rejit_ns=212.25, speedup=0.828x, ops_stock=1057810.71, ops_rejit=896053.24, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=13, stock_ns=126.39, rejit_ns=125.13, speedup=1.010x, ops_stock=69.46, ops_rejit=68.55, cpu_stock=0.03, cpu_rejit=0.03
- `tcpretrans`: sites=42, stock_ns=9559.00, rejit_ns=11185.27, speedup=0.855x, ops_stock=1.62, ops_rejit=1.60, cpu_stock=0.07, cpu_rejit=0.03
- `capable`: sites=244, stock_ns=97.38, rejit_ns=93.77, speedup=1.039x, ops_stock=2611.69, ops_rejit=2626.11, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=13, stock_ns=61.43, rejit_ns=143.31, speedup=0.429x, ops_stock=75.76, ops_rejit=75.98, cpu_stock=0.17, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-3.91%, ops=0.28%, cpu=-100.00%
- `biosnoop` delta: avg_ns=20.81%, ops=-15.29%, cpu=n/a%
- `runqlat` delta: avg_ns=-1.00%, ops=-1.31%, cpu=-0.00%
- `tcpretrans` delta: avg_ns=17.01%, ops=-0.80%, cpu=-50.00%
- `capable` delta: avg_ns=-3.71%, ops=0.55%, cpu=n/a%
- `vfsstat` delta: avg_ns=133.27%, ops=0.29%, cpu=-80.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'runqlat', 'capable']; regressed: ['biosnoop', 'tcpretrans', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `0.832x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

