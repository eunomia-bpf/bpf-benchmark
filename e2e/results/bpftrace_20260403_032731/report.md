# bpftrace Real E2E Report

- Generated: `2026-04-03T03:34:07.379134+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2+`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `4`; aggregate site count: `12`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.047x`.

## Per-Script

- `tcplife`: sites=2, stock_ns=810.74, rejit_ns=670.61, speedup=1.209x, ops_stock=21.86, ops_rejit=21.57, cpu_stock=0.03, cpu_rejit=0.00
- `biosnoop`: sites=1, stock_ns=245.11, rejit_ns=250.49, speedup=0.979x, ops_stock=315425.37, ops_rejit=289748.70, cpu_stock=0.00, cpu_rejit=0.00
- `runqlat`: sites=7, stock_ns=139.03, rejit_ns=136.85, speedup=1.016x, ops_stock=54.04, ops_rejit=56.32, cpu_stock=0.00, cpu_rejit=0.03
- `tcpretrans`: sites=2, stock_ns=7565.48, rejit_ns=7065.51, speedup=1.071x, ops_stock=2.36, ops_rejit=2.53, cpu_stock=0.03, cpu_rejit=0.03
- `capable`: sites=0, stock_ns=112.05, rejit_ns=112.08, speedup=1.000x, ops_stock=674.65, ops_rejit=438.22, cpu_stock=0.00, cpu_rejit=0.00
- `vfsstat`: sites=0, stock_ns=33.56, rejit_ns=32.79, speedup=1.023x, ops_stock=51342.49, ops_rejit=52594.48, cpu_stock=0.03, cpu_rejit=0.03

## Comparison

- `tcplife` delta: avg_ns=-17.28%, ops=-1.32%, cpu=-100.00%
- `biosnoop` delta: avg_ns=2.20%, ops=-8.14%, cpu=n/a%
- `runqlat` delta: avg_ns=-1.57%, ops=4.20%, cpu=n/a%
- `tcpretrans` delta: avg_ns=-6.61%, ops=7.14%, cpu=-0.00%
- `capable` delta: avg_ns=0.03%, ops=-35.05%, cpu=n/a%
- `vfsstat` delta: avg_ns=-2.29%, ops=2.44%, cpu=0.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['tcplife', 'runqlat', 'tcpretrans', 'vfsstat'], regressed=['biosnoop', 'capable']. The overall geomean across scripts with stock+ReJIT data is `1.047x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

