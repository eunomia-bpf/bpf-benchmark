# Inline Kfunc Feasibility on `vendor/linux-framework/` (7.0-rc2)

Scope: analyze whether a new "Inline Kfunc" mechanism can reuse the existing kfunc verifier/interpreter model and only extend JIT `BPF_CALL` lowering on x86 and arm64.

All source references below are from this tree and use `path:line` ranges.

## Executive Summary

- The core idea is feasible in this tree if "kinsn" means: keep existing kfunc verification and fixup semantics, keep the real kfunc body as the canonical fallback implementation, and teach x86/arm64 JITs to optionally replace a kfunc `CALL` with a straight-line native sequence. The verifier type/ownership checks in `check_kfunc_call()` do not need semantic changes for the base design. Relevant code: `kernel/bpf/verifier.c:14088-14480`.
- The current kernel already has two strong precedents:
  - verifier-side kfunc rewrites that fully replace some kfunc calls with plain BPF instructions in `fixup_kfunc_call()` (`bpf_cast_to_kern_ctx`, `bpf_rdonly_cast`, `bpf_session_is_return`, `bpf_session_cookie`), see `kernel/bpf/verifier.c:23215-23310`;
  - JIT-side native alternative emission in the current BpfReJIT path (`bpf_jit_try_emit_rule()` on x86/arm64), see `arch/x86/net/bpf_jit_comp.c:3041-3078` and `arch/arm64/net/bpf_jit_comp.c:844-886`.
- `fixup_kfunc_call()` already converts the user-visible BTF ID into a real kernel target address using a per-program descriptor table. That descriptor is initially populated by `add_kfunc_call()` with `kallsyms_lookup_name(kfunc.name)`, then optionally specialized by `specialize_kfunc()`. Relevant code: `kernel/bpf/verifier.c:3432-3524`, `kernel/bpf/verifier.c:23117-23165`, `kernel/bpf/verifier.c:23184-23323`.
- No fixup change is required for the base design. JITs can recover per-kfunc metadata through the same per-program `kfunc_tab` lookup pattern already used by `bpf_jit_find_kfunc_model()`, which keys on final `insn->imm` + `insn->off`. Relevant code: `kernel/bpf/verifier.c:3558-3599`, `include/linux/bpf.h:3099-3104`.
- The main caveat is interpreter fallback: technically the interpreter `JMP_CALL` path can execute a fixed-up kfunc call because it only needs `insn->imm` as `__bpf_call_base` relative offset (`kernel/bpf/core.c:2114-2129`), but current policy explicitly forbids non-JIT runtime for any program that has kfunc calls. That policy lives in `add_kfunc_call()` and `bpf_prog_select_runtime()`: `kernel/bpf/verifier.c:3446-3460`, `kernel/bpf/core.c:2599-2632`. So "fallback to normal JIT CALL" is true with zero extra work; "fallback to interpreter" is not currently enabled.
- The most upstream-friendly shape is therefore:
  - `v1`: JIT-only inline expansion with normal kfunc call fallback;
  - `v1.5` optional: relax current "kfunc requires JIT" policy if true interpreter fallback is desired;
  - `v2` optional: persist verifier-proven constant kfunc arguments into JIT-visible metadata to enable immediate-specialized encodings such as `RORX imm8`.

## 1. Current Kfunc Pipeline

### 1.1 Descriptor creation before full verification

The verifier collects kfunc calls very early in `add_subprog_and_kfunc()`. Any instruction with `src_reg == BPF_PSEUDO_KFUNC_CALL` triggers `add_kfunc_call(env, insn->imm, insn->off)`. Relevant code:

- `kernel/bpf/verifier.c:269-273` defines `bpf_pseudo_kfunc_call()`.
- `kernel/bpf/verifier.c:3616-3644` calls `add_kfunc_call()` for every pseudo kfunc call.
- `kernel/bpf/verifier.c:26008-26020` shows this happens before main verification.

`add_kfunc_call()` does the important descriptor setup:

1. Allocates `prog->aux->kfunc_tab` on first use (`kernel/bpf/verifier.c:3443-3471`).
2. Resolves the BTF and prototype through `fetch_kfunc_meta()` (`kernel/bpf/verifier.c:3497-3499`, `kernel/bpf/verifier.c:3369-3430`).
3. Resolves the initial implementation address with `kallsyms_lookup_name(kfunc.name)` (`kernel/bpf/verifier.c:3501-3504`).
4. Distills a `struct btf_func_model` for later JIT/trampoline use (`kernel/bpf/verifier.c:3513-3521`, `kernel/bpf/btf.c:7462-7526`).
5. Stores `{ func_id, offset, addr, func_model }` into `prog->aux->kfunc_tab` (`kernel/bpf/verifier.c:3517-3524`).

Important detail: `desc->addr` is obtained from `kallsyms_lookup_name()`, not from `module_kallsyms_lookup_name()`, and not inside `fixup_kfunc_call()`. The only later mutation of `desc->addr` is `specialize_kfunc()`.

### 1.2 Verifier validation path

`check_kfunc_call()` performs the full verifier-side type, ownership, sleepability, callback, and return-value logic for kfuncs. Relevant code: `kernel/bpf/verifier.c:14088-14480`.

This path is already independent from JIT lowering:

- it fetches metadata through `fetch_kfunc_arg_meta()` (`kernel/bpf/verifier.c:14106-14113`, `kernel/bpf/verifier.c:13880-13903`);
- it checks argument types and records special cases in `check_kfunc_args()` (`kernel/bpf/verifier.c:13333-13880`);
- it marks caller-saved registers invalid after the call (`kernel/bpf/verifier.c:14320-14325`);
- it sets up the return type/state in `R0` (`kernel/bpf/verifier.c:14327-14444`).

For the base Inline Kfunc design, this verifier logic does not need to change.

### 1.3 Fixup: `fixup_kfunc_call()`

`do_misc_fixups()` handles surviving `BPF_CALL` instructions after verification. The kfunc branch is:

- `kernel/bpf/verifier.c:23696-23715`.

`fixup_kfunc_call()` itself is at:

- `kernel/bpf/verifier.c:23184-23323`.

The base flow is:

1. Reject `imm == 0` if dead-code elimination did not remove it (`23190-23193`).
2. Lookup the descriptor with `find_kfunc_desc(env->prog, insn->imm, insn->off)` (`23201-23206`).
3. Call `specialize_kfunc()` to swap the address for context-specific variants (`23208-23210`, specialization body at `23117-23165`).
4. If the arch does not support far kfunc calls, rewrite `insn->imm = BPF_CALL_IMM(desc->addr)` (`23212-23213`).

`BPF_CALL_IMM(x)` is defined as the offset from `__bpf_call_base`: `include/linux/filter.h:465-475`.

In this tree, neither x86 nor arm64 overrides `bpf_jit_supports_far_kfunc_call()`, so both inherit the default `false` implementation from `kernel/bpf/core.c:3212-3215`. Therefore, on both studied JITs, the fixed-up kfunc call immediate is the same 32-bit relative helper-call style immediate.

`specialize_kfunc()` only changes `desc->addr`; it does not change the verifier model or the instruction encoding format. Existing specializations include:

- device-bound kfunc resolution (`kernel/bpf/verifier.c:23131-23135`);
- `bpf_dynptr_from_skb` readonly variant (`23136-23146`);
- locked xattr helpers (`23147-23152`);
- sleepable/non-sleepable file/arena variants (`23153-23161`).

### 1.4 What happens to `src_reg` and `off`

If the kfunc remains a call, `fixup_kfunc_call()` does not overwrite `insn->src_reg` or `insn->off`.

- There is no `src_reg = 0` in `fixup_kfunc_call()` (`23184-23323`).
- When extra BPF instructions are inserted, the final patched call copies `*insn`, preserving `src_reg` and `off` (`23227-23231`, `23251-23254`, `23317-23320`).

This is consistent with later code:

- `bpf_jit_get_func_addr()` still checks `insn->src_reg == BPF_PSEUDO_KFUNC_CALL` for far-call arches (`kernel/bpf/core.c:1336-1364`);
- `bpf_jit_find_kfunc_model()` does JIT-side lookup by final `imm + off` (`kernel/bpf/verifier.c:3583-3599`).

So the correct statement is:

- if a kfunc call survives fixup, `src_reg` remains `BPF_PSEUDO_KFUNC_CALL`;
- if a kfunc is fully rewritten into plain BPF instructions, the call instruction disappears entirely.

## 2. Existing "Inline Kfunc" Precedents

### 2.1 Kfunc-specific verifier rewrites already exist

`fixup_kfunc_call()` already has two different classes of kfunc-specific lowering:

1. Add hidden arguments before a real call:
   - `bpf_obj_new_impl` / `bpf_percpu_obj_new_impl`: prepend `MOV`/`LD_IMM64`, then keep the call (`kernel/bpf/verifier.c:23215-23231`);
   - `bpf_obj_drop_impl`, `bpf_percpu_obj_drop_impl`, `bpf_refcount_acquire_impl`: prepend `LD_IMM64`, then keep the call (`23232-23254`);
   - list/rbtree insertion helpers: prepend `struct_meta` / `node_offset`, then keep the call (`23255-23275`);
   - implicit `prog->aux` argument injection via `arg_prog` (`23312-23320`).

2. Fully replace the kfunc call with plain BPF instructions:
   - `bpf_cast_to_kern_ctx`: `r0 = r1` (`23276-23279`);
   - `bpf_rdonly_cast`: same rewrite (`23276-23279`);
   - `bpf_session_is_return`: 3 BPF instructions (`23280-23292`);
   - `bpf_session_cookie`: 6 BPF instructions (`23293-23309`).

This is already an existence proof that:

- kfuncs are not treated as "must always lower to CALL";
- kfunc identity can drive special lowering logic after verification;
- upstream code already accepts kfunc-specific rewrite stages.

### 2.2 Helper inline precedents also exist

Two helper inline precedents matter because the proposed Inline Kfunc dispatch lives in the same JIT `CALL` lowering slot:

- verifier-side helper inlining on x86-friendly paths in `do_misc_fixups()`:
  - `bpf_get_smp_processor_id()` (`kernel/bpf/verifier.c:23996-24022`);
  - `bpf_get_current_task()` / `_btf()` (`24024-24040`);
  - gate function `verifier_inlines_helper_call()` (`18289-18307`).

- JIT-side helper inlining on arm64:
  - inline `bpf_get_smp_processor_id()` and `bpf_get_current_task*()` directly in `build_insn()` (`arch/arm64/net/bpf_jit_comp.c:2139-2157`);
  - advertise this through `bpf_jit_inlines_helper_call()` (`arch/arm64/net/bpf_jit_comp.c:3872-3880`).

So "inline at verifier fixup time" and "inline at JIT call-lowering time" are both already accepted implementation patterns in this tree.

### 2.3 Current BpfReJIT is an even closer native-emission precedent

This tree already contains JIT-time native alternative emission for canonical forms:

- x86 dispatcher: `arch/x86/net/bpf_jit_comp.c:3041-3078`;
- arm64 dispatcher: `arch/arm64/net/bpf_jit_comp.c:844-886`.

The rotate emitter is directly relevant:

- x86 rotate emitter: `arch/x86/net/bpf_jit_comp.c:2169-2224`;
- arm64 rotate emitter: `arch/arm64/net/bpf_jit_comp.c:638-651`;
- arm64 support predicate: `arch/arm64/net/bpf_jit_comp.c:3850-3860`;
- x86 support predicate with BMI2 check: `arch/x86/net/bpf_jit_comp.c:5734-5745`.

This is not kfunc-based, but it proves that "emit arch-native straight-line code from the JIT main loop instead of emitting stock instruction lowering" is already implemented and maintained here.

## 3. JIT `CALL` Handling

### 3.1 x86

Current x86 `BPF_CALL` lowering is at:

- `arch/x86/net/bpf_jit_comp.c:4001-4021`.

The current logic does not distinguish helper call vs kfunc call at the JIT layer:

- it computes `func = (u8 *)__bpf_call_base + imm32` (`4004`);
- it does optional `push_r9` / `pop_r9` around the call when private frame pointer support is active (`4011-4019`);
- it does optional call-depth accounting (`4015`);
- then emits `emit_call(&prog, func, ip)` (`4016`).

`emit_call()` is:

- `arch/x86/net/bpf_jit_comp.c:584-587`.

It delegates to `emit_patch()`:

- `arch/x86/net/bpf_jit_comp.c:569-582`,

which emits opcode `0xE8` plus `disp32`, and `X86_PATCH_SIZE` is explicitly defined as 5 bytes:

- `arch/x86/net/bpf_jit_comp.c:336-337`.

So on x86, the normal call instruction itself is always 5 bytes.

**Precise insertion point for Inline Kfunc dispatch on x86**

The natural insertion point is inside `case BPF_JMP | BPF_CALL` at `arch/x86/net/bpf_jit_comp.c:4001`, immediately after `u8 *ip = image + addrs[i - 1];` and before `func = (u8 *)__bpf_call_base + imm32;`.

That gives the emitter access to:

- the current BPF instruction (`insn`);
- the current native write cursor (`prog`);
- the native instruction base for this BPF insn (`ip`);
- the surrounding JIT state already in scope.

### 3.2 arm64

Current arm64 `BPF_CALL` lowering is at:

- `arch/arm64/net/bpf_jit_comp.c:2131-2185`.

This path:

1. first inlines a few helpers directly (`2139-2157`);
2. for everything else, resolves the function address via `bpf_jit_get_func_addr()` unless it is an extra-pass subprog call (`2160-2175`);
3. emits `emit_call(func_addr, ctx)` (`2177`);
4. copies architectural return register `x0` into BPF `R0`/`x7` for all normal calls (`2178-2184`).

`emit_call()` chooses between direct and indirect call:

- `should_emit_indirect_call()` at `arch/arm64/net/bpf_jit_comp.c:221-233`;
- direct `BL` at `235-243`;
- indirect `MOVN/MOVK/MOVK + BLR` at `245-259`.

Important arm64 details:

- if `ctx->ro_image` is not allocated yet, or the target is unknown, arm64 intentionally emits the larger indirect form in early passes (`225-229`);
- if the final target is within ±128 MiB, it shrinks to a direct `BL` in the final image (`231-259`).

So arm64 already proves that "call size can change across JIT passes" is supported.

**Precise insertion point for Inline Kfunc dispatch on arm64**

The natural insertion point is in `case BPF_JMP | BPF_CALL` at `arch/arm64/net/bpf_jit_comp.c:2131`, after the existing helper-inline special cases (`2139-2157`) and before the general `bpf_jit_get_func_addr()` path (`2160-2175`).

That placement preserves existing helper special cases and lets kinsn bypass the normal call/return-register shuffle.

## 4. JIT Multi-Pass and Variable-Length Emit

### 4.1 x86 multi-pass details

x86 JIT state:

- `struct jit_context` at `arch/x86/net/bpf_jit_comp.c:318-330`;
- `do_jit()` at `3187-4298`;
- outer convergence loop in `bpf_int_jit_compile()` at `5225-5415`.

The key mechanics are:

- `addrs[i]` stores the native offset after BPF instruction `i` (`3250-3254`, `4288-4289`);
- before pass 0, `addrs[]` is initialized with a rough upper bound of 64 bytes per BPF insn (`5318-5325`);
- each pass re-runs `do_jit()`, updates `addrs[]`, and the image is expected to shrink until stable (`5329-5393`);
- once image memory is allocated, the final emission pass validates that each instruction emits exactly the same length as recorded previously (`4272-4283`).

This means Inline Kfunc native emission can fit into the existing framework if:

1. emitted length is deterministic for a given pass state;
2. emitted length is bounded by the per-insn temporary buffer/cap:
   - temp buffer: `u8 temp[BPF_MAX_INSN_SIZE + BPF_INSN_SAFETY];` (`3199`);
   - hard limit: `ilen > BPF_MAX_INSN_SIZE` is fatal (`4266-4269`);
   - current cap: `BPF_MAX_INSN_SIZE = 128` (`332-334`).

**Important x86 caveat**

The rough initial estimate still uses 64 bytes per BPF insn (`5318-5325`), with the comment "each BPF instruction is translated to less than 64 bytes". Existing JIT code relies on that. So for a generic kinsn facility there are two safe choices:

- restrict inline sequences to significantly less than 64 bytes;
- or change the rough-estimate constant to `BPF_MAX_INSN_SIZE` so third-party emitters cannot violate the convergence assumption.

For the intended "instruction-like" kfuncs (rotate, bit extract, address calc), emitted sequences are tiny, so this is not a blocker.

### 4.2 x86 relation to existing variable-length emission

x86 already handles many cases where one BPF insn maps to different native lengths:

- short vs near conditional jumps (`4109-4138`);
- short vs near unconditional jumps (`4194-4223`);
- nop-padding convergence logic using `INSN_SZ_DIFF` (`1950`, `4111-4128`, `4184-4215`).

So replacing a 5-byte `CALL` with an `N`-byte inline sequence is not a new category of problem; it is just another native-size choice inside the same pass machinery.

### 4.3 arm64 multi-pass details

arm64 JIT flow:

- `build_body()` records `ctx->offset[i] = ctx->idx` (`2478-2524`);
- `bpf_int_jit_compile()` first does a max-size estimate pass (`2699-2716`);
- then pass 2 determines exact positions without writing body instructions (`2735-2765`);
- then pass 3 writes the final body with correct branch offsets (`2772-2780`);
- an extra validation pass checks the produced code (`2782-2786`).

Because arm64 native instructions are fixed-width 4-byte words, straight-line inline emission is simpler than x86:

- dry-run sizing already exists naturally through `emit()` incrementing `ctx->idx` even when `ctx->image == NULL` (`120-126`);
- final writing is handled by the same `build_body()` pass 3.

The existing call path already demonstrates size changes across passes (`221-259`, `2699-2780`), so a straight-line kinsn emitter fits cleanly.

### 4.4 Consequence for callback design

For both x86 and arm64, a separate `estimate_*()` callback is not required for the base design.

- x86 already dry-runs by emitting into a temporary buffer during `do_jit()`;
- arm64 already dry-runs by incrementing `ctx->idx` with `ctx->image == NULL` / `ctx->write == false`.

So a single `emit_*()` callback per arch is sufficient if the callback respects the "size-only vs write" mode of the surrounding JIT.

## 5. Current `KF_*` Flags and `KF_INLINE_EMIT`

Current flags in `include/linux/btf.h:18-81`:

| Flag | Bit |
| --- | --- |
| `KF_ACQUIRE` | 0 |
| `KF_RELEASE` | 1 |
| `KF_RET_NULL` | 2 |
| `(unused)` | 3 |
| `(unused)` | 4 |
| `KF_SLEEPABLE` | 5 |
| `KF_DESTRUCTIVE` | 6 |
| `KF_RCU` | 7 |
| `KF_ITER_NEW` | 8 |
| `KF_ITER_NEXT` | 9 |
| `KF_ITER_DESTROY` | 10 |
| `KF_RCU_PROTECTED` | 11 |
| `KF_FASTCALL` | 12 |
| `KF_ARENA_RET` | 13 |
| `KF_ARENA_ARG1` | 14 |
| `KF_ARENA_ARG2` | 15 |
| `KF_IMPLICIT_ARGS` | 16 |

The flags are stored as `u32` next to each BTF ID in `struct btf_id_set8`:

- `include/linux/btf_ids.h:16-23`;
- lookup returns a pointer to the adjacent `flags` field in `kernel/bpf/btf.c:8763-8781`.

There is ample space.

Recommendation:

- define `KF_INLINE_EMIT` as `(1 << 17)`, not as bit 3 or 4.

Reason:

- bits 3 and 4 are currently unused, but appending a new semantic flag at bit 17 is less likely to collide with historical gaps or future backports;
- there is no storage pressure, since flags are already `u32`.

Verifier semantics for `KF_INLINE_EMIT`:

- none are required for the base mechanism;
- `check_kfunc_call()` should keep treating it as an ordinary kfunc.

In other words: `KF_INLINE_EMIT` is declarative and JIT-facing, not verifier-facing.

## 6. Minimal Inline-Emit Callback Interface

### 6.1 Recommended scope restriction

The cleanest contract is:

- straight-line native code only;
- pure register operations only;
- no memory accesses;
- no native calls/jumps;
- no stack pointer manipulation;
- only caller-saved temporaries may be clobbered;
- final result must be written into the arch register that backs BPF `R0`.

This restriction materially improves feasibility:

- no extable handling is needed;
- no branch-target / `addrs[]` / `ctx->offset[]` exposure is needed;
- emitted size is stable and small;
- code review surface stays instruction-like, not mini-backend-like.

### 6.2 What the callback minimally needs

Given the above restriction, the callback needs only:

- output cursor / sizing mode;
- instruction index (optional but useful for future per-insn metadata);
- BPF-to-native register mapping for the current arch;
- a small set of arch temp registers reserved for JIT use;
- CPU feature information if the encoding is feature-gated;
- whether constant blinding was requested, so the callback can avoid baking attacker-controlled immediates into native code.

Not needed for the base design:

- helper/kfunc verifier metadata (the kfunc ABI is always `R1..R5 -> R0`);
- native branch target tables;
- final-pass marker separate from "write vs size-only";
- stack-depth or extable plumbing.

### 6.3 A reasonable base API

Base API shape:

```c
/* include/linux/bpf.h */
#define KF_INLINE_EMIT (1U << 17)

struct bpf_inline_x86_ctx {
	u8 **prog;
	u32 insn_idx;
	bool write;
	bool blinding_requested;
	const u8 *reg_code;   /* BPF reg -> x86 reg encoding nibble */
	const u8 *reg_is_ext; /* BPF reg -> needs REX extension */
	u8 aux_reg;           /* x86 r11 in current JIT */
	u8 ax_reg;            /* x86 r10 in current JIT */
};

struct bpf_inline_arm64_ctx {
	struct jit_ctx *jit;  /* or a narrower public wrapper */
	u32 insn_idx;
	bool write;
	bool blinding_requested;
	const u8 *bpf2a64;
	u8 tmp_reg1;
	u8 tmp_reg2;
	u8 tmp_reg3;
};

struct bpf_kfunc_inline_ops {
#ifdef CONFIG_X86_64
	int (*emit_x86)(struct bpf_inline_x86_ctx *ctx,
			const struct bpf_insn *insn);
#endif
#ifdef CONFIG_ARM64
	int (*emit_arm64)(struct bpf_inline_arm64_ctx *ctx,
			  const struct bpf_insn *insn);
#endif
};
```

Return convention:

- `0`: emitted successfully, JIT should not emit the normal call;
- `-ENOTSUPP`: fallback to normal call;
- any other negative errno: fatal JIT error.

### 6.4 Existing public helper pattern to mirror

There is already a public JIT-side kfunc accessor pattern:

- `bpf_jit_find_kfunc_model()` is declared in `include/linux/bpf.h:3099-3104`;
- implemented in `kernel/bpf/verifier.c:3583-3599`.

Inline Kfunc can follow the same pattern with a new helper such as:

```c
const struct bpf_kfunc_inline_ops *
bpf_jit_find_kfunc_inline_ops(const struct bpf_prog *prog,
			      const struct bpf_insn *insn);
```

That lets JIT code stay per-program and keyed by final `imm + off`, so `fixup_kfunc_call()` does not need to preserve the original BTF ID.

## 7. Calling Convention Implications

### 7.1 x86 register mapping

x86 BPF register mapping is explicit in `arch/x86/net/bpf_jit_comp.c:173-199`:

| BPF reg | x86 reg |
| --- | --- |
| `R0` | `RAX` |
| `R1` | `RDI` |
| `R2` | `RSI` |
| `R3` | `RDX` |
| `R4` | `RCX` |
| `R5` | `R8` |
| `R6` | `RBX` |
| `R7` | `R13` |
| `R8` | `R14` |
| `R9` | `R15` |
| `AX` | `R10` |
| `AUX_REG` | `R11` |

Implications:

- normal kfunc/helper calls already use the BPF ABI register placement directly;
- BPF `R0` already matches the x86 return register, so inline emit can write the result directly into `RAX`;
- safe scratch choices are `R10`/`R11` and caller-saved argument regs;
- `RBX`, `R13`, `R14`, `R15`, `RBP`, and JIT-reserved `R9`/`R12` should not be touched by a minimal inline emitter.

### 7.2 arm64 register mapping

arm64 mapping is explicit in `arch/arm64/net/bpf_jit_comp.c:49-78`:

| BPF reg | arm64 reg |
| --- | --- |
| `R0` | `x7` |
| `R1` | `x0` |
| `R2` | `x1` |
| `R3` | `x2` |
| `R4` | `x3` |
| `R5` | `x4` |
| `R6` | `x19` |
| `R7` | `x20` |
| `R8` | `x21` |
| `R9` | `x22` |
| `AX` | `x9` |
| `TMP_REG_1..3` | `x10..x12` |

Implications:

- normal calls return in architectural `x0`, and the JIT then copies `x0 -> x7` (`arch/arm64/net/bpf_jit_comp.c:2178-2184`);
- inline emit can avoid that extra move by writing the result directly into `x7`;
- `x9..x12` are the natural scratch set for minimal inline emission;
- `x19..x28` and special registers `PRIVATE_SP`, `TCCNT_PTR`, `ARENA_VM_START` should stay untouched.

### 7.3 Verifier-side liveness model already matches this

`check_kfunc_call()` invalidates caller-saved BPF registers after every kfunc call:

- `kernel/bpf/verifier.c:14320-14325`.

So an inline emitter is allowed to clobber caller-saved regs (`R1..R5`) and JIT scratch regs if it wants to. It must preserve the callee-saved BPF regs (`R6..R9`) because the verifier keeps them live across calls.

## 8. Special Scenarios

### 8.1 Constant propagation

Yes, the verifier can prove that a kfunc argument is a compile-time constant:

- `is_kfunc_arg_constant()` and `__k` suffix handling: `kernel/bpf/verifier.c:12234-12237`, `13384-13397`;
- constant `__szk` handling: `13755-13765`;
- the transient metadata container is `struct bpf_kfunc_call_arg_meta::arg_constant` (`kernel/bpf/verifier.c:309-360`).

But this information is not persisted into a JIT-visible structure today. It is used immediately during verification for special kfuncs such as:

- `bpf_obj_new_impl` (`kernel/bpf/verifier.c:13921-14001`);
- `bpf_rdonly_cast` (`14018-14041`);
- `bpf_dynptr_slice*` (`14043-14060`).

So:

- base Inline Kfunc needs no constant-propagation plumbing and can use register-form native instructions;
- if you want `bpf_rotate64(val, 13)` to become immediate-form `RORX imm8` / `ROR imm` / `A64_ROR_I`, you need extra per-insn metadata that survives into JIT.

That optional `v2` enhancement is not zero-verifier-change anymore.

### 8.2 Struct return / multi-return

Current kfunc/trampoline function-model distillation rejects by-value struct return types:

- `kernel/bpf/btf.c:7494-7500`.

So multi-return / struct-return handling is not needed for the proposed scheme.

### 8.3 Error handling and fallback

Recommended policy:

- if inline ops are absent for the arch: normal call;
- if inline ops return `-ENOTSUPP`: normal call;
- if inline ops return any other negative errno: fail JIT as a real backend error.

That matches the "graceful downgrade to real kfunc body" goal without weakening correctness.

## 9. What Must Change for True Interpreter Fallback

The interpreter can execute a fixed-up call:

- `kernel/bpf/core.c:2114-2129`.

But current runtime policy still forces JIT for any program that has kfunc calls:

- `add_kfunc_call()` rejects programs with `!env->prog->jit_requested` and with no JIT kfunc support (`kernel/bpf/verifier.c:3452-3460`);
- `bpf_prog_select_runtime()` sets `jit_needed = true` when `bpf_prog_has_kfunc_call(fp)` is true (`kernel/bpf/core.c:2609-2611`), and returns `-ENOTSUPP` if JIT did not happen (`2627-2632`).

Therefore:

- "interpreter implementation needs no new call opcode logic" is true;
- "the current kernel already allows interpreter fallback for kfunc programs" is false.

If true interpreter fallback is a hard requirement, additional policy changes are needed in those two locations.

## 10. Minimal Implementation Plan

### 10.1 Data structures and registration

Recommended base shape:

1. `include/linux/btf.h`
   - add `KF_INLINE_EMIT`.
2. `include/linux/bpf.h`
   - add `struct bpf_kfunc_inline_ops`;
   - add `bpf_register_kfunc_inline_ops()` / `bpf_unregister_kfunc_inline_ops()`;
   - add `bpf_jit_find_kfunc_inline_ops()`.
3. `kernel/bpf/btf.c`
   - keep a registry keyed by `(struct btf *, relocated_btf_id) -> inline_ops`.

Registration should use the same owner/BTF lifetime model as kfunc registration. A clean way is a macro wrapper that passes `THIS_MODULE` implicitly:

```c
int __bpf_register_kfunc_inline_ops(struct module *owner, u32 btf_id,
				    const struct bpf_kfunc_inline_ops *ops);

#define bpf_register_kfunc_inline_ops(btf_id, ops) \
	__bpf_register_kfunc_inline_ops(THIS_MODULE, btf_id, ops)
```

Reason:

- module/vmlinux BTF lookup already exists in `kernel/bpf/btf.c:8441-8472`;
- module references for module-BTF kfuncs are already held in `kfunc_btf_tab` (`kernel/bpf/verifier.c:3249-3311`, `3313-3323`).

### 10.2 Verifier-side bookkeeping only, not validation changes

Extend `struct bpf_kfunc_desc` with an inline-ops pointer:

- existing definition: `kernel/bpf/verifier.c:3173-3179`.

Populate it in `add_kfunc_call()` right after `fetch_kfunc_meta()`:

```c
desc->inline_ops = (*kfunc.flags & KF_INLINE_EMIT) ?
		   btf_kfunc_inline_ops(kfunc.btf, func_id) : NULL;
```

Then add a JIT accessor mirroring `bpf_jit_find_kfunc_model()`:

```c
const struct bpf_kfunc_inline_ops *
bpf_jit_find_kfunc_inline_ops(const struct bpf_prog *prog,
			      const struct bpf_insn *insn)
{
	/* same bsearch pattern as bpf_jit_find_kfunc_model() */
}
```

This is enough for the base design. `fixup_kfunc_call()` does not need to preserve BTF IDs because JIT lookup can already key on final `imm + off`.

### 10.3 x86 JIT patch point

Insert in `arch/x86/net/bpf_jit_comp.c` inside:

- `case BPF_JMP | BPF_CALL:` at `4001-4021`.

Suggested shape:

```c
case BPF_JMP | BPF_CALL: {
	u8 *ip = image + addrs[i - 1];

	if (src_reg == BPF_PSEUDO_KFUNC_CALL) {
		const struct bpf_kfunc_inline_ops *ops;
		struct bpf_inline_x86_ctx inline_ctx;

		ops = bpf_jit_find_kfunc_inline_ops(bpf_prog, insn);
		if (ops && ops->emit_x86) {
			err = ops->emit_x86(&inline_ctx, insn);
			if (!err)
				break;          /* emitted */
			if (err != -ENOTSUPP)
				return err;     /* fatal */
		}
	}

	func = (u8 *)__bpf_call_base + imm32;
	...
	if (emit_call(&prog, func, ip))
		return -EINVAL;
	...
	break;
}
```

This is a narrow, local change.

### 10.4 arm64 JIT patch point

Insert in `arch/arm64/net/bpf_jit_comp.c` inside:

- `case BPF_JMP | BPF_CALL:` at `2131-2185`,

after the current helper-inline special cases and before the generic address-resolution branch.

Suggested shape:

```c
case BPF_JMP | BPF_CALL:
{
	...
	if (insn->src_reg == BPF_PSEUDO_KFUNC_CALL) {
		const struct bpf_kfunc_inline_ops *ops;
		struct bpf_inline_arm64_ctx inline_ctx;

		ops = bpf_jit_find_kfunc_inline_ops(ctx->prog, insn);
		if (ops && ops->emit_arm64) {
			ret = ops->emit_arm64(&inline_ctx, insn);
			if (!ret)
				break;
			if (ret != -ENOTSUPP)
				return ret;
		}
	}

	...
	ret = bpf_jit_get_func_addr(...);
	...
	emit_call(func_addr, ctx);
	...
	break;
}
```

### 10.5 Fixup changes

Base design: none.

Why no fixup change is required:

- fixed-up kfunc calls already preserve `src_reg == BPF_PSEUDO_KFUNC_CALL` if the call survives;
- `imm + off` already identify the final per-program descriptor;
- `sort_kfunc_descs_by_imm_off()` already prepares that lookup table for JIT (`kernel/bpf/verifier.c:3558-3575`, `24309-24311`).

### 10.6 Optional `v1.5` interpreter fallback changes

If true interpreter fallback is desired, also change:

- `kernel/bpf/verifier.c:3452-3460`;
- `kernel/bpf/core.c:2609-2632`.

That is outside the minimal JIT-only Inline Kfunc mechanism.

## 11. Rotate Example

### 11.1 Practical note

For the base zero-verifier-change design, the simplest rotate kfunc is a register-form rotate:

```c
u64 bpf_rotate_right64(u64 val, u32 shift)
```

This already demonstrates the mechanism.

If immediate-specialized `RORX imm8` / `A64_ROR_I` is required for constant `shift`, add the optional `v2` constant-arg metadata from section 8.1.

### 11.2 Module sketch

```c
// kernel module: bpf_rotate.c
#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/module.h>
#include <linux/filter.h>

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_rotate_right64(u64 val, u32 shift)
{
	shift &= 63;
	return (val >> shift) | (val << ((64 - shift) & 63));
}

__bpf_kfunc_end_defs();

BTF_KFUNCS_START(rotate_kfunc_ids)
BTF_ID_FLAGS(func, bpf_rotate_right64, KF_INLINE_EMIT)
BTF_KFUNCS_END(rotate_kfunc_ids)

BTF_ID_LIST(rotate_one_id)
BTF_ID(func, bpf_rotate_right64)

static const struct btf_kfunc_id_set rotate_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &rotate_kfunc_ids,
};

#ifdef CONFIG_X86_64
static int rotate_emit_x86(struct bpf_inline_x86_ctx *ctx,
			   const struct bpf_insn *insn)
{
	/*
	 * Base form:
	 *   mov rax, rdi
	 *   mov ecx, esi
	 *   ror rax, cl
	 *
	 * BPF ABI mapping on x86-64:
	 *   R1=RDI (value), R2=RSI (shift), R0=RAX
	 *   R4=RCX is caller-saved, so clobbering it is fine.
	 */

	if (ctx->blinding_requested)
		return -ENOTSUPP; /* optional conservative policy */

	/* Pseudocode assuming thin arch helpers; a raw-byte PoC is also possible. */
	bpf_inline_x86_mov64_reg(ctx, BPF_REG_0, BPF_REG_1);
	bpf_inline_x86_mov32_reg(ctx, BPF_REG_4, BPF_REG_2);
	bpf_inline_x86_ror64_cl(ctx, BPF_REG_0);
	return 0;
}
#endif

#ifdef CONFIG_ARM64
static int rotate_emit_arm64(struct bpf_inline_arm64_ctx *ctx,
			     const struct bpf_insn *insn)
{
	/*
	 * Single instruction:
	 *   rorv x7, x0, x1
	 *
	 * BPF ABI mapping on arm64:
	 *   R1=x0 (value), R2=x1 (shift), R0=x7
	 */
	bpf_inline_arm64_emit(ctx,
		A64_RORV(1, ctx->bpf2a64[BPF_REG_0],
			    ctx->bpf2a64[BPF_REG_1],
			    ctx->bpf2a64[BPF_REG_2]));
	return 0;
}
#endif

static const struct bpf_kfunc_inline_ops rotate_inline_ops = {
#ifdef CONFIG_X86_64
	.emit_x86 = rotate_emit_x86,
#endif
#ifdef CONFIG_ARM64
	.emit_arm64 = rotate_emit_arm64,
#endif
};

static int __init bpf_rotate_init(void)
{
	int ret;

	ret = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC, &rotate_kfunc_set);
	if (ret)
		return ret;

	ret = bpf_register_kfunc_inline_ops(rotate_one_id[0], &rotate_inline_ops);
	if (ret)
		return ret;

	return 0;
}

static void __exit bpf_rotate_exit(void)
{
	bpf_unregister_kfunc_inline_ops(rotate_one_id[0]);
}

module_init(bpf_rotate_init);
module_exit(bpf_rotate_exit);
MODULE_LICENSE("GPL");
```

### 11.3 Optional immediate-specialized version

If `v2` constant metadata is added, the kfunc can instead be:

```c
__bpf_kfunc u64 bpf_rotate_right64_k(u64 val, u32 shift__k)
```

Then the x86 emitter can use the exact same native forms already implemented by the current BpfReJIT rotate emitter:

- `RORX` path: `arch/x86/net/bpf_jit_comp.c:2188-2208`;
- plain immediate `ROR` path: `2208-2224`;
- arm64 immediate rotate: `arch/arm64/net/bpf_jit_comp.c:638-651`.

This is phase 2, not required for the base feasibility claim.

### 11.4 BPF side usage

```c
extern __u64 bpf_rotate_right64(__u64 val, __u32 shift) __ksym;

SEC("xdp")
int prog(struct xdp_md *ctx)
{
	__u64 v = 0x1122334455667788ULL;
	__u64 r = bpf_rotate_right64(v, 13);
	return r ? XDP_PASS : XDP_DROP;
}
```

Toolchain-wise this is just an ordinary kfunc declaration and `__ksym` usage; no new opcode or new frontend syntax is needed.

## 12. Estimated LOC

Base `v1` estimate (JIT-only inline dispatch, no constant-arg persistence, no interpreter-policy changes):

| Change | File | Estimated LOC |
| --- | --- | ---: |
| `KF_INLINE_EMIT` flag | `include/linux/btf.h` | 2 |
| inline ops structs + API decls | `include/linux/bpf.h` | 30-45 |
| inline-ops registry + register/unregister | `kernel/bpf/btf.c` | 80-130 |
| stash ops in `bpf_kfunc_desc` + JIT lookup helper | `kernel/bpf/verifier.c` | 35-55 |
| x86 JIT inline dispatch | `arch/x86/net/bpf_jit_comp.c` | 25-45 |
| arm64 JIT inline dispatch | `arch/arm64/net/bpf_jit_comp.c` | 20-35 |
| fixup adjustments | `kernel/bpf/verifier.c` | 0 |
| **Total** |  | **192-312** |

Optional additions:

| Optional enhancement | Files | Extra LOC |
| --- | --- | ---: |
| true interpreter fallback | `kernel/bpf/verifier.c`, `kernel/bpf/core.c` | 10-25 |
| persist constant kfunc arg into JIT-visible metadata | verifier + one aux/header file | 40-90 |
| x86 rough-estimate hardening from 64 -> `BPF_MAX_INSN_SIZE` | `arch/x86/net/bpf_jit_comp.c` | 1-3 |

These estimates are materially smaller than introducing a new ISA opcode plus verifier/interpreter support.

## 13. Comparison to Other Approaches

Updated comparison:

| | `kinsn` (new opcode) | Inline Kfunc (`v1`) | Current BpfReJIT |
| --- | --- | --- | --- |
| Verifier type/ownership path | new logic needed | **reuse `check_kfunc_call()`** | separate validator/policy path |
| Verifier instruction fixup | new opcode handling | **none required for base design** | separate canonical-form machinery |
| JIT changes | per-arch opcode lowering | **small `BPF_CALL` dispatch hook** | large per-arch canonical emitters |
| Interpreter changes | new opcode support | **0 mechanism changes** |
| Interpreter fallback policy | new policy work | **not enabled today; optional small policy patch** | N/A |
| New opcode | yes | **no** | no |
| Frontend/toolchain surface | new builtin/opcode mapping | **existing `__ksym` kfunc flow** | external rewrite/policy machinery |
| Graceful fallback | hard | **yes, to normal kfunc CALL** | N/A |
| Upstream narrative | "new BPF ISA" | **"another kfunc lowering mode"** | larger subsystem story |

The strongest upstream argument for Inline Kfunc is not "we need a custom opcode", but rather:

- kfuncs already have special verifier/fixup lowering;
- JITs already inline helpers and canonical forms;
- this proposal only adds a new JIT-time lowering choice for an existing kfunc abstraction.

## 14. Risks and Limits

- Inline emit bugs are kernel-module TCB bugs, but that is not qualitatively different from bugs in the kfunc body itself. The emitted sequence runs in kernel text and must be reviewed at the same trust level.
- To keep the surface reviewable, inline emitters should be restricted to straight-line register-only sequences. Allowing arbitrary loads/stores/extables/calls would rapidly turn this into a second backend framework.
- Constant blinding interaction is real. If a kfunc argument comes from user-controlled BPF bytecode and the inline emitter bakes it into native immediates, it can bypass the intended JIT blinding policy (`kernel/bpf/core.c:1395-1401`, `include/linux/bpf.h:1807-1815`). The conservative answer is: no immediate-specialized inline emission when `prog->blinding_requested` is set, unless blinding-aware emitters are explicitly designed.
- Re-JIT / staged JIT is compatible as long as emitted size is deterministic within a compile attempt. Relevant pass handling:
  - x86: `arch/x86/net/bpf_jit_comp.c:5276-5291`, `5335-5393`;
  - arm64: `arch/arm64/net/bpf_jit_comp.c:2668-2680`, `2750-2807`.
- One subtle current-policy limitation: runtime treats "program ever referenced a kfunc" as "program needs JIT" via `prog->aux->kfunc_tab`, even if `fixup_kfunc_call()` later rewrote every such kfunc into plain BPF instructions. So any future interpreter-fallback work should be deliberate and policy-aware, not assume current behavior already permits it.

## Final Assessment

`Inline Kfunc` is a credible and relatively low-intrusion way to add instruction-like BPF extensions on top of the existing kfunc ecosystem in this tree.

The strongest form of the claim that is supported by the source is:

- **Verifier validation path**: reusable as-is.
- **Interpreter execution mechanism**: reusable as-is, but current runtime policy still forces JIT for kfunc programs.
- **Fixup path**: reusable as-is for the base design.
- **JIT changes**: localized to `BPF_CALL` handling on x86 and arm64 plus a small per-program metadata lookup hook.

The proposal is particularly strong if it stays within this envelope:

- straight-line register-only native emission;
- fallback to the real kfunc body when inline emission is unavailable;
- no attempt to expose arbitrary backend power in the first version.

Under those constraints, this looks substantially more upstreamable than a new opcode, and much smaller than the current BpfReJIT machinery.
