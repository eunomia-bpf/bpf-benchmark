# Per-Form Isolation Benchmark: Correct Policy Re-run

**Date**: 2026-03-12
**Purpose**: Re-run 6 per-form isolation benchmarks with corrected per-benchmark policies (precise insn offsets), replacing the previous broken aggregate per_family policy run.

## Summary

All **6/6** benchmarks successfully applied (previously only 3/6 applied due to insn offset mismatch in aggregate policy).

| Benchmark | Form | Sites Applied | Stock (ns) | Recompile (ns) | Ratio | Result |
|---|---|---|---|---|---|---|
| cond_select_dense | COND_SELECT / cmov | 104 | 124.0 | 101.0 | **0.815x** | speedup |
| rotate_dense | ROTATE | 256 | 266.0 | 172.5 | **0.648x** | speedup |
| addr_calc_stride | ADDR_CALC / lea | 8 | 160.0 | 166.5 | 1.041x | regression |
| extract_dense | BITFIELD_EXTRACT | 512 | 164.0 | 170.0 | 1.037x | regression |
| endian_swap_dense | ENDIAN_FUSION | 256 | 211.0 | 199.5 | **0.945x** | speedup |
| branch_flip_dense | BRANCH_FLIP | 255 | 239.0 | 239.5 | 1.002x | neutral |

**Speedups**: rotate_dense (35.2%), cond_select_dense (18.5%), endian_swap_dense (5.5%)
**Regressions**: addr_calc_stride (+4.1%), extract_dense (+3.7%)
**Neutral**: branch_flip_dense (+0.2%)

## Kernel Limit Increase Required

The first run (without limit increase) failed for 2 benchmarks due to kernel hardcoded limits:

- `extract_dense`: 512 sites → exceeded `BPF_JIT_MAX_RULES = 256` **and** blob > 64KB
- `branch_flip_dense`: 255 sites → blob size 76532 bytes exceeded `BPF_JIT_DIRECTIVES_MAX_BLOB_SIZE = SZ_64K = 65536`

**Fix**: Increased limits in `vendor/linux-framework/kernel/bpf/jit_directives.c`:
- `BPF_JIT_DIRECTIVES_MAX_BLOB_SIZE`: SZ_64K → SZ_512K
- `BPF_JIT_MAX_RULES`: 256 → 1024

Kernel rebuilt (build #36) and all 6 benchmarks ran successfully.

## Policy Files Used

All policies are version 3 (per-site directive list, precise insn offsets from scanner):

| Policy File | Program | Sites | Family |
|---|---|---|---|
| micro/policies/cond_select_dense.yaml | cond_select_dense_xdp | 104 | cmov |
| micro/policies/rotate_dense.yaml | rotate_dense_xdp | 256 | rotate |
| micro/policies/addr_calc_stride.yaml | addr_calc_stride_xdp | 8 | lea |
| micro/policies/extract_dense.yaml | extract_dense_xdp | 512 | extract |
| micro/policies/endian_swap_dense.yaml | endian_swap_dense_xdp | 256 | endian |
| micro/policies/branch_flip_dense.yaml | branch_flip_dense_xdp | 255 | branch-flip |

## Interpretation

### Winners
- **ROTATE** (0.648x): Strong 35% speedup. 256 rotate sites with proper RORX emission is clearly beneficial.
- **COND_SELECT / cmov** (0.815x): 18.5% speedup. Note: this contradicts corpus results where cmov was net-negative. The isolated dense benchmark shows cmov *is* beneficial when the branch pattern truly isolates select diamonds.
- **ENDIAN_FUSION** (0.945x): 5.5% speedup. Endian fusion optimization working as expected.

### Neutrals/Regressions
- **BRANCH_FLIP** (1.002x): Essentially neutral — branch flip doesn't help/hurt on this VM.
- **ADDR_CALC / LEA** (1.041x): Small regression. Only 8 sites — low statistical weight, possibly measurement noise. The LEA optimization may not benefit this access pattern.
- **BITFIELD_EXTRACT** (1.037x): Small regression with 512 sites. Bitfield extract optimization is not beneficial for this dense packed-word extraction pattern.

### Note on CMOV vs Corpus
The cond_select_dense speedup (0.815x) contrasts with corpus-level cmov results (0.906x without cmov = cmov net-negative). This is expected: the isolated benchmark tests *only* select-diamond patterns, while corpus programs have mixed code where cmov can hurt branch prediction on other patterns.

## Data File
`docs/tmp/per-form-rerun-correct-policy.json`

## Run Parameters
- VM: vendor/linux-framework bzImage (build #36, with raised limits)
- `--iterations 2 --warmups 2 --repeat 500`
- Runtimes: kernel, kernel-recompile
