# Cascade Integration Test Report

Date: 2026-03-26

## Scope

Added five cascade-focused integration tests in `daemon/src/passes/mod.rs` to verify the `map_inline -> const_prop -> dce` flow with non-zero map values:

- `cascade_map_inline_emits_non_zero_mov_constant`
- `cascade_const_prop_folds_non_zero_map_inline_output`
- `cascade_dce_eliminates_dead_branch_after_const_prop`
- `cascade_full_pipeline_shortens_program_and_preserves_folded_semantics`
- `cascade_hash_map_keeps_null_path_but_folds_non_null_path`

These tests reuse the existing daemon test-only mock map infrastructure (`install_mock_map`, `BpfMapInfo`, `MockMapState`) already used by the map-inline and const-prop unit tests.

## What Was Verified

1. `MapInlinePass` rewrites a non-zero array-map lookup into `mov64_imm(r0, 42)`.
2. `ConstPropPass` folds arithmetic that consumes the map-inlined constant into `mov64_imm(r1, 52)`.
3. `DcePass` removes the dead branch path after `const_prop` proves `val != 0`.
4. The full canonical pipeline preserves the cascade result and shortens the program.
5. Speculative HASH-map inlining folds the non-null path but preserves the null path.

## Verification Runs

Focused cascade run:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml cascade
```

Result:

- Passed: 5
- Failed: 0

Full daemon suite:

```bash
make daemon-tests
```

Result:

- Passed: 448
- Failed: 0
- Ignored: 12

Notes:

- The repo-level `AGENTS.md` says `make <target>` is the canonical full-suite entry point, so the full verification used `make daemon-tests`.
- The focused `cargo test ... cascade` run was kept because the task explicitly requested a cascade-filtered check.

## Warnings

Both verification runs emitted pre-existing `dead_code`-style warnings in unrelated daemon code:

- `src/analysis/cfg.rs`: `SubprogRange.end`
- `src/pass.rs`: `Arch::Aarch64`
- `src/profiler.rs`: `HotnessRanking.observation_window`

No test failures were observed.
