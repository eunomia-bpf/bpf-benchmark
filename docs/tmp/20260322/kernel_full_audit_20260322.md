# BpfReJIT Kernel Code Full Audit Report

**Date**: 2026-03-22
**Scope**: All BpfReJIT changes in `vendor/linux-framework/` from `a3173b119^..HEAD` (13 files, +975/-4 lines)
**Commits reviewed**: a3173b119..b4bd737ef (12 commits)

---

## Summary

Total findings: 18 (3 HIGH, 6 MED, 5 LOW, 4 INFO)

**Conclusion**: The code is NOT yet at upstreamable quality. There are 3 HIGH severity issues (memory leaks, early-return bug in struct_ops refresh) and several MED issues (architecture portability, unnecessary scope of expedited RCU change, missing insns/len swap). The core REJIT mechanism (syscall -> verify -> JIT -> swap -> refresh) is architecturally sound, but the implementation has cleanup gaps and one correctness bug in multi-slot struct_ops patching.

---

## HIGH Severity Findings

### H1. Memory leak: `kfd_array` never freed in `bpf_prog_rejit()`

**File**: `kernel/bpf/syscall.c` lines 3434, 3473-3484
**Description**: `kfd_array` is allocated via `kvmalloc()` at line 3473 but is never freed -- not on the success path (line 3669), not on any error path (`out_unlock`, `free_tmp`, `free_tmp_noref`).
**Impact**: Every REJIT call that passes an `fd_array` leaks memory.
**Fix**: Add `kvfree(kfd_array)` before every exit point, or add it to the `out_unlock` label and ensure all paths go through it.

### H2. Memory leak: `func_info`/`func_info_aux` not freed in `free_tmp` error path

**File**: `kernel/bpf/syscall.c` lines 3549-3577, 3680-3689
**Description**: For BPF_PROG_TYPE_EXT programs, `tmp->aux->func_info` and `tmp->aux->func_info_aux` are allocated (lines 3556, 3565). If `security_bpf_prog_load()` succeeds but later fails before `bpf_check()`, the `free_tmp_sec` -> `free_tmp` path does not free these allocations. `bpf_prog_free()` eventually calls `bpf_prog_free_deferred()` which does NOT free `func_info`/`func_info_aux` (those are normally freed by `__bpf_prog_put_rcu`).
**Impact**: Memory leak for EXT program REJIT failures after security check.
**Fix**: Add `kvfree(tmp->aux->func_info)` and `kfree(tmp->aux->func_info_aux)` to the `free_tmp` label, or restructure to use `__bpf_prog_put_noref` consistently.

### H3. `bpf_struct_ops_refresh_prog()` only patches the first matching slot

**File**: `kernel/bpf/bpf_struct_ops.c` lines 1502-1535
**Description**: The loop at line 1502 iterates over `st_map->funcs_cnt`, but line 1531 does `return 0` immediately after patching the first matching link. If a single BPF program is used for multiple function pointers in the same struct_ops map, only the first slot gets patched; the rest still call the old `bpf_func` address (which will be freed after RCU grace period), leading to a use-after-free.
**Impact**: Crash/corruption if a program is used in multiple struct_ops slots and then REJIT'd.
**Fix**: Replace `return 0;` at line 1531 with `continue;` (or remove the early return entirely and let the loop finish).

---

## MED Severity Findings

### M1. `synchronize_rcu_expedited()` in `bpf_dispatcher_update()` affects ALL dispatchers

**File**: `kernel/bpf/dispatcher.c` line 131
**Description**: The original `synchronize_rcu()` was changed to `synchronize_rcu_expedited()` for "consistency with syscall.c fix." However, `bpf_dispatcher_update()` is called by `bpf_dispatcher_change_prog()` (normal XDP attach/detach) AND `bpf_dispatcher_refresh_prog()` (REJIT only). The expedited change impacts ALL dispatcher updates, not just REJIT, sending IPIs to all CPUs for every XDP program attach/detach.
**Impact**: Increased IPI pressure on production systems unrelated to REJIT. Upstream reviewers will flag this.
**Fix**: Revert to `synchronize_rcu()` in `bpf_dispatcher_update()`. If REJIT needs expedited semantics, add it only in `bpf_dispatcher_refresh_prog()` or pass a flag.

### M2. `find_call_site()` is x86-only but compiled on all architectures

**File**: `kernel/bpf/bpf_struct_ops.c` lines 1461-1478
**Description**: Scans for x86 CALL opcode (0xE8). On ARM64, BL instructions use a different encoding; this function will always return NULL, causing `bpf_struct_ops_refresh_prog()` to return -ENOENT (silently swallowed by the caller at syscall.c line 3647). A REJIT of a struct_ops program on ARM64 will silently fail to patch the trampoline, leading to stale function pointers.
**Impact**: Silent corruption on ARM64 struct_ops REJIT (currently not a practical issue since ARM64 struct_ops + REJIT is unlikely to be tested, but will fail code review).
**Fix**: Either (a) make `find_call_site` arch-aware, or (b) add `#ifdef CONFIG_X86` guard and return -EOPNOTSUPP on other architectures, or (c) use `bpf_arch_text_poke`'s IP-based approach instead of opcode scanning.

### M3. `bpf_register_kfunc_inline_ops()` requires `emit_x86` even on non-x86

**File**: `kernel/bpf/verifier.c` line 3245
**Description**: `!ops->emit_x86` is a hard requirement in the registration function. On ARM64, a module that only provides `emit_arm64` would fail to register.
**Impact**: Inline kfunc is broken on ARM64-only systems.
**Fix**: Change to `if (!ops->emit_x86 && !ops->emit_arm64)` or make the check architecture-conditional.

### M4. `prog->insns` and `prog->len` not swapped during REJIT

**File**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_swap()`
**Description**: `prog->len` (BPF insn count) and the flexible array `prog->insns` (BPF bytecode) are NOT updated during the swap. After REJIT, `bpf_prog_get_info_by_fd()` returns stale `xlated_prog_len` and `xlated_prog_insns` from the OLD program. The `orig_insns`/`orig_prog_len` ARE correctly swapped, so `GET_ORIGINAL` returns the right data.
**Impact**: `bpftool prog dump xlated` shows wrong bytecode after REJIT. Not a runtime correctness bug (JIT uses `bpf_func`, not `insns`), but confusing for debugging and introspection.
**Note**: `insns` is a flexible array member embedded in `struct bpf_prog`, so it can't be pointer-swapped. The fix would require either (a) copying insns if sizes match, or (b) documenting this as a known limitation, or (c) making `xlated_prog_insns` in info_by_fd read from the new JIT image's aux data instead.

### M5. `bpf_arch_text_invalidate` removal weakens security hardening

**File**: `kernel/bpf/core.c` lines 1011-1014
**Description**: `bpf_arch_text_invalidate()` fills freed JIT memory with INT3 (trap) instructions. This prevents stale function pointers from executing old JIT code. The removal avoids `text_mutex` contention but leaves freed JIT slots containing executable code until they're overwritten by a new allocation.
**Impact**: If a stale pointer somehow reaches freed JIT memory, it executes old code instead of trapping. This is a defense-in-depth regression. Upstream will likely object to removing this without an alternative (e.g., deferred invalidation outside text_mutex).
**Fix**: Consider deferring the invalidation to a workqueue that doesn't contend with the JIT path, rather than removing it entirely.

### M6. No `flags` field in UAPI `rejit` struct

**File**: `include/uapi/linux/bpf.h` lines 1926-1935
**Description**: The `rejit` union member has no `flags` field. UAPI structs are immutable once merged. Future extensions (e.g., "dry-run", "verify-only", "preserve-stats") would require adding a new `__u32 flags` field, which would change the `BPF_PROG_REJIT_LAST_FIELD` and break backward compat if any field is added after `fd_array_cnt`.
**Impact**: Design limitation that makes future extension harder.
**Fix**: Add `__u32 flags;` and `__u32 :32;` padding now, before the UAPI is frozen.

---

## LOW Severity Findings

### L1. `array->ptrs[key]` read without lock in `poke_target_phase`

**File**: `kernel/bpf/syscall.c` line 3328
**Description**: `array->ptrs[key] != prog` is checked outside `poke_mutex`. A concurrent map update could change the slot between the check and the locked `map_poke_run`. This is a TOCTOU race.
**Impact**: Low -- `map_poke_run` validates the state internally, so the worst case is a redundant call or a missed slot. The missed-slot case would be caught by the normal map_poke_run triggered by the concurrent update itself.

### L2. `bpf_prog_rejit_poke_target_phase` scans all maps in the system

**File**: `kernel/bpf/syscall.c` lines 3315-3340
**Description**: Iterates through the entire `map_idr` to find PROG_ARRAY maps. On systems with thousands of maps, this is O(n) per REJIT.
**Impact**: Performance concern for systems with many maps. Not a correctness issue.
**Fix**: Add a reverse index from prog to PROG_ARRAY maps that contain it, similar to `trampoline_users`.

### L3. `smp_wmb()` without documented reader-side barrier

**File**: `kernel/bpf/syscall.c` line 3411
**Description**: `smp_wmb()` before `WRITE_ONCE(prog->bpf_func, ...)` ensures metadata is visible before the function pointer. However, the reader side (`include/linux/filter.h` line 712) uses a plain `prog->bpf_func` access without `READ_ONCE()` or `smp_rmb()`.
**Impact**: On weakly-ordered architectures, a reader could theoretically see the new `bpf_func` but stale metadata. On x86 (TSO), this is safe. On ARM64, the data dependency (load bpf_func, then call it) provides implicit ordering for the function call itself, but not for metadata reads that happen after return. Practically very low risk.
**Fix**: Add a comment documenting the ordering contract and why it's safe.

### L4. Comments with Chinese / informal language

**File**: Various commit messages
**Description**: Some commit messages use Chinese characters (e.g., `maps/kfunc/mutex 支持，去掉防御代码`). Code comments are all in English, which is correct.
**Impact**: Upstream submission requires all-English commit messages.

### L5. `bpf_prog_rejit_supported()` allows all program types

**File**: `kernel/bpf/syscall.c` lines 3159-3182
**Description**: Only checks for `!jited`, `is_func`, offloaded, dev_bound. All other program types (socket_filter, cgroup_skb, tracing, etc.) are allowed. The function comments explain why some types are safe, but the blanket `return true` is permissive.
**Impact**: Some exotic program types might have cached bpf_func pointers in places the refresh path doesn't cover. Low risk in practice since the common types are well-tested.

---

## INFO Findings

### I1. `INIT_LIST_HEAD_RCU` in `__bpf_ksym_del` is a correctness fix

**File**: `kernel/bpf/core.c` line 657
**Description**: After `list_del_rcu()`, the node's pointers contain RCU poison values. The subsequent `list_empty()` guard (line 652) would not correctly detect deletion without `INIT_LIST_HEAD_RCU()`. This is needed because REJIT calls `bpf_prog_kallsyms_del_all()` then `bpf_prog_kallsyms_add()` -- without the fix, the add would fail because `list_empty` returns false for a poisoned node.
**Assessment**: Correct and necessary fix. Clean.

### I2. `synchronize_rcu_expedited()` in `bpf_prog_rejit()` is acceptable

**File**: `kernel/bpf/syscall.c` line 3659
**Description**: Called once per REJIT syscall after the swap. REJIT is an infrequent admin operation. The expedited form reduces latency by ~100ms at the cost of IPIs.
**Assessment**: Acceptable for the REJIT path. The concern is only about M1 (dispatcher path).

### I3. `security_bpf_prog_load(tmp, &load_attr, NULL, true)` passes `is_kernel=true`

**File**: `kernel/bpf/syscall.c` line 3579
**Description**: Tells the security subsystem this is a kernel-initiated load. This is intentional since REJIT already requires CAP_BPF + CAP_SYS_ADMIN, but LSM policies that distinguish kernel vs user loads might behave differently.
**Assessment**: Intentional design choice. Document in commit message.

### I4. test_run.c `bpf_prog_change_xdp()` removal is correct

**File**: `net/bpf/test_run.c` (removed lines)
**Description**: `bpf_prog_test_run_xdp()` used `bpf_prog_change_xdp(NULL, prog)` / `bpf_prog_change_xdp(prog, NULL)` to temporarily register/unregister the prog with the XDP dispatcher during test runs. This was an optimization to enable direct dispatch during repeated test runs. The removal means test_run always goes through the indirect call path.
**Assessment**: The removal is functionally correct -- `bpf_prog_test_run_xdp` works without dispatcher registration, just slightly slower for repeated runs. This is NOT related to REJIT safety; it avoids a dispatcher contention issue during rapid test runs. However, this is a stock kernel behavior change that upstream might not accept. Consider reverting this if it was only done to avoid a REJIT interaction.

---

## Bug Fix Review (commit b4bd737ef)

### 1. core.c: Remove `bpf_arch_text_invalidate` -- see M5
- Fixes the deadlock but weakens security hardening. Needs alternative.

### 2. syscall.c: `synchronize_rcu_expedited` -- see I2
- Correct for REJIT path. The dispatcher.c change (M1) is the concern.

### 3. syscall.c: Remove subfunc kallsyms double-registration -- CORRECT
- `jit_subprogs()` during REJIT compilation already registers subfunc ksyms. Re-registering in `bpf_prog_rejit_swap()` corrupts the latch tree. The fix is correct and the comment is accurate.

### 4. test_run.c: Remove `bpf_prog_change_xdp` -- see I4
- Functionally correct but changes stock kernel behavior.

---

## Lock Ordering Analysis

Current lock acquisition order in REJIT:
1. `prog->aux->rejit_mutex` (syscall.c:3456)
2. `array->aux->poke_mutex` (syscall.c:3331, 3576) -- per-PROG_ARRAY
3. `tr->mutex` (trampoline.c:936) -- per-trampoline
4. `prog->aux->st_ops_assoc_mutex` (bpf_struct_ops.c:1493)
5. `text_mutex` (via bpf_arch_text_poke) -- global

In `bpf_trampoline_link_prog`:
1. `tr->mutex` (trampoline.c:857)
2. `prog->aux->rejit_mutex` (trampoline.c:863)

This creates a potential **lock inversion**: REJIT takes `rejit_mutex` then `tr->mutex`, while `bpf_trampoline_link_prog` takes `tr->mutex` then `rejit_mutex`. However, in `bpf_trampoline_link_prog`, the `rejit_mutex` is taken AFTER `tr->mutex` is released (line 858: `mutex_unlock`, then line 863: `mutex_lock`). So there is no actual inversion -- the two locks are never held simultaneously in the link path. This is safe but fragile.

---

## Architecture Readiness Summary

| Component | x86 | ARM64 | Notes |
|-----------|-----|-------|-------|
| Inline kfunc JIT | OK | OK | Both emitters present |
| REJIT syscall | OK | OK | Core path is arch-agnostic |
| Trampoline refresh | OK | OK | Uses arch-agnostic bpf_arch_text_poke |
| Struct_ops refresh | OK | **BROKEN** | find_call_site uses x86 opcode (M2) |
| Inline kfunc registration | OK | **BROKEN** | Requires emit_x86 (M3) |
| Dispatcher refresh | OK | OK | Arch-agnostic |
| Poke/tail_call refresh | OK | OK | Uses arch-agnostic map_poke_run |

---

## Verdict

**Not yet upstreamable.** The 3 HIGH issues must be fixed. The MED issues (especially M1, M2, M5, M6) should be addressed before submission. The core REJIT mechanism is well-designed with proper serialization, but the implementation has several cleanup and portability gaps typical of a POC evolving toward production.

Priority fixes:
1. **H1+H2**: Fix memory leaks (kfd_array, func_info) -- straightforward
2. **H3**: Fix struct_ops multi-slot patching -- change `return 0` to `continue`
3. **M1**: Revert expedited RCU in dispatcher to avoid impact on non-REJIT paths
4. **M5**: Restore text invalidation with deferred approach or document the security trade-off
5. **M6**: Add `flags` field to UAPI before it's frozen
