# bpftrace Real E2E Report

- Generated: `2026-03-11T16:38:36.319564+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2-g2a6783cc77b6`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `2`; aggregate site count: `9`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `0.992x`.

## Per-Script

- `open_latency`: sites=5, stock_ns=277.17, rejit_ns=273.77, speedup=1.012x, ops_stock=95367.05, ops_rejit=96082.49, cpu_stock=0.03, cpu_rejit=0.03
- `exec_trace`: sites=0, stock_ns=467.11, rejit_ns=n/a, speedup=n/a, ops_stock=198.84, ops_rejit=n/a, cpu_stock=0.00, cpu_rejit=n/a
- Note: no eligible directive sites
- `scheduler_latency`: sites=4, stock_ns=158.59, rejit_ns=163.27, speedup=0.971x, ops_stock=41.72, ops_rejit=38.09, cpu_stock=0.00, cpu_rejit=0.00
- `vfs_read_count`: sites=0, stock_ns=58.42, rejit_ns=n/a, speedup=n/a, ops_stock=286499.06, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: no eligible directive sites
- `tcp_connect`: sites=0, stock_ns=305.59, rejit_ns=n/a, speedup=n/a, ops_stock=18.93, ops_rejit=n/a, cpu_stock=0.00, cpu_rejit=n/a
- Note: no eligible directive sites

## Comparison

- `open_latency` delta: avg_ns=-1.23%, ops=0.75%, cpu=0.00%
- `exec_trace` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `scheduler_latency` delta: avg_ns=2.95%, ops=-8.70%, cpu=n/a%
- `vfs_read_count` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `tcp_connect` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['open_latency'], regressed=['scheduler_latency']. The overall geomean across scripts with stock+ReJIT data is `0.992x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

