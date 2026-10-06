# BpfReJIT Kernel Code Review v3 - 2026-03-24

Reviewer: Claude Opus 4.6 (automated, upstream BPF subsystem reviewer standard)
Base: `master` (stock kernel, merge tag x86-urgent-2026-03-08)
Head: `cb82fae35` (committed HEAD on branch `rejit-v2`)
Working tree: clean (no uncommitted changes)

---

## 1. v2 Review Issue Fix Status

| # | v2 Severity | Issue | v3 Status | Evidence |
|---|-------------|-------|-----------|----------|
| 1 | **Critical** | `lower_kinsn_proof_regions()` control flow bug -- only processes first kinsn call due to broken indentation/early return | **FIXED** | Lines 4018-4095: for loop body is properly indented, `return 0` is after the loop closes at line 4093. All kinsn calls are processed. |
| 2 | Major | `skip_full_check:` indentation broken (extra tab) | **FIXED** | Line 26730-26740: consistent single-tab indentation after label, matching surrounding code. |
| 3 | Major | `validate_ldimm64_layout()` debug scaffolding (~12 full-program scans per verification) | **FIXED** | No calls to `validate_ldimm64_layout` remain anywhere in verifier.c. |
| 4 | Major | `kinsn_regions` fixed 256-element array (4KB) in committed HEAD | **FIXED** | `bpf_verifier.h` line 857: `struct bpf_kinsn_region *kinsn_regions` (pointer) + `kinsn_region_cap` (dynamic). Allocation in `alloc_kinsn_proof_regions()` uses `kvcalloc`. |
| 5 | Major | `kfunc_desc_tab`/`kfunc_btf_tab` dynamic allocation refactor mixed with kinsn feature | **STILL MIXED** | The dynamic allocation (`ensure_desc_capacity`, `struct bpf_kfunc_desc *descs` pointer + `desc_cap`) is committed together with the kinsn feature in a single commit. Should be a separate preparatory patch for upstream. |
| 6 | Major | `kallsyms_lookup_name()` usage for kinsn resolution | **NOT FIXED** | Line 3670: `addr = kallsyms_lookup_name(sym_name)` still present in `fetch_kinsn_desc_meta()`. |
| 7 | Major | `bpf_trampoline_refresh_prog()` uses wrong poke type for freplace | **FIXED** | Lines 938-942: now uses `bpf_trampoline_update(tr, true)` which does a full trampoline rebuild instead of text-poke hacks. Correct and safe. |
| 8 | Major | TOCTOU in `poke_target_phase` scan | **MITIGATED** | Lines 3329-3336: added a detailed comment explaining why the lockless pre-check is benign. Not a code fix, but acceptable. |

**Score: 6/8 fixed, 1 mitigated with comment, 1 still open (`kallsyms_lookup_name`).**

Also verified v1 review fixes that were uncommitted in v2:
- `dst_reg` masked to 4 bits in `bpf_kinsn_sidecar_payload()`: COMMITTED (line 991)
- `kinsn_tab` swap in `bpf_prog_rejit_swap()`: COMMITTED (line 3278)
- E2BIG check before swap: COMMITTED (line 3623-3625)
- Scratch buffer for x86 emit: COMMITTED (line 584)
- Struct_ops instruction-boundary scan: COMMITTED (uses `insn_init`/`insn_get_length`)
- ARM64 const-cast removed: COMMITTED (line 1629 uses `ctx->prog` directly)
- `KF_KINSN` dead code removed: CONFIRMED (btf.h diff is only blank line removal)
- `api_version`/`flags` dead fields removed from `struct bpf_kinsn`: CONFIRMED
- `tnum.h` include removed: CONFIRMED
- `__maybe_unused` removed from kinsn functions: CONFIRMED

---

## 2. New Issues Found

### 2.1 Major

#### [M1] `kallsyms_lookup_name()` still present -- upstream blocker
- **File**: `kernel/bpf/verifier.c`, line 3670
- **Issue**: `kallsyms_lookup_name(sym_name)` is used to resolve kinsn descriptor addresses from BTF symbol names. Since commit `0bd476e6c671` upstream explicitly discourages new uses of `kallsyms_lookup_name` in loadable modules. BPF maintainers (Alexei, Andrii) have repeatedly rejected patches using it.
- **Fix**: Replace with a registration-based mechanism: kinsn modules call `register_bpf_kinsn()` at init, verifier looks up by BTF type ID from a global table. This aligns with the `register_btf_kfunc_id_set()` pattern.
- **Upstream risk**: HIGH. This is the single biggest upstream acceptance blocker remaining.

#### [M2] `bpf_prog_has_kinsn_call()` does O(N) full program scan -- should use `kinsn_tab`
- **File**: `kernel/bpf/verifier.c`, lines 3811-3822
- **Issue**: This function scans every instruction in the program to find a kinsn call. It is called from `fixup_call_args()` which runs before `bpf_prog_jit_attempt_done()` frees the tab. The equivalent `bpf_prog_has_kfunc_call()` just checks `!!prog->aux->kfunc_tab`. Same pattern should be used here.
- **Fix**: `return !!prog->aux->kinsn_tab;`
- **Impact**: Wastes O(insn_cnt) on every non-JIT fallback path.

#### [M3] `count_kinsn_calls()` duplicates work already done in `add_subprog_and_kfunc()`
- **File**: `kernel/bpf/verifier.c`, lines 3993-4005
- **Issue**: `alloc_kinsn_proof_regions()` calls `count_kinsn_calls()` which does another O(N) scan. But `add_subprog_and_kfunc()` already iterated all instructions and found every kinsn call (calling `add_kinsn_call`). The count is `env->prog->aux->kinsn_tab->nr_descs`.
- **Fix**: Use `tab->nr_descs` (though this is an upper bound since dedup happens -- but the current `count_kinsn_calls` counts instruction-level occurrences, not unique descriptors). Actually, instruction-level count could exceed descriptor count. A cleaner fix: store `env->kinsn_call_cnt` during `add_subprog_and_kfunc`.
- **Impact**: Minor performance, but upstream reviewers dislike unnecessary scans.

#### [M4] `kfunc_desc_tab` dynamic allocation refactor should be a separate patch
- **File**: `kernel/bpf/verifier.c`, lines 3196-3233
- **Issue**: The conversion of `kfunc_desc_tab.descs` from a fixed `[MAX_KFUNC_DESCS]` array to a dynamically allocated array with `ensure_desc_capacity()` is a significant refactor of pre-existing infrastructure. It changes memory allocation behavior for ALL BPF programs, even those without kinsn. This must be split into a separate preparatory patch to be reviewed and tested independently.
- **Risk**: Medium. Mixing unrelated infrastructure changes with feature code is a common upstream review objection.

#### [M5] `bpf_struct_ops_refresh_prog()` uses `bpf_arch_text_poke` with wrong argument semantics
- **File**: `kernel/bpf/bpf_struct_ops.c`, lines 1550-1554
- **Issue**: The call is:
  ```c
  err = bpf_arch_text_poke(call_site, BPF_MOD_CALL,
                           BPF_MOD_CALL,
                           (void *)old_bpf_func,
                           (void *)prog->bpf_func);
  ```
  The second argument (`old_t`) and third argument (`new_t`) are both `BPF_MOD_CALL`. Looking at the x86 implementation of `bpf_arch_text_poke`, `old_t` tells the function what instruction currently exists at `ip` (CALL, JMP, or NOP), and `new_t` tells it what to write. So `BPF_MOD_CALL, BPF_MOD_CALL` means "the current instruction at `call_site` is a CALL to `old_addr`, replace it with a CALL to `new_addr`." This is semantically correct for struct_ops trampolines which embed a direct CALL to `bpf_func`.

  **REVISED**: After re-examining the x86 implementation of `bpf_arch_text_poke()`, this is actually **correct**. The function verifies the old instruction matches, then patches to the new target. The struct_ops trampoline contains a `CALL bpf_func` instruction, and we're patching it from `CALL old_bpf_func` to `CALL new_bpf_func`. The `find_call_site()` correctly locates the CALL opcode.

  **Downgrade to Nit**: The code is correct.

#### [M5 REVISED - not a bug] -- removed from Major list.

### 2.2 Minor

#### [m1] `bpf_kinsn_sidecar_payload()` silently truncates fields without validation
- **File**: `include/linux/bpf.h`, lines 989-993
- **Issue**: The payload packing uses 4 bits for `dst_reg`, 16 bits for `off`, 32 bits for `imm` = 52 bits total. The masking `(insn->dst_reg & 0xf)` is correct but there's no compile-time assertion that `BPF_KINSN_SIDECAR_PAYLOAD_BITS == 52`. If the encoding changes, the constant and the actual packing could silently diverge.
- **Fix**: Either add `BUILD_BUG_ON(BPF_KINSN_SIDECAR_PAYLOAD_BITS != 52)` or remove the unused constant.

#### [m2] `bpf_prog_rejit_swap()` copies too many fields individually
- **File**: `kernel/bpf/syscall.c`, lines 3216-3290
- **Issue**: The swap function copies ~30 individual fields between `prog` and `tmp`. Many are boolean flags (`gpl_compatible`, `cb_access`, `blinding_requested`, etc.) that could be handled with a single `memcpy` of the flag region. This is fragile: any new field added to `bpf_prog` or `bpf_prog_aux` must also be added here, or it silently becomes stale after REJIT.
- **Fix**: Add a comment listing which fields intentionally skip swap (e.g., `refcnt`, `type`, `expected_attach_type`, `ops`). Consider a more structured approach.

#### [m3] `BPF_PSEUDO_KINSN_SIDECAR=3` and `BPF_PSEUDO_KINSN_CALL=4` -- SIDECAR is not in `src_reg` of a CALL
- **File**: `include/uapi/linux/bpf.h`, lines 1383-1395
- **Issue**: The comment says "when `bpf_mov->src_reg == BPF_PSEUDO_KINSN_SIDECAR`" but the values share the `src_reg` namespace with `BPF_PSEUDO_KFUNC_CALL=2`. SIDECAR (3) is used in a MOV instruction, KINSN_CALL (4) in a CALL instruction. They are in different instruction types so the values 3 and 4 cannot collide with KFUNC_CALL=2 in practice. But the sequential numbering suggests they are in the same namespace, which is misleading.
- **Fix**: Add a comment clarifying that SIDECAR uses `src_reg` of ALU64|MOV|K, not of JMP|CALL.

#### [m4] `orig_prog_insns` padding in `struct bpf_prog_info`
- **File**: `include/uapi/linux/bpf.h`, lines 6719-6720
- **Issue**: `orig_prog_len` is `__u32` followed by `orig_prog_insns` which is `__aligned_u64`. There are 4 bytes of implicit padding between them. This is normal for UAPI structs but explicit padding (or reordering) is preferred upstream.
- **Fix**: Either swap the order (`orig_prog_insns` first, then `orig_prog_len`), or add `__u32 __pad_orig;` between them.

#### [m5] `BPF_KINSN_SIDECAR_PAYLOAD_BITS` constant defined but never used
- **File**: `include/linux/bpf.h`, line 981
- **Issue**: `#define BPF_KINSN_SIDECAR_PAYLOAD_BITS 52` is defined but never referenced in any code.
- **Fix**: Remove it or use it in a BUILD_BUG_ON.

#### [m6] `bpf_prog_rejit_poke_target_phase()` is O(N_maps * max_entries)
- **File**: `kernel/bpf/syscall.c`, lines 3302-3349
- **Issue**: Scans ALL maps to find PROG_ARRAY entries containing this prog. On large systems this could be slow. The comment documents the design decision but a reverse index would be preferred for upstream.
- **Fix**: Add reverse index from prog to PROG_ARRAY slots. Non-blocking for initial submission.

### 2.3 Nit

#### [n1] Enhanced `pr_err` in x86 JIT is unrelated to REJIT
- **File**: `arch/x86/net/bpf_jit_comp.c`, line 2804
- **Issue**: Changed `pr_err("bpf_jit: unknown opcode %02x\n", ...)` to include insn details. Useful but unrelated to BpfReJIT. Should be a separate cleanup patch.

#### [n2] `scripts/Makefile.btf` changes are fragile against upstream evolution
- **File**: `scripts/Makefile.btf`, lines 5-18
- **Issue**: The `extmod-btf-global-var-y` variable appends `,global_var` to the `--btf_features` flag only when building external modules. This is a one-line functional change but depends on the exact format of the upstream `--btf_features` string. If upstream adds features or reformats, this will break silently.
- **Fix**: Acceptable for now, but document the dependency.

#### [n3] `test_run.c` removal of `bpf_prog_change_xdp` changes XDP test behavior
- **File**: `net/bpf/test_run.c`, lines 1390-1414
- **Issue**: Removing `bpf_prog_change_xdp(NULL, prog)` / `bpf_prog_change_xdp(prog, NULL)` means XDP test_run no longer registers/unregisters with the dispatcher for repeated runs. This changes observable behavior: programs use indirect calls instead of dispatcher direct calls during `bpf_prog_test_run_xdp`.
- **Fix**: Add a comment explaining the rationale, or keep the original behavior.

#### [n4] `jit_disasm_helpers.c` `normalize_movabs_imm_hex()` is unrelated to BpfReJIT
- **File**: `tools/testing/selftests/bpf/jit_disasm_helpers.c`
- **Issue**: Test infrastructure improvement. Should be a separate patch.

#### [n5] `btf.h` blank line removal
- **File**: `include/linux/btf.h`
- **Issue**: Only change is removing a blank line between `KF_IMPLICIT_ARGS` and the `__bpf_kfunc` comment. This is cosmetic and should not be mixed with the feature patch.

---

## 3. Unnecessary Changes Checklist

| File | Change | Necessary for REJIT/kinsn? | Recommendation |
|------|--------|:---:|---|
| `arch/x86/net/bpf_jit_comp.c` line 2804 | Enhanced pr_err message for unknown opcode | NO | Move to separate cleanup patch |
| `include/linux/btf.h` | Remove blank line | NO | Drop (zero value, creates noise) |
| `net/bpf/test_run.c` | Remove `bpf_prog_change_xdp` calls | UNCLEAR | Needs justification comment or revert |
| `scripts/Makefile.btf` | Add `global_var` for external modules | YES (for kinsn module BTF) | Keep, but document |
| `tools/testing/selftests/bpf/jit_disasm_helpers.c` | `normalize_movabs_imm_hex()` + `#include <stdlib.h>` | NO (test infra) | Move to separate patch |
| `include/linux/bpf.h` line 981 | `BPF_KINSN_SIDECAR_PAYLOAD_BITS` constant | NO (unused) | Delete |
| `kernel/bpf/core.c` lines 1010-1013 | Comment on `bpf_arch_text_invalidate` | TANGENTIAL | Move to separate cleanup or drop |
| `kernel/bpf/verifier.c` | `kfunc_desc_tab`/`kfunc_btf_tab` dynamic allocation refactor | INDIRECTLY (shared `ensure_desc_capacity`) | Split to preparatory patch |

**Removable changes**: ~40-50 lines can be removed or split out (pr_err enhancement, blank line, unused constant, test helper, core.c comment, kfunc refactor).

---

## 4. Code Quantity Analysis and Reduction Suggestions

### Current Breakdown (core kernel, excluding tools/tests)

| Component | File(s) | Net Lines | Purpose |
|-----------|---------|-----------|---------|
| REJIT syscall + swap | `syscall.c` | 520 | Core REJIT functionality |
| Verifier kinsn support | `verifier.c` | 550 | Proof lowering, kinsn desc management, do_misc_fixups |
| Internal headers | `bpf.h`, `bpf_verifier.h`, `filter.h`, `btf.h` | 87 | Struct definitions, inline helpers |
| UAPI | `uapi/linux/bpf.h` | 23 | REJIT command, kinsn constants, prog_info fields |
| Struct_ops refresh | `bpf_struct_ops.c` | 89 | find_call_site + text_poke |
| Trampoline refresh | `trampoline.c` | 45 | Reverse index + rebuild |
| x86 JIT | `bpf_jit_comp.c` (x86) | 44 | emit_kinsn_desc_call, sidecar skip, movabs refactor |
| ARM64 JIT | `bpf_jit_comp.c` (arm64) | 32 | emit_kinsn_desc_call_arm64, sidecar skip |
| Dispatcher refresh | `dispatcher.c` | 15 | bpf_dispatcher_refresh_prog |
| Core + disasm + filter | `core.c`, `disasm.c`, `filter.c` | 15 | Init, ksym fix, XDP refresh |
| Makefile.btf | `Makefile.btf` | 2 | External module BTF |
| test_run.c | `test_run.c` | -4 | XDP dispatcher removal |
| **TOTAL** | **17 files** | **~1418** | |

### Reduction Opportunities

| # | Opportunity | Est. Savings | Difficulty |
|---|-------------|-------------|------------|
| 1 | **Split kfunc_desc_tab dynamic allocation to separate patch** -- doesn't reduce total LOC but reduces the REJIT patch size by ~60 lines | 60 lines | Easy |
| 2 | **Replace `bpf_prog_has_kinsn_call()` with `!!kinsn_tab`** | 10 lines | Trivial |
| 3 | **Replace `count_kinsn_calls()` with counter from `add_subprog_and_kfunc`** | 12 lines | Easy |
| 4 | **Consolidate `bpf_prog_rejit_swap()` flag copying** into a struct-level memcpy with explicit skip list | ~20 lines | Medium (risky) |
| 5 | **Remove unused `BPF_KINSN_SIDECAR_PAYLOAD_BITS`** | 1 line | Trivial |
| 6 | **Remove unrelated pr_err enhancement** | 3 lines | Trivial |
| 7 | **Remove btf.h blank line change** | 1 line | Trivial |
| 8 | **Move `emit_movabs_imm64` refactor to separate cleanup patch** | 0 (keeps LOC but removes from REJIT series) | Easy |
| 9 | **Remove `bpf_prog_refresh_xdp` / `bpf_dispatcher_refresh_prog`** if XDP REJIT isn't tested | 25 lines | Medium (reduces functionality) |
| 10 | **Simplify `bpf_prog_rejit_poke_target_phase` comments** | 10 lines | Trivial |

### Realistic Target

The current ~1418 net lines in core kernel cannot realistically be reduced to <1000 without removing functionality. The breakdown:
- **REJIT syscall** (520 lines): This is the minimum for safe prog swap with poke_tab, trampoline, struct_ops, and dispatcher support. The swap function alone is ~75 lines of individual field copies, which is inherent complexity.
- **Verifier kinsn** (550 lines): ~200 lines for kinsn_desc_tab management (mirrors kfunc_desc_tab), ~200 lines for proof lowering/restoration, ~150 lines for validation and misc_fixups integration. The kfunc_desc_tab dynamic allocation (~60 lines) should be split out.
- **Refresh paths** (185 lines total): struct_ops (89), trampoline (45), dispatcher (15), JIT (76). These are architecturally necessary.

**After applying easy reductions**: ~1350 net lines (from ~1418).
**After splitting kfunc refactor to prep patch**: REJIT-specific ~1290 net lines.
**Theoretical minimum** (removing all dispatcher/XDP, simplifying comments): ~1200 lines.

The plan doc claims "~550 lines." This is only achievable by counting just the core mechanism (REJIT syscall command + minimal kinsn proof lowering) without the refresh paths for trampoline/struct_ops/dispatcher/poke_tab. If upstream review demands reducing scope, the refresh paths could be deferred to follow-up patches.

---

## 5. Upstream Acceptability Assessment

### Verdict: **Close to ready, 2 blocking issues remain**

### Blocking Issues

| # | Severity | Issue | Fix Effort |
|---|----------|-------|------------|
| 1 | Major | `kallsyms_lookup_name()` in `fetch_kinsn_desc_meta()` -- upstream won't accept | Medium (need registration API) |
| 2 | Major | `kfunc_desc_tab` dynamic allocation mixed with feature -- must split | Easy (git rebase -i) |

### Non-blocking but Should Fix Before Submission

| # | Severity | Issue |
|---|----------|-------|
| 3 | Minor | `bpf_prog_has_kinsn_call()` does O(N) scan, should use `!!kinsn_tab` |
| 4 | Minor | `count_kinsn_calls()` duplicates work |
| 5 | Minor | `BPF_KINSN_SIDECAR_PAYLOAD_BITS` unused constant |
| 6 | Minor | `orig_prog_insns` padding in UAPI struct |
| 7 | Minor | `bpf_prog_rejit_swap()` is fragile against new fields |
| 8 | Minor | `bpf_prog_rejit_poke_target_phase()` O(N_maps) scan |
| 9 | Nit | Unrelated changes mixed in (pr_err, btf.h blank line, jit_disasm_helpers) |
| 10 | Nit | test_run.c behavior change needs justification |

### Strengths (improved from v2)

1. **All v1 Critical/Major issues fixed and committed** -- no uncommitted changes remaining.
2. **`lower_kinsn_proof_regions()` control flow is correct** -- processes all kinsn calls via backward iteration.
3. **`bpf_trampoline_refresh_prog()` uses full rebuild** -- much safer than text-poke hacks.
4. **TOCTOU race documented** with clear comment explaining benign nature.
5. **Dead code cleaned up**: `KF_KINSN`, `api_version`, `flags`, `tnum.h`, `__maybe_unused` all removed.
6. **`skip_full_check` indentation fixed**.
7. **Debug scaffolding (`validate_ldimm64_layout`) removed**.
8. **Security model is sound**: `CAP_BPF + CAP_SYS_ADMIN`, full verifier re-verification, scratch buffer for JIT emit, instruction-boundary scanning for struct_ops.
9. **Concurrency model is correct**: lock ordering is safe (`rejit_mutex` -> `tr->mutex`, `rejit_mutex` -> `poke_mutex`), `smp_wmb()` + `WRITE_ONCE()` for bpf_func publication.
10. **Error paths are thorough**: `free_tmp_noref`, `free_tmp_sec`, `free_tmp` cleanly handle all resources.

---

## 6. Suggested Patch Series Split

For upstream submission, split into **4 patches** (reduced from v2's 8 to minimize review overhead):

```
Patch 1/4: bpf: convert kfunc/kfunc_btf desc tables to dynamic allocation

  Pure refactor of existing kfunc_desc_tab and kfunc_btf_tab:
  - Remove MAX_KFUNC_DESCS/MAX_KFUNC_BTFS limits
  - Add ensure_desc_capacity() helper for doubling growth
  - Change bpf_free_kfunc_btf_tab() and add bpf_free_kfunc_desc_tab()
  - No functional change for existing programs

  Files: kernel/bpf/verifier.c, kernel/bpf/core.c, kernel/bpf/syscall.c,
         include/linux/bpf.h
  ~60 lines net


Patch 2/4: bpf: add BPF_PROG_GET_ORIGINAL and BPF_PROG_REJIT syscall commands

  Core REJIT functionality:
  - Store orig_insns at load time, expose via bpf_prog_get_info_by_fd
  - BPF_PROG_REJIT: verify + JIT + atomic swap with rejit_mutex
  - Poke_tab update for tail_call direct jumps
  - Target-side poke_target_phase for PROG_ARRAY reverse patching
  - Trampoline reverse index + rebuild via bpf_trampoline_update()
  - Struct_ops refresh via find_call_site + bpf_arch_text_poke
  - Dispatcher + XDP refresh
  - UAPI: BPF_PROG_REJIT command, rejit union, orig_prog_{len,insns}

  Files: kernel/bpf/syscall.c, kernel/bpf/trampoline.c,
         kernel/bpf/bpf_struct_ops.c, kernel/bpf/dispatcher.c,
         kernel/bpf/core.c, net/core/filter.c,
         include/linux/bpf.h, include/uapi/linux/bpf.h,
         include/linux/filter.h, tools/include/uapi/linux/bpf.h
  ~750 lines net

  Selftest: get_original_poc.c


Patch 3/4: bpf: add kinsn (kernel instruction) extension mechanism

  Kinsn verifier and JIT integration:
  - UAPI: BPF_PSEUDO_KINSN_CALL, BPF_PSEUDO_KINSN_SIDECAR
  - kinsn_desc_tab management (add, find, free, sort)
  - Proof sequence lowering (lower_kinsn_proof_regions) and restoration
  - validate_kinsn_proof_seq with JMP32|JA support
  - Sidecar handling in backtrack_insn, do_check_insn
  - do_misc_fixups kinsn lowering for non-JIT fallback
  - fixup_call_args kinsn-requires-JIT check
  - disasm.c kinsn-descriptor string

  Files: kernel/bpf/verifier.c, kernel/bpf/disasm.c,
         include/linux/bpf.h, include/linux/bpf_verifier.h,
         include/uapi/linux/bpf.h, include/linux/filter.h
  ~450 lines net

  NOTE: Replace kallsyms_lookup_name with registration API before submission.


Patch 4/4: bpf/{x86,arm64}: JIT emit support for kinsn descriptors

  Architecture-specific JIT code:
  - x86: emit_kinsn_desc_call() with scratch buffer, sidecar skip
  - x86: emit_movabs_imm64() refactor (used by kinsn indirectly)
  - ARM64: emit_kinsn_desc_call_arm64(), sidecar skip
  - scripts/Makefile.btf: global_var for external module BTF

  Files: arch/x86/net/bpf_jit_comp.c, arch/arm64/net/bpf_jit_comp.c,
         scripts/Makefile.btf
  ~90 lines net
```

**Unrelated changes to split out separately:**
- x86 JIT `pr_err` enhancement (3 lines)
- `btf.h` blank line removal (1 line)
- `test_run.c` XDP dispatcher removal (needs justification or revert)
- `jit_disasm_helpers.c` `normalize_movabs_imm_hex()` (test infra, 30 lines)

---

## 7. Summary Statistics

| Category | Count |
|----------|-------|
| v2 Critical issues fixed | 1/1 |
| v2 Major issues fixed | 5/7 (kallsyms + kfunc split remain) |
| New Major issues | 4 (M1-M4, M1 = carryover) |
| New Minor issues | 6 |
| New Nit issues | 5 |
| Core kernel lines (net) | ~1418 |
| Test/tools lines (net) | ~141 |
| Total files changed | 21 |
| Uncommitted changes | 0 (all committed) |
| Estimated reducible lines | ~70-130 (via splitting, dedup, cleanup) |
| Minimum realistic LOC after cleanup | ~1290 (REJIT-specific, after kfunc split) |
