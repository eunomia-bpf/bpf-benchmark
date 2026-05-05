# Invalidation Removal Summary 2026-05-05
Per-file deletions: daemon/src/invalidation.rs -346; daemon/src/server.rs -332; daemon/src/commands.rs -235; daemon/crates/bpfget/src/lib.rs -39; bpfopt/crates/bpfopt/src/passes/map_inline.rs -20; bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs -20.
Tests removed (10): test_check_unchanged_returns_empty; test_check_changed_returns_affected_progs; test_check_multiple_maps_independent; test_check_missing_entry_invalidates_program; test_remove_prog_clears_entries; test_duplicate_key_updates_value; test_batch_check_efficiency; process_invalidation_tick_reoptimizes_invalidated_programs; process_invalidation_tick_propagates_reoptimization_failures; reoptimization_state_persists_pass_list_for_map_inline_results.
Additional review: daemon/src/commands.rs:680 removed BPF-mutated-map census/skip with tracker; daemon/src/server.rs:58 keeps only socket/watch loop; bpfopt/crates/bpfopt/src/pass.rs:556 drops expected_value; daemon/crates/bpfget/src/lib.rs:37 drops unused map metadata; bpfopt/crates/bpfopt/src/passes/map_inline.rs:813 keeps hash null-check logic, removes invalidation-only diagnostics.
Out-of-scope cleanups: bpfopt/crates/bpfopt/tests/cli_pipeline.rs:223 stale list-passes count 14->15.
Near-net-zero touched: docs/kernel-jit-optimization-plan.md and docs/tmp/bpfopt_design_v3.md remove stale invalidation lifecycle wording; daemon/src/bpf.rs/README/main only module/comment/layout cleanup.
Result reporting: daemon/src/commands.rs:439 collects (map_id,key) records; daemon/src/commands.rs:456 resolves value_hex from the snapshot; daemon/src/commands.rs:839 still fills OptimizeOneResult.inlined_map_entries.
Verification: daemon+bpfopt workspace cargo test pass; release builds pass; clippy pass with pre-existing warnings; root cargo test --workspace cannot run because repo root has no Cargo.toml.
LoC delta with summary: +98/-1033 net -935.
Commit: 8b75920e (https://github.com/eunomia-bpf/bpf-benchmark/commit/8b75920e).
