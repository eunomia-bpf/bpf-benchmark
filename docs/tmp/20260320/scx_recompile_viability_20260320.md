# scx struct_ops Recompile Viability Check

Date: 2026-03-20

Task: scx struct_ops recompile viability after `#263`

## Bottom Line

Live `scx` / `sched_ext` `struct_ops` recompile is still **not** supported in the current tree.

- `kernel/bpf/jit_directives.c` still has an explicit `-EOPNOTSUPP` guard for live associated `STRUCT_OPS` programs (`vendor/linux-framework/kernel/bpf/jit_directives.c:284-290`, `:637-642`).
- That guard is still justified. `#263` added trampoline regeneration for the generic `struct bpf_trampoline` infrastructure, but `struct_ops` trampolines are built and stored through a separate `bpf_struct_ops_map` path and are not touched by `bpf_prog_regenerate_trampolines()`.
- For the paper, this is probably **not worth pursuing now**. `scx_rusty` has `28` sites total from `#76`, but `27` are `CMOV` and default recompile policy skips `CMOV`; the only non-CMOV site is a single `LEA` in `rusty_init`, which I infer is cold / init-only rather than a steady-state hot path.

## 1. Current Recompile Entry Point

The explicit block is still present.

- `bpf_jit_recompile_has_trampoline_dependency()` returns true only for:
  - `prog->type == BPF_PROG_TYPE_STRUCT_OPS`
  - and `prog->aux->st_ops_assoc != NULL`
- `bpf_prog_jit_recompile()` then logs:
  - `live struct_ops programs are not supported: trampoline regeneration does not cover struct_ops yet`
  - and returns `-EOPNOTSUPP`

Source:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:284-290`
- `vendor/linux-framework/kernel/bpf/jit_directives.c:637-642`

This matches the earlier `#109` / `#117` conclusion: the stale x86 extable bug was fixed, but live attached `struct_ops` still needed trampoline refresh support.

## 2. What `#263` Actually Added

`#263` did add a new post-commit refresh hook:

- recompile commits the new image
- then calls `bpf_prog_regenerate_trampolines(prog, old_prog_func)`
- then does `synchronize_rcu()`

Source:

- `vendor/linux-framework/kernel/bpf/jit_directives.c:469-505`

The `#263` report describes the new coverage as:

- attached tracing programs (`fentry` / `fexit` / `LSM`)
- target-side trampoline retargeting
- freplace target repoke
- attached freplace retargeting

Source:

- `docs/tmp/trampoline_regen_rotate_fix_20260319.md:25-35`

That list does **not** include `struct_ops`, and the code agrees.

## 3. Why `bpf_prog_regenerate_trampolines()` Does Not Cover struct_ops

`bpf_prog_regenerate_trampolines()` only walks the generic trampoline hash table:

- `trampoline_key_table[]`
- entries of type `struct bpf_trampoline`

It collects matches by scanning those tables, then does one of:

- extension repoke
- target retarget
- `bpf_trampoline_update(tr, ...)`

Source:

- `vendor/linux-framework/kernel/bpf/trampoline.c:850-965`

This is the wrong object model for `struct_ops`.

### struct_ops uses a separate attachment path

`struct_ops` does not create or register a `struct bpf_trampoline` in the generic trampoline tables.
Instead:

- each live `struct_ops` map owns:
  - `links`
  - `ksyms`
  - `image_pages`
- the callable function pointer installed into the subsystem struct comes from those map-owned images

Source:

- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:24-56`

During map registration:

- `bpf_struct_ops_map_update_elem()` associates each BPF program with `prog->aux->st_ops_assoc`
- allocates a `struct bpf_tramp_link`
- calls `bpf_struct_ops_prepare_trampoline(...)`
- stores the resulting stub address into `kvalue.data + member_offset`

Source:

- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:686-858`

And `bpf_struct_ops_prepare_trampoline()` directly calls:

- `arch_prepare_bpf_trampoline(NULL, image + image_off, ...)`

using transient `bpf_tramp_links`, not a persistent `struct bpf_trampoline`.

Source:

- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:597-640`

So the generic refresh path has no handle to:

- find these images
- rebuild them
- patch the live function pointer in `st_map->kvalue.data`
- retire the old image pages

### x86 struct_ops trampolines still bake in `prog->bpf_func`

The x86 trampoline emitter still emits a call to the linked program's current `p->bpf_func` when the image is built:

- `emit_rsb_call(&prog, p->bpf_func, ...)`

Source:

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4878-4885`

That means a live `struct_ops` trampoline built before recompile still points at the old JIT body unless it is rebuilt.

## 4. Does `bpf_trampoline_update()` Work for struct_ops?

No, not as-is.

`bpf_trampoline_update()` operates on `struct bpf_trampoline` objects managed by the generic trampoline subsystem.
`struct_ops` does not keep its live stubs in that subsystem; it keeps raw image pages in `struct bpf_struct_ops_map`.

So simply removing the guard would not make live `struct_ops` safe:

- the program body would get a new `prog->bpf_func`
- the live `sched_ext_ops` function pointer would still point to the old struct_ops trampoline image
- that old image would still call the old `p->bpf_func` baked into it

This is exactly why the current guard message is still accurate.

## 5. What Is Still Missing

The missing piece is a **struct_ops-specific trampoline regeneration / republish path**, not a one-line unblock.

At minimum, a safe implementation would need to:

1. Find the associated live `bpf_struct_ops_map` from `prog->aux->st_ops_assoc`.
2. Identify the affected member from `prog->expected_attach_type`.
3. Rebuild the corresponding struct_ops trampoline image using the same `bpf_struct_ops_prepare_trampoline()` path.
4. Publish the new function pointer into the live `st_map->kvalue.data` entry used by the subsystem.
5. Protect / register the new image and retire the old image with struct_ops-appropriate lifetime handling.

There is already evidence that `struct_ops` needs its own image-retirement logic: map teardown waits with `synchronize_rcu_mult(call_rcu, call_rcu_tasks)` before freeing trampoline images.

Source:

- `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c:1000-1017`

That is stronger than the generic recompile path's plain `synchronize_rcu()`, and suggests the eventual fix should be designed on top of the `struct_ops` image model, not by pretending it is an ordinary `bpf_trampoline`.

## 6. scx-specific Extra Constraint

`sched_ext` already exposes a `struct_ops` map-update callback, but it explicitly rejects live scheduler updates:

- `bpf_scx_update()` returns `-EOPNOTSUPP`

Source:

- `vendor/linux-framework/kernel/sched/ext.c:5428-5437`

This does **not** prove that in-place recompile is impossible, but it does show there is no existing subsystem-supported live-update primitive to reuse for active scx schedulers.

Inference:

- Even after adding struct_ops-specific trampoline regeneration, scx live recompile would still need a clear safety story for updating the active scheduler's callback pointers in place.

## 7. Recompile-Eligible Sites in scx_rusty

From `#76`, the live `scx_rusty` programs have:

- total sites: `28`
- `CMOV`: `27`
- `LEA`: `1`

Breakdown:

- `rusty_enqueue`: `12` CMOV
- `rusty_stopping`: `10` CMOV
- `rusty_set_cpumask`: `2` CMOV
- `rusty_runnable`: `1` CMOV
- `rusty_quiescent`: `1` CMOV
- `rusty_init_task`: `1` CMOV
- `rusty_init`: `1` LEA

Source:

- `docs/kernel-jit-optimization-plan.md:650`

### If CMOV is skipped by policy

The scanner's default `enumerate --recompile` cost model skips `CMOV` by default.

Source:

- `scanner/README.md:137-146`
- `scanner/src/cli.cpp:130-145`
- `scanner/src/cli.cpp:607-614`

So with default policy behavior, the only remaining non-CMOV site is:

- `1` `LEA` site in `rusty_init`

Inference:

- `rusty_init` is an initialization callback, so this lone `LEA` site is unlikely to move steady-state `hackbench` / `stress-ng` / `sysbench` results in a meaningful way.

## 8. Is It Worth Doing for the Paper?

Probably not.

Why:

1. The engineering cost is not small.
   This needs real `struct_ops`-specific regeneration and image-lifetime work, not just deleting a guard.

2. The likely paper payoff is small under the current policy.
   With default policy, `CMOV` is skipped, leaving only one `LEA` site.

3. The one non-CMOV site is probably cold.
   It is in `rusty_init`, not in `enqueue` / `dispatch` / other steady-state callbacks.

4. Even the current E2E harness would need follow-up work.
   `e2e/cases/scx/case.py` calls `apply_recompile(prog_ids, scanner_binary)`, but `apply_recompile()` now treats "no policy + no blind_apply" as stock/no-op, so the harness would not actually request a recompile unless it is given a policy or changed to blind apply.

Source:

- `e2e/cases/scx/case.py:765-773`
- `e2e/common/recompile.py:370-405`

My recommendation:

- Do **not** spend paper-critical time on live scx recompile right now.
- Keep scx as:
  - a real non-networking `struct_ops` deployment story
  - a site census data point
  - a clear statement of current limitation

If scx is revisited later, it should be for completeness / future work, not because it looks like a high-payoff evaluation target under the present policy assumptions.

## Final Answer

Can `struct_ops` recompile work now?

- For live attached scx `struct_ops`: **No**.
- For unattached / not-yet-associated `struct_ops`: probably yes in principle, because the current guard only blocks live associated programs. But that is not the scx E2E case.

What code change is needed to unblock it?

- Not a one-line unblock.
- Needed: a new `struct_ops`-specific post-recompile refresh path that rebuilds and republishes map-owned trampoline images, plus safe old-image retirement.
- After that feature exists, the current `-EOPNOTSUPP` guard in `jit_directives.c` could be removed or narrowed.

Is it worth doing for the paper?

- Probably **no**.
- Site count is only `28`, `27` are `CMOV`, default policy skips `CMOV`, and the single non-CMOV site is a likely cold `LEA` in `rusty_init`.
