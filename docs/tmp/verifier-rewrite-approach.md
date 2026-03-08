# Verifier-Rewrite Approach: Directive-Guided BPF Rewriting Before JIT

## Thesis

The current JIT-level design asks the x86 backend to consume userspace directives inside `do_jit()`. That works for closed local fusions, but it is the wrong abstraction for the transforms that actually strengthen the paper:

- `branch_reorder`
- `subprog_inline`
- any non-local elimination or CFG restructuring

The reason is structural, not stylistic. `vendor/linux/arch/x86/net/bpf_jit_comp.c` is a linear emitter:

- `bpf_int_jit_compile()` repeatedly calls `do_jit()` until `addrs[]` converges.
- `do_jit()` walks the BPF program in original instruction order.
- control-flow is resolved by looking up native offsets in `addrs[]`.
- the final image pass asserts that the native length for each BPF instruction boundary did not change from the sizing pass.

That model is excellent for ordinary 1:1 lowering and for bounded local collapse. It is not a natural home for "move this hot block before that cold block" or "inline this callee body here".

Path B is to move directive consumption up one level:

1. verify the original BPF program;
2. use verifier facts to rewrite the BPF instruction stream itself;
3. hand the rewritten BPF program to the ordinary linear JIT.

This is not speculative. The verifier already does exactly this kind of work today:

- it inlines `bpf_loop()` at the BPF level;
- it rewrites context accesses into ordinary memory operations;
- it expands helper/kfunc calls into straight-line BPF sequences;
- it inserts speculation barriers and pointer-sanitization sequences;
- it removes dead code and NOPs;
- it rewrites `may_goto`, `ld_abs/ld_ind`, `tail_call`, and several tracing helpers.

So the key question is not "can the verifier rewrite BPF?" It already does. The real question is: which userspace-guided optimizations belong in that verifier rewrite stage, and which still belong in target-specific JIT lowering?

## 1. What the Verifier Already Rewrites

### 1.1 Current pipeline and where rewrites happen

The relevant pipeline in `vendor/linux/kernel/bpf/verifier.c` is:

1. `resolve_pseudo_ldimm64(env)`
2. `check_cfg(env)`
3. `compute_postorder(env)`
4. `compute_scc(env)`
5. `compute_live_registers(env)`
6. `do_check_main(env)` and `do_check_subprogs(env)`, both funneled through `do_check()`
7. `remove_fastcall_spills_fills(env)`
8. `check_max_stack_depth(env)`
9. `optimize_bpf_loop(env)`
10. privileged path: `opt_hard_wire_dead_code_branches(env)`, `opt_remove_dead_code(env)`, `opt_remove_nops(env)`
11. unprivileged path: `sanitize_dead_code(env)`
12. `convert_ctx_accesses(env)`
13. `do_misc_fixups(env)`
14. `opt_subreg_zext_lo32_rnd_hi32(env, attr)`
15. `fixup_call_args(env)` and, inside it, `jit_subprogs(env)` when JIT is requested
16. much later, `convert_pseudo_ld_imm64(env)`

The verifier itself marks the transition explicitly with the comment:

`/* instruction rewrites happen after this point */`

right before `optimize_bpf_loop()` and the later fixup passes.

So there is already a late verifier rewrite phase. Path B is about putting userspace-guided optimization there, not inventing a new concept.

### 1.2 Core rewrite primitive: `bpf_patch_insn_data()`

Most verifier rewrites are built on `bpf_patch_insn_data(env, off, patch, len)`.

Conceptually it does:

- replace one instruction at `off` with `len` instructions;
- grow `env->insn_aux_data` if needed;
- patch the actual `struct bpf_prog`;
- call `adjust_insn_aux_data()` to shift per-insn metadata;
- call `adjust_subprog_starts()` to move subprogram boundaries;
- call `adjust_insn_arrays()` to keep insn-array maps coherent;
- call `adjust_poke_descs()` to keep tail-call poke descriptors coherent.

This matters for Path B because it shows the verifier already has:

- a splice primitive for 1->N instruction replacement;
- bookkeeping for aux data and subprogram starts;
- an existing model for keeping post-verifier metadata consistent.

It also shows the current limits:

- `bpf_patch_insn_data()` is a splice, not a block scheduler;
- `adjust_jmp_off()` only handles "all jumps that target this insertion point shift by delta";
- there is no general block-permutation helper today;
- `adjust_insn_aux_data()` is designed for local patching, not arbitrary CFG re-layout.

So Path B is plausible, but `branch_reorder` and `subprog_inline` need new verifier-side machinery beyond the existing splice helper.

### 1.3 Complete inventory of current rewrite families

This section is intentionally exhaustive. The goal is to see exactly how much rewriting the verifier already owns today.

#### Exact `bpf_patch_insn_data()` call-site inventory

`bpf_patch_insn_data()` itself appears at 31 call sites in `verifier.c`.

Grouped by pass, the exact sites are:

1. Wrapper helpers
   - `add_hidden_subprog()` in `do_misc_fixups()`: append a hidden exception callback subprogram.
   - `inline_bpf_loop()` in `optimize_bpf_loop()`: replace one `bpf_loop` call with an inlined loop body.

2. `opt_subreg_zext_lo32_rnd_hi32()`
   - patch one instruction into either `{insn; zext}` or the 4-insn randomized-high-32 test sequence.

3. `convert_ctx_accesses()`
   - patch entry insn 0 to save `ARG_PTR_TO_CTX` for a generated epilogue;
   - patch entry insn 0 with a generated program-type prologue;
   - prepend `BPF_ST_NOSPEC()` before an access marked by aux `nospec`;
   - append `BPF_ST_NOSPEC()` after a write marked by aux `nospec_result`;
   - apply the main context-access rewrite buffer, including generated epilogue replacement of `EXIT`.

4. `do_misc_fixups()`
   - replace immediate signed `div/mod -1` with an exception-free sequence;
   - replace register `div/mod` with guarded divide-by-zero / signed-`-1` sequences;
   - guard `BPF_PROBE_MEM` / `BPF_PROBE_MEMSX` loads against userspace addresses;
   - rewrite `LD_ABS` / `LD_IND` through `gen_ld_abs()`;
   - expand pointer arithmetic into the speculation-safe mask sequence driven by `alu_state` / `alu_limit`;
   - rewrite timed `may_goto`;
   - rewrite non-timed `may_goto`;
   - patch `BPF_PSEUDO_KFUNC_CALL` through `fixup_kfunc_call()`;
   - harden unprivileged `bpf_tail_call` with bounds+mask logic;
   - inject `prog->aux` before `bpf_timer_set_callback`;
   - inject GFP flags before storage-get helpers;
   - inject `r1 = *(u64 *)(r1 + 0)` for percpu-alloc-ptr helpers;
   - inline `map_lookup_elem` through `map_gen_lookup()`;
   - inline `bpf_jiffies64`;
   - inline `bpf_get_smp_processor_id`;
   - inline `bpf_get_current_task` / `_btf`;
   - inline `bpf_get_func_arg`;
   - inline `bpf_get_func_ret`;
   - inline `bpf_get_func_arg_cnt`;
   - replace `bpf_get_func_ip` with a single `ctx[-16]` load;
   - inline `bpf_get_branch_snapshot`;
   - inline `bpf_kptr_xchg`;
   - insert subprogram-entry stack initialization for previously rewritten `may_goto`.

That exact list matters for Path B. It shows the verifier already owns:

- helper inlining;
- kfunc specialization;
- speculation-hardening rewrites;
- synthesized control-flow expansion;
- hidden-subprogram insertion;
- stack-layout changes;
- non-trivial BPF call replacement.

In other words, the verifier is already acting like a BPF late-lowering pass.

#### Pre-verification rewrite: `resolve_pseudo_ldimm64()`

Before abstract interpretation even begins, `resolve_pseudo_ldimm64()` rewrites pseudo `ldimm64` instructions:

- `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_IDX` become real kernel map pointers in the immediate.
- `BPF_PSEUDO_MAP_VALUE` / `BPF_PSEUDO_MAP_IDX_VALUE` become direct map-value addresses plus recorded `map_index` / `map_off`.
- `BPF_PSEUDO_BTF_ID` becomes a kernel symbol address and records resulting pointer type in aux data.
- `BPF_PSEUDO_FUNC` is marked in aux data as `PTR_TO_FUNC`.

This pass does not use `bpf_patch_insn_data()`, but it is still a verifier-owned rewrite.

#### `remove_fastcall_spills_fills()`

This pass is a targeted BPF-level cleanup:

- it identifies spill/fill pairs around `bpf_fastcall` patterns via aux metadata;
- it rewrites those instructions in place to NOPs (`BPF_JMP_IMM(BPF_JA, 0, 0, 0)`);
- `opt_remove_nops()` later physically removes them.

This is already a small verifier-owned DSE pass.

#### `optimize_bpf_loop()` / `inline_bpf_loop()`

This is the strongest existing precedent for Path B. The verifier already performs structural BPF expansion of a function-like construct.

If aux data marks a `bpf_loop()` call site as `fit_for_inline`, `inline_bpf_loop()` replaces the single call instruction with a synthesized loop body that:

- checks the iteration bound;
- spills `R6`, `R7`, and `R8`;
- initializes loop state;
- issues a relative `BPF_CALL_REL()` to the callback subprogram;
- increments the loop counter;
- conditionally loops;
- restores registers;
- returns the number of iterations.

This is not a peephole. It is a non-trivial verifier-side BPF transformation.

#### Dead-code and NOP rewriting

The verifier also already rewrites control flow after analysis:

- `opt_hard_wire_dead_code_branches()` turns conditional jumps with a dead arm into unconditional `ja`.
- `opt_remove_dead_code()` physically deletes unreachable instruction ranges through `verifier_remove_insns()`.
- `opt_remove_nops()` physically removes `ja +0` NOPs and `may_goto +0`.
- `sanitize_dead_code()` rewrites dead code to `ja -1` on the unprivileged path.

These are not profitability optimizations, but they prove the verifier already edits CFG shape after proof.

#### `convert_ctx_accesses()`

This pass does several families of rewrites through `bpf_patch_insn_data()`:

1. It inserts generated prologue/epilogue code through program-type hooks.
2. It prepends `BPF_ST_NOSPEC()` before accesses whose aux data says `nospec`.
3. It appends `BPF_ST_NOSPEC()` after writes whose aux data says `nospec_result`.
4. It rewrites `PTR_TO_CTX`, socket-context, and some BTF-context loads/stores into ordinary BPF memory operations produced by `convert_ctx_access`.
5. It widens narrower context loads to 4-byte or 8-byte loads and then inserts shift/mask instructions to reconstruct the originally requested narrower field.
6. It rewrites some accesses into `BPF_PROBE_MEM`, `BPF_PROBE_MEMSX`, `BPF_PROBE_MEM32`, `BPF_PROBE_MEM32SX`, or `BPF_PROBE_ATOMIC`.
7. It rewrites early `EXIT` instructions to a shared generated epilogue when one exists.

This pass is especially relevant to Path B because it already turns one verified memory-access pattern into a different BPF-level memory-access pattern.

#### `do_misc_fixups()`

`do_misc_fixups()` is the largest verifier rewrite pass. It contains both in-place mutations and many `bpf_patch_insn_data()` call sites.

Current rewrite families include:

1. Exception-subprogram creation
   - if the verifier saw exceptions and no callback subprogram exists, it appends a hidden subprogram through `add_hidden_subprog()`.

2. In-place opcode normalization
   - some address-space-cast moves are rewritten in place from 64-bit move form to 32-bit move form.
   - if aux data says `needs_zext`, ALU64 instructions are rewritten in place to their ALU32 form.

3. Div/mod exception elimination
   - signed divide/mod-by-minus-one cases are expanded into explicit safe sequences;
   - divide/mod-by-zero cases are expanded into explicit guarded sequences.

4. Fault-behavior guards
   - `BPF_PROBE_MEM` and `BPF_PROBE_MEMSX` loads may be wrapped with an address-range check that zeros the destination on bad address.

5. Classic packet access lowering
   - `LD_ABS` and `LD_IND` are rewritten into normal BPF instruction sequences through `ops->gen_ld_abs()`.

6. Pointer-arithmetic sanitization
   - pointer `ADD`/`SUB` marked by aux `alu_state` / `alu_limit` are expanded into masked/speculation-safe sequences.

7. `may_goto` lowering
   - `may_goto` is expanded into explicit stack-counter logic;
   - extra prologue stores are inserted at the start of the affected subprograms.

8. kfunc specialization and inlining
   - `fixup_kfunc_call()` may prepend metadata loads or fully inline special kfuncs such as:
     - object creation/drop/refcount helpers,
     - list/rbtree insertion helpers,
     - cast helpers,
     - tracing-session helpers like `bpf_session_is_return()` and `bpf_session_cookie()`.

9. Helper-call rewriting
   - `bpf_tail_call` is rewritten into the special `BPF_TAIL_CALL` opcode and, on some paths, wrapped with extra speculation-safe index checks.
   - `bpf_timer_set_callback` gets a prepended `prog->aux` load.
   - storage-get helpers get a prepended `GFP_ATOMIC` or `GFP_KERNEL` argument materialization.
   - `{this,per}_cpu_ptr()` over percpu-allocated memory gets a prepended pointer dereference.

10. Helper inlining / direct-call specialization
   - some map helpers are rewritten into inlined map-specific BPF sequences through `map_gen_lookup()`;
   - some helpers are rewritten by changing `imm` to direct call immediates;
   - helpers such as `bpf_jiffies64`, `bpf_get_smp_processor_id`, `bpf_get_current_task`, `bpf_get_current_task_btf`, `bpf_get_func_arg`, `bpf_get_func_ret`, `bpf_get_func_arg_cnt`, `bpf_get_func_ip`, `bpf_get_branch_snapshot`, and `bpf_kptr_xchg` may be turned into inlined BPF sequences.

This pass alone already spans:

- local fusion,
- helper inlining,
- control-flow synthesis,
- extra hidden subprogram generation,
- stack-layout changes,
- direct-call retargeting.

That is already much closer to a compiler late-lowering pass than to a validator-only stage.

#### `opt_subreg_zext_lo32_rnd_hi32()`

This pass is intentionally late because earlier patching may create new instructions that need zero-extension handling.

It rewrites one instruction into:

- the original instruction plus `BPF_ZEXT_REG(dst)` when the JIT requires architectural zero-extension, or
- a 4-instruction randomized-high-32 sequence under testing flags.

Again, this is proof that the verifier already performs target-aware late BPF rewriting for JIT convenience.

#### `fixup_call_args()` and `jit_subprogs()`

This stage does not use `bpf_patch_insn_data()` as heavily, but it still performs substantial rewriting:

- if JIT is requested, `jit_subprogs()` discovers callee subprograms, temporarily rewrites pseudo-call state, splits the verified program into per-subprogram `struct bpf_prog`s, JITs them, patches call targets, and preserves interpreter fallback state;
- if JIT is not used, `fixup_call_args()` rewrites pseudo calls for interpreter dispatch via `bpf_patch_call_args()`.

This matters for Path B because it means:

- subprogram structure is already a verifier-owned concept;
- call-lowering already happens outside the JIT proper;
- any verifier-level `subprog_inline` must run before `fixup_call_args()` / `jit_subprogs()`.

#### Final pseudo cleanup: `convert_pseudo_ld_imm64()`

This late pass simply clears `src_reg` on pseudo `ldimm64` instructions once their immediates already hold real kernel addresses.

It is small, but it confirms that the final BPF image handed to the JIT is already not the exact user-submitted image.

### 1.4 What information exists at each rewrite point

By the time late rewrites run, the verifier already knows far more than the JIT ever will.

#### Facts produced by core verification

`do_check()` and the earlier analysis pipeline give access to:

- full CFG validity from `check_cfg()`;
- postorder / successor structure;
- SCC information from `compute_scc()`;
- subprogram boundaries in `env->subprog_info`;
- stack depths per subprogram;
- register and stack liveness infrastructure;
- instruction-level aux facts in `struct bpf_insn_aux_data`.

Relevant aux fields include:

- `ptr_type`
- `ctx_field_size`
- `map_ptr_state`
- `map_key_state`
- `nospec`
- `nospec_result`
- `needs_zext`
- `zext_dst`
- `alu_state`
- `alu_limit`
- `non_sleepable`
- `call_with_percpu_alloc_ptr`
- `kptr_struct_meta`
- `obj_new_size`
- `insert_off`
- `arg_prog`
- `loop_inline_state`
- `orig_idx`

And the key verifier routine that establishes memory safety for load/store sites is `check_mem_access()`, which reasons over:

- pointer class (`PTR_TO_STACK`, `PTR_TO_MAP_VALUE`, `PTR_TO_CTX`, `PTR_TO_MEM`, `PTR_TO_BTF_ID`, packet pointers, socket pointers, etc.);
- effective offset and size;
- alignment via `check_ptr_alignment()`;
- region size via `check_mem_region_access()` / `check_map_access()` / `check_packet_access()`;
- special behavior such as context-field size and kptr access.

So the verifier rewrite stage sees:

- exact BPF semantics;
- exact program CFG;
- exact pointer and memory class facts;
- exact subprogram layout;
- target-independent structure plus some target-specific constraints already surfaced by the verifier.

That is exactly the information `branch_reorder` and `subprog_inline` want, and exactly the information the JIT does not have.

#### What each major rewrite site actually sees

The important point is not just that "the verifier knows a lot". Different rewrite sites see different subsets of that information.

1. `inline_bpf_loop()`
   - `loop_inline_state.fit_for_inline`
   - `loop_inline_state.callback_subprogno`
   - caller position
   - synthesized `stack_base`
   - `env->subprog_info[callback_subprogno].start`

2. `opt_subreg_zext_lo32_rnd_hi32()`
   - `aux[adj_idx].zext_dst`
   - `aux[adj_idx].ptr_type`
   - decoded destination/load register
   - `attr->prog_flags & BPF_F_TEST_RND_HI32`
   - `bpf_jit_needs_zext()`

3. `convert_ctx_accesses()`
   - `aux[i + delta].ptr_type`
   - `aux[i + delta].ctx_field_size`
   - `aux[i + delta].nospec`
   - `aux[i + delta].nospec_result`
   - generated prologue/epilogue length
   - `subprogs[0].stack_depth`
   - program-type hooks such as `gen_prologue`, `gen_epilogue`, and `convert_ctx_access`

4. `do_misc_fixups()`
   - `aux[i + delta].needs_zext`
   - `aux[i + delta].alu_state` / `alu_limit`
   - `aux[i + delta].map_ptr_state`
   - `aux[i + delta].map_key_state`
   - `aux[i + delta].non_sleepable`
   - `aux[i + delta].call_with_percpu_alloc_ptr`
   - `aux[i + delta].kptr_struct_meta`
   - `aux[i + delta].obj_new_size`
   - `aux[i + delta].insert_off`
   - `aux[i + delta].arg_prog`
   - `prog_type`, `expected_attach_type`, `prog->jit_requested`, `prog->blinding_requested`
   - subprogram stack depths and starts

5. `fixup_call_args()` / `jit_subprogs()`
   - finalized rewritten call sites
   - `env->subprog_info`
   - saved original pseudo-call immediates in `aux[i].call_imm`
   - computed callee stack depths
   - JIT-requested state

This is exactly why Path B is appealing. The verifier rewrite stage sees:

- more semantic structure than the JIT;
- more safety facts than userspace;
- and more program-wide context than a local peephole emitter.

### 1.5 How current rewrites interact with each other

There are several important interaction rules.

1. Late passes are already ordered carefully.
   - `opt_subreg_zext_lo32_rnd_hi32()` runs after `convert_ctx_accesses()` and `do_misc_fixups()` specifically so newly inserted instructions are seen.
   - `fixup_call_args()` runs after those fixups so it sees the final call sites.
   - `convert_pseudo_ld_imm64()` runs even later, after maps/BTFs have been copied into aux state.

2. Existing passes already compose through repeated splicing.
   - each pass maintains its own `delta`;
   - `bpf_patch_insn_data()` shifts aux data, subprog starts, insn arrays, and poke descriptors.

3. Existing aux provenance is good enough for local patching, but not for arbitrary structural transforms.
   - `orig_idx` is a single integer;
   - inserted instructions mostly get zeroed aux state except for a few copied fields;
   - this is enough for current local fixups, but weak for "keep a stable provenance map across reorder and inlining".

4. The verifier already has examples of rewrite-after-proof.
   - `inline_bpf_loop()` expands a call after verification;
   - `opt_remove_dead_code()` physically deletes instructions after verification;
   - `convert_ctx_accesses()` replaces memory operations after verification.

5. The current machinery is still biased toward local 1->N replacement.
   - there is no general "permute blocks and rebuild all branch offsets" helper;
   - there is no general "rebuild aux state after a structural transform" helper;
   - there is no internal select opcode today.

Those are the exact gaps Path B must close.

## 2. What New Rewrites Could Directives Enable?

### 2.1 Byte-load recomposition (replaces `wide_load`)

#### Core idea

Instead of asking the x86 JIT to detect and fuse a byte-load ladder, the verifier rewrites the ladder into one ordinary wide BPF load:

- 4 bytes -> `BPF_LDX_MEM(BPF_W, ...)`
- 8 bytes -> `BPF_LDX_MEM(BPF_DW, ...)`

Then every existing JIT naturally lowers the rewritten BPF instruction in its normal path.

#### Exact before/after sequence

Example 8-byte little-endian recomposition:

```c
/* before */
BPF_LDX_MEM(BPF_B,  BPF_REG_6, BPF_REG_1, 0);
BPF_LDX_MEM(BPF_B,  BPF_REG_7, BPF_REG_1, 1);
BPF_ALU64_IMM(BPF_LSH, BPF_REG_7, 8);
BPF_ALU64_REG(BPF_OR,  BPF_REG_6, BPF_REG_7);
BPF_LDX_MEM(BPF_B,  BPF_REG_7, BPF_REG_1, 2);
BPF_ALU64_IMM(BPF_LSH, BPF_REG_7, 16);
BPF_ALU64_REG(BPF_OR,  BPF_REG_6, BPF_REG_7);
...
BPF_LDX_MEM(BPF_B,  BPF_REG_7, BPF_REG_1, 7);
BPF_ALU64_IMM(BPF_LSH, BPF_REG_7, 56);
BPF_ALU64_REG(BPF_OR,  BPF_REG_6, BPF_REG_7);

/* after */
BPF_LDX_MEM(BPF_DW, BPF_REG_6, BPF_REG_1, 0);
```

Example 4-byte recomposition:

```c
/* before */
BPF_LDX_MEM(BPF_B,  BPF_REG_2, BPF_REG_1, 12);
BPF_LDX_MEM(BPF_B,  BPF_REG_3, BPF_REG_1, 13);
BPF_ALU64_IMM(BPF_LSH, BPF_REG_3, 8);
BPF_ALU64_REG(BPF_OR,  BPF_REG_2, BPF_REG_3);
BPF_LDX_MEM(BPF_B,  BPF_REG_3, BPF_REG_1, 14);
BPF_ALU64_IMM(BPF_LSH, BPF_REG_3, 16);
BPF_ALU64_REG(BPF_OR,  BPF_REG_2, BPF_REG_3);
BPF_LDX_MEM(BPF_B,  BPF_REG_3, BPF_REG_1, 15);
BPF_ALU64_IMM(BPF_LSH, BPF_REG_3, 24);
BPF_ALU64_REG(BPF_OR,  BPF_REG_2, BPF_REG_3);

/* after */
BPF_LDX_MEM(BPF_W,  BPF_REG_2, BPF_REG_1, 12);
```

#### What the verifier must prove

The existing verifier proof for byte loads is not enough by itself. It proved `N` separate byte loads are safe, not that one 4-byte or 8-byte load is safe.

A sound verifier-side rewrite must additionally prove:

1. The region is straight-line.
   - no interior jump targets;
   - no helper calls, exits, or side effects in the middle.

2. The value really is a contiguous little-endian byte gather.
   - one base register;
   - one contiguous offset ladder;
   - one exact use of each byte;
   - one live-out result register;
   - all temporary values are dead after the region.

3. The wide replacement load is itself legal.
   - re-run `check_mem_access()`-equivalent logic on the proposed `BPF_W` or `BPF_DW` load;
   - re-check alignment through `check_ptr_alignment()`;
   - reject if the original byte ladder was legal but the wide access is not.

4. Fault behavior is preserved.
   - initial versions should stay away from `BPF_PROBE_MEM*` / untrusted BTF loads / faulting loads where changing load width changes exception behavior.

#### Feasibility assessment

This is strongly feasible at verifier level.

Why:

- it is already an ordinary BPF instruction after rewriting;
- the verifier already knows pointer type, offset class, and alignment policy;
- it automatically works on x86, arm64, and any other JIT because the JIT sees only `LDX W` or `LDX DW`.

The main caveat is that this optimization is structurally verifier-friendly but weak as a userspace-policy story. It is a profitable substrate case, not the novelty anchor.

#### Important subtlety

`convert_ctx_accesses()` already does a related transformation today: it sometimes widens a narrower context-field load to a 4-byte or 8-byte load and then reconstructs the originally requested narrow field with mask/shift.

So byte-load recomposition is not alien to the current verifier. It is the same class of idea applied to a larger source pattern.

### 2.2 Branch-to-cmov (replaces `cmov_select`)

#### Core idea

The conceptual transform is right:

- recognize a one-entry, one-join diamond;
- replace branchy control flow with an explicit selection operation;
- let the x86 JIT lower that to `cmp` + `cmovcc`, and arm64 lower it to `cmp` + `csel`.

But there is a key difference from byte-load recomposition:

today's BPF ISA has no select instruction.

#### Exact before/after sequence

Current branch diamond:

```c
/* before */
BPF_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_2, +2);   /* true -> insn 3 */
BPF_MOV64_REG(BPF_REG_3, BPF_REG_4);              /* false arm */
BPF_JMP_A(+1);
BPF_MOV64_REG(BPF_REG_3, BPF_REG_5);              /* true arm */
/* join */
```

Conceptual rewritten form:

```c
/* after: pseudo syntax, not current ISA */
BPF_SELECT64(dst = BPF_REG_3,
             cc = BPF_JGT,
             lhs = BPF_REG_1,
             rhs = BPF_REG_2,
             false_val = BPF_REG_4,
             true_val  = BPF_REG_5);
```

Immediate-arm variant:

```c
/* before */
BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, +2);
BPF_MOV64_IMM(BPF_REG_0, 1);
BPF_JMP_A(+1);
BPF_MOV64_IMM(BPF_REG_0, 42);

/* after: pseudo syntax */
BPF_SELECT64(dst = BPF_REG_0,
             cc = BPF_JEQ,
             lhs = BPF_REG_1,
             rhs_imm = 0,
             false_imm = 1,
             true_imm  = 42);
```

#### What new internal opcodes would be needed?

There are three realistic choices.

##### Option A: a real internal-only `BPF_SELECT`

Introduce one or more verifier/JIT/interpreter-only pseudo instructions, never exposed to user bytecode.

At minimum we need variants that encode:

- compare width: 32 or 64;
- compare source kind: reg/reg or reg/imm;
- arm kind: reg/reg, reg/imm, imm/reg, imm/imm;
- destination register.

One instruction does not have enough fields to carry all of:

- compare lhs
- compare rhs
- destination
- true value
- false value
- condition code

So a realistic internal encoding is a short bundle, for example:

1. `BPF_SELECT_CMP32/64`
2. `BPF_SELECT_VAL32/64`

or even:

1. compare descriptor
2. false-arm descriptor
3. true-arm descriptor

This is doable, but it is new internal ISA surface.

##### Option B: aux metadata only, no BPF rewrite

The verifier recognizes the diamond and stores a normalized "select region" plan in aux metadata, and the JIT consumes that.

That avoids new BPF opcodes, but it is no longer a pure verifier rewrite. It is back to a hybrid verifier-recognition / JIT-lowering design.

##### Option C: encode select with existing BPF instructions

For general diamonds, this is not realistic.

BPF has:

- branches;
- moves;
- ALU ops;

but no exposed flag register, no `setcc`, and no true conditional move. A faithful straight-line replacement of a diamond is therefore not expressible with today's ISA in the general case.

#### What the verifier must prove

The validator would need to prove the same core shape as the current narrow `cmov_select` design:

1. exactly one entry branch and one join;
2. no interior targets;
3. each arm performs exactly one assignment to the same destination register;
4. no side effects in either arm;
5. compare condition maps exactly to the requested condition code;
6. 32-bit forms preserve zero-extension semantics.

#### Feasibility assessment

Conceptually: strong.

As a pure BPF rewrite using today's ISA: not feasible.

As a verifier-level normalization to a new internal opcode: feasible, but invasive.

This is the first place where Path B stops being "just move the same design earlier" and becomes "extend the internal BPF vocabulary".

That does not kill the idea. It does mean the honest design is:

- verifier owns region recognition and legality;
- verifier rewrites the diamond to an internal select abstraction;
- the JIT remains responsible for target-specific lowering to `cmovcc`, `csel`, or a retained branch.

So this optimization is best viewed as a hybrid even under Path B.

### 2.3 Basic block reordering (replaces `branch_reorder`)

#### Core idea

This is the cleanest Path B win.

Unlike `cmov_select`, basic-block reordering is already expressible in ordinary BPF:

- physically move basic blocks in the BPF instruction stream;
- invert branches where necessary;
- recompute jump offsets.

No new opcode is needed.

#### Exact before/after sequence

Simple one-diamond example:

```c
/* before: true arm is hot but not fall-through */
0: BPF_JMP_IMM(BPF_JGT, BPF_REG_1, 0, +2);   /* true -> 3 */
1: /* cold false block */
2: BPF_JMP_A(+1);
3: /* hot true block */
4: /* join */
```

Reordered to make the hot path fall through:

```c
/* after */
0: BPF_JMP_IMM(BPF_JLE, BPF_REG_1, 0, +2);   /* cold -> 3 */
1: /* hot true block */
2: BPF_JMP_A(+1);
3: /* cold false block */
4: /* join */
```

Multi-instruction arm example:

```c
/* before */
10: BPF_JMP_REG(BPF_JSGT, BPF_REG_6, BPF_REG_7, +3);  /* hot true -> 14 */
11: BPF_MOV64_IMM(BPF_REG_0, 0);                      /* cold false */
12: BPF_STX_MEM(BPF_DW, BPF_REG_FP, BPF_REG_1, -8);   /* cold false */
13: BPF_JMP_A(+2);                                    /* -> join */
14: BPF_MOV64_IMM(BPF_REG_0, 1);                      /* hot true */
15: BPF_MOV64_REG(BPF_REG_8, BPF_REG_9);              /* hot true */
16: /* join */

/* after */
10: BPF_JMP_REG(BPF_JSLE, BPF_REG_6, BPF_REG_7, +3);  /* cold false -> 14 */
11: BPF_MOV64_IMM(BPF_REG_0, 1);                      /* hot true */
12: BPF_MOV64_REG(BPF_REG_8, BPF_REG_9);              /* hot true */
13: BPF_JMP_A(+2);                                    /* -> join */
14: BPF_MOV64_IMM(BPF_REG_0, 0);                      /* cold false */
15: BPF_STX_MEM(BPF_DW, BPF_REG_FP, BPF_REG_1, -8);   /* cold false */
16: /* join */
```

#### What the verifier must prove

For a first implementation, the validator should be much narrower than "arbitrary CFG scheduling":

1. the region is one closed diamond;
2. there is one entry and one join;
3. no external edge enters either interior arm;
4. the join post-dominates both arms;
5. neither arm crosses a subprogram boundary;
6. neither arm contains instructions whose semantics depend on remaining in their original relative location inside a larger open region;
7. every affected jump offset can be recomputed in range.

The verifier already has the right raw ingredients:

- CFG validity from `check_cfg()`;
- SCC structure from `compute_scc()` to reject loops/backedges in v1;
- subprogram boundaries from `subprog_info`;
- instruction metadata arrays that can be moved with the rewritten instructions.

#### Required new verifier machinery

This is where Path B needs a real new helper, because `adjust_jmp_off()` is not enough.

We would need a general block-permutation routine that:

1. materializes an `old_idx -> new_idx` map for the transformed region;
2. rewrites all branch offsets that target moved blocks;
3. moves corresponding aux data with the moved instructions;
4. updates line info, insn arrays, poke descriptors, and subprog starts.

That is more work than a local splice, but it is exactly the kind of work that belongs at the BPF level, not in `do_jit()`.

#### Feasibility assessment

This is the strongest verifier-level candidate in the whole set.

Why:

- it is naturally a BPF-level transform;
- it is inherently non-local, so it is a poor fit for current JIT emission;
- it is target-neutral;
- it directly addresses the biggest weakness of the current JIT-level proposal.

If Path B becomes the new direction, `branch_reorder` is the most compelling reason.

### 2.4 Subprogram inlining (replaces `subprog_inline`)

#### Core idea

This also belongs conceptually at verifier level, because subprograms are a verifier concept before they are a JIT concept.

The verifier already knows:

- all subprogram boundaries;
- stack depth per subprogram;
- call graph structure;
- which instructions are `BPF_PSEUDO_CALL` / `BPF_PSEUDO_FUNC`.

Inlining means replacing a call site with a copy of the callee body, then retargeting internal branches and converting callee exits to jumps back to the continuation.

#### Exact before/after sequence

Minimal conceptual example:

```c
/* caller before */
10: BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
11: BPF_CALL_REL(+4);                  /* callee starts at 16 */
12: BPF_MOV64_REG(BPF_REG_7, BPF_REG_0);
13: BPF_EXIT_INSN();

/* callee */
16: BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_1, 0);
17: BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 8);
18: BPF_EXIT_INSN();
```

After inlining:

```c
/* caller after */
10: BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
11: BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_1, 0);
12: BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 8);
13: BPF_MOV64_REG(BPF_REG_7, BPF_REG_0);
14: BPF_EXIT_INSN();
```

Callee stack rewrite example:

```c
/* callee before */
BPF_STX_MEM(BPF_DW, BPF_REG_FP, BPF_REG_1, -8);
BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_FP, -8);
```

If the caller reserves an extra 16-byte inline frame for this callee, those become:

```c
/* after inline into caller */
BPF_STX_MEM(BPF_DW, BPF_REG_FP, BPF_REG_1, -24);
BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_FP, -24);
```

#### Main challenges

This is much harder than block reorder.

1. Stack-frame translation
   - callee stack slots are relative to its own `R10`;
   - after inlining, every `FP` access in the callee body must be remapped into caller frame space;
   - caller stack depth must be increased accordingly.

2. Exit rewriting
   - callee `BPF_EXIT` no longer means "return from the whole program";
   - it must become a jump to the call continuation.

3. Internal branch retargeting
   - all branches inside the copied callee body must be retargeted to the copied body, not the original subprogram.

4. Nested calls
   - a copied callee may itself contain bpf-to-bpf calls;
   - v1 likely needs to inline only leaf subprograms.

5. Metadata rebuild
   - `subprog_info`, `func_info`, line info, and possibly kallsyms-related layout all change;
   - removed subprograms should disappear from the final program image.

6. Verification facts are no longer obviously reusable
   - original proof was over caller + callee with call-frame semantics;
   - after inlining, stack offsets and CFG shape change.

#### Do we need to re-verify?

For this transform, yes in practice.

A safe implementation should assume that inlining invalidates enough derived verifier state that the rewritten program must at least rerun:

- `check_subprogs()`
- `check_cfg()`
- `compute_postorder()`
- `compute_scc()`
- `compute_live_registers()`
- `do_check_main()` / `do_check_subprogs()`
- `check_max_stack_depth()`

The existing late-patch machinery is not enough by itself.

#### Feasibility assessment

In principle: yes.

For a v1 verifier-rewrite prototype: probably too invasive.

This is still a better conceptual fit for the verifier than for the JIT. It just belongs in a more ambitious second phase, not the first cut.

### 2.5 Redundant bounds check elimination

#### Core idea

The tempting argument is:

- the verifier already knows pointer bounds;
- therefore it should be able to remove explicit user-authored bounds checks that are redundant.

This is mostly the wrong optimization story.

#### Exact sequence and the key caveat

Example:

```c
/* user-authored check */
BPF_JMP_IMM(BPF_JGE, BPF_REG_2, 64, +2);
BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0);   /* imagine r1+r2 addressing before this */
BPF_JMP_A(+1);
/* slow / reject path */
```

There are two cases.

1. The verifier already knows the condition is always false or always true on all reachable states.
   - then one arm is dead;
   - `opt_hard_wire_dead_code_branches()` plus `opt_remove_dead_code()` already remove it today.

2. The condition is not dead.
   - then removing it changes program behavior on inputs that fail the check;
   - verifier proof of safety for the original program does not authorize that semantic change.

So the safe subset is mostly already implemented as dead-branch elimination.

#### Feasibility assessment

As a general userspace-guided directive: weak.

As an internal cleanup after other rewrites: maybe.

As a headline verifier-rewrite optimization: no.

This transform is fundamentally different from block reordering or byte-load recomposition:

- those preserve semantics while changing implementation structure;
- general bounds-check elimination changes semantics unless the check is already dead.

### 2.6 Dead store/load elimination

#### Core idea

After aggressive verifier rewrites, some newly introduced stack spills, fills, or temporary loads can become dead.

Example:

```c
/* before */
BPF_STX_MEM(BPF_DW, BPF_REG_FP, BPF_REG_1, -8);
BPF_LDX_MEM(BPF_DW, BPF_REG_2, BPF_REG_FP, -8);
/* no later use of BPF_REG_2 and no other read of fp[-8] */

/* after */
/* both instructions removed */
```

The verifier already has a tiny specialized version of this:

- `remove_fastcall_spills_fills()` turns matched spill/fill pairs into NOPs;
- `opt_remove_nops()` deletes them.

#### What would be needed for a general pass

The verifier already computes liveness, but not in a form that can simply be reused after arbitrary late rewriting.

A general DSE pass would need one of:

1. a new retained per-insn live-out summary for rewritten programs; or
2. a rerun of liveness on the rewritten program.

It would also need to distinguish:

- stack stores that are semantically dead;
- loads whose only use is dead;
- temporary values inserted by helper inlining or block normalization;
- stores that cannot be deleted because of helper-visible side effects, aliasing, or exception behavior.

#### Feasibility assessment

Feasible as a verifier-owned cleanup pass.

Weak as a userspace directive by itself.

This feels like a secondary kernel-owned cleanup that should run after other structural rewrites, not something userspace should micromanage directly.

## 3. Advantages Over the JIT-Level Approach

### 3.1 The JIT stays simple

The x86 JIT can remain what it already is:

- a linear emitter over `prog->insnsi`;
- a repeated size-discovery loop with `addrs[]`;
- a target-specific lowering pass, not a CFG transformer.

No need to teach `do_jit()` how to:

- reorder blocks;
- duplicate or inline regions;
- maintain multiple native PCs for one BPF instruction;
- recover from non-local directive failure while preserving `addrs[]`.

### 3.2 The verifier already has the right facts

The verifier already owns:

- CFG shape;
- subprogram boundaries;
- stack depth;
- pointer type;
- context-layout facts;
- map/kfunc metadata;
- speculation-safety metadata.

Those are exactly the facts structural transforms need.

The JIT does not have them. It only sees a finalized BPF instruction stream plus some aux flags that were retained for lowering.

### 3.3 Rewrites happen at the BPF level, so they are cross-architecture

If the verifier turns:

- 8 byte loads into one `BPF_LDX_MEM(BPF_DW, ...)`;
- a hot/cold diamond into reordered BPF blocks;
- a call site into an inlined callee body;

then every JIT sees the same rewritten BPF.

That means:

- x86 benefits;
- arm64 benefits;
- interpreter semantics can also benefit if the transform uses ordinary BPF instructions.

This is a stronger story than "x86 learned a userspace-guided peephole".

### 3.4 Non-local transforms become natural

At verifier level, `branch_reorder` is just:

- CFG validation;
- instruction permutation;
- jump retargeting.

At verifier level, `subprog_inline` is just:

- call-site expansion;
- stack-offset rewrite;
- callee-exit retargeting.

At JIT level, both are awkward because the JIT is already in the business of:

- emitting native code in one linear walk;
- resolving branches through native offsets, not BPF blocks.

### 3.5 It is easier to defend against "just add kernel peepholes"

If the framework only does `wide_load` and `cmov_select` inside x86 emission, reviewers can say:

"These are just kernel peepholes."

If the framework instead does:

- verifier-level block layout,
- verifier-level structural normalization,
- possible eventual subprogram inlining,

then the contribution is no longer "fancier x86 peepholes". It is a new control point in the verified BPF pipeline.

## 4. Disadvantages and Challenges

### 4.1 The verifier is security-critical

Every extra rewrite validator increases attack surface in the most sensitive part of the BPF stack.

The current late passes are already correctness-critical, but they are mostly owned by kernel code with narrowly defined semantics.

Path B would add:

- userspace-triggered structural rewrites;
- new provenance / remap machinery;
- possibly new internal opcodes.

That needs a much stronger soundness story than the current JIT-level local-fusion design.

### 4.2 Existing metadata helpers are splice-oriented, not permutation-oriented

Current helpers can cope with:

- one instruction becoming several;
- deletion of dead ranges;
- simple target-offset shifts.

They do not yet provide:

- arbitrary block permutation;
- instruction duplication with canonical provenance;
- rebuilt live-out summaries;
- rebuilt aux facts after deep structural transforms.

`branch_reorder` and `subprog_inline` therefore require real new verifier infrastructure.

### 4.3 `BPF_SELECT` is not free

For `cmov_select`, verifier-level normalization is only clean if the kernel accepts a new internal select abstraction.

That raises new questions:

- should the interpreter support it?
- what happens if JIT compilation later fails?
- how are multi-word immediates encoded?
- is it a true new internal instruction, or a short pseudo bundle?

This is a larger kernel design change than byte-load recomposition or block reorder.

### 4.4 Some "cross-architecture" rewrites still have target-sensitive legality

Byte-load recomposition is the best example.

Even at the BPF level, replacing eight byte loads with one 8-byte load is only legal if the resulting 8-byte load is legal on this kernel:

- alignment policy may differ;
- untrusted memory classes may have different fault behavior;
- some access classes become `BPF_PROBE_MEM*` instead of plain `LDX`.

So verifier-level does not magically remove all target sensitivity. It just moves it into verifier legality checking instead of JIT emission.

### 4.5 Re-verification may be required

For local rewrites, local validation is enough.

For structural rewrites like subprogram inlining, previous verifier state is not obviously reusable. At that point the safest route is:

- rewrite;
- rerun major parts of verification.

That increases load-time cost and implementation complexity.

### 4.6 Interaction with existing rewrite order matters

This is not a blank slate. Current passes already depend on order:

- `convert_ctx_accesses()` expects original verified access patterns plus aux pointer types;
- `do_misc_fixups()` expects post-ctx-rewrite instructions;
- `opt_subreg_zext_lo32_rnd_hi32()` expects all earlier insertions already happened;
- `fixup_call_args()` expects final call sites and subprogram boundaries.

A new directive pass must either:

- run early enough that later passes see the rewritten BPF naturally; or
- run late enough that it does not invalidate earlier derived state.

There is no single universally correct insertion point for every directive family.

## 5. Hybrid Approach

The cleanest answer is probably not "move everything to the verifier" or "keep everything in the JIT". It is to split by abstraction level.

### 5.1 Best verifier-level candidates

These are naturally BPF-structural:

- `branch_reorder`
- `subprog_inline` (future, with re-verification)
- byte-load recomposition
- dead-code / dead-NOP / local cleanup after structural rewrites

These are about the shape of the BPF program, not the last-mile instruction encoding.

### 5.2 Best JIT-level candidates

These are naturally target-specific lowerings:

- how an internal select becomes `cmovcc` on x86 vs `csel` on arm64;
- short encoding choices;
- `lea`-style address arithmetic fusion;
- rotate/BMI2 encodings;
- zero-displacement encoding choices.

Those are backend decisions even after the BPF program shape is fixed.

### 5.3 Split responsibility for `cmov_select`

This optimization lands in the middle:

- verifier-level: recognize and normalize the diamond into an internal select abstraction;
- JIT-level: choose whether to lower that abstraction to `cmovcc`, `csel`, or keep branches.

That preserves the good part of Path B:

- non-local region recognition happens where CFG exists;

while preserving the good part of Path A:

- actual microarchitecture-sensitive lowering remains in the backend.

### 5.4 Recommended division

If the project pivots to Path B, the most coherent split is:

- verifier-level directives for structural program rewrites;
- JIT-level directives only for target-specific lowering of internal verifier-normalized forms.

That makes the system:

- cross-architecture where it should be;
- target-specific only where it must be.

## 6. Concrete Implementation Plan

### 6.1 Recommended placement in the pipeline

There should be two classes of directive-guided rewrites.

#### Class A: local or CFG-closed rewrites that preserve stack/call structure

Examples:

- byte-load recomposition
- one-diamond block reorder
- branch-to-select normalization

Recommended placement:

after:

- `do_check_main()` / `do_check_subprogs()`
- dead-code cleanup (`opt_hard_wire_dead_code_branches()`, `opt_remove_dead_code()`, `opt_remove_nops()` or `sanitize_dead_code()`)

before:

- `convert_ctx_accesses()`
- `do_misc_fixups()`

Why:

- the verifier has all legality facts already;
- dead branches are already gone, which simplifies region matching;
- the BPF program is still close to source structure, which makes directive matching easier;
- later ctx/helper fixups naturally see the rewritten BPF.

#### Class B: structural rewrites that change stack or call structure

Example:

- `subprog_inline`

Recommended placement:

- also after core `do_check_*()`;
- but only in a separate structural phase that is followed by re-verification.

This likely implies moving or redoing:

- `check_max_stack_depth()`
- `check_subprogs()`
- later metadata setup

for the rewritten program.

### 6.2 Proposed new pass structure

A realistic implementation could look like this:

1. current front half of `bpf_check()` stays unchanged through `do_check_main()` / `do_check_subprogs()`.
2. dead-code cleanup runs as today.
3. `apply_user_verifier_directives(env, phase1)` runs.
   - handles only local/closed rewrites in v1.
4. existing `convert_ctx_accesses(env)` runs on the rewritten program.
5. existing `do_misc_fixups(env)` runs on the rewritten program.
6. optional `apply_user_verifier_directives(env, phase2)` runs for very local late cleanups if needed.
7. `opt_subreg_zext_lo32_rnd_hi32(env, attr)` runs.
8. `fixup_call_args(env)` / `jit_subprogs(env)` run.
9. `convert_pseudo_ld_imm64(env)` runs.

For future `subprog_inline`, insert a separate structural phase after step 2 and rerun the necessary verifier analyses before step 4.

### 6.3 How to ensure safety

Different rewrite classes need different validation strength.

#### Byte-load recomposition

Validate locally:

- region shape;
- contiguous offsets;
- same base register;
- dead temps;
- wide access legality via `check_mem_access()`-equivalent recheck.

No full re-verification required if stack/call structure is unchanged.

#### One-diamond block reorder

Validate structurally:

- exact diamond shape;
- no external entries into interior blocks;
- same live-in / live-out set at the join;
- same side effects, just reordered;
- branch offsets rewritten exactly.

No full semantic re-verification is strictly necessary if the rewrite is only a permutation of a closed region and aux data is moved with the instructions, but a dedicated structural validator is required.

#### Branch-to-select

Validate structurally plus semantically:

- exact diamond shape;
- pure assignment arms;
- exact condition-code mapping;
- destination-only live-out difference.

If implemented with a new internal opcode, either:

- interpreter support must be added, or
- JIT failure after rewrite must become a hard load failure, not an interpreter fallback.

#### Subprogram inline

Treat as requiring re-verification.

Do not try to "patch aux data and hope".

### 6.4 Do we need to re-verify?

Recommended answer by class:

- byte-load recomposition: no full re-verification
- block reorder of a closed diamond: no full re-verification, but strong structural validation
- branch-to-select with internal opcode: no full re-verification if validator is exact and interpreter/JIT semantics are defined
- subprogram inlining: yes

In other words:

- local/closed transformations can be validator-driven;
- call-graph and stack-structure changes should be re-verified.

### 6.5 New infrastructure likely needed

Path B likely needs at least the following new pieces.

1. A verifier-side directive plan object.
   - similar to the current idea of a parsed directive blob, but consumed before JIT.

2. Better provenance than one `orig_idx`.
   - for repeated rewrites, a single integer is too weak;
   - likely need an origin span or stable site identifier.

3. A general block-permutation helper.
   - splice helpers are not enough for `branch_reorder`.

4. Optional internal select abstraction.
   - required for a clean verifier-level `cmov_select`.

5. A re-verification path for structural rewrites.
   - at least for `subprog_inline`.

## 7. Comparison Table

| Optimization | JIT-level feasible? | Verifier-level feasible? | Better at which level? | Why |
| --- | --- | --- | --- | --- |
| Byte-load recomposition / `wide_load` | Yes | Yes | Verifier-level, if the goal is cross-arch BPF rewriting | It is naturally expressible as ordinary `LDX W/DW`; verifier can re-check legality; all JITs benefit automatically. |
| Branch-to-cmov / `cmov_select` | Yes for narrow local diamonds | Yes only with a new internal select abstraction | Hybrid | Verifier is the right place to recognize and normalize the diamond; JIT is still the right place to choose `cmovcc` vs `csel` vs branch. |
| Basic block reordering / `branch_reorder` | Not a good fit for current linear `do_jit()` | Yes | Verifier-level | This is a BPF CFG transform. The verifier has CFG and state facts; the current JIT does not. |
| Subprogram inlining / `subprog_inline` | No, not cleanly | Yes in principle, but heavy | Verifier-level | Subprograms are verifier-owned structure. JIT-side inlining collides with `jit_subprogs()` and the split-prog pipeline. |
| Redundant bounds-check elimination | Only trivially | Only for the already-dead subset | Neither as a directive family | Safe elimination is mostly already covered by verifier dead-code removal; general elimination changes semantics. |
| Dead store/load elimination | Only tiny local peepholes | Yes, with liveness recompute or retained live-out data | Verifier internal cleanup, not a primary userspace directive | It is analysis-driven compiler cleanup, not a strong policy-guided directive. |

## 8. Impact on Novelty

### 8.1 Does Path B strengthen the paper story?

Yes, if the paper pivots from:

- "userspace-guided JIT lowering"

to:

- "userspace-guided verifier rewriting plus target-specific JIT lowering"

because it directly solves the current design's biggest weakness:

- the strongest candidate optimizations are non-local;
- the current JIT is structurally local.

### 8.2 Which framing is more novel?

Between:

- userspace-guided JIT lowering
- userspace-guided verifier optimization

the second is more novel and broader.

Why:

1. It is no longer tied to one backend's peepholes.
2. It naturally supports structural transforms like block layout and eventual inlining.
3. It applies across architectures at the BPF level.
4. It is easier to defend as a new kernel/userspace split rather than "kernel peepholes with a blob format".

### 8.3 Which is more defensible against "just add kernel peepholes"?

Verifier-level structural rewriting is much more defensible.

Reviewers can still say:

"Why not just do this in LLVM before load?"

The answer is better here than in the JIT-level story:

- some facts only exist after verification and target binding:
  - actual context-access rewrites,
  - actual map and BTF types,
  - actual pointer classes,
  - actual subprogram layout after verifier normalization,
  - actual dead branches after verifier reasoning.
- the verifier already owns the trusted legality plane;
- userspace is still deciding profitability, not injecting arbitrary code.

That is a stronger and more publishable split than "userspace suggests a few x86 emission choices".

### 8.4 Important caution

Path B only strengthens novelty if it is used for things that really need it.

If the prototype only does byte-load recomposition in the verifier, reviewers can still say:

"This is just one more kernel optimization pass."

Path B becomes compelling only if it carries at least one transformation that the current JIT-level plan cannot honestly support:

- one-diamond hot/cold block reorder is the best near-term candidate;
- internal-select normalization is a second strong candidate if the new internal opcode is acceptable;
- subprogram inline is the long-term big win, but not a first implementation target.

## Bottom line

The verifier-rewrite approach is directionally better than the current JIT-level approach for the optimizations that matter most.

The cleanest reading is:

- `wide_load` becomes `byte_load_recompose` at verifier level;
- `branch_reorder` clearly belongs at verifier level;
- `cmov_select` becomes a hybrid: verifier-level normalization, JIT-level lowering;
- `subprog_inline` also belongs at verifier level, but only with a stronger second-phase implementation that reruns verification.

So if the project changes direction, the right v1 Path B is not "move every directive into the verifier".

It is:

1. move structural BPF rewrites into the verifier;
2. keep target-specific encoding choices in the JIT;
3. use the verifier as the legality owner for non-local transformations the current JIT cannot naturally express.
