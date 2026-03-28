# bpftrace Real E2E Report

- Generated: `2026-03-28T18:53:28.152101+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `21`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.037x`.

## Per-Script

- `tcplife`: sites=8, stock_ns=1072.90, rejit_ns=850.22, speedup=1.262x, ops_stock=21.89, ops_rejit=24.22, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=4, stock_ns=3758.27, rejit_ns=4022.94, speedup=0.934x, ops_stock=14129.56, ops_rejit=14128.85, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=0, stock_ns=193.52, rejit_ns=189.15, speedup=1.023x, ops_stock=61.21, ops_rejit=62.10, cpu_stock=0.03, cpu_rejit=0.03
- `tcpretrans`: sites=3, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=19.69, ops_rejit=21.95, cpu_stock=0.03, cpu_rejit=0.00
- `capable`: sites=6, stock_ns=252.16, rejit_ns=255.34, speedup=0.988x, ops_stock=611.56, ops_rejit=231.07, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=34.94, rejit_ns=34.73, speedup=1.006x, ops_stock=13534.61, ops_rejit=14038.38, cpu_stock=0.00, cpu_rejit=0.07

## Comparison

- `tcplife` delta: avg_ns=-20.76%, ops=10.66%, cpu=-100.00%
- `biosnoop` delta: avg_ns=7.04%, ops=-0.00%, cpu=n/a%
- `runqlat` delta: avg_ns=-2.26%, ops=1.46%, cpu=0.00%
- `tcpretrans` delta: avg_ns=n/a%, ops=11.48%, cpu=-100.00%
- `capable` delta: avg_ns=1.26%, ops=-62.22%, cpu=n/a%
- `vfsstat` delta: avg_ns=-0.62%, ops=3.72%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'vfsstat'], regressed=['biosnoop', 'capable']. The overall geomean across scripts with stock+ReJIT data is `1.037x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

