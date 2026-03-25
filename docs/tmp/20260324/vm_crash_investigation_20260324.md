# VM Crash/Disconnect Investigation - 2026-03-24

Investigating whether BpfReJIT kernel modifications (vendor/linux-framework, rejit-v2 branch)
can cause QEMU/KVM VM crashes, disconnects, or hangs.

## 0. Evidence Inventory

No kernel oops/panic/BUG traces were found in any result directory
(`e2e/results/`, `micro/results/`, `corpus/results/`). The VM kernel
boots with `panic=-1` (reboot on panic) and `loglevel=0` (quiet), so
a crash would manifest as the VM process exiting unexpectedly or the
guest script timing out -- neither leaves an explicit stack trace in
the host-visible result files.

The bug log (`rejit_bug_log_20260324.md`) records 18 bugs found and fixed
during v2 development, but none describe a VM-level crash. The symptoms
there are verifier rejections, incorrect BPF behavior, and build failures.

## 1. Dangerous Changes Ranked by Crash Risk

### CRITICAL (Risk 1): `bpf_prog_rejit_swap()` -- UAF Window on Old JIT Image

**File**: `kernel/bpf/syscall.c`

**Code path**: `bpf_prog_rejit()` -> `bpf_prog_rejit_swap()` -> `WRITE_ONCE(prog->bpf_func, tmp->bpf_func)` -> `synchronize_rcu[_expedited|_tasks_trace]()` -> `__bpf_prog_put_noref(tmp)`

**Crash scenario**:
After `WRITE_ONCE(prog->bpf_func, ...)` publishes the new function pointer,
any CPU currently executing the OLD JIT image is still running code in
memory that will be freed after `synchronize_rcu`. The swap uses only
`smp_wmb()` before the WRITE_ONCE, which ensures metadata ordering
but does NOT guarantee that all CPUs have drained execution of the old
image before the free.

The code does call `synchronize_rcu_expedited()` (or `_tasks_trace` for
sleepable progs) AFTER the swap, which should wait for all preempt-off
RCU readers to complete. **However**:

1. **BPF trampoline trampolines**: If a trampoline is rebuilt by
   `bpf_trampoline_refresh_prog()` AFTER `bpf_func` is swapped but
   BEFORE `synchronize_rcu`, and a CPU is in the middle of executing
   the old trampoline that still calls the old `bpf_func`, the
   trampoline rebuild does its own `synchronize_rcu()` inside
   `bpf_trampoline_update()`. This nested synchronize is safe on its
   own, but the **ordering** is:

   ```
   swap bpf_func                         <-- CPUs may still use old func
   bpf_trampoline_refresh_prog()         <-- rebuilds trampoline
     bpf_trampoline_update()
       arch_prepare_bpf_trampoline()
       bpf_tramp_image_alloc_and_swap()
         synchronize_rcu_tasks()          <-- waits for old trampoline users
   synchronize_rcu_expedited()            <-- waits for old bpf_func users
   __bpf_prog_put_noref(tmp)             <-- frees old JIT image
   ```

   The question is: can a CPU enter the old trampoline (which calls old
   `bpf_func`) AFTER the trampoline update's `synchronize_rcu_tasks()`
   but BEFORE the outer `synchronize_rcu_expedited()`? Yes, because the
   trampoline update only waits for old trampoline users, and the outer
   synchronize waits for RCU read-side critical sections (which is when
   BPF programs run in non-sleepable mode). The window exists but the
   outer synchronize should cover it.

   **Verdict**: Likely safe for non-sleepable programs, but the ordering
   is fragile. For sleepable programs using `synchronize_rcu_tasks_trace()`,
   the guarantees are weaker if a trampoline is concurrently in use.

2. **No bpf_text_poke invalidation of old image**: The old JIT image is
   freed via normal `bpf_prog_free()` -> `bpf_prog_pack_free()`. The
   code correctly calls `bpf_arch_text_invalidate()` inside
   `bpf_prog_pack_free()` (verified: core.c still has this call with
   a WARN_ONCE). This fills freed pack regions with `int3` (on x86)
   or equivalent, preventing stale execution.

   **Verdict**: Safe -- `bpf_arch_text_invalidate` is present.

3. **Multi-subprog programs**: `bpf_prog_rejit_swap()` swaps
   `prog->aux->func` (the subprog array). The old subfuncs are on
   `tmp` and freed after RCU. But subfunc pointers may be cached in
   various places (tail call maps, other progs' call sites). The swap
   of `func[]` array means `prog->aux->func[i]->bpf_func` now points
   to new subfuncs. Call sites in the main prog that do `bpf_func()`
   dispatch should resolve correctly because they go through the main
   prog's JIT image.

   **Verdict**: Needs careful review per call path, but structurally
   the swap covers `func[]`. **Potential issue**: if a subprog was
   independently called from another prog (not the case in current BPF).

**Crash manifestation**: UAF -> random code execution -> kernel panic/oops
or silent memory corruption -> eventual crash. In a VM, this causes the
guest to crash or hang, which the host sees as the QEMU process exiting
or stalling.

**KVM interaction**: Not KVM-specific, but in a VM environment, memory
corruption can interact badly with virtio/9p shared memory, causing the
VM to lose its root filesystem and appear to "disconnect".

---

### HIGH (Risk 2): `bpf_struct_ops_refresh_prog()` -- text_poke into Trampoline Image

**File**: `kernel/bpf/bpf_struct_ops.c`

**Code path**: `bpf_prog_rejit()` -> `bpf_struct_ops_refresh_prog()` -> `find_call_site()` -> `bpf_arch_text_poke()`

**API verification**: `bpf_arch_text_poke()` in this tree takes 5
parameters: `(ip, old_t, new_t, old_addr, new_addr)`. The call passes
`(call_site, BPF_MOD_CALL, BPF_MOD_CALL, old_bpf_func, prog->bpf_func)`,
which is correct: replacing a CALL with a CALL, patching from old target
to new target.

**Crash scenario**:

1. **Incorrect call site detection**: `find_call_site()` uses the x86
   instruction decoder (`asm/insn.h`) to walk instructions in the
   struct_ops trampoline image, looking for a `CALL rel32` whose target
   is `old_bpf_func`. Bug #5 in the bug log confirms this was previously
   using raw byte matching and was fixed.

   **Remaining risk**: If the trampoline image has been modified by
   another concurrent operation (e.g., another BPF prog REJIT affecting
   the same struct_ops map), the scan could find the wrong call site.
   The code holds `st_ops_assoc_mutex` which prevents concurrent struct_ops
   association changes, but NOT concurrent JIT image modifications to
   the same trampoline from different paths.

2. **find_call_site returns NULL**: If the call site is not found
   (e.g., the trampoline was rebuilt between the swap and the refresh),
   the function prints a warning and returns `-ENOENT`. The caller
   swallows this error (`err = 0`), meaning the struct_ops trampoline
   retains the old call target. After the old image is freed and
   invalidated with `int3`, the struct_ops trampoline calls `int3`,
   causing an immediate `#BP` exception -> kernel panic.

   This scenario requires the trampoline to have been rebuilt by a
   concurrent operation, which is unlikely under normal benchmarking
   but could happen with concurrent struct_ops updates.

3. **text_poke targets wrong address in trampoline**: If the trampoline
   contains multiple CALL instructions (e.g., for prologue/epilogue
   helpers), `find_call_site()` correctly scans for the specific call
   to `old_bpf_func`. Since it uses the instruction decoder, false
   positives are unlikely.

**Severity**: Moderate. The text_poke call itself is correct, but the
error-swallowing pattern means a failed refresh silently creates a
use-after-free when the old image is freed. The failure window is small
under normal operation.

---

### MEDIUM (Risk 3): Trampoline Refresh Lock Ordering -- Review

**File**: `kernel/bpf/trampoline.c`

**Code path**: `bpf_prog_rejit()` holds `prog->aux->rejit_mutex`, then
calls `bpf_trampoline_refresh_prog()` which takes `tr->mutex` for each
trampoline. Nesting: `rejit_mutex -> tr->mutex`.

Meanwhile, `bpf_trampoline_link_prog()` takes `tr->mutex` first, then
**releases it**, then takes `prog->aux->rejit_mutex`. The two locks are
NOT held simultaneously in the link/unlink path.

**Analysis**: Since the link/unlink paths release `tr->mutex` before
acquiring `rejit_mutex`, there is no ABBA deadlock in the current code.
The lock ordering is:
- REJIT path: `rejit_mutex` held -> `tr->mutex` taken/released
- Link/unlink path: `tr->mutex` taken/released -> `rejit_mutex` taken/released

However, there is a **subtle race window**: Between releasing `tr->mutex`
and acquiring `rejit_mutex` in `bpf_trampoline_link_prog()`, a concurrent
REJIT could rebuild the trampoline. The rebuild uses the `trampoline_users`
list, but the new tramp_user entry has not yet been added. This means the
rebuild would NOT include the newly linked prog. However, the newly linked
prog was already added to the trampoline's progs list (under `tr->mutex`),
and the next trampoline update will pick it up. The window is safe because
the trampoline update inside `refresh_prog` uses `bpf_trampoline_get_progs()`
which reads `tr->progs_hlist` (protected by `tr->mutex`).

**Verdict**: No deadlock. The race window is benign. Not a crash risk.

---

### HIGH (Risk 4): `bpf_prog_rejit_poke_target_phase()` -- Map IDR Scan Without Proper Locking

**File**: `kernel/bpf/syscall.c`

**Code path**: `bpf_prog_rejit()` -> `bpf_prog_rejit_poke_target_phase(prog, false)` which scans ALL PROG_ARRAY maps in the system.

**Crash scenario**:

1. The function uses `bpf_map_get_curr_or_next(&id)` to iterate all
   maps. For each PROG_ARRAY, it reads `array->ptrs[key]` without
   holding the map's poke_mutex or spin_lock first (the comment says
   "intentionally lockless pre-check").

2. It then takes `array->aux->poke_mutex` and calls
   `map->ops->map_poke_run()`. The `map_poke_run` for PROG_ARRAY
   iterates `poke_progs` list and calls `text_poke` on each caller's
   JIT image.

3. **Race**: Between the lockless `array->ptrs[key] != prog` check and
   the `map_poke_run` call, the slot could have been updated. The comment
   acknowledges this, saying both directions are "benign". This is
   probably correct for functional behavior, but:

4. **Potential issue**: `map_poke_run` with `old=prog, new=NULL` does
   `text_poke` to replace `jmp addr` with `nop`. If `prog` was already
   removed from the slot by another thread, the text_poke tries to
   replace a `jmp` that may have already been replaced. The
   `bpf_arch_text_poke` verifies the old bytes match, so it would
   return -EINVAL. The error propagates up but is not checked by
   `map_poke_run`.

**Manifestation**: Usually benign (text_poke fails silently), but could
theoretically leave a stale direct jump in a caller's JIT image.

---

### MEDIUM (Risk 5): `bpf_prog_rejit_update_poke_tab()` -- Poke Entry Copy Without Full Synchronization

**File**: `kernel/bpf/syscall.c`

The function copies JIT address fields from `tmp`'s poke entries into
`prog`'s poke entries. It holds `poke_mutex` and uses
`WRITE_ONCE(tailcall_target_stable, false)` to block concurrent
`map_poke_run`.

**Potential issue**: Between Phase 1 (delete direct jumps) and Phase 2
(insert with new address), there's a window where direct tail calls to
this prog fall through to the fallback path. The code comments say this
is safe because `rejit_mutex` is held and the target prog is always
valid. This is correct -- the prog is always valid, it just temporarily
doesn't have a direct jump optimization.

**Verdict**: Functionally correct but introduces a brief performance
regression during REJIT (tail calls go through the fallback indirect
path).

---

### MEDIUM (Risk 6): Dispatcher Refresh with `synchronize_rcu_expedited()`

**File**: `kernel/bpf/dispatcher.c`

`bpf_dispatcher_refresh_prog()` calls `bpf_dispatcher_update()` with
`expedited=true`, which uses `synchronize_rcu_expedited()` instead of
the normal `synchronize_rcu()`.

**KVM guest concern**: `synchronize_rcu_expedited()` sends IPIs to all
CPUs to force grace period completion. In a KVM guest:
- IPIs are delivered via virtual interrupts
- If QEMU is overcommitting CPUs, the IPI delivery can be delayed
- Multiple concurrent `synchronize_rcu_expedited()` calls from different
  REJIT operations could cause IPI storms

**Manifestation**: Not a crash per se, but can cause severe latency
spikes and apparent "disconnects" if the VM monitoring infrastructure
has tight timeouts.

---

### MEDIUM (Risk 7): Verifier `lower_kinsn_proof_regions()` -- Program Mutation During Verification

**File**: `kernel/bpf/verifier.c`

**Code path**: `bpf_check()` -> `lower_kinsn_proof_regions()` (before
main verification) -> `bpf_patch_insn_data()` to replace sidecar+call
with proof sequence -> main verification -> `restore_kinsn_proof_regions()`
(after verification).

**Crash scenario**: `bpf_patch_insn_data()` can reallocate the program.
The lowering iterates from end to start, using `env->prog->insnsi[i]`
which points to the most recent reallocation. Bug #9 in the bug log
shows this was already found and fixed (stale region start values after
earlier-site lowering changed program length).

**Remaining risk**: The `adjust_prior_kinsn_region_starts()` function
shifts all previously recorded region starts by the net delta. If the
delta calculation is wrong (e.g., due to an edge case with ldimm64 two-
instruction sequences), a subsequent restore could patch the wrong
location, corrupting the insn array.

**Manifestation**: Heap corruption during verification -> crash during
`kvfree` or later. Unlikely to manifest as a VM crash unless it
corrupts random kernel memory.

---

### LOW (Risk 8): `__bpf_ksym_del` RCU List Init Change

**File**: `kernel/bpf/core.c`

**Change**: Added `INIT_LIST_HEAD_RCU(&ksym->lnode)` after `list_del_rcu()`.

**Purpose**: Presumably to prevent a `list_del_rcu` + subsequent
`bpf_prog_kallsyms_add` from racing on the same ksym. The
`INIT_LIST_HEAD_RCU` ensures the list node is in a clean state for
potential re-insertion.

**Risk**: `INIT_LIST_HEAD_RCU` after `list_del_rcu` is generally safe
and is a defensive pattern. No crash risk.

---

### LOW (Risk 9): `test_run.c` XDP Change Removal (now reverted in uncommitted)

**File**: `net/bpf/test_run.c`

The committed diff removes `bpf_prog_change_xdp(NULL, prog)` /
`bpf_prog_change_xdp(prog, NULL)` around repeated XDP test runs.
The uncommitted changes REVERT this (add them back).

**Risk**: Without the change_xdp calls, repeated XDP test_run would
not register/unregister the dispatcher, meaning the XDP dispatcher
would not have the test prog's JIT image in its dispatch table. This
affects only XDP `bpf_prog_test_run_xdp()` with `repeat > 1`.

**Manifestation**: XDP benchmark might be slower (no direct dispatch),
but not a crash.

---

### LOW (Risk 10): `scripts/Makefile.btf` Global Var for External Modules

**File**: `scripts/Makefile.btf`

Adds `global_var` to pahole's `--btf_features` for external module
BTF generation. This is needed so that kinsn module BTF includes
`BTF_KIND_VAR` entries for the kinsn descriptors.

**Risk**: None for crash. Could cause older pahole versions to fail
to generate BTF for kinsn modules if they don't support `global_var`.

---

## 2. KVM/VM Specific Interaction Analysis

### 2.1 Why Would Kernel Bugs Cause VM "Disconnect" Rather Than Just BPF Errors?

In a virtme-ng/QEMU setup:
- The guest kernel boots with `panic=-1` (reboot on panic)
- The guest uses 9p filesystem (`rootfstype=9p`) for the host filesystem
- The guest console is `ttyS0` (serial)

When the guest kernel crashes:
1. **Oops/panic**: Guest reboots (panic=-1), QEMU exits, host sees
   subprocess exit with non-zero code
2. **Deadlock**: Guest hangs, no console output, host subprocess times
   out after the configured timeout
3. **Memory corruption of 9p metadata**: Guest loses filesystem,
   commands fail with I/O errors, script exits with errors
4. **Memory corruption of virtio queues**: Guest-host communication
   breaks, QEMU may crash or the guest appears to "disconnect"

### 2.2 I-Cache Coherency on x86

On x86, writes to code pages are automatically visible to all CPUs
because x86 has a strong memory model and self-modifying code support.
The `text_poke` mechanism uses the `int3` + IPI synchronization protocol
(or `text_poke_bp` on newer kernels). There's no manual `flush_icache_range`
needed on x86.

**However**, in a KVM guest, the guest's writes to code pages go through
the EPT (Extended Page Tables). KVM's EPT does not cache instruction
bytes independently of the guest's TLBs. The x86 `text_poke` mechanism
works correctly in a KVM guest because:
- The guest uses the same `int3` + IPI protocol
- KVM delivers the IPIs as virtual interrupts
- The guest's `serialize` instruction (after `int3` replacement) ensures
  all CPUs see the new code

**Verdict**: I-cache coherency is NOT the issue on x86 KVM.

### 2.3 EPT/Shadow Page Table Invalidation

BPF JIT images live in the `module_alloc` region (or bpf_prog_pack).
When `bpf_arch_text_poke` modifies these pages:
- The guest writes to RWX pages (BPF JIT has W+X at text_poke time)
- KVM's EPT sees the write and updates the EPT entry
- No explicit EPT invalidation needed from the guest

When `bpf_prog_pack_free` + `bpf_arch_text_invalidate` fills freed
regions with `int3`:
- Same mechanism, writes through EPT

**Verdict**: EPT interaction is NOT the issue.

### 2.4 Expedited RCU in KVM Guest

`synchronize_rcu_expedited()` sends IPIs to all online CPUs. In a KVM
guest with multiple vCPUs, these IPIs are delivered as virtual interrupts.
If the host is under load, vCPU scheduling delays can delay IPI delivery,
extending the `synchronize_rcu_expedited()` call. This is normal KVM
behavior and should not cause crashes.

However, multiple concurrent `synchronize_rcu_expedited()` calls (from
REJIT + dispatcher refresh + trampoline refresh) could create a burst
of IPIs that interact poorly with KVM's vCPU scheduling.

**Verdict**: Could contribute to latency/timeout issues but not crashes.

## 3. Most Likely Root Causes (Ordered)

### Root Cause 1: Ordering Fragility in swap + trampoline refresh + RCU

The ordering between `bpf_func` swap, trampoline rebuild, and
`synchronize_rcu` could theoretically allow a CPU to execute old code
after the old image is freed. The current ordering looks correct for the
common case but has subtle edge cases with sleepable programs and
concurrent trampoline updates.

**Impact**: Rare UAF -> crash.

### Root Cause 2: struct_ops Refresh Error Swallowed -- Silent UAF

If `bpf_struct_ops_refresh_prog()` fails (e.g., `find_call_site()` returns
NULL because the trampoline was concurrently rebuilt), the error is logged
but swallowed (`err = 0`). The old JIT image is still freed. Any remaining
reference to the old `bpf_func` address (in the struct_ops trampoline)
becomes a use-after-free.

**Impact**: Crash after old image free for struct_ops programs. Requires
a concurrent struct_ops trampoline rebuild during REJIT (unlikely but
possible).

**Fix**: If struct_ops refresh fails, either roll back the REJIT swap or
leak the old image (don't free it).

### Root Cause 3: Non-REJIT VM Instability

If the VM crashes happen even WITHOUT REJIT operations (i.e., during
plain kernel boot or regular BPF program loading), the issue is likely:
- The modified `kfree(prog->aux->kfunc_tab)` -> `bpf_free_kfunc_desc_tab()`
  change in `__bpf_prog_put_noref` and `bpf_prog_jit_attempt_done`
- The `kvfree(prog->aux->orig_insns)` could crash if `orig_insns` is
  not properly initialized (but `bpf_prog_alloc` zeroes the struct, so
  this should be NULL by default)

## 4. Recommended Debug Steps

### Step 1: Enable Kernel Logging

Change VM boot params from `loglevel=0` to `loglevel=7` and add
`no_hash_pointers` to get raw pointers in stack traces.

### Step 2: Reproduce Without REJIT

Boot the modified kernel and run the benchmark suite WITHOUT loading
kinsn modules and WITHOUT running the daemon. If the VM still crashes,
the issue is in the non-REJIT code paths (the changes to `__bpf_prog_put_noref`,
`bpf_prog_load` for `orig_insns`, etc.).

### Step 3: Reproduce With REJIT But Without struct_ops

Run the micro benchmark suite (which uses tracepoint/kprobe programs,
not struct_ops). If stable, the struct_ops refresh error-swallowing
issue (Root Cause 2) is the likely culprit when struct_ops programs
are involved.

### Step 4: Add lockdep Annotations

Enable `CONFIG_PROVE_LOCKING` in the kernel config. This would
immediately detect any lock ordering violations at runtime.

### Step 5: Add KASAN

Enable `CONFIG_KASAN` to detect UAF in the JIT image free path.

### Step 6: Bisect the VM Crashes

If crashes are intermittent, bisect the rejit-v2 commits to identify
which specific change introduced the instability.

## 5. Summary

| # | Risk | Component | Bug Type | Confirmed? | Impact |
|---|------|-----------|----------|------------|--------|
| 1 | HIGH | swap + RCU + trampoline ordering | UAF race | Possible (code review) | Crash after old image free |
| 2 | HIGH | struct_ops refresh error swallowed | Silent UAF | Possible (code review) | Crash if refresh fails |
| 3 | MEDIUM | trampoline refresh lock ordering | Race window | Reviewed: NOT a deadlock | Benign |
| 4 | MEDIUM | poke_target_phase | Race condition | Possible | Stale jump / benign |
| 5 | MEDIUM | expedited RCU in KVM | Latency spike | Known behavior | Timeout appearance |
| 6 | LOW | verifier proof lowering | Off-by-one | Fixed (#9) | N/A (fixed) |
| 7 | LOW | ksym list init | Defensive | No | N/A |

**Primary recommendations**:
1. Change the struct_ops and trampoline refresh error paths to NOT
   swallow errors. If any refresh fails, the REJIT should fail and
   ideally roll back the swap (or at minimum, not free the old image).
2. Audit the RCU grace period ordering between `bpf_func` swap,
   trampoline rebuild, and old image free. Consider adding a second
   `synchronize_rcu()` after trampoline rebuild to ensure all CPUs
   have drained execution of old trampolines that reference the old
   `bpf_func`.
3. Enable `CONFIG_KASAN` and `CONFIG_PROVE_LOCKING` in the VM kernel
   config to catch UAF and lock ordering issues at runtime.
4. If the VM crashes happen even without REJIT operations, focus on the
   `__bpf_prog_put_noref()` changes (where `kfree` was replaced with
   `bpf_free_kfunc_desc_tab`) and the new `kvfree(orig_insns)` path.
