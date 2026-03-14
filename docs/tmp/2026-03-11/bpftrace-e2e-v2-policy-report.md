# bpftrace Real E2E Report

- Generated: `2026-03-12T04:50:30.701645+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `3`; aggregate site count: `13`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `1.056x`.

## Per-Script

- `open_latency`: sites=6, stock_ns=324.05, rejit_ns=269.18, speedup=1.204x, ops_stock=95143.99, ops_rejit=96220.93, cpu_stock=0.07, cpu_rejit=0.03
- `exec_trace`: sites=0, stock_ns=551.71, rejit_ns=n/a, speedup=n/a, ops_stock=193.18, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: no eligible directive sites
- `scheduler_latency`: sites=6, stock_ns=164.85, rejit_ns=168.55, speedup=0.978x, ops_stock=41.18, ops_rejit=39.44, cpu_stock=0.03, cpu_rejit=0.07
- `vfs_read_count`: sites=0, stock_ns=59.60, rejit_ns=n/a, speedup=n/a, ops_stock=347574.27, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: no eligible directive sites
- `tcp_connect`: sites=1, stock_ns=947.26, rejit_ns=947.81, speedup=0.999x, ops_stock=18.61, ops_rejit=18.68, cpu_stock=0.03, cpu_rejit=0.00

## Comparison

- `open_latency` delta: avg_ns=-16.93%, ops=1.13%, cpu=-50.00%
- `exec_trace` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `scheduler_latency` delta: avg_ns=2.24%, ops=-4.22%, cpu=100.00%
- `vfs_read_count` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `tcp_connect` delta: avg_ns=0.06%, ops=0.37%, cpu=-100.00%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['open_latency'], regressed=['scheduler_latency', 'tcp_connect']. The overall geomean across scripts with stock+ReJIT data is `1.056x`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

