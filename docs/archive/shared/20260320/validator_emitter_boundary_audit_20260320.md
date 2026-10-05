# Validator/Emitter Boundary Audit

Date: 2026-03-20

Scope:
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`

Boundary rule audited:
- Validator is the only safety gate.
- Emitters consume validated canonical params mechanically.
- `bpf_jit_arch_form_supported()` declares arch capability.
- Emitter `-EINVAL` is reserved for genuine arch-lowering impossibility, not invalid params.

## Summary

I audited all 8 shared form validators, all 8 x86 emitters, and all 4 arm64 emitters against the new boundary rule.

Concrete fixes:
- Tightened validator-side constraints for `BITFIELD_EXTRACT`, `ZERO_EXT_ELIDE`, and `BRANCH_FLIP`.
- Added an explicit validator-side width bound for `WIDE_MEM`.
- Removed redundant per-form emitter-side param/native-choice validation on x86 and arm64.
- Deleted the x86 `BITFIELD_EXTRACT` `SHR+AND` fallback and made the form a pure canonical extract lowering.
- Moved x86 `BITFIELD_EXTRACT` capability declaration to `bpf_jit_arch_form_supported()` via BMI1 gating.

No emitter was found reading raw program insns directly. `BRANCH_FLIP` still re-emits BPF body instructions, but only from validator-owned copied arrays stored in canonical params, which is consistent with the param-only contract.

## Per-Form Audit

| Form | Validator audit | x86 emitter audit | arm64 emitter audit | Result |
|---|---|---|---|---|
| `COND_SELECT` | Exact site-shape validation was already complete. Width and compare op are validator-derived. | Entry-point param/type checks were redundant. Dispatch native-choice checks were redundant. No raw-insn reads. | Same redundancy pattern as x86. No raw-insn reads. | Clean after deleting emitter-side rechecks. |
| `WIDE_MEM` | Shape parsing already enforced contiguous byte-load recompose. Added explicit `width in [2,8]` bound to make the contract local and obvious. | Entry-point param/type and encoded-flag checks were redundant. Dispatch native-choice check was redundant. | Same redundancy pattern as x86. `arm64_resolve_mem_base()` remains a mechanical address resolver, not semantic validation. | Clean after explicit width bound plus emitter cleanup. |
| `ROTATE` | Validator already enforced legal rotate amount and exact high-mask semantics for masked 32-bit forms. | Entry-point param/amount/width checks were redundant. BMI2 gating for `RORX` belonged in `bpf_jit_arch_form_supported()`, not in the emitter. Dispatch native-choice check was redundant. | Entry-point param/amount/width/native-choice checks were redundant. arm64 still maps both rotate native choices to the same immediate rotate encoding. | Clean after deleting emitter-side checks and relying on validator plus arch capability. |
| `ADDR_CALC` | Exact 3-insn site-shape validation was already complete, including scale range. | Entry-point param/type/scale checks were redundant. Dispatch native-choice check was redundant. | Not implemented on arm64. | Clean after x86 emitter cleanup. |
| `BITFIELD_EXTRACT` | This was the main validator gap. Before: only shape and `shift < width` were checked. After: validator normalizes the site to canonical low-mask extract semantics, clamps boundary masks to the remaining bit-width, rejects non-contiguous effective masks, and guarantees `lsb + field_width <= width`. | Before: emitter redundantly revalidated params, kept a `SHR+AND` fallback, and opportunistically used BEXTR. After: emitter consumes normalized params and uses the canonical extract path only; `SHR+AND` fallback is deleted. BMI1 requirement now lives in `bpf_jit_arch_form_supported()`. | Before: emitter still had UBFX representability checks because validator allowed wider/non-canonical masks. After: validator guarantees UBFX-safe params, so the emitter becomes a direct `UBFX` lowering with no representability checks. | Clean after pushing extract semantics fully into the validator. |
| `ZERO_EXT_ELIDE` | This had a real validator bug. Before: any ALU32 insn except `END` was accepted. That allowed signed 32-bit `DIV/MOD` and unsupported `MOVSX32` variants even though the x86 replay emitter does not faithfully regenerate them. After: validator accepts only the ALU32 subset that the linear x86 replay emitter can encode. | Entry-point param/type/code checks were redundant once validator matched the replayable subset. | Not implemented on arm64. | Clean after validator-side replayability check. |
| `ENDIAN_FUSION` | Exact shape validation was already complete: width, direction, register linkage, and opcode pairing were validator-derived. | Entry-point param/type/width/direction checks were redundant. MOVBE feature gating belongs in `bpf_jit_arch_form_supported()`, not in the emitter. Dispatch native-choice check was redundant. | Not implemented on arm64. | Clean after x86 emitter cleanup. |
| `BRANCH_FLIP` | This had a real validator gap. Before: validator only ensured bodies were jump/store-free and length-bounded, but the x86 branch-flip emitter only accepts a stricter linearizable instruction subset. After: validator checks branch bodies against the actual linear emitter-supported ALU/END/LDX subset. | Entry-point param/type/class/body-length/pointer checks were redundant. Dispatch native-choice check was redundant. Re-emission uses validator-copied body arrays from canonical params, not raw program insns. | Not implemented on arm64. | Clean after validator-side body linearizability check. |

## Findings And Changes

### 1. `BITFIELD_EXTRACT` had a split safety model; it is now validator-owned

Problem:
- Shared validator accepted generic `rsh+and` and `and+rsh` sites without proving that the effective extracted field was contiguous or in-range.
- x86 then kept a local `BEXTR` fast path plus `SHR+AND` fallback.
- arm64 then re-checked whether `UBFX` was representable.

Why that violated the new rule:
- Semantic validity lived partly in the validator and partly in the emitters.
- Backend behavior depended on emitter-local checks instead of canonical params.

Fix:
- Validator now derives the effective extracted mask, clamps it to the remaining source width, rejects non-contiguous masks, and guarantees a canonical low-mask extract.
- Validator now emits normalized canonical params with `SHIFT_MASK` order and a canonical mask.
- x86 `BITFIELD_EXTRACT` is now a direct BEXTR-based lowering.
- arm64 `BITFIELD_EXTRACT` is now a direct UBFX-based lowering.
- x86 BMI1 support now comes from `bpf_jit_arch_form_supported()`.

Consequence:
- `test_bitfield_extract_boundary` still passes because the validator canonicalizes the boundary mask to the semantically relevant low bits instead of relying on emitter-local fallback behavior.

### 2. `ZERO_EXT_ELIDE` could validate a site that x86 replay could not encode correctly

Problem:
- Validator accepted any ALU32 op.
- The x86 `ZERO_EXT_ELIDE` emitter replays the original ALU32 insn through `emit_bpf_alu32_insn()`.
- That replay path does not encode signed 32-bit `DIV/MOD` and does not support every possible `MOVSX32` variant.

Fix:
- Added validator-side ALU32 replayability checks.
- `ZERO_EXT_ELIDE` now only activates on the subset the replay emitter can encode exactly.

Consequence:
- No validator-pass / emitter-misencode gap remains for this form.

### 3. `BRANCH_FLIP` body validation was weaker than the actual x86 linear emitter

Problem:
- Validator only rejected control flow, stores, and `ldimm64`.
- The x86 `BRANCH_FLIP` path actually re-emits only a stricter linear subset via `emit_linear_bpf_insn()`.

Fix:
- Added validator-side ALU32/ALU64 replayability helpers and used them to validate each branch body instruction against the linear emitter-supported subset.

Consequence:
- `measure_branch_flip_body()` and `emit_branch_flip_body()` are no longer expected to discover invalid body contents after validation.

### 4. Backend capability checks now live in `bpf_jit_arch_form_supported()`

x86 changes:
- `COND_SELECT`: `CMOV`
- `ROTATE/RORX`: `BMI2`
- `BITFIELD_EXTRACT`: `BMI1`
- `ENDIAN_FUSION`: `MOVBE`

This matches the design rule better than emitter-local feature tests.

## Dead Paths Removed

Deleted:
- x86 `BITFIELD_EXTRACT` `SHR+AND` fallback path
- x86 per-form dispatch native-choice guards
- arm64 per-form dispatch native-choice guards
- x86/arm64 entry-point param/type/width/native-choice validation in the canonical emitters

Remaining impossible-path checks:
- Generic helper functions such as binding-value movers and condition-code mappers still return errors on impossible internal misuse. They are no longer the first-line safety gate for any canonical form.

## Raw-Insn Contract Check

Results:
- `COND_SELECT`: param-only on x86 and arm64
- `WIDE_MEM`: param-only on x86 and arm64
- `ROTATE`: param-only on x86 and arm64
- `ADDR_CALC`: param-only on x86
- `BITFIELD_EXTRACT`: param-only on x86 and arm64
- `ZERO_EXT_ELIDE`: param-only on x86 by reconstructing a synthetic ALU32 insn from canonical params
- `ENDIAN_FUSION`: param-only on x86
- `BRANCH_FLIP`: uses validator-copied BPF body arrays carried in canonical params; does not read the original program insn stream during emission

No raw-program-insn contract violation was found.

## Files Changed

- `vendor/linux-framework/kernel/bpf/jit_validators.c`
  - validator-side replayability helpers
  - canonical `BITFIELD_EXTRACT` normalization
  - explicit `WIDE_MEM` width bound
  - stricter `BRANCH_FLIP` body validation
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
  - deleted redundant per-form emitter validation
  - deleted `BITFIELD_EXTRACT` fallback path
  - moved `BITFIELD_EXTRACT` capability declaration to `bpf_jit_arch_form_supported()`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
  - deleted redundant per-form emitter validation
  - simplified `BITFIELD_EXTRACT` to direct UBFX lowering on validator-normalized params

## Verification

Build:
- `make -C vendor/linux-framework -j$(nproc) bzImage` ✅

Runtime/test:
- `make vm-selftest` ✅ `27/27`
- `make vm-micro-smoke` ✅
- `make scanner-tests` ✅

Artifacts:
- micro smoke output: `micro/results/dev/vm_micro_smoke.json`

