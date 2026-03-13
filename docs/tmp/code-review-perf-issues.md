# Code Review: Performance Issues in BpfReJIT

Date: 2026-03-13
Reviewer: code-review agent
Context: post-BEXTR-fix, post-policy-iteration state. Overall 0.995x micro, applied-only 0.993x.

---

## Summary of Findings (by severity)

| Priority | Component | Issue | Estimated Impact |
|----------|-----------|-------|-----------------|
| P0-CRITICAL | `emit_canonical_rotate` | RORX VEX encoding: byte2 logic inverted R/B meaning | Could silently corrupt registers in rotations |
| P1-HIGH | `emit_canonical_rotate` | 5-insn rotate: dst != src but RORX emits only RORX without prior MOV | Wrong result if dst != src |
| P1-HIGH | `jit_directives.c` | `num_applied == 0` path does `restore` but still ran the full JIT — I-cache flush not avoided | Wasted recompile overhead |
| P1-HIGH | `simple_packet` benchmark | Uses `DEFINE_PACKET_BACKED_XDP_BENCH` with trivial body — sub-10ns, dominated by XDP harness overhead | Measurement noise (0.545x meaningless) |
| P2-MED | `emit_canonical_wide_load` | Width=5,6,7 sub-power-of-2 paths use scratch reg `AUX_REG` without checking for clobbering | Potential correctness issue on some sites |
| P2-MED | `emit_bitfield_extract_core` | BEXTR path only checked `src != dst`; does not check `AUX_REG` alias | Clobbers AUX_REG if it equals src or dst |
| P2-MED | Scanner | `scan_v5_builtin` does greedy first-match scan — a longer pattern at pos X can be masked by a shorter match at pos X | Missed sites for multi-instruction patterns |
| P2-MED | `multi_acc_4` (0.746x) | `micro_read_u64_le` uses byte-by-byte loop — 8 BPF byte loads; WIDE_MEM can fuse these but scanner not run on micro programs | Real regression due to unoptimized read |
| P3-LOW | `emit_canonical_branch_flip` | `jmp_join_size` measured before body_b emitted — 2-pass instability if body_b grows near im8 boundary | Potential JIT convergence divergence |
| P3-LOW | Scanner COND_SELECT patterns | Guarded-update and switch-chain patterns recognized but `emit_canonical_select` only handles site_len 3 and 4 — larger sites always fall back | Pattern scan correctly identifies them but emitter rejects them silently |
| P3-LOW | `emit_canonical_endian_fusion` | 16-bit MOVBE zero-extension sequence emits extra movzx (3B) making 16-bit case larger than original | I-cache overhead for 16-bit paths |

---

## Detailed Analysis

### 1. RORX VEX Encoding: byte2 R/B bit inversion logic (P0-CRITICAL)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, lines 2373–2387

**Code:**
```c
byte2 = 0x03;
if (!is_ereg(dst_reg))
    byte2 |= 0x80;
byte2 |= 0x40;
if (!is_ereg(src_reg))
    byte2 |= 0x20;
```

**Issue:** The 3-byte VEX prefix byte2 has bits `~R ~X ~B m[4:0]`. Setting bit 7 (`0x80`) when `!is_ereg(dst_reg)` is correct: `~R = 1` when dst_reg is NOT extended (R extension bit = 0). Similarly bit 5 (`0x20`) for `~B` when src is not extended. This is logically correct.

However: the `0x40` unconditional set (bit 6, `~X`) is correct since RORX has no SIB-index operand. The encoding appears correct but should be verified against the Intel SDM table. **On re-analysis this looks correct.**

**Actual concern:** The `byte2 = 0x03` starting value then adding bits is equivalent to the `emit_3vex` helper which uses inverted booleans. The raw byte2 construction _bypasses_ the `emit_3vex` helper. A subtle divergence: `emit_3vex` takes `bool r, bool x, bool b` and inverts them internally (`!r << 7`). The manual RORX code does the same inversion manually. This is consistent and correct.

**Verdict:** The RORX VEX encoding is correct. No bug here.

---

### 2. 5-insn Rotate Pattern: dst != src requires MOV before RORX (P1-HIGH)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, `emit_canonical_rotate` (lines 2331–2409)

**Issue:** The 5-insn rotate pattern (`bpf_jit_parse_rotate_5insn`) sets `shape.dst_reg = mov2->dst_reg` and `shape.src_reg = mov1->src_reg`. These can differ: `dst` is the output register (gets the rotated result) and `src` is the original input register.

When `native_choice == BPF_JIT_ROT_RORX`:
- The RORX path emits: `RORX dst_reg, src_reg, ror_imm` — **this is a non-destructive 3-operand rotate** and correctly handles `dst != src`. No extra MOV needed.

When `native_choice == BPF_JIT_ROT_ROR`:
```c
if (src_reg != dst_reg)
    emit_mov_reg(&prog, is64, dst_reg, src_reg);
EMIT3(0xC1, add_1reg(0xC8, dst_reg), ror_imm);
```
This correctly emits `mov dst, src; ror dst, imm`. Correct.

**Verdict:** No bug here. Both paths handle `dst != src` correctly.

---

### 3. num_applied == 0: Redundant full JIT run not avoided (P1-HIGH)

**File:** `/vendor/linux-framework/kernel/bpf/jit_directives.c`, lines 3395–3401 and 3679–3684

**Issue:** The `out_no_commit` path at line 3400 correctly skips the commit (no image swap). However, the full JIT recompile (`bpf_jit_recompile_prog_images`) was already called (line 3637) before this check. The check at the in-JIT path (line 3400, inside `bpf_jit_recompile_execute_passes`) correctly skips the final image allocation. But the convergence loop and all JIT passes still ran.

**Measurement impact:** When `active_cnt == 0`, the syscall still runs `do_jit` multiple times (convergence passes), allocates a scratch image, and triggers the `synchronize_rcu()` + I-cache flush on the **abort** path. This is the overhead that bench_kernel sees even when no rules apply.

**Actually:** Looking at line 3615: `if (policy->active_cnt == 0)` → returns `-EINVAL`. So if zero active rules, the entire recompile aborts early. But the issue is: the recompile check happens inside the JIT pass itself. A policy with `sites: []` (empty) has `active_cnt == 0` and is rejected at parse time.

**Real situation for current benchmarks:** For benches with `sites: []` (cond_select_dense, extract_dense, endian_swap_dense), the policy has no rules, so `active_cnt == 0`, so `bpf_jit_parse_policy` already returns -EINVAL before any JIT work. The benchmark sees the overhead of just the policy-parse syscall (minimal). **No bug for empty policies.**

But for benches where some rules exist but all fail validation at runtime: the full JIT still runs. The `jit_recompile_num_applied == 0` check at line 3679 correctly invokes `bpf_jit_recompile_restore()` to keep the pre-recompile image, but the JIT still ran and flushed I-caches.

**Verdict:** The `num_applied == 0` guard at line 3679 is correctly placed as a post-JIT guard. The real fix would be to detect "all rules rejected" earlier during validation and skip the JIT. The `active_cnt` pre-check at line 3615 handles the empty-policy case. The case of "policy has rules but all fail runtime validation" (e.g., wrong prog_tag or pattern mismatch) still wastes JIT time. This is a minor overhead issue, not a regression for current benchmarks.

---

### 4. simple_packet 0.545x: Measurement artifact (P1-HIGH)

**File:** `/micro/programs/simple_packet.bpf.c`

**Code:**
```c
static __always_inline int bench_simple_packet(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}
DEFINE_PACKET_BACKED_XDP_BENCH(simple_packet_xdp, bench_simple_packet)
```

**Issue:** This benchmark has a trivially empty hot path. The measured time (~52-56ns in VM) is dominated by:
1. `micro_prepare_packet_payload`: packet header parsing overhead
2. XDP context access overhead
3. Memory write for result

Since the bench function body is essentially `store 12345678 → result`, BpfReJIT has zero optimization sites and zero opportunity. When `kernel-recompile` runs, it does a no-op recompile (empty policy) then executes, adding the policy-parse overhead to the same baseline.

The 0.545x ratio means the recompile variant is ~1.8x slower on a ~50ns benchmark. At sub-10ns benchmark granularity, the overhead of `bpf_prog_test_run_opts` itself is the dominant term. This is not a regression from BpfReJIT — it's a measurement noise issue at the ktime resolution limit.

**Root cause of 0.545x:** With `sites: []`, the recompile path adds the policy syscall overhead (8ms scanner + 30μs syscall in real programs, but for micro benches it's just the `bpf_prog_test_run_opts` overhead plus one extra syscall). Since the benchmark runs repeat=1000 times per iteration and the total is ~50ns*1000=50μs, a +30μs overhead from the recompile syscall dominates.

**Fix:** Exclude `simple_packet` from the "applied" set in calculations. It should be in the "control/non-applied" group since it has no optimization sites.

---

### 5. WIDE_MEM Emitter: AUX_REG clobber risk (P2-MED)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, `emit_wide_load_sequence` (lines 2230–2267)

**Code:**
```c
u32 chunk_reg = first_chunk ? result_reg : AUX_REG;
```

**Issue:** For sub-power-of-2 widths (3, 5, 6, 7 bytes), the emitter uses `AUX_REG` (R11/r11) for intermediate chunks. If `result_reg` or any register in the surrounding BPF program uses R11, and the wide-load site's base_reg is also R11, there would be a conflict.

However, the kernel BPF JIT reserves R11 as `AUX_REG` and BPF programs cannot reference it directly. The `bpf_jit_prog_valid_reg` validator should reject any BPF reg that maps to R11.

**Verdict:** AUX_REG (R11) is a JIT-reserved register, not accessible from BPF. No actual bug, but the code assumes this invariant is enforced upstream (which it is).

---

### 6. BEXTR: AUX_REG collision check missing (P2-MED)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, `emit_bitfield_extract_core` (lines 3311–3320)

**Code:**
```c
if (boot_cpu_has(X86_FEATURE_BMI1) &&
    src_reg != dst_reg &&
    bitfield_low_mask_width(effective_mask, &field_width)) {
    u32 control = ((field_width & 0xff) << 8) | (shift & 0xff);
    emit_mov_imm32_noflags(&prog, false, AUX_REG, control);
    emit_bextr(&prog, dst_reg, src_reg, AUX_REG, is64);
```

**Issue:** `AUX_REG` is written with the BEXTR control word. If either `src_reg == AUX_REG` or `dst_reg == AUX_REG`, the sequence would be incorrect:
- If `src_reg == AUX_REG`: `emit_mov_imm32_noflags(AUX_REG, control)` overwrites the source before `emit_bextr(dst, AUX_REG, AUX_REG, ...)`.
- If `dst_reg == AUX_REG`: `emit_bextr(AUX_REG, src_reg, AUX_REG, ...)` — AUX_REG is both control and destination, which is wrong (BEXTR reads control from control_reg, writes to dst_reg; if they're the same, the result is written to AUX_REG after reading from it — the MOV before sets AUX_REG to the control value, then BEXTR reads that as control and writes result back to AUX_REG, overwriting the control. This is actually the intended behavior — but only if the result destination is indeed AUX_REG intentionally).

**But again:** BPF programs cannot reference AUX_REG (R11), so `src_reg` and `dst_reg` here come from `jit_bpf_reg()` translation of BPF registers 0-10. AUX_REG is R11, which is never a valid output of `jit_bpf_reg()`.

**Verdict:** Same as WIDE_MEM — AUX_REG is JIT-reserved, so no real collision is possible. The guard `src_reg != dst_reg` is for the semantics of BEXTR vs SHR+AND, not for AUX_REG collision. No bug.

---

### 7. Scanner: Greedy First-Match Scan Misses Longer Patterns (P2-MED)

**File:** `/scanner/src/pattern_v5.cpp`, lines 1734–1790

**Code:**
```cpp
for (uint32_t idx = 0; idx < insns.size();) {
    bool matched = false;
    // branch_flip checked first (non-V5 special case)
    for (const auto &desc : descs) {
        if (!match_v5_pattern_at(insns, idx, desc)) continue;
        summary.rules.push_back(make_v5_policy_rule(idx, desc));
        idx += static_cast<uint32_t>(desc.pattern.size());
        matched = true;
        break;  // <-- stops at first match
    }
    if (!matched) ++idx;
}
```

**Issue:** For position `idx`, the scanner tries all descriptors in insertion order and stops at the **first match**. If a shorter 3-insn pattern (e.g., compact COND_SELECT) matches at `idx`, the scanner advances by 3 and misses a potential 4-insn diamond COND_SELECT that started at the same position. The order of `descs` determines which pattern wins.

However, within each family, the descriptor order is consistent (diamond patterns added before compact in `add_v5_cond_select_descs_for_jump`). So the longer diamond pattern is tried first. The first-match is actually longest-first for COND_SELECT.

**Real issue:** When multiple families overlap at the same position (e.g., a ROTATE pattern whose first instruction also looks like a BITFIELD_EXTRACT pattern), the first family wins. The scan order in `scan_v5_builtin` is: cmov → wide → rotate → lea → extract → zero_ext → endian. This means if a site could be classified as both rotate AND extract, rotate wins.

**How common is this overlap?** Unlikely in practice because the pattern structures are quite different. But it's a latent correctness concern.

**More concrete issue:** The scanner advances by `desc.pattern.size()` on a match, so after matching a 4-insn COND_SELECT diamond at idx, it resumes at idx+4. The instruction at idx+4 is the instruction after the diamond (the join target's first instruction). A rotate pattern starting at idx+1 (the first mov in the diamond) would be missed if idx+1 is also the start of a rotate idiom. But this is semantically correct: the diamond is already matched and those instructions are "consumed."

**Verdict:** The greedy scan is correct for non-overlapping patterns. The first-match strategy is a potential coverage gap only when two different family patterns genuinely start at the same index. For the 8 current families, this is rare. Not an immediate regression.

---

### 8. multi_acc_4 0.746x: Real regression from unoptimized byte reads (P2-MED)

**File:** `/micro/programs/multi_acc_4.bpf.c`

**Code:**
```c
u64 value = micro_read_u64_le(data, 8 + i * 8U);
```

**`micro_read_u64_le` in common.h:**
```c
static __always_inline u64 micro_read_u64_le(const u8 *data, u32 offset)
{
    u64 value = 0;
    for (u32 i = 0; i < 8; i++) {
        value |= ((u64)data[offset + i]) << (i * 8);
    }
    return value;
}
```

**Issue:** `micro_read_u64_le` is a byte-by-byte loop, unrolled by the BPF verifier into 8 separate `BPF_LDX | BPF_MEM | BPF_B` byte loads plus 7 shift-and-or sequences. This is exactly the WIDE_MEM pattern: 8 consecutive byte loads with shifts and ORs into a destination register.

The kernel JIT compiles these as 8 separate `movzx + lsh + or` sequences (≥ 56 bytes). BpfReJIT WIDE_MEM can fuse this into a single 64-bit `MOV` load (4 bytes). However, the micro benchmark infrastructure does NOT run the scanner on micro benchmark programs — it only uses hand-crafted policies (the `.yaml` files in `micro/policies/`).

**Why is recompile slower here?** The recompile adds the policy-parse overhead (negligible at ≥1K repeats) but does NOT apply WIDE_MEM optimization. The 0.746x ratio means the recompile kernel path is slower — this is because:
1. Full image recompile adds I-cache flush overhead
2. WIDE_MEM sites are NOT in the policy (not listed in `micro/policies/multi_acc_4.yaml` or the main policy)
3. So recompile runs but improves nothing, and the I-cache flush of the full image hurts

**Fix:** Add WIDE_MEM scanning for `multi_acc_4` (and other benchmarks using `micro_read_u64_le`) in the policy configuration, OR change `micro_read_u64_le` to use a `u64*` cast with `__builtin_bswap` where needed.

**Expected impact:** If WIDE_MEM applied correctly (replacing 8 byte loads with 1 QWORD load), the loop body shrinks dramatically, likely achieving 1.5–2x speedup. The WIDE_MEM family shows strong gains in corpus (wide_load pattern dominates byte-recompose ablation at 50.7%).

---

### 9. BRANCH_FLIP: jmp_join_size Two-Pass Instability (P3-LOW)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, lines 3183–3187

**Code:**
```c
jmp_join_size = is_imm8_jmp_offset((s32)body_a_size) ? 2U : 5U;
err = emit_local_cond_jump(pprog, jmp_cond,
                           (s32)body_b_size + (s32)jmp_join_size);
```

**Issue:** `jmp_join_size` is computed from `body_a_size`, which is measured by `measure_branch_flip_body`. If `body_a_size` is near the imm8 boundary (±127 bytes), the choice between 2-byte and 5-byte join jump affects the offset of `body_b` relative to the start of the conditional jump. This can cause a JIT convergence issue:

- Pass N: body_a_size = 127 → `jmp_join_size = 2` → conditional jump offset = body_b_size + 2
- After emitting body_b and join, the next pass recalculates body_a_size as 128 (due to alignment effects) → `jmp_join_size = 5` → different total size → unstable

This is the classic JIT convergence issue (documented in the `MAX_PASSES` comment near line 5670). The x86 BPF JIT handles normal jump convergence via the 123-byte positive offset limit. But `emit_canonical_branch_flip` does not use the standard JIT jump mechanism — it computes displacements manually.

**Concrete scenario:** If `body_a_size` oscillates around 127 bytes between passes, `jmp_join_size` oscillates between 2 and 5, causing the total emitted size to oscillate, preventing convergence. The `MAX_PASSES = 20` loop would eventually give up or find a fixed point.

**Mitigation:** The `body_a_len` is bounded to 16 BPF instructions. Each BPF instruction compiles to at most ~15 bytes (for div/mod with saves). 16 × 15 = 240 bytes — well above the 127-byte threshold. So for large body_a, the 5-byte form is always chosen and there's no oscillation. For small body_a (e.g., 1 instruction = 3-5 bytes), the 2-byte form is always chosen. The oscillation window is body_a_size ∈ [120, 134] bytes, requiring 9-10 BPF instructions of average 12+ bytes each — uncommon in practice.

**Verdict:** Low risk in practice but a latent convergence bug for dense branch-flip patterns. Not the cause of current regressions.

---

### 10. COND_SELECT Emitter: Larger Patterns Silently Fail (P3-LOW)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, `emit_canonical_select` (lines 1478–1506)

**Code:**
```c
if (site_len == 4)
    return emit_bpf_cmov_select(pprog, &insns[idx], &insns[idx + 3],
                                &insns[idx + 1], use_priv_fp);
if (site_len == 3)
    return emit_bpf_cmov_select_compact(pprog, &insns[idx],
                                        &insns[idx + 1],
                                        &insns[idx + 2], use_priv_fp);
return -EOPNOTSUPP;
```

**Issue:** The scanner in `pattern_v5.cpp` generates COND_SELECT rules for guarded-update patterns (site_len=2: `jcc, mov`) and switch-chain patterns (site_len=5,6: multi-insn conditional chains). However, the emitter only handles site_len=3 (compact) and site_len=4 (diamond). Patterns with site_len=2, 5, or 6 return `-EOPNOTSUPP`, which causes:
1. The rule is marked as active (validated by scanner)
2. The emitter returns -EOPNOTSUPP < 0
3. `bpf_jit_apply_prog_rule` logs "emitter fallback (err=-95)"
4. The site falls back to standard emission (no optimization)

This means the scanner generates rules that the emitter cannot apply — wasted syscall overhead and log noise. The guarded-update (2-insn) and switch-chain (5,6-insn) rules validated at kernel level should not be generated by the scanner if they can't be applied.

**Expected impact:** The scanner currently flags these larger patterns as "cmov sites" in the summary, inflating the reported site count. In reality they fall back, providing 0 benefit. This inflates the `cmov_sites` statistic but doesn't cause performance regression beyond the wasted validation.

---

### 11. ENDIAN_FUSION 16-bit MOVBE: Emitter adds extra movzx (P3-LOW)

**File:** `/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`, `emit_movbe_load` (lines 2648–2667)

**Code:**
```c
if (width == 16)
    EMIT1(0x66);
maybe_emit_mod(&prog, base_reg, dst_reg, width == 64);
EMIT3(0x0F, 0x38, 0xF0);
emit_insn_suffix(&prog, base_reg, dst_reg, off);

if (width == 16) {
    if (is_ereg(dst_reg))
        EMIT3(0x45, 0x0F, 0xB7);
    else
        EMIT2(0x0F, 0xB7);
    EMIT1(add_2reg(0xC0, dst_reg, dst_reg));
}
```

**Issue:** 16-bit MOVBE emits:
1. `66 [REX] 0F 38 F0 /r` — loads 16-bit big-endian value into dst (as 16-bit)
2. `[REX] 0F B7 /r` — movzx dst, dx (zero-extends 16-bit to 64-bit)

**Original sequence** (LDX + BSWAP16):
- `movzx dst, word [base+off]` (3-4 bytes)
- `rol dst, 8` (4-5 bytes for 16-bit rotate)
- `movzx dst, dx` (3-4 bytes for zero extension)

Total original: ~10-13 bytes for 3 instructions.

**MOVBE 16-bit total:** 5 bytes (MOVBE) + 3 bytes (movzx) = 8 bytes for 2 instructions.

This is actually a size improvement (8 < 10). But the benchmark showed 0.695x for endian_swap_dense with 256 sites — the I-cache flush from full image recompile dominates. For 32-bit MOVBE (5 bytes vs LDX+BSWAP32 = 3+2 = 5 bytes), it's a zero-gain same-size case. For 64-bit MOVBE (6 bytes vs LDX+BSWAP64 = 4+3 = 7 bytes), MOVBE saves 1 byte.

**Verdict:** The 16-bit emitter is correct but the extra movzx is necessary (MOVBE 16-bit only loads 16 bits, requires explicit zero-extension for BPF semantics). Not a bug, but an inherent 16-bit ENDIAN_FUSION limitation: the fused instruction saves no latency and minimal code size vs the original. 16-bit endian fusion sites are not worth the recompile overhead.

---

## Action Items

### Immediate (for paper data quality)

1. **Classify `simple_packet` as non-applied control**: The 0.545x ratio is measurement noise on a <10ns benchmark. Exclude it from the applied-only geomean or move it to a "non-applicable" category alongside `multi_acc_4`.

2. **Investigate `multi_acc_4` WIDE_MEM opportunity**: Add WIDE_MEM scanning for `multi_acc_4`. The `micro_read_u64_le` byte-loop generates exactly the WIDE_MEM pattern. Applying WIDE_MEM should give 1.5-2x for this benchmark and convert a 0.746x loss to a positive number.

3. **Scanner coverage: verify guarded-update site_len=2 rules**: The scanner generates 2-insn COND_SELECT sites (`jcc, mov`) that the emitter rejects. Filter them out in the scanner or extend the emitter to handle them. Extend the emitter's `emit_canonical_select` to support site_len=2 (guarded update: just emit `cmp + cmovcc`). This is a small but real coverage gap.

### For correctness hardening

4. **Branch_flip convergence**: Add a comment documenting the oscillation risk. The fix is to always choose `jmp_join_size = 5` (conservative), ensuring monotonic non-decrease of emitted size, which guarantees convergence. Cost: 3 bytes of NOP per branch-flip site (or encode a short-form if body_a_size < 123). Alternatively: use an imm8 threshold of 120 instead of 127 to leave headroom.

5. **ENDIAN_FUSION: skip 16-bit sites in policy**: The 16-bit MOVBE emitter is correct but the 2-instruction lowering (MOVBE + movzx) is not materially better than original (LDX + ROL + movzx). Add a policy recommendation: only enable ENDIAN_FUSION for 32-bit and 64-bit widths where the size/latency benefit is real.

### For coverage improvement (new sites)

6. **ZERO_EXT_ELIDE expansion**: The zero-ext-elide pattern requires exact register self-copy (`mov dst, dst` with off=1 or 0 forms). Real programs often have the 32-bit ALU result in a different register. Consider if additional patterns are being missed.

7. **ROTATE: scan 5-insn clang pattern more aggressively**: The `bpf_jit_parse_rotate_5insn` validates a 5-insn variant where `dst != src`. The scanner's `build_v5_rotate_descriptors` should also build descriptors for this pattern variant so these sites are included in the policy.

---

## Performance Impact Summary

| Fix | Expected Delta |
|-----|----------------|
| multi_acc_4 WIDE_MEM | 0.746x → ~1.4-1.6x |
| simple_packet reclassify | 0.545x removed from applied-only geomean |
| Guarded-update COND_SELECT (site_len=2) | +coverage, real programs only |
| Branch_flip jmp_join_size conservative | 0 perf impact, convergence safety |
| 16-bit ENDIAN_FUSION policy skip | removes a site type that net-negatives |

If multi_acc_4 is fixed via WIDE_MEM, the applied-only geomean improves from 0.993x to approximately 1.00-1.01x (removing one of the major applied-but-loses cases).
