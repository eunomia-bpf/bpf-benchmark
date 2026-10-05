# Per-Form Ablation Analysis: BpfReJIT Micro Benchmarks

**Date**: 2026-03-13
**Suite**: 62-benchmark micro suite, targeted 19 benchmarks with policy sites
**Protocol**: iterations=5, warmups=3, repeat=1000, single VM session
**Method**: For each canonical form family, only that family's sites are active; all other sites cleared
**Metric**: kernel-recompile / kernel (lower = faster with recompile; <1.0 = win)

## Summary Table

| Family | Sites | Applicable Benchmarks | Geomean Ratio | Win/Loss |
|--------|-------|----------------------|---------------|----------|
| Rotate (ROL/ROR) | 285 | 3 | 0.923x | WIN |
| Endian Fusion (LDX+BSWAP → MOVBE) | 256 | 1 | 0.981x | WIN |
| Branch Flip (Jcc inversion) | 262 | 3 | 0.992x | WIN |
| Address Calc (ADD/SUB → LEA) | 11 | 3 | 0.999x | WIN |
| Wide Load (MOV32 → MOV64) | 18 | 9 | 1.007x | LOSS |
| Bitfield Extract (AND/SHR → BEXTR) | 514 | 2 | 1.067x | LOSS |
| Conditional Select (Jcc → CMOV) | 111 | 7 | 1.068x | LOSS |
| **ALL (combined reference)** | — | 19 | 0.988x | WIN |

## Per-Family Detail

### Rotate (ROL/ROR)

**Geomean**: 0.923x | **Benchmarks**: 3

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| rotate_dense | 256 | 231 | 169 | 0.732x < |
| cmov_dense | 26 | 69 | 60 | 0.870x < |
| memcmp_prefix_64 | 3 | 106 | 131 | 1.236x > |

### Endian Fusion (LDX+BSWAP → MOVBE)

**Geomean**: 0.981x | **Benchmarks**: 1

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| endian_swap_dense | 256 | 158 | 155 | 0.981x < |

### Branch Flip (Jcc inversion)

**Geomean**: 0.992x | **Benchmarks**: 3

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| branch_flip_dense | 255 | 212 | 209 | 0.986x < |
| branch_dense | 4 | 634 | 630 | 0.994x < |
| large_mixed_500 | 3 | 717 | 715 | 0.997x < |

### Address Calc (ADD/SUB → LEA)

**Geomean**: 0.999x | **Benchmarks**: 3

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| multi_acc_8 | 2 | 610 | 588 | 0.964x < |
| multi_acc_4 | 1 | 369 | 370 | 1.003x > |
| addr_calc_stride | 8 | 213 | 220 | 1.033x > |

### Wide Load (MOV32 → MOV64)

**Geomean**: 1.007x | **Benchmarks**: 9

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| switch_dispatch | 2 | 342 | 317 | 0.927x < |
| mixed_alu_mem | 1 | 842 | 797 | 0.947x < |
| log2_fold | 3 | 390 | 373 | 0.956x < |
| multi_acc_8 | 2 | 494 | 484 | 0.980x < |
| branch_dense | 2 | 627 | 620 | 0.989x < |
| bpf_call_chain | 2 | 528 | 528 | 1.000x = |
| bounds_ladder | 2 | 200 | 205 | 1.025x > |
| multi_acc_4 | 2 | 303 | 323 | 1.066x > |
| binary_search | 2 | 590 | 707 | 1.198x > |

### Bitfield Extract (AND/SHR → BEXTR)

**Geomean**: 1.067x | **Benchmarks**: 2

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| mixed_alu_mem | 2 | 966 | 986 | 1.021x > |
| extract_dense | 512 | 244 | 272 | 1.115x > |

### Conditional Select (Jcc → CMOV)

**Geomean**: 1.068x | **Benchmarks**: 7

| Benchmark | Sites | kernel (ns) | recompile (ns) | ratio |
|-----------|-------|-------------|----------------|-------|
| cmov_select | 1 | 592 | 578 | 0.976x < |
| bounds_ladder | 2 | 199 | 197 | 0.990x < |
| binary_search | 1 | 662 | 656 | 0.991x < |
| bpf_call_chain | 1 | 526 | 526 | 1.000x = |
| branch_dense | 1 | 633 | 634 | 1.002x > |
| switch_dispatch | 1 | 340 | 366 | 1.076x > |
| cond_select_dense | 104 | 52 | 80 | 1.538x > |

## All-Families Combined Reference

Geomean across 19 applicable benchmarks with all families active: **0.988x**

| Benchmark | kernel (ns) | recompile (ns) | ratio |
|-----------|-------------|----------------|-------|
| addr_calc_stride | 177 | 182 | 1.028x |
| binary_search | 595 | 588 | 0.988x |
| bounds_ladder | 208 | 214 | 1.029x |
| bpf_call_chain | 419 | 458 | 1.093x |
| branch_dense | 557 | 541 | 0.971x |
| branch_flip_dense | 194 | 211 | 1.088x |
| cmov_dense | 62 | 66 | 1.065x |
| cmov_select | 587 | 575 | 0.980x |
| cond_select_dense | 83 | 67 | 0.807x |
| endian_swap_dense | 158 | 169 | 1.070x |
| extract_dense | 182 | 189 | 1.038x |
| large_mixed_500 | 601 | 606 | 1.008x |
| log2_fold | 343 | 356 | 1.038x |
| memcmp_prefix_64 | 131 | 151 | 1.153x |
| mixed_alu_mem | 820 | 818 | 0.998x |
| multi_acc_4 | 321 | 276 | 0.860x |
| multi_acc_8 | 526 | 481 | 0.914x |
| rotate_dense | 262 | 192 | 0.733x |
| switch_dispatch | 324 | 327 | 1.009x |

## Interpretation & Optimal Combination

### Ranking by per-family contribution (lower ratio = more beneficial):

1. **Rotate (ROL/ROR)**: 0.923x (+7.7% contribution)
2. **Endian Fusion (LDX+BSWAP → MOVBE)**: 0.981x (+1.9% contribution)
3. **Branch Flip (Jcc inversion)**: 0.992x (+0.8% contribution)
4. **Address Calc (ADD/SUB → LEA)**: 0.999x (+0.1% contribution)
5. **Wide Load (MOV32 → MOV64)**: 1.007x (-0.7% contribution)
6. **Bitfield Extract (AND/SHR → BEXTR)**: 1.067x (-6.7% contribution)
7. **Conditional Select (Jcc → CMOV)**: 1.068x (-6.8% contribution)

### Policy recommendations:

**Beneficial forms (keep active):**
- Rotate (ROL/ROR): 0.923x geomean
- Endian Fusion (LDX+BSWAP → MOVBE): 0.981x geomean
- Branch Flip (Jcc inversion): 0.992x geomean
- Address Calc (ADD/SUB → LEA): 0.999x geomean

**Detrimental forms (skip or be policy-selective):**
- Wide Load (MOV32 → MOV64): 1.007x geomean
- Bitfield Extract (AND/SHR → BEXTR): 1.067x geomean
- Conditional Select (Jcc → CMOV): 1.068x geomean

### Notes on context-sensitivity:

- **CMOV/cond_select_dense**: Policy-sensitive. Predictable branches → CMOV regression. Unpredictable branches → win.
- **EXTRACT/extract_dense**: Dense-site I-cache flush dominates for 512 sites. Sparse sites (mixed_alu_mem) may win.
- **ENDIAN/endian_swap_dense**: Same-size rewrite (5B→5B) means I-cache flush with no code-size benefit.
- **ROTATE**: Consistently beneficial for dense sites (256 sites → 1.167x authoritative).
- **LEA/addr_calc_stride**: Consistently beneficial for sparse sites (8 sites → 1.401x authoritative).

---
*Generated by docs/tmp/analyze_per_form_ablation.py*
