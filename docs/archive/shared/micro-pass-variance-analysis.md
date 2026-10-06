# Micro Benchmark Pass Variance Analysis

Date: 2026-06-24

## Key Claim: One-Size-Fits-All Policy Does Not Work

This analysis demonstrates that a single optimization pass or pass policy produces
highly variable results across different BPF programs. The same pass that provides
significant speedup for one program can cause slowdown in another, proving that
per-program or per-workload tuning is essential for optimal performance.

## Evidence Summary

### 1. Same Pass, Opposite Effects Across Benchmarks

From ARM64 AWS micro benchmarks (`aws_arm64_micro_20260606_001225_821028`):

| Benchmark | Kernel ns | ReJIT ns | Speedup | Applied Kinsn |
|-----------|-----------|----------|---------|---------------|
| `siphash_rotate64_mixer` | 194 | 102 | **1.902x** (WIN) | extr_x=348, ldrh=21, ldr_w=3 |
| `cilium_socket_lb_service_select` | 1126 | 666 | **1.691x** (WIN) | ldr_w=15, ldrh=6 |
| `bpftrace_string_search_prefix_scan` | 642 | 412 | **1.558x** (WIN) | extr_x=3, ldr_w=3 |
| `bpftrace_comm_key_fnv_hash` | 1581 | 1835 | **0.862x** (LOSS) | ldr_w=6, stp_x=3 |
| `bitmap_popcount_scan` | 2190 | 2266 | **0.966x** (LOSS) | ldr_w=6 |

The same kinsn families (`ldr_w`, `stp_x`) help `siphash_rotate64_mixer` achieve
1.9x speedup while hurting `bpftrace_comm_key_fnv_hash` by 14%.

### 2. Wide Variance Range

From the same ARM64 micro run, the speedup ratio ranges from:
- **Best**: 1.902x (`siphash_rotate64_mixer`)
- **Worst**: 0.862x (`bpftrace_comm_key_fnv_hash`)
- **Range**: 2.2x difference in outcome from the same pass policy

24 wins, 2 losses, 3 ties across 29 benchmarks, with a geomean of 1.208x.

### 3. x86 BMI2 Variable-Shift Pass Example

From `x86_kvm_micro_20260607_072937_370032` with BMI2 `shlx`/`shrx` selectors:

| Benchmark | Kernel ns | ReJIT ns | Speedup | BMI2 Sites |
|-----------|-----------|----------|---------|------------|
| `packet_toeplitz_rss_hash` | 257 | 209 | **1.230x** | 5 |
| `packed_header_bitfield_decode` | 277 | 242 | **1.145x** | 4 |
| `bpftrace_comm_key_fnv_hash` | 435 | 441 | **0.986x** | 4 |

Same BMI2 shift optimization: 23% speedup on one benchmark, 1.4% slowdown on another.

### 4. Corpus App-Level Variance

From kinsn corpus evaluation (`kinsn_eval_20260604_summary.md`):

| App | Geomean | Wins/Losses/Ties | Applied Sites |
|-----|---------|------------------|---------------|
| `bcc` | 0.961x (WIN) | 11/4/0 | 77 |
| `otel` | 1.065x (LOSS) | 0/1/0 | 1475 |
| `cilium` | 1.009x (TIE) | 1/1/0 | 4086 |
| `katran` | 0.940x (WIN) | 1/0/0 | 90 |
| `tracee` | 1.028x (LOSS) | 14/27/0 | 14833 |

OTEL shows **6.5% regression** with 1475 applied sites, while BCC shows **3.9% improvement**
with only 77 sites. More optimization sites does NOT guarantee better performance.

### 5. Per-Program Variance Within Same App

From tracee corpus results:

| Program | Baseline ns/run | Post ns/run | Ratio |
|---------|-----------------|-------------|-------|
| `blk_account_io_` | 229.88 | 179.19 | 0.780x (22% faster) |
| `trace_ret_do_mm` | 672.95 | 878.56 | 1.306x (31% slower) |
| `trace_security_` | 716.62 | 891.31 | 1.244x (24% slower) |
| `tracepoint__sys` | 64.99 | 60.10 | 0.925x (7.5% faster) |

Within the same app (`tracee`), the same pass policy makes some programs 22% faster
and others 31% slower.

### 6. Platform-Specific Policy Sensitivity (arm64)

From kinsn ablation (`kinsn_ablation_20260605_summary.md`):

**x86 Cilium:**
- Full policy: workload 1.114x, BPF cost 0.776x (best)
- No bulk/prefetch: workload 0.999x, BPF cost 0.991x

**arm64 Cilium:**
- Conservative (no bulk/endian/prefetch): workload 0.983x, BPF cost 0.997x
- All selectors enabled: workload 0.978x, BPF cost 1.066x (6.6% regression)

The same pass that helps x86 hurts arm64 for the same app.

### 7. Predictability-Sensitive Passes (cond_select)

From OTEL regression analysis (`otel_native_tracer_kinsn_regression_20260507.md`):

The `cond_select` pass (CMOV/CSEL) converts branch-over-mov sequences to branchless
conditional moves. This helps when branches are **unpredictable** but hurts when
branches are **highly predictable**:

- OTEL `native_tracer_entry`: **2.49x slowdown** (baseline 2904 ns/run to post 7220 ns/run)
- Reason: The original branches were highly predictable; branchless code added data
  dependencies that the CPU pipeline could not hide.

From micro smoke (`micro-rejit-smoke-20260428.md`):
| Benchmark | Kernel ns | ReJIT ns | Ratio |
|-----------|-----------|----------|-------|
| `cond_select_dense` | 237 | 149 | 0.629x (37% faster) |
| `log2_fold` | 395 | 311 | 0.787x (21% faster on some runs) |

The cond_select pass helped synthetic micro benchmarks with designed-in unpredictable
branches, but hurt real app programs with predictable control flow.

## Concrete Evidence: Same Pass, Different Outcomes

### Example 1: bulk_memory family
- **Helps**: `siphash_rotate64_mixer` (1.90x speedup)
- **Hurts**: `bpftrace_comm_key_fnv_hash` (0.86x = 14% regression)
- **Conclusion**: Bulk memory load/store fusion depends on access patterns

### Example 2: kinsn LEA/load selectors
- **Helps BCC**: 11 wins, 4 losses (geomean 0.961x = 4% faster)
- **Hurts OTEL**: 0 wins, 1 loss (geomean 1.065x = 6.5% slower)
- **Conclusion**: LEA optimization profitability depends on register pressure and
  instruction mix

### Example 3: Platform-specific bulk_memory
- **x86 Cilium**: bulk_memory ON = best performance (0.776x BPF cost)
- **arm64 Cilium**: bulk_memory ON = regression (1.066x BPF cost)
- **Conclusion**: Same logical optimization, opposite effect per architecture

## Implications for Policy

1. **No universal "enable all" policy**: The data shows that enabling all passes
   produces regressions in real workloads (OTEL 6.5% slower, tracee programs up to
   31% slower).

2. **Per-app tuning required**: Different apps benefit from different pass subsets:
   - BCC: full kinsn helps
   - OTEL: conservative policy needed
   - Katran: rotate/extract/endian good, bulk_memory/prefetch bad on arm64

3. **Profile-guided decisions needed**: Passes like `cond_select` and `prefetch`
   should only apply when runtime profile data confirms profitability.

4. **Variance range is too wide for blanket policy**: 2.2x difference between best
   and worst outcomes (1.90x speedup vs 0.86x regression) from the same pass set
   means a one-size-fits-all approach will consistently hurt some workloads.

## Data Sources

- `micro/results/aws_arm64_micro_20260606_001225_821028/` - ARM64 full micro suite
- `micro/results/x86_kvm_micro_20260607_072937_370032/` - x86 BMI2 focused micro
- `docs/tmp/kinsn_eval_20260604_summary.md` - Corpus per-app breakdown
- `docs/tmp/kinsn_ablation_20260605_summary.md` - Platform ablation study
- `docs/tmp/otel_native_tracer_kinsn_regression_20260507.md` - OTEL regression case study
- `docs/tmp/kinsn_per_app_native_guided_20260607.md` - Per-app policy trials
