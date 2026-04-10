# bpftrace Real E2E Report

- Generated: `2026-04-10T03:01:13.300777+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `5`; aggregate applied site count: `33` (map_inline=1, const_prop=8, dce=3, wide_mem=21).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.037x`.

## Per-Script

- `tcplife`: sites=10, stock_ns=1049.39, rejit_ns=876.60, speedup=1.197x, ops_stock=26.83, ops_rejit=26.73, cpu_stock=0.10, cpu_rejit=0.00
- `biosnoop`: sites=5, stock_ns=256.85, rejit_ns=266.12, speedup=0.965x, ops_stock=385948.15, ops_rejit=373115.95, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=150.18, rejit_ns=149.03, speedup=1.008x, ops_stock=19.56, ops_rejit=19.01, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=5, stock_ns=13001.50, rejit_ns=9978.62, speedup=1.303x, ops_stock=1.69, ops_rejit=1.55, cpu_stock=0.00, cpu_rejit=0.03
- `capable`: sites=6, stock_ns=141.15, rejit_ns=120.37, speedup=1.173x, ops_stock=938.81, ops_rejit=1129.94, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=76.04, rejit_ns=108.99, speedup=0.698x, ops_stock=81.64, ops_rejit=75.48, cpu_stock=0.00, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-16.47%, ops=-0.36%, cpu=-100.00%
- `biosnoop` delta: avg_ns=3.61%, ops=-3.32%, cpu=n/a%
- `runqlat` delta: avg_ns=-0.77%, ops=-2.81%, cpu=n/a%
- `tcpretrans` delta: avg_ns=-23.25%, ops=-8.15%, cpu=n/a%
- `capable` delta: avg_ns=-14.72%, ops=20.36%, cpu=n/a%
- `vfsstat` delta: avg_ns=43.32%, ops=-7.55%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['tcplife', 'runqlat', 'tcpretrans', 'capable']; regressed: ['biosnoop', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `1.037x`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

