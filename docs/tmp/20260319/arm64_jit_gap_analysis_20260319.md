# ARM64 Kernel BPF JIT Gap Analysis

Date: 2026-03-19

## Scope

This report answers one question: for the stock ARM64 kernel BPF JIT, which of the 8 BpfReJIT canonical forms still represent real optimization gaps on ARM64, and which ones do not.

Inputs used:

- Project context: `docs/kernel-jit-optimization-plan.md`
- ARM64 JIT source: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- Baseline comparison: `vendor/linux-baseline/arch/arm64/net/bpf_jit_comp.c`
- Existing benchmark/docs context:
  - `docs/tmp/2026-03-08/arm64-cross-arch-analysis.md`
  - `docs/tmp/2026-03-11/arm64-analysis-review.md`
  - `docs/tmp/micro-per-form-ablation.md`
  - `docs/tmp/2026-03-11/corpus-8families-census.md`
  - `docs/tmp/arm64_cross_compile_qemu_20260319.md`
  - `docs/tmp/arm64_e2e_verification_20260319.md`

Constraints followed:

- No kernel code was modified.
- ARM64 QEMU validation used the existing `make vm-arm64-smoke` flow plus a temporary userspace loader to dump JIT images.

## Executive Summary

The stock ARM64 JIT is a per-BPF-op translator, not a peephole optimizer. `build_body()` just walks BPF insns and calls `build_insn()` one at a time; there is no generic neighboring-insn pattern recovery in the stock backend (`bpf_jit_comp.c:1201-1900`, `1902-1938`).

The ARM64 framework and baseline JIT files are byte-identical, so there is no local delta to account for here.

### Bottom line

| Form | ARM64 gap? | Call |
| --- | --- | --- |
| `COND_SELECT` | real but policy-sensitive | `PARTIAL` |
| `ROTATE` | clear missing lowering | `YES` |
| `WIDE_MEM` | clear missing lowering | `YES` |
| `ADDR_CALC` | real but smaller payoff | `PARTIAL` |
| `BITFIELD_EXTRACT` | clear missing lowering | `YES` |
| `ZERO_EXT_ELIDE` | already mostly free on ARM64 | `NO` |
| `ENDIAN_FUSION` | stock ARM64 already emits native endian ops | `NO` |
| `BRANCH_FLIP` | missing, but profitability depends on bias/layout | `PARTIAL` |

### Porting recommendation

- First-wave ARM64 ports: `ROTATE`, `WIDE_MEM`, `BITFIELD_EXTRACT`, `COND_SELECT`
- Second-wave / lower-priority ARM64 ports: `ADDR_CALC`, `BRANCH_FLIP`
- Do not port as-is: `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`

So the practical answer is:

- `4` forms are worth porting now
- `2` more are plausible ARM64 follow-ups
- `2` should be skipped on ARM64 in their current x86-defined form

## Relation To Existing Measurements

These ARM64 conclusions are consistent with, but not identical to, the existing x86 story.

- The authoritative x86 pure-JIT characterization gap in the project hub is `L/K = 0.609x`. That is the upper bound on how much backend-only quality improvement exists in the stock-vs-LLVM comparison; it is not a direct prediction of ARM64 re-JIT speedup.
- Existing ARM64 pure-JIT characterization is already strong at `L/K = 0.656`, so ARM64 clearly has meaningful stock-JIT headroom too.
- The x86 per-form ablation result is still useful as a caution signal:
  - `ROTATE 0.923x` was the clearest win
  - `ENDIAN 0.981x` and `BRANCH_FLIP 0.992x` were small/policy-sensitive wins
  - `ADDR_CALC 0.999x` was near-neutral
  - `WIDE 1.007x`, `EXTRACT 1.067x`, and `COND_SELECT 1.068x` showed that “real codegen gap exists” and “blindly enable this form” are different questions
- The 8-family site census is also relevant:
  - x86 per-section census reported large `endian` and `bflip` populations but `zeroext=0`
  - this matches the ARM64 source conclusion that `ZERO_EXT_ELIDE` is not a good ARM64 port target either

The main implication is:

- x86 data are useful for prioritization and for spotting policy-sensitive families
- but ARM64 emitted-code evidence is still required, because some x86 forms transfer poorly (`ENDIAN_FUSION`) while some ARM64 base-ISA features make the case stronger (`BITFIELD_EXTRACT`)

## Stock ARM64 JIT Characteristics

Key source facts:

- Immediate add lowering is in `emit_a64_add_i()`, which only does `ADD/SUB immediate` or `mov imm + ADD`; it does not exploit shifted-register add forms (`bpf_jit_comp.c:295-306`).
- ALU register ops are direct one-op mappings such as `ADD`, `LSLV`, `LSRV`, `ASRV`, `ORR`, `EOR` (`bpf_jit_comp.c:1265-1315`).
- Endian ops already lower directly to `REV16`, `REV32`, `REV64`, with `UXTH/UXTW` when needed (`bpf_jit_comp.c:1322-1360`).
- Conditional jumps are emitted as `CMP/TST` followed by `B.cond`; there is no `csel` family lowering (`bpf_jit_comp.c:1463-1567`).
- Memory ops lower to scalar `LDRB/H/W/X`, `LDRSB/H/SW`, `STRB/H/W/X`; there is no normal multi-load fusion in the BPF memory path (`bpf_jit_comp.c:1642-1863`).
- The file contains no generic lowering use of `csel`, `csinc`, `csinv`, `csneg`, `ror`, `rorv`, `extr`, `ubfx`, `sbfx`, or `ubfiz`. `stp/ldp` appear only in prologue/epilogue save-restore code, not in BPF memory-op lowering.

This matters because the 8 canonical forms are all pattern recoveries across multiple BPF insns. The stock ARM64 JIT mostly never tries to do that.

## QEMU Validation

I validated the source reading with actual ARM64 JIT output in QEMU.

Because the minimal ARM64 guest did not have a convenient `bpftool` flow, and ARM64 `BPF_PROG_JIT_RECOMPILE` is currently `-EOPNOTSUPP`, I used a small temporary ARM64 libbpf loader to:

- load selected `.bpf.o` programs inside the guest
- fetch `bpf_prog_info.jited_prog_insns`
- dump the JIT image as hex
- disassemble it on the host with `aarch64-linux-gnu-objdump`

Representative emitted-code observations:

| Program | What the ARM64 JIT emitted | Conclusion |
| --- | --- | --- |
| `cmov_select` | `cmp` + `b.hi` / `b.ne`, no `csel` | branchy select, no conditional-select recovery |
| `rotate64_hash` | `lsl/lsr/orr`, no `ror` or `extr` | no rotate idiom recovery |
| `load_byte_recompose` | repeated `ldrb` + `lsl` + `orr` ladders | no byte-ladder fusion |
| `addr_calc_stride` | `lsl x3, x3, #3` then `add x3, x3, x1` | no shifted-register add fusion |
| `extract_dense` | `lsr` + `and`, no `ubfx/sbfx` | no bitfield-extract lowering |
| `endian_swap_dense` | repeated `rev w2, w2` | endian lowering already good |
| `branch_flip_dense` | `cmp` + `b.eq` style branches | no branch inversion/layout rewrite |

Useful snippets from the disassembly:

- `cmov_select`: `cmp x0, x1` then `b.hi`, later `cmp x0, #0x6c` then `b.ne`
- `load_byte_recompose`: `ldrb`, `lsl`, `orr` ladders like `ldrb w1, [x0, #9]`; `lsl x1, x1, #8`; `orr x1, x1, x2`
- `addr_calc_stride`: `lsl x3, x3, #3`; `add x3, x3, x1`
- `extract_dense`: `lsr x3, x3, #17`; `and x3, x3, #0x3ff`
- `endian_swap_dense`: `ldr w2, [x0, #8]`; `rev w2, w2`

This emitted-code evidence matches the source reading.

## Per-Form Analysis

## 1. `COND_SELECT`

### Stock ARM64 behavior

The stock ARM64 backend emits compare/test plus conditional branch for BPF jumps (`bpf_jit_comp.c:1463-1567`). I did not find any `csel`-family lowering in the file.

The QEMU `cmov_select` JIT image confirms this: it contains `cmp` and `b.hi` / `b.ne`, not `csel`.

### ARM64 ISA opportunity

ARM64 has native conditional-select instructions:

- `csel`
- `csinc`
- `csinv`
- `csneg`

These are the natural ARM64 analog of x86 `cmovcc`, and they map well to short select diamonds and guarded updates.

### Assessment

`PARTIAL`

This is a real codegen gap, but it is not an always-on win.

Why not `YES` outright:

- Existing x86 per-form ablation shows select lowering is policy-sensitive, not universally positive.
- Existing ARM64 pure-JIT data still show a large LLVM win on `cmov_select` (`L/K = 0.345`), which proves the gap exists, but not that unconditional `csel` conversion is always right.

### If implemented

Emit:

- `csel` for plain `dst = cond ? a : b`
- `csinc/csinv/csneg` for common booleanized or increment/invert variants

Estimated complexity:

- Medium

Priority:

- Medium-high, but policy-controlled rather than always-on

## 2. `ROTATE`

### Stock ARM64 behavior

The backend lowers shifts directly to `LSLV/LSRV/ASRV` or immediate `LSL/LSR/ASR` (`bpf_jit_comp.c:1304-1315`, `1435-1445`).

There is no rotate idiom recognizer in the source, and the QEMU `rotate64_hash` disassembly contains `lsl/orr` sequences but no `ror`, `rorv`, or `extr`.

### ARM64 ISA opportunity

ARM64 has native rotate support:

- `ror` for constant rotates
- `rorv` for variable rotates
- `extr dst, src, src, imm` as the underlying constant-rotate encoding

### Assessment

`YES`

This is a clear ARM64 backend gap. The stock JIT is leaving real instructions on the table.

### If implemented

Emit:

- `ror` / `extr` for constant rotate idioms
- `rorv` for variable rotate idioms

Estimated complexity:

- Medium

Priority:

- High

## 3. `WIDE_MEM`

### Stock ARM64 behavior

The stock backend only emits scalar loads/stores in the BPF memory path: `LDRB/H/W/X`, sign-extending variants, and matching stores (`bpf_jit_comp.c:1642-1863`).

The QEMU `load_byte_recompose` JIT image shows exactly the byte ladder we would expect from a non-fusing backend:

- `ldrb`
- `lsl`
- `orr`
- repeated many times

### ARM64 ISA opportunity

The most relevant ARM64 opportunity is not `ldp`; it is:

- replacing byte ladders with a single wider `ldr wN` / `ldr xN` when legality allows
- optionally pairing with `rev` when the byte ladder is building a big-endian scalar

`ldp` is a secondary ARM64-specific opportunity for clustered independent loads, but it is not the main analog of x86 byte-recompose fusion.

### Assessment

`YES`

This is one of the clearest ARM64 gaps:

- the stock backend does not recover byte-ladder patterns
- emitted code confirms the ladder is still there
- existing ARM64 pure-JIT results show `load_byte_recompose` is a strong LLVM win (`L/K = 0.351`)

### If implemented

Emit:

- `ldr wN` / `ldr xN` for legal contiguous byte ladders
- optionally `rev` after wide load when the reconstructed scalar is endian-swapped relative to memory order

Estimated complexity:

- Medium-high

Notes:

- legality depends on access class, offset range, exception behavior, and whether the wider load would touch bytes beyond the originally proven safe window
- packet/ctx loads need more care than stack/map loads

Priority:

- High

## 4. `ADDR_CALC`

### Stock ARM64 behavior

The backend emits separate shift and add instructions:

- `ADD` for `BPF_ADD | X` (`bpf_jit_comp.c:1265-1268`)
- `LSLV/LSL` for shifts (`bpf_jit_comp.c:1304-1315`, `1435-1445`)
- `emit_a64_add_i()` also does not use shifted-register addressing (`bpf_jit_comp.c:295-306`)

The QEMU `addr_calc_stride` image confirms this with sequences like:

- `lsl x3, x3, #3`
- `add x3, x3, x1`

### ARM64 ISA opportunity

ARM64 can fuse many address-calculation patterns directly:

- `add dst, base, idx, lsl #imm`
- similarly `sub ... , lsl #imm`

This is the ARM64 analog of x86 `lea`-style fusion.

### Assessment

`PARTIAL`

This is a real missed lowering, but likely a smaller payoff than `ROTATE`, `WIDE_MEM`, or `BITFIELD_EXTRACT`.

Reasons for `PARTIAL`:

- the source and QEMU output clearly show the missed fusion
- but x86 per-form data suggest this family is low magnitude
- ARM64 will save instructions here, but the dynamic impact is likely workload-dependent

### If implemented

Emit:

- shifted-register `add/sub` for local `shift -> add/sub` patterns with single use

Estimated complexity:

- Low-medium

Priority:

- Medium, after the higher-value forms

## 5. `BITFIELD_EXTRACT`

### Stock ARM64 behavior

There is no `ubfx`/`sbfx` lowering in the source. The backend emits the obvious primitive ops instead.

The QEMU `extract_dense` disassembly shows repeated:

- `lsr x3, x3, #17`
- `and x3, x3, #0x3ff`

### ARM64 ISA opportunity

ARM64 has first-class bitfield extraction:

- `ubfx` for unsigned extract
- `sbfx` for signed extract

This is a base-ISA feature, not an optional extension.

### Assessment

`YES`

This is a clear ARM64 gap. Unlike x86 BMI-specific `bextr`, ARM64 bitfield extract is always available, which makes the case stronger on ARM64 than on x86.

### If implemented

Emit:

- `ubfx dst, src, lsb, width`
- `sbfx dst, src, lsb, width` when sign-extension semantics match

Estimated complexity:

- Low-medium

Priority:

- High

## 6. `ZERO_EXT_ELIDE`

### Stock ARM64 behavior

ARM64 already gets most of this “for free” because writes to `Wn` zero-extend into `Xn`.

The source explicitly relies on this:

- `A64_MOV(0, tmp, src)` comment: `32-bit mov clears the upper 32 bits` (`bpf_jit_comp.c:1231-1237`)
- endian-32 path comment: `upper 32 bits already cleared` (`bpf_jit_comp.c:1339-1341`)
- 32-bit ALU paths use `is64 = 0`, so the backend naturally emits `W`-register forms

### ARM64 ISA opportunity

There is no x86-style `movzx` tax to avoid here in the common case. ARM64 already makes 32-bit writes zeroing writes.

### Assessment

`NO`

This canonical form is not worth porting to ARM64 in its current meaning. The stock ARM64 JIT already benefits from automatic zero-extension semantics.

### If implemented

I would not port this form unless a very specific verifier-inserted redundant-zext pattern shows up in ARM64 emitted code and survives the existing `W`-register lowering. I did not find evidence of that here.

Priority:

- None

## 7. `ENDIAN_FUSION`

### Stock ARM64 behavior

The stock ARM64 backend already lowers `BPF_END` directly to native byte-swap instructions:

- `REV16`
- `REV32`
- `REV64`

Source: `bpf_jit_comp.c:1322-1360`

The QEMU `endian_swap_dense` image confirms repeated `rev w2, w2`.

### ARM64 ISA opportunity

ARM64 does not have an x86 `movbe`-style “load and byte-swap in one memory op” equivalent for this use case. The natural lowering is already `ldr + rev`.

That means the x86-defined `ENDIAN_FUSION` form does not transfer cleanly.

### Assessment

`NO`

For ARM64, explicit endian conversion is already lowered the right way. Any remaining opportunity is really a different form:

- wide-load plus `rev`
- or packet/ctx structural load fusion

Those belong under `WIDE_MEM` or a new ARM64-specific family, not under x86-style `ENDIAN_FUSION`.

Priority:

- None

## 8. `BRANCH_FLIP`

### Stock ARM64 behavior

The backend preserves BPF branch structure and emits direct `B.cond` branches using the original control flow (`bpf_jit_comp.c:1453-1567`). There is no body swap / branch inversion pass.

The QEMU `branch_flip_dense` image shows repeated `cmp` + `b.eq` style branches, which is exactly what the source suggests.

### ARM64 ISA opportunity

ARM64 can obviously invert branch conditions and swap straight-line bodies just like x86 can. There is no ISA blocker.

### Assessment

`PARTIAL`

This is a real missing optimization, but it is inherently policy-sensitive:

- it depends on branch bias
- it depends on code size and layout
- it depends on whether the hot path should become fall-through

So there is a gap, but not one that should be blindly enabled.

### If implemented

Emit:

- inverted `B.cond`
- swapped if/else bodies when the canonical site is a local diamond and bias data says flip helps

Estimated complexity:

- Medium

Priority:

- Low-medium unless you also have branch-bias information

## Recommended ARM64 Port Order

### Port now

1. `ROTATE`
2. `WIDE_MEM`
3. `BITFIELD_EXTRACT`
4. `COND_SELECT`

Rationale:

- these are the clearest missing lowerings in both source and emitted code
- they map directly to strong ARM64 ISA features
- existing ARM64 pure-JIT results already support real backend gaps for at least the select and byte-ladder cases

### Port later if needed

1. `ADDR_CALC`
2. `BRANCH_FLIP`

Rationale:

- both are real gaps
- both are likely lower-yield than the first-wave set
- both need tighter profitability discipline

### Do not port

1. `ZERO_EXT_ELIDE`
2. `ENDIAN_FUSION`

Rationale:

- ARM64 already gets the first mostly for free
- ARM64 already lowers the second to the natural native instructions, and lacks a direct `movbe` analog anyway

## Should We Run Pure-JIT ARM64 Benchmarks?

Yes.

But the right framing is:

- static analysis is already sufficient to choose the first ARM64 forms to port
- authoritative ARM64 pure-JIT benchmarking is still needed to quantify payoff and rank the borderline forms

Why `yes`:

- there is already evidence of a meaningful ARM64 stock-kernel gap: existing ARM64 pure-JIT geomean is `L/K = 0.656`
- ARM64-specific cases already line up with this source pass:
  - `cmov_select`: `0.345`
  - `load_byte_recompose`: `0.351`
- `docs/tmp/2026-03-11/arm64-analysis-review.md` is correct that cross-arch ratio data alone are not enough for publication-grade backend claims; emitted-code evidence was missing there, and this report now supplies part of that missing evidence

Recommendation:

- do not block the initial ARM64 port on another benchmark rerun
- but before making paper claims or spending time on second-wave forms, run an authoritative same-SHA ARM64 pure-JIT characterization pass
- the most useful ARM64 rerun is `llvmbpf-arm64 vs stock kernel-arm64`, not ARM64 recompile, because ARM64 recompile is still unsupported today

## ARM64-Specific Opportunities Outside The 8 Forms

Yes, ARM64 has worthwhile opportunities not captured cleanly by the current 8 x86-defined forms.

### 1. Zero/test branch specialization

Likely candidates:

- `cbz` / `cbnz` for compare-against-zero branches
- `tbz` / `tbnz` for single-bit tests

Why this matters:

- stock ARM64 currently emits `cmp/tst` plus `b.cond`
- ARM64 has dedicated branch instructions for exactly these common cases

### 2. Generalized bitfield family beyond extract

Likely candidates:

- `bfxil`
- `ubfiz`
- `bfi`

Why this matters:

- ARM64 bitfield instructions are richer than just `ubfx/sbfx`
- some shift-mask-insert patterns are probably better expressed as a distinct ARM64 family

### 3. Conditional-result materialization beyond plain select

Likely candidates:

- `cset`
- `csinc`
- `csinv`
- `csneg`

Why this matters:

- ARM64’s select family is broader than “plain `csel`”
- boolean materialization and guarded arithmetic may deserve an ARM64-specific subfamily rather than being squeezed into x86-style `COND_SELECT`

### 4. Pair-load/store shaping

Likely candidates:

- `ldp`
- `stp`

Why this matters:

- not for byte-recompose itself
- but potentially for clustered stack traffic or adjacent independent loads/stores if safety and exception semantics allow it

This is more speculative than the first three items above.

## Final Conclusion

ARM64 does not simply inherit the x86 answer.

What clearly carries over:

- `ROTATE`
- `WIDE_MEM`
- `BITFIELD_EXTRACT`
- the underlying `COND_SELECT` gap

What clearly does not:

- `ZERO_EXT_ELIDE`
- `ENDIAN_FUSION`

What remains real but secondary:

- `ADDR_CALC`
- `BRANCH_FLIP`

If the goal is a pragmatic ARM64 port, I would implement the first-wave set only:

1. `ROTATE`
2. `WIDE_MEM`
3. `BITFIELD_EXTRACT`
4. `COND_SELECT` with explicit policy control

Then rerun ARM64 pure-JIT characterization to decide whether `ADDR_CALC` and `BRANCH_FLIP` are worth the extra complexity.
