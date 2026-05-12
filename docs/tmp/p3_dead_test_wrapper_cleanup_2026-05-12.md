# Phase 3 Dead Test and Wrapper Cleanup

Date: 2026-05-12

## Rule Source

- Requested CLAUDE path was absent: `/home/yunwei37/.claude/projects/-home-yunwei37-workspace-bpf-benchmark/CLAUDE.md`.
- Read repo `CLAUDE.md`; it contains the Unit Test Quality rule used for this cleanup.

## Tests Deleted

### `bpfopt/crates/bpfopt/src/pass_tests.rs`

- Deleted `pipeline_lifts_once_runs_multiple_passes_on_same_bbprogram`.
  - Rationale: mock-only `CountingPass` interface test; it verified a test harness shape, not production pass behavior.
- Deleted `pipeline_lowers_once_after_all_bbprogram_mutations`.
  - Rationale: mock-only `DeleteFirstMovPass` interface test; real mutation/lowering behavior remains covered by pass and BBProgram tests.
- Deleted `pass_context_owns_side_input_fields_for_bbprogram_passes`.
  - Rationale: trivial setter/getter field ownership check; no bug-detection value.

### `bpfopt/crates/bpfopt/src/passes/mod_tests.rs`

- Deleted `custom_pipeline_rejects_unknown_pass_names_without_running`.
  - Rationale: exercised a test-only custom pipeline resolver and helper struct, not production CLI/pipeline behavior.

### `bpfopt/crates/bpfopt/src/passes/map_inline/map_info_tests.rs`

- Deleted `map_info_analysis_runs_without_live_map_metadata`.
  - Rationale: covered the removed test-only `BpfProgram`/`MapProvider` shim.
- Deleted `map_info_analysis_propagates_live_map_lookup_errors`.
  - Rationale: covered the removed test-only live-map provider shim, not the current BBProgram side-input path.
- Deleted `map_info_analysis_preserves_old_fd_binding_after_leading_map_is_deleted`.
  - Rationale: duplicate legacy shim coverage; current BBProgram map binding behavior remains covered in BBProgram tests.

### `bpfopt/crates/bpfopt/src/verifier_log_tests.rs`

- Deleted five `extract_failure_pc_*` tests.
  - Rationale: they tested only a local test helper with no production caller.

## Redundant Assertions Removed

### `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift_tests.rs`

- Removed the local `roundtrip()` helper and all lift/lower equality calls.
  - Rationale: these were redundant lift->lower->eq checks already covered by `bbprogram_roundtrip.rs`; the semantic lift assertions remain.

### `bpfopt/crates/bpfopt/src/passes/map_inline/map_info_tests.rs`

- Removed duplicate `supports_direct_value_access()` assertions in map type tests.
  - Rationale: duplicate coverage in the same test body.

## Wrappers Deleted

### `bpfopt/crates/bpfopt/src/test_helpers.rs`

- Deleted legacy test-only `BpfProgram`, `MapProvider`, `SnapshotMapProvider`, and `build_map_fd_bindings`.
  - Rationale: obsolete BBProgram migration shim with no remaining production path.
- Deleted one-line side-input setter helpers:
  - `ctx_with_annotations`
  - `set_branch_miss_rate`
  - `add_inner_map`
  - `skip_map_snapshot`
  - `set_map_inline_hints`
  - `set_btf_records`
  - Rationale: each only forwarded to direct `PassContext` field mutation.

### `bpfopt/crates/bpfopt/src/pass.rs`

- Deleted test-only re-exports for the removed legacy shim.
- Deleted unused `PassCategory` and the default `BpfPass::category()` method.
- Deleted `PassContext::verifier_states_len()`.
  - Rationale: no real caller after the trivial side-input ownership test was removed.

### `bpfopt/crates/bpfopt/src/main_tests.rs`

- Deleted `registered_call_name()`.
  - Rationale: one-line wrapper around `lookup_by_kinsn_call(...).canonical_name`.

## Tests Kept Despite Review

- Kept BTF metadata tests because they verify remapping semantics and encoded metadata behavior.
- Kept pass behavior tests that assert apply counts, rewritten instruction bytes, skip reasons, error paths, branch fixups, ABI-like sidecar encoding, or cross-pass behavior.
- Kept `bbprogram_roundtrip.rs` and `cli_pipeline.rs` untouched as requested.

## Counts

- Test count: `216` -> `204`.
- Test/helper inventory LOC: `5081` -> `4474` (`-607`).
- Additional production wrapper LOC removed from `pass.rs`: `-22`.
- Net LOC reduction for files changed by this cleanup: `-629`.

## Gate Results

- `cd bpfopt && cargo build --release`: passed.
- `cd bpfopt && cargo test --release`: passed, 204 tests.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: passed.
- `cd bpfopt && cargo fmt --all && cargo fmt --all --check`: passed, 0 diff.
