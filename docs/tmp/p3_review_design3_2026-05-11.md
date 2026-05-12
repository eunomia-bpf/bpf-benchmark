# Phase 3 BBProgram Migration Review 3

Verdict: NOT-CONVERGED.

Snapshot note: the working tree changed while this review was running. The gate results and line references below are from the final snapshot I reviewed: `bpfopt/crates/bpfopt/src/passes/map_inline.rs` was 3935 LOC, and the requested non-test production LOC command returned 18940 total.

## Top Issues

1. must-fix: current `map_inline.rs` does not compile after the hint-type simplification. `ResolvedMapInlineHint` and `ResolvedHintMap` are the only resolved-hint types defined at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:524-534`, but the file still references removed or never-defined types such as `BoundaryResolvedInlineHint` and `ResolvedInlineHints` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:684-689`, `ResolvedHintAnchor` and `BoundaryResolvedInlineHint` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:731-750`, `ResolvedInlineHint` / `ResolvedInlineValue` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1068-1112`, `ResolvedInlineHint` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2042-2048`, and `ResolvedInlineHints` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2395-2398`. Suggested fix: finish one coherent rename. Either restore the removed type family, or update every call site to the new `ResolvedMapInlineHint` / `ResolvedHintMap` shape and remove the invalid `Default` derive on `ResolvedMapInlineHint`.
2. must-fix: `cargo build --release`, `cargo test --release`, and `cargo clippy --release --all-targets -- -D dead_code -D warnings` all fail with the compile errors above. This blocks all functional validation, including the BTF tests requested below.
3. must-fix: `cargo fmt --all --check` fails. Representative diffs are at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:978-990`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1736`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2163`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2588`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3179-3188`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3795-3808`. Suggested fix: run `cargo fmt --all` after the compile fix.
4. nice-to-have: `map_inline.rs` still owns ordered traversal/window logic that feels like BBProgram should provide if Phase 3 wants to eliminate pass-local program-order reasoning. Examples: `sites_after_site_in_frame` / `sites_before_site_in_frame_rev` / `advance_site_queue_to` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:156-208`, whole-program scanning in `lookup_pattern_removal_is_safe` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3048-3095`, and whole-program scanning in `null_check_removal_window_is_trivial` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3795-3854`. Suggested fix: if this is a Phase 3 requirement, move these to named BBProgram queries so pass code asks semantic questions.
5. nice-to-have: raw verifier state storage is still crate-visible on `PassContext` at `bpfopt/crates/bpfopt/src/pass.rs:465-466`. Production passes no longer name raw verifier types, but this remains a broad crate-internal escape hatch. Suggested fix: make it private to `pass.rs` and expose only the lift-boundary accessor needed by `bbprogram_lift`.
6. nice-to-have: `docs/tmp/p3_fix_mapinline_simplify_2026-05-11.md` is still missing. The LOC data shows simplification happened, but there is no fix report artifact for it.

## A. Identity Opacity

- `BlockId.0`, `FrameId.0`, `InsnSite.block`, and `InsnSite.idx` are `pub(crate)` in the identity definitions at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:20-28`.
- I sampled production pass files `map_inline.rs`, `const_prop.rs`, `wide_mem.rs`, `branch_flip.rs`, and `prefetch.rs` and did not find direct destructuring of `InsnSite` fields. The field-like hits I did find were pass-local structs, not `InsnSite`: `BranchTerm.block` is a local `BlockId` field at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:136-143`, used at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:398-445`; `CondBranchShape.block` is a local field at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:94-101`, used at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:357-390`.

## B. Verifier Surface

- Raw verifier declarations are crate-visible or stricter: `VerifierInsnKind` at `bpfopt/crates/bpfopt/src/verifier_log.rs:15-22`, `VerifierValueWidth` at `bpfopt/crates/bpfopt/src/verifier_log.rs:23-28`, `Tnum` at `bpfopt/crates/bpfopt/src/verifier_log.rs:29-33`, `ScalarRange` at `bpfopt/crates/bpfopt/src/verifier_log.rs:34-44`, `VerifierInsn` at `bpfopt/crates/bpfopt/src/verifier_log.rs:45-54`, `RegState` at `bpfopt/crates/bpfopt/src/verifier_log.rs:55-65`, and `StackState` at `bpfopt/crates/bpfopt/src/verifier_log.rs:95-99`. `VerifierOracle` is re-exported crate-visible at `bpfopt/crates/bpfopt/src/analysis/mod.rs:14`.
- Production passes sampled do not name raw verifier types directly. They use typed BBProgram queries: `map_inline` uses `reg_known_stack_bytes` and `reg_kind` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:390-400`; `const_prop` uses `reg_known_constant` and `reg_kind` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:323-365`; `wide_mem` uses `reg_kind` at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:407-415`; `branch_flip` uses `site_hotness`, `branch_miss_rate`, and `branch_taken_rate` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:94-108`; `prefetch` uses `prefetch_hint` and `site_hotness` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:181-200`.
- BBProgram exposes the requested typed queries: `reg_known_constant`, `reg_known_map_ptr`, `reg_proven_bounds`, `reg_kind`, `reg_known_stack_bytes`, `site_is_dead_code`, `branch_taken_rate`, `branch_miss_rate`, `site_hotness`, and `prefetch_hint` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:311-437`.

## C. PC Arithmetic

- I found no `.0 + N` or `block.0 + 1` arithmetic in production pass code. Block id `.0` arithmetic remains inside BBProgram/lowering internals, not in passes.
- There is still local `idx + N` arithmetic in pattern matchers. Examples: `rotate` block-local instruction slices at `bpfopt/crates/bpfopt/src/passes/rotate.rs:153-160` and `bpfopt/crates/bpfopt/src/passes/rotate.rs:252-260`; `bulk_memory` block-local cursors at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:334-366`; `wide_mem` local windows at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:59-84` and `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:126-203`; `ccmp` chain indexing at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:358`. I did not classify these as program-wide PC identity leaks; they operate on local copied instruction slices or block-local chains.
- I did not find pass-local struct fields named `slot`, `position`, `pos_in_prog`, `prog_offset`, `pc_load`, `target_slot`, `allowed_slot`, `expected_slot`, or `prog_idx` with type `usize`. The remaining `offset: usize` evidence is the semantic function parameter `read_scalar_from_value_at(value, offset, size)` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2945`, not a pass-local PC field.
- The only `BTreeMap<usize, _>` hit in production passes is `resolved_by_index` at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:203`, keyed by map ordinal/index during map resolution, not by program PC.

## D. Mutation Single Path

- `replace_range(block, Range<usize>, ...)` is gone from `bbprogram_api.rs`. The replacement entry point is `replace_range_at(site, len, ...)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:49-80`, with private implementation underneath.
- Production pass replacement calls use `replace_range_at`, for example `const_prop` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:94`, `map_inline` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1880` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1896`, and the paired terminator-site replacements at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1878` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1894`. Terminator/block-level structural APIs remain for CFG transforms.
- I found no production pass calls to `attach_side_inputs`, `invalidate_oracle`, `rebuild_use_def_after_mutation`, `attach_profile_data`, `attach_prefetch_profile_from_original_pcs`, `attach_profile_from_annotations`, or `reset_btf_to_current_pcs`. The lifecycle methods are BBProgram/pass-manager side: `invalidate_oracle` and `rebuild_use_def_after_mutation` are at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:816-823`; `PassManager` calls `invalidate_oracle` after mutation at `bpfopt/crates/bpfopt/src/pass.rs:721-723`.
- Direct reads of BBProgram internals from pass code appear fixed. For example, the `ldimm64_second_slots` map is private at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:52`, and BBProgram exposes `ldimm64_second_slot` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:638-639`.

## E. Report PC Conversion

- `PassManager::finalize_reports` is the only production boundary I found that calls `site_current_pc`: `bpfopt/crates/bpfopt/src/pass.rs:728-746`.
- `main.rs` routes skip/diagnostic reports through `PassManager::finalize_reports` at `bpfopt/crates/bpfopt/src/main.rs:1836-1848` and `bpfopt/crates/bpfopt/src/main.rs:1862-1874`; it does not call `site_current_pc` directly.
- PC/original-PC conversion helpers remain crate-internal on BBProgram at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:572-588`. The lift boundary uses `original_pc_to_site` to resolve CLI/map-inline hint PCs at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:246-256`.

## F. Helper Distribution

- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs` does not exist. The only helper-named source file under `bpfopt/crates/bpfopt/src` is test-only `bpfopt/crates/bpfopt/src/test_helpers.rs`.
- `analysis/mod.rs` declares BBProgram modules only and has no helper module or helper glob re-export at `bpfopt/crates/bpfopt/src/analysis/mod.rs:4-18`.
- Helper content landed in the requested places: `packet_ctx_layout` is in `bpfopt/crates/bpfopt/src/insn.rs:86-125`; `SimpleRegValue` and `advance_reg_state` are in `bpfopt/crates/bpfopt/src/insn.rs:644-704`; `all_sites` and `branch_target_entry_sites` are in `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:149-151` and `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:589-609`; `read_json_file` is private in `bpfopt/crates/bpfopt/src/main.rs:1803-1807`.

## G. Escape Patterns

- I found no matches in production pass code for `.ok()?`, `.ok().flatten()`, `let _ = ...`, `unwrap_or_default`, `unwrap_or(0)`, `#[allow(dead_code)]`, `#[ignore]`, `todo!()`, or `unimplemented!()`.
- I found no production pass-code mentions of `fallback`, `legacy`, `compat`, or `bridge`.
- I found no underscore-prefixed bindings holding typed BBProgram query results. The previous `_r2_kind` / `_r2_bounds` issue is fixed; `map_inline` now consumes `reg_known_stack_bytes` and `reg_kind` directly at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:390-400`.

## H. map_inline-Specific

- `MapInlineHintAnchor::Pc` does not exist in the pass-internal type. `MapInlineHintAnchor` has only `Site(InsnSite)` and `MapName(String)` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:16-20`. The external CLI/spec type still accepts `Pc(usize)` at `bpfopt/crates/bpfopt/src/pass.rs:207-210`, and lift resolves it to a site at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:246-256`.
- `map_inline.rs` no longer performs CLI side-input parsing; `MapInlinePass::from_cli_args` rejects pass args at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:44-50`. CLI side input loading is now in `main.rs` at `bpfopt/crates/bpfopt/src/main.rs:771-786`, and JSON/map snapshot reads are in `main.rs` at `bpfopt/crates/bpfopt/src/main.rs:1123-1202`.
- `MapReference.slot` and `MapBinding.pc_load` are gone. `MapReference` is site-keyed at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:73-82`, and `MapBinding` is site-keyed at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:105-113`.
- I found no `lookup_call_site_at_pc`, no `current_pc += insn_width(insn)`, and no `all_sites().collect::<Vec<_>>(); sites[i..=j]` slicing pattern in current `map_inline.rs` / `map_info.rs`.
- Evidence simplification ran: `map_inline.rs` is 3935 LOC, down from the 4197 baseline by 262 LOC. However, the current simplified file is not compile-clean because of the unresolved hint-type references listed in Top Issue 1.

## I. Cross-Cutting

- map_inline simplify: yes by LOC, from 4197 to 3935 (-262). The specific fix report `docs/tmp/p3_fix_mapinline_simplify_2026-05-11.md` is missing.
- BTF tests did not pass because `cargo test --release` does not compile. The named tests exist at `bpfopt/crates/bpfopt/src/pass_tests.rs:160` (`remap_btf_metadata_drops_deleted_entries_and_shifts_survivors`) and `bpfopt/crates/bpfopt/src/passes/bounds_check_merge_tests.rs:232` (`bounds_check_merge_remaps_btf_metadata_on_bbprogram`), but they were not executed in the final gate snapshot.

## J. Gates

- `cd bpfopt && cargo build --release`: exit 101. First failing class is unresolved `map_inline` hint-resolution types, with evidence at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:684-689`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:731-750`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1068-1112`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2042-2048`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2220-2224`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2395-2398`.
- `cd bpfopt && cargo test --release`: exit 101 with the same compile errors; tests were not run.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: exit 101 with the same compile errors.
- `cd bpfopt && cargo fmt --all --check`: exit 1. Representative non-formatted sites are `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:978-990`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1736`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2163`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2588`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3179-3188`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3795-3808`.

## K. Net LOC

- Requested non-test production LOC command returned 18940 total, which is 54 below the 18994 baseline. This gate passes on LOC alone.

## L. Architecture Smells

- Five largest production pass files sampled: `map_inline.rs` (3935), `bulk_memory.rs` (785), `cond_select.rs` (677), `bounds_check_merge.rs` (560), and `ccmp.rs` (530).
- The only strong "BBProgram should provide this" smell I found is still in `map_inline.rs`: frame-order traversal helpers at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:156-208`, lookup-pattern window safety at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3048-3095`, and null-check window safety at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3795-3854`. These are now site-keyed, but they still encode ordered program-window reasoning inside the pass.
- The other sampled large passes mostly use BBProgram APIs for CFG and mutations. Examples: `cond_select` uses BBProgram diamond replacement and `site_block` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:189-234`; `bounds_check_merge` delegates interleaving checks to `prog.bcm_sites_between` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:416`; `ccmp` uses BBProgram terminator/merge APIs at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:257-297`.
- map_inline responsibilities are only partially separated. `map_info.rs` separates map-reference analysis at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:73-113`, but hint resolution, key extraction, map-in-map routing, rewrite construction, and cleanup still live in the same 3935-line file: hint resolution starts around `bpfopt/crates/bpfopt/src/passes/map_inline.rs:684`, key extraction around `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2042`, hard-null rewrite around `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2226`, and map-in-map state around `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2395`.

## R2 Confirmed-Fixed List

- R2-1 map_inline JSON/IO in pass: fixed. `map_inline` rejects CLI side inputs at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:44-50`; main owns side-input parsing/loading at `bpfopt/crates/bpfopt/src/main.rs:771-786` and map JSON reads at `bpfopt/crates/bpfopt/src/main.rs:1123-1202`.
- R2-2 pass-internal `MapInlineHintAnchor::Pc`: fixed. The pass type has only `Site` and `MapName` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:16-20`; PC is confined to the external spec and lift boundary at `bpfopt/crates/bpfopt/src/pass.rs:207-210` and `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:246-256`.
- R2-3 `MapReference.slot` / `MapBinding.pc_load`: fixed. Current structs are site-keyed at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:73-82` and `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:105-113`.
- R2-4 program-order indexing in map_inline: partially fixed. The old Vec slicing/position pattern is gone, but pass-side ordered traversal remains at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:156-208`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3048-3095`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3795-3854`.
- R2-5 direct `InsnSite.block` reads in passes: fixed. The current direct `.block` hits I inspected are local pass fields such as `BranchTerm.block` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:136-143` and `CondBranchShape.block` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:94-101`.
- R2-6 raw verifier types public/re-exported/pass context raw states: mostly fixed. Raw declarations are `pub(crate)` in `bpfopt/crates/bpfopt/src/verifier_log.rs:15-99`; tests get raw type re-exports under `#[cfg(test)]` at `bpfopt/crates/bpfopt/src/pass.rs:19-21`. Residual: `PassContext.verifier_states` remains `pub(crate)` at `bpfopt/crates/bpfopt/src/pass.rs:465-466`.
- R2-7 discarded typed queries: fixed. `map_inline` now consumes `reg_known_stack_bytes` and `reg_kind` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:390-400`.
- R2-8 direct `ldimm64_second_slots` reads: fixed. The field is private at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:52`, with accessor `ldimm64_second_slot` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:638-639`.
- R2-9 `rep_admit_kinsn_site_window` returning `(BlockId, Range<usize>)`: fixed. It now returns `Option<KinsnAdmissionWindow>` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1684-1717`; callers use `start_site()` / `end_site()`, for example `bpfopt/crates/bpfopt/src/passes/rotate.rs:87-94`.
- R2-10 `reset_btf_to_current_pcs` lifecycle call: fixed. No `reset_btf_to_current_pcs` symbol remains in `bpfopt/crates/bpfopt/src`; mutation rebuilding only rebuilds use-def and invalidates oracle/profile at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:820-823`.
