# bpftrace Real E2E Report

- Generated: `2026-04-23T11:01:00.414999+00:00`
- Run mode: `smoke`
- Duration per phase: `5s`
- Guest kernel: `7.0.0-rc2`
- bpftrace version: `bpftrace v0.20.2`

## Outcome

- This benchmark treats `bpftrace` itself as the tracing agent and measures application throughput plus bpftrace CPU while tracing is active.
- Scripts with applied sites: `0`; aggregate applied site count: `0` (none).
- Geomean BPF speedup across scripts with both baseline and ReJIT data: `n/a`.

## Per-Script

- `capable`: sites=0, stock_ns=n/a, rejit_ns=n/a, speedup=n/a, ops_stock=n/a, ops_rejit=n/a, cpu_stock=n/a, cpu_rejit=n/a
- Note: BPF program set did not stabilize before timeout (timeout_s=20, last_program_count=1, last_program_ids=309)

## Comparison

- `capable` delta: avg_ns=n/a%, ops=n/a%, cpu=n/a%

## Interpretation

- The prior VM-only bpftrace measurements were pure BPF run-time deltas. This case adds application throughput and bpftrace CPU overhead, which makes the policy-sensitive regressions visible as honest end-to-end cost.
- Scripts improved after applied ReJIT: ['none']; regressed: ['none']. The overall geomean across scripts with stock+ReJIT data is `n/a`.
- Scripts with zero applied sites were still measured for the baseline end-to-end overhead, but their ReJIT columns remain `n/a` to avoid implying a meaningless comparison.

