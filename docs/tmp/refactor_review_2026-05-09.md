# bpfopt-suite Refactor Review 2026-05-09

## Verdict

**fail**: build/test pass, and I did not find a bytecode-equivalence regression in the four migrated passes, but the current tree violates explicit review blockers: semantic `BpfInsn` constructors/wrappers, hardcoded BTF IDs, same-name libbpf const aliases, and two dead `RewritePlan` APIs.

## Scope Confirmed

Command required by review prompt:

```text
$ git diff --stat HEAD -- bpfopt/crates/bpfopt/src daemon/src
31 files changed, 1029 insertions(+), 970 deletions(-)
```

All changed files are under `bpfopt/crates/bpfopt/src`; `daemon/src` has no diff in this scope.

## LOC Sanity

Required `wc -l` after current refactor:

```text
   263 bpfopt/crates/bpfopt/src/passes/rewrite.rs
   346 bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs
   550 bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs
   833 bpfopt/crates/bpfopt/src/passes/const_prop.rs
   673 bpfopt/crates/bpfopt/src/passes/wide_mem.rs
   491 bpfopt/crates/bpfopt/src/insn.rs
   148 bpfopt/crates/bpfopt/src/test_helpers.rs
  1012 bpfopt/crates/bpfopt/src/pass.rs
  4316 total
```

Measured against `HEAD`:

| File | HEAD | current | delta |
|---|---:|---:|---:|
| `passes/rewrite.rs` | 0 | 263 | +263 |
| `passes/skb_load_bytes.rs` | 398 | 346 | -52 |
| `passes/bounds_check_merge.rs` | 589 | 550 | -39 |
| `passes/const_prop.rs` | 863 | 833 | -30 |
| `passes/wide_mem.rs` | 719 | 673 | -46 |
| `insn.rs` | 462 | 491 | +29 |
| `test_helpers.rs` | 227 | 148 | -79 |
| `pass.rs` | 1026 | 1012 | -14 |
| required wc subset total | 4284 | 4316 | +32 |

Report comparison:

| Report | Claim | Current measurement |
|---|---:|---:|
| #268 target scope | `32766 -> 32719 (-47)` | plausible for Round A-only baseline; current combined diff is later |
| #269 P0 target | `5341 -> 5447 (+106)` from post-Round-A baseline | current final after values match, but against `HEAD` the same P0 target is `5363 -> 5447 (+84)` |
| #269 shortstat | `31 files changed, 766 insertions(+), 970 deletions(-)` | stale/incomplete now; current `git diff HEAD` is `1029 insertions(+), 970 deletions(-)` because `rewrite.rs` is included as added |

## Build & Test

Commands run exactly with `--locked` and no benchmark:

| Workspace | Command | Result |
|---|---|---|
| `bpfopt/` | `cargo build --workspace --locked` | pass, `Finished dev profile ... in 0.06s` |
| `bpfopt/` | `cargo test --workspace --locked 2>&1 \| tail -40` | pass |
| `bpfopt/` | `cargo test --workspace --locked --lib 2>&1 \| tail -20` | pass, `332 passed` |
| `daemon/` | `cargo build --workspace --locked` | pass, `Finished dev profile ... in 0.07s` |
| `daemon/` | `cargo test --workspace --locked 2>&1 \| tail -20` | pass, `25 passed` |

Fresh count: `bpfopt lib 332 + bpfopt bin 12 + cli_pipeline 12 + daemon 25 = 381`, same as the prior reports.

## Round A Violations: BpfInsn Constructors

Policy judgment: these are semantic instruction constructors over libbpf UAPI constants/`struct bpf_insn`. `libbpf-sys` exposes `bpf_insn` and constants, but not Rust-callable C macro constructors. So there is no one-call libbpf-rs replacement; direct replacement means either raw `libbpf_sys::bpf_insn` literals plus bitfield setters, or retaining only a raw `BpfInsn::new` gateway. Under the user's "helper/prog def must directly use libbpf" rule, all semantic constructors are wrappers and should not be expanded.

Call counts are from `rg 'BpfInsn::<name>(' bpfopt/crates/bpfopt/src daemon/src`.

| Constructor | Calls | Direct libbpf replacement? | Strict raw-literal LOC impact estimate |
|---|---:|---|---:|
| `mov64_reg` | 168 | yes: `bpf_insn` with `BPF_ALU64|BPF_MOV|BPF_X` | about +650 LOC |
| `mov64_imm` | 274 | yes: `BPF_ALU64|BPF_MOV|BPF_K` | about +1050 LOC |
| `mov32_reg` **#268** | 11 | yes: `BPF_ALU|BPF_MOV|BPF_X` | about +40 LOC |
| `mov32_imm` | 43 | yes: `BPF_ALU|BPF_MOV|BPF_K` | about +160 LOC |
| `jump_imm` **#268** | 2 | yes: `BPF_JMP|op|BPF_K` | about +5 LOC |
| `jump_reg` **#268** | 2 | yes: `BPF_JMP|op|BPF_X` | about +5 LOC |
| `ja` | 46 | yes: `BPF_JMP|BPF_JA` | about +175 LOC |
| `exit` **#268** | 308 | yes: `BPF_JMP|BPF_EXIT` | about +1200 LOC |
| `ldx_mem` | 176 | yes: `BPF_LDX|size|BPF_MEM` | about +680 LOC |
| `stx_mem` | 23 | yes: `BPF_STX|size|BPF_MEM` | about +85 LOC |
| `st_mem` **#268** | 56 | yes: `BPF_ST|size|BPF_MEM` | about +220 LOC |
| `alu64_imm` | 130 | yes: `BPF_ALU64|op|BPF_K` | about +500 LOC |
| `alu64_reg` | 56 | yes: `BPF_ALU64|op|BPF_X` | about +220 LOC |
| `nop` | 19 | yes: `BPF_JMP|BPF_JA, off=0` | about +70 LOC |
| `call_kfunc` | 2 | yes: `BPF_JMP|BPF_CALL`, src `BPF_PSEUDO_KFUNC_CALL` | about +5 LOC |
| `call_kfunc_with_off` | 0 external, 1 internal | yes | delete or inline into the two `call_kfunc` users |
| `call_kinsn_with_off` | 3 | yes: src `BPF_PSEUDO_KINSN_CALL` | about +10 LOC |
| `kinsn_sidecar` | 3 | yes, but payload field packing is project-specific | about +20 LOC |
| `helper_call` **#268** | 97 | yes: `BPF_JMP|BPF_CALL`, src 0 | about +380 LOC |

If the team accepts `BpfInsn::new(...)` as the only raw gateway, deleting semantic constructors would likely reduce about 70-90 LOC with small call-site churn. If "direct libbpf" means raw `libbpf_sys::bpf_insn` at every call site, LOC explodes by roughly 5k+ lines and is not a code-size improvement. The cleaner compromise is: keep only raw ABI conversion/accessors, delete semantic constructors, and use `libbpf_sys::*` constants directly at construction sites.

Specific #268 blocker: `BpfInsn::{exit, helper_call, mov32_reg, st_mem, jump_imm, jump_reg}` are exactly the helper wrappers the user rejected. They should be removed or the whole `BpfInsn` constructor policy must be explicitly re-approved.

## Hardcoded BTF IDs

Required grep:

```text
bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:8:const MEMCPY_BTF_ID: i32 = 4101;
bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:9:const MEMSET_BTF_ID: i32 = 4102;
```

No other `BTF_ID` numeric constants or `4101/4102` hits were found in `bpfopt/crates/bpfopt/src daemon/src`.

Why this violates the rule: the tests encode fake BTF IDs as global constants, then thread them through expected emissions and assertions at lines 81, 102, 310-311, 369, 483-484, 508, 518.

Replacement: remove the file-level `MEMCPY_BTF_ID`/`MEMSET_BTF_ID`; make expected builders and `bulk_call_count` assertions read `ctx.kinsn_registry.memcpy_bulk_btf_id` / `ctx.kinsn_registry.memset_bulk_btf_id` from the same `PassContext` passed into `BulkMemoryPass`. A fixture can return `(ctx, memcpy_id, memset_id)` if the tests need local names, but the IDs should be registry-provided, not hardcoded global BTF constants.

## Same-Name Const Alias Audit

Required grep found same-name libbpf const aliases in source and tests. Classification:

- `A`: same name, same type, zero-increment alias. Delete and use `libbpf_sys::...` directly.
- `B`: type narrowing/conversion alias, e.g. `u8 = libbpf_sys::* as u8`. Temporarily defensible while `BpfInsn` uses `u8`, but still a wrapper if the strict direct-libbpf rule is applied.
- `C`: wrapper function or crate-local alias, not a direct libbpf const alias.
- `D`: 0-caller dead API.

### A: delete

Production:

```text
bpfopt/crates/bpfopt/src/mock_maps.rs:28:BPF_MAP_TYPE_PERCPU_ARRAY
bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:14,16,18,20,22,24,26:BPF_PROG_TYPE_*
bpfopt/crates/bpfopt/src/passes/wide_mem.rs:423,425,427,429,431,433,435:BPF_PROG_TYPE_*
bpfopt/crates/bpfopt/src/passes/prefetch.rs:27,28,29,30,31,32,33:BPF_PROG_TYPE_*
bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:13,14:BPF_PROG_TYPE_*
bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:9,10,11,13,14,15,16,18:BPF_MAP_TYPE_*
```

Tests:

```text
bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:465,466,467,468,469:BPF_MAP_TYPE_*
bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:19,20,21,22,23,24,25:BPF_MAP_TYPE_*
bpfopt/crates/bpfopt/src/passes/bounds_check_merge_tests.rs:8,9,10,11:BPF_PROG_TYPE_*
bpfopt/crates/bpfopt/src/passes/skb_load_bytes_tests.rs:11,12,13:BPF_PROG_TYPE_*
bpfopt/crates/bpfopt/src/passes/mod_tests.rs:9,10:BPF_MAP_TYPE_*
```

Disposition: delete all A aliases. This directly covers the user's example `const BPF_PROG_TYPE_SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;` and the same pattern appears 7x each in `bounds_check_merge.rs` and `wide_mem.rs`, plus 7x in `prefetch.rs`.

### B: keep only if the type-conversion policy is accepted

```text
bpfopt/crates/bpfopt/src/insn.rs:9-16,19-22,25-26,29-43,46-47,50-61,63-64,67-68,71,73,76,80-90
bpfopt/crates/bpfopt/src/pass.rs:433,434
bpfopt/crates/bpfopt/src/passes/mod_tests.rs:11
bpfopt/crates/bpfopt/src/passes/prefetch.rs:20,21
bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:11
bpfopt/crates/bpfopt/src/passes/skb_load_bytes_tests.rs:8,9
```

Disposition: `BPF_LD: u8 = libbpf_sys::BPF_LD as u8` fits the user's B category. Keep only as a temporary ABI-convenience layer; if "direct libbpf" is strict, inline the `as u8`/`as i32` at actual uses or change internal opcode fields to match libbpf types.

### C: wrappers / middle layers

```text
bpfopt/crates/bpfopt/src/insn.rs:305-427 semantic BpfInsn constructors
bpfopt/crates/bpfopt/src/test_helpers.rs:35,38,41,44 add64_imm/jeq_imm/jne_imm/jgt_reg
bpfopt/crates/bpfopt/src/passes/skb_load_bytes_tests.rs:18 helper_call
bpfopt/crates/bpfopt/src/passes/map_inline.rs:21-24 crate::insn pseudo-map aliases
bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:19-20 crate::insn pseudo-map aliases
```

Disposition: delete or inline. The remaining local `helper_call` in `skb_load_bytes_tests.rs:18` is especially inconsistent with Round A's stated duplicate-helper cleanup.

### D: zero-caller dead

```text
bpfopt/crates/bpfopt/src/insn.rs:87:BPF_REG_7
bpfopt/crates/bpfopt/src/insn.rs:88:BPF_REG_8
bpfopt/crates/bpfopt/src/passes/rewrite.rs:42:RewritePlan::insert_before
bpfopt/crates/bpfopt/src/passes/rewrite.rs:56:RewritePlan::add_internal_branch
```

Disposition: delete now. `RewritePlan::insertions` and `internal_branch_patches` are only live because these dead APIs read them inside `commit`/`validate`; without callers they are speculative infrastructure and violate "No Dead Code".

## RewriteBuilder / RewritePlan Design Review

The shared `RewritePlan::commit` path is directionally reasonable for replace/delete passes:

- validates instruction-boundary alignment via `instruction_boundaries`
- rejects overlapping replace/delete ranges
- preserves LD_IMM64 two-slot copying
- builds `addr_map`
- delegates surviving branch fixup to `fixup_all_branches`
- optionally remaps BTF metadata
- remaps annotations

Bytecode-equivalence judgment for current migrations:

| Pass | Assessment |
|---|---|
| `skb_load_bytes_spec` | Equivalent for one-instruction call replacements. `emit_replacement` order is preserved; `jgt_reg` became `BpfInsn::jump_reg(BPF_JGT, ...)`, same encoding. |
| `bounds_check_merge` | Equivalent for current one-slot replace + delete usage. Cleanup annotation remap now happens in two steps instead of composed map; `remap_annotations` semantics make that equivalent. |
| `const_prop` | Equivalent for current ALU/ALU64 replacements. Replacements are one-slot originals; BTF remap remains enabled. |
| `wide_mem` | Equivalent for byte-ladder range to one wide load. `map_replacement_range` maps all old slots to replacement pc when `new_len=1`, matching old behavior. |

Issues in the design:

1. P0 dead API: `insert_before` and `add_internal_branch` have no callers. Delete them until a pass actually needs insertions/internal patching.
2. P1 error style: `replace_range` and `delete_range` use `assert!`/`expect`. For a CLI bytecode tool, invalid rewrite plans should return `anyhow::Result` with friendly stderr, not panic.
3. P2 naming: there is no `RewriteBuilder` type, only `RewritePlan`. The #269 report title says RewriteBuilder; either rename consistently or update docs.

P1 migration candidates:

| Priority | Pass | Reason |
|---|---|---|
| P1 | `bulk_memory` | emits kinsn replacement ranges and already uses shared branch/BTF utilities; high LOC payoff |
| P1 | `extract` | simple kinsn replacement pattern; likely fits replace-range |
| P1 | `endian` | similar replace-range structure with kinsn metadata remap |
| P1 | `cond_select` | structured replacement plus internal branches, but only after internal branch API has a real caller |
| P2 | `rotate` / `ccmp` | smaller kinsn passes; migrate after API cleanup |
| P2 | `prefetch` | more side-input/profile handling; useful but not first |
| P2/P3 | `map_inline` | complex map/value/control-flow rewrite; leave until plan API is proven |

Do not migrate `branch_flip` in this batch; it is block reorder/PGO-specific, not a simple replace-range pass.

## Test Quality Review

No test functions were added or removed in the touched high-churn files. `git diff HEAD -- *_tests.rs | rg '^[-+]fn |^[-+]#\[test\]'` returned no test-name changes for `map_inline_tests.rs`, `bulk_memory_tests.rs`, `const_prop_tests.rs`, `bounds_check_merge_tests.rs`, `skb_load_bytes_tests.rs`, and `wide_mem_tests.rs`.

Therefore the `map_inline_tests.rs +409`, `bulk_memory_tests.rs +15`, and `const_prop_tests.rs +16` line movement is rename/mechanical constructor churn, not new coverage. The existing named tests I inspected are real bug detectors: verifier-state absence, map-in-map chains, const-prop oracle safety, branch fixup, packet pointer gates, BTF pointer gates, and negative pattern matrices.

Delete recommendation by Unit Test Quality: **delete no test function from this diff on quality grounds**. The cleanup should target helper/constructor churn, not test coverage. The low-signal part is not a specific test; it is the repeated instruction-constructor spelling.

## CLAUDE.md Compliance

| Rule | Status | Evidence / recommendation |
|---|---|---|
| Fail-fast: no dead code | violated | `rewrite.rs:42 insert_before`, `rewrite.rs:56 add_internal_branch`, `insn.rs:87-88 BPF_REG_7/8` have 0 callers. Delete. |
| Fail-fast: no silenced errors | pass in grep scope | `rg '#[allow(dead_code)]|unwrap_or_default|let _ = ' ...` returned no matches; extra `.ok()` grep also returned no matches. |
| Use libbpf-rs/libbpf-sys, don't re-wrap | violated | semantic `BpfInsn` constructors and same-name prog/map/helper aliases wrap libbpf UAPI. |
| Daemon syscall boundary | pass | `bpfopt` has no `libc::syscall/SYS_bpf`; direct `SYS_bpf` appears only in `daemon/src/syscall.rs`, which is allowed. |
| No CLI cross-dependencies | pass | no path dependency between `bpfopt` and `bpfrejit-daemon`; daemon composes via `Command::new("bpfopt")`. |
| Unit Test Quality | pass-with-noise | no new test names; existing tests have bug-detection purpose, but constructor rename churn bloats tests. |

## Bug List

### P0

1. `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:8-9` hardcodes fake BTF IDs `4101/4102`. Remove globals and use `ctx.kinsn_registry.*_btf_id` throughout expected emission/assertions.
2. `bpfopt/crates/bpfopt/src/insn.rs:305-427` semantic instruction constructors violate the user's direct-libbpf rejection, especially #268's `exit/helper_call/mov32_reg/st_mem/jump_imm/jump_reg`. Decide a strict construction policy and delete wrappers accordingly.
3. Same-name same-type libbpf aliases listed in A above violate the explicit zero-increment const rule. Delete and use `libbpf_sys::...` directly.
4. `bpfopt/crates/bpfopt/src/passes/rewrite.rs:42,56` dead public plan methods plus their backing fields are speculative. Delete until a pass uses them.

### P1

1. `bpfopt/crates/bpfopt/src/passes/skb_load_bytes_tests.rs:18` retains a local `helper_call` wrapper after Round A claimed duplicate helper cleanup. Inline or replace according to the final constructor policy.
2. `bpfopt/crates/bpfopt/src/insn.rs:87-88` `BPF_REG_7/8` are public aliases with 0 callers. Delete under no-dead-code.
3. `bpfopt/crates/bpfopt/src/passes/rewrite.rs:33-54` panics on duplicate/overflow planning via `assert!`/`expect`. Prefer `anyhow::Result` so CLI failures stay friendly.
4. `bpfopt/crates/bpfopt/src/passes/prefetch.rs:20-33`, `bounds_check_merge.rs:14-26`, `wide_mem.rs:423-435`, `skb_load_bytes.rs:11-14` use local aliases for libbpf helper/prog types. Delete with the A/B alias cleanup.

### P2

1. `bpfopt/crates/bpfopt/src/passes/rewrite.rs` is named `RewritePlan`, while report/task language says `RewriteBuilder`. Align naming.
2. `PacketCtxLayout`/packet prog-type matching is duplicated across multiple passes. Consider a tiny shared utility only after removing zero-increment aliases; do not add another abstraction before that cleanup.
3. Existing `BpfInsn` wrapper still wraps `libbpf_sys::bpf_insn`. If the strict interpretation is "program bytecode should be `Vec<libbpf_sys::bpf_insn>`", this is a larger design change and should be a separate tracked migration.

## Next Steps

1. P0 cleanup, expected net negative LOC: delete hardcoded BTF constants, A aliases, dead `RewritePlan` insertion/internal-branch support, `BPF_REG_7/8`, and the local `helper_call`.
2. P0 policy decision: either approve a single raw `BpfInsn::new` gateway, or migrate all instruction storage/construction to direct `libbpf_sys::bpf_insn`. The latter is strict but will increase LOC substantially.
3. P1 after policy: remove semantic `BpfInsn` constructors or confine them to tests only if explicitly allowed.
4. P1 migrate next passes to `RewritePlan` only after dead APIs are removed; start with `bulk_memory`, `extract`, and `endian`.
5. Re-run `cargo build/test --workspace --locked` for both workspaces after cleanup; no benchmark needed for these source hygiene fixes.
