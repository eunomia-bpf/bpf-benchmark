# Tracee E2E Post-Fix Rerun Report

- Date: 2026-03-13
- Kernel: build #39 (BEXTR without-copy fix), `vendor/linux-framework/arch/x86/boot/bzImage`
- VM: 4 CPUs, 8G memory, virtme-ng
- Output JSON: `e2e/results/tracee_authoritative_20260313_postfix.json`
- Output MD: `e2e/results/tracee-e2e-real-postfix.md`

## Key Finding: BpfReJIT Now Applies Successfully

Previous run (pre-fix, build without BEXTR fix): **0/13 programs applied** — 11 permission errors due to TMPDIR issue and/or earlier pipeline bugs.

This run (post-BEXTR-fix, build #39): **11/13 programs applied**, 0 errors.

## Baseline Results

| Workload    | App Throughput         | BPF avg_ns/run |
|-------------|------------------------|----------------|
| exec_storm  | 156.31 bogo-ops/s      | 92.47 ns       |
| file_io     | 4258.17 IOPS           | 51.06 ns       |
| network     | 4911.95 req/s          | 43.41 ns       |

## Post-ReJIT Results

| Workload    | App Throughput         | BPF avg_ns/run |
|-------------|------------------------|----------------|
| exec_storm  | 165.65 bogo-ops/s      | 85.90 ns       |
| file_io     | 4322.61 IOPS           | 50.55 ns       |
| network     | 5072.12 req/s          | 43.03 ns       |

## Comparison (post vs baseline)

| Workload   | App Throughput Δ | Events/s Δ | BPF ns Δ   | Agent CPU Δ |
|------------|-----------------|------------|------------|-------------|
| exec_storm | **+5.97%**      | +5.92%     | **-7.11%** | -0.96%      |
| file_io    | +1.51%          | +1.26%     | -1.00%     | ~0%         |
| network    | **+3.26%**      | +3.26%     | -0.87%     | +2.04%      |

## Per-Program BPF Latency (programs with run data)

| Prog ID | Name (truncated)    | Baseline (ns) | Post (ns) | Delta    |
|---------|---------------------|---------------|-----------|----------|
| 17      | tracepoint__raw     | 37.14         | 36.53     | -1.64%   |
| 21      | tracepoint__raw     | 44.99         | 44.35     | -1.43%   |
| 29      | tracepoint__sch     | 1150.71       | 1122.76   | **-2.43%** |

(10 other programs had zero run counts during workload — not executed by these workloads.)

## Assessment vs Previous Data

- Previous report showed exec_storm +21.65% **app throughput** improvement (pre-BEXTR-fix data, recompile did not actually apply).
  That number was unreliable — recompile had 0 applies.
- **This run is the first valid comparison**: recompile applied 11/13 programs.
- exec_storm: **+5.97% app throughput, -7.11% BPF ns/run** — consistent improvement.
- network: **+3.26% throughput, -0.87% BPF ns** — positive but smaller.
- file_io: small improvement (+1.51% app, -1.00% BPF ns), BPF path is not the bottleneck here.

## Summary

BpfReJIT with BEXTR fix (build #39) successfully applied to 11/13 Tracee programs in VM.
- **exec_storm**: app +5.97%, BPF -7.11% — strong signal, exec-heavy workload benefits most.
- **network**: app +3.26%, BPF -0.87% — moderate improvement.
- **file_io**: app +1.51%, BPF -1.00% — minor improvement (I/O bound, not BPF bound).
- No event drops in any phase.
- The +21.65% exec_storm figure from the previous report was from a run where recompile never applied; this replaces it with the validated +5.97% result.

## Next Steps

- Policy iteration to improve applied-only geomean (currently 11/13, 2 skipped).
- Consider additional E2E workloads beyond Tracee.
- Update plan doc with authoritative E2E numbers.
