# ARM64 Emitter Deep Code Review

Date: 2026-03-19

Rating: 7/10

## Findings

### 1. High: staged recompile first-pass bookkeeping diverges from x86 and likely breaks subprog recompile

`bpf_jit_recompile_stage_ok()` requires `jit_recompile_bpf_func` to be populated on every recompile pass, even before the final staged image is marked live-ish (`vendor/linux-framework/kernel/bpf/jit_directives.c:210-220`, `vendor/linux-framework/kernel/bpf/jit_directives.c:337-346`).

The ARM64 backend only publishes `jit_recompile_bpf_func` inside `if (!prog->is_func || extra_pass)` (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2993-3006`). That means first-pass recompiles of `prog->is_func` images do not expose a staged function pointer at all.

x86 does not have this hole: it always stores `jit_recompile_bpf_func` during recompile and only gates the `jit_recompile_staged` boolean on `!prog->is_func || extra_pass` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5785-5798`).

Impact:
- Single-entry programs are fine.
- Multi-function / bpf-to-bpf-call programs on ARM64 are likely to fail the first `stage_ok(..., final_pass=false)` check with `-EIO`.
- Current selftests do not appear to cover this path; the shipped test programs are all single-entry XDP programs under `tests/kernel/progs/`.

### 2. Medium: `BITFIELD_EXTRACT` does not preserve site-local fallback for valid non-`UBFX` cases

The validator accepts generic `rsh+and` / `and+rsh` sites and does not require that the extracted field width fit `shift + field_width <= width` (`vendor/linux-framework/kernel/bpf/jit_validators.c:811-926`).

The ARM64 emitter only checks that the effective mask is a contiguous low-bit mask, then emits `A64_UBFX(...)` unconditionally (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:842-873`). But `A64_UBFX` is just `UBFM(lsb, lsb + width - 1)` (`vendor/linux-framework/arch/arm64/net/bpf_jit.h:214-215`), and the generic AArch64 encoder returns `AARCH64_BREAK_FAULT` if `imms` overflows the architectural bit-width (`vendor/linux-framework/arch/arm64/lib/insn.c:819-871`).

So a valid canonical site such as a large post-shift mask can:
- pass validation,
- reach the ARM64 emitter,
- generate `BREAK_FAULT` instead of returning `-EINVAL`,
- skip the intended per-site fallback path,
- and fail later in `validate_ctx()`, turning a local emitter miss into a whole-program recompile failure.

x86 is more robust here: it only uses `BEXTR` opportunistically and otherwise falls back to explicit `SHR+AND` lowering (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3257-3300`).

## Assessment

### ISA encoding correctness

`A64_EXTR` is correct. It forwards operands to `aarch64_insn_gen_extr()` in the right `Rm, Rn, Rd` order (`vendor/linux-framework/arch/arm64/net/bpf_jit.h:210-213`), and the rotate emitter uses `EXTR src, src, #width-amount`, which matches the existing rotate canonical params (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:706-741`).

`A64_UBFX` is correct as a helper for representable cases. `UBFX Rd, Rn, #lsb, #width` is the standard `UBFM Rd, Rn, lsb, lsb+width-1` encoding (`vendor/linux-framework/arch/arm64/net/bpf_jit.h:214-215`). The bug is not the helper formula; it is the missing representability guard in the emitter.

The manual `CSEL`/`CSINC`/`CSINV` encoder is correct. The opcode bases and field placement in `a64_gen_cond_select()` (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:466-510`) match A64 encodings. I spot-checked them against GNU `aarch64-linux-gnu-as`:
- `csel x3, x4, x5, eq` -> `0x9a850083`
- `csinc x3, xzr, xzr, ne` -> `0x9a9f17e3`
- `csinv x3, xzr, xzr, ne` -> `0xda9f13e3`

### Security / fail-closed behavior

The ARM64 emitter path consumes validated `canonical_params`, not raw user-provided insns. Dispatch goes from validated rule lookup to `rule->params` only (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1000-1038`).

Shared fail-closed arch gating is intact:
- validators reject unsupported forms via `bpf_jit_arch_form_supported()` before activation (`vendor/linux-framework/kernel/bpf/jit_validators.c:1541-1595`)
- ARM64 only advertises `COND_SELECT`, `WIDE_MEM`, `ROTATE`, and `BITFIELD_EXTRACT` (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:4004-4018`)

Per-site fallback is structurally correct for rotate, wide load, and select. `bpf_jit_apply_prog_rule()` snapshots `ctx->idx` / `ctx->exentry_idx`, resets them on emitter error, and falls back to stock lowering (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1041-1065`).

The exception is `BITFIELD_EXTRACT`: the current code can emit `BREAK_FAULT` instead of returning `-EINVAL`, so fail-closed is preserved only at whole-recompile rollback granularity, not at the intended site-local fallback granularity.

### Staged recompile lifecycle

For single-image / single-entry programs, the ARM64 staged lifecycle is otherwise sound:
- `build_body()` integration is in the right place and collapses offsets consistently (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2630-2677`)
- commit updates insn pointers, line info, extable, private stack, and `bpf_func`, then frees staging state (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3062-3087`)
- abort frees staged image/state and clears the staged markers (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3090-3110`)
- shared staged accessors/prototypes are correctly widened to ARM64 (`vendor/linux-framework/include/linux/bpf_jit_directives.h:180-222`)

The lifecycle is not correct for first-pass subprog recompiles because of finding #1.

### Form coverage

Implemented coverage matches the intended first wave:
- `ROTATE -> extr/ror` is correctly wired for immediate rotates (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:706-741`)
- `WIDE_MEM -> ldr{b,h,w,x} + rev* + chunking` is implemented and mirrors x86’s exact-width chunking strategy (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:744-810`)
- `COND_SELECT -> cmp/tst + csel/cset/csetm` is implemented and reasonable (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:876-981`)
- `BITFIELD_EXTRACT -> ubfx` is only partially covered in practice because the emitter currently assumes every contiguous-low-mask case is representable as `UBFX`

### Missing items

`ADDR_CALC` and `BRANCH_FLIP` are still missing on ARM64. That matches the gap analysis: they remain plausible second-wave ports, but they are not accidental omissions in this first-wave implementation.

`ZERO_EXT_ELIDE` and `ENDIAN_FUSION` should stay unsupported on ARM64 for now. The gap analysis explicitly argues they are poor ARM64 targets, and the current `bpf_jit_arch_form_supported()` rejection is the right fail-closed behavior.

### Comparison with x86

Good matches:
- same `build_body()`-level rule dispatch shape
- same validated-param-only emitter interface
- same offset-collapse model
- same commit/abort split

Important ARM64 regressions vs x86:
- x86 stages `jit_recompile_bpf_func` on every recompile pass; ARM64 currently does not
- x86 `BITFIELD_EXTRACT` has a general fallback path when `BEXTR` is not appropriate; ARM64 currently jumps straight to `UBFX`

## Bottom line

The core ARM64 emitter design is good, and the A64 instruction selection itself is mostly correct. `ROTATE`, `WIDE_MEM`, and `COND_SELECT` look solid. The two issues above are the blockers to calling the implementation production-ready:

1. fix subprog first-pass staging to match x86 semantics
2. make `BITFIELD_EXTRACT` return `-EINVAL` for non-`UBFX` cases, or add an ARM64 fallback lowering analogous to x86’s `SHR+AND`

Without those fixes, I would not fully trust ARM64 recompile on multi-function programs, and I would not consider the current `BITFIELD_EXTRACT` path to preserve the intended emitter-level fail-closed behavior.
