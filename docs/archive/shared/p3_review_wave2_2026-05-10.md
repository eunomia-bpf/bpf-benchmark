# Phase 3 BBProgram Migration Wave-2 Review

Date: 2026-05-10  
Repository: `/home/yunwei37/workspace/bpf-benchmark`  
Branch: `main`  
Mode: read-only audit, except writing this report.

## Evidence Commands

Commands used:

- `git status --short --branch`
- `git diff bfa802c9..HEAD --stat`
- `git diff bfa802c9 --numstat -- ...`
- `rg` for legacy flat-mode and duplicate-helper patterns
- `wc -l`
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml -- -D dead_code -D warnings`
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`

State caveat: `git status --short --branch` shows `main...origin/main [ahead 3]` with a large dirty worktree/index. `git diff bfa802c9..HEAD --stat` is still dominated by docs/results and does not reflect all current working-tree source changes. Current source evidence below is from filesystem line numbers.

Current source LOC measured with `rg --files bpfopt/crates/bpfopt/src bpfopt/crates/bpfopt/tests | xargs wc -l`: 27016 total. Non-test source with `_tests.rs` and `/tests/` excluded: 22576. Key files: `map_inline.rs` is 5724 LOC; `map_info.rs` is 655; `bbprogram.rs` is 1131; `bbprogram_api.rs` is 782; `pass.rs` is 1103.

`git diff bfa802c9 --numstat -- bpfopt/crates/bpfopt/src/passes/map_inline.rs` reports `973` additions and `605` deletions, net `+368` LOC.

## Executive Summary

Wave 2 made real migration progress. Wave 1 had 2 A-rated passes, 3 B-rated passes, 9 C-rated passes, and 1 D-rated pass. Current wave-2 state is 14 A-rated passes and 1 B-rated pass (`map_inline`). There are no remaining C/D-rated passes by the wave-1 rating key.

The main remaining design miss is `map_inline`: the old `BpfProgram` wrapper is gone, but it was replaced with a private `MapInlineProgram` linear adapter and PC-keyed analyses. That is a major improvement over D, but it is not A.

Build/test status from context is strong, but clippy is not clean for `--all-targets`: 4 diagnostics remain in `const_prop.rs`, `bulk_memory_tests.rs`, and `pass_tests.rs`.

## Per-Pass Rating

Rating key:

- A: production path operates on `BBProgram`; no `lower(prog)` in pass body, no `BpfProgram::new(insns)`, no full-program `linear_insn_sites` scan, and mutations use BBProgram APIs.
- B: no old flat pass wrapper, but still carries a private linear view, PC-keyed analysis, or local address-plan layer.
- C: production path lowers to flat bytecode or relies on full-program flat scan/rewrite shims.
- D: wrapper around the old flat `BpfProgram` pass.

| Pass | Wave 1 | Wave 2 | Delta | Evidence |
| --- | --- | --- | --- | --- |
| `noop.rs` | A | A | stayed | Direct no-op over `&mut BBProgram` at `bpfopt/crates/bpfopt/src/passes/noop.rs:19-20`; helper also unchanged at `noop.rs:24-25`. |
| `dce.rs` | A | A | stayed | Uses `prog.use_def.defs` / `uses_for` at `bpfopt/crates/bpfopt/src/passes/dce.rs:55-58`, deletes with `prog.delete_insn(def)?` at `dce.rs:67-69`, and validates instruction sites through `prog.insn_at` at `dce.rs:99-102`. |
| `const_prop.rs` | B | A | improved | Entry is BBProgram-native at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:457-461`; block walk uses `prog.blocks()` at `const_prop.rs:474-482`; instruction walk uses logical BBProgram sites at `const_prop.rs:571-586`; replacements are `(InsnSite, Vec<BpfInsn>)` applied through `prog.replace_range` at `const_prop.rs:497-502`. |
| `bounds_check_merge.rs` | B | A | improved | Entry uses BBProgram inputs at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:83-98`; scanner walks blocks/sites at `bounds_check_merge.rs:276-300`; edits use `prog.replace_range` and `prog.delete_cond_branch` at `bounds_check_merge.rs:183-218`. It still returns an address map for compatibility at `bounds_check_merge.rs:220-225`, but the production scan/edit path is not flat. |
| `branch_flip.rs` | B | A | improved | No lowering; candidate scan starts from BBProgram terminators at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:277-280` and `branch_flip.rs:536-551`; rewrite uses `replace_terminator` and `permute_blocks` at `branch_flip.rs:478-500`. |
| `rotate.rs` | C | A | improved | Iterates `prog.blocks()` / `prog.sites_in_block` at `bpfopt/crates/bpfopt/src/passes/rotate.rs:81-88`; applies with `prog.replace_range` at `rotate.rs:153-157`; no lowering or `linear_insn_sites`. |
| `extract.rs` | C | A | improved | Iterates blocks/sites at `bpfopt/crates/bpfopt/src/passes/extract.rs:115-124`; applies with `prog.replace_range` at `extract.rs:178-182`; cross-block skip is BBProgram-based at `extract.rs:192-218`. |
| `endian.rs` | C | A | improved | Iterates blocks/sites at `bpfopt/crates/bpfopt/src/passes/endian.rs:375-390`; applies with `prog.replace_range` at `endian.rs:441-451`; cross-block skip is BBProgram-based at `endian.rs:461-493`. |
| `bulk_memory.rs` | C | A | improved | Entry scans BBProgram at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:209-214`; block/site scan is at `bulk_memory.rs:257-278`; applies with `prog.replace_range` at `bulk_memory.rs:242-247`. |
| `prefetch.rs` | C | A | improved | Entry uses current BBProgram site PCs at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:248-261`; insertion is `prog.replace_range(insert_idx..insert_idx, ...)` at `prefetch.rs:311-317`; PC-window helpers are BBProgram site queries at `prefetch.rs:783-853`. |
| `wide_mem.rs` | C | A | improved | Uses per-block `BBProgram` body views rather than lowering at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:501-515`; applies with `prog.replace_range` at `wide_mem.rs:634-635`; cross-block skip detection uses BBProgram fallthroughs at `wide_mem.rs:645-727`. |
| `skb_load_bytes.rs` | C | A | improved | Entry is BBProgram-native at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:62-74`; scan is per-block via `block_body_linear_view` at `skb_load_bytes.rs:107-113`; applies with `prog.replace_range` at `skb_load_bytes.rs:82-94`. |
| `cond_select.rs` | C | A | improved | Scans BBProgram conditional terminators at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:298-325`; pattern matching uses block successors and block bodies at `cond_select.rs:336-456`; rewrite is `prog.replace_diamond_with_insns` at `cond_select.rs:196-197`. |
| `ccmp.rs` | C | A | improved | Scans BBProgram branch-chain blocks at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:397-416`; applies with `split_block`, `replace_terminator`, `merge_linear_chain`, and `replace_range` at `ccmp.rs:273-303`. |
| `map_inline.rs` | D | B | improved, not A | Old wrapper is gone, but production uses a private linear adapter: `MapInlineProgram { insns, pc_to_site, site_to_pc, subprog_ranges, ... }` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:248-255`; rebuilt every fixed-point round at `map_inline.rs:2697-2708`; analyses still iterate `program.insns` by PC, e.g. direct map-value rewrite at `map_inline.rs:4234-4245`; `linear_insn_sites` remains in `raw_map_lookup_call_pcs_flat` at `map_inline.rs:2143-2147`. Edits are now direct BBProgram site edits at `map_inline.rs:3305-3349`, so this is no longer D. |

Pass status against the explicit wave-2 check:

- The former C-rated passes (`rotate`, `extract`, `endian`, `bulk_memory`, `prefetch`, `wide_mem`, `skb_load_bytes`, `cond_select`, `ccmp`) are now A.
- The former B-rated passes (`const_prop`, `bounds_check_merge`, `branch_flip`) are now A.
- The former D-rated `map_inline` is not A; it is B because of the private linear adapter and PC-keyed iteration.

## Duplicate Helpers Across Passes

The exact requested search returned no matches:

```text
rg "fn same_block_window|fn linear_iter|fn block_body_view|fn find_block_for_site|fn site_window|fn window_at_site|fn original_pc_for|fn site_for_original_pc" bpfopt/crates/bpfopt/src/passes/
```

However, duplicate private helpers remain under different names:

- `site_current_pc`: `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:891`, `extract.rs:231`, `endian.rs:506`, `rotate.rs:196`, `prefetch.rs:848`.
- `block_slot_offset`: `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:880`, `extract.rs:220`, `endian.rs:495`, `rotate.rs:185`.
- `packet_ctx_layout`: `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:97`, `prefetch.rs:555`, `bounds_check_merge.rs:257`.
- `read_json_file<T>`: `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:185`, `prefetch.rs:158`, `map_inline.rs:1283`.
- `annotations_from_profile`: `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:191`, `prefetch.rs:164`.
- `is_terminator_site`: `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:228`, `map_inline.rs:3378`.
- Simple register-state helpers duplicated between `bulk_memory` and `skb_load_bytes`: `advance_reg_state` at `bulk_memory.rs:815` / `skb_load_bytes.rs:237`, `advance_alu64_state` at `bulk_memory.rs:849` / `skb_load_bytes.rs:264`, `advance_alu32_state` at `bulk_memory.rs:860` / `skb_load_bytes.rs:277`, and `combine_ldimm64` at `bulk_memory.rs:874` / `skb_load_bytes.rs:337`.

`bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:10-89` already defines a `BBProgramAddressView`, but `rg` shows no production caller outside its own export in `analysis/mod.rs:18`. Either use that file for the hoisted helpers or delete it.

## `map_inline.rs` +368 LOC Investigation

The old subsystems Codex A claimed to delete are actually gone from `map_inline.rs`:

- No `linear_program_view`.
- No `linear_subprog_bounds` or `linear_subprog_ranges`.
- No `DirectMapValueLoadRewrites` alias.
- No `SiteRewrite.replacements: BTreeMap<usize, ...>`; current `SiteRewrite.replacements` is `Vec<SiteReplacement>` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1939-1945`.
- No `ReplacementBranchPatch` and no `target_old_pc`.
- No `map_inline_addr_map`.
- No `patch_replacement_branches`.

`BpfProgram::new` is no longer in `map_inline.rs`. It remains only under `#[cfg(test)]` in `map_inline/map_info.rs`, including the test-only `MapInfoAnalysis::run(&BpfProgram)` path at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:124-148` and test helper construction at `map_info.rs:185`.

The +368 net LOC came from replacement infrastructure, not from retaining the exact old code:

- New `MapInlineProgram` linear adapter: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:248-433`. This owns `insns`, `pc_to_site`, `site_to_pc`, `subprog_ranges`, map fd bindings, and a context pointer.
- New current-PC/terminator re-emission helpers for that adapter: `map_inline.rs:435-590`.
- Rebuilt per-round adapter loop: `map_inline.rs:2668-2708`.
- New site-based replacement records: `SiteReplacement` at `map_inline.rs:1371-1375`, `DirectMapValueLoadRewriteResult` at `map_inline.rs:1377-1383`, and `site_replacement()` at `map_inline.rs:1963-1971`.
- New direct BBProgram edit application layer: `apply_map_inline_edit`, `apply_replacements_and_deletions`, `replace_site`, `delete_site`, BTF reset, and cleanup at `map_inline.rs:3283-3439`.
- New fail-closed soft-fold guard path: `build_soft_hint_site_rewrite()` validates soft hints and then returns `soft fold requires BBProgram CFG insertion` at `map_inline.rs:3753-3803`.
- Direct pseudo-map-value load rewrite now emits `SiteReplacement` from a PC loop over `program.insns` at `map_inline.rs:4234-4348`.
- `map_info` production analysis was adapted to `MapInlineProgram` at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:131-145`.

Conclusion: the deletion claim is materially true for the named old subsystems, but the replacement is not yet BBProgram-native. It is a BBProgram-backed linear adapter with PC-to-site maps.

## Clippy Diagnostics

The exact requested command:

```text
cargo clippy --release --manifest-path bpfopt/Cargo.toml -- -D dead_code -D warnings 2>&1 | grep -E "error\[|warning:" | head -50
```

emitted no grep lines in this tree. That command does not include test targets. The suspected failures appear with `--all-targets`:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:577`: `clippy::type_complexity` on `Option<(&mut Vec<(InsnSite, Vec<BpfInsn>)>, &mut Vec<SkipReason>)>`. Fix: introduce a small `RewriteOutputs<'a>` struct or type aliases.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:616`: `clippy::too_many_arguments` on `analyze_instruction(...)` with 8 args. Fix: pass an `AnalyzeInstructionInput`/context struct.
- `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:53`: `clippy::too_many_arguments` on test helper `pack_memset_payload(...)`. Fix: use a test payload struct or call the production encoder shape.
- `bpfopt/crates/bpfopt/src/pass_tests.rs:127`: `clippy::unnecessary_map_or`; replace `.map_or(true, |states| states.is_empty())` with `.is_none_or(|states| states.is_empty())`.

## P0/P1/P2/P3 Issues For Next Wave

### P0 - Correctness / Fail-Fast

1. `merge_linear_chain` is still not clone-swap atomic.
   - Evidence: metadata remap happens at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:283`, the first block is mutated at `bbprogram_api.rs:285-289`, and `remove_blocks(&remove)?` can still fail at `bbprogram_api.rs:291-292`. Production caller is `ccmp.rs:279`.
   - Fix: wrap `merge_linear_chain` like `replace_range` and `split_block`: clone, mutate clone, then assign after success.
   - Estimated LOC delta: +15 to +30.

2. `remove_blocks` mutates before all remap/rebuild work is proven.
   - Evidence: `self.blocks = blocks` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:501`, then `remap_pc_relative_targets_after_remove` and `rebuild_use_def_after_mutation` can fail at `bbprogram_api.rs:509-511`.
   - Fix: either make all callers operate on a clone or compute all remaps/rebuild validation before assigning fields.
   - Estimated LOC delta: +30 to +80.

3. Public unchecked BBProgram query APIs still panic.
   - Evidence: `live_in`, `live_out`, and `live_out_site` panic through `unwrap_or_else` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:228-256`; `btf_records()` panics at `bbprogram.rs:302-304`.
   - Fix: delete unchecked APIs or make them `#[cfg(test)]`; use checked variants in tests and production.
   - Estimated LOC delta: -20 to -40.

4. Kinsn registry duplicate registration still panics.
   - Evidence: `assert!(previous.is_none(), "duplicate kinsn target name {name}")` at `bpfopt/crates/bpfopt/src/pass.rs:812-820`.
   - Fix: return `Result` from registration/construction and `bail!` with the duplicate name.
   - Estimated LOC delta: +10 to +25.

5. `map_inline` applies multi-site batches non-transactionally.
   - Evidence: `apply_map_inline_edit` calls `apply_replacements_and_deletions` before cleanup/BTF reset at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3283-3296`; the edit loop mutates one site at a time at `map_inline.rs:3305-3332`.
   - Fix: clone-swap the whole map-inline edit batch, then assign after replacement, cleanup, and BTF reset all succeed.
   - Estimated LOC delta: +10 to +30.

6. Forbidden `let _ =` pattern remains.
   - Evidence: `let _ = process_block_state(...)?;` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:82-88`.
   - Diagnosis: the error is propagated, so this is not a silenced error, but it violates the repo's fail-fast style rule.
   - Fix: call `process_block_state(...)?;` directly or bind the returned state to a named variable if it matters.
   - Estimated LOC delta: neutral.

### P1 - Design Contract

1. No C/D-rated passes remain.
   - Evidence: current pass audit above.
   - Fix: none for C/D class.
   - Estimated LOC delta: none.

2. `map_inline` is still B, not A.
   - Evidence: `MapInlineProgram` linear adapter at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:248-255`, per-round rebuild at `map_inline.rs:2697-2708`, PC loop over `program.insns` at `map_inline.rs:4234-4245`, and `linear_insn_sites` helper at `map_inline.rs:2143-2147`.
   - Fix: migrate map-inline analyses to `InsnSite`/block iteration, and keep any PC only as diagnostics/profile coordinates. Delete the private full-program `insns` adapter or reduce it to a temporary local helper with no pass-wide PC-keyed state.
   - Estimated LOC delta: -300 to -700.

3. `BpfProgram` remains in the public pass framework even though production passes no longer need it.
   - Evidence: `BpfProgram` is defined at `bpfopt/crates/bpfopt/src/pass.rs:291-321`; `MapProvider` stack starts at `pass.rs:369`; remaining `BpfProgram::new` uses are `#[cfg(test)]` in `map_inline/map_info.rs:124-185` and tests.
   - Fix: move test-only map-info fixtures off `BpfProgram`, then delete or `#[cfg(test)]` the `BpfProgram`/`MapProvider` stack.
   - Estimated LOC delta: -250 to -350.

### P2 - LOC Reduction

1. Hoist duplicate current-PC and slot helpers.
   - Evidence: `site_current_pc` appears in 5 pass files and `block_slot_offset` in 4 pass files, listed above.
   - Fix: add `BBProgram::pc_for_site_checked(site)` and `BBProgram::block_slot_offset(site)` or use `bbprogram_helpers.rs`.
   - Estimated LOC delta: -45 to -75 across small pass files.

2. Hoist packet/profile utility duplication.
   - Evidence: `packet_ctx_layout` in 3 pass files; `read_json_file<T>` and `annotations_from_profile` duplicate in profile-guided passes.
   - Fix: shared packet-layout helper and profile JSON helper module.
   - Estimated LOC delta: -40 to -80.

3. Remove or use dead public `BBProgramAddressView`.
   - Evidence: `BBProgramAddressView` is `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:10-89`; `rg` finds only the export at `analysis/mod.rs:18`.
   - Fix: either delete the file/export or make it the home for the hoisted helpers.
   - Estimated LOC delta: -90 if deleted; net -50 to -100 if used to remove pass-local helpers.

4. Trim `map_inline` adapter code.
   - Evidence: `MapInlineProgram` at `map_inline.rs:248-433`; duplicate current-PC/terminator helpers at `map_inline.rs:435-590`; edit application at `map_inline.rs:3283-3439`.
   - Fix: use shared BBProgram current-PC helpers and a shared edit-batch helper; remove `emit_current_terminator` duplication or centralize it with lower/address-view code.
   - Estimated LOC delta: -150 to -300 short-term, -300 to -700 after native map-inline analysis.

5. Remove `BpfProgram`/`MapProvider` from `pass.rs`.
   - Evidence: `BpfProgram` and map-provider stack at `pass.rs:291-552`.
   - Fix: update `map_info` tests to use `MapInlineProgram` or lower-level binding helpers; delete production-public legacy types.
   - Estimated LOC delta: -250 to -350.

6. Slim `bbprogram.rs`.
   - Evidence: BTF/query/view/liveness APIs are mixed in one file: BTF view starts at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:302`, current/linear views at `bbprogram.rs:352-470`, kinsn subprog checks at `bbprogram.rs:477-544`, liveness implementation starts around `bbprogram.rs:1028`.
   - Fix: split into focused modules. Net LOC may not drop, but `bbprogram.rs` should shrink by 250-400 LOC for auditability.
   - Estimated LOC delta: net neutral, file-local -250 to -400.

### P3 - Polish

1. Fix clippy `--all-targets`.
   - Evidence: diagnostics listed above.
   - Fix: small local refactors in `const_prop.rs`, `bulk_memory_tests.rs`, and `pass_tests.rs`.
   - Estimated LOC delta: neutral to +20.

2. Remove stale `IMPL:` breadcrumbs.
   - Evidence: `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:87`, `analysis/bbprogram_map_refs_tests.rs:14`, `analysis/bbprogram_site_scan_tests.rs:12`, `analysis/bbprogram_site_scan_tests.rs:52`, `analysis/bbprogram_cfg_tests.rs:20`, `analysis/bbprogram_cfg_tests.rs:56`, `passes/bounds_check_merge_tests.rs:246`, and `passes/map_inline_tests.rs:580`.
   - Fix: convert to normal comments or delete when the referenced API exists.
   - Estimated LOC delta: -5 to -20.

3. Update stale design-doc stage text.
   - Evidence: `docs/bbprogram-architecture-design.md:326` still names `legacy_cleanup`; `docs/bbprogram-architecture-design.md:345-356` still describes temporary legacy implementations.
   - Fix: update the doc to wave-2 reality or mark it historical.
   - Estimated LOC delta: neutral.

4. Add only bug-detection tests for transaction fixes.
   - Evidence: current tests exercise transformation output but not failed multi-edit atomicity.
   - Fix: add targeted tests only for `merge_linear_chain`/`map_inline` clone-swap failure behavior if the next wave changes those paths.
   - Estimated LOC delta: +30 to +80 if implemented.

## Convergence Assessment

Wave 2 made real progress:

- C/D pass count: wave 1 had 10 C/D passes; wave 2 has 0.
- Non-A pass count: wave 1 had 13 non-A passes; wave 2 has 1 (`map_inline`).
- P0 progress: wave 1's `split_block` panic is fixed with a fallible clone-swap wrapper at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:319-323`; `replace_range` is clone-swap at `bbprogram_api.rs:42-51`; BTF output is fail-fast at `bpfopt/crates/bpfopt/src/main.rs:702-719`; unknown target features now `bail!` at `main.rs:847-854`.

Remaining blockers:

- `map_inline` is still a linear-adapter pass, not fully native.
- `--all-targets` clippy is still red.
- LOC did not converge; `map_inline.rs` is net +368 against the Phase 3 start comparison, and the pass framework still carries legacy `BpfProgram` surface.

## Recommended Next Wave

Do another small parallel wave; do not declare convergence yet. Keep the risky `map_inline` work isolated and make the helper/clippy cleanup a separate low-risk lane.

### Codex 1 - Clippy + Small-Pass Helper Hoist

File scope:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs`
- `bpfopt/crates/bpfopt/src/pass_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/{rotate,extract,endian,bulk_memory,prefetch}.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs`

TODOs:

- Fix all 4 `--all-targets` clippy diagnostics.
- Hoist `site_current_pc` and `block_slot_offset`.
- Either use or delete `BBProgramAddressView`.

Estimated LOC delta: -50 to -120.  
Risk: low.

### Codex 2 - `map_inline` B-to-A Trim / Transaction

File scope:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` only for targeted regressions

TODOs:

- Make `apply_map_inline_edit` clone-swap atomic.
- Remove `raw_map_lookup_call_pcs_flat` / `linear_insn_sites` from production helpers.
- Collapse `current_block_start_pcs`, `current_block_end_pcs`, `current_subprog_ranges`, and `emit_current_terminator` into shared BBProgram/lower helpers or eliminate them while porting analysis to sites.
- Trim or simplify the fail-closed soft-fold path if guarded CFG insertion is not being implemented in this wave.

Estimated LOC delta: -150 to -300 short-term.  
Risk: medium-high.

### Codex 3 - Infra Cleanup

File scope:

- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs`
- `bpfopt/crates/bpfopt/src/pass.rs`
- tests that directly depend on these APIs

TODOs:

- Make `merge_linear_chain` and `remove_blocks` clone-swap/transactional.
- Delete or `#[cfg(test)]` unchecked panic APIs.
- Replace the `let _ = process_block_state(...)?` pattern.
- Remove `BpfProgram`/`MapProvider` once map-info tests are converted.

Estimated LOC delta: -200 to -400 after `BpfProgram` removal.  
Risk: medium.

If only two parallel agents are available, run Codex 1 and Codex 2 first, then do Codex 3 sequentially after the helper shape is known.
