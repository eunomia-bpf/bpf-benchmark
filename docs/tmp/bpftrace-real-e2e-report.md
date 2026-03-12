# bpftrace Real E2E Report

- Generated: `2026-03-12T23:23:02.030969+00:00`
- Run mode: `full`
- Duration per phase: `5s`
- Guest kernel: `6.15.11-061511-generic`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with detected sites: `2`; aggregate site count: `12`.
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `n/a`.

## Per-Script

- `open_latency`: sites=6, stock_ns=147.87, rejit_ns=n/a, speedup=n/a, ops_stock=39356.29, ops_rejit=n/a, cpu_stock=0.20, cpu_rejit=n/a
- Note: BPF_PROG_JIT_RECOMPILE did not apply
- `scheduler_latency`: sites=6, stock_ns=123.38, rejit_ns=n/a, speedup=n/a, ops_stock=41.13, ops_rejit=n/a, cpu_stock=0.00, cpu_rejit=n/a
- Note: BPF_PROG_JIT_RECOMPILE did not apply

## Comparison

- `open_latency` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%
- `scheduler_latency` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Eligible CMOV-bearing scripts split by workload: improved=['none'], regressed=['none']. The overall geomean across scripts with stock+ReJIT data is `n/a`.
- Scripts with zero eligible sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

