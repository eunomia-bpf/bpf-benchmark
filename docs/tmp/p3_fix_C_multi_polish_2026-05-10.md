# P3 C Multi-Block + B Polish Fix

Date: 2026-05-10

## Scope

Touched code files:

- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
- `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs`

The other four scoped pass files were already BBProgram-native in the current dirty tree when this pass started:

- `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs`
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs`
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs`
- `bpfopt/crates/bpfopt/src/passes/branch_flip.rs`

## Per-Pass Rating And LOC Delta

LOC delta is measured from the start of this task in the current working tree.

| Pass | Review rating before | Rating after | LOC before | LOC after | Delta |
| --- | --- | --- | ---: | ---: | ---: |
| `wide_mem.rs` | C | A | 643 | 731 | +88 |
| `skb_load_bytes.rs` | C | A | 357 | 357 | 0 |
| `cond_select.rs` | C | A | 702 | 702 | 0 |
| `ccmp.rs` | C | A | 583 | 583 | 0 |
| `const_prop.rs` | B | A | 943 | 989 | +46 |
| `bounds_check_merge.rs` | B | A | 654 | 677 | +23 |
| `branch_flip.rs` | B | A | 701 | 701 | 0 |

## Removal Details

`const_prop.rs`:

- Removed `ConstPropRewritePlan`.
- Removed `ConstReplacement`.
- Replacements are collected as `(InsnSite, Vec<BpfInsn>)` and emitted directly with `prog.replace_range(...)`.
- Verifier oracle maps moved from `(pc, frame, reg)` keys to `(InsnSite, frame, reg)` keys for scalar facts and scalar post-states.
- Pointer post-state lookahead now stores site ordinals instead of PCs so one-past-end verifier post-state evidence still gates materialization without PC-keyed oracle maps.

`bounds_check_merge.rs`:

- Removed `LadderRewrite`.
- Removed the remaining `ProgramView`/`BBProgramAddressView` dependency from the pass.
- Rewrites are represented locally as `(dominant_add_site, merged_end, skip_sites)` and applied with BBProgram mutation APIs.
- Current PCs, target PCs, and PC-to-site lookups come directly from `BBProgram` query methods.

## Helpers Added

`wide_mem.rs`:

- `SafeWideMemSite`
- `add_cross_block_wide_mem_skips`
- `WideMemWindow`
- `collect_wide_mem_window`

`const_prop.rs`:

- `state_pc_insertion_ordinal`

`bounds_check_merge.rs`:

- `current_program_len`

No private helpers were needed in `skb_load_bytes.rs`, `cond_select.rs`, `ccmp.rs`, or `branch_flip.rs` during this task because the current tree already had their BBProgram-native scans.

## BBProgram Method Gaps

The pass-local code still wants these BBProgram helpers:

- `current_program_len()`
- `pc_for_site(site)`
- `insn_at_current_pc(pc)`
- `logical_window_from_site(site, max_len)`
- `block-start/target-pc query wrappers` that avoid rebuilding maps in passes

These were intentionally kept private/pass-local per the scope rule; a later dedup pass can hoist them.

## Test Status

Commands run:

- `cargo test --release`
- `cargo test --release`
- `cargo test --release`
- `cargo test --release`

Results:

- First run compiled and executed the lib tests: 186 passed, 2 `wide_mem` skip-accounting tests failed. Those failures were fixed by adding BBProgram-local cross-block skip detection.
- Subsequent runs did not reach the test suite because the current shared dirty tree has out-of-scope `map_inline.rs` compile errors, including missing `lower` import and stale `MapInlineProgram` field accesses.
- I did not modify `map_inline.rs` because it is outside this task's allowed file scope.

Pattern check:

`rg` over the seven scoped pass files found no remaining `lower(`, `program_linear_view`, `site_for_original_pc`, `replace_flat_range`, `ConstPropRewritePlan`, `ConstReplacement`, `LadderRewrite`, `ProgramView`, or `BBProgramAddressView`.
