# BpfReJIT Kernel Code Review v2 - 2026-03-24

Reviewer: Claude Opus 4.6 (automated, upstream BPF subsystem reviewer standard)
Base: `master` (stock kernel)
Head: working tree on branch `rejit-v2` (includes uncommitted changes on top of `cb82fae35`)

NOTE: This review covers the **working tree** state (committed HEAD + uncommitted changes), which is the intended submission candidate. Differences between committed HEAD and working tree are noted where relevant.

---

## 1. Diff Statistics

```
21 files changed, ~1764 insertions(+), ~32 deletions(-)
```

Core kernel files (working tree vs master):

| File | +/- (approx) |
|------|-------------|
| kernel/bpf/verifier.c | ~750+ |
| kernel/bpf/syscall.c | ~600+ |
| kernel/bpf/bpf_struct_ops.c | ~100+ |
| kernel/bpf/trampoline.c | ~65+ |
| arch/x86/net/bpf_jit_comp.c | ~50+ |
| arch/arm64/net/bpf_jit_comp.c | ~40+ |
| include/linux/bpf.h | ~95+ |
| include/uapi/linux/bpf.h | ~24+ |
| include/linux/bpf_verifier.h | ~12+ |
| include/linux/filter.h | ~11+ |
| include/linux/btf.h | ~1+ |
| kernel/bpf/dispatcher.c | ~25+ |
| kernel/bpf/core.c | ~15+ |
| kernel/bpf/disasm.c | ~2+ |
| net/core/filter.c | ~5+ |
| net/bpf/test_run.c | ~5- |
| scripts/Makefile.btf | ~4+ |
| tools/include/uapi/linux/bpf.h | ~24+ (mirror) |
| tools/testing/selftests/bpf/* | ~140+ (tests) |

---

## 2. Previous Review Issue Fix Status

| # | Severity | Issue | Status | Verification |
|---|----------|-------|--------|-------------|
| 1 | Critical | `validate_kinsn_proof_seq` JMP32\|JA uses `insn->off` instead of `insn->imm` | **FIXED** | Lines 3917-3919: `jmp_off = insn->off; if (class == BPF_JMP32 && op == BPF_JA) jmp_off = insn->imm;`. Also removed the misleading `BPF_OP(insn->code) != BPF_CALL` condition. |
| 2 | Critical | `kinsn_tab` swap not symmetric with `kfunc_tab` | **FIXED** | Uncommitted change adds `swap(prog->aux->kinsn_tab, tmp->aux->kinsn_tab)` in `bpf_prog_rejit_swap()`. |
| 3 | Major | `bpf_kinsn_sidecar_payload()` `dst_reg` not masked to 4 bits | **FIXED** | Uncommitted change: `(u64)(insn->dst_reg & 0xf)`. |
| 4 | Major | `bpf_prog_rejit_swap()` silently drops xlated insns if new prog larger | **FIXED** | Uncommitted change: replaced conditional copy with unconditional copy, and added early `-E2BIG` return if `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE` before the swap. |
| 5 | Major | `find_call_site()` byte-by-byte 0xE8 scan could false-positive | **FIXED** | Uncommitted change: x86 path now uses `insn_init()`/`insn_get_length()` from `<asm/insn.h>` to decode instruction boundaries, stepping by actual instruction length instead of byte-by-byte. |
| 6 | Major | x86 `emit_kinsn_desc_call()` buffer overflow: module writes to live JIT image before size check | **FIXED** | Uncommitted change: module now writes to a stack-local `scratch[BPF_MAX_INSN_SIZE]` buffer. After validation, `memcpy(prog, scratch, off)` copies to the actual image. Also added pre-check: `if (kinsn->max_emit_bytes > BPF_MAX_INSN_SIZE) return -E2BIG;`. |
| 7 | Major | ARM64 const-cast `(struct bpf_prog *)ctx->prog` | **PARTIALLY FIXED** | `emit_kinsn_desc_call_arm64()` signature now takes `const struct bpf_prog *`. The `emit_arm64` callback also takes `const`. BUT the call site at line 1630 still has `(struct bpf_prog *)ctx->prog` -- the cast is now unnecessary and should be removed. |

---

## 3. New Issues Found

### 3.1 Critical

### [Critical] Broken control flow in `lower_kinsn_proof_regions()` (uncommitted working tree)
- **File**: `kernel/bpf/verifier.c`, lines 4113-4127
- **Issue**: The function has a severe indentation/control-flow bug. After `verifier_remove_insns()` (line 4113), the code starting at line 4117 (`new_prog = bpf_patch_insn_data(...)`) is indented as if inside a block, but there is no opening brace. The closing brace at line 4125 corresponds to the `for` loop body, and `return 0;` at line 4127 causes the function to return after processing the **first** kinsn call, skipping all remaining ones.

  Specifically:
  ```c
  err = verifier_remove_insns(env, i - 1, 1);
  if (err)
      goto err_free_proof_buf;

          new_prog = bpf_patch_insn_data(env, i - 1, proof_buf, cnt);  // wrong indent
          kvfree(proof_buf);
          if (!new_prog)
              return -ENOMEM;

          env->prog = new_prog;
          adjust_prior_kinsn_region_starts(env, region->start,
                                         cnt - 2);
      }    // closes the for loop

      return 0;  // returns after first kinsn!
  ```

  If the program has multiple kinsn calls, only the last one found (iterating backward) gets lowered. The rest are silently skipped.

- **Fix**: Remove the errant indentation. The `bpf_patch_insn_data` block should be at the same indentation as the `verifier_remove_insns` call. Remove the misplaced `}` and `return 0;`, and let the `for` loop continue. The `return 0;` should be after the `for` loop.
- **Upstream acceptance risk**: High (correctness bug, would be caught immediately)

### 3.2 Major

### [Major] `skip_full_check:` indentation is broken (committed + working tree)
- **File**: `kernel/bpf/verifier.c`, line 26762+
- **Issue**: After the `skip_full_check:` label, the code uses extra tab indentation:
  ```c
  skip_full_check:
          kvfree(env->explored_states);   // extra tab
          env->explored_states = NULL;    // extra tab
  ```
  All subsequent code (the kinsn restore, `remove_fastcall_spills_fills`, etc.) has inconsistent indentation compared to the rest of the function. This would fail `checkpatch.pl --strict`.
- **Fix**: Remove the extra tab level after `skip_full_check:`.
- **Upstream acceptance risk**: Medium (checkpatch failure, but not a correctness bug)

### [Major] `validate_ldimm64_layout()` debug scaffolding pollutes the verification path
- **File**: `kernel/bpf/verifier.c`, lines 26767-26826 (uncommitted)
- **Issue**: The working tree inserts `validate_ldimm64_layout()` calls after **every single verification pass** (restore_kinsn, remove_fastcall, check_max_stack_depth, optimize_bpf_loop, opt_hard_wire, opt_remove_dead_code, opt_remove_nops, sanitize_dead_code, convert_ctx_accesses, do_misc_fixups, opt_subreg_zext). This is ~12 additional full-program scans added to every verification, adding O(12*N) overhead where N is program length. This is clearly debug/development scaffolding, not production code.
- **Fix**: Remove all `validate_ldimm64_layout()` calls. If a specific pass has a known ldimm64 corruption bug, fix that pass directly. At most, add a single assert under `CONFIG_BPF_JIT_ALWAYS_ON` or `CONFIG_DEBUG_INFO_BTF` for debug builds.
- **Upstream acceptance risk**: High (would never be accepted upstream, pure debug overhead)

### [Major] `kinsn_regions` fixed array still in committed HEAD
- **File**: `include/linux/bpf_verifier.h` (committed HEAD)
- **Issue**: The committed HEAD has `struct bpf_kinsn_region kinsn_regions[MAX_KINSN_REGIONS]` (256 elements * 16 bytes = 4KB) embedded in `bpf_verifier_env`. The working tree fixes this with dynamic allocation (`struct bpf_kinsn_region *kinsn_regions` + `u32 kinsn_region_cap`), but this fix is **uncommitted**.
- **Fix**: Commit the dynamic allocation change.
- **Upstream acceptance risk**: Medium (4KB isn't catastrophic since verifier_env is heap-allocated, but upstream reviewers would flag fixed-size arrays)

### [Major] `kfunc_desc_tab` and `kfunc_btf_tab` dynamic allocation changes are mixed with kinsn feature
- **File**: `kernel/bpf/verifier.c` (uncommitted)
- **Issue**: The uncommitted working tree changes the existing `kfunc_desc_tab` and `kfunc_btf_tab` from fixed-size arrays (`descs[MAX_KFUNC_DESCS]`) to dynamically allocated arrays with `ensure_desc_capacity()`. This is a significant refactor of pre-existing infrastructure (not BpfReJIT-specific) that changes the memory allocation pattern for all BPF programs, even those without kinsn. This should be a **separate preparatory patch** that is reviewed and tested independently.
- **Fix**: Split into patch 0/N: "bpf: convert kfunc/kfunc_btf desc tables to dynamic allocation".
- **Upstream acceptance risk**: Medium (mixing unrelated refactors with feature code is a common review objection)

### [Major] `kallsyms_lookup_name()` for kinsn resolution is fragile
- **File**: `kernel/bpf/verifier.c`, `fetch_kinsn_desc_meta()`, line ~3646
- **Issue**: Uses `kallsyms_lookup_name(sym_name)` to resolve a BTF symbol name to a `struct bpf_kinsn *`. Multiple problems:
  1. If two modules export symbols with the same name, the wrong one is resolved.
  2. No validation that the returned address points to a valid `struct bpf_kinsn` beyond checking three fields are non-NULL.
  3. `kallsyms_lookup_name` is discouraged for new uses in upstream (see commit `0bd476e6c671`).
- **Fix**: Use a proper registration mechanism similar to `register_btf_kfunc_id_set()`, where kinsn modules register their descriptors at load time into a global table. The verifier then looks up by BTF type ID directly instead of doing symbol name resolution.
- **Upstream acceptance risk**: High (upstream BPF maintainers have repeatedly objected to `kallsyms_lookup_name` usage)

### [Major] `bpf_trampoline_refresh_prog()` uses wrong `bpf_arch_text_poke()` arguments for freplace
- **File**: `kernel/bpf/trampoline.c`, `bpf_trampoline_refresh_prog()`, line ~938
- **Issue**: The call is:
  ```c
  err = bpf_arch_text_poke(tr->func.addr,
                           BPF_MOD_JUMP, BPF_MOD_JUMP,
                           (void *)old_bpf_func,
                           (void *)prog->bpf_func);
  ```
  For freplace trampolines, `tr->func.addr` is the entry point of the **target function** (the function being replaced). The trampoline itself uses a JMP instruction at `tr->func.addr` to redirect to the replacement. However, `bpf_arch_text_poke` with `BPF_MOD_JUMP, BPF_MOD_JUMP` expects that `old_addr` already has a JMP at `ip`. The actual text poke verifies the old instruction bytes match. If the trampoline uses a CALL (not JMP) at this location, the poke will silently fail or corrupt code.

  Reviewing the normal freplace path in `arch_prepare_bpf_trampoline` for x86: the trampoline image contains a CALL to the replacement prog's `bpf_func`. So using `BPF_MOD_CALL, BPF_MOD_CALL` would be correct, not `BPF_MOD_JUMP, BPF_MOD_JUMP`.

  Actually, looking more carefully: for freplace, the mechanism is: at `tr->func.addr` (start of the target function), there's an indirect jump via trampoline. The trampoline itself calls `bpf_func`. So the poke target should be inside the trampoline image, not `tr->func.addr`. The `bpf_trampoline_update()` path (used for fentry/fexit) is correct since it rebuilds the entire trampoline. But the freplace shortcut here is likely wrong.

- **Fix**: Either always use `bpf_trampoline_update()` for freplace (simplest, correctest), or find the actual CALL site inside the trampoline image (like `find_call_site` does for struct_ops).
- **Upstream acceptance risk**: High (correctness bug in a critical code path)

### [Major] Concurrency gap: REJIT poke_target_phase scans without synchronization
- **File**: `kernel/bpf/syscall.c`, `bpf_prog_rejit_poke_target_phase()`, line ~3297
- **Issue**: The function scans all PROG_ARRAY maps for slots containing `prog`. It reads `array->ptrs[key]` without RCU read lock or map lock, then acquires `poke_mutex` before calling `map_poke_run`. Between the `array->ptrs[key] != prog` check and the `mutex_lock`, another CPU can update the slot (e.g., via `bpf_map_update_elem`). The `poke_mutex` serializes the `poke_run` calls but doesn't prevent the TOCTOU.

  In the delete phase (Phase 1), a false negative (missing a slot that was just added) means the old JMP target survives briefly -- harmless because the old bpf_func is still valid until RCU grace period.

  In the insert phase (Phase 2), a false negative means a slot that was just added gets a stale NOP instead of the new JMP target. The next `bpf_fd_array_map_update_elem` will fix this via its own `poke_run`. So this is benign.

  However, a false positive in Phase 1 (calling `poke_run(map, key, prog, NULL)` on a slot that was already cleared) could corrupt the poke if `poke_run` doesn't handle NULL gracefully -- but it does, since `bpf_jit_get_func_addr` for NULL returns the bypass stub.

- **Verdict**: Benign race, but needs a comment documenting why it's safe.
- **Upstream acceptance risk**: Medium (reviewers will flag the missing lock)

### 3.3 Minor

### [Minor] `#include <linux/tnum.h>` in `bpf.h` is unnecessary
- **File**: `include/linux/bpf.h`, line 30
- **Issue**: `tnum.h` is included but nothing in `bpf.h` uses `tnum_*` types or functions. This was likely added for code that was later removed.
- **Fix**: Remove the include.
- **Upstream acceptance risk**: Low

### [Minor] `KF_KINSN (1 << 17)` in `btf.h` is dead code
- **File**: `include/linux/btf.h`, line 82
- **Issue**: `KF_KINSN` is defined but never checked or used anywhere in the codebase. The kinsn mechanism uses BTF_KIND_VAR resolution, not the kfunc flags path.
- **Fix**: Remove if unused.
- **Upstream acceptance risk**: Low (dead code is a common review complaint)

### [Minor] `api_version` and `flags` in `struct bpf_kinsn` are unused
- **File**: `include/linux/bpf.h`, line 971/974
- **Issue**: These fields are defined in the struct but never read or written by kernel code. They waste 4 bytes per descriptor and suggest unimplemented features.
- **Fix**: Remove or document planned use. If reserved for future, at minimum add a comment.
- **Upstream acceptance risk**: Low (reviewers will object to unused fields)

### [Minor] ARM64 call site retains unnecessary cast
- **File**: `arch/arm64/net/bpf_jit_comp.c`, line 1630
- **Issue**: `(struct bpf_prog *)ctx->prog` cast is now unnecessary since `emit_kinsn_desc_call_arm64` accepts `const struct bpf_prog *`.
- **Fix**: Change to `ctx->prog` directly.
- **Upstream acceptance risk**: Low

### [Minor] `BPF_PSEUDO_KINSN_SIDECAR=3` and `BPF_PSEUDO_KINSN_CALL=4` defined in confusing order
- **File**: `include/uapi/linux/bpf.h`, lines ~1387-1395
- **Issue**: `BPF_PSEUDO_KINSN_CALL` (4) is defined before `BPF_PSEUDO_KINSN_SIDECAR` (3) in the source, violating numerical ordering convention.
- **Fix**: Reorder definitions to match numerical order (3 before 4).
- **Upstream acceptance risk**: Low

### [Minor] `bpf_prog_rejit()` uses `bpf_prog_get()` instead of `bpf_prog_get_type()`
- **File**: `kernel/bpf/syscall.c`, line 3465
- **Issue**: `bpf_prog_get()` doesn't verify the prog type matches the caller's expectation. In `bpf_prog_load`, the type is set by the caller. In REJIT, the type is copied from the existing prog, so this is safe. But using `bpf_prog_get_type()` would be more defensive.
- **Verdict**: Acceptable as-is since type is inherited from prog.
- **Upstream acceptance risk**: Low

### [Minor] `bpf_pseudo_kinsn_call()` is marked `__maybe_unused`
- **File**: `kernel/bpf/verifier.c`, line 275
- **Issue**: The function IS used (in `add_subprog_and_kfunc`, `do_check_insn`, `do_misc_fixups`, etc.). The `__maybe_unused` attribute is incorrect.
- **Fix**: Remove `__maybe_unused`.
- **Upstream acceptance risk**: Low

### [Minor] `lower_kinsn_proof_regions()` and `restore_kinsn_proof_regions()` are `__maybe_unused`
- **File**: `kernel/bpf/verifier.c`
- **Issue**: These functions ARE called from `bpf_check()`. The `__maybe_unused` suggests development scaffolding.
- **Fix**: Remove `__maybe_unused`.
- **Upstream acceptance risk**: Low

### [Minor] `count_kinsn_calls()` does a full program scan that duplicates work
- **File**: `kernel/bpf/verifier.c`, line ~3997
- **Issue**: `alloc_kinsn_proof_regions()` calls `count_kinsn_calls()` which scans all instructions. This is called from `bpf_check()` after `add_subprog_and_kfunc()` which already iterated all instructions and found all kinsn calls. The count could be tracked during `add_kinsn_call()` instead.
- **Fix**: Store the count in `env->kinsn_call_cnt` during `add_subprog_and_kfunc`.
- **Upstream acceptance risk**: Low

### [Minor] `orig_prog_insns` placement in `struct bpf_prog_info` may break ABI
- **File**: `include/uapi/linux/bpf.h`, line ~6720
- **Issue**: `orig_prog_len` (__u32) and `orig_prog_insns` (__aligned_u64) are appended after `attach_btf_id`. Due to alignment, there may be 4 bytes of implicit padding between `orig_prog_len` and `orig_prog_insns`. The struct uses `__attribute__((aligned(8)))`. Older userspace with smaller `sizeof(bpf_prog_info)` will not see these fields (the kernel clamps to `info_len`). This is fine for forward compatibility, but the implicit padding wastes 4 bytes.
- **Fix**: Consider reordering to place `orig_prog_len` after `orig_prog_insns`, or add an explicit `__u32 __reserved_pad;` field.
- **Upstream acceptance risk**: Low (padding is normal, but reviewers may comment)

### [Minor] `bpf_prog_rejit_poke_target_phase()` is O(N_maps * max_entries)
- **File**: `kernel/bpf/syscall.c`, line ~3297
- **Issue**: Scans all maps in the system to find PROG_ARRAY entries containing this prog. On systems with many maps, this could cause significant latency under `rejit_mutex`.
- **Fix**: Add a reverse index from prog to PROG_ARRAY slots (similar to `trampoline_users`).
- **Upstream acceptance risk**: Medium (performance concern on large deployments)

### 3.4 Nit

### [Nit] `bpf_free_kfunc_desc_tab()` function is trivial
- **File**: `kernel/bpf/verifier.c`, line ~3389
- **Issue**: In the committed HEAD (before dynamic allocation), `bpf_free_kfunc_desc_tab()` is just `if (!tab) return; kfree(tab);`. With dynamic allocation, it becomes `kvfree(tab->descs); kfree(tab);` which justifies the wrapper.
- **Verdict**: Fine with dynamic allocation.

### [Nit] `jit_disasm_helpers.c` changes are unrelated to BpfReJIT
- **File**: `tools/testing/selftests/bpf/jit_disasm_helpers.c`
- **Issue**: The `normalize_movabs_imm_hex()` function and `#include <stdlib.h>` are useful test infrastructure improvements but should be in a separate patch.
- **Upstream acceptance risk**: Low

### [Nit] `test_run.c` removal of `bpf_prog_change_xdp` may change XDP test behavior
- **File**: `net/bpf/test_run.c`, lines 1390-1414
- **Issue**: Removing `bpf_prog_change_xdp(NULL, prog)` / `bpf_prog_change_xdp(prog, NULL)` around the test repeat loop means XDP test_run no longer registers/unregisters with the XDP dispatcher for repeated runs. This changes behavior: without dispatcher registration, XDP programs use indirect calls instead of the dispatcher's direct calls during `bpf_prog_test_run_xdp`.
- **Fix**: Ensure this is intentional. If the removal was to avoid conflicts with REJIT's dispatcher refresh, add a comment.
- **Upstream acceptance risk**: Medium (changes existing behavior)

### [Nit] Debug `pr_err` enhancement in x86 JIT
- **File**: `arch/x86/net/bpf_jit_comp.c`, line ~2804 (uncommitted)
- **Issue**: Enhanced error message `pr_err("bpf_jit: unknown opcode %02x at insn %d ...")` is useful but should be in a separate cleanup patch.
- **Upstream acceptance risk**: Low

---

## 4. Security Analysis

### Strengths
1. **REJIT requires `CAP_BPF + CAP_SYS_ADMIN`** -- strongest privilege level, correct.
2. **Full verifier re-verification** of new bytecode -- no bypass possible.
3. **`rejit_mutex`** serializes concurrent REJIT on the same prog.
4. **kinsn proof sequence validation** prevents arbitrary native code injection -- the verifier verifies the BPF equivalent, the JIT emits the native equivalent.
5. **UAPI design** is backward-compatible (new fields appended, CHECK_ATTR used).
6. **dst_reg masking** in sidecar payload now prevents field overlap (fixed).
7. **Scratch buffer** for x86 kinsn emit prevents buffer overflow (fixed).
8. **Instruction-boundary scan** for struct_ops `find_call_site` prevents false positives (fixed).
9. **`insn_cnt` bounded** by `BPF_COMPLEXITY_LIMIT_INSNS`, `fd_array_cnt` bounded by 64.
10. **`copy_from_user` return value** checked correctly.

### Remaining Concerns
1. **`kallsyms_lookup_name`** for kinsn resolution is fragile (symbol collisions, discouraged API).
2. **Trampoline freplace refresh** uses potentially wrong poke type (`BPF_MOD_JUMP` vs `BPF_MOD_CALL`).
3. **TOCTOU in poke_target_phase** -- benign but undocumented.
4. **kinsn module trust boundary**: `instantiate_insn` and `emit_x86`/`emit_arm64` callbacks run in kernel context with full access. A malicious module could emit arbitrary code. Trust model: module loading requires `CAP_SYS_MODULE`, so this is acceptable.

### Integer Overflow Analysis
- `insn_cnt * sizeof(struct bpf_insn)` via `bpf_prog_insn_size()`: `insn_cnt` is capped at `BPF_COMPLEXITY_LIMIT_INSNS` (1M). `sizeof(bpf_insn)` = 8. Product = 8MB, no overflow on 32/64-bit.
- `fd_array_cnt * sizeof(int)`: capped at 64 * 4 = 256 bytes, no overflow.
- `ensure_desc_capacity` doubling: protected by `U32_MAX/2` check.

---

## 5. Concurrency Analysis

### Lock Ordering
- `rejit_mutex` -> `tr->mutex`: used in `bpf_trampoline_refresh_prog()` and `bpf_trampoline_link_prog()` (the latter releases `tr->mutex` before acquiring `rejit_mutex`, so no nesting). **Safe**.
- `rejit_mutex` -> `st_ops_assoc_mutex`: used in `bpf_struct_ops_refresh_prog()`. No reverse ordering exists. **Safe**.
- `rejit_mutex` -> `d->mutex` (dispatcher): used in `bpf_dispatcher_refresh_prog()`. No reverse ordering. **Safe**.
- `rejit_mutex` -> `poke_mutex`: used in `bpf_prog_rejit_update_poke_tab()` and `bpf_prog_rejit_poke_target_phase()`. `poke_mutex` is never held when `rejit_mutex` is acquired. **Safe**.

### Atomicity of Image Swap
- `bpf_func` is updated via `WRITE_ONCE()` with a preceding `smp_wmb()`.
- Concurrent BPF execution reads `bpf_func` via indirect call (data dependency on x86).
- ARM64: relies on `WRITE_ONCE` + `smp_wmb()` + instruction fetch coherency. The ARM64 architecture ensures CALL target resolution uses the latest store-visible value after `smp_wmb()` + ISB (if needed). Since BPF dispatch goes through a stored function pointer, `WRITE_ONCE` is sufficient.
- The two-phase poke_target approach (NOP gap between old and new) is safe for tail calls.

---

## 6. Overall Upstream Acceptability Assessment

### Verdict: **Not ready for upstream submission**

### Blocking Issues (must fix)
1. **Critical**: `lower_kinsn_proof_regions()` control flow bug -- only processes first kinsn call.
2. **Major**: `validate_ldimm64_layout()` debug scaffolding must be removed.
3. **Major**: `skip_full_check:` indentation would fail checkpatch.
4. **Major**: `kallsyms_lookup_name` usage would be rejected by BPF maintainers.
5. **Major**: Trampoline freplace refresh likely uses wrong poke type.
6. **Major**: Uncommitted changes must be committed (the fixes from v1 review are only in working tree).
7. **Major**: kfunc_desc_tab dynamic allocation refactor must be split to a separate patch.

### Non-blocking but Important
1. Dead code: `KF_KINSN`, `api_version`, `flags`, `tnum.h` include.
2. `__maybe_unused` on functions that are used.
3. ARM64 unnecessary const-cast.
4. `test_run.c` behavior change needs documentation.
5. UAPI ordering of KINSN_SIDECAR/KINSN_CALL definitions.

### Positive Aspects
1. The architecture (proof-sequence lowering, verifier modeling, scratch-buffer emit) is sound and well-designed.
2. Permission model is correct and conservative (`CAP_BPF + CAP_SYS_ADMIN`).
3. Error paths are thorough with proper cleanup.
4. The REJIT swap with two-phase poke targeting is clever and correct.
5. The kinsn_tab/kfunc_tab swap symmetry fix (from v1 review) is correct.
6. Dynamic allocation of desc tables (when committed) removes hard limits.
7. Struct_ops instruction-boundary scan fix is correct.
8. The `smp_wmb()` + `WRITE_ONCE()` pattern for bpf_func publication is correct.

---

## 7. Suggested Patch Series Split

For upstream submission, the changes should be split into the following patch series:

```
Patch 0/8: bpf: convert kfunc/kfunc_btf desc tables to dynamic allocation
  - Pure refactor of existing infrastructure
  - No functional change for existing programs
  - Standalone testable

Patch 1/8: bpf: store original program bytecode for prog_info
  - Add orig_insns/orig_prog_len to bpf_prog_aux
  - Expose via bpf_prog_get_info_by_fd
  - UAPI: add orig_prog_len/orig_prog_insns to bpf_prog_info
  - Include selftest: get_original_poc.c

Patch 2/8: bpf: add BPF_PROG_REJIT syscall command
  - Core REJIT syscall: verify + JIT + atomic swap
  - Permission check, serialization, error handling
  - UAPI: add BPF_PROG_REJIT command and rejit union member
  - No poke/trampoline/dispatcher support yet

Patch 3/8: bpf: REJIT support for tail_call poke_tab
  - bpf_prog_rejit_update_poke_tab()
  - bpf_prog_rejit_poke_target_phase()
  - bpf_prog_rejit_untrack_tmp_pokes()

Patch 4/8: bpf: REJIT support for trampolines and freplace
  - bpf_tramp_user reverse index
  - bpf_trampoline_refresh_prog()
  - Link/unlink tracking

Patch 5/8: bpf: REJIT support for struct_ops and XDP dispatcher
  - bpf_struct_ops_refresh_prog() with instruction-boundary scan
  - bpf_dispatcher_refresh_prog()
  - bpf_prog_refresh_xdp()

Patch 6/8: bpf: add kinsn (kernel instruction) extension mechanism
  - UAPI: BPF_PSEUDO_KINSN_CALL, BPF_PSEUDO_KINSN_SIDECAR
  - Verifier: proof sequence lowering/restoration
  - kinsn_desc_tab, add_kinsn_call, find_kinsn_desc
  - kinsn registration (replace kallsyms_lookup_name with proper API)

Patch 7/8: bpf/x86: JIT emit support for kinsn descriptors
  - emit_kinsn_desc_call() with scratch buffer
  - Sidecar skip in MOV_K handler
  - emit_movabs_imm64() refactor

Patch 8/8: bpf/arm64: JIT emit support for kinsn descriptors
  - emit_kinsn_desc_call_arm64()
  - Sidecar skip in build_insn()
```

Each patch should be independently compilable and testable. The existing `get_original_poc` selftest covers Patch 1. Additional selftests should cover REJIT (Patch 2-5) and kinsn (Patch 6-8).

---

## 8. Summary Statistics

| Category | Count |
|----------|-------|
| Previous Critical issues fixed | 2/2 |
| Previous Major issues fixed | 4/5 (ARM64 cast partial) |
| New Critical issues | 1 |
| New Major issues | 7 |
| New Minor issues | 12 |
| New Nit issues | 4 |
| Total lines changed (working tree vs master) | ~1764+ / ~32- |
| Core kernel LOC (excl tests/tools) | ~1580 net |
| Files modified | 21 |
| Uncommitted changes pending | 7 files |
