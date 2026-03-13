# Policy Iteration Rounds — Dense Benchmark Optimization

Goal: find policy combo with applied-only geomean > 1.0x for dense benchmarks.

## Baseline Data (from micro_62bench_post_bextr_fix_20260313.json)

| Benchmark | kernel-recompile/kernel ratio | Sites | Family | Status |
|-----------|------------------------------|-------|--------|--------|
| cond_select_dense | **0.482x** | 104 cmov | COND_SELECT | Regression: predictable-branch CMOV |
| extract_dense | **0.556x** | 512 extract | BITFIELD_EXTRACT | Regression: without-copy BEXTR bug |
| endian_swap_dense | **0.695x** | 256 endian | ENDIAN_FUSION | Regression: same-size, I-cache flush |
| rotate_dense | 1.167x | ≤26 rotate | ROTATE | Positive |
| addr_calc_stride | 1.401x | ≤8 lea | ADDR_CALC | Positive |
| branch_flip_dense | 1.052x | ≤4 bflip | BRANCH_FLIP | Positive |

Geometric mean of all 6 (current policy): (0.482 × 0.556 × 0.695 × 1.167 × 1.401 × 1.052)^(1/6) ≈ **0.836x**

## Policy Analysis (Static, Based on Root Cause Investigation)

### Root Cause per Regressor

**cond_select_dense (0.482x)**
- 104 CMOV sites, all `cond-select-64` pattern
- Root cause: benchmark uses predictable branches (alternating 0/1 pattern)
- Branch predictor correctly predicts 50%+ → branch is faster than CMOV
- CMOV moves the condition into the critical path: `cmp + cmov` > `cmp + jcc` (predicted)
- Policy decision: **empty sites (skip all)** → benchmark becomes identity (1.000x)
- This IS policy-sensitivity evidence: log2_fold (unpredictable) benefits from CMOV (+28.3%)

**extract_dense (0.556x)**
- 512 BEXTR sites, all `bitfield-extract-64-shift-mask` pattern
- Root cause #1: emitter bug — `dst_reg == src_reg` guard was removed in #167 BEXTR fix
  - without-copy path now goes through BEXTR even when dst==src
  - Emits: `REG_COPY(2B) + BEXTR(7B) = 9B` vs original `SHR(3B) + AND(3B) = 6B`
  - +3B per site × 512 sites = +1536B code growth
- Root cause #2: BEXTR latency 3 cycles vs SHR+AND 2 cycles on Skylake/Alderlake
- Policy decision: **empty sites (skip all)** pending #170 emitter fix
  - After #170 fix: with-copy sites (dst≠src) should show positive (3-insn→2-insn)
  - without-copy sites (dst==src): should NOT apply BEXTR until emitter is corrected
- TODO #170: add `src_reg != dst_reg` guard in `emit_bitfield_extract_core`

**endian_swap_dense (0.695x)**
- 256 ENDIAN_FUSION sites, `endian-load-swap-32` pattern
- Root cause: MOVBE 32-bit instruction = 5 bytes = LDX(3B) + BSWAP32(2B)
  - Same code size → no code density benefit
  - Full image recompile causes I-cache flush → recompile cost > execution benefit
  - Persistent regression even with repeated runs (~0.695x stable)
- Policy decision: **empty sites (skip all)**
- ENDIAN_FUSION is policy-sensitive: beneficial only with specific CPU models or branch misprediction

### Optimal Policy (Round 1 Equivalent)

**Config**: cond_select_dense=[], extract_dense=[], endian_swap_dense=[], rotate_dense=FULL, addr_calc_stride=FULL, branch_flip_dense=FULL

**Expected ratios**:
| Benchmark | Expected ratio | Applied? |
|-----------|---------------|----------|
| cond_select_dense | ~1.000x | No (skip) |
| extract_dense | ~1.000x | No (skip) |
| endian_swap_dense | ~1.000x | No (skip) |
| rotate_dense | 1.167x | Yes |
| addr_calc_stride | 1.401x | Yes |
| branch_flip_dense | 1.052x | Yes |

Expected geomean (all 6): (1.0 × 1.0 × 1.0 × 1.167 × 1.401 × 1.052)^(1/6) ≈ **1.080x**
Expected geomean (applied only, 3 benches): (1.167 × 1.401 × 1.052)^(1/3) ≈ **1.198x**

This achieves applied-only geomean > 1.0x target.

## Files Modified

- `micro/policies/cond_select_dense.yaml` → sites: [] (was 104 CMOV sites)
- `micro/policies/extract_dense.yaml` → sites: [] (was 512 BEXTR sites)
- `micro/policies/endian_swap_dense.yaml` → sites: [] (was 256 endian sites)

Original content is recoverable from git: `git diff micro/policies/`

## Verification Needed

Run VM benchmark to confirm expected ratios:
```bash
bash docs/tmp/fix-and-run-all.sh
```

Or run just the 6 dense benches:
```bash
source /home/yunwei37/workspace/.venv/bin/activate
vng --run vendor/linux-framework/arch/x86/boot/bzImage --rwdir /home/yunwei37/workspace/bpf-benchmark -- bash -lc "
  cd /home/yunwei37/workspace/bpf-benchmark
  source /home/yunwei37/workspace/.venv/bin/activate
  python3 micro/run_micro.py \
    --runtime kernel --runtime kernel-recompile \
    --bench cond_select_dense \
    --bench extract_dense \
    --bench endian_swap_dense \
    --bench rotate_dense \
    --bench addr_calc_stride \
    --bench branch_flip_dense \
    --iterations 5 --warmups 2 --repeat 500 \
    --output docs/tmp/policy_optimized_verify.json
"
```

## Next Steps

1. **#170**: Fix `emit_bitfield_extract_core` — add `src_reg != dst_reg` guard so without-copy path uses SHR+AND
   - After fix: restore extract_dense sites (512 entries), expect ~0.9x on dense (with-copy OK, without-copy also OK)
2. **Corpus rerun**: Run `bash run_corpus_rerun.sh` with fixed packet + current policies
3. **Full 62-bench authoritative rerun**: After #170 fix, rerun all 62 benchmarks
