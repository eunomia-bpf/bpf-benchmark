# bpftrace Real E2E Report

- Generated: `2026-04-03T02:13:18.955249+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `12`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.966x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=777.98, rejit_ns=751.25, speedup=1.036x, ops_stock=23.53, ops_rejit=23.11, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=1, stock_ns=265.37, rejit_ns=255.28, speedup=1.040x, ops_stock=303115.17, ops_rejit=281653.65, cpu_stock=0.03, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=139.63, rejit_ns=136.34, speedup=1.024x, ops_stock=54.53, ops_rejit=54.42, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=2, stock_ns=6305.60, rejit_ns=8406.75, speedup=0.750x, ops_stock=1.91, ops_rejit=2.52, cpu_stock=0.03, cpu_rejit=0.03
- `capable`: sites=0, stock_ns=110.68, rejit_ns=110.70, speedup=1.000x, ops_stock=309.64, ops_rejit=119.45, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.42, rejit_ns=33.93, speedup=0.985x, ops_stock=52859.11, ops_rejit=52696.30, cpu_stock=0.03, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-3.44%, ops=-1.76%, cpu=-100.00%
- `biosnoop` delta: avg_ns=-3.80%, ops=-7.08%, cpu=-100.00%
- `runqlat` delta: avg_ns=-2.35%, ops=-0.20%, cpu=n/a%
- `tcpretrans` delta: avg_ns=33.32%, ops=31.92%, cpu=0.00%
- `capable` delta: avg_ns=0.02%, ops=-61.42%, cpu=n/a%
- `vfsstat` delta: avg_ns=1.53%, ops=-0.31%, cpu=-0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'biosnoop', 'runqlat'], regressed=['tcpretrans', 'capable', 'vfsstat']. The overall geomean across scripts with stock+ReJIT data is `0.966x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

