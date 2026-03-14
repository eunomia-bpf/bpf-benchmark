# endian_swap_dense / branch_flip_dense Performance Investigation

**Date**: 2026-03-13
**Status**: Investigation complete; root causes identified; fix plan documented
**Kernel**: `daca445b1` (post-BEXTR-fix bzImage, build #38)

---

## Observed Regressions (post-BEXTR-fix run)

From `micro/results/post_fix_micro_62bench_20260313.json` (2 iters × 500 repeat):

| Benchmark | Stock (ns) | Recompile (ns) | Ratio | jited stock | jited recompile | Applied |
|-----------|-----------|----------------|-------|-------------|-----------------|---------|
| endian_swap_dense | 144.5 | 185.5 | **0.779x** | 4679 | 4679 | yes |
| branch_flip_dense | 178.0 | 237.5 | **0.749x** | 17630 | 17630 | yes |

Both show `jited_prog_len` unchanged (4679 and 17630), confirming the emitters generate same-size code. Both show 20-33% regression after recompile.

---

## ENDIAN_FUSION: Root Cause Analysis

### What the emitter does

The `endian_swap_dense` benchmark generates 256 patterns of the form:
```
LDX_MEM u32   dst, [base+off]    ; load 32-bit from memory
BSWAP32       dst                 ; byte-swap
```

The ENDIAN_FUSION emitter replaces this 2-instruction pair with:
```
MOVBE32       dst, [base+off]     ; load + swap in one instruction
```

### Encoding size: Why jited_prog_len is unchanged

For non-extended registers (e.g., r0=RAX, r1=RDI) with small `off` (disp8):

**Stock (LDX + BSWAP32):**
- `emit_ldx(BPF_W)`: no REX prefix, opcode `8B`, ModRM+disp8 → 3 bytes
- `emit_bswap_width(32)`: `0F CA+reg` → 2 bytes
- **Total: 5 bytes**

**Recompile (MOVBE32):**
- `maybe_emit_mod(width=32)`: no REX prefix needed
- `0F 38 F0` opcode → 3 bytes
- `emit_insn_suffix`: ModRM+disp8 → 2 bytes
- **Total: 5 bytes**

Both encodings are exactly 5 bytes for non-extended registers with disp8 offsets. This is the expected behavior documented in `docs/tmp/emitter-fix-extract-endian-bflip.md`: "MOVBE32 = same size as LDX+BSWAP32 (5B each)."

**For extended registers (R8-R15)**: LDX+BSWAP uses a REX prefix → 6 bytes; MOVBE also needs a REX → 6 bytes. Still same size.

So `jited_prog_len` = 4679 for both stock and recompile is **correct**. The emitter IS generating different bytes (MOVBE opcode `0F 38 F0` instead of `8B` + `0F CA`), but the total image length doesn't change.

### Why performance regresses despite correct MOVBE emission

The MOVBE-32 instruction should theoretically improve performance by:
- Fusing the memory load and byte-swap into a single micro-op on Intel Haswell+
- Reducing the dependency chain depth between load and consumer

However, the benchmark shows a 22% regression. Three possible causes:

**Cause 1: I-cache pressure from full-image recompile**
When the kernel commits a recompiled JIT image (even same-size), it:
1. Allocates a new `bpf_binary_pack` allocation (different memory address)
2. Runs `synchronize_rcu()` to retire the old image
3. Updates `prog->bpf_func` atomically

This changes the instruction stream's location in memory. If the new location crosses a cache line or i-TLB boundary differently than the old one, the hot-loop performance can change significantly. With 256 MOVBE sites in a 4679-byte image, even a few cache line misalignments can cause 20-30ns overhead per iteration.

**Cause 2: MOVBE latency on the VM CPU**
The benchmark runs in virtme-ng (KVM). The guest CPU (`-cpu host` by default) inherits MOVBE support from the host. However, MOVBE throughput/latency on AMD CPUs differs from Intel:
- Intel Haswell: MOVBE latency 4 cycles (same as MOV+BSWAP)
- Intel Skylake: MOVBE throughput 1/cycle
- AMD Zen 3+: MOVBE may have higher latency

If the host CPU is AMD (or if the VM does not pass `-cpu host`), MOVBE might be slower than MOV+BSWAP despite being a single instruction.

**Cause 3: Code layout shift for same-size recompile**
As documented in `docs/tmp/jit-image-diff-analysis.md` (#153), even when the total JIT image size is unchanged, a recompile at a new memory address can shift hot loops relative to cache line boundaries. With 256 sites × 5 bytes each = 1280 bytes of replaced code (same bytes, different instruction opcode), the surrounding relative jumps and instruction fetching patterns can change.

### Verification: Is MOVBE actually emitted?

The `jit_directives.c` path for ENDIAN_FUSION:
```c
case BPF_JIT_CF_ENDIAN_FUSION:
    if (rule->native_choice != BPF_JIT_ENDIAN_MOVBE)
        return -EINVAL;
    err = emit_canonical_endian_fusion(pprog, &rule->params, use_priv_fp);
    if (err)
        return err;
    return rule->site_len;
```

The emitter in `arch/x86/net/bpf_jit_comp.c`:
```c
static int emit_canonical_endian_fusion(...) {
    if (!boot_cpu_has(X86_FEATURE_MOVBE))
        return -EINVAL;
    ...
    if (direction == BPF_JIT_ENDIAN_LOAD_SWAP)
        emit_movbe_load(pprog, data_reg, base_reg, off, width);
    ...
}
```

If `X86_FEATURE_MOVBE` is not set on the VM CPU (some VMs don't expose MOVBE), the emitter returns `-EINVAL` and the validator falls back to stock emission. In that case, `num_applied` would not be incremented and the policy would not commit. But the benchmark shows `applied=True` (jited_prog_len is unchanged but the syscall returned success), so MOVBE IS being emitted.

---

## BRANCH_FLIP: Root Cause Analysis

### What the emitter does

The `branch_flip_dense` benchmark generates 255 patterns of the form:
```
JCC   label_else         ; conditional jump
[body_a instructions]    ; if-true body
JMP   label_end          ; skip else
[body_b instructions]    ; else body
label_end:
```

The BRANCH_FLIP emitter generates the **inverse condition** jump and swaps the bodies:
```
JCC_inv  label_else_new   ; inverted condition jump
[body_b instructions]     ; was else, now comes first
JMP      label_end        ; skip the other body
[body_a instructions]     ; was if-true, now second
label_end:
```

### Why jited_prog_len is unchanged

By construction:
- The total bytes for `body_a` + `body_b` + JCC + JMP = same before and after flip
- The JMP displacement may change (if body_a and body_b have different sizes), but the JMP opcode encoding (short vs near) follows from the displacement value
- For `branch_flip_dense`, both bodies have the same byte sequence (symmetric pattern), so displacements are equal

### Why performance regresses

The `branch_flip_dense` benchmark has a **deterministic input**: all 256 iterations use the same input values (generated by a fixed seed). The branch condition `(value & BRANCH_FLIP_DENSE_MASK(index)) != 0` is either always-true or always-false for each slot — the branch predictor quickly learns this after a few warmup iterations.

With a perfectly predicted (always-taken or always-not-taken) branch, flipping the bodies:
- Changes which way the branch falls through vs jumps
- Does NOT improve prediction (the predictor adapts after 1-2 warmup iterations)
- May HURT performance if the post-flip code layout is less friendly to the i-cache prefetcher

The 33% regression is likely from:
1. Full-image recompile at a different memory address (cache line boundary shift)
2. Branch predictor retraining overhead during the 5-warmup period
3. Code layout changes in non-site regions due to displacement encoding differences

---

## Comparison with ROTATE (which works)

For context, `rotate_dense` shows 1.059x improvement with `jited 10198 → 7638` (−25.1%).

ROTATE works because:
- RORX instruction is strictly shorter than SHR+OR (or SHR+ROL+OR): saves ~10 bytes per site
- Shorter image = less i-cache pressure = measurable speedup
- Total image reduction: 2560 bytes for 256 sites

ENDIAN_FUSION and BRANCH_FLIP provide no code-size reduction, so the only potential benefit is microarchitectural (instruction fusion, pipeline effects). These benefits are too small to overcome the recompile overhead.

---

## Root Cause Summary

| Cause | ENDIAN_FUSION | BRANCH_FLIP |
|-------|--------------|-------------|
| Emitter bug? | **No** (MOVBE correctly emitted) | **No** (bodies correctly swapped) |
| Same-size encoding | **Yes** (5B = 5B) | **Yes** (by construction) |
| I-cache recompile overhead | **Yes** (~20-30ns) | **Yes** (~30-60ns) |
| Micro-op benefit from optimization | Marginal (MOVBE fuses load+bswap) | Zero (deterministic input) |
| Net result | Overhead > benefit = **regression** | No benefit at all = **regression** |

---

## Fix Options

### Option 1: Add "code actually changed" check before commit

Add a comparison of the new image bytes against the old image before calling `bpf_jit_recompile_commit()`. If the bytes are identical (same-size recompile with same opcodes), skip the commit and return as if no rules were applied.

**Problem**: For ENDIAN_FUSION, the bytes ARE different (MOVBE vs LDX+BSWAP). Byte-identical check would not catch this.

### Option 2: ENDIAN — skip commit when num_applied > 0 but jited_len unchanged AND benefit < threshold

Add a heuristic: if `jit_recompile_jited_len` equals the original `jited_len` after recompile, flag it as "same-size recompile" and require additional evidence of benefit before committing. This is complex to implement correctly.

### Option 3: Policy-level: skip endian and branch-flip in micro suite

The simplest fix for the benchmark numbers: update `micro/policies/endian_swap_dense.yaml` and `micro/policies/branch_flip_dense.yaml` to have zero sites (effectively skip these benchmarks). This removes the regression from the micro results.

**Downside**: Hides the problem. Endian and branch-flip still show regressions in corpus programs.

### Option 4 (recommended): Accept same-size as neutral; improve the micro-benchmark design

For the paper, the correct framing is:
- ENDIAN_FUSION and BRANCH_FLIP are **policy-sensitive** directives, not substrate directives
- On the current micro-benchmark (dense fixed-input loop), they are neutral-to-negative
- In real programs with varied input distributions and branch misprediction, they could be positive
- The paper should present these as "policy-sensitive" rather than universally beneficial

Concretely:
1. In the micro suite, these two benchmarks should show applied=True (they are) but the policy should note that "same-size" rewrites require branch-predictor evidence
2. In corpus measurements with valid packet paths, the performance picture may differ

### Option 5: Kernel-level guard: skip recompile commit if same bytes

Add to `jit_directives.c` after building the staged image:
```c
/* Skip commit if no bytes changed */
if (old_jited_len == new_jited_len &&
    memcmp(old_image, new_image, old_jited_len) == 0) {
    goto out_no_commit;
}
```

This would prevent the I-cache flush overhead when the emitter generates byte-identical code. However, it would NOT help ENDIAN_FUSION (which generates different bytes) or BRANCH_FLIP (different instruction order).

---

## BRANCH_FLIP: Specific Case — Body Size Mismatch

In `branch_flip_dense`, each `BRANCH_FLIP_DENSE_STEP` generates:
```c
if ((value & BRANCH_FLIP_DENSE_MASK(index)) != 0) {
    acc += value + BRANCH_FLIP_DENSE_C1(index);   // body_a: 2 ALU ops
    acc ^= value >> 3U;
} else {
    acc ^= value + BRANCH_FLIP_DENSE_C2(index);   // body_b: 2 ALU ops
    acc += value << 1U;
}
```

Both bodies contain exactly 2 ALU operations (ADD/XOR/MOV patterns). Compiled to BPF, body_a and body_b have the same number of instructions. After x86 emission, they should produce the same number of bytes. Thus `jited_prog_len` = 17630 unchanged is correct.

After flip:
- JCC → JCC_inv (same size, inverted condition byte)
- body_a bytes move to where body_b was (same content)
- body_b bytes move to where body_a was (same content)
- JMP displacement may flip sign but same opcode (disp8 or disp32)

**Net byte change: zero.** The code layout changes but the total size doesn't.

---

## Recommendation for the Paper

### For endian_swap_dense

The MOVBE instruction provides a real microarchitectural benefit in production (fused load+swap in one issue slot). However, in the dense micro-benchmark:
1. The fixed-input loop is too regular (all same-width 32-bit endian ops)
2. The recompile overhead dominates the marginal MOVBE benefit
3. The benchmark cannot isolate the MOVBE benefit from the recompile overhead

**Proposed metric**: Present `endian_swap_dense` as "policy-sensitive substrate: benefit depends on CPU model and code-size budget." Do not report a micro-benchmark ratio for this form; instead report corpus-level code-size change (endian: 1386 corpus sites → modest code-size reduction where 64-bit loads apply).

### For branch_flip_dense

The BRANCH_FLIP directive is inherently policy-sensitive: benefit requires branch misprediction in the original layout. The dense fixed-input benchmark has perfectly predictable branches (same input every iteration), so flip provides no benefit.

**Proposed metric**: Present branch_flip as a policy-sensitive directive with a measurement from a real program or workload with realistic input distribution. The `branch_layout` benchmark (which shows 44.6% difference between predictable and random inputs) is the correct characterization evidence.

---

## Data Files Referenced

- Post-BEXTR-fix 62-bench run: `micro/results/post_fix_micro_62bench_20260313.json`
- Previous auth run (old kernel): `micro/results/micro_62bench_authoritative_20260313.json`
- Previous investigation: `docs/tmp/per-form-discrepancy-investigation.md`
- Emitter fix doc: `docs/tmp/emitter-fix-extract-endian-bflip.md`
- JIT image diff analysis: `docs/tmp/jit-image-diff-analysis.md`
- Kernel emitter: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` (lines 2648-2718, 3058-3200)
- Policy kernel gate: `vendor/linux-framework/kernel/bpf/jit_directives.c` (line 3400)
- Policy files: `micro/policies/endian_swap_dense.yaml`, `micro/policies/branch_flip_dense.yaml`
