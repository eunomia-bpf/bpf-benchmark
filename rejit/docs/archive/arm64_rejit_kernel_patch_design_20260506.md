# ARM64 REJIT Kernel Patch Design: Option A Dynamic Grow / Re-layout

Date: 2026-05-06

Scope: design only. This document describes the ARM64 kernel-side patch shape for
multi-subprogram REJIT image growth. It does not modify
`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`.

Primary sources: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2056-2272`
and `docs/tmp/arm64_rejit_failure_root_cause_20260506.md` section C.

Important review note: a local ARM64 grow retry is not enough if the retry
allocates a new executable address for a subprogram whose address has already
been used to patch sibling bpf-to-bpf calls. The implementation must either
keep the subprogram entry address stable, or teach the multi-subprogram final
pass to restart address patching before kallsyms publication. Ignoring this
would replace one `EOPNOTSUPP` with stale direct-call targets.

## A. Current ARM64 JIT Image-Budget Flow

### Code Map

- JIT private state is `struct arm64_jit_data` with only `header`,
  `ro_image`, `ro_header`, and saved `ctx`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2056-2061`.
- Entry locals include candidate pack pointers, private stack state,
  `extra_pass`, `ctx`, `body_idx`, and `exentry_idx`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2063-2080`.
- The function returns early if JIT is not requested:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2081-2082`.
- Constant blinding can replace `prog` with a temporary blinded program:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2084-2093`.
- `prog->aux->jit_data` is allocated once and reused across the
  subprogram preliminary/final pass boundary:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2095-2103`.
- Private stack allocation is done before layout; ownership is stored in
  `prog->aux->priv_stack_ptr`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2104-2120`.

### Control Flow

```text
bpf_int_jit_compile(prog)
  |
  |-- !prog->jit_requested -> return orig_prog
  |
  |-- blind constants, maybe replace prog with tmp
  |
  |-- allocate/reuse arm64_jit_data
  |
  |-- allocate private stack if verifier requested it
  |
  |-- if jit_data->ctx.offset:
  |     EXTRA_PASS_REUSE
  |       ctx = jit_data->ctx
  |       header/ro_header/ro_image = saved pack
  |       image_ptr = RW alias corresponding to saved ro_image
  |       extra_pass = true
  |       prog_size = sizeof(u32) * ctx.idx
  |       goto skip_init_ctx
  |
  |-- else:
  |     FIRST_LAYOUT
  |       zero ctx, allocate ctx.offset
  |       set arena/private-stack fields
  |       pass 1: prologue + body + epilogue + PLT sizing
  |       prog_size = sizeof(u32) * ctx.idx
  |       extable_offset = round_up(prog_size + PLT_TARGET_SIZE, extable_align)
  |       image_size = extable_offset + extable_size
  |       allocate pack
  |       set ctx.image/ctx.ro_image and prog->aux->extable
  |
  |-- skip_init_ctx:
  |     pass 2: compute positions with body writes disabled
  |     pass 3: write final body, epilogue, PLT
  |     validate code and exception-entry count
  |     prog_size = sizeof(u32) * ctx.idx
  |
  |-- if !prog->is_func || extra_pass:
  |     if extra_pass && ctx.idx > jit_data->ctx.idx:
  |       fail image-budget invariant
  |     finalize pack, flush icache
  |   else:
  |     save ctx and pack into jit_data for later extra_pass
  |
  |-- publish prog->bpf_func/prog->jited/prog->jited_len
  |
  |-- if final program or extra_pass:
  |     scale ctx.offset to bytes
  |     fill jited line info
  |     update instruction pointers
  |     free ctx.offset and jit_data
  |
  `-- return prog
```

### State Transitions

| State | Entry Condition | Owned State | Exit |
|---|---|---|---|
| `NO_JIT` | `!prog->jit_requested` at `bpf_jit_comp.c:2081-2082` | none | return original program |
| `BLINDED_TMP` | `bpf_jit_blind_constants()` returns a different program at `bpf_jit_comp.c:2090-2093` | temporary blinded `prog` | release the other program at `bpf_jit_comp.c:2302-2305` |
| `JIT_DATA_NEW` | `prog->aux->jit_data == NULL` at `bpf_jit_comp.c:2095-2103` | empty `arm64_jit_data` | either store first-pass pack or free on final cleanup |
| `FIRST_LAYOUT` | `jit_data->ctx.offset == NULL` | `ctx.offset`, maybe private stack | allocate image pack at `bpf_jit_comp.c:2170-2177` |
| `EXTRA_PASS_REUSE` | `jit_data->ctx.offset != NULL` at `bpf_jit_comp.c:2121-2130` | saved first-pass pack and offsets | reuse old budget; no new allocation |
| `FINALIZABLE` | `!prog->is_func || extra_pass` at `bpf_jit_comp.c:2242` | candidate pack has final body/PLT/extable | growth check, finalize, icache flush |
| `SAVE_FOR_EXTRA_PASS` | `prog->is_func && !extra_pass` at `bpf_jit_comp.c:2267-2272` | unfinalized pack saved in `jit_data` | later `jit_subprogs()` final pass |
| `PUBLISHED` | after finalization or save | `prog->bpf_func`, `jited`, `jited_len` set at `bpf_jit_comp.c:2274-2276` | metadata fill and cleanup if final |
| `BAILOUT` | growth guard trips at `bpf_jit_comp.c:2247-2253` | old candidate pack still allocated | set non-jited state, free pack, free `jit_data` |

### Initial Image Allocation

The first image allocation happens only on the non-reuse path. ARM64 first runs
a sizing pass with no writable image, then computes:

- `prog_size = sizeof(u32) * ctx.idx`
  at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2170-2171`.
- `extable_offset = round_up(prog_size + PLT_TARGET_SIZE, extable_align)`
  at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2172-2173`.
- `image_size = extable_offset + extable_size`
  at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2174`.
- `bpf_jit_binary_pack_alloc(...)`
  at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2175-2177`.

There is no dynamic slack. The allocation budget is the sizing-pass `ctx.idx`.

### Extra Pass Reuse

When `jit_data->ctx.offset` is present, ARM64 does not rerun sizing and does not
allocate a new image:

- It copies `ctx = jit_data->ctx`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2121-2122`.
- It reloads `ro_image`, `ro_header`, and `header`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2123-2125`.
- It derives the RW image alias from the saved RO/RW pack offset:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2126-2127`.
- It sets `extra_pass = true`, computes `prog_size` from the old `ctx.idx`,
  and jumps to `skip_init_ctx`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2128-2130`.

That old `ctx.idx` is treated as the immutable final-pass budget.

### Final Growth Check

The final write path resets `ctx.idx`, rebuilds prologue/body/epilogue/PLT, then
validates:

- reset/write setup: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2196-2200`
- pass 2 body positioning: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2201-2217`
- pass 3 final body write: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2219-2227`
- validation: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2229-2233`
- real final `prog_size`: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2235-2236`

The current bailout is:

```c
if (extra_pass && ctx.idx > jit_data->ctx.idx) {
        pr_err_once("multi-func JIT bug %d > %d\n",
                    ctx.idx, jit_data->ctx.idx);
        prog->bpf_func = NULL;
        prog->jited = 0;
        prog->jited_len = 0;
        goto out_free_hdr;
}
```

Source: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2247-2253`.

The guard is in the finalizable branch only:
`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2242-2267`.

### Bailout State

After growth bailout:

- `prog->bpf_func = NULL`, `prog->jited = 0`, and `prog->jited_len = 0`
  are set before any finalize call:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2250-2252`.
- `out_free_hdr` copies header size into the RO header and frees the pack:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2308-2314`.
- `out_off` frees `ctx.offset`, frees `jit_data`, and clears
  `prog->aux->jit_data` for final programs or extra passes:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2278-2301`.
- In `jit_subprogs()`, a subprogram whose final JIT failed becomes
  `!func[i]->jited`, producing `-ENOTSUPP`:
  `vendor/linux-framework/kernel/bpf/verifier.c:23276-23282`.
- In `BPF_PROG_REJIT`, a non-jited temporary program becomes `-EOPNOTSUPP`:
  `vendor/linux-framework/kernel/bpf/syscall.c:3784-3786`.

## B. Option A Patch Design

### Target Behavior

When final pass emits `ctx.idx > allocated_budget_idx`, ARM64 should not
immediately publish failure. It should:

1. Record the observed final instruction count.
2. Compute a larger budget with deterministic slack.
3. Discard the stale candidate pack exactly once.
4. Rebuild the final image against a fresh pack.
5. Recompute all address-dependent metadata.
6. Retry a bounded number of times.
7. Publish either a fully finalized image or the same clean non-jited failure
   state that the current bailout publishes.

The patch must preserve the existing safety property: never write past the
currently allocated pack and never publish partial metadata.

### Data Structure Changes

Add budget and retry accounting to `struct arm64_jit_data`:

```c
struct arm64_jit_data {
        struct bpf_binary_header *header;
        struct bpf_binary_header *ro_header;
        u8 *ro_image;
        struct jit_ctx ctx;
        u32 budget_idx;   /* allocated instruction-word budget */
        u32 attempts;     /* grow/re-layout attempts in this JIT session */
};
```

Semantics:

- `ctx.idx` remains the actual instruction count from the latest completed
  layout.
- `budget_idx` is the number of AArch64 instruction slots allocated for code.
  `image_size` is derived from `budget_idx`, not from stale `ctx.idx`, on retry.
- `attempts` counts only grow retries, not normal ARM64 pass 1/pass 2/pass 3.
- On first allocation, initialize `budget_idx = ctx.idx`.
- On retry, set `budget_idx = max(ctx.idx + arm64_jit_growth_slack(ctx.idx),
  old_budget_idx + ARM64_JIT_MIN_GROW_SLACK)`.

Suggested constants:

```c
#define ARM64_JIT_MAX_GROW_RETRIES 3
#define ARM64_JIT_MIN_GROW_SLACK 32    /* AArch64 instructions, 128 bytes */
#define ARM64_JIT_MAX_GROW_SLACK 1024  /* AArch64 instructions, 4 KiB */
```

### Slack Heuristic

Use instruction counts, not bytes:

```c
static u32 arm64_jit_growth_slack(u32 idx)
{
        u32 pct = DIV_ROUND_UP(idx, 16); /* 6.25% */
        u32 slack = clamp_t(u32, pct,
                            ARM64_JIT_MIN_GROW_SLACK,
                            ARM64_JIT_MAX_GROW_SLACK);

        return round_up(slack, 16);
}
```

New budget:

```c
new_budget = max(ctx.idx + arm64_jit_growth_slack(ctx.idx),
                 budget_idx + ARM64_JIT_MIN_GROW_SLACK);
new_budget = round_up(new_budget, 16);
```

Rationale:

- `ctx.idx` after final write is the observed lower bound.
- 32 instructions covers one-off PLT alignment changes and small direct/indirect
  call representation shifts.
- 6.25% keeps large-program retries rare without making normal images much
  larger.
- 1024 instructions caps waste to 4 KiB per retry for very large programs.
- The retry cap handles unstable sizing if a fresh allocation changes call
  distance decisions again.

### Image Size From Budget

The current image-size calculation uses `prog_size = sizeof(u32) * ctx.idx`.
The retry path must instead derive the allocation from `budget_idx`:

```c
prog_size_budget = sizeof(u32) * budget_idx;
extable_offset = round_up(prog_size_budget + PLT_TARGET_SIZE, extable_align);
image_size = extable_offset + extable_size;
```

The published `prog->jited_len` must still use actual final `ctx.idx`, not
`budget_idx`.

### Retry Timing

Detect growth after final body/epilogue/PLT build and `validate_ctx()`, but
before:

- `bpf_jit_dump()`
- `bpf_jit_binary_pack_finalize()`
- `bpf_flush_icache()`
- `prog->bpf_func`, `prog->jited`, or `prog->jited_len` publication
- line-info fill
- instruction-pointer update
- kallsyms publication by `jit_subprogs()`

The current code dumps before the growth guard:
`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2238-2240`.
Option A should move the dump after the retry decision, or include an attempt
number and only dump successful final attempts. Dumping a known discarded image
is misleading.

### Old Pack Freeing

Safe freeing rules:

1. Never call `bpf_jit_binary_pack_free()` twice for the same `(ro_header,
   header)` pair.
2. Before freeing an unfinalized pack, copy the RW header size into the RO
   header exactly as the current `out_free_hdr` path does:
   `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2308-2312`.
3. Clear all local and `jit_data` pack pointers immediately after free.
4. Clear `prog->aux->extable` if it points inside the discarded candidate pack.
5. Do not free `ctx.offset` or `prog->aux->priv_stack_ptr` during a grow retry.
   They are still needed for the next attempt.
6. Do not expose a dangling `prog->bpf_func` to a later direct-call patching
   pass. If fresh allocation changes the subprogram entry address, the caller
   must restart sibling call patching before any final image can be considered
   valid.

The simplest local helper is:

```c
static void arm64_jit_pack_free_safe(struct bpf_binary_header **ro_header,
                                     struct bpf_binary_header **header)
{
        if (!*header)
                return;
        bpf_arch_text_copy(&(*ro_header)->size, &(*header)->size,
                           sizeof((*header)->size));
        bpf_jit_binary_pack_free(*ro_header, *header);
        *ro_header = NULL;
        *header = NULL;
}
```

This is pseudocode. The actual patch should avoid double evaluation and should
match kernel style.

### Metadata That Must Be Recomputed

Every retry must rebuild metadata from the fresh `ctx.ro_image` and fresh
budget:

| Metadata | Why it must be recomputed | Source |
|---|---|---|
| PLT alignment and target slot | `build_plt()` may insert an alignment NOP and writes `plt->target` through `ctx->image`; both depend on current `ctx.idx` and current image pointer. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:971-987` |
| `extable_offset` | Exception table is placed after `budget_prog_size + PLT_TARGET_SIZE`, not after old actual size. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2166-2174` |
| `prog->aux->extable` | Exception handlers write relative offsets using the current RO image and table address. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1139-1163`, `2194-2195` |
| Exception entry count | `validate_ctx()` must see all entries emitted for this attempt. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2007-2015` |
| BPF-to-JIT offsets | `build_body()` rewrites `ctx.offset[i]` from current `ctx.idx`. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1956-1990` |
| line-info offsets | `bpf_prog_fill_jited_linfo()` must run once, after final offsets are scaled to bytes. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2281-2285` |
| instruction pointers | `bpf_prog_update_insn_ptrs()` must use final `ctx.ro_image`, not the discarded pack. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2286-2291` |
| private stack pointer | Keep the existing allocation across retry; free only on terminal failure before successful image ownership exists. | `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:2104-2120`, `2293-2295` |
| kallsyms | Subprogram kallsyms are added only after all final JIT passes and lock-ro succeed. Retry must complete before that point. | `vendor/linux-framework/kernel/bpf/verifier.c:23340-23351` |

### Direct-Call Address Coherency

ARM64 call emission depends on the current target address and current
`ctx.ro_image`:

- unknown or unavailable targets emit indirect calls:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:211-219`.
- direct-call range is checked against `&ctx->ro_image[ctx->idx]`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:221-222`.
- `BPF_CALL` uses `bpf_jit_get_func_addr(..., extra_pass, ...)`:
  `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1651-1655`.
- for `BPF_PSEUDO_CALL`, final pass reads callee addresses from
  `prog->aux->func[off]->bpf_func`:
  `vendor/linux-framework/kernel/bpf/core.c:1249-1269`.

`jit_subprogs()` currently treats a changed final subprogram address as a hard
failure:

- it records `old_bpf_func` before the final pass:
  `vendor/linux-framework/kernel/bpf/verifier.c:23320-23322`.
- it rejects if the returned program changed or `bpf_func` changed:
  `vendor/linux-framework/kernel/bpf/verifier.c:23322-23327`.

Therefore the real Option A patch has a required review gate:

- If retry can allocate a different `bpf_func`, `jit_subprogs()` needs a bounded
  "address repatch + final JIT restart" loop before `bpf_prog_lock_ro()` and
  `bpf_prog_kallsyms_add()`.
- If the first implementation intentionally avoids touching `jit_subprogs()`,
  it must fail cleanly when the retry changes `bpf_func`; that version is a safe
  intermediate patch but is not sufficient for real ARM64 multi-subprog corpus
  coverage.

### Full Re-layout Pseudocode

The pseudocode below is intentionally complete enough for review but is not a
drop-in C patch.

```c
struct arm64_jit_data {
        struct bpf_binary_header *header;
        struct bpf_binary_header *ro_header;
        u8 *ro_image;
        struct jit_ctx ctx;
        u32 budget_idx;
        u32 attempts;
};

bpf_int_jit_compile(prog)
{
        orig_prog = prog;
        jit_data = get_or_alloc_jit_data(prog);
        priv_stack_ptr = get_or_alloc_private_stack(prog);
        force_relayout = false;
        requested_budget = 0;

again:
        header = NULL;
        ro_header = NULL;
        image_ptr = NULL;
        ro_image_ptr = NULL;
        extra_pass = false;

        if (jit_data->ctx.offset && !force_relayout) {
                /*
                 * Existing final pass: reuse the first-pass pack.
                 * The allocation budget is budget_idx if present, otherwise
                 * the historical ctx.idx budget.
                 */
                ctx = jit_data->ctx;
                budget_idx = jit_data->budget_idx ?: jit_data->ctx.idx;
                ro_image_ptr = jit_data->ro_image;
                ro_header = jit_data->ro_header;
                header = jit_data->header;
                image_ptr = rw_alias_from_pack(header, ro_header, ro_image_ptr);
                extra_pass = true;
                goto setup_emit_passes;
        }

        if (!jit_data->ctx.offset) {
                /*
                 * First layout for this bpf_prog object.
                 */
                zero(ctx);
                ctx.prog = prog;
                ctx.offset = alloc_offset_array(prog->len + 1);
                init_arena_and_private_stack_fields(&ctx, prog, priv_stack_ptr);

                build_prologue(&ctx, was_classic);
                build_body(&ctx, false);
                ctx.epilogue_offset = ctx.idx;
                build_epilogue(&ctx, was_classic);
                build_plt(&ctx);

                budget_idx = ctx.idx;
                jit_data->budget_idx = budget_idx;
        } else {
                /*
                 * Grow retry: keep structural ctx fields and offset storage,
                 * but allocate a new pack from the requested larger budget.
                 * The final pass remains extra_pass=true because bpf-to-bpf
                 * targets have already been resolved.
                 */
                ctx = jit_data->ctx;
                ctx.image = NULL;
                ctx.ro_image = NULL;
                ctx.idx = 0;
                ctx.exentry_idx = 0;
                ctx.write = false;
                budget_idx = jit_data->budget_idx;
                extra_pass = true;
        }

        image_size = arm64_jit_image_size_from_budget(prog, budget_idx,
                                                      &extable_offset);
        ro_header = bpf_jit_binary_pack_alloc(image_size, &ro_image_ptr,
                                              sizeof(u64), &header, &image_ptr,
                                              jit_fill_hole);
        if (!ro_header)
                goto fail_clean;

setup_emit_passes:
        ctx.image = (__le32 *)image_ptr;
        ctx.ro_image = (__le32 *)ro_image_ptr;
        if (extable_size)
                prog->aux->extable = (void *)ro_image_ptr + extable_offset;

        ctx.idx = 0;
        ctx.exentry_idx = 0;
        ctx.write = true;

        build_prologue(&ctx, was_classic);
        exentry_idx = ctx.exentry_idx;
        body_idx = ctx.idx;

        ctx.write = false;
        build_body(&ctx, extra_pass);

        ctx.epilogue_offset = ctx.idx;
        ctx.exentry_idx = exentry_idx;
        ctx.idx = body_idx;
        ctx.write = true;

        build_body(&ctx, extra_pass);
        assert(ctx.idx == ctx.epilogue_offset);
        build_epilogue(&ctx, was_classic);
        build_plt(&ctx);
        validate_ctx(&ctx);

        actual_idx = ctx.idx;

        if (extra_pass && actual_idx > budget_idx) {
                new_budget = arm64_jit_next_budget(budget_idx, actual_idx);

                if (++jit_data->attempts > ARM64_JIT_MAX_GROW_RETRIES)
                        goto fail_clean_with_nonjited_publish;

                /*
                 * Detach and free this attempt's pack. Keep ctx.offset and
                 * private stack for the next attempt.
                 */
                if (prog->aux->extable points inside ro_image_ptr)
                        prog->aux->extable = NULL;
                arm64_jit_pack_free_safe(&ro_header, &header);

                jit_data->header = NULL;
                jit_data->ro_header = NULL;
                jit_data->ro_image = NULL;
                jit_data->budget_idx = new_budget;

                force_relayout = true;
                goto again;
        }

        prog_size = sizeof(u32) * actual_idx;

        if (bpf_jit_enable > 1)
                bpf_jit_dump(prog->len, prog_size, attempt_count, ctx.image);

        if (!prog->is_func || extra_pass) {
                finalize_pack_or_fail(ro_header, header);
                bpf_flush_icache(ro_header, ctx.ro_image + actual_idx);
        } else {
                /*
                 * Preliminary subprogram pass. Save unfinalized pack for the
                 * later final pass.
                 */
                jit_data->ctx = ctx;
                jit_data->budget_idx = budget_idx;
                jit_data->ro_image = ro_image_ptr;
                jit_data->header = header;
                jit_data->ro_header = ro_header;
        }

        old_bpf_func = prog->bpf_func;
        prog->bpf_func = (void *)ctx.ro_image + cfi_get_offset();
        prog->jited = 1;
        prog->jited_len = prog_size - cfi_get_offset();

        if (extra_pass && old_bpf_func && old_bpf_func != prog->bpf_func)
                signal_subprog_address_changed_to_caller();

        if (!prog->is_func || extra_pass) {
                scale_offsets_once_to_bytes(ctx.offset);
                bpf_prog_fill_jited_linfo(prog, ctx.offset + 1);
                bpf_prog_update_insn_ptrs(prog, ctx.offset, ctx.ro_image);
                free ctx.offset;
                free jit_data;
                prog->aux->jit_data = NULL;
        }

        return prog;

fail_clean_with_nonjited_publish:
        prog->bpf_func = NULL;
        prog->jited = 0;
        prog->jited_len = 0;

fail_clean:
        if (prog->aux->extable points inside ro_image_ptr)
                prog->aux->extable = NULL;
        arm64_jit_pack_free_safe(&ro_header, &header);
        free ctx.offset if this is final cleanup;
        free private stack only if no successful image owns it;
        free jit_data and clear prog->aux->jit_data;
        return prog_or_orig_prog_consistent_with_current_error_path;
}
```

### Required Multi-subprogram Caller Handling

If the grow retry can change `prog->bpf_func`, the caller-side final pass needs
bounded repatching. The design target is:

```c
jit_subprogs_final_pass(func[])
{
        for (addr_attempt = 0; addr_attempt < MAX_ADDR_REPATCH; addr_attempt++) {
                changed = false;

                patch_all_bpf_call_immediates_from_current_func_addresses(func);

                for_each_subprog(func[i]) {
                        old = func[i]->bpf_func;
                        tmp = bpf_int_jit_compile(func[i]);
                        if (tmp != func[i] || !func[i]->jited)
                                return -ENOTSUPP;
                        if (func[i]->bpf_func != old)
                                changed = true;
                }

                if (!changed)
                        break;

                /*
                 * Any already-finalized candidate image from this address
                 * attempt must be discarded before the next attempt, because
                 * its direct calls may point at old subprogram entries.
                 * Kallsyms has not been published yet.
                 */
                discard_unpublished_final_images_for_next_addr_attempt(func);
        }

        if (changed)
                return -ENOTSUPP;

        lock_ro_and_add_subprog_kallsyms(func);
        publish_main_prog_fields_from_func0();
}
```

This caller-side part is the highest-risk edge in Option A. If it is deferred,
the ARM64 local patch must explicitly document that it handles only same-address
re-layouts and still cleanly rejects address-changing retries.

### Terminal Error Propagation

On retry cap exhaustion, allocation failure, validation failure, or pack
finalize failure:

- free the current candidate pack exactly once;
- clear any `prog->aux->extable` pointer into the discarded pack;
- set `prog->bpf_func = NULL`, `prog->jited = 0`, `prog->jited_len = 0` for
  final `extra_pass` failures;
- free `ctx.offset` and `jit_data` on the final cleanup path;
- free `prog->aux->priv_stack_ptr` only when no successful JIT image owns it;
- return through the existing non-jited failure path so `jit_subprogs()` and
  `BPF_PROG_REJIT` surface the error naturally.

Do not add a fallback to interpreter execution for multi-subprogram final-pass
failure. The current kernel path correctly rejects these cases rather than
silently downgrading.

## C. Risks / Verification Matrix

| risk | trigger condition | mitigation | verification method |
|---|---|---|---|
| old pack double-free | grow retry frees the saved first-pass pack, then existing `out_free_hdr` also sees stale `header` | centralize pack free in `arm64_jit_pack_free_safe()`, set local and `jit_data` pointers to NULL immediately | enable KASAN/KFENCE, force one grow retry, unload program, confirm no double-free report |
| partial metadata publish | retry path sets `bpf_func`, line info, instruction pointers, or kallsyms before final success | perform grow check before finalize and before all publish calls; fill line info and insn ptrs once after success | instrument a forced grow failure and verify `bpftool prog show` never reports the failed tmp as jited |
| kallsyms inconsistency | subprogram address changes after sibling calls or kallsyms names were generated | do not call `bpf_prog_kallsyms_add()` until all retries and address repatching converge | run `test_progs -t ksyms,ksyms_module` and verify `bpf_prog_kallsyms_verify_off()` on free |
| exception-table mis-offset | retry allocates a different `ro_image` or budget but reuses old `prog->aux->extable` | recompute `extable_offset` from `budget_idx`, repoint `prog->aux->extable`, rerun `add_exception_handler()` | run `subprogs_extable`, `jit_probe_mem`, and BPF exception selftests under ARM64 |
| instruction pointer mis-offset | retry reuses `ctx.offset` values from old layout or scales offsets to bytes twice | rebuild body offsets on every attempt; scale to bytes only after final success | compare `bpftool prog dump jited linum` before/after retry; run line-info-enabled selftests |
| private stack lifetime bug | grow retry takes failure label that frees `prog->aux->priv_stack_ptr`, then retries with dangling private stack state | retry labels must skip private-stack free; terminal failure frees only if no image owns it | run `tests/unittest/build-arm64/rejit_private_stack` under KASAN |
| stale bpf-to-bpf direct call | retry changes one subprog entry after earlier subprogs were final-emitted against old addresses | bounded caller-side address repatch/re-finalize, or clean rejection for address-changing retry | construct multi-subprog caller/callee test; disassemble final BL targets and execute test run |
| retry infinite loop | fresh allocation changes RO image distance and direct/indirect call choice every attempt | `ARM64_JIT_MAX_GROW_RETRIES = 3`, deterministic slack, fail non-jited after cap | forced always-grow stress test should return `EOPNOTSUPP` and not hang |

## D. Test Plan

### 1. Existing Kernel and Repo Tests

Run the normal ARM64 test suite first:

```sh
make aws-arm64-test AWS_ARM64_TEST_MODE=selftest
make aws-arm64-test AWS_ARM64_TEST_MODE=test
```

The `test` mode includes the repo's kernel selftest wrapper
`tests/kernel/build/test_recompile` when present:
`runner/suites/test.py:183-192`, and then runs repo unit and negative suites:
`runner/suites/test.py:253-260`.

Run targeted Linux BPF selftests on the patched ARM64 kernel:

```sh
cd vendor/linux-framework/tools/testing/selftests/bpf
./test_progs -t subprogs
./test_progs -t subprogs_extable
./test_progs -t jit_probe_mem
./test_progs -t exceptions
./test_progs -t tailcalls
./test_progs -t ksyms
./test_progs -t ksyms_module
```

Run repo REJIT tests that stress swap, tail calls, private stack, and kinsn:

```sh
tests/unittest/build-arm64/rejit_swap_tests
tests/unittest/build-arm64/rejit_tail_call
tests/unittest/build-arm64/rejit_private_stack
tests/unittest/build-arm64/rejit_kinsn
tests/unittest/build-arm64/rejit_regression
tests/unittest/build-arm64/rejit_hotswap_xdp
```

### 2. Multi-subprogram REJIT: Katran `balancer_ingress`

Run the supported real-app corpus path on ARM64 with Katran only:

```sh
BPFREJIT_CORPUS_APPS=katran make aws-arm64-corpus SAMPLES=1
```

Validation criteria:

- `balancer_ingress` appears in the raw `result.json` program list.
- ReJIT lifecycle status is `ok`, not `EOPNOTSUPP`.
- Kernel log has no `multi-func JIT bug %d > %d` message.
- `bpftool prog dump jited` for Katran programs succeeds after ReJIT.
- If a grow retry happened, debug logs show bounded attempts and final success.

Do not compute benchmark ratios in the framework for this validation. Only
check raw status, raw counters, and kernel/JIT correctness.

### 3. Always-growing Stress

Use a temporary, not-to-be-committed stress hook to force the retry cap:

1. Use a synthetic multi-subprogram BPF program with one caller and one callee.
2. Force `actual_idx > budget_idx` on every retry for that program name, or use
   a throwaway transform that monotonically increases final JIT size.
3. Confirm attempts stop at `ARM64_JIT_MAX_GROW_RETRIES`.
4. Confirm REJIT returns `EOPNOTSUPP`, the kernel does not hang, and
   KASAN/KFENCE report no leak, use-after-free, or double free.
5. Confirm the original live program remains valid after the failed REJIT.

The stress hook must stay out of production code.

### 4. ARM64 KVM Smoke

When an ARM64 KVM runner is available, boot the patched kernel and run:

```sh
uname -m
bpftool prog show
tests/unittest/build-arm64/rejit_hotswap_xdp
tests/unittest/build-arm64/rejit_tail_call
BPFREJIT_CORPUS_APPS=katran make aws-arm64-corpus SAMPLES=1
```

If local ARM64 KVM is unavailable, use `aws-arm64-test` and `aws-arm64-corpus`
as the ARM64 smoke path, keeping the default small instance policy.

## E. LoC and Risk Estimate

ARM64-local grow/re-layout core:

| item | estimated LoC | risk |
|---|---:|---|
| `struct arm64_jit_data` fields and constants | ~5 | low |
| retry loop and labels in `bpf_int_jit_compile()` | ~30 | medium-high |
| helper functions: slack, image-size-from-budget, safe pack free, extable pointer guard | ~30-50 | medium |
| modified callsites for allocation/finalize/dump/cleanup | ~20 | medium |
| comments/documentation in code | ~20 | low |
| total ARM64-local patch | ~80-150 | medium-high |

If the final implementation handles address-changing subprogram retries by
restarting `jit_subprogs()` address patching, add roughly 40-80 LoC and raise
integration risk. That work is required unless retry proves stable entry
addresses.

Primary risk drivers:

- packed text memory ownership;
- final-pass address-dependent layout;
- exception table relative offsets;
- `bpf_func` direct-call coherency across subprograms;
- no partial publication before `BPF_PROG_REJIT` swap.

## F. Alternative Comparison

| option | LoC | risk | applicable scenario |
|---|---:|---|---|
| Option A: dynamic grow / re-layout | 80-150 ARM64-local; +40-80 if caller address restart is needed | M-H | Required for real ARM64 corpus if final-pass growth is expected and must succeed |
| Option B: static slack only | 30-80 | M | Short-term mitigation; works only if slack covers all observed growth |
| Option C: gate multi-subprog off | 5-30 | L | Paper can mark ARM64 multi-subprog REJIT as N/A; no real ARM64 corpus claim |
| Option D: arch hook / unsupported gate | 30-70 | L | Similar to C, but cleaner architecture boundary and clearer error |

Option A is the only path that preserves the ability to claim real ARM64
multi-subprogram corpus coverage. Option B can reduce immediate failures but
does not prove correctness under sizing instability. Options C and D are valid
engineering fallbacks only if ARM64 corpus coverage is explicitly out of scope.
