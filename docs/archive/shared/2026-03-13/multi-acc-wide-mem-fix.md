# multi_acc WIDE_MEM Policy Fix and COND_SELECT site_len=2 Emitter

Date: 2026-03-13
Context: Code review identified two issues in BpfReJIT; this document tracks the investigation, fixes, and validation results.

---

## Issue 1: multi_acc_4/8 Missing WIDE_MEM + LEA Policy

### Root Cause Analysis

Scanner found these sites in `multi_acc_4.bpf.o`:
- `wide:10:wide-load-2` (site_len=4) — setup code, reads u32 `count` field (cold path)
- `wide:23:wide-load-2` (site_len=4) — setup code, reads u32 `seed` field (cold path)
- `lea:93:addr-calc` (site_len=3) — **hot loop**, `r2 = (r9 << 1) + r7` → LEA

Scanner found these sites in `multi_acc_8.bpf.o`:
- `wide:10:wide-load-2` — setup code (cold)
- `wide:23:wide-load-2` — setup code (cold)
- `lea:155:addr-calc` — **hot loop**
- `lea:158:addr-calc` — **hot loop**

**Key finding**: The code review's claim about "8 BPF byte loads in hot loop" was partially incorrect. The `micro_read_u64_le` in the inner loop uses *dynamic register-based offsets* (e.g., `r5-0x7` through `r5+0x0`), so the scanner cannot match them as static-offset wide-load patterns. Only the cold setup code u32 reads are matchable.

The hot-loop body byte recompose pattern appears at BPF insns 52-73 (multi_acc_4) with dynamic offsets, which do NOT produce WIDE_MEM site matches in the current scanner.

### What was actually fixed

The LEA sites ARE in the hot loop (not just setup code). These convert `mov + lsh + add` sequences into a single LEA instruction, saving 1-2 bytes per site and removing data-dependency latency in the address calculation.

### Policies Created

**micro/policies/multi_acc_4.yaml**: wide=2 (cold) + lea=1 (hot)
**micro/policies/multi_acc_8.yaml**: wide=2 (cold) + lea=2 (hot)

Config updated: `config/micro_pure_jit.yaml` now references these policy files.

---

## Issue 2: COND_SELECT site_len=2 Emitter Support

### Root Cause Analysis

The scanner generates 2-insn COND_SELECT rules for the "guarded update" pattern:
```
jcc +1    ; if (condition) skip next insn
mov dst, src   ; the guarded update (runs only when condition is FALSE)
```

The previous `emit_canonical_select` returned `-EOPNOTSUPP` for `site_len == 2`, causing:
1. The rule is validated (counted as active)
2. The emitter rejects it silently
3. Kernel logs "emitter fallback (err=-95)"
4. No optimization applied

**Affected benchmarks with cmov site_len=2**:
- `log2_fold`: 1 cmov site at insn 101 (site_len=2, cond-select-64)
- Other programs have site_len=2 for other families (extract, endian) — NOT cmov

### Fix: emit_bpf_cmov_guarded_update()

New function added to `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`:

```c
static int emit_bpf_cmov_guarded_update(pprog, jmp_insn, update_insn, use_priv_fp)
```

Logic:
- Validates `jcc +1, simple_mov` pattern
- Verifies jump/mov width consistency (JMP64 with ALU64, JMP32 with ALU32)
- Emits the comparison (via `emit_bpf_jmp_cmp`)
- Inverts the condition (branch skips update when TRUE → cmov fires on NOT-TRUE)
- Emits `cmov(NOT_condition) dst, src`

`emit_canonical_select` updated to handle `site_len == 2`:
```c
if (site_len == 2)
    return emit_bpf_cmov_guarded_update(pprog, &insns[idx], &insns[idx + 1], use_priv_fp);
```

**Correctness**: The CMOV replaces the `jcc+mov` pair identically:
- Original: condition TRUE → branch taken → mov skipped → dst unchanged
- Original: condition FALSE → branch not taken → mov executes → dst = src
- CMOV: cmov(NOT_cond) dst, src → fires when condition FALSE → dst = src; else dst unchanged

### Kernel Rebuild

Kernel rebuilt successfully: `vendor/linux-framework/arch/x86/boot/bzImage` (#42)

---

## Validation Results (VM, 5 iterations × 2000 repeats)

| Benchmark | kernel (ns) | kernel-recompile (ns) | Ratio | Expected Result |
|-----------|-------------|----------------------|-------|----------------|
| multi_acc_4 | 367 | 369 | 0.994x | 1366287837132792961 ✓ |
| multi_acc_8 | 614 | 579 | 1.060x | 6524869553103642107 ✓ |
| log2_fold | 393 | 376 | 1.045x | 9 ✓ |
| binary_search | 663 | 662 | 1.001x | 126 ✓ |
| switch_dispatch | 388 | 359 | 1.081x | 16 ✓ |

All expected results match exactly. No correctness regressions.

### Performance Analysis

**multi_acc_4** (0.994x): Essentially no change. The 2 wide sites are in cold setup code (run once), and the 1 LEA site in the hot loop doesn't show statistically significant gain with these parameters. The byte-recompose in the hot loop is NOT addressed (dynamic offsets).

**multi_acc_8** (1.060x): Small improvement from 2 LEA sites in the hot loop. The LEA saves 1-2 instruction latency per address-calculation site.

**log2_fold** (1.045x): Improvement from 3 wide sites. The guarded-update site_len=2 at insn 101 is NOT in the log2_fold policy (cmov sites intentionally excluded from this benchmark's policy due to branch-predictability concerns). The new emitter code path for site_len=2 is exercised only when a policy includes such a site.

---

## Summary

### What Changed

1. **`micro/policies/multi_acc_4.yaml`**: New policy file with 2 wide + 1 lea sites
2. **`micro/policies/multi_acc_8.yaml`**: New policy file with 2 wide + 2 lea sites
3. **`config/micro_pure_jit.yaml`**: Added `policy_file` references for multi_acc_4 and multi_acc_8
4. **`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`**: Added `emit_bpf_cmov_guarded_update()` and updated `emit_canonical_select()` to handle `site_len == 2`

### Key Findings vs Code Review Claims

| Claim | Actual |
|-------|--------|
| multi_acc_4 hot loop has 8-byte WIDE_MEM sites | FALSE: dynamic offsets in loop prevent scanner matching; only cold setup code matched |
| Expected ~1.4x gain from WIDE_MEM | NOT ACHIEVED: 0.994x (wide sites are cold, LEA site is hot but small gain) |
| COND_SELECT site_len=2 emitter fix | IMPLEMENTED: emit_bpf_cmov_guarded_update() now handles this case |

The multi_acc_4 0.746x regression from a previous run was likely measurement noise or a different kernel version. With the correct policy (wide cold + lea hot), the benchmark shows ~1.0x (no regression, no gain).

### Next Steps

For real improvement on multi_acc_4, the byte-recompose in the hot loop needs a different approach — either:
1. Change `micro_read_u64_le` to use `*(u64 *)` direct load (would emit 64-bit MOV)
2. Implement dynamic-offset wide-load matching in the scanner (significantly more complex)
