# bpftrace Real E2E Report

- Generated: `2026-03-12T21:08:52.584223+00:00`
- Run mode: `full`
- Duration per phase: `30s`
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `3`; aggregate site count: `13`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `n/a`.

## Per-Script

- `open_latency`: sites=6, stock_ns=233.29, rejit_ns=n/a, speedup=n/a, ops_stock=95489.31, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: BPF_PROG_JIT_RECOMPILE did not apply
- `exec_trace`: sites=0, stock_ns=2100.67, rejit_ns=n/a, speedup=n/a, ops_stock=708.79, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: no eligible directive sites
- `scheduler_latency`: sites=6, stock_ns=147.32, rejit_ns=n/a, speedup=n/a, ops_stock=42.53, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: BPF_PROG_JIT_RECOMPILE did not apply
- `vfs_read_count`: sites=0, stock_ns=57.65, rejit_ns=n/a, speedup=n/a, ops_stock=360769.65, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: no eligible directive sites
- `tcp_connect`: sites=1, stock_ns=519.95, rejit_ns=n/a, speedup=n/a, ops_stock=20.06, ops_rejit=n/a, cpu_stock=0.03, cpu_rejit=n/a
- Note: BPF_PROG_JIT_RECOMPILE did not apply

## Comparison

- `open_latency` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `exec_trace` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `scheduler_latency` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `vfs_read_count` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `tcp_connect` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['none'], regressed=['none']. The overall geomean across scripts with stock+ReJIT data is `n/a`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

