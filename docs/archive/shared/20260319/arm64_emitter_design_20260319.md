# ARM64 BpfReJIT Emitter Design

Date: 2026-03-19

## Scope

This document designs the ARM64 BpfReJIT backend for the first-wave 4 canonical forms:

1. `ROTATE`
2. `WIDE_MEM`
3. `BITFIELD_EXTRACT`
4. `COND_SELECT`

This is design only. No kernel code was modified.

Inputs read for this design:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/arm64_jit_gap_analysis_20260319.md`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit.h`
- `vendor/linux-framework/arch/arm64/include/asm/insn.h`

## Executive Summary

The ARM64 backend should mirror the x86 design shape:

- add an ARM64-local rule lookup + dispatch path in `build_body()`
- emit canonical native sequences directly from the validated `canonical_params`
- fail closed at the emitter boundary and fall back to stock per-insn lowering
- add ARM64 staged-image commit/abort support so `bpf_jit_supports_recompile()` can return `true`

The first-wave forms split into two categories:

- straightforward, high-confidence native lowerings:
  - `ROTATE`
  - `WIDE_MEM`
  - `COND_SELECT`
- mostly straightforward but with one important caveat:
  - `BITFIELD_EXTRACT`: native `ubfx` is correct only when the effective mask is a contiguous low-bit field; current canonical params do not encode signed extract, so first-wave should use `ubfx`, not `sbfx`

Key design calls:

- `ROTATE`: use `extr`/`ror` for constant rotates; keep a `rorv` path available as a future-ready extension, but current validator only feeds immediate rotate amounts.
- `WIDE_MEM`: use exact-width `ldr{h,w,x}` chunking plus `rev16/rev32/rev64` when reconstructed byte order differs from the CPU's native load order. Do not use `ldp` in first wave.
- `BITFIELD_EXTRACT`: normalize `(shift, mask, order)` to `(lsb, field_width)` and use `ubfx`; fail closed on non-contiguous masks.
- `COND_SELECT`: compare/test plus `csel`; optionally use `cset`/`csetm` aliases (`csinc`/`csinv`) for boolean materialization patterns.

`jit_directives.c` should not need logic changes. One shared interface change is still required: `include/linux/bpf_jit_directives.h` is currently x86-only for staged-image accessors and commit/abort declarations, so ARM64 must be added there or ARM64 will keep hitting the stubbed `-EOPNOTSUPP` path.

## Source Anchors

- ARM64 backend helpers and JIT body:
  - `emit_a64_mov_i()`: `arch/arm64/net/bpf_jit_comp.c:126`
  - `emit_a64_add_i()`: `arch/arm64/net/bpf_jit_comp.c:295`
  - `is_lsi_offset()`: `arch/arm64/net/bpf_jit_comp.c:335`
  - `add_exception_handler()`: `arch/arm64/net/bpf_jit_comp.c:1113`
  - `build_insn()`: `arch/arm64/net/bpf_jit_comp.c:1201`
  - `build_body()`: `arch/arm64/net/bpf_jit_comp.c:1902`
  - `struct arm64_jit_data`: `arch/arm64/net/bpf_jit_comp.c:2002`
- x86 reference emitters and recompile path:
  - `emit_canonical_select()`: `arch/x86/net/bpf_jit_comp.c:1320`
  - `emit_canonical_wide_load()`: `arch/x86/net/bpf_jit_comp.c:2222`
  - `emit_canonical_rotate()`: `arch/x86/net/bpf_jit_comp.c:2253`
  - `emit_canonical_bitfield_extract()`: `arch/x86/net/bpf_jit_comp.c:3303`
  - `bpf_jit_try_emit_rule()`: `arch/x86/net/bpf_jit_comp.c:3371`
  - `bpf_jit_try_emit_prog_rule()`: `arch/x86/net/bpf_jit_comp.c:3460`
  - `struct x64_jit_data`: `arch/x86/net/bpf_jit_comp.c:5562`
  - `bpf_jit_recompile_commit()`: `arch/x86/net/bpf_jit_comp.c:5849`
  - `bpf_jit_recompile_abort()`: `arch/x86/net/bpf_jit_comp.c:5879`
  - `bpf_jit_supports_recompile()`: `arch/x86/net/bpf_jit_comp.c:6088`
- Canonical params and validator contract:
  - param enums: `include/linux/bpf_jit_directives.h:35-115`
  - `COND_SELECT` validator: `kernel/bpf/jit_directives.c:708-727`
  - `WIDE_MEM` validator: `kernel/bpf/jit_directives.c:853-883`
  - `ROTATE` validator: `kernel/bpf/jit_directives.c:1073-1122`
  - `BITFIELD_EXTRACT` validator: `kernel/bpf/jit_directives.c:1221-1261`
  - form metadata table: `kernel/bpf/jit_directives.c:1808-1855`
  - recompile stage checks: `kernel/bpf/jit_directives.c:215-227`
  - syscall handler: `kernel/bpf/jit_directives.c:2633-2795`

## Shared Design Decisions

### 1. Rule dispatch belongs in `build_body()`, not in `build_insn()`

ARM64 stock JIT is currently a pure per-insn translator. Canonical rules span multiple BPF insns, so the right insertion point is the `build_body()` loop, exactly like x86's `do_jit()` loop.

Design:

- before calling `build_insn()` for `insn[i]`, look up an active rule at `i`
- if a rule exists, try the ARM64 canonical emitter
- on success:
  - emit the alternative native sequence
  - collapse `ctx->offset[]` for the covered BPF region
  - skip `rule->site_len` BPF insns
- on emitter failure:
  - log `"emitter fallback"` during the final write pass
  - reset `ctx->idx` to the pre-rule position
  - emit the original BPF insns with stock `build_insn()`

### 2. ARM64 does not need x86's temp-buffer commit model

x86 uses a temp byte buffer because instruction lengths are variable and it needs region commit logic. ARM64 emits fixed 4-byte words directly into `ctx->image`, so the ARM64 apply path can be much simpler:

- validate all params first
- record `region_start = ctx->idx`
- emit directly with `emit()`
- if the emitter returns error:
  - restore `ctx->idx = region_start`
  - fall back to stock emission

No ARM64 equivalent of `bpf_jit_commit_rule_region()` is needed.

### 3. Fail-closed means emitter error -> stock fallback

The validator already proved the site shape. The arch emitter still must reject params it cannot lower safely.

Required behavior for all 4 forms:

- invalid or unsupported params return `-EINVAL`
- caller logs fallback during the final write pass
- caller emits stock ARM64 lowering for the original BPF insns
- no partial alternative sequence may be left live

### 4. Offset collapsing should mirror x86 semantics

For a rule covering `N` BPF insns with native region `[S, E)`:

- `offset[site_start] = S`
- `offset[site_start + 1 ... site_start + N - 2] = S`
- `offset[site_start + N - 1] = E`

This matches the existing x86 "collapse interior entries to region start, final entry to region end" model and is safe because `jit_directives.c` already rejects interior control-flow edges into canonical sites.

### 5. ARM64 helper additions should stay local where possible

Existing reusable generic helpers already exist for:

- `extr`: `aarch64_insn_gen_extr()`
- bitfield ops: `aarch64_insn_gen_bitfield()`
- data2 ops including `RORV`: `aarch64_insn_gen_data2()`
- compare/load/store/logical/branch encoders already wrapped by `A64_*`

Recommended new ARM64-local wrappers in `arch/arm64/net/bpf_jit.h`:

- `A64_RORV(sf, Rd, Rn, Rm)`
- `A64_EXTR(sf, Rd, Rn, Rm, lsb)`
- `A64_ROR_I(sf, Rd, Rn, imm)` as an `EXTR` alias
- `A64_UBFX(sf, Rd, Rn, lsb, width)`
- `A64_SBFX(sf, Rd, Rn, lsb, width)`

Recommended new ARM64-local helpers in `arch/arm64/net/bpf_jit_comp.c`:

- `arm64_binding_value_is_noop()`
- `emit_arm64_binding_value()`
- `bpf_jmp_to_a64_cond()`
- `bpf_jmp_invert()` or a smaller `a64_invert_cond()` helper
- `emit_a64_cond_select()` for `csel`/`csinc`/`csinv`
- `arm64_emit_ldr_chunk()` for `WIDE_MEM`
- `arm64_resolve_mem_base()` for FP/private-stack addressing

I would keep `csel` encoding local to the ARM64 JIT instead of extending `asm/insn.h/c` in the first implementation. `extr` and bitfield generation already exist in the shared insn library; conditional select does not.

## Form 1: ROTATE

### 1. Params consumed

Reads these canonical params:

- `BPF_JIT_ROT_PARAM_DST_REG`
- `BPF_JIT_ROT_PARAM_SRC_REG`
- `BPF_JIT_ROT_PARAM_AMOUNT`
- `BPF_JIT_ROT_PARAM_WIDTH`

Expected types from the current validator:

- `DST_REG`: `REG`
- `SRC_REG`: `REG`
- `AMOUNT`: `IMM`
- `WIDTH`: `IMM`

Important semantic point:

- current validator stores the left-shift amount from the source idiom
- x86 therefore emits `ror width-amount`
- ARM64 must do the same; the canonical `amount` is not "rotate-right immediate"

Operand mapping:

- `DST_REG` -> `Rd`
- `SRC_REG` -> `Rn` and `Rm` for `EXTR`
- `AMOUNT` -> `ror_amt = width - amount`
- `WIDTH` -> 32-bit or 64-bit instruction variant

### 2. ARM64 instruction sequence

#### Current reachable path: constant rotate

32-bit:

```asm
extr wDst, wSrc, wSrc, #((32 - amount) & 31)
```

64-bit:

```asm
extr xDst, xSrc, xSrc, #((64 - amount) & 63)
```

Assembler aliases these as `ror wDst, wSrc, #imm` and `ror xDst, xSrc, #imm`.

Notes:

- this is one ARM64 instruction whether `dst == src` or `dst != src`
- unlike x86 `ROR`, ARM64 `EXTR` already has a separate destination register, so no pre-copy is needed
- for `width == 32`, use the 32-bit variant so the upper 32 bits are zeroed; this is required for the masked 32-bit rotate forms that the validator normalizes from ALU64 source code

#### Future-ready path: variable rotate

Current validator does not produce a register-valued rotate amount, but the param encoding can represent one. If a later validator extension uses `REG` for `AMOUNT`, lower it as:

32-bit:

```asm
neg  wTmp, wAmt
rorv wDst, wSrc, wTmp
```

64-bit:

```asm
neg  xTmp, xAmt
rorv xDst, xSrc, xTmp
```

Reason:

- canonical `amount` is rotate-left
- ARM64 only has `RORV` (rotate-right variable)
- `-amount mod width` is equivalent to `width - amount`

### 3. ARM64 encoding helpers needed

Reuse:

- `emit()`
- `bpf2a64[]`
- `aarch64_insn_gen_extr()`
- `aarch64_insn_gen_data2(..., AARCH64_INSN_DATA2_RORV)`

Write:

- `A64_EXTR()`
- `A64_ROR_I()` alias helper
- `A64_RORV()`

No new generic control-plane or validator helper is needed.

### 4. Fallback behavior

Return `-EINVAL` and fall back to stock ARM64 emission if:

- `DST_REG` or `SRC_REG` is not `REG`
- `WIDTH` is not `32` or `64`
- `AMOUNT` is `0` or `>= width`
- `AMOUNT` is a `REG` but the first-wave implementation does not include the `rorv` path
- `native_choice` is unsupported

Recommended ARM64 choice handling:

- accept both `BPF_JIT_ROT_ROR` and `BPF_JIT_ROT_RORX`
- lower both to the same ARM64 rotate instruction sequence

Reason:

- current form metadata allows both choices
- rejecting `RORX` on ARM64 would create avoidable policy no-apply cases without improving safety

### 5. Code size estimate

- emitter body: ~45-60 LOC
- helper wrappers: ~10-15 LOC
- dispatch case: ~5 LOC

Total touched ARM64 LOC for this form: roughly 60-75.

### 6. Risk assessment

Main risks:

- off-by-width bug from treating canonical `amount` as rotate-right instead of rotate-left
- emitting the 64-bit variant for normalized 32-bit masked sites and accidentally preserving stale upper bits
- future `rorv` path forgetting the `neg` and rotating in the wrong direction

Testing needed:

- all 4 validated rotate source shapes
- `width=32` and `width=64`
- `amount=1` and `amount=width-1`
- `dst==src` and `dst!=src`
- policy using both `ROR` and `RORX`

## Form 2: WIDE_MEM

### 1. Params consumed

Reads these canonical params:

- `BPF_JIT_WMEM_PARAM_DST_REG`
- `BPF_JIT_WMEM_PARAM_BASE_REG`
- `BPF_JIT_WMEM_PARAM_BASE_OFF`
- `BPF_JIT_WMEM_PARAM_WIDTH`

Decoded meaning of `WIDTH`:

- low 8 bits: byte width in `[2, 8]`
- high bits: flags
- currently only `BPF_JIT_WMEM_F_BIG_ENDIAN`

Operand mapping:

- `DST_REG` -> result register
- `BASE_REG` -> address base register
- `BASE_OFF` -> starting byte offset
- `WIDTH & BPF_JIT_WMEM_WIDTH_MASK` -> exact byte count
- `WIDTH & BPF_JIT_WMEM_F_BIG_ENDIAN` -> canonical byte order

Special ARM64 address mapping:

- if `BASE_REG == BPF_REG_FP`:
  - use `PRIVATE_SP` when `ctx->priv_sp_used`
  - otherwise use `SP`
  - add `ctx->stack_size` to the effective offset
- otherwise use `bpf2a64[BASE_REG]` directly

### 2. ARM64 instruction sequence

### Core design choice

First-wave ARM64 `WIDE_MEM` should use exact-width scalar loads and chunking:

- `ldrh`
- `ldr w`
- `ldr x`
- plus `ldrb` for tail bytes
- plus `rev16/rev32/rev64` when the reconstructed scalar byte order differs from the CPU's native load order

It should not use `ldp` in first wave.

Why not `ldp`:

- canonical `WIDE_MEM` reconstructs one scalar value, not two independent values
- `ldp` only loads homogeneous 32-bit or 64-bit register pairs
- it would over-read for `width=3/5/6/7`
- it adds alignment and legality questions without a clear first-wave win
- `width=8` is already best served by one `ldr x`

### Endianness rule

The canonical flag means "desired scalar byte order with respect to increasing memory addresses", not "host endianness".

Define:

```c
need_rev = canonical_big_endian ^ IS_ENABLED(CONFIG_CPU_BIG_ENDIAN);
```

Then:

- if `need_rev == false`, multi-byte chunks can be consumed exactly as loaded
- if `need_rev == true`, every multi-byte chunk must be byte-swapped before shifting/or-ing

This keeps correctness on both little-endian and big-endian ARM64 kernels.

### Width-specific lowering

#### Width = 2

```asm
ldrh wDst, [xBase, #off]    ; or register-offset form
rev16 wDst, wDst            ; only if need_rev
```

#### Width = 4

```asm
ldr  wDst, [xBase, #off]    ; or register-offset form
rev  wDst, wDst             ; only if need_rev
```

#### Width = 8

```asm
ldr  xDst, [xBase, #off]    ; or register-offset form
rev  xDst, xDst             ; only if need_rev
```

#### Width = 3 / 5 / 6 / 7

Use x86-style chunk decomposition with ARM64 loads:

- choose chunks greedily from `{4, 2, 1}`
- first chunk loads directly into `dst`
- later chunks load into `TMP_REG_1`
- if `need_rev && chunk > 1`, apply `rev16` or `rev32`
- shift by:
  - little-endian canonical order: `consumed * 8`
  - big-endian canonical order: `(remaining - chunk) * 8`
- OR the shifted chunk into `dst`

Example, width 6, little-endian result:

```asm
ldr  wDst, [xBase, #off+0]
ldrh wTmp, [xBase, #off+4]
lsl  xTmp, xTmp, #32
orr  xDst, xDst, xTmp
```

Example, width 6, big-endian result on little-endian ARM64:

```asm
ldr  wDst, [xBase, #off+0]
rev  wDst, wDst
lsl  xDst, xDst, #16
ldrh wTmp, [xBase, #off+4]
rev16 wTmp, wTmp
orr  xDst, xDst, xTmp
```

### Immediate-offset vs register-offset loads

Reuse the stock ARM64 rule:

- if `is_lsi_offset(off_adj, scale)` is true, use the immediate-offset `LDR*I` form
- otherwise:
  - materialize `off_adj` in `TMP_REG_2`
  - use register-offset `LDRB/H/32/64`

This is the same addressing discipline as stock `build_insn()`.

### 3. ARM64 encoding helpers needed

Reuse:

- `emit()`
- `emit_a64_mov_i()`
- `is_lsi_offset()`
- existing `A64_LDRBI`, `A64_LDRHI`, `A64_LDR32I`, `A64_LDR64I`
- existing `A64_LDRB`, `A64_LDRH`, `A64_LDR32`, `A64_LDR64`
- existing `A64_LSL`, `A64_ORR`
- existing `A64_REV16`, `A64_REV32`, `A64_REV64`

Write:

- `arm64_resolve_mem_base()` for `FP` / `PRIVATE_SP` / `SP` adjustment
- `arm64_emit_ldr_chunk()` for `{1,2,4,8}` byte zero-ext loads
- `arm64_pick_wide_chunk()` helper, same policy as x86 (`4`, then `2`, then `1`)

No new shared ISA helper is needed.

### 4. Fallback behavior

Return `-EINVAL` and fall back to stock ARM64 emission if:

- param types are wrong
- width is outside `[2, 8]`
- unknown width flags are set
- an internal chunk size is somehow not in `{1,2,4,8}`

Do not fail just because the access is unaligned.

Reason:

- the original byte ladder is alignment-agnostic
- ARM64 scalar loads are allowed on unaligned normal memory
- the backend already emits unaligned `LDRH/W/X` in other paths when needed

Do not use `ldp` as a fallback.

### 5. Code size estimate

- emitter body: ~80-100 LOC
- address/chunk helpers: ~50-70 LOC
- dispatch case: ~5 LOC

Total touched ARM64 LOC for this form: roughly 135-175.

### 6. Risk assessment

Main risks:

- wrong `rev` polarity on big-endian kernels
- over-reading beyond the exact byte window
- forgetting the `FP` -> `SP/PRIVATE_SP + stack_size` remap
- immediate-offset legality bugs for negative or misaligned offsets
- shift/or bugs for widths `3/5/6/7`

Testing needed:

- widths `2,3,4,5,6,7,8`
- canonical little-endian and canonical big-endian ladders
- positive, negative, aligned, and unaligned offsets
- stack loads via `BPF_REG_FP`
- packet/map/ctx loads that remain plain `BPF_LDX|MEM|B` ladders

## Form 3: BITFIELD_EXTRACT

### 1. Params consumed

Reads these canonical params:

- `BPF_JIT_BFX_PARAM_DST_REG`
- `BPF_JIT_BFX_PARAM_SRC_REG`
- `BPF_JIT_BFX_PARAM_SHIFT`
- `BPF_JIT_BFX_PARAM_MASK`
- `BPF_JIT_BFX_PARAM_WIDTH`
- `BPF_JIT_BFX_PARAM_ORDER`

Expected meaning:

- `SHIFT`: logical right-shift amount
- `MASK`: raw AND immediate from the original site
- `WIDTH`: `32` or `64`
- `ORDER`:
  - `BPF_JIT_BFX_ORDER_SHIFT_MASK`
  - `BPF_JIT_BFX_ORDER_MASK_SHIFT`

Normalized ARM64 lowering inputs:

- `lsb = shift`
- `effective_mask = (order == MASK_SHIFT) ? (raw_mask >> shift) : raw_mask`
- `field_width = number of contiguous low bits in effective_mask`

### 2. ARM64 instruction sequence

### Current semantic scope

Current canonical form is unsigned extract only.

Why:

- validator matches `RSH` + `AND`, not arithmetic shift / sign extension
- current canonical params do not encode "signed vs unsigned extract"

So first-wave emitter should use `ubfx`, not `sbfx`.

### Native lowering

If `effective_mask` is a contiguous low-bit field of width `field_width`:

32-bit:

```asm
ubfx wDst, wSrc, #shift, #field_width
```

64-bit:

```asm
ubfx xDst, xSrc, #shift, #field_width
```

This works for both validator shapes:

- 2-insn in-place form
- 3-insn with-copy form

because the canonical params already normalize `dst`, `src`, `shift`, `mask`, and `order`.

### Trivial special cases

If `effective_mask == 0`:

```asm
mov wDst, #0   ; width=32
mov xDst, #0   ; width=64
```

If `shift == 0` and `effective_mask == full_mask`:

- `dst == src`: emit nothing
- `dst != src`: emit `mov`

### Why not generic `lsr+and` inside the emitter?

Possible, but not necessary for the first wave.

Recommended first-wave behavior:

- emit `ubfx` when the normalized mask is contiguous
- otherwise fail closed and let stock ARM64 emit the original `rsh/and` sequence

This keeps the ARM64 canonical emitter honest: it only claims the site when it can really use the native bitfield instruction.

### 3. ARM64 encoding helpers needed

Reuse:

- `emit()`
- `emit_a64_mov_i()`
- `aarch64_insn_gen_bitfield()`

Write:

- `A64_UBFX(sf, Rd, Rn, lsb, width)` implemented as `UBFM(Rd, Rn, lsb, lsb + width - 1)`
- `A64_SBFX(sf, Rd, Rn, lsb, width)` implemented as `SBFM(...)`
- `arm64_bitfield_low_mask_width()` helper, ported from the x86 logic
- `arm64_bitfield_mask_from_imm()` helper matching the current x86 sign/zero-extension behavior for 32-bit vs 64-bit forms

### 4. Fallback behavior

Return `-EINVAL` and fall back to stock ARM64 emission if:

- param types are wrong
- `WIDTH` is not `32` or `64`
- `SHIFT >= WIDTH`
- `ORDER` is invalid
- normalized `effective_mask` is not a contiguous low-bit field

Do not emit `sbfx` in the first wave.

Reason:

- current canonical form does not encode signed extraction
- using `sbfx` would silently change semantics

### 5. Code size estimate

- emitter body: ~45-60 LOC
- mask normalization helpers and wrappers: ~25-40 LOC
- dispatch case: ~5 LOC

Total touched ARM64 LOC for this form: roughly 75-100.

### 6. Risk assessment

Main risks:

- incorrectly treating any `AND` mask as `ubfx`-compatible
- mishandling `MASK_SHIFT` normalization
- wrong 64-bit raw-mask sign extension
- accidentally using `sbfx` for an unsigned site

Testing needed:

- 2-insn and 3-insn shapes
- `SHIFT_MASK` and `MASK_SHIFT`
- contiguous masks that should become `ubfx`
- non-contiguous masks that must fail closed
- `shift=0`, `shift=width-1`, and zero-mask cases

## Form 4: COND_SELECT

### 1. Params consumed

Reads these canonical params:

- `BPF_JIT_SEL_PARAM_DST_REG`
- `BPF_JIT_SEL_PARAM_COND_OP`
- `BPF_JIT_SEL_PARAM_COND_A`
- `BPF_JIT_SEL_PARAM_COND_B`
- `BPF_JIT_SEL_PARAM_TRUE_VAL`
- `BPF_JIT_SEL_PARAM_FALSE_VAL`
- `BPF_JIT_SEL_PARAM_WIDTH`

Expected types:

- `DST_REG`: `REG`
- `COND_OP`: `IMM`
- `COND_A`: `REG`
- `COND_B`: `REG` or `IMM`
- `TRUE_VAL`: `REG` or `IMM`
- `FALSE_VAL`: `REG` or `IMM`
- `WIDTH`: `IMM`

Important point:

- the validator already normalizes guarded-update, compact, and diamond shapes into the same canonical parameter set
- the ARM64 emitter should not branch on `site_len`
- the only shape-specific effect that remains is whether `TRUE_VAL` or `FALSE_VAL` is a "noop" meaning `REG == dst`

### 2. ARM64 instruction sequence

### Compare/test phase

Map the condition exactly the way stock ARM64 jump lowering already does:

| BPF op | compare/test | ARM64 cond |
| --- | --- | --- |
| `JEQ` | `cmp` | `eq` |
| `JNE` | `cmp` | `ne` |
| `JGT` | `cmp` | `hi` |
| `JLT` | `cmp` | `cc` |
| `JGE` | `cmp` | `cs` |
| `JLE` | `cmp` | `ls` |
| `JSGT` | `cmp` | `gt` |
| `JSLT` | `cmp` | `lt` |
| `JSGE` | `cmp` | `ge` |
| `JSLE` | `cmp` | `le` |
| `JSET` | `tst` | `ne` |

Reg/reg compare:

```asm
cmp  xA, xB
tst  xA, xB    ; for JSET
```

Reg/imm compare:

- use `cmp #imm` / `cmn #(-imm)` when encodable
- otherwise:

```asm
mov  xTmp, #imm
cmp  xA, xTmp
```

For `JSET` with immediate:

- use `tst #imm` when `A64_TST_I` succeeds
- otherwise:

```asm
mov  xTmp, #imm
tst  xA, xTmp
```

### General select phase

#### Both arms already equal `dst`

Emit nothing.

#### True arm is noop (`true_val == dst`)

Materialize `false_val` if needed, then:

```asm
csel xDst, xDst, xFalse, cond
```

#### False arm is noop (`false_val == dst`)

Materialize `true_val` if needed, then:

```asm
csel xDst, xTrue, xDst, cond
```

#### General case

Materialize both candidate values into registers if needed, then:

```asm
csel xDst, xTrue, xFalse, cond
```

Use 32-bit `w*` forms when `WIDTH == 32`.

### Boolean fast paths

These are optional but recommended because they are cheap and match ARM64's strengths.

`cond ? 1 : 0`

```asm
cset xDst, cond
```

`cond ? 0 : 1`

```asm
cset xDst, inv(cond)
```

`cond ? -1 : 0`

```asm
csetm xDst, cond
```

`cond ? 0 : -1`

```asm
csetm xDst, inv(cond)
```

These are aliases of the richer conditional-select family:

- `cset` -> `csinc`
- `csetm` -> `csinv`

No first-wave use of `csneg` is required.

### How the 3 select shapes are handled

#### Guarded-update (`site_len=2`)

Canonicalization makes this:

- `true_val = dst`
- `false_val = update`

So the emitter naturally becomes:

```asm
cmp/tst ...
csel dst, dst, update, cond
```

#### Compact (`site_len=3`)

Canonicalization makes this:

- `true_val = mov_default`
- `false_val = mov_override`

General `csel` path applies directly.

#### Diamond (`site_len=4`)

Canonicalization makes this:

- `true_val = mov_true`
- `false_val = mov_false`

General `csel` path applies directly.

In other words, guarded-update/compact/diamond are not different emitter problems on ARM64; they are all the same after validator normalization.

### 3. ARM64 encoding helpers needed

Reuse:

- `emit()`
- `emit_a64_mov_i()`
- `emit_a64_add_i()` compare-immediate helpers already in stock ARM64 path
- existing `A64_CMP`, `A64_CMP_I`, `A64_CMN_I`, `A64_TST`, `A64_TST_I`

Write:

- `arm64_binding_value_is_noop()`
- `emit_arm64_binding_value()`
- `bpf_jmp_to_a64_cond()`
- `bpf_jmp_invert()` or `a64_invert_cond()`
- `emit_a64_cond_select(op, is64, dst, true_reg, false_reg, cond)` for:
  - `csel`
  - `csinc`
  - `csinv`

I would also add tiny alias helpers:

- `emit_a64_cset()`
- `emit_a64_csetm()`

### 4. Fallback behavior

Return `-EINVAL` and fall back to stock ARM64 emission if:

- param types are wrong
- `WIDTH` is not `32` or `64`
- `COND_OP` is not one of the supported BPF conditional ops
- an immediate candidate value does not fit the existing `emit_a64_mov_i()` contract (`s32`)
- compare/test immediate lowering cannot be encoded and immediate materialization also fails

If both `true_val` and `false_val` are noops, success is still correct and simply emits zero ARM64 instructions for the site.

### 5. Code size estimate

- emitter body: ~90-120 LOC
- binding/condition/select helpers: ~45-65 LOC
- dispatch case: ~5 LOC

Total touched ARM64 LOC for this form: roughly 140-190.

### 6. Risk assessment

Main risks:

- incorrect BPF-op -> ARM64-cond mapping
- forgetting that `JSET` is `tst + ne`, not `cmp`
- clobbering flags between compare/test and `csel`
- mishandling 32-bit forms and leaving stale upper 32 bits
- using too many temps when both value arms are immediates

Testing needed:

- all 3 validated source shapes
- all supported BPF condition ops
- reg/reg, reg/imm, imm/reg, imm/imm select arms
- true-noop and false-noop cases
- boolean materialization fast paths
- `WIDTH=32` and `WIDTH=64`

## ARM64 Integration Design

### 1. `bpf_jit_supports_recompile()`

ARM64 should return `true`, but only after staged-image support is added.

Required condition for flipping it on:

- ARM64 implements:
  - staged rule dispatch
  - staged image bookkeeping
  - `bpf_jit_recompile_commit()`
  - `bpf_jit_recompile_abort()`
  - header-level staged accessors are no longer stubbed on ARM64

Until then it must stay `false`/missing.

### 2. ARM64 emit dispatch

Add ARM64 equivalents of the x86 helpers:

- `bpf_jit_rule_lookup_prog()`
- `bpf_jit_try_emit_rule()`
- `bpf_jit_apply_prog_rule()`

Recommended dispatch policy:

```c
switch (rule->canonical_form) {
case BPF_JIT_CF_ROTATE:
case BPF_JIT_CF_WIDE_MEM:
case BPF_JIT_CF_BITFIELD_EXTRACT:
case BPF_JIT_CF_COND_SELECT:
    ...
default:
    return -EINVAL;
}
```

Choice handling:

- `COND_SELECT`: accept `BPF_JIT_SEL_CMOVCC`
- `WIDE_MEM`: accept `BPF_JIT_WMEM_WIDE_LOAD`
- `BITFIELD_EXTRACT`: accept `BPF_JIT_BFX_EXTRACT`
- `ROTATE`: accept both `BPF_JIT_ROT_ROR` and `BPF_JIT_ROT_RORX` and lower both identically on ARM64

Insert the apply helper at the top of the `build_body()` loop before stock `build_insn()`.

### 3. ARM64 staged image management

This is the biggest ARM64-specific integration area.

### Current ARM64 state

ARM64 already has a `jit_data` staging object, but it is only for the normal extra-pass flow. It is not sufficient for `BPF_PROG_JIT_RECOMPILE`.

Current gaps:

- no `bpf_jit_supports_recompile()`
- no `bpf_jit_recompile_commit()`
- no `bpf_jit_recompile_abort()`
- no ARM64 staged-image accessors in `bpf_jit_directives.h`
- current compile path publishes some live aux state too early for recompile

### Required ARM64 changes

#### 3.1 Extend `struct arm64_jit_data`

It needs enough state to survive until commit/abort:

- `ro_header`
- `header` only when the image is not finalized yet
- `ro_image`
- final or in-progress `ctx`
- final `prog_size`
- staged extable pointer
- staged private-stack pointer
- `allocated_priv_stack` flag

This is the ARM64 equivalent of x86's larger `struct x64_jit_data`.

#### 3.2 Move extable ownership into `jit_ctx`

Today `add_exception_handler()` writes through `ctx->prog->aux->extable`.

That is not safe for staged recompile, because the live program must keep its old extable until commit.

Design change:

- add `ctx->extable`
- add `ctx->num_exentries` or keep using `prog->aux->num_exentries`
- make `add_exception_handler()` and `validate_ctx()` use `ctx->extable`

This is the most important ARM64-specific staging difference from x86.

#### 3.3 Do not publish live aux state during recompile

During `prog->aux->jit_recompile_active`:

- do not assign newly allocated `priv_stack_ptr` to `prog->aux->priv_stack_ptr`
- do not assign staged extable to `prog->aux->extable`
- do not call `bpf_prog_update_insn_ptrs()`
- do not call `bpf_prog_fill_jited_linfo()`
- do not update `prog->bpf_func`
- do not update `prog->jited_len`

Instead, fill the `jit_recompile_*` aux fields and keep `jit_data` alive until commit/abort.

#### 3.4 Finalize staged ARM64 images before publish

Like x86, the staged ARM64 image must still go through:

- `bpf_jit_binary_pack_finalize()`
- `bpf_flush_icache()`

before it becomes the staged publish candidate.

`jit_directives.c` only delays pointer publication, not image finalization.

#### 3.5 Implement ARM64 commit

ARM64 `bpf_jit_recompile_commit()` should:

- verify `jit_data` exists and staged image is valid
- update `bpf_prog` instruction pointers from staged `ctx.offset`
- update jited line info from staged `ctx.offset`
- publish staged `priv_stack_ptr`
- publish staged extable / num_exentries
- set `prog->jited = 1`
- set `prog->jited_len`
- `smp_store_release(&prog->bpf_func, staged_func)`
- free `jit_data`, but not the staged RO image because it is now live
- clear staged aux fields

ARM64 does not currently maintain x86-style `fp_start/fp_end`, so those can remain `0` in the staged aux path.

#### 3.6 Implement ARM64 abort

ARM64 `bpf_jit_recompile_abort()` should:

- free the staged image:
  - if pre-finalize, free both `ro_header` and `header`
  - if finalized staged image, free `ro_header` only
- free staged `ctx.offset`
- free staged private stack if it was newly allocated and not the live one
- free `jit_data`
- clear staged aux fields

#### 3.7 Teach `bpf_jit_free()` to abort staged ARM64 recompiles

Mirror x86 behavior:

- if `jit_recompile_active` or a staged image exists, abort it first
- only then free the live ARM64 image

### 4. Shared header change needed

`include/linux/bpf_jit_directives.h` currently gates staged-image accessors and commit/abort declarations under `CONFIG_X86_64` only.

That must be widened to include ARM64, otherwise:

- `bpf_jit_recompile_has_staged_image()` always returns `false`
- `bpf_jit_recompile_commit()` is the stubbed `-EOPNOTSUPP`
- `bpf_jit_recompile_abort()` is the empty stub

This is a shared arch-interface change, not a control-plane logic change.

### 5. Control-plane changes needed

`jit_directives.c`: zero logic changes.

The existing control plane already does the right things:

- exact site validation
- canonical param filling
- overlap checks
- interior-edge rejection
- staged-image lifecycle orchestration
- commit/abort sequencing

What ARM64 must provide is the backend half of that contract.

## Recommended Implementation Order

1. Add ARM64 local helper wrappers:
   - `A64_EXTR`, `A64_RORV`, `A64_UBFX`, `A64_SBFX`
   - `emit_a64_cond_select()` and value/condition helpers
2. Add ARM64 rule lookup/dispatch/apply path in `build_body()`
3. Implement `ROTATE`
4. Implement `WIDE_MEM`
5. Implement `BITFIELD_EXTRACT`
6. Implement `COND_SELECT`
7. Extend `arm64_jit_data` and `jit_ctx` for staged recompile
8. Implement ARM64 `commit` / `abort` / `supports_recompile`
9. Widen `bpf_jit_directives.h` staged-image arch guard to include ARM64

This order keeps correctness bring-up simple:

- get pure-JIT emitter paths working first
- then wire staged recompile

## Validation Checklist

Per-form correctness:

- `ROTATE`: 4 source shapes, 32/64-bit, edge rotate amounts
- `WIDE_MEM`: widths 2-8, canonical little/big-endian, stack and non-stack bases
- `BITFIELD_EXTRACT`: 2/3-insn forms, both orders, contiguous/non-contiguous masks
- `COND_SELECT`: 2/3/4-insn source shapes, all cond ops, reg/imm combinations

Recompile lifecycle:

- ARM64 `BPF_PROG_JIT_RECOMPILE` no longer returns `-EOPNOTSUPP`
- staged image survives until commit
- commit swaps `bpf_func` only after all metadata are ready
- abort frees staged image and preserves live image
- zero-applied-rule case keeps the live image unchanged

Regression-sensitive areas:

- exception-table generation while a staged image exists
- private stack ownership across commit/abort
- offset collapse and `jited_linfo` correctness
- subprog extra-pass interaction with staged image pointers

## Bottom Line

The first-wave ARM64 backend is feasible without changing the control-plane logic.

The concrete design is:

- `ROTATE` -> `extr` now, `rorv` later if a register-valued rotate amount is introduced
- `WIDE_MEM` -> exact-width `ldr` chunking plus `rev*`, explicitly not `ldp`
- `BITFIELD_EXTRACT` -> `ubfx` when the normalized mask is contiguous, otherwise fail closed
- `COND_SELECT` -> `cmp/tst + csel`, with optional `cset/csetm` fast paths

The main integration work is not the per-form emitters. It is staged-image management on ARM64:

- local rule dispatch in `build_body()`
- staged extable/private-stack handling
- ARM64 `commit` / `abort`
- turning on `bpf_jit_supports_recompile()` only after those pieces exist
