# Phase 3 N2 Cleanup Report

Date: 2026-05-11

## Task Results

- T1 - PassManager to free function: done.
  - Replaced `PassManager::finalize_reports(...)` with `finalize_pass_reports(...)`.
  - Updated the two `main.rs` call sites.
  - Deleted the empty `PassManager` struct.
  - LOC delta: -3.

- T2 - `map_pseudo_kind` / `map_pseudo` collapse: done.
  - `map_pseudo()` had the wider call base.
  - Migrated the two `map_pseudo_kind()` callers in map-info code to `map_pseudo()`.
  - Deleted `map_pseudo_kind()`.
  - LOC delta: -4.

- T3 - profile attach path collapse: done.
  - Collapsed `attach_profile_from_annotations()` through the intermediate profile-data path into one function.
  - Removed the now-unused `ProfilingData` struct while retaining the existing `PmuRecord` alias for the BBProgram profile map.
  - LOC delta: -32.

- T4 - visibility tightening: done / no-op.
  - Verified these are already private in the current tree: `verifier_states_at()`, `block_start_pc()`, `parse_verifier_log()`, and `rebuild_use_def()`.
  - LOC delta: 0.

- T5 - `analysis/mod.rs` narrowing: done.
  - Changed `bbprogram_lift` and `bbprogram_lower` implementation modules to `pub(crate)`.
  - Kept external access through the existing public re-exports `lift_with_pass_context` and `lower`.
  - LOC delta: 0.

Total LOC delta across allowed files: -39.

## Gates

- `cargo build --release`: passed.
- `cargo test --release`: passed, 216 tests.
- `cargo clippy --release --all-targets -- -D dead_code -D warnings`: passed.
- `cargo fmt --all`: passed.
- `cargo fmt --all --check`: passed, zero diff.

## Left For Future Cleanup

- PassContext map-inline field move: deferred as high-risk.
- `main.rs` JSON parser split: deferred as high-risk.
- No N2 low-risk cleanup item was skipped.
