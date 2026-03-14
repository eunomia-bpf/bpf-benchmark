# Kernel Framework Code Review

Date: 2026-03-13T02:05:20Z

Scope reviewed:
- `git -C vendor/linux-framework diff HEAD`
- `git -C vendor/linux-framework diff --stat HEAD`
- `git -C vendor/linux-framework log --oneline -5`
- `git -C vendor/linux-framework status --short --branch`
- Current-tree build smoke check: `make -C vendor/linux-framework -j4 kernel/bpf/jit_directives.o arch/x86/net/bpf_jit_comp.o kernel/bpf/core.o kernel/bpf/syscall.o`

## Executive Summary

I reviewed 9 tracked modified files plus the new untracked `include/trace/events/bpf.h`.

The current tree builds the touched objects with the checked-in `.config`, but I do **not** think the recompile/rollback path is safe to merge as-is. The biggest problems are:

1. Recompile mutates live JIT state in place without synchronizing against runtime execution.
2. The success path does not free the old JIT image and does not refresh BPF kallsyms, which also breaks exception-table lookup for the new image.
3. Rollback only restores a shallow snapshot and does not own/clean all staged JIT artifacts.
4. The 32-bit masked ROTATE validators still accept arbitrary non-zero masks, so a crafted policy can pass validation and be emitted as a rotate even when the source sequence is not a rotate.
5. The recompile helper now relies on `bpf_int_jit_compile()` as if it were a `NULL`-on-failure API, so a failed extra pass on `func[0]` can be reported as success.

Overall assessment: **not ready for kernel use in current form**.

## Repo State

- Branch: `jit-directive-v5`
- Recent commits:
  - `05a184549 cmov emitter correctness fix`
  - `e52504a75 bpf: add zero-ext, endian, and branch-flip forms`
  - `b5e7bf6cc bpf: add ZERO_EXT_ELIDE and ENDIAN_FUSION canonical forms`
  - `5d99e3842 bpf: v6 tier-1 - remove shape whitelist, add recompile log, raise tuple limits`
  - `a99cd78ed bpf: drop legacy jit directive paths`
- Working tree status:
  - Modified tracked files: 9
  - Untracked file: `include/trace/events/bpf.h`

## File-By-File Summary

| File | Diff (+/-) | Total lines | Review summary |
| --- | ---: | ---: | --- |
| `arch/x86/net/bpf_jit_comp.c` | +10 / -2 | 6524 | Good fail-closed changes for CMOV shape restriction, BMI1/BEXTR restriction, per-rule tracepoints, and private-stack cleanup; surrounding recompile sequencing still has serious correctness problems. |
| `include/linux/bpf.h` | +3 / -0 | 4015 | New `jit_recompile_mutex`, `recompile_count`, and `jit_recompile_num_applied` are internally consistent. |
| `include/linux/bpf_jit_directives.h` | +3 / -0 | 118 | New trace helper declaration is fine. |
| `include/uapi/linux/bpf.h` | +4 / -0 | 7954 | `BPF_F_RECOMPILE_ROLLBACK` and `bpf_prog_info.recompile_count` are append-only ABI additions; no user ABI break found. |
| `include/trace/events/bpf.h` | new, untracked | 85 | Tracepoint definitions look conventional, but the file is not tracked in git, which makes the patch set incomplete. |
| `kernel/bpf/core.c` | +2 / -0 | 3371 | Mutex init/destroy additions are correct. |
| `kernel/bpf/jit_directives.c` | +565 / -81 | 3428 | Most validator hardening is good, but recompile/rollback lifetime and concurrency handling are still unsafe. |
| `kernel/bpf/syscall.c` | +2 / -0 | 6601 | Userspace export of `recompile_count` is correct and uses `main_prog_aux` when present. |
| `tools/bpf/bpftool/prog.c` | +4 / -0 | 2622 | Display support is correct. |
| `tools/include/uapi/linux/bpf.h` | +4 / -0 | 7706 | Tools UAPI mirror is consistent with kernel UAPI. |

## Correctness Analysis

### `kernel/bpf/jit_directives.c`

What looks good:
- The canonical-site validators for `WIDE_MEM`, `ROTATE`, `ADDR_CALC`, `BITFIELD_EXTRACT`, `ZERO_EXT_ELIDE`, `ENDIAN_FUSION`, and `BRANCH_FLIP` now cross-check the extracted canonical params against the actual instruction site and, in most cases, also reject interior control-flow edges.
- `bpf_jit_main_aux()` removes repeated open-coded `main_prog_aux ? : aux` logic.
- The policy parser still validates `arch_id` against `BPF_JIT_ARCH_X86_64` and the UAPI blob length/prog-tag bindings before activation.

What is still wrong:
- The rollback snapshot is too shallow. `struct bpf_jit_recompile_prog_state` saves `bpf_func`, `priv_stack_ptr`, `extable`, `jited_len`, `num_exentries`, `jited`, and `exception_boundary`, but it does **not** snapshot `prog->aux->jit_data`, the staged pack headers, or kallsyms state (`kernel/bpf/jit_directives.c:37`, `kernel/bpf/jit_directives.c:215`, `kernel/bpf/jit_directives.c:244`, `kernel/bpf/jit_directives.c:278`).
- The mutex only serializes recompile syscalls. It does not synchronize with any runtime execution path. Nothing in `bpf_prog_jit_recompile()` blocks readers, regenerates non-struct_ops trampolines, or waits for an RCU grace period before `bpf_int_jit_compile()` starts rewriting live program state (`kernel/bpf/jit_directives.c:3245`, `kernel/bpf/jit_directives.c:3277`).
- `main_aux->bpf_exception_cb` is explicitly cleared and republished during recompile (`kernel/bpf/jit_directives.c:3227`), while `bpf_throw()` dereferences `ctx.aux->bpf_exception_cb` directly on the runtime path (`kernel/bpf/helpers.c:3159`). Without reader synchronization, that creates a direct NULL/stale-function-pointer window.
- `bpf_jit_recompile_prog_images()` reuses the load-time two-pass JIT flow, but it does so on already-live programs and without the load-time cleanup/error checks from the verifier path (`kernel/bpf/jit_directives.c:3163`; compare `kernel/bpf/verifier.c:22925` and `kernel/bpf/verifier.c:22970`).
- `main_aux->recompile_count` is incremented unchecked and will silently wrap after `U32_MAX` successful recompiles (`include/linux/bpf.h:1715`, `kernel/bpf/jit_directives.c:3406`).

Validator-specific notes:
- `COND_SELECT`: still only validates the site shape and interior-edge property; it does **not** validate that the bound canonical params match the actual site (`kernel/bpf/jit_directives.c:633`, `kernel/bpf/jit_directives.c:2423`, `kernel/bpf/jit_directives.c:2541`).
- `ROTATE`: the masked 32-bit forms still accept any non-zero immediate mask, and any `AND_X` mask, which is not sufficient to prove rotate semantics (`kernel/bpf/jit_directives.c:1113`, `kernel/bpf/jit_directives.c:1178`, `kernel/bpf/jit_directives.c:1232`, `kernel/bpf/jit_directives.c:1301`).

### `arch/x86/net/bpf_jit_comp.c`

What looks good:
- `emit_canonical_select()` is now explicitly fail-closed for non-diamond/non-compact COND_SELECT sites (`arch/x86/net/bpf_jit_comp.c:1471`).
- `emit_bitfield_extract_core()` now disables the BMI1/BEXTR fast path for `dst != src`, which avoids the cross-register emission case that was unsafe (`arch/x86/net/bpf_jit_comp.c:3771`).
- Per-rule tracepoint emission is wired in only on the final `image` pass, so it does not double count the size-estimation pass (`arch/x86/net/bpf_jit_comp.c:4172`, `arch/x86/net/bpf_jit_comp.c:4186`).
- The `allocated_priv_stack` fix is correct: it prevents a failed recompile from freeing a pre-existing private stack owned by the live image (`arch/x86/net/bpf_jit_comp.c:6138`, `arch/x86/net/bpf_jit_comp.c:6188`, `arch/x86/net/bpf_jit_comp.c:6334`).

What is still wrong:
- `bpf_int_jit_compile()` can return the same `struct bpf_prog *` while clearing `prog->bpf_func`/`prog->jited` on an extra-pass failure (`arch/x86/net/bpf_jit_comp.c:6229`). The recompile helper no longer detects that for `func[0]`.
- First-pass recompile staging stores new headers in `prog->aux->jit_data` (`arch/x86/net/bpf_jit_comp.c:6299`), but the rollback code in `kernel/bpf/jit_directives.c` does not snapshot or clean that state.

### Headers / Support Files

What looks good:
- `jit_recompile_mutex` is initialized in `bpf_prog_alloc_no_stats()` and destroyed in `__bpf_prog_free()` (`kernel/bpf/core.c:143`, `kernel/bpf/core.c:295`).
- `bpf_prog_info.recompile_count` is appended at the end of the struct in both kernel and tools UAPI, so existing shorter user buffers remain valid through the usual `info_len`/record-size handling (`include/uapi/linux/bpf.h:6949`, `tools/include/uapi/linux/bpf.h:6702`, `kernel/bpf/syscall.c:5042`).
- `bpftool` plain/json display changes are straightforward and correct (`tools/bpf/bpftool/prog.c:444`, `tools/bpf/bpftool/prog.c:531`).

What needs attention:
- `include/trace/events/bpf.h` is not tracked by git even though `kernel/bpf/jit_directives.c` includes it directly.
- I did not do a dedicated `CONFIG_TRACING=n` build, but from `include/linux/tracepoint.h` the `trace_bpf_jit_recompile_*()` sites should stub out cleanly when tracepoints are disabled. The current `.config` build passed.

## Safety Analysis

### Locking / Concurrency

- `jit_recompile_mutex` is sufficient to prevent two recompile syscalls from racing with each other.
- It is **not** sufficient to make recompile safe for live programs. Runtime execution does not take this mutex, and the recompile path rewrites `prog->bpf_func`, subprog call immediates, `prog->aux->extable`, and `main_aux->bpf_exception_cb` in place.
- The special-case rejection for attached `struct_ops` programs (`kernel/bpf/jit_directives.c:3300`) is correct, but it also makes the broader gap obvious: other attached program types are not protected.

### Memory Lifetime / Error Paths

- Old JIT images are not reference-counted and are not freed on successful recompile.
- Rollback restores pointers, not ownership. New staged pack headers and `jit_data` survive failed recompiles in some paths.
- The x86 private-stack fix is good, but it only addresses one field (`priv_stack_ptr`), not the wider staged-JIT lifetime problem.

### Exception Tables

- The direct `prog->aux->extable` pointer update in `bpf_jit_recompile_prog_images()` is not enough by itself (`kernel/bpf/jit_directives.c:3224`).
- `search_bpf_extables()` first maps faulting IPs back to a program via the BPF kallsyms tree (`kernel/bpf/core.c:787`). Because the recompile path never re-registers kallsyms, faults in the new image can miss the program entirely.

### ABI / Userspace

- No ABI break found in the `bpf_prog_info` extension. Kernel and tools headers are mirrored.
- `BPF_F_RECOMPILE_ROLLBACK` is a new flag in a reused `flags` namespace; that is normal for `union bpf_attr`.

### Tracepoints

- The tracepoints are conventional `TRACE_EVENT()` definitions.
- Current-tree object build succeeded.
- Dedicated `CONFIG_TRACING=n` coverage was not built, so that part remains a static review conclusion rather than a build-tested conclusion.

## Requested Specific Checks

| Check | Result |
| --- | --- |
| Rollback restores old JIT image and old policy | **Partial only.** Old pointer fields and `old_policy` are restored, but old/new binary ownership is not tracked, and staged `jit_data` is not restored or freed. |
| `jit_recompile_mutex` initialized before use and destroyed on free | **Yes.** `kernel/bpf/core.c:143` and `kernel/bpf/core.c:295`. |
| Tracepoints compile with `CONFIG_TRACING=n` | **Likely yes by inspection**, not explicitly build-tested. Current `.config` build passed. |
| `recompile_count` overflow handled | **No.** It is a raw `u32` increment. |
| Exception-table pointer update correct after recompile | **No.** The extable pointer is updated, but kallsyms are not, so `search_bpf_extables()` can no longer find the program for the new IP range. |
| Old image reference counting / `bpf_jit_binary_pack_hdr` lifetime correct | **No.** The success path overwrites `prog->bpf_func` without freeing the old pack header. |
| `BPF_F_RECOMPILE_ROLLBACK` with stock re-JIT (`policy_fd = 0`) | **Policy pointer handling is logically correct**, but all of the image lifetime / live-reader safety problems still apply. |

## Issues Found

### Bug

1. Live recompile is not synchronized with runtime execution.
   - `kernel/bpf/jit_directives.c:3277` only serializes recompilers.
   - `arch/x86/net/bpf_jit_comp.c:6322` rewrites `prog->bpf_func` during JIT staging.
   - `kernel/bpf/jit_directives.c:3187` rewrites in-program call targets in place.
   - There is no RCU synchronization, trampoline regeneration (other than the `struct_ops` reject case), or stop-the-world mechanism before the live program image is mutated.

2. The main function's failed extra pass can be misreported as success.
   - The core contract explicitly says `bpf_int_jit_compile()` returns a valid `struct bpf_prog *` even on failure/fallback (`kernel/bpf/core.c:2540`).
   - `arch/x86/net/bpf_jit_comp.c:6229` returns the same `prog` pointer while clearing `prog->bpf_func`/`prog->jited` on extra-pass failure.
   - `kernel/bpf/jit_directives.c:3172` and `kernel/bpf/jit_directives.c:3213` treat pointer equality as success and skip the old-address stability check for `i == 0`.
   - This means `func[0]` can fail its final pass, yet `bpf_jit_recompile_prog_images()` still returns success and propagates `func[0]`'s now-invalid state to the main program.

3. Successful recompile leaks the old JIT image.
   - `kernel/bpf/jit_directives.c:3402` frees only the old policy, not the old binary image.
   - `arch/x86/net/bpf_jit_comp.c:6322` overwrites `prog->bpf_func` with the new image.
   - `arch/x86/net/bpf_jit_comp.c:6392` later frees only the image reachable from the current `prog->bpf_func`.
   - There is no retained handle to the pre-recompile pack header, so old module text remains leaked.

4. Recompile never refreshes BPF kallsyms, which breaks exception-table lookup for the new image.
   - `kernel/bpf/core.c:673` / `kernel/bpf/core.c:703` are the only obvious add/del helpers.
   - No recompile path calls them.
   - `kernel/bpf/core.c:787` uses the BPF kallsyms tree to find the program before consulting `prog->aux->extable`.
   - After recompile, the new image runs at a new address, but the tree still indexes the old one.

5. Rollback is not ownership-complete and leaves staged JIT artifacts behind.
   - `kernel/bpf/jit_directives.c:37` does not snapshot `jit_data`, staged pack headers, or kallsyms state.
   - `arch/x86/net/bpf_jit_comp.c:6299` stores first-pass staging in `prog->aux->jit_data`.
   - `kernel/bpf/jit_directives.c:3377` restores pointer fields but never cleans per-prog `jit_data` on failed multi-subprog recompiles.
   - Result: failed recompiles can leave stale staged images attached to live `struct bpf_prog`s until a later teardown.

6. The masked 32-bit ROTATE validators are still too weak and allow semantic bypass.
   - `kernel/bpf/jit_directives.c:1178` and `kernel/bpf/jit_directives.c:1312` only reject zero immediate masks.
   - Arbitrary non-zero masks are not enough to prove rotate semantics.
   - `arch/x86/net/bpf_jit_comp.c:2679` then emits `ror`/`rorx` purely from the canonical params, so a crafted non-rotate pattern can be miscompiled as a rotate.

### Potential-Issue

1. `COND_SELECT` is now the odd one out: canonical params are validated for type/range, but not against the actual site.
   - `kernel/bpf/jit_directives.c:633` only checks the site shape.
   - `kernel/bpf/jit_directives.c:2423` validates param types/ranges.
   - `kernel/bpf/jit_directives.c:2541` never cross-checks those params with the concrete instructions.
   - Today the x86 emitter re-parses the actual site (`arch/x86/net/bpf_jit_comp.c:1471`), so this is not an immediate x86 miscompile, but the framework can no longer treat `rule->params` as trustworthy for this form.

2. Hidden subprogs are treated inconsistently.
   - `kernel/bpf/jit_directives.c:3170` computes `real_func_cnt`, but the actual compile/update loops still iterate only `main_aux->func_cnt`.
   - `kernel/bpf/jit_directives.c:3228` then scans `real_func_cnt` when repointing `main_aux->bpf_exception_cb`.
   - I did not prove a current runtime failure from this asymmetry, but it deserves either a comment or a test proving that hidden exception-callback subprogs never need the re-JIT/update passes.

3. Branch-flip validation and x86 emission disagree for `BPF_JSET`.
   - `kernel/bpf/jit_directives.c:1984` and `kernel/bpf/jit_directives.c:2491` now accept `BPF_JSET` for `BRANCH_FLIP`.
   - The x86 branch-flip emitter still depends on `bpf_jmp_invert()`, which does not handle `BPF_JSET` (`arch/x86/net/bpf_jit_comp.c:1127`, `arch/x86/net/bpf_jit_comp.c:3552`).
   - Result: such rules can validate and become active, but will always fall back during JIT emission.

### Style

1. The trace-events header is currently untracked.
   - `git status` reports `?? include/trace/events/bpf.h`.
   - Because `kernel/bpf/jit_directives.c` includes this header directly, the patch set is incomplete as committed source.

### Enhancement

1. `recompile_count` should not silently wrap.
   - `include/linux/bpf.h:1715`
   - `kernel/bpf/jit_directives.c:3406`
   - `kernel/bpf/syscall.c:5052`
   - Saturating the counter, documenting wraparound, or widening the internal counter would make the userspace-visible semantics clearer.

## Recommended Fixes

1. Do not mutate live `prog->bpf_func` state in place. Build a replacement image off to the side, publish it with proper synchronization, and retire the old image after an RCU-safe grace period.
2. Reintroduce the load-time JIT success checks in `bpf_jit_recompile_prog_images()`, especially the `func[0]` final-pass stability check and explicit `jited` checks after each pass.
3. Track and free the pre-recompile pack header on successful image swap.
4. Refresh kallsyms around a successful image swap, or provide an equivalent safe in-place update path for the BPF ksym tree.
5. Extend rollback state to cover per-prog `jit_data` / staged pack ownership, and add cleanup for partially recompiled multi-subprog failure paths.
6. Tighten masked ROTATE validation so the mask proves the bits being wrapped are exactly the high `N` bits of a 32-bit rotate.
7. Either derive and validate `COND_SELECT` canonical params from the site, or stop treating its stored params as validated canonical state.
8. Add tests for:
   - recompile failure on `func[0]` extra pass
   - successful rollback after partial multi-subprog staging
   - exception handling after successful recompile
   - repeated recompiles to detect old-image leaks
   - masked ROTATE negative cases

## Overall Assessment

The validator work itself is moving in the right direction, and the x86-side `CMOV` / `BEXTR` / private-stack changes are individually reasonable. The problems are in the lifecycle of re-JITing a **live** kernel program: publication, rollback ownership, old-image retirement, kallsyms/extable integration, and one missing error check in the main-function final pass.

Until those are fixed, this code is not safe enough for ring-0 deployment.
