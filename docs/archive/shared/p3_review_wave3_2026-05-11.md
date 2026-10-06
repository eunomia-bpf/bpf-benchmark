# Phase 3 BBProgram Migration Fresh-Eyes Review - Wave 3

Date: 2026-05-11
Reviewer constraint: read-only source review plus requested report write. I did not read any prior `docs/tmp/p3_*.md` reports.

## Verdict

**NOT-CONVERGED.**

The 5 claimed blocker fixes are verified under the exact requested checks, and all requested build/test/clippy/smoke gates pass. However, Phase 3 is not converged because only 2 of 15 passes are clean BBProgram-native A. The other 13 retain PC bridges, private linear views, or flat PC-indexed local scans, so the "all 15 passes A" convergence bar is not met.

## A. Independent Verification Of 5 Blocker Fixes

1. **`BBProgram.entry` encapsulation: PASS**
   - `rg "pub entry:" bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` returned 0 matches.
   - Field is `pub(crate)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:32`.
   - Accessor exists at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:110`.

2. **Banned pass helper calls: PASS for the exact blocker pattern**
   - `rg "current_sites\(|ordered_site_pcs\(|branch_target_sites\(|block_start_pc\(|report_pc\(|site_by_report_pc\(" bpfopt/crates/bpfopt/src/passes/` returned 0 matches.
   - Caveat: this does not mean all private linear views are gone. `map_inline` still uses `current_sites_after_in_frame` and `current_sites_before_in_frame_rev`, e.g. `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1115`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3388`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4050`.

3. **Short non-pass `*_tests.rs` files: PASS**
   - `find ... -name '*_tests.rs' -not -path '*/passes/*' ... | awk '$1 <= 80'` returned 0 files.
   - Remaining non-pass test files are all above 80 LOC: `main_tests.rs` 374, `verifier_log_tests.rs` 329, `pass_tests.rs` 313, `bbprogram_lift_tests.rs` 135, `bbprogram_liveness_tests.rs` 90.

4. **`parse_bytecode` has no production `.expect()`: PASS**
   - `rg "\.expect\(" bpfopt/crates/bpfopt/src/main.rs | grep -v "cfg(test)"` returned 0 matches.
   - `parse_bytecode` returns `Result<Vec<BpfInsn>>` and propagates conversion errors at `bpfopt/crates/bpfopt/src/main.rs:431` and `bpfopt/crates/bpfopt/src/main.rs:441`.

5. **Prefetch admission policy documented insert-only: PASS**
   - Comment says prefetch is insert-only and kinsn replacement admission does not apply at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:276`.
   - The implementation inserts with an empty `replace_range` range at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:280`.

## B. Per-Pass A/B/C/D Rating

Rating key used here:
- **A**: clean BBProgram-native.
- **B**: retains PC bridge, private linear view, or local flat PC/index view.
- **C**: lowers plus flat-scan plus PC remap.
- **D**: production BpfProgram wrapper path.

| Pass | Rating | Evidence |
| --- | --- | --- |
| `noop` | A | Runs directly on `&mut BBProgram` and returns unchanged at `bpfopt/crates/bpfopt/src/passes/noop.rs:19`. |
| `dce` | A | Uses `def_sites`, `uses_for_def`, `sites_in_block`, and `delete_insn` without PC bridge at `bpfopt/crates/bpfopt/src/passes/dce.rs:25` and `bpfopt/crates/bpfopt/src/passes/dce.rs:41`. |
| `map_inline` | B | Uses linear program-site and PC bridge helpers: `program_sites`/`site_pc` at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:153`, `site_by_pc` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1839`, `control_flow_target_sites` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2361`, and current-site linear views at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1115` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4050`. |
| `const_prop` | B | Builds `program_site_pcs` and `pc_to_site` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:128`, partitions by PC at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:353`, and calls `site_pc` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:520`. |
| `bounds_check_merge` | B | Uses `control_flow_target_sites` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:72`, `site_pc` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:249`, and `linear_sites_between` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:433`. |
| `branch_flip` | B | Consumes PC-keyed profile data at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:143`, uses `control_flow_target_sites` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:255`, and `site_pc` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:535`. |
| `bulk_memory` | B | Uses `admit_kinsn_site_window` at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:232`, `site_pc` at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:279`, and flat local `insns[pc]` lookback at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:721`. |
| `ccmp` | B | Uses `admit_kinsn_site_window` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:193` and computes `site_pc`/`block_start_slot` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:473`. |
| `cond_select` | B | Uses `admit_kinsn_site_window` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:157` and `site_pc` to build branch shape at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:310`. |
| `endian_fusion` | B | Scans flat local `insns[pc]` at `bpfopt/crates/bpfopt/src/passes/endian.rs:87`, uses `admit_kinsn_site_window` at `bpfopt/crates/bpfopt/src/passes/endian.rs:392`, and `site_pc`/`next_site_in_linear_order` at `bpfopt/crates/bpfopt/src/passes/endian.rs:452`. |
| `extract` | B | Uses `admit_kinsn_site_window` at `bpfopt/crates/bpfopt/src/passes/extract.rs:131` and `site_pc`/`next_site_in_linear_order` at `bpfopt/crates/bpfopt/src/passes/extract.rs:194`. |
| `prefetch` | B | Reads PC-keyed profile entries at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:122`, uses `program_sites` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:217`, and uses `site_pc` plus `linear_sites_after_within_slots` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:373`. |
| `rotate` | B | Uses `admit_kinsn_site_window`, which returns/report PCs, at `bpfopt/crates/bpfopt/src/passes/rotate.rs:94`, and scans flat local `insns[pc]` at `bpfopt/crates/bpfopt/src/passes/rotate.rs:283`. |
| `skb_load_bytes_spec` | B | Uses `control_flow_target_sites` at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:89` and `site_pc` at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:130`. |
| `wide_mem` | B | Scans flat local `while pc < n` / `insns[pc]` at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:71` and `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:88`, uses `control_flow_target_sites` at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:513`, and `site_pc` at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:536`. |

Summary: **2 A, 13 B, 0 C, 0 D**.

I found no production pass `lower(` calls, no production `BpfProgram::new`, and no production `program.insns[pc]` pass path. The remaining issue is B-level PC/linear bridge usage, not C/D fallback to the old wrapper.

## C. Gates

All requested gates passed.

| Gate | Result |
| --- | --- |
| `cargo build --release --manifest-path bpfopt/Cargo.toml` | PASS |
| `cargo test --release --manifest-path bpfopt/Cargo.toml` | PASS: 217 tests total passed (188 lib, 16 main, 1 roundtrip integration, 12 CLI integration). |
| `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings` | PASS |
| `target/release/bpfopt list-passes` | PASS: 15 passes listed (`noop`, `map-inline`, `const-prop`, `dce`, `skb-load-bytes`, `bounds-check-merge`, `wide-mem`, `bulk-memory`, `rotate`, `cond-select`, `ccmp`, `extract`, `endian`, `branch-flip`, `prefetch`). |
| DCE smoke command | PASS, exit status 0. |
| source LOC command | PASS, `19590 total`. |

## D. CLAUDE.md Violations

No P0 ReJIT filtering found in the permitted bpfopt source scope. The ReJIT-filtering search had no relevant match; the only "excluded" hit was map-type policy text in `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:37`, not ReJIT program filtering.

No production `.unwrap()`, `.expect()`, or `panic!()` violations found in the non-test source sweep. The hits were under `#[cfg(test)]` or inline test modules, e.g. `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:204`, `bpfopt/crates/bpfopt/src/pass.rs:419`, and `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:218`.

No production `.ok()`, `let _ =`, `unwrap_or_default`, fallback/legacy-comment violation was found by the requested pattern sweep in the permitted bpfopt source scope.

Dead-code gate passed under clippy with `-D dead_code -D warnings`.

Residual cleanup concern: some public BBProgram PC/report helpers remain even where pass use has moved away from the exact old names, notably `site_by_report_pc` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:399` and `branch_target_sites` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:408`. They are not clippy-reported because they are public methods, but they are still PC/report bridge surface area that should disappear if the final architecture requires no linear-PC bridge API.

## E. Final Verdict

**NOT-CONVERGED.**

Reasons:
- All 5 blocker fixes are verified.
- Gates are green.
- No production D wrapper path or pass-local `lower` path observed.
- But 13 of 15 passes are B, not A, due to PC bridge/private linear view/local flat PC-index patterns. Convergence requires all 15 passes to be A.

## F. Corpus Apply Verification

Not green-lit. Because this review is **NOT-CONVERGED**, Phase 3 is not done and corpus apply verification should not start yet.

## G. Top 5 Remaining Tasks

1. Remove pass-visible PC bridge helpers from the remaining B passes. Priority targets are `map_inline`, `const_prop`, `branch_flip`, and `prefetch`, where PC-keyed side inputs or `site_by_pc`/`program_site_pcs` still drive behavior.

2. Replace private linear current-site views with BBProgram-native traversal. Priority targets are `map_inline` (`current_sites_after_in_frame`, `current_sites_before_in_frame_rev`, `current_site_position`), `prefetch` (`linear_sites_after_within_slots`), and `bounds_check_merge` (`linear_sites_between`).

3. Convert single-block kinsn matchers away from `pc`-named flat slice scans and `start_pc` mutation. Priority targets are `rotate`, `extract`, `endian_fusion`, `bulk_memory`, and `wide_mem`.

4. Replace `admit_kinsn_site_window` with a BBProgram-native admission API that returns block/range/site-only data and does not leak/report absolute PCs back into pass logic.

5. Delete or privatize stale BBProgram PC/report bridge APIs after consumers move off them, especially `site_by_report_pc` and `branch_target_sites`; then rerun the exact gates above.
