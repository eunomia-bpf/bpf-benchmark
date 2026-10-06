# Phase 3 BBProgram Final Code Review - 2026-05-12

## 1. Executive Verdict

**Verdict: NEEDS-WORK**

The Phase 3 migration has made real progress: build/test/clippy/fmt all pass, `PassManager` is gone, `bbprogram_helpers.rs` is gone, map-inline no longer owns JSON IO, matcher APIs exist, and the source has dropped from the Phase 3 baseline of 18,994 production LOC to 17,612 production LOC.

It is **not converged** against the cumulative design contract. The remaining blockers are architectural, not mechanical: production pass code still reaches inside opaque identity types, `prefetch` still performs pass-local PC/slot conversion through `site_current_pc`, raw verifier state still leaks through `PassContext`, and at least one dead public API remains.

## 2. Per-Goal Findings A-N

### A. Identity opacity - **VIOLATED, must-fix**

Satisfied foundation: the identity fields are no longer public API fields. `BlockId(pub(crate) usize)`, `FrameId(pub(crate) usize)`, and `InsnSite { pub(crate) block, pub(crate) idx }` are crate-visible only in `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:20`, `:22`, and `:24-26`.

Violation: pass bodies still use those fields directly.

- `branch_flip` does `BlockId` arithmetic and reconstructs IDs: `left.0 + 1 == right.0` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:234`, range checks at `:242` and `:298`, and `BlockId(block)` reconstruction at `:250` and `:307`.
- `bounds_check_merge` reads `InsnSite.block` directly at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:433-438` and `:451`.
- `prefetch` reads `anchor.block`, `target.block`, and `ptr_def.block` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:452`, `:481-489`, and `:511`.
- `endian` reads `InsnSite.idx` directly at `bpfopt/crates/bpfopt/src/passes/endian.rs:349-355` and `:377-379`.
- `extract` reads `InsnSite.idx` directly at `bpfopt/crates/bpfopt/src/passes/extract.rs:132-133`.

Concrete fix: replace pass-side identity reads with BBProgram queries or local body-view positions. For example, use `prog.site_block(site)`, `prog.site_frame(site)`, and body-view membership checks such as `body.sites.last() == Some(&start)` instead of `start.idx + 1`. For branch ranges, derive positions from `prog.block_ids()` or add generic BBProgram order queries that do not expose `BlockId.0`.

### B. Verifier opacity - **PARTIAL, must-fix API leak**

Satisfied: raw verifier structs are crate-visible or stricter: `VerifierInsnKind`, `Tnum`, `ScalarRange`, `VerifierInsn`, `RegState`, and `StackState` are `pub(crate)` in `bpfopt/crates/bpfopt/src/verifier_log.rs:17`, `:30`, `:35`, `:46`, `:56`, and `:96`. `VerifierOracle` is a `pub(crate)` alias in `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:17`. `PrefetchProfile` and `PmuRecord` are crate-visible in `bpfopt/crates/bpfopt/src/pass.rs:180` and `:186`.

Satisfied query surface: passes use typed BBProgram queries such as `reg_known_constant`, `reg_kind`, `reg_known_stack_bytes`, `site_is_dead_code`, `branch_taken_rate`, `branch_miss_rate`, `site_hotness`, and `prefetch_hint` in `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:308-357` and `:380-406`. Current pass use is typed: `map_inline` uses `reg_known_stack_bytes` and consumes `reg_kind` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:373-387`; `branch_flip` uses profile queries at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:95-113`; `prefetch` uses `prefetch_hint` and `site_hotness` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:185-204`.

Violation: raw verifier states are still exposed on `PassContext`. `PassContext.verifier_states: Arc<[VerifierInsn]>` is `pub(crate)` at `bpfopt/crates/bpfopt/src/pass.rs:451`, and `VerifierInsn` / `VerifierInsnKind` are re-exported from `pass.rs:21`. Because passes are in the same crate, this still gives pass bodies a raw verifier escape hatch even if they do not currently use it.

Concrete fix: make `verifier_states` private and move raw verifier ownership into the lift boundary, or add a private lift-only accessor outside the pass module surface. Keep raw verifier exports under `#[cfg(test)]` or in analysis-only internals.

### C. No PC in pass bodies - **VIOLATED, critical**

Satisfied intended sink: `finalize_pass_reports` is a free function and converts report sites to PCs at `bpfopt/crates/bpfopt/src/pass.rs:713-720`.

Violation: `prefetch` still converts sites to current PCs from pass code through `pf_site_start_slot`, which calls `prog.site_current_pc(site)` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:540-542`. It also rebuilds block/frame slot bounds in pass code at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:550-577`.

Concrete fix: rewrite prefetch insertion-window selection around site-order/body-view APIs instead of current PCs. If slot distance is genuinely needed, make it a generic BBProgram query that returns relative logical distance without exposing PC conversion to pass code.

### D. Single mutation path - **SATISFIED**

The old public `replace_range(block, Range<usize>, ...)` API is absent. The in-block edit path is `replace_range_at(site, len, ...)` in `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:49-80`; the internal helper is private at `:82-136`.

CFG mutations are through the approved BBProgram APIs: `delete_cond_branch` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:138`, `replace_terminator` at `:166`, `replace_terminator_at_site` at `:177`, `permute_blocks` at `:205`, `merge_linear_chain` at `:250`, `delete_unreachable_blocks` at `:357`, `split_block` at `:380`, and `replace_diamond_with_insns` at `:436`.

Pass usage is consistent: examples include `rotate` using `replace_range_at` at `bpfopt/crates/bpfopt/src/passes/rotate.rs:127-130`, `ccmp` using `merge_linear_chain` and `replace_terminator` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:258-290`, and `cond_select` using `replace_diamond_with_insns` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:188-189`.

### E. No pass-specific helpers on BBProgram - **SATISFIED**

The pass-specific helpers are in pass files, not on `BBProgram`: `pf_*` helpers live in `bpfopt/crates/bpfopt/src/passes/prefetch.rs:437-544`, `bf_*` helpers live in `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:222-293`, and `bcm_sites_between` lives in `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:428-462`.

The BBProgram APIs used across passes are generic, for example `all_sites` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:180`, `branch_target_entry_sites` at `:518`, and `scan_block_starts` at `:826`.

### F. No JSON IO in passes - **SATISFIED**

JSON IO is lifted into `main.rs`: the private `read_json_file` helper is at `bpfopt/crates/bpfopt/src/main.rs:1803-1807`. Map-inline CLI side input is attached before pass execution in `main.rs` at `bpfopt/crates/bpfopt/src/main.rs:771-787`.

`map_inline` rejects pass-local profile/JSON arguments at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:44-49` and consumes typed side input via `prog.map_inline_side_input()` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:58-61`. The BBProgram side-input getter is at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:566-570`.

### G. Helper distribution - **SATISFIED**

`bbprogram_helpers.rs` is absent from the production file list. Helper content is distributed as designed:

- `PacketCtxLayout`, `PacketCtxLayoutScope`, and `packet_ctx_layout` are in `bpfopt/crates/bpfopt/src/insn.rs:87-96`.
- `SimpleRegValue` and `advance_reg_state` are in `bpfopt/crates/bpfopt/src/insn.rs:633-644`.
- `all_sites` and `branch_target_entry_sites` are BBProgram methods at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:180` and `:518`.
- `read_json_file` is private in `bpfopt/crates/bpfopt/src/main.rs:1803-1807`.

### H. No escape patterns - **PARTIAL, must-fix**

The enumerated hard patterns were not present in production source: no `.ok()?`, `.ok().flatten()`, `let _ = ...`, `unwrap_or_default`, `unwrap_or(0)`, `#[allow(dead_code)]`, `#[ignore]`, `todo!()`, or `unimplemented!()` in production files. The earlier `_r2_kind` / `_r2_bounds` typed-query discards are gone; `map_inline` consumes the `reg_kind` result in a match at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:373-387`.

New finding: `map_inline` still silences fallible stack-pointer resolution by converting errors to `None`:

- `resolve_stack_store_slot` drops `resolve_stack_pointer_to_stack_inner` errors at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2708-2716`.
- It also drops `i16` conversion failure at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2717-2721`.
- `resolve_stack_load_slot` repeats the same pattern at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2728-2739`.

Concrete fix: return `anyhow::Result<Option<...>>` from these helpers. Return `Ok(None)` only for structural non-matches; propagate resolution and overflow errors.

### I. PassManager removal - **SATISFIED**

No production `PassManager` struct remains. The runner path is `run_pass_once` at `bpfopt/crates/bpfopt/src/pass.rs:691-711`, and report finalization is the free function at `bpfopt/crates/bpfopt/src/pass.rs:713-730`.

Stale test naming still mentions PassManager (`test_pass_manager_invalidates_verifier_states_after_transform` in test output), but that is test text, not production structure.

### J. `bbprogram_helpers.rs` absent - **SATISFIED**

The audited production source list contains no `bbprogram_helpers.rs`, no re-export in `analysis/mod.rs`, and no helper module under `passes/helpers`. The analysis module declaration list is only `bbprogram`, `bbprogram_api`, `bbprogram_btf`, `bbprogram_lift`, `bbprogram_lower`, and `bbprogram_use_def` in `bpfopt/crates/bpfopt/src/analysis/mod.rs:4-9`.

### K. Matcher API post-M - **SATISFIED with identity caveats**

The matcher API exists: `block_body_view` is implemented at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:816-824`, and `scan_block_starts` is implemented at `:826-897`. The required BpfInsn predicates exist at `bpfopt/crates/bpfopt/src/insn.rs:592-608`.

Adoption evidence:

- `rotate` uses `scan_block_starts` at `bpfopt/crates/bpfopt/src/passes/rotate.rs:76-79`.
- `wide_mem` uses `scan_block_starts` at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:214-217`.
- `extract` uses `scan_block_starts` at `bpfopt/crates/bpfopt/src/passes/extract.rs:70-78`.
- `endian` uses `scan_block_starts` at `bpfopt/crates/bpfopt/src/passes/endian.rs:292-295`.
- `bulk_memory` uses the matcher body view for stateful in-block scanning at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:232-287`.

Cond-select and ccmp remain CFG matchers, as intended: `scan_cond_select_sites` walks CFG blocks at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:299-328`, and `scan_ccmp_sites` does the same at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:381-395`.

Caveat: the in-block matcher migration did not remove all identity leaks; `extract` and `endian` still use `start.idx` in cross-block skip helpers, cited under Goal A.

### L. No dead code - **PARTIAL, must-fix**

`cargo clippy --release --all-targets -- -D dead_code -D warnings` passes. That catches private dead code and many test-target issues.

New finding: `MapInfoAnalysis` appears to be dead public API. It is declared at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:101`, re-exported at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:10`, and re-exported again at `bpfopt/crates/bpfopt/src/passes/mod.rs:33`. The production search found no real caller or value construction.

Concrete fix: delete `MapInfoAnalysis` and the two re-exports, unless there is an external API consumer not represented in this workspace. The crate is documented as workspace-internal in `bpfopt/crates/bpfopt/src/lib.rs:4-6`, so external compatibility is not a strong reason to keep it.

### M. No new files - **SATISFIED**

No forbidden files are present: no `passes/utilities.rs`, no `passes/helpers/`, and no `analysis/bbprogram_internal.rs`. The production file list in section 8 is exactly the expected analysis/framework/pass organization.

### N. Single-file source organization - **SATISFIED**

The organization matches the requested shape:

- `analysis/`: `bbprogram`, `api`, `btf`, `lift`, `lower`, `use_def`, `mod`.
- framework: `insn.rs`, `pass.rs`, `verifier_log.rs`, `main.rs`, `lib.rs`.
- `passes/`: 15 pass files plus `map_inline/map_info.rs`.

The source file list in section 8 is complete for the production audit scope.

## 3. Confirmed-Fixed List from Prior Reviews

Confirmed fixed from R2:

- JSON IO moved out of `map_inline`: `map_inline` rejects pass-local args at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:44-49`; JSON reads are in `bpfopt/crates/bpfopt/src/main.rs:1803-1807`.
- `MapInlineHintAnchor::Pc` removed from pass-side hint representation: pass-side anchor variants are only `Site` and `MapName` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:16-19`; PC hint specs are resolved at lift time in `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:246-256`.
- Map-inline references are site-keyed, not slot/PC keyed: `MapReference` stores `site: InsnSite` at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:75-82`, and lookup is by site at `:93-98`.
- Map-inline no longer reads raw `ldimm64_second_slots`; the accessor is `ldimm64_second_slot` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:563-565`, used by passes such as `const_prop` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:488-495`.
- `rep_admit_kinsn_site_window` returns `KinsnAdmissionWindow` with typed accessors `start_site()` / `end_site()` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:65-76` and `:1446-1480`.
- BTF reset lifecycle was removed; BTF lowering remaps original PCs to current PCs via `old_pc_to_current_pc` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:130-140` and lowering at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:55-101`.

Confirmed fixed from R3/R4 and N cleanup:

- Build/fmt regressions are gone: all gates in section 5 exit 0.
- `PassManager` is removed in production; see Goal I.
- `bbprogram_helpers.rs` is gone; see Goal J.
- Matcher APIs exist and are used by the linear kinsn passes; see Goal K.
- `map_inline` is materially simplified: current LOC is 2,847 for `bpfopt/crates/bpfopt/src/passes/map_inline.rs`, and it uses `reg_known_stack_bytes` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:373`.
- Pass-specific helpers were moved out of BBProgram; see Goal E.

Not fully fixed:

- Raw verifier state still leaks through `PassContext.verifier_states` at `bpfopt/crates/bpfopt/src/pass.rs:451`.
- Identity opacity regressed or remained incomplete in non-map-inline passes, listed under Goal A.
- PC conversion is not single-point because `prefetch` calls `site_current_pc`, listed under Goal C.

## 4. New Architectural Smells / Leaks

1. **New finding, critical:** `prefetch` reintroduced a pass-local PC model by calling `site_current_pc` and computing block/frame slot bounds itself (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:540-577`).
2. **New finding, must-fix:** identity fields are still used in several non-map-inline passes (`branch_flip`, `bounds_check_merge`, `prefetch`, `endian`, `extract`).
3. **New finding, must-fix:** raw verifier states remain reachable from pass code through `PassContext.verifier_states` (`bpfopt/crates/bpfopt/src/pass.rs:451`).
4. **New finding, must-fix:** `map_inline` converts fallible stack-pointer resolution failures to `None` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2708-2739`).
5. **New finding, must-fix:** dead public `MapInfoAnalysis` remains exported without a production caller (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:101`, `bpfopt/crates/bpfopt/src/passes/mod.rs:33`).

## 5. Gate Results

All gates were run from `/home/yunwei37/workspace/bpf-benchmark/bpfopt`.

| Gate | Command | Exit code | Result |
|---|---|---:|---|
| build | `cargo build --release` | 0 | Passed |
| test | `cargo test --release` | 0 | Passed: 190 lib tests, 13 main tests, 1 roundtrip test, 12 CLI tests, 0 doc tests |
| clippy | `cargo clippy --release --all-targets -- -D dead_code -D warnings` | 0 | Passed |
| fmt | `cargo fmt --all --check` | 0 | Passed |

## 6. LOC Accounting

Production source total:

`find bpfopt/crates/bpfopt/src -name '*.rs' -not -name '*_tests.rs' -not -name 'test_helpers.rs' -not -name 'pass_tests.rs' -print0 | xargs -0 wc -l | tail -1`

Result: **17,612 total**. Compared with Phase 3 baseline 18,994, this is **-1,382 LOC** or about **-7.3%**.

Framework and analysis:

| File | LOC |
|---|---:|
| `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` | 1,756 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` | 848 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs` | 140 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs` | 560 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs` | 253 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs` | 303 |
| `bpfopt/crates/bpfopt/src/analysis/mod.rs` | 21 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 825 |
| `bpfopt/crates/bpfopt/src/main.rs` | 1,905 |
| `bpfopt/crates/bpfopt/src/insn.rs` | 836 |
| `bpfopt/crates/bpfopt/src/verifier_log.rs` | 853 |
| `bpfopt/crates/bpfopt/src/lib.rs` | 17 |
| Subtotal | 8,317 |

Passes:

| File | LOC |
|---|---:|
| `bpfopt/crates/bpfopt/src/passes/mod.rs` | 178 |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | 2,847 |
| `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` | 262 |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs` | 502 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs` | 753 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem.rs` | 381 |
| `bpfopt/crates/bpfopt/src/passes/cond_select.rs` | 677 |
| `bpfopt/crates/bpfopt/src/passes/ccmp.rs` | 530 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs` | 596 |
| `bpfopt/crates/bpfopt/src/passes/branch_flip.rs` | 581 |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs` | 642 |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs` | 296 |
| `bpfopt/crates/bpfopt/src/passes/rotate.rs` | 370 |
| `bpfopt/crates/bpfopt/src/passes/endian.rs` | 408 |
| `bpfopt/crates/bpfopt/src/passes/extract.rs` | 158 |
| `bpfopt/crates/bpfopt/src/passes/dce.rs` | 92 |
| `bpfopt/crates/bpfopt/src/passes/noop.rs` | 22 |
| Subtotal | 9,295 |

## 7. Top Remaining Issues

1. **critical - PC leak in `prefetch`:** `prefetch` calls `prog.site_current_pc(site)` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:540-542`. Fix by using site-order/window APIs and keeping PC conversion in `finalize_pass_reports`.
2. **must-fix - `BlockId` arithmetic in `branch_flip`:** direct `.0` reads and `BlockId(block)` construction occur at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:231-250` and `:293-307`. Fix with generic block-order queries or local position lookup over `prog.block_ids()`.
3. **must-fix - `InsnSite` field reads in passes:** `bounds_check_merge`, `prefetch`, `endian`, and `extract` read `.block` / `.idx` directly. Fix with `site_block`, `site_frame`, body-view membership checks, or dedicated generic BBProgram helpers.
4. **must-fix - raw verifier escape hatch:** `PassContext.verifier_states` remains `pub(crate)` at `bpfopt/crates/bpfopt/src/pass.rs:451`. Make it private and lift-only.
5. **must-fix - silenced stack resolution errors in `map_inline`:** `Err(_) => return None` occurs at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2715`, `:2720`, and `:2735`. Return `Result<Option<_>>` and propagate real failures.
6. **must-fix - dead public API:** remove `MapInfoAnalysis` and re-exports at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:101`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:10`, and `bpfopt/crates/bpfopt/src/passes/mod.rs:33`.
7. **nice-to-have - bulk matcher consistency:** `bulk_memory` uses `block_body_view` but still carries a hand-advanced `idx` scanner at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:232-287`. This is not a correctness failure, but it is the least uniform of the five linear matcher migrations.
8. **nice-to-have - public crate surface remains broad:** `lib.rs` still exports `analysis`, `insn`, `pass`, `passes`, and `verifier_log` as public modules at `bpfopt/crates/bpfopt/src/lib.rs:8-12`. The crate is workspace-internal, but the broad public surface makes dead public API harder to catch.

## 8. Files Audited

Production files audited end to end:

- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs`
- `bpfopt/crates/bpfopt/src/analysis/mod.rs`
- `bpfopt/crates/bpfopt/src/insn.rs`
- `bpfopt/crates/bpfopt/src/lib.rs`
- `bpfopt/crates/bpfopt/src/main.rs`
- `bpfopt/crates/bpfopt/src/pass.rs`
- `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs`
- `bpfopt/crates/bpfopt/src/passes/branch_flip.rs`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs`
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs`
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
- `bpfopt/crates/bpfopt/src/passes/dce.rs`
- `bpfopt/crates/bpfopt/src/passes/endian.rs`
- `bpfopt/crates/bpfopt/src/passes/extract.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`
- `bpfopt/crates/bpfopt/src/passes/mod.rs`
- `bpfopt/crates/bpfopt/src/passes/noop.rs`
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `bpfopt/crates/bpfopt/src/passes/rotate.rs`
- `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs`
- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs`
- `bpfopt/crates/bpfopt/src/verifier_log.rs`

Test files were not reviewed for production-contract violations except through the requested gates.

## 9. Honest Paper-Readiness Assessment

For OSDI '26, this is not paper-ready as the Phase 3 BBProgram migration boundary. The implementation may be functionally green under current tests, but the architectural contract is still porous in ways that matter for maintainability and review credibility: pass-side identity arithmetic, pass-side PC conversion, raw verifier state exposure, and dead public API all contradict the stated migration goals.

The remaining fixes are scoped and tractable. Once the top issues in section 7 are fixed and re-gated, the codebase can plausibly be called converged for the Phase 3 API boundary. Until then, the correct verdict is **NEEDS-WORK**, not **CONVERGED**.
