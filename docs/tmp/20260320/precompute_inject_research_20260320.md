# Pre-compute + Inject JIT Refactoring Feasibility

Date: 2026-03-20

## Executive Verdict

The refactor is feasible in the narrow sense that existing rule sites can be precomputed into fixed native blobs and then injected at the top of the per-insn loop, while leaving convergence, branch-offset recomputation, subprog staging, and exception-table generation to the existing JIT passes.

The important correction is that step 1 is **not** true as stated:

- On x86, the current emitters do not need `addrs[]`, `oldproglen`, or the current native PC, but they do need at least `use_priv_fp` via `jit_bpf_reg()` (`arch/x86/net/bpf_jit_comp.c:1060-1066`). `ZERO_EXT_ELIDE` and `BRANCH_FLIP` also depend on the same CPU-feature-driven lowering choices already embedded in helper emitters such as `emit_bpf_alu32_insn()` and `emit_bpf_alu64_insn()` (`arch/x86/net/bpf_jit_comp.c:2311-2501`, `2645-2842`).
- On arm64, the current emitters are structurally local and do not need `ctx->offset` or a current global branch target, but they are not params-only either. `WIDE_MEM` depends on `ctx->priv_sp_used` and `ctx->stack_size` when the base register is `BPF_REG_FP` through `arm64_resolve_mem_base()` (`arch/arm64/net/bpf_jit_comp.c:602-617`, `733-737`).

So the right abstraction is:

- `canonical_params` + a tiny arch-specific emit environment
- not `canonical_params` alone

The other major conclusion is that the "inject at the top of the loop" structure already exists today:

- x86 already has a 15-line direct hook in `do_jit()` (`arch/x86/net/bpf_jit_comp.c:3295`, `3299`, `3378-3390`)
- arm64 already has an 11-line direct hook in `build_body()` (`arch/arm64/net/bpf_jit_comp.c:2551-2552`, `2569-2577`)

So this refactor does **not** materially simplify `do_jit()` / `build_body()` themselves. The code movement is mostly in helper glue and emitter placement, not in the main loops.

## Files Read

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/bpf.h`

## Current Recompile Path

### Shared orchestration

`bpf_prog_jit_recompile()` in `kernel/bpf/jit_directives.c:577-740`:

- validates permissions and policy
- snapshots the live JIT state (`152-209`)
- swaps the validated policy onto `main_aux->jit_policy` (`687-690`)
- calls `bpf_jit_recompile_prog_images()` (`292-575`)

`bpf_jit_recompile_prog_images()`:

- marks every image as `jit_recompile_active` (`322-332`)
- recompiles every image once (`334-346`)
- for multi-function programs, rewrites pseudo-func / pseudo-call targets to staged/live addresses (`348-395`)
- recompiles every image again for the final pass (`398-410`)
- commits staged images or aborts/rolls back (`438-575`)

Important implication:

- avoiding a full re-run entirely is hard for multi-function programs, because the generic recompile path already performs a second compile after subprog targets are rewritten

Also note the explicit comment at `jit_directives.c:413-419`: even when no rule changes lowering, a fresh JIT image can perturb relocation-sensitive bytes such as helper-call displacements. That is a direct warning against "just patch the final text" unless relocation is fully understood.

### Shared rule validation

`canonical_params` is only 16 typed scalar slots (`include/linux/bpf_jit_directives.h:35-37`). `BRANCH_FLIP` uses pointer-valued slots to hold copied BPF instruction arrays (`108-116`).

Rules are validated by `bpf_jit_validate_rule()` (`kernel/bpf/jit_validators.c:1676-1731`), which:

- checks header and range
- checks arch support through `bpf_jit_arch_form_supported()`
- rejects side effects for most forms (`1714-1719`)
- rejects exterior jumps into the middle of a rewritten site via `bpf_jit_has_interior_edge()` (`140-200`, `1724-1728`)

That interior-edge rejection is exactly what makes collapsed `addrs[]` / `offset[]` entries safe.

## What The Main Loops Already Do

### x86

`do_jit()` is at `arch/x86/net/bpf_jit_comp.c:3289-4400`.

At the top of the per-insn loop:

- `main_aux` is loaded at `3295`
- `has_active_rules` is computed at `3299`
- the rule hook runs at `3378-3390`

The rule hook already:

- looks up a rule for the current BPF insn
- emits replacement native bytes
- updates `addrs[]`
- skips the consumed BPF insns

The canonical-form call sites are **not** scattered through `do_jit()`. They are centralized in `bpf_jit_try_emit_rule()` at `3151-3202`:

- `COND_SELECT` at `3152-3156`
- `WIDE_MEM` at `3158-3162`
- `ROTATE` at `3164-3169`
- `ADDR_CALC` at `3171-3175`
- `BITFIELD_EXTRACT` at `3177-3182`
- `ZERO_EXT_ELIDE` at `3184-3189`
- `ENDIAN_FUSION` at `3191-3195`
- `BRANCH_FLIP` at `3197-3202`

### arm64

`build_body()` is at `arch/arm64/net/bpf_jit_comp.c:2548-2595`.

At the top of its per-insn loop:

- `main_aux` is loaded at `2551`
- `has_active_rules` is computed at `2552`
- the rule hook runs at `2569-2577`

Again, the per-form call sites are centralized in `bpf_jit_try_emit_rule()` at `918-939`:

- `ROTATE` at `919-924`
- `WIDE_MEM` at `925-929`
- `BITFIELD_EXTRACT` at `930-934`
- `COND_SELECT` at `935-939`

arm64 only supports those four forms today (`arch/arm64/net/bpf_jit_comp.c:3920-3934`).

## Per-Form Feasibility

### Summary table

| Form | x86 today | arm64 today | Needs current native offset / global relocation? | Can precompute as params-only? | Feasible with tiny arch env? | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `ROTATE` | supported | supported | No | x86: no, arm64: yes | Yes | x86 needs `use_priv_fp`; arm64 does not need offset state |
| `WIDE_MEM` | supported | supported | No | No | Yes | arm64 needs `priv_sp_used` + `stack_size` for FP base |
| `ADDR_CALC` | supported | unsupported | No | No | Yes on x86 | x86 uses `use_priv_fp` through register mapping |
| `COND_SELECT` | supported | supported | No | x86: no, arm64: yes | Yes | no internal relative jumps on either arch |
| `BITFIELD_EXTRACT` | supported | supported | No | x86: no, arm64: yes | Yes | x86 needs `use_priv_fp` if FP appears in params |
| `ZERO_EXT_ELIDE` | supported | unsupported | No | No | Yes on x86 | output depends on x86 ALU32 helper lowering choices |
| `ENDIAN_FUSION` | supported | unsupported | No | No | Yes on x86 | no extable interaction for current matched sites |
| `BRANCH_FLIP` | supported | unsupported | No external offset; only local jump sizing | No | Yes on x86 | bodies are copied BPF insn arrays and must be re-emitted with same arch env |

### Detailed notes per form

#### `COND_SELECT`

x86:

- emitter: `emit_canonical_select()` (`arch/x86/net/bpf_jit_comp.c:1320-1408`)
- uses `emit_bpf_jmp_cmp()` plus `cmov`, not relative jumps
- no `addrs[]`, `image`, `oldproglen`, or current native offset
- depends on `use_priv_fp` because it uses `jit_bpf_reg()` and binding-value helpers

arm64:

- emitter: `emit_canonical_select_arm64()` (`arch/arm64/net/bpf_jit_comp.c:805-895`)
- emits compare + `CSEL`/`CSET`/`CSETM`
- no relative branches inside the emitter
- no dependency on `ctx->offset` or current native PC

Verdict:

- feasible to precompute
- `COND_SELECT` does **not** need internal relative jumps on either arch

#### `BRANCH_FLIP`

x86:

- validator copies the body BPF instructions into params (`kernel/bpf/jit_validators.c:1479-1510`)
- release path frees those copied arrays (`kernel/bpf/jit_directives.c:263-276`)
- emitter: `emit_canonical_branch_flip()` (`arch/x86/net/bpf_jit_comp.c:2979-3050`)
- body sizing is done up front with `measure_branch_flip_body()` (`2912-2932`)
- body emission uses `emit_branch_flip_body()` / `emit_linear_bpf_insn()` (`2934-2947`, `2844-2910`)
- internal jumps are only `emit_local_cond_jump()` and `emit_local_jump()` (`2949-2977`)
- those local offsets depend only on `body_a_size` and `body_b_size`, not on the surrounding program's PC

Validator constraints matter here:

- body A and body B must be linearized subsets with no calls, stores, or nested control flow (`1354-1387`, `1446-1448`)

Verdict:

- pre-encoding is feasible
- but not from `canonical_params` alone; it also depends on the x86 linearization helpers, `use_priv_fp`, and the same CPU-feature-dependent choices used by those helpers

#### `ZERO_EXT_ELIDE`

x86:

- emitter: `emit_canonical_zero_ext_elide()` (`2503-2516`)
- reconstructs a synthetic `struct bpf_insn` and re-emits it with `emit_bpf_alu32_insn()` (`2311-2501`)
- no global relocation or current native offset needed

Verdict:

- feasible to precompute
- not params-only in the strict sense, because the emitted bytes still depend on x86 helper lowering choices and `use_priv_fp`

#### `WIDE_MEM`

x86:

- emitter: `emit_canonical_wide_load()` (`2199-2220`)
- helper sequence is fully local (`2057-2167`)
- no current PC dependency

arm64:

- emitter: `emit_canonical_wide_load_arm64()` (`715-771`)
- no global relocation
- but `arm64_resolve_mem_base()` uses `ctx->priv_sp_used` and `ctx->stack_size` for FP-based accesses (`602-617`)

Verdict:

- precompute is feasible
- arm64 needs a small environment object, or an earlier normalization pass that resolves FP-based addressing before byte generation

#### `ROTATE`, `ADDR_CALC`, `BITFIELD_EXTRACT`, `ENDIAN_FUSION`

These are all local register/immediate/memory-addressing transforms:

- x86 `ROTATE`: `2222-2285`
- x86 `ADDR_CALC`: `2287-2309`
- x86 `BITFIELD_EXTRACT`: `3076-3118`
- x86 `ENDIAN_FUSION`: `2553-2575`
- arm64 `ROTATE`: `689-713`
- arm64 `BITFIELD_EXTRACT`: `773-803`

None of them encode branches to external program locations.

Verdict:

- all are feasible to precompute
- x86 still needs `use_priv_fp`
- arm64 versions are straightforward except `WIDE_MEM`

## `addrs[]` / `offset[]` Management

### x86 exact current behavior

`bpf_jit_commit_rule_region()` (`arch/x86/net/bpf_jit_comp.c:3224-3251`) does:

- `region_start = *proglen`
- `ilen = *pprog - temp`
- copy bytes if `image != NULL`
- `*proglen = region_start + ilen`
- for `j = 0 .. consumed - 2`, set `addrs[addrs_idx + j] = region_start`
- set `addrs[addrs_idx + consumed - 1] = *proglen`

So for a rewritten N-insn site:

- the first `N - 1` BPF instruction boundaries collapse to the native start of the site
- the last BPF instruction boundary becomes the native end of the site

That is intentional.

### arm64 exact current behavior

`bpf_jit_apply_prog_rule()` on arm64 (`arch/arm64/net/bpf_jit_comp.c:945-979`) does the same logical collapse:

- `region_start = ctx->idx`
- after emitting the replacement, for `j = 1 .. consumed - 2`, set `ctx->offset[insn_idx + j] = region_start`
- set `ctx->offset[insn_idx + consumed - 1] = ctx->idx`

The first entry for the site was already set by `ctx->offset[i] = ctx->idx` before the hook (`2568`).

### Does convergence depend on all entries being valid?

Yes.

x86:

- conditional jumps use `addrs[i + insn->off] - addrs[i]` (`4211`)
- unconditional jumps use `addrs[i + insn->off] - addrs[i]` or `addrs[i + insn->imm] - addrs[i]` (`4262`, `4267`)
- final image emission asserts `proglen + ilen == addrs[i]` (`4383-4385`)
- `bpf_prog_update_insn_ptrs()` and `bpf_prog_fill_jited_linfo()` consume the completed array later (`5555`, `5576`, `5605-5606`)

arm64:

- branch offsets are derived from `ctx->offset[]` by `bpf2a64_offset()` (`262-273`)
- final linfo / insn pointer updates consume the completed array (`2931-2940`, `2986-2987`)

So a precompute-inject path must preserve the same collapsed-boundary semantics, not just the final site length.

### Are there any lookups for instructions inside a site?

Yes, in principle external jumps could target any BPF instruction index. That is why `bpf_jit_has_interior_edge()` exists (`kernel/bpf/jit_validators.c:140-200`).

The current design is only correct because validation rejects jumps from outside the site to strict interior targets (`1724-1728`).

Therefore the correct fill policy when skipping `N` BPF insns is:

- x86: keep `addrs[site_start .. site_start + N - 2]` collapsed to the native start and `addrs[last]` at the native end
- arm64: same with `ctx->offset[]`

Any other fill policy would break branch targets, linfo, or both.

## Precise Current Line Counts

### Direct loop-local counts

These are the lines physically inside the main per-insn loops.

| Scope | Exact lines |
| --- | ---: |
| x86 `do_jit()` total | 1112 |
| x86 direct recompile lines in `do_jit()` | 15 |
| arm64 `build_body()` total | 48 |
| arm64 direct recompile lines in `build_body()` | 11 |

Breakdown:

- x86 direct 15 lines = `3295`, `3299`, `3378-3390`
- arm64 direct 11 lines = `2551-2552`, `2569-2577`

This is the clearest reason the proposed refactor does not buy much inside the main loops.

### Helper glue around the loop

| Function cluster | Exact lines |
| --- | ---: |
| x86 lookup/dispatch/commit/apply helper glue | 156 |
| arm64 lookup/dispatch/apply helper glue | 81 |

x86 breakdown:

- `bpf_jit_rule_lookup_prog()` `3120-3134`: 15
- `bpf_jit_try_emit_rule()` `3144-3206`: 63
- `bpf_jit_try_emit_prog_rule()` `3208-3222`: 15
- `bpf_jit_commit_rule_region()` `3224-3251`: 28
- `bpf_jit_apply_prog_rule()` `3253-3287`: 35

arm64 breakdown:

- `bpf_jit_rule_lookup_prog()` `897-911`: 15
- `bpf_jit_try_emit_rule()` `913-943`: 31
- `bpf_jit_apply_prog_rule()` `945-979`: 35

### Canonical emitter bodies currently present

| Scope | Exact lines |
| --- | ---: |
| x86 listed canonical emitters and branch-flip local helpers | 399 |
| arm64 listed canonical emitters | 204 |

x86 counted functions:

- `emit_canonical_select()`: 89
- `emit_canonical_wide_load()`: 22
- `emit_canonical_rotate()`: 64
- `emit_canonical_lea_fusion()`: 23
- `emit_canonical_zero_ext_elide()`: 14
- `emit_canonical_endian_fusion()`: 23
- `measure_branch_flip_body()`: 21
- `emit_branch_flip_body()`: 14
- `emit_local_cond_jump()`: 14
- `emit_local_jump()`: 14
- `emit_canonical_branch_flip()`: 72
- `emit_canonical_bitfield_extract()`: 43

arm64 counted functions:

- `emit_canonical_rotate_arm64()`: 25
- `emit_canonical_wide_load_arm64()`: 57
- `emit_canonical_bitfield_extract_arm64()`: 31
- `emit_canonical_select_arm64()`: 91

### Extra x86 helper code that the emitters already depend on

This matters because moving emitters to a new file is not just "move eight functions".

`ZERO_EXT_ELIDE` and `BRANCH_FLIP` already depend on another **523 exact lines** of x86-only helper code:

- `emit_bpf_alu32_insn()`: 191
- `emit_bpf_end_insn()`: 67
- `emit_bpf_alu64_insn()`: 198
- `emit_linear_bpf_insn()`: 67

Those helpers are not used by the main stock `do_jit()` path; they exist only for recompile-side re-emission.

### File-local move candidates

If the goal is only "shrink `bpf_jit_comp.c` by moving recompile-side code elsewhere", the exact move-candidate totals are:

| File | Exact move-candidate lines |
| --- | ---: |
| x86 recompile-only helper/emitter/dispatch functions | 1412 |
| arm64 recompile-only helper/emitter/dispatch functions | 597 |

Those are **file-local** counts only. They are not real whole-tree savings, because the code would mostly be moved, not deleted.

### Commit / abort lifecycle code

Explicit lifecycle entrypoints in `bpf_jit_comp.c`:

| Function | Exact lines |
| --- | ---: |
| x86 `bpf_jit_recompile_commit()` | 28 |
| x86 `bpf_jit_recompile_abort()` | 22 |
| arm64 `bpf_jit_recompile_commit()` | 26 |
| arm64 `bpf_jit_recompile_abort()` | 22 |

Totals:

- x86 explicit commit/abort lifecycle: 50 lines
- arm64 explicit commit/abort lifecycle: 48 lines

These can stay where they are.

## Proposed Line Counts

Only the current code can be counted precisely. The proposed counts below are estimates.

### Minimal-change version

If the goal is to keep the current architecture and only replace "emit on demand" with "lookup precomputed blob":

- x86 `do_jit()` direct hook: stays effectively **15 lines**
- arm64 `build_body()` direct hook: stays effectively **11 lines**
- x86 helper glue can probably shrink from **156** to roughly **95-110** lines
- arm64 helper glue can probably shrink from **81** to roughly **50-60** lines

Why the savings are small:

- the direct loop hooks already exist
- the addrs/offset collapse helpers still have to exist
- the actual emitter logic still has to exist somewhere

### Whole-tree net savings

Whole-tree savings are likely **near zero or slightly negative**.

Reason:

- the current emitters already encode fixed local byte sequences
- the new design adds precompute storage, blob lifetime management, and precompute dispatch
- moving emitters to `bpf_jit_recompile.c` mostly relocates code instead of deleting it

My estimate:

- likely `bpf_jit_comp.c` shrinks materially if you split files
- likely total code size grows modestly because of blob storage and precompute lifetime code

## Alternative Approaches

| Approach | Avoids full JIT rerun? | Generality | Risk | Verdict |
| --- | --- | --- | --- | --- |
| Keep current rerun model, precompute rule blobs, inject via existing hooks | No | Full | Low | Best option |
| Patch same-size sites in place with `text_poke` / arch text patching | Sometimes | Low | Medium | Only useful for equal-size replacements |
| General post-JIT binary patcher with relocation | Yes | High | Very high | Not attractive here |
| Reserve max-size windows in stock JIT, patch later | Sometimes | Medium | High | Much more invasive than current design |

### Could we avoid re-running `do_jit()` entirely?

Not realistically for the general case.

Why:

- x86 calls encode relative displacements from `image + addrs[i - 1]` (`4104-4119`)
- x86 jumps encode displacements from `addrs[]` (`4211`, `4262`, `4267`)
- arm64 chooses direct vs indirect call based on `ctx->ro_image` and current instruction index (`221-260`)
- exception-table entries point to exact emitted instruction locations (`3835-3887`, `3964-4005`, arm64 `2379-2381`, `2451-2453`, `2511-2536`)
- linfo and insn pointer updates consume the final offset arrays

So any size-changing post-JIT patch would need relocation metadata for:

- jumps
- helper calls
- subprog calls
- exception tables
- linfo / insn pointer mappings

That is more invasive than just keeping the current staged full-image rebuild.

### Could we use `text_poke`?

Only for a much narrower problem:

- same-size in-place patches
- possibly smaller patches if the site already has reserved slack

For the current rewrite forms, site size often changes, and later code addresses move. `text_poke` does not solve the relocation problem by itself.

## Risk Assessment

### 1. Strict params-only purity is false today

If you precompute from `canonical_params` alone, some sites will be wrong:

- x86 FP-mapped sites need `use_priv_fp`
- arm64 FP-based `WIDE_MEM` needs `priv_sp_used` and `stack_size`

Fallback:

- add a tiny arch env to the precompute API
- or normalize FP-based params into resolved arch registers/adjusted offsets before byte generation

### 2. Per-image caching is safer than policy-global caching

The policy is attached to the main program and indexed by absolute `site_start` (`include/linux/bpf_jit_directives.h:145-150`, lookup helpers on both arches).

For multi-function programs:

- `bpf_jit_rule_lookup_prog()` adds `subprog_start` before lookup (`x86 3130-3133`, `arm64 907-910`)
- arm64 `WIDE_MEM` can depend on the current image's stack size

So blobs should live with arch JIT state (`jit_data`) or another per-image cache, not be written back into the shared validated policy.

### 3. Preserve exact collapsed-boundary semantics

If the new path fills interior `addrs[]` / `offset[]` entries differently, you will break:

- external jumps to site entry
- linfo monotonicity assumptions
- `bpf_prog_update_insn_ptrs()`

This is the easiest place to introduce a subtle bug.

### 4. `BRANCH_FLIP` must not split measure and emit semantics

Today local branch sizes are derived by measuring with the same emission helpers used for the real body (`2912-3049`).

If you introduce separate "length estimator" and "emitter" code paths, they can drift. The safe version is:

- emit once into a scratch buffer
- use the resulting length directly

### 5. Exception tables are fine today only because the validators already keep them out

Current matched forms do not route through the probe-memory / probe-atomic emission paths that allocate extable entries.

That is why a pure-byte blob is enough today.

If a future form rewrites any `BPF_PROBE_*` site, the precompute path would need:

- extable metadata production
- or a hard validator rejection

### 6. Multi-function recompiles still need the generic two-stage orchestration

Even with precomputed rule blobs, the generic recompile flow still needs:

- first staged compile
- subprog target rewrite
- final compile

That does not go away.

## Minimal `bpf_jit_comp.c` Diff

If the objective is minimal churn, the best path is:

1. Keep `do_jit()` and `build_body()` hooks structurally unchanged.
2. Keep `bpf_jit_commit_rule_region()` / arm64 offset-collapse logic.
3. Add a per-image precompute cache after private-stack decisions are finalized.
4. Replace the current emit-on-demand dispatcher with a lookup-and-copy dispatcher.
5. Leave commit/abort and the generic `jit_directives.c` orchestration alone.

That means:

- no need to move commit/abort out of `bpf_jit_comp.c`
- no need to rewrite convergence logic
- no need to rewrite exception-table generation outside the replaced sites

Only after that works would I split x86 emitter code into `arch/x86/net/bpf_jit_recompile.c`.

## Concrete Implementation Plan

### Recommended plan

1. Add a per-image precompute blob table owned by the arch JIT state.
2. Build that table inside each arch JIT compile path, after private-stack decisions are known:
   - x86: after `priv_stack_ptr` / `use_priv_fp` is fixed
   - arm64: after `ctx.stack_size` / `ctx.priv_sp_used` is known
3. Keep the current validated `canonical_params` unchanged.
4. Extend the emitter API to take:
   - `canonical_params`
   - small arch env
   - output buffer
5. On x86, preserve current `bpf_jit_commit_rule_region()` semantics exactly.
6. On arm64, preserve current `ctx->offset[]` collapse semantics exactly.
7. Free the precompute blobs with the same lifetime as staged JIT state:
   - successful commit
   - abort
   - error unwind

### Fallback for the strict params-only design

If the goal is truly "params-only", the fallback is to add a normalization stage before byte generation:

- x86: resolve BPF registers to final arch registers using `use_priv_fp`
- arm64 `WIDE_MEM`: resolve FP-based base register and adjusted offset using `priv_sp_used` and `stack_size`

That turns the pure generator input into "fully normalized arch params", not raw `canonical_params`.

## Final Answer

Feasible overall: **yes, with caveats**.

Feasible exactly as proposed in step 1: **no**.

The right version is:

- precompute native override blobs per image
- keep the current top-of-loop inject hooks
- keep the current `addrs[]` / `offset[]` collapse logic
- keep commit/abort and generic orchestration where they are

The main benefit is architectural separation, not meaningful simplification of `do_jit()` / `build_body()` or whole-tree line-count reduction.
