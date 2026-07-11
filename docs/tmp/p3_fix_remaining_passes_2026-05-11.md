# Phase 3 Remaining Pass Cleanup

## Task Results

1. Removed pass-visible PC bridge helpers from B passes.
   - `map_inline`: PC hints now resolve through lookup-call `InsnSite`s at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1682` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1881`.
   - `const_prop`: verifier PCs are correlated through local ordered `InsnSite` state, not `program_site_pcs`/`pc_to_site`, at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:126` and `bpfopt/crates/bpfopt/src/passes/const_prop.rs:153`.
   - `branch_flip`: interior-target scan uses `subprog_blocks` plus block sites at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:239`.
   - `prefetch`: map-value lookahead uses BBProgram subprogram/block site traversal at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:356`.

2. Replaced private linear current-site views.
   - `map_inline`: local BBProgram-native frame helpers are at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:964`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:983`, and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1009`.
   - `prefetch`: removed `linear_sites_after_within_slots` use at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:356`.
   - `bounds_check_merge`: removed `linear_sites_between` use; frame/block scan is at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:424`.

3. Converted single-block kop matchers away from `pc`/`start_pc` mutation.
   - `rotate`: `start_idx` flow at `bpfopt/crates/bpfopt/src/passes/rotate.rs:81`, matcher at `bpfopt/crates/bpfopt/src/passes/rotate.rs:157`, and constructor at `bpfopt/crates/bpfopt/src/passes/rotate.rs:426`.
   - `extract`: block index matcher at `bpfopt/crates/bpfopt/src/passes/extract.rs:56`.
   - `endian_fusion`: block index matcher at `bpfopt/crates/bpfopt/src/passes/endian.rs:62`.
   - `bulk_memory`: block index scan/matchers at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:277`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:338`, and `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:414`.
   - `wide_mem`: `start_idx` rewrite site and block-site mapping at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:17` and `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:374`.

4. Refactored `admit_kop_site_window`.
   - `AdmittedKopWindow` now returns only `block` and intra-block `range` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:80`.
   - Admission still emits skip diagnostics from the boundary site internally at `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:85`.

5. Deleted stale BBProgram/report bridge APIs.
   - Removed `site_by_report_pc`, `branch_target_sites`, `ordered_site_pcs`, `report_pc`, `linear_sites_between`, `linear_sites_after_within_slots`, and the current-site frame/position helpers from `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`.
   - Remaining native traversal APIs used by passes are `subprog_blocks` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:274` and `sites_in_block` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:328`.

## Pass Ratings

| Pass | Rating | Residual reason |
|---|---:|---|
| `map_inline` | B | Still has external PC hint/report boundaries and uses control-flow target/site diagnostics, but no banned PC bridge helpers or private current-site views remain. |
| `const_prop` | B | Verifier log states are inherently PC-keyed; the old `program_site_pcs`/`pc_to_site` bridge is gone. |
| `bounds_check_merge` | B | Uses BBProgram traversal for the former linear range, but still uses target-site and report-PC diagnostics. |
| `branch_flip` | B | Paper-B PGO input remains PC-keyed by design; the pass no longer uses the deleted linear helper. |
| `bulk_memory` | A | Single-block matcher is index/site based; admission returns only block/range. |
| `endian_fusion` | B | Single-block matcher is index based; cross-block skip still uses `next_site_in_linear_order`. |
| `extract` | B | Single-block matcher is index based; cross-block skip still uses `next_site_in_linear_order`. |
| `prefetch` | B | Profile annotations and insertion diagnostics remain PC-keyed, but lookahead is BBProgram block/subprogram traversal. |
| `rotate` | A | Single-block matcher is index/site based; admission returns only block/range. |
| `wide_mem` | B | Single-block matching is index/site based; verifier-state safety still consumes PC-keyed oracle data. |

No affected pass is C or D.

## Verification

- `cargo build --release --manifest-path bpfopt/Cargo.toml`: pass.
- `cargo test --release --manifest-path bpfopt/Cargo.toml`: pass, 217 tests.
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`: pass.
- `target/release/bpfopt list-passes`: pass, 15 passes listed.
- DCE smoke command: pass, exit `0`.
- Final non-test LOC: `19138`.

## rg Checks

- `rg "site_by_pc|program_site_pcs|pc_to_site" bpfopt/crates/bpfopt/src/passes/{map_inline,const_prop,branch_flip,prefetch}.rs`: clean.
- `rg "current_sites_after_in_frame|current_sites_before_in_frame_rev|linear_sites_after_within_slots|linear_sites_between|current_site_position" bpfopt/crates/bpfopt/src/passes/`: clean.
- `rg "let mut pc|let mut start_pc|start_pc \\+=|pc \\+=" bpfopt/crates/bpfopt/src/passes/{rotate,extract,endian,bulk_memory,wide_mem}.rs`: clean.
- `rg "site_by_report_pc\\(|branch_target_sites\\(" bpfopt/crates/bpfopt/src -g'*.rs'`: clean.
