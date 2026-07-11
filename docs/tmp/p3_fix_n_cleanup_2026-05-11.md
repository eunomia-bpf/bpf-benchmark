# P3 Fix N Cleanup - 2026-05-11

## Summary

Executed the high-confidence N cleanup items in the allowed bpfopt files:

- Deleted the listed zero-call BBProgram/API/verifier residue.
- Moved branch_flip, prefetch, and bounds_check_merge policy helpers out of `BBProgram`.
- Tightened private/test-only visibility for verifier/use-def/slot helpers.
- Collapsed the redundant profile attach chain to a single `attach_profile_data` path.
- Deleted dead instruction helpers in `insn.rs`.

## Per-Item Changes

### N-A Dead BBProgram API

- `bbprogram.rs:137 entry()` -> deleted.
- `bbprogram.rs:152 block_body_len()` -> deleted.
- `bbprogram.rs:180 block_body_insns()` -> deleted.
- `bbprogram.rs:194 body_insn_window()` -> deleted.
- `bbprogram.rs:614 block_entry_site()` -> deleted.
- `bbprogram.rs:499 kop_registry()` -> deleted.
- `bbprogram_api.rs:145 delete_cond_branch_at_site()` -> deleted.
- `bbprogram_api.rs:394 split_block_at_site()` -> deleted.
- `bbprogram.rs:321 reg_known_map_ptr()` -> deleted.
- `bbprogram.rs:331 reg_proven_bounds()` -> deleted.
- `bbprogram.rs:935 map_ptr_from_reg_state()` -> deleted.
- `bbprogram.rs:943 proven_bounds_from_reg_state()` -> deleted.
- `pass.rs:27 MapPtr` -> deleted.
- Test-only liveness/oracle surface tightened:
  - `dominance()`, `live_in_checked()`, `live_out_checked()`, and `reaching_defs()` are now `#[cfg(test)]`.
  - `Dominance`, `ReachingDefs`, `LivenessSets`, and `compute_liveness()` are now `#[cfg(test)]`.
- `block_count()` was removed; the only caller now uses `prog.block_ids().count()` in `branch_flip.rs`.

### N-B Pass-Specific Helpers

- `bbprogram.rs:1471 bf_skip_reason()` -> moved to `branch_flip.rs:222`.
- `bbprogram.rs:1480 bf_blocks_are_adjacent()` -> moved to `branch_flip.rs:231`.
- `bbprogram.rs:1490 bf_block_range_has_body_site()` -> moved to `branch_flip.rs:237`.
- `bbprogram.rs:1510 bf_validate_flipped_branch_deltas()` -> moved to `branch_flip.rs:257`.
- `bbprogram.rs:1565 pf_skip_reason()` -> moved to `prefetch.rs:437`.
- `bbprogram.rs:1574 pf_sites_after_in_frame()` -> moved to `prefetch.rs:446`.
- `bbprogram.rs:1601 pf_prefetch_window_sites()` -> moved to `prefetch.rs:473`.
- `bbprogram.rs:1648 pf_nearest_prefetch_insert_site()` -> moved to `prefetch.rs:520`.
- `bbprogram.rs:1725 bcm_sites_between()` -> moved to `bounds_check_merge.rs:428`.
- `bbprogram.rs:1682 rep_site_slot()` -> retained only as `#[cfg(test)]` at `bbprogram.rs:1466` for `test_helpers.rs`.

### N-F insn.rs Dead Helpers

- `insn.rs:178 MapPseudo::has_value_offset()` -> deleted.
- `insn.rs:402 BpfInsn::is_map_pseudo()` -> deleted.
- `insn.rs:451 BpfInsn::call_kfunc_with_off()` -> deleted.
- `insn.rs:461 BpfInsn::call_kfunc()` -> deleted.
- `bbprogram.rs` was migrated from `map_pseudo_kind()` to `map_pseudo()`.

### N-D Visibility Tightening

- `bbprogram.rs:308 verifier_states_at()` -> private at `bbprogram.rs:306`.
- `bbprogram.rs:678 block_start_pc()` -> private and test-only at `bbprogram.rs:629`.
- `verifier_log.rs:147 parse_verifier_log()` -> private at `verifier_log.rs:147`.
- `bbprogram.rs:800 rebuild_use_def()` -> private at `bbprogram.rs:751`.

### N-C Lifecycle Simplification

- Removed `attach_prefetch_profile_from_original_pcs()`.
- `attach_profile_from_annotations()` now feeds `attach_profile_data()`, and `attach_profile_data()` builds one combined `PmuRecord` map before attaching it.

## LOC Delta

Baseline was measured before this N cleanup from the current dirty worktree.

| File | Before | After | Delta |
|---|---:|---:|---:|
| `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` | 1955 | 1781 | -174 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` | 859 | 848 | -11 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs` | 560 | 560 | 0 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 842 | 835 | -7 |
| `bpfopt/crates/bpfopt/src/insn.rs` | 847 | 840 | -7 |
| `bpfopt/crates/bpfopt/src/verifier_log.rs` | 853 | 853 | 0 |
| `bpfopt/crates/bpfopt/src/passes/branch_flip.rs` | 478 | 581 | +103 |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs` | 498 | 642 | +144 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs` | 560 | 596 | +36 |
| Total | 7452 | 7536 | +84 |

Gross diff deletion count in the affected files is 455 lines. Net LOC did not decrease because N-B moved helper bodies into pass files instead of deleting that logic, and the prefetch move needed local slot-bound helpers once it no longer used BBProgram-private slot helpers.

## Gates

- `cd bpfopt && cargo build --release`: passed clean.
- `cd bpfopt && cargo test --release`: passed, 216 tests.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: passed clean.
- `cd bpfopt && cargo fmt --all && cargo fmt --all --check`: passed clean.

## Not Done

- `map_pseudo_kind()` / `map_pseudo()` full collapse was not completed. Remaining `map_pseudo_kind()` callers are in `passes/map_inline/map_info.rs` and `passes/map_inline/map_info_tests.rs`, and `map_inline.rs` / `map_info.rs` were explicitly forbidden in this round.
- `PassManager` replacement with a free function was not done because its production callers are in `main.rs`, which was explicitly deferred.
