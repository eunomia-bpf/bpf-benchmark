# BpfReJIT Kernel Code Review - 2026-03-24

Reviewer: Claude Opus 4.6 (automated)
Base commit: `c23719abc` (Merge tag 'x86-urgent-2026-03-08')
Head: working tree (includes uncommitted changes on top of `cb82fae35`)

---

## Diff Statistics

```
17 files changed, 1717 insertions(+), 46 deletions(-)
```

Core kernel files (excluding tests/tools):
- kernel/bpf/verifier.c: ~700 lines added
- kernel/bpf/syscall.c: ~590 lines added
- kernel/bpf/bpf_struct_ops.c: ~98 lines added
- kernel/bpf/trampoline.c: ~63 lines added
- arch/x86/net/bpf_jit_comp.c: ~46 lines added
- arch/arm64/net/bpf_jit_comp.c: ~40 lines added
- include/linux/bpf.h: ~93 lines added
- Others: ~87 lines added

---

## include/uapi/linux/bpf.h

### Severity: Minor
- **Lines**: BPF_PSEUDO_KINSN_CALL=4, BPF_PSEUDO_KINSN_SIDECAR=3
- **Issue**: The numbering gap (KFUNC_CALL=2, SIDECAR=3, KINSN_CALL=4) is fine, but the ordering is confusing -- SIDECAR (3) is defined after KINSN_CALL (4) in the source. Convention is sequential definition.
- **Fix**: Reorder the definitions to match numerical order.

### Severity: Minor
- **Lines**: `struct { ... } rejit;` in `union bpf_attr`
- **Issue**: The `rejit` struct is placed after `prog_assoc_struct_ops` but the padding/alignment implications of the union are not validated. The `fd_array` field is `__aligned_u64` which is correct. However, `CHECK_ATTR(BPF_PROG_REJIT)` depends on `BPF_PROG_REJIT_LAST_FIELD` being `rejit.flags`, which is the last field. This is correct.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `orig_prog_len` / `orig_prog_insns` in `struct bpf_prog_info`
- **Issue**: New UAPI fields appended at end of struct. Placement is correct for backward compatibility since older kernels would have `info_len` smaller.
- **Verdict**: OK.

---

## include/linux/bpf.h

### Severity: Major
- **Lines**: `bpf_kinsn_sidecar_payload()` packing
- **Issue**: The payload encoding packs `dst_reg` (4 bits), `off` (16 bits shifted left by 4), and `imm` (32 bits shifted left by 20). Total: 4+16+32 = 52 bits, fitting in u64. However, `dst_reg` is defined as `__u8` in `struct bpf_insn` but only 4 bits are used (values 0-15). The cast `(u64)insn->dst_reg` would include all 8 bits. If a malicious program sets `dst_reg` to a value > 15, the high 4 bits would overlap with the `off` field. The verifier checks for `dst_reg == 0` for the sidecar case (in `do_check_insn`), but there's no explicit range check before payload extraction in the JIT path.
- **Fix**: Either mask dst_reg to 4 bits in `bpf_kinsn_sidecar_payload()`: `(u64)(insn->dst_reg & 0xF)`, or add an explicit check in the verifier. Currently the verifier skips the sidecar instruction via `check_kinsn_sidecar_insn` which does NOT validate dst_reg range.

### Severity: Minor
- **Lines**: `struct bpf_kinsn` definition
- **Issue**: The `api_version` and `flags` fields are defined but never checked anywhere in the code. Dead fields.
- **Fix**: Remove or document intended future use.

### Severity: Nit
- **Lines**: `#include <linux/tnum.h>` added
- **Issue**: No code in `bpf.h` uses tnum directly. This include may have been needed by removed code.
- **Fix**: Remove if not needed.

---

## include/linux/bpf_verifier.h

### Severity: Minor (fixed in working tree)
- **Lines**: `struct bpf_kinsn_region kinsn_regions[MAX_KINSN_REGIONS]` (committed HEAD)
- **Issue**: The committed HEAD has a 256-element fixed array of `bpf_kinsn_region` (each ~16 bytes) embedded in `bpf_verifier_env`, adding ~4KB to a stack/heap-allocated struct. The working tree fixes this with dynamic allocation.
- **Verdict**: Fixed in working tree, but uncommitted.

---

## kernel/bpf/syscall.c

### Severity: Critical
- **Lines**: `bpf_prog_rejit()` -- missing `kinsn_tab` swap
- **Issue**: In `bpf_prog_rejit_swap()`, `kfunc_tab` is swapped but `kinsn_tab` is NOT swapped. After JIT, `bpf_prog_jit_attempt_done()` frees both `kfunc_tab` and `kinsn_tab` and sets them to NULL. So `tmp->aux->kinsn_tab` is already NULL when we reach the swap. The swap of `kfunc_tab` transfers prog's still-valid `kfunc_tab` to tmp (where it will be freed on tmp destruction), and gives prog the NULL. This is correct because kfunc_tab is only needed during verification/JIT, not at runtime. However, `kinsn_tab` is NOT swapped, meaning prog's old `kinsn_tab` will be freed when prog itself is eventually freed via `__bpf_prog_put_noref`, and tmp's NULL kinsn_tab is harmless. This is actually correct but inconsistent -- `kfunc_tab` is swapped (giving prog NULL) while `kinsn_tab` is not swapped (prog keeps its old pointer). The old `kinsn_tab` was already freed in `bpf_prog_jit_attempt_done` at initial load time, so prog->aux->kinsn_tab should already be NULL.
- **Verdict**: After analysis, this is likely correct because both tabs are freed post-JIT. But it's fragile -- if kinsn_tab survives past JIT for any reason, there would be a double-free. The asymmetry with kfunc_tab is suspicious. **Recommend making the kinsn_tab handling explicit** (either swap it too, or add a comment explaining why not).

### Severity: Major
- **Lines**: `bpf_prog_rejit_swap()` -- insn copy size check
- **Issue**: The code checks `if (bpf_prog_size(tmp->len) <= prog->pages * PAGE_SIZE)` before copying the new instructions. `bpf_prog_size()` returns the total struct size including the flexible array. But `prog->pages * PAGE_SIZE` is the allocation size of the *original* prog. If the new program has more instructions than the original, the copy is silently skipped. This means `bpf_prog_get_info_by_fd` (xlated dump) would show stale instructions while the JIT image has already been updated. This is a **correctness issue** -- observability tools (bpftool) would see inconsistent state.
- **Fix**: Either always reallocate prog to fit the new insns, or document this limitation, or return -ENOMEM if the new program doesn't fit.

### Severity: Major
- **Lines**: `bpf_prog_rejit_poke_target_phase()` -- map_idr scan
- **Issue**: This function iterates over ALL maps in the system to find PROG_ARRAY entries containing this program. This is O(N_maps * max_entries) and holds `poke_mutex` for each array. On systems with many maps, this could cause significant latency under `rejit_mutex`.
- **Fix**: Consider adding a reverse index from prog to PROG_ARRAY slots (similar to `trampoline_users`). This is a performance concern, not a correctness bug.

### Severity: Major
- **Lines**: `bpf_prog_rejit_poke_target_phase()` -- reading `array->ptrs[key]`
- **Issue**: `array->ptrs[key]` is read without holding the map lock or RCU read lock. Another CPU could be updating this slot concurrently. The `poke_mutex` is only locked *after* the match is found. A TOCTOU race: the slot could change between the check and the poke_run. However, `poke_mutex` serializes poke_run calls, and the worst case is a spurious NOP->JMP or JMP->NOP that gets corrected by the subsequent poke_run triggered by the concurrent update. This is acceptable for the REJIT use case.
- **Verdict**: Acceptable, but add a comment documenting the benign race.

### Severity: Major
- **Lines**: `bpf_prog_rejit_swap()` -- `smp_wmb()` before `WRITE_ONCE(prog->bpf_func, ...)`
- **Issue**: The `smp_wmb()` ensures all metadata writes are visible before `bpf_func` is published. However, on architectures with weak memory ordering (ARM64), readers need a corresponding `smp_rmb()` or `READ_ONCE()` + data dependency. The BPF trampoline and dispatcher use `prog->bpf_func` via indirect calls which provide implicit data dependencies on x86 but may not on ARM64. The existing kernel code uses `rcu_dereference`/`READ_ONCE` for such patterns.
- **Fix**: Verify that all readers of `prog->bpf_func` use `READ_ONCE()` or equivalent. The fast path in BPF dispatch already does this, but custom REJIT paths should be audited.

### Severity: Minor
- **Lines**: `bpf_prog_rejit()` permission check
- **Issue**: Requires `CAP_BPF` and `CAP_SYS_ADMIN`. This is the strongest permission level. The original `BPF_PROG_LOAD` uses `bpf_capable()` (which is `CAP_BPF`). REJIT requiring `CAP_SYS_ADMIN` in addition is a sound security decision -- it's more restrictive than load.
- **Verdict**: Good.

### Severity: Minor
- **Lines**: `bpf_prog_rejit()` -- fd_array handling
- **Issue**: `kfd_array` is allocated with `kvmalloc(fda_size, GFP_USER)` and filled from user space. The max is 64 entries (256 bytes). This is fine.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `bpf_prog_rejit()` -- `load_attr.insns = attr->rejit.insns`
- **Issue**: The `insns` field is a user pointer that gets passed to `bpf_check()` via the synthesized `load_attr`. Since `load_uattr = KERNEL_BPFPTR(&load_attr)`, and the insns were already copied into `tmp->insns` above, the verifier should use `tmp->insns` directly. The `load_attr.insns` is only used for the verifier log path and fd_array processing, not for re-reading instructions. This is safe.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `bpf_prog_get_info_by_fd()` -- orig_insns exposure
- **Issue**: Original bytecode is exposed when `bpf_dump_raw_ok()` is true. This matches the existing `xlated_prog_insns` permission model. No additional attack surface.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `bpf_prog_rejit()` error paths
- **Issue**: The error cleanup paths (`free_tmp_noref`, `free_tmp_sec`, `free_tmp`) handle dst_prog, attach_btf, func_info, orig_insns correctly. The `free_tmp_sec` path calls `security_bpf_prog_free` before `free_tmp`. The `free_tmp_noref` path handles the post-verification case where `__bpf_prog_put_noref` handles full cleanup.
- **Verdict**: Error paths look correct.

### Severity: Nit
- **Lines**: `bpf_prog_rejit()` -- `if (attr->rejit.flags)` check
- **Issue**: Currently rejects all nonzero flags. This is correct for future extensibility. But the error code is `-EINVAL` which should be consistent with `CHECK_ATTR`.
- **Verdict**: OK.

---

## kernel/bpf/verifier.c

### Severity: Critical
- **Lines**: `validate_kinsn_proof_seq()` -- line 3916
- **Issue**: The condition `if (op == BPF_JA || BPF_OP(insn->code) != BPF_CALL)` is logically always true after the previous check. The previous `if` already returns for `op == BPF_CALL`, so at this point `BPF_OP(insn->code) != BPF_CALL` is always true. This means the jump range check applies to ALL JMP/JMP32 instructions (except CALL/EXIT which are already excluded). This is actually the intended behavior (check all conditional jumps), but the condition is misleadingly written. It should just be a fallthrough without the redundant `BPF_OP(insn->code) != BPF_CALL` check. More importantly, for conditional jumps (`BPF_JEQ`, `BPF_JGT`, etc.), the fall-through path (`i+1`) should also be validated (it always is valid since `i+1 <= cnt`). But the `tgt <= i` check prevents back-edges while allowing `tgt == i+1` (fall-through alias for `off=0`). This is fine.
- **Real bug**: For `BPF_JMP32 | BPF_JA` (the 32-bit unconditional jump), the offset is in `insn->imm`, not `insn->off`. This function only checks `insn->off`. If a kinsn proof sequence contains a JMP32|JA, the target calculation would be wrong.
- **Fix**: Add a case for `BPF_JMP32 | BPF_JA` using `insn->imm` as the offset. Or forbid JMP32 in proof sequences.

### Severity: Major
- **Lines**: `__find_kfunc_desc_btf()` -- lazy init of `kfunc_btf_tab`
- **Issue**: The original code assumed `kfunc_btf_tab` was already allocated before this function is called (it's normally set up in `add_kfunc_call`). The new code adds lazy initialization: if `tab` is NULL, allocate it. This was added to support kinsn calls which might need `find_kfunc_desc_btf` before any kfunc is added. However, the `bsearch` on the next line still runs with `tab->descs` and `tab->nr_descs` (both zeroed from kzalloc), which is harmless (bsearch with nr_descs=0 returns NULL immediately). This is correct.
- **Verdict**: OK, but the lazy init changes the invariant for all callers of this function, not just kinsn. This could mask bugs where `kfunc_btf_tab` was expected to already exist. Add a comment.

### Severity: Major
- **Lines**: `fetch_kinsn_desc_meta()` -- `kallsyms_lookup_name(sym_name)` to get kinsn address
- **Issue**: Using `kallsyms_lookup_name()` to resolve a BTF symbol name to a `struct bpf_kinsn *` is fragile. If two modules export symbols with the same name, the wrong one could be resolved. Additionally, there's no validation that the returned address actually points to a valid `struct bpf_kinsn` -- the code dereferences `(*kinsn)->owner` etc. without any bounds checking or type validation beyond the BTF type check. A malicious module could export a BTF_KIND_VAR with the right type but with garbage data. However, since this requires `CAP_BPF` and module loading requires `CAP_SYS_MODULE`, the trust model is acceptable.
- **Fix**: Consider using `btf_id_set8` registration mechanism similar to kfunc registration to avoid `kallsyms_lookup_name` reliance.

### Severity: Major
- **Lines**: `check_kinsn_sidecar_insn()` -- verifier handling
- **Issue**: The sidecar instruction check advances `env->insn_idx` by 1 (skipping the next kinsn call). But it does NOT actually verify the kinsn call's effects on register state. The kinsn call is processed via `lower_kinsn_proof_regions` (pre-verification) which replaces the sidecar+call pair with the proof sequence. After verification, `restore_kinsn_proof_regions` puts them back. This means the verifier verifies the *proof sequence* (the BPF equivalent), not the native kinsn. This is the correct design -- the proof sequence IS the verifier's model of the kinsn. However, the sidecar check in `do_check_insn` should never be reached if lowering works correctly, since the sidecar is replaced before verification. The code IS reached only during the restore phase or if lowering is incomplete.
- **Verdict**: The architecture is sound, but the unreachable-in-normal-flow sidecar handler could mask lowering bugs. Add a `WARN_ON_ONCE` instead of silently advancing.

### Severity: Major
- **Lines**: `lower_kinsn_proof_regions()` / `restore_kinsn_proof_regions()` ordering
- **Issue**: `lower_kinsn_proof_regions` iterates from the end of the program backward (i = prog->len-1 to 0), patching as it goes. Each patch changes instruction indices. The code uses `verifier_remove_insns` then `bpf_patch_insn_data`. Since it iterates backward, earlier indices are not affected by patches to later indices. This is correct.
- **Issue**: `restore_kinsn_proof_regions` iterates from region 0 to kinsn_region_cnt-1 (forward). Regions were added during backward iteration, so region[0] has the highest `start` index. Restoring from highest to lowest index is correct since each restoration changes only instructions at/after `region->start`. Wait -- actually regions were added in backward order, so `regions[0]` has the LAST (smallest) start index found during backward iteration. No -- the backward loop finds kinsn calls from end to start, so the first one found (added to regions[0]) has the highest start. The second one found has a lower start, etc. So `regions[0].start > regions[1].start > ...`. Restoring in forward order (0, 1, 2...) means we restore the highest-start region first, which is correct (doesn't affect lower indices).
- **Verdict**: Correct.

### Severity: Minor
- **Lines**: `bpf_check()` -- moved `check_btf_info_early` and `add_subprog_and_kfunc` before `explored_states` allocation
- **Issue**: These were moved to run before `explored_states` allocation so that `lower_kinsn_proof_regions` can run before the verifier main loop. But the error goto now jumps to `skip_full_check` which tries to `kvfree(env->explored_states)`. Since `explored_states` is not yet allocated (still NULL), `kvfree(NULL)` is a no-op, which is safe.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `skip_full_check` label -- indentation
- **Issue**: The code after `skip_full_check:` has inconsistent indentation:
  ```c
  skip_full_check:
          kvfree(env->explored_states);   // extra tab
          env->explored_states = NULL;    // extra tab

          if (ret == 0)                   // extra tab
                  ret = restore_kinsn_proof_regions(env);

      /* might decrease stack depth... */  // correct indent
  ```
- **Fix**: Remove the extra tab indentation after `skip_full_check:`.

### Severity: Minor
- **Lines**: `jit_subprogs()` -- `func[i]->aux->kinsn_tab = prog->aux->kinsn_tab`
- **Issue**: Shares the kinsn_tab pointer between the main prog and all subfunctions, same as kfunc_tab. This is correct -- all subprogs need access to the same kinsn descriptors for JIT emission.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `do_misc_fixups()` -- kinsn lowering for non-JIT
- **Issue**: When `bpf_kinsn_has_native_emit` returns true and JIT is requested, the sidecar+call pair is kept for the JIT. Otherwise, the proof sequence replaces the pair. This is the correct fallback behavior.
- **Verdict**: OK.

### Severity: Nit
- **Lines**: `disasm_call_name()` (renamed from `disasm_kfunc_name`)
- **Issue**: Good cleanup. Handles both kfunc and kinsn calls, with NULL check on btf_type_by_id result.
- **Verdict**: OK.

### Severity: Nit
- **Lines**: `backtrack_insn()` -- sidecar handling
- **Issue**: Returns 0 for sidecar instructions, treating them as no-ops for precision tracking. This is correct since sidecars don't modify register state.
- **Verdict**: OK.

---

## arch/x86/net/bpf_jit_comp.c

### Severity: Major
- **Lines**: `emit_kinsn_desc_call()` -- emit vs non-emit pass
- **Issue**: The x86 JIT runs two passes: first with `emit=false` (size calculation), then `emit=true` (actual emission). The code passes `!!rw_image` as the `emit` flag. The kinsn's `emit_x86` callback receives `prog` and `off` by pointer. When `emit=false`, `prog` points to the writable buffer (NULL in first pass). The module's emit function must handle `image=NULL` correctly when `emit=false`. This is a contract that module authors must follow but is not enforced.
- **Fix**: Document this contract in the `struct bpf_kinsn` definition.

### Severity: Major
- **Lines**: `emit_kinsn_desc_call()` -- size validation
- **Issue**: The check `if (ret != off || ret > kinsn->max_emit_bytes)` validates that the returned count matches the offset delta and doesn't exceed max. However, `off` is initialized to 0 and the callback is expected to advance it. If the callback writes more bytes than `max_emit_bytes`, the overflow has already happened by the time the check runs.
- **Fix**: The `max_emit_bytes` should be used to limit the buffer space available to the callback, not just as a post-hoc check. This requires coordination with the JIT's memory layout.

### Severity: Minor
- **Lines**: `emit_movabs_imm64()` -- new helper
- **Issue**: Clean refactoring of `emit_priv_frame_ptr()` to use a proper movabs helper. The old code used `emit_mov_imm64` which splits the 64-bit value into two 32-bit halves differently. The new helper emits the standard REX.W + B8+rd encoding followed by the full 8-byte immediate.
- **Verdict**: Good cleanup.

### Severity: Minor
- **Lines**: `BPF_ALU64 | BPF_MOV | BPF_K` case -- sidecar skip
- **Issue**: When the instruction is a sidecar, the JIT breaks out of the case without emitting anything. This is correct since the sidecar's payload is consumed by the following kinsn call emission.
- **Verdict**: OK.

---

## arch/arm64/net/bpf_jit_comp.c

### Severity: Major
- **Lines**: `emit_kinsn_desc_call_arm64()` -- `n_insns` variable reuse
- **Issue**: `n_insns` is first assigned the return value of `bpf_jit_get_kinsn_payload()` (which returns 0 on success, negative on error). Then it's reused for the `emit_arm64` callback return value. The initial check `if (n_insns)` catches errors from the first call (non-zero = error). Then `n_insns = kinsn->emit_arm64(...)` overwrites it with the actual instruction count. This works but the variable name is misleading for the first usage.
- **Fix**: Use a separate `ret` variable for the first call's return value for clarity.

### Severity: Minor
- **Lines**: `build_insn()` -- sidecar skip
- **Issue**: Returns 0 for sidecar instructions, making the JIT skip them. Correct behavior.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: const cast `(struct bpf_prog *)ctx->prog`
- **Issue**: `ctx->prog` is `const struct bpf_prog *` but `emit_arm64` takes `struct bpf_prog *`. The cast drops const. The callback should take a const pointer if it doesn't modify the prog.
- **Fix**: Change `emit_arm64` signature to take `const struct bpf_prog *`.

---

## kernel/bpf/trampoline.c

### Severity: Major
- **Lines**: `bpf_trampoline_link_prog()` -- pre-allocation + rejit_mutex
- **Issue**: The `bpf_tramp_user` allocation and list insertion uses `link->link.prog->aux->rejit_mutex`. This mutex is taken AFTER `tr->mutex` is released. The lock ordering is: `tr->mutex` -> release -> `rejit_mutex`. In `bpf_trampoline_refresh_prog()`, the lock ordering is: `rejit_mutex` (held by caller) -> `tr->mutex`. This creates a potential deadlock:
  - Thread A: `bpf_trampoline_link_prog` holds `tr->mutex`, releases it, then takes `rejit_mutex`
  - Thread B: `bpf_prog_rejit` holds `rejit_mutex`, then `bpf_trampoline_refresh_prog` takes `tr->mutex`

  Actually, in `bpf_trampoline_link_prog`, `tr->mutex` is released BEFORE `rejit_mutex` is acquired. So:
  - Thread A: lock(tr->mutex) -> unlock(tr->mutex) -> lock(rejit_mutex)
  - Thread B: lock(rejit_mutex) -> lock(tr->mutex) -> unlock(tr->mutex) -> unlock(rejit_mutex)

  There is no cycle because A never holds both simultaneously. Thread B holds rejit_mutex then takes tr->mutex. Thread A takes them sequentially without nesting. No deadlock.
- **Verdict**: Lock ordering is safe.

### Severity: Minor
- **Lines**: `bpf_trampoline_refresh_prog()` -- `bpf_arch_text_poke` for freplace
- **Issue**: Uses `BPF_MOD_JUMP, BPF_MOD_JUMP` (old_type=JUMP, new_type=JUMP) which is the correct signature for patching an existing jump to a new target.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `bpf_trampoline_unlink_prog()` -- list cleanup
- **Issue**: After unlinking, iterates `trampoline_users` to find and remove the matching entry. This is correct but O(N) where N is the number of trampolines using this prog. In practice N is small.
- **Verdict**: OK.

---

## kernel/bpf/bpf_struct_ops.c

### Severity: Major
- **Lines**: `find_call_site()` -- x86 byte-scanning
- **Issue**: The x86 scan iterates byte-by-byte looking for `CALL_INSN_OPCODE` (0xE8). This could produce false positives if 0xE8 appears as an immediate value or displacement in another instruction. The scan is over JIT-generated trampoline code where the layout is controlled, making false positives unlikely but not impossible.
- **Fix**: Consider using the `bpf_arch_text_poke` mechanism directly or recording the call site offset during trampoline generation instead of scanning.

### Severity: Minor
- **Lines**: `bpf_struct_ops_refresh_prog()` -- `guard(mutex)` usage
- **Issue**: Uses `guard(mutex)(&prog->aux->st_ops_assoc_mutex)` which is a cleanup-based lock pattern. This is modern kernel style and correct.
- **Verdict**: OK.

### Severity: Minor
- **Lines**: `bpf_struct_ops_refresh_prog()` -- `bpf_arch_text_poke` parameters
- **Issue**: The call uses `BPF_MOD_CALL, BPF_MOD_CALL` which patches an existing CALL instruction to a new target. The `call_site` was found by scanning for the old target. This is correct.
- **Verdict**: OK.

---

## kernel/bpf/dispatcher.c

### Severity: Minor
- **Lines**: `bpf_dispatcher_refresh_prog()` / `bpf_dispatcher_update()` with `expedited` parameter
- **Issue**: The `expedited` flag uses `synchronize_rcu_expedited()` instead of `synchronize_rcu()`. This is appropriate for REJIT where we want to minimize the time between old and new images.
- **Verdict**: OK.

### Severity: Nit
- **Lines**: `bpf_dispatcher_find_prog()` usage
- **Issue**: `bpf_dispatcher_find_prog()` is called under `d->mutex`, which is correct.
- **Verdict**: OK.

---

## kernel/bpf/core.c

### Severity: Minor
- **Lines**: `INIT_LIST_HEAD_RCU(&ksym->lnode)` in `__bpf_ksym_del()`
- **Issue**: After erasing from the latch tree and deleting from the list, the lnode is re-initialized with RCU semantics. This is necessary because REJIT might re-add the ksym after deletion (for the new JIT image). Without re-initialization, the subsequent `list_add_rcu` in `bpf_prog_kallsyms_add` would encounter a corrupted list node. Good fix.
- **Verdict**: Correct and necessary.

### Severity: Minor
- **Lines**: `bpf_prog_jit_attempt_done()` -- `bpf_free_kfunc_desc_tab()` / `bpf_free_kinsn_desc_tab()`
- **Issue**: Changed from `kfree(prog->aux->kfunc_tab)` to `bpf_free_kfunc_desc_tab()`. The new free function handles the dynamically allocated `descs` array inside the tab (working tree). This is correct.
- **Verdict**: OK.

---

## kernel/bpf/disasm.c

### Severity: Nit
- **Lines**: New `BPF_PSEUDO_KINSN_CALL` disassembly string
- **Issue**: Shows "kinsn-descriptor" for kinsn calls. Clear and consistent.
- **Verdict**: OK.

---

## net/core/filter.c

### Severity: Nit
- **Lines**: `bpf_prog_refresh_xdp()` -- delegates to dispatcher
- **Issue**: Simple wrapper, correct.
- **Verdict**: OK.

---

## net/bpf/test_run.c

### Severity: Minor
- **Lines**: Removed `bpf_prog_change_xdp(NULL, prog)` / `bpf_prog_change_xdp(prog, NULL)` calls
- **Issue**: These were wrapping the XDP test_run repeat path with dispatcher registration/unregistration. Removing them means the XDP dispatcher is no longer updated for test_run. This could be intentional (test_run doesn't go through the dispatcher), but it changes behavior for XDP programs that are also attached via the dispatcher.
- **Fix**: Verify this removal is intentional and doesn't break XDP test_run with direct dispatch.

---

## scripts/Makefile.btf

### Severity: Minor
- **Lines**: `global_var` BTF feature for external modules
- **Issue**: Adds `,global_var` to pahole's `--btf_features` when building external modules (`KBUILD_EXTMOD`). This enables BTF generation for global variables in kinsn modules, which is needed for the verifier to resolve `struct bpf_kinsn` descriptors. This is a clean integration.
- **Verdict**: OK.

---

## include/linux/filter.h

### Severity: Nit
- **Lines**: `BPF_CALL_KINSN()` macro
- **Issue**: Clean instruction builder macro, consistent with existing patterns.
- **Verdict**: OK.

---

## include/linux/btf.h

### Severity: Minor
- **Lines**: `KF_KINSN (1 << 17)`
- **Issue**: New kfunc flag defined but never checked in the codebase. This appears to be dead code -- the kinsn mechanism uses BTF_KIND_VAR resolution, not KF_KINSN flag.
- **Fix**: Remove if unused, or implement the check.

---

## Overall Assessment

### Total LOC
- **Core kernel**: ~1,717 lines added, ~46 removed = ~1,671 net
- Excluding test/tools: ~1,480 lines net kernel changes
- This exceeds the "~550 lines" claim in the plan doc (that was likely counting only the minimal POC, not all the struct_ops/trampoline/poke_tab support)

### Security Risk Assessment: **Medium**

**Strengths:**
1. REJIT requires `CAP_BPF + CAP_SYS_ADMIN` -- strongest privilege level
2. Full verifier re-verification of new bytecode -- no bypass
3. Proper `rejit_mutex` serialization of concurrent REJIT on same prog
4. kinsn proof sequence validation prevents arbitrary code injection
5. UAPI design is backward-compatible

**Concerns:**
1. `kallsyms_lookup_name` for kinsn resolution is fragile (symbol collisions)
2. `bpf_kinsn_sidecar_payload` field overlap when dst_reg > 15 (needs masking)
3. `find_call_site` byte-scanning could false-positive (unlikely in practice)
4. `validate_kinsn_proof_seq` doesn't handle `BPF_JMP32|BPF_JA` offset correctly
5. Swap-without-realloc for insns means bpftool can show stale bytecode

### Upstream Readiness: **Not yet**
The code is functionally complete but has several issues that would block upstream:
1. The indentation error at `skip_full_check` would fail checkpatch
2. The `KF_KINSN` flag is dead code
3. The `tnum.h` include in bpf.h appears unnecessary
4. The `api_version` and `flags` fields in `struct bpf_kinsn` are unused
5. The `find_call_site` byte-scanning approach would be rejected for upstream (too fragile)
6. The `validate_kinsn_proof_seq` has a correctness bug with JMP32|JA

### Must-Fix Blockers

| # | Severity | File | Issue |
|---|----------|------|-------|
| 1 | Critical | verifier.c | `validate_kinsn_proof_seq` does not handle `BPF_JMP32\|BPF_JA` offset (uses `insn->off` instead of `insn->imm`) |
| 2 | Major | bpf.h | `bpf_kinsn_sidecar_payload()` doesn't mask `dst_reg` to 4 bits -- overlaps with `off` field |
| 3 | Major | syscall.c | `bpf_prog_rejit_swap()` silently drops xlated insns if new prog is larger |
| 4 | Major | bpf_struct_ops.c | `find_call_site()` byte-scanning for CALL opcode could false-positive |
| 5 | Major | x86 JIT | `emit_kinsn_desc_call()` -- buffer overflow possible if module's `emit_x86` writes more than `max_emit_bytes` before post-hoc check |
| 6 | Minor | verifier.c | Uncommitted working tree changes (dynamic allocation) should be committed |
| 7 | Minor | verifier.c | `skip_full_check` indentation is broken |

### Recommended Improvements (Non-blocking)

1. Add reverse index for PROG_ARRAY -> prog (avoid O(N_maps) scan)
2. Replace `kallsyms_lookup_name` with proper kinsn registration API
3. Add `WARN_ON_ONCE` to sidecar handler in `do_check_insn` (should be unreachable)
4. Document `emit` flag contract for `emit_x86`/`emit_arm64` callbacks
5. Make `emit_arm64` take `const struct bpf_prog *`
6. Remove dead `KF_KINSN`, `api_version`, `flags`, `tnum.h` include
