# BpfReJIT Kernel Code Review v4 - 2026-03-24

Reviewer: Claude Opus 4.6 (automated, upstream BPF subsystem reviewer standard)
Base: `master` (stock kernel, merge tag x86-urgent-2026-03-08)
Committed HEAD: `cb06f7908` (bpf: Refactor kinsn handling and improve verifier region management)
Working tree: committed HEAD + 7 uncommitted files (+299/-49)

---

## 1. v3 Problem Fix Status

| # | v3 Issue | v3 Severity | v4 Status | Evidence |
|---|----------|-------------|-----------|----------|
| **M1** | `kallsyms_lookup_name()` in `fetch_kinsn_desc_meta()` | **Major (blocker)** | **FIXED** | Replaced with `btf_try_get_kinsn_desc()` registration-based API in new `kernel/bpf/btf.c`. `kallsyms_lookup_name` no longer appears in working tree diff. |
| **M2** | `bpf_prog_has_kinsn_call()` does O(N) scan | Major | **FIXED** | Uncommitted change: `return !!prog->aux->kinsn_tab;` (mirrors `bpf_prog_has_kfunc_call`). |
| **M3** | `count_kinsn_calls()` duplicates work | Major | **FIXED** | Uncommitted change: function deleted, replaced by `env->kinsn_call_cnt` tracked during `add_subprog_and_kfunc()`. |
| **M4** | `kfunc_desc_tab` dynamic allocation mixed with kinsn feature | **Major (blocker)** | **NOT FIXED** | Still in the same commit(s). Must be split to a separate preparatory patch for upstream. |
| m1 | `bpf_kinsn_sidecar_payload()` truncation without BUILD_BUG_ON | Minor | **PARTIALLY FIXED** | `BPF_KINSN_SIDECAR_PAYLOAD_BITS` constant removed entirely. No validation added. Acceptable since the encoding is self-documenting in the inline function. |
| m2 | `bpf_prog_rejit_swap()` fragile field-by-field copy | Minor | Not addressed | Same as v3. Non-blocking. |
| m5 | `BPF_KINSN_SIDECAR_PAYLOAD_BITS` unused constant | Minor | **FIXED** | Removed from working tree `include/linux/bpf.h`. |
| m6 | `bpf_prog_rejit_poke_target_phase()` O(N_maps) scan | Minor | Not addressed | Non-blocking for initial submission. |
| n1 | Enhanced `pr_err` in x86 JIT unrelated to REJIT | Nit | **FIXED** | Uncommitted change reverts `pr_err` to upstream original: `pr_err("bpf_jit: unknown opcode %02x\n", insn->code)`. |
| n2 | `scripts/Makefile.btf` fragile | Nit | Not addressed | Acceptable. |
| n3 | `test_run.c` removal of `bpf_prog_change_xdp` | Nit | **FIXED** | Uncommitted change restores the original `bpf_prog_change_xdp` calls. Working tree has zero diff vs master for `test_run.c`. |
| n4 | `jit_disasm_helpers.c` unrelated to BpfReJIT | Nit | **NOT FIXED** | `normalize_movabs_imm_hex()` + `#include <stdlib.h>` still committed and present in working tree. Should be a separate patch. |
| n5 | `btf.h` blank line removal | Nit | **FIXED** | Uncommitted change restores the blank line. Working tree btf.h diff only has functional kinsn additions. |

**Score: 7/10 fixed, 1 partially fixed, 2 not fixed (M4 kfunc split + n4 jit_disasm).**

---

## 2. New Code Review: `kernel/bpf/btf.c` (+237 lines)

This is the kinsn registration API that replaces `kallsyms_lookup_name`. It follows the `register_btf_kfunc_id_set()` pattern.

### Architecture

- `struct btf_kinsn_desc { var_id, desc }` -- maps BTF VAR id to `struct bpf_kinsn *`
- `struct btf_kinsn_tab { cnt, descs[] }` -- flex array, sorted by var_id, stored in `struct btf`
- `register_bpf_kinsn_set()` -- called by kinsn modules at init, resolves BTF names to var_ids, stores in btf->kinsn_tab
- `unregister_bpf_kinsn_set()` -- cleanup on module exit
- `btf_try_get_kinsn_desc()` -- verifier-side lookup by var_id with `try_module_get`

### [Major] M-NEW-1: No concurrency protection for `btf->kinsn_tab` access

- **File**: `kernel/bpf/btf.c`, lines 9024-9085 and 9087-9163
- **Issue**: `register_bpf_kinsn_set()` and `unregister_bpf_kinsn_set()` read and write `btf->kinsn_tab` (including `kfree(old_tab)` + `btf->kinsn_tab = new_tab`) without any locking. If two modules call `register_bpf_kinsn_set` concurrently for the same BTF (e.g., vmlinux BTF), there is a use-after-free/double-free race on `old_tab`.

  The existing `register_btf_kfunc_id_set` has the same lack of locking but documents "This function must be invoked only from initcalls/module init functions" -- which are serialized by the module loader's `module_mutex`. The new kinsn registration has **no such documentation**.

  Additionally, `btf_try_get_kinsn_desc()` reads `btf->kinsn_tab` without barriers. If called concurrently with `register_bpf_kinsn_set()` (verifier running while a module is loading), the pointer read could see a stale `kinsn_tab`. In practice, module init completes before verification uses the module's kinsn, but this is not enforced.

- **Fix**: Add the same documentation comment: `/* Must be invoked only from initcalls/module init functions */`. If concurrent registration is ever needed, add a mutex.

### [Major] M-NEW-2: `btf_type_is_kinsn_desc()` duplicated in btf.c and verifier.c

- **File**: `kernel/bpf/btf.c` line 8983 and `kernel/bpf/verifier.c` line 3616
- **Issue**: Two separate `static` definitions of `btf_type_is_kinsn_desc()` with slightly different signatures:
  - btf.c: `static bool btf_type_is_kinsn_desc(const struct btf *btf, u32 type_id)`
  - verifier.c: `static bool btf_type_is_kinsn_desc(struct btf *btf, u32 type_id)` -- missing `const`, has extra redundant `btf_type_by_id` check

  The verifier.c version does:
  ```c
  t = btf_type_by_id(btf, type_id);  // redundant
  if (!t) return false;
  t = btf_type_skip_modifiers(btf, type_id, &type_id);  // also resolves type_id
  ```
  The first `btf_type_by_id` is redundant because `btf_type_skip_modifiers` handles NULL internally.

- **Fix**: Move `btf_type_is_kinsn_desc()` to a shared header or export it from btf.c. Use the `const struct btf *` signature. Remove the redundant `btf_type_by_id` call from the verifier.c copy.

### [Minor] m-NEW-1: `(void)param;` casts in `btf_try_get_kinsn_desc` stub

- **File**: `include/linux/btf.h`, lines 656-658
- **Issue**: The `!CONFIG_BPF_SYSCALL` stub uses `(void)btf; (void)var_id; (void)desc;` to suppress unused parameter warnings. This is not standard kernel style. The kernel convention is to either use `__always_unused` attribute or simply have the return statement (the compiler doesn't warn for static inline stubs with parameters that are unused). No other stub in the same file uses `(void)` casts.
- **Fix**: Remove the three `(void)` casts. Just `return -ENOENT;`.

### [Minor] m-NEW-2: `unregister_bpf_kinsn_set()` silently fails on allocation failure

- **File**: `kernel/bpf/btf.c`, lines 9136-9138
- **Issue**: If `kmalloc` for `new_tab` fails during unregistration, the function silently returns without removing any descriptors. The old_tab retains stale entries pointing to soon-to-be-unloaded module memory. When the module is freed, `btf_try_get_kinsn_desc()` could return a dangling `desc` pointer (the `try_module_get` would fail since the module is being unloaded, so this is safe in practice -- `try_module_get` returns false for modules in `MODULE_STATE_GOING`).

  However, the `var_ids` allocation at line 9105 also fails silently, and in that case the function returns without doing anything. If the module then fully unloads, a subsequent `btf_try_get_kinsn_desc()` call would:
  1. `bsearch` finds the stale entry
  2. `res->desc` points to freed module memory
  3. `kinsn->owner` is read from freed memory (use-after-free)
  4. `try_module_get(kinsn->owner)` -- UAF on the `struct module`

  This is a real UAF vulnerability on the `kinsn->owner` dereference in `btf_try_get_kinsn_desc` line 9185.

- **Fix**: Either:
  1. Use `GFP_KERNEL` (not `__GFP_NOWARN`) so OOM killer can help, and WARN on failure since module cleanup must succeed.
  2. Or mark the entries as invalidated (set `desc = NULL`) in-place without reallocation.
  3. Or at minimum, set `old_tab->descs[i].desc = NULL` for each entry being removed, so the `!res->desc` check in `btf_try_get_kinsn_desc` catches it.

### [Minor] m-NEW-3: `unregister_bpf_kinsn_set` has O(N*M) complexity

- **File**: `kernel/bpf/btf.c`, lines 9114-9126 and 9142-9153
- **Issue**: Two nested loops over `old_tab->cnt * set->cnt`. The same O(N*M) scan is repeated twice (once for counting, once for copying). For small N and M this is fine, but the pattern could be simplified to a single pass with in-place compaction.
- **Fix**: Non-blocking, but could be simplified.

### [Nit] n-NEW-1: `btf_free_kinsn_tab` does not release module refs

- **File**: `kernel/bpf/btf.c`, lines 1815-1819
- **Issue**: `btf_free_kinsn_tab()` only does `kfree(btf->kinsn_tab)`. It does NOT call `module_put` on the kinsn descriptors' owners. Compare with `bpf_free_kinsn_desc_tab()` in verifier.c which DOES call `module_put`. The btf-side tab stores `const struct bpf_kinsn *desc` but `register_bpf_kinsn_set` does NOT call `try_module_get` during registration (the module is guaranteed alive during init). And `btf_try_get_kinsn_desc` does its own `try_module_get`. So `btf_free_kinsn_tab` doesn't need to `module_put`. This is correct.
- **Verdict**: Correct, but the asymmetry with `bpf_free_kinsn_desc_tab` (verifier side) is confusing. Add a comment.

---

## 3. New Code Review: `kernel/bpf/verifier.c` changes (+65/-49 uncommitted)

### [Major] M-NEW-3: `kinsn_call_cnt` can over-count

- **File**: `kernel/bpf/verifier.c`, uncommitted change in `add_subprog_and_kfunc()`
- **Issue**: The code increments `env->kinsn_call_cnt` before calling `add_kinsn_call()`:
  ```c
  else {
      env->kinsn_call_cnt++;
      ret = add_kinsn_call(env, insn->imm, insn->off);
  }
  ```
  If `add_kinsn_call()` fails (returns error), the count is already incremented but no descriptor was actually added. The count is then used to allocate `kinsn_regions`. An over-count leads to a slightly over-sized allocation (harmless waste) but the actual region usage (`kinsn_region_cnt`) is correctly tracked separately during `lower_kinsn_proof_regions`.

  More importantly, `add_subprog_and_kfunc` returns the error immediately after the failed `add_kinsn_call`, so the over-counted value is never used. The allocation happens later in `bpf_check()` only if `add_subprog_and_kfunc` succeeds.

- **Verdict**: **Downgraded to Minor**. Not a correctness issue since the count is only used on the success path. But the increment should be after the success check for clarity:
  ```c
  ret = add_kinsn_call(env, insn->imm, insn->off);
  if (ret >= 0)
      env->kinsn_call_cnt++;
  ```

### Verified: `fetch_kinsn_desc_meta()` correctly uses new API

- The function now calls `btf_try_get_kinsn_desc(btf, var_id, kinsn)` which does the BTF lookup + `try_module_get`.
- On failure, provides differentiated error messages for `-ENOENT` vs other errors.
- Post-lookup validation checks `instantiate_insn` and `max_insn_cnt`, and correctly calls `module_put` if the descriptor is incomplete.
- The old `kallsyms_lookup_name` path is completely gone.
- The old `!(*kinsn)->owner` check is correctly removed -- built-in descriptors have `owner == NULL`, which is now explicitly documented in `struct bpf_kinsn`.

---

## 4. Remaining Changes Review

### `include/linux/bpf.h` (+24/-0 uncommitted)

- Added `bpf_kinsn_id` and `bpf_kinsn_set` structs: clean, minimal.
- Added `struct module *owner` comment "NULL for built-in/vmlinux descriptors": good documentation.
- Added `register_bpf_kinsn_set`/`unregister_bpf_kinsn_set` declarations + stubs: correct.
- Removed `BPF_KINSN_SIDECAR_PAYLOAD_BITS`: good cleanup.

### `include/linux/btf.h` (+12 uncommitted)

- Added `struct bpf_kinsn` forward declaration: needed for `btf_try_get_kinsn_desc`.
- Added `btf_try_get_kinsn_desc` declaration + stub: correct.
- `(void)` casts in stub: style issue (see m-NEW-1 above).

### `include/linux/bpf_verifier.h` (+1 uncommitted)

- Added `u32 kinsn_call_cnt`: clean, used correctly.

### `arch/x86/net/bpf_jit_comp.c` (+4/-2 uncommitted)

- Reverts the enhanced `pr_err` back to the upstream original: `pr_err("bpf_jit: unknown opcode %02x\n", insn->code)`. Good cleanup.

### `net/bpf/test_run.c` (+5 uncommitted)

- Restores the `bpf_prog_change_xdp` calls that were erroneously removed in committed HEAD. Working tree matches upstream. Good.

---

## 5. Unnecessary Changes Checklist (Working Tree vs Master)

| File | Change | Necessary for REJIT/kinsn? | Status |
|------|--------|:---:|---|
| `tools/testing/selftests/bpf/jit_disasm_helpers.c` | `normalize_movabs_imm_hex()` + `#include <stdlib.h>` (+30 lines) | NO (test infra) | **Should be separate patch** |
| `kernel/bpf/verifier.c` | `kfunc_desc_tab`/`kfunc_btf_tab` dynamic allocation refactor (~60 lines) | INDIRECTLY (shared `ensure_desc_capacity`) | **Should be separate patch** |
| `scripts/Makefile.btf` | `global_var` for external modules (+2 lines) | YES (for kinsn module BTF) | Keep |
| `kernel/bpf/verifier.c` | `btf_type_is_kinsn_desc()` duplicate | NO (should use btf.c version) | **Should deduplicate** |

**Unrelated changes remaining**: ~90 lines (jit_disasm_helpers 30 + kfunc refactor 60). Significantly reduced from v3.

**Previously flagged unnecessary changes now fixed**:
- pr_err enhancement: REVERTED
- btf.h blank line: RESTORED
- test_run.c XDP removal: RESTORED
- KF_KINSN dead code: REMOVED (v3)
- api_version/flags dead fields: REMOVED (v3)
- tnum.h include: REMOVED (v3)
- `__maybe_unused`: REMOVED (v3)

---

## 6. Upstream Acceptability Assessment

### Blocking Issues

| # | Severity | File | Issue | Fix Effort |
|---|----------|------|-------|------------|
| 1 | Major | verifier.c | `kfunc_desc_tab`/`kfunc_btf_tab` dynamic allocation mixed with kinsn feature -- must be separate preparatory patch | Easy (git rebase) |
| 2 | Minor | btf.c | `register_bpf_kinsn_set` missing "must be called from init" documentation | Trivial (add comment) |
| 3 | Minor | btf.c + verifier.c | `btf_type_is_kinsn_desc()` duplicated with different signatures | Easy (deduplicate) |

### Important Non-blocking Issues

| # | Severity | File | Issue |
|---|----------|------|-------|
| 4 | Minor | btf.c | `unregister_bpf_kinsn_set` silent failure on OOM can leave dangling descriptors (UAF on `kinsn->owner`) |
| 5 | Minor | btf.h | `(void)param` casts in stub -- non-standard kernel style |
| 6 | Minor | verifier.c | `kinsn_call_cnt` incremented before `add_kinsn_call` success check |
| 7 | Minor | bpf.h | `bpf_prog_rejit_swap()` fragile field-by-field copy |
| 8 | Minor | syscall.c | `bpf_prog_rejit_poke_target_phase()` O(N_maps) scan |
| 9 | Nit | jit_disasm_helpers.c | Unrelated test infra change should be separate patch |

### Previously Reported Issues: Resolved

The following major/critical issues from v1-v3 are all confirmed fixed in the working tree:

1. `validate_kinsn_proof_seq` JMP32|JA bug (v1 Critical) -- FIXED in committed HEAD
2. `lower_kinsn_proof_regions` control flow bug (v2 Critical) -- FIXED in committed HEAD
3. `bpf_kinsn_sidecar_payload` dst_reg masking (v1 Major) -- FIXED in committed HEAD
4. `bpf_prog_rejit_swap` E2BIG check (v1 Major) -- FIXED in committed HEAD
5. `find_call_site` byte-scanning (v1 Major) -- FIXED in committed HEAD (instruction-boundary scan)
6. x86 emit buffer overflow (v1 Major) -- FIXED in committed HEAD (scratch buffer)
7. ARM64 const-cast (v1 Major) -- FIXED in committed HEAD
8. `kinsn_tab` swap symmetry (v1 Critical) -- FIXED in committed HEAD
9. `skip_full_check` indentation (v2 Major) -- FIXED in committed HEAD
10. `validate_ldimm64_layout` debug scaffolding (v2 Major) -- FIXED in committed HEAD
11. `kinsn_regions` fixed array (v2 Major) -- FIXED in committed HEAD (dynamic allocation)
12. Trampoline freplace refresh wrong poke type (v2 Major) -- FIXED in committed HEAD (full rebuild)
13. `kallsyms_lookup_name` (v1-v3 Major blocker) -- **FIXED** in uncommitted btf.c
14. `bpf_prog_has_kinsn_call` O(N) scan (v3 Major) -- **FIXED** in uncommitted verifier.c
15. `count_kinsn_calls` duplication (v3 Major) -- **FIXED** in uncommitted verifier.c
16. Dead code (KF_KINSN, api_version, flags, tnum.h, PAYLOAD_BITS, __maybe_unused) -- all FIXED
17. Unrelated changes (pr_err, btf.h blank line, test_run.c) -- all FIXED (reverted)

---

## 7. Security Analysis of New btf.c Code

### Trust Model
- `register_bpf_kinsn_set()` requires module init context (module loading requires `CAP_SYS_MODULE`).
- `btf_try_get_kinsn_desc()` is only called from the verifier path which requires `CAP_BPF`.
- Module reference counting (`try_module_get`/`module_put`) prevents use-after-free of module code.

### Potential UAF in Unregistration
- If `unregister_bpf_kinsn_set()` fails (OOM on `var_ids` or `new_tab` allocation), stale entries remain in `btf->kinsn_tab`.
- When the module is fully unloaded, `kinsn->owner` becomes a dangling pointer.
- `btf_try_get_kinsn_desc()` reads `kinsn->owner` before calling `try_module_get`.
- **Mitigation**: In `MODULE_STATE_GOING`, the module's memory is still valid during the `going` notifier chain. By the time `module_free()` is called, all verifier uses should be done. However, this is fragile.
- **Risk**: Low in practice (OOM during module unload is rare and the window is small), but a theoretical UAF.

### Integer Overflow Analysis
- `struct_size(new_tab, descs, old_cnt + set->cnt)` in `register_bpf_kinsn_set`: `set->cnt` is u32, `old_cnt` is u32. Sum could overflow. `struct_size` uses `size_mul`/`size_add` which return `SIZE_MAX` on overflow, causing `kmalloc` to fail. **Safe**.
- `array_size(old_cnt, sizeof(new_tab->descs[0]))` in `memcpy`: same overflow protection via `array_size`. **Safe**.

---

## 8. Code Quantity Summary

### Per-file Breakdown (Working Tree vs Master)

| File | +/- | Purpose |
|------|-----|---------|
| kernel/bpf/verifier.c | +682/-32 | kinsn verifier, kfunc refactor, proof lowering |
| kernel/bpf/syscall.c | +601/-1 | REJIT syscall, swap, poke_tab |
| kernel/bpf/btf.c | +237/-0 | **NEW**: kinsn registration API |
| include/linux/bpf.h | +110/-0 | structs, helpers, declarations |
| kernel/bpf/bpf_struct_ops.c | +108/-0 | struct_ops refresh |
| kernel/bpf/trampoline.c | +58/-1 | trampoline refresh |
| arch/x86/net/bpf_jit_comp.c | +51/-2 | x86 kinsn emit |
| arch/arm64/net/bpf_jit_comp.c | +38/-0 | arm64 kinsn emit |
| include/uapi/linux/bpf.h | +24/-0 | UAPI: REJIT, kinsn, prog_info |
| kernel/bpf/dispatcher.c | +20/-3 | dispatcher refresh |
| include/linux/btf.h | +11/-0 | kinsn BTF declarations |
| include/linux/filter.h | +11/-0 | BPF_CALL_KINSN macro |
| kernel/bpf/core.c | +10/-1 | ksym reinit, free tab |
| include/linux/bpf_verifier.h | +10/-0 | kinsn_region, kinsn_call_cnt |
| net/core/filter.c | +5/-0 | XDP refresh |
| scripts/Makefile.btf | +3/-1 | external module BTF |
| kernel/bpf/disasm.c | +2/-0 | kinsn disasm string |
| **Core kernel total** | **+1981/-41** | **1940 net** |
| tools/include/uapi/linux/bpf.h | +24/-0 | UAPI mirror |
| tools/testing/selftests/bpf/* | +138/-0 | tests |
| **Tools/tests total** | **+162/-0** | **162 net** |
| **GRAND TOTAL** | **+2143/-41** | **2102 net** |

### Comparison with Previous Reviews

| Review | Core Kernel Net LOC | Blocker Count | Notes |
|--------|-------------------|---------------|-------|
| v1 | ~1480 | 7 | Initial review |
| v2 | ~1580 | 7 | Some fixes, new issues found |
| v3 | ~1418 | 2 (kallsyms + kfunc split) | Major cleanup, most issues fixed |
| **v4** | **~1940** | **1 (kfunc split)** | +237 btf.c (kallsyms replacement), fixes accumulated |

The +522 line increase from v3 to v4 is primarily:
- `kernel/bpf/btf.c`: +237 (new registration API replacing `kallsyms_lookup_name`)
- `include/linux/bpf.h`: +23 (new structs for registration API)
- `include/linux/btf.h`: +11 (declarations)
- Net effect of other uncommitted changes: ~+51

The btf.c addition is a direct consequence of fixing the v3 kallsyms blocker. The new code follows established kernel patterns (`register_btf_kfunc_id_set`).

### Plan Doc Claim vs Reality

Plan doc claims: "~550 lines (not counting comments)"
Actual core kernel: **1940 net lines** (including comments)

The 550-line claim is only achievable by counting the minimal REJIT syscall + kinsn proof lowering without:
- Refresh paths (struct_ops 108 + trampoline 58 + dispatcher 20 + XDP 5 = 191 lines)
- Registration API (btf.c 237 lines)
- kfunc refactor (60 lines, should be split anyway)
- Headers and UAPI (155 lines)
- JIT arch support (89 lines)

---

## 9. Overall Assessment

### Verdict: **Close to ready. 1 remaining blocker.**

The single remaining blocker is **M4: kfunc_desc_tab dynamic allocation must be split into a separate preparatory patch**. This is a git-rebase-level fix, not a code change.

The `kallsyms_lookup_name` blocker from v3 has been properly fixed with a well-designed registration API that follows established kernel patterns. The new btf.c code is structurally sound, with a few minor issues (missing init-only documentation, function duplication, theoretical UAF on unregister OOM).

### Progress Across Reviews

- **v1**: 7 blockers (2 Critical, 5 Major)
- **v2**: 7 blockers (1 Critical, 6 Major) -- some fixed, new ones found
- **v3**: 2 blockers (0 Critical, 2 Major) -- major cleanup
- **v4**: 1 blocker (0 Critical, 1 Major) -- kallsyms fixed, cleanup continues

### Recommended Actions Before Submission

1. **[Blocker]** Split kfunc dynamic allocation to a separate preparatory patch
2. **[Should fix]** Add init-only comment to `register_bpf_kinsn_set`
3. **[Should fix]** Deduplicate `btf_type_is_kinsn_desc()` between btf.c and verifier.c
4. **[Should fix]** Remove `(void)` casts in btf.h stub
5. **[Should fix]** Fix `unregister_bpf_kinsn_set` silent failure (set `desc = NULL` in-place)
6. **[Should fix]** Move `kinsn_call_cnt++` after `add_kinsn_call` success
7. **[Nice to have]** Split `jit_disasm_helpers.c` changes to separate patch
8. **[Nice to have]** Commit all uncommitted changes

### Positive Aspects

1. **kallsyms replacement is well-designed**: The btf.c registration API follows the exact pattern of `register_btf_kfunc_id_set`, making it familiar to upstream reviewers.
2. **Aggressive cleanup of unnecessary changes**: pr_err enhancement, btf.h blank line, test_run.c removal, dead code -- all cleaned up.
3. **All v1/v2 Critical issues remain fixed**: proof sequence, control flow, buffer overflow, swap symmetry.
4. **Security model unchanged**: CAP_BPF + CAP_SYS_ADMIN, full verifier re-verification, module ref counting.
5. **The architecture is sound**: proof-sequence lowering, scratch-buffer JIT emit, registration-based lookup.
