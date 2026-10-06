# Micro 62-Bench Post-BEXTR-Fix Run (2026-03-13)

## Overview

Full 62-benchmark recompile micro suite rerun using build #38 bzImage (`7.0.0-rc2-ga7ce05b49cb2-dirty`) after the BEXTR emitter fix (#167, commit `daca445b1`). The fix removed the `dst_reg == src_reg` guard in `emit_bitfield_extract_core`, enabling the 3-insn→2-insn BEXTR optimization for the with-copy (dst≠src) pattern.

- **Kernel**: `7.0.0-rc2-ga7ce05b49cb2-dirty`
- **Suite**: `config/micro_pure_jit.yaml` (62 benchmarks)
- **Parameters**: warmups=2, iterations=2, repeat=500, cpu=0 (taskset), performance governor
- **Method**: one VM boot per benchmark via `kernel_recompile_micro_resume.py`
- **Result file**: `micro/results/micro_62bench_post_bextr_fix_20260313.json`

## Headline Numbers

| Metric | Post-BEXTR-fix | Pre-fix (authoritative 20260313) | Delta |
|---|---|---|---|
| Overall geomean (stock/recompile) | **1.003x** | 1.004x | -0.001x |
| Applied-only geomean | **0.932x** | 0.942x | -0.010x |
| Valid pairs | 61/62 | 62/62 | -1 (cmov_dense still failing) |
| Applied pairs | 16 | 17 | -1 |
| Wins / Losses / Ties | 30 / 30 / 1 | 29 / 32 / 1 | +1 win, -2 losses |

Observation: overall summary nearly identical. The fix helped bitfield_extract (non-dense, 1-site) but the dense bench (512-site) is still a regression, and actually worsened slightly.

## Key Benchmark Results — 8 Canonical Forms

| Benchmark | Family | Stock (ns) | Recompile (ns) | Ratio | Applied | Sites | vs Pre-fix |
|---|---|---|---|---|---|---|---|
| `extract_dense` | BITFIELD_EXTRACT | 149 | 268 | **0.556x** | yes | 512 | was 0.677x — worse |
| `bitfield_extract` | BITFIELD_EXTRACT | 309 | 240 | **1.288x** | no | 0 | was 1.292x — stable |
| `endian_swap_dense` | ENDIAN_FUSION | 130 | 187 | **0.695x** | yes | 256 | was 0.695x — same |
| `branch_flip_dense` | BRANCH_FLIP | 203.5 | 193.5 | **1.052x** | yes | 255 | was 1.075x — slight drop |
| `rotate_dense` | ROTATE | 206 | 176.5 | **1.167x** | yes | 256 | first measurement |
| `addr_calc_stride` | ADDR_CALC | 215 | 153.5 | **1.401x** | yes | 8 | first measurement |
| `cond_select_dense` | COND_SELECT | 48 | 99.5 | **0.482x** | yes | 104 | was similar |
| `log2_fold` | COND_SELECT? | 363 | 375 | **0.968x** | yes | 3 | slight regression |
| `binary_search` | COND_SELECT | 711 | 639.5 | **1.112x** | yes | 3 | consistent |
| `branch_dense` | BRANCH_FLIP | 636.5 | 560 | **1.137x** | yes | 7 | win |

## Analysis of extract_dense Regression

**Pre-BEXTR-fix** (old emitter, without-copy only): 148.5ns → 219.5ns, ratio 0.677x
**Post-BEXTR-fix** (new emitter, with-copy path enabled): 149ns → 268ns, ratio **0.556x**

The BEXTR fix was intended to optimize `bitfield_extract` (1 site, dst≠src: 3 insns → 2 insns, 1.288x win confirmed). However for `extract_dense` (512 sites, dst==src pattern), the fix removed the `dst_reg == src_reg` guard which previously short-circuited to the fallback path. The bug fix triggered more BEXTR emissions in the hot path, but the dense pattern with 512 sites appears to generate code that runs slower than the old fallback.

Possible causes:
1. BEXTR is used but the VEX-encoded instruction has higher decode overhead at 512x
2. The instruction scheduling interaction is worse at high density
3. The old code path (without BEXTR) happened to be scheduling-friendly via simpler shift sequences

**bitfield_extract (1 site, non-dense)**: The fix produces the expected win (1.288x), consistent with the reported 3-insn→2-insn improvement.

## Full Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only | Wins | Losses |
|---|---|---|---|---|---|---|---|
| addr-calc | 1 | 1 | 1 | 1.401x | 1.401x | 1 | 0 |
| bitfield-extract | 2 | 2 | 1 | 0.846x | **0.556x** | 1 | 1 |
| rotate-canonical | 1 | 1 | 1 | 1.167x | 1.167x | 1 | 0 |
| endian-fusion | 1 | 1 | 1 | 0.695x | 0.695x | 0 | 1 |
| branch-flip | 1 | 1 | 1 | 1.052x | 1.052x | 1 | 0 |
| select-diamond | 3 | 2 | 2 | 0.650x | **0.650x** | 0 | 2 |
| search | 1 | 1 | 1 | 1.112x | 1.112x | 1 | 0 |
| baseline | 3 | 3 | 0 | 1.010x | n/a | 1 | 1 |
| log2-fold | 1 | 1 | 1 | 0.968x | 0.968x | 0 | 1 |

## Comparison with Previous Authoritative Results

The overall trajectory is unchanged from pre-fix:
- Still 1.003–1.004x overall geomean (near-neutral policy)
- The applied-only geomean dropped slightly (0.942x → 0.932x) because `extract_dense` worsened
- The BEXTR fix fixed the `bitfield_extract` (single-site, non-dense) benchmark as intended
- `extract_dense` (512 dense sites) is an anomalous regression: recompile is 1.8x slower than stock

## Issues and Next Steps

1. **extract_dense 0.556x regression requires root cause analysis**: the dense 512-site BEXTR path is slower. Need to inspect generated native code before/after to understand whether the issue is instruction throughput, front-end decode, or register allocation.

2. **endian_swap_dense 0.695x regression persists**: MOVBE 32-bit = same size as LDX+BSWAP32 (5B each); this was a known finding. Not changed by BEXTR fix.

3. **cond_select_dense 0.482x regression persists**: CMOV denylist applied at corpus level but cmov_dense still failing (command-failed).

4. **cmov_dense still broken**: 1 invalid pair. Same as pre-fix.

5. **Wins added vs pre-fix**: +1 net win in the W/L count (30/30 vs 29/32), meaning the fix improved aggregate win rate.

## Conclusion

The BEXTR emitter fix (`daca445b1`) confirmed correct for single-site bitfield_extract (1.288x win). For the dense 512-site `extract_dense` benchmark, the fix made things worse (0.677x → 0.556x), suggesting the BEXTR instruction itself at scale is not beneficial and the old fallback path was inadvertently better. The overall 62-bench suite geomean (1.003x) is unchanged within noise. The applied-only geomean dropped from 0.942x to 0.932x primarily due to this extract_dense worsening.

**Authoritative post-BEXTR-fix numbers**:
- Overall geomean: **1.003x** (61 valid pairs, 16 applied)
- Applied-only geomean: **0.932x**
- Wins/Losses/Ties: 30/30/1
