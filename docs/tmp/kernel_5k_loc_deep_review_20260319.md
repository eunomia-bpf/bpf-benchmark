# Kernel 5k LOC Deep Review (2026-03-19)

Scope reviewed line-by-line:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` (emitter/recompile delta vs stock)
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/filter.h`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/syscall.c`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
- `vendor/linux-framework/tools/bpf/bpftool/prog.c`
- `tests/kernel/test_recompile.c`

Note: `vendor/linux-framework/tools/bpf/bpftool/prog.c` has no current recompile delta on this branch, so there was nothing substantive to review in that file.

## Score

`6/10`

The validator/fallback structure is much cleaner than earlier iterations, but this is still not safe to ship as-is. The big blocker is that live recompile is still allowed for trampoline-attached programs even though the recompile path only updates JIT text and ksym state, not the attached trampoline images that call into that text.

## P0 Findings

### P0-1: Live recompile still permits trampoline-attached tracing/LSM programs, but the recompile path does not regenerate those trampolines

References:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:3004-3016`
- `vendor/linux-framework/include/linux/bpf.h:1554`
- `vendor/linux-framework/kernel/bpf/trampoline.c:137-151`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2832-2919`
- `tests/kernel/test_recompile.c:1971-2018`

Why this is a blocker:

- The syscall entry only rejects attached `struct_ops` programs.
- The tree already has a generic `bpf_prog_has_trampoline()` helper, and it covers tracing trampoline users (`fentry`, `fexit`, `fmod_ret`, `fsession`) plus LSM trampoline users.
- The commit path swaps `prog->bpf_func`, exception callback state, extable metadata, and ksym metadata, then frees the old image after `synchronize_rcu()`.
- What it does not do is rebuild or relink any live trampoline image that was generated against the old `prog->bpf_func`.

Impact:

- A trampoline can continue jumping to the stale body after the old executable image has been retired. That is kernel-crash/UAF territory, not just a stale-optimization issue.
- Coverage does not catch it today because the only attach test is XDP attach, which does not use BPF trampolines.

Recommendation:

- Reject `bpf_prog_has_trampoline(prog)` in `bpf_prog_jit_recompile()` until trampoline regeneration exists end-to-end.
- If live trampoline-attached recompile is a real requirement, the recompile transaction must own trampoline regeneration and relinking before old text is freed.

## P1 Findings

### P1-1: Two canonical emitters still re-read original BPF insns instead of consuming only normalized params

References:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:1937-1942`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2182-2197`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h:112-123`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2557-2576`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3057-3135`

Details:

- `ZERO_EXT_ELIDE` stores `alu32_insn` as `BPF_JIT_ZEXT_PARAM_ALU32_PTR`, then the x86 emitter casts it back to `struct bpf_insn *` and re-emits from the original insn.
- `BRANCH_FLIP` stores `site_insns` as `BPF_JIT_BFLIP_PARAM_SITE_PTR`, then the x86 emitter re-reads the original branch and both bodies from that pointer.

Why this matters:

- This breaks the intended contract that Layer 2 validation fully normalizes the site and Layer 3 emitters only consume validated params.
- It weakens architecture separation. The params are no longer architecture-neutral data; they are kernel pointers into the original insn stream.
- It also makes later hardening/porting harder because correctness depends on the original insn representation still being available and unchanged.

Recommendation:

- Normalize the remaining inputs into scalar params and remove raw-insn pointer params from `struct bpf_jit_canonical_params`.

## P2 Findings

### P2-1: `BRANCH_FLIP` still carries dead normalized fields that the only emitter ignores

References:

- `vendor/linux-framework/include/linux/bpf_jit_directives.h:93-100`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2184-2195`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3071-3095`

Details:

- The validator fills `BODY_A_START`, `BODY_B_START`, and `JOIN_TARGET`.
- The x86 emitter does not consume any of them. It recomputes `body_a_start = 1` and `body_b_start = body_a_start + body_a_len + 1` from the raw site pointer.

This is clear cleanup residue after the DSL/pattern cleanup. It increases schema surface area without providing authority.

### P2-2: Reserved policy-header flags are not fail-closed

References:

- `vendor/linux-framework/include/uapi/linux/bpf.h:1476-1485`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2570-2647`
- `vendor/linux-framework/tools/include/uapi/linux/bpf.h:1476-1485`

Details:

- UAPI marks `struct bpf_jit_policy_hdr.flags` as reserved.
- The parser validates `magic`, `hdr_len`, `total_len`, `insn_cnt`, `prog_tag`, `arch_id`, `rule_cnt`, and `version`, but never rejects non-zero `hdr->flags`.

Why it matters:

- This is a fail-open hole in an otherwise fail-closed parser.
- Unknown future header bits will currently be accepted silently instead of rejected.

### P2-3: Overlapping active rules are accepted, and later ones can become silently unreachable

References:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:580-593`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2444-2511`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:2680-2712`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3618-3628`

Details:

- Policy parsing validates each rule independently and then sorts by `site_start` and `user_index`.
- There is no policy-level overlap rejection.
- Once a rule applies, the JIT main loop advances by `consumed - 1`, so any later rule whose `site_start` lies inside the already-consumed site is skipped.

Impact:

- The resulting policy semantics are order-dependent.
- Some accepted active rules are effectively dead, but nothing reports that to the caller.

Recommendation:

- Reject overlapping active rules at parse time, or explicitly document/diagnose first-match-wins semantics.

### P2-4: Test coverage is still missing half of the canonical forms and the highest-risk attach mode

References:

- `tests/kernel/test_recompile.c:1520-1716`
- `tests/kernel/test_recompile.c:1718-2025`
- `tests/kernel/test_recompile.c:2041-2060`

Missing coverage I would expect before trusting this path:

- `BRANCH_FLIP`
- `BITFIELD_EXTRACT`
- `ZERO_EXT_ELIDE`
- `ENDIAN_FUSION`
- reserved `policy_hdr.flags` rejection
- trampoline-attached program rejection/regeneration behavior
- overlapping-rule policy behavior
- multi-subprog recompile with pseudo-call retargeting under failure injection

## Answers To The Specific Checks

### 1. Design defects / security model / error paths

- The main design defect is the missing generic trampoline safety gate. Existing helper/API support is available, but the recompile entry point only hard-codes the `struct_ops` subset.
- Parser fail-closed behavior is mostly good, but `policy_hdr.flags` is a gap.
- Per-site emitter failure handling is fail-closed and good: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3500-3512` falls back to stock emission if canonical emission returns `<= 0`.

### 2. Dead code after cleanup removals

Concrete leftovers I found:

- dead `BRANCH_FLIP` normalized fields: `BODY_A_START`, `BODY_B_START`, `JOIN_TARGET`
- retained-but-unread policy blob ownership:
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:571-578`
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:2437-2440`
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:2510`
  - `vendor/linux-framework/include/linux/bpf_jit_directives.h:146-156`

I did **not** find leftover runtime logic for the removed stock-choice, tracepoint, `recompile_count`, or `ROLLBACK` mechanisms in the reviewed files.

### 3. Unnecessary complexity / redundant checks

- The biggest complexity smell is carrying raw insn pointers through canonical params instead of completing normalization.
- `BRANCH_FLIP` also keeps dead normalized fields that do not participate in emission.

### 4. Potential bugs

- P0 trampoline-attached live recompile bug.
- P2 overlap semantics bug/ambiguity.

### 5. Existing kernel APIs that should be used

- The tree already exposes `bpf_prog_has_trampoline()` and the recompile syscall should use it instead of the current hand-rolled `struct_ops`-only gate.

### 6. Do all validators follow the unified pattern?

Mostly yes.

- The canonical validators in `vendor/linux-framework/kernel/bpf/jit_directives.c` consistently follow `parse shape -> fill params`.
- I did not find a remaining separate "match step" from the old DSL design.
- The caveat is that `ZERO_EXT_ELIDE` and `BRANCH_FLIP` stop short of full normalization because their filled params include kernel pointers to original insns.

### 7. Do all emitters only consume params, never re-read original insns?

No.

- `emit_canonical_zero_ext_elide()` re-reads the original ALU32 insn.
- `emit_canonical_branch_flip()` re-reads the original branch/body insns.

Everything else I reviewed follows the intended param-only pattern.

### 8. Is the 3-layer security model intact?

Only partially.

What is intact:

- Layer 1 site bounds/subprog placement:
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:2356-2360`
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:2388-2425`
- Layer 2 form validation:
  - `vendor/linux-framework/kernel/bpf/jit_directives.c:2270-2385`
- Layer 3 fail-closed emission fallback:
  - `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3490-3527`

What breaks the model:

- the P0 trampoline-attached recompile hole
- the P1 raw-insn-pointer params, which mean emitters are not fully isolated from original program text
- the P2 fail-open parser handling of reserved policy-header flags

## Bottom Line

The core validator organization is now coherent, and the stock-fallback emitter path is doing the right thing. The remaining issue set is not broad, but it includes one ship-stopper: live recompile must not be allowed on trampoline-attached programs until trampoline regeneration is part of the transaction. After that, the next cleanup target should be finishing normalization for `ZERO_EXT_ELIDE` and `BRANCH_FLIP`, then trimming the dead branch-flip params and adding the missing tests.
