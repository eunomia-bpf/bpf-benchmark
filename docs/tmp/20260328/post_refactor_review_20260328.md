# Post-Refactor Review (2026-03-28)

## Scope

- Review target: today's refactors in `a481d28..HEAD`, plus the current worktree.
- Note: `daemon/src/passes/map_inline.rs`, `daemon/src/passes/map_inline_tests.rs`, and `daemon/src/passes/mod_tests.rs` changed during this review. Validation below uses the final rerun state after those edits.

## Executive Summary

- Final validation status is good: `make daemon-tests` passed (`508/508`) and `python3 -m pytest tests/python/` passed (`38/38`).
- I found 2 real residual issues and 2 cleanup-quality issues.
- The most important remaining bug is a daemon socket protocol mismatch between the Rust daemon and the C++ runner client.

## Findings

### 1. High: C++ daemon socket client still expects the pre-refactor optimize schema

Evidence:

- The daemon now serializes `summary.verifier_rejections` and per-pass `verify`, not `summary.verifier_retries` / `summary.final_disabled_passes`:
  - `daemon/src/commands.rs` lines defining `OptimizeSummary` and `PassDetail`
  - `daemon/src/commands_tests.rs` serialization tests
- The C++ client still hard-requires `summary.final_disabled_passes` and only optionally reads `summary.verifier_retries`:
  - `runner/src/daemon_client.cpp` lines 206-220
- `extract_json_string_array()` throws when the key is missing:
  - `runner/src/json_parser.cpp` lines 315-320
- The runner-side schema still preserves only the old fields and does not carry the new per-pass `verify` data:
  - `runner/include/micro_exec.hpp` lines 115-141
  - `runner/src/common.cpp` lines 952-966

Impact:

- A successful daemon response can still be rejected by the C++ runner path as `invalid daemon JSON`.
- Even after the parse bug is fixed, the runner currently drops the new `verifier_rejections` / per-pass `verify` information on the floor.

Why this matters for today's refactors:

- This directly regresses refactor 4 (`per-pass verify`) from the C++ consumer side.
- It also undermines refactor 3 (`runner C++ dedup`), because the shared client layer is still wired to the old protocol.

Recommendation:

- Update the C++ client schema to the Rust daemon v2 response format.
- Add one end-to-end parser test that feeds a real current optimize JSON blob into the C++ path.

### 2. Medium: `run_case_lifecycle()` breaks explicit empty pass-list semantics

Evidence:

- `e2e/case_common.py` line 368 uses:
  - `enabled_passes=enabled_passes or benchmark_rejit_enabled_passes()`
- Elsewhere in the repo, explicit empty pass lists are intentionally preserved:
  - `tests/python/test_rejit.py`
  - `tests/python/test_corpus_modes.py`
  - `tests/python/test_micro_driver.py`

Impact:

- A caller passing `enabled_passes=[]` will silently run the benchmark default pass set instead of “run no passes”.
- That is an external behavior change introduced by refactor 6 (E2E lifecycle dedup), even if no current case happens to pass `[]`.

Recommendation:

- Distinguish `None` from `[]` in `run_case_lifecycle()`.
- Add a dedicated unit test for this helper.

### 3. Medium: runner C++ dedup is incomplete inside `kernel_runner.cpp`

Evidence:

- Same daemon-summary mapping logic exists three times:
  - `runner/src/kernel_runner.cpp` lines 2135-2153
  - `runner/src/kernel_runner.cpp` lines 3241-3256
  - `runner/src/kernel_runner.cpp` lines 3680-3694

Impact:

- Protocol changes need to be updated in multiple places.
- The stale `verifier_retries` / `final_disabled_passes` fields survived in all copies, which is likely how finding 1 slipped through.

Recommendation:

- Keep a single helper and delete the two duplicated inline copies.

### 4. Low: serve-only CLI cleanup is functionally fine, but not fully clean

What I checked:

- `daemon/src/main.rs` now exposes only `Serve`.
- I did not find residual references to removed CLI verbs (`watch`, `apply-all`, `enumerate`, `rewrite`) in the live command surface.

Residual cleanup issue:

- `daemon/src/passes/mod.rs` still has `PassRegistryEntry.description` and `available_passes_help()`, but they are unused after the serve-only CLI simplification.
- This shows up in the warning set and looks like leftover CLI-help infrastructure.

Recommendation:

- Remove or explicitly gate the unused help-path code.

## Review By Requested Refactor

### 1. `corpus/modes.py` split to `runner/libs/*`

- Current `corpus/modes.py` imports cleanly and re-exports the moved helpers through module-level imports.
- `tests/python/test_corpus_modes.py` passes.
- I did not find a lost-function regression in the current state.

### 2. daemon CLI serve-only

- `daemon/src/main.rs` is clean: one subcommand, `Serve`.
- The only residue I found is unused helper/help code, not live dead references to removed CLI verbs.

### 3. runner C++ dedup

- Both `kernel_runner` and `batch_runner` now use the shared `daemon_client.cpp`, `json_parser.cpp`, and `bpf_helpers.cpp` layer.
- However, in-file dedup is incomplete and the shared client still speaks the old daemon schema.

### 4. per-pass verify

- Static review of `PassManager::run_single_pass()` looks correct: changed pass, verify callback, reject => rollback to pre-pass snapshot, continue pipeline.
- The old attribution / retry helpers are gone.
- `make daemon-tests` passes on the final rerun, including the pass-manager verification tests.
- I did not find a current correctness bug here.

### 5. PGO socket protocol

- `serve` handles `profile-start`, `profile-stop`, `profile-save`, and `profile-load`.
- `ProfilerSession::start()` / `stop()` lifecycle looks coherent.
- `server::tests::process_request_profile_save_and_load_round_trip` passes.
- I did not find a current protocol/lifecycle bug here.

### 6. E2E case scaffold dedup

- All 6 cases use `run_case_lifecycle()`:
  - `bcc`, `bpftrace`, `katran`, `scx`, `tetragon`, `tracee`
- The only behavior regression I found is the explicit-empty-pass-list bug in finding 2.

### 7. mutable writeback guard site-local

- `collect_mutable_maps_with_lookup_value_writes()` is gone.
- I found no residual implementation references.
- The current logic is site-local (`mutable lookup result has non-load uses`), and the targeted `map_inline` tests pass in the final rerun.
- I did not find a current safety gap here.

## Validation

- `make daemon-tests`
  - Final rerun status: pass
  - Result: `508 passed; 0 failed`
  - Log: `/tmp/bpf_benchmark_make_daemon_tests_rerun_20260328.log`
- `python3 -m pytest tests/python/`
  - Status: pass
  - Result: `38 passed`
  - Log: `/tmp/bpf_benchmark_pytest_20260328.log`
- `cargo build --manifest-path daemon/Cargo.toml`
  - Status: pass
  - Result: `12 warnings`
  - Log: `/tmp/bpf_benchmark_cargo_build_daemon_rerun_20260328.log`

## Daemon Cargo Warnings (12)

Current source build really does emit 12 warnings. `make daemon-tests` only shows 7 because the test build references some symbols that the plain build does not.

1. `src/bpf.rs:1160` `get_orig_insns_by_id` is never used.
Verdict: should fix. This looks like dead code.

2. `src/pass.rs:367` `SkipReason.pc` is never read.
Verdict: should fix if the field is not going to be surfaced or consumed.

3. `src/pass.rs:732` `PassManager::run` is never used.
Verdict: low priority, but should be cleaned up or annotated.

4. `src/passes/mod.rs:44` `PassRegistryEntry.description` is never read.
Verdict: should fix. This is likely residue from the removed CLI help path.

5. `src/passes/mod.rs:121` `available_passes_help` is never used.
Verdict: should fix. Same residue as above.

6. `src/profiler.rs:49` `ProgStatsDelta.{prog_id, elapsed, after, avg_ns}` are never read.
Verdict: low priority, but this is dead API surface today.

7. `src/profiler.rs:85` `PgoAnalysis.{prog_id, delta_run_time_ns, delta_avg_ns}` are never read.
Verdict: low priority, but also dead surface today.

8. `src/profiler.rs:94` `PgoAnalysis::{from_delta, hotness_score}` are never used.
Verdict: low priority unless the old hotness-ranking path is meant to stay.

9. `src/profiler.rs:132` `HotnessRanking::from_analyses` is never used.
Verdict: low priority.

10. `src/profiler.rs:475` `collect_program_profiling` is never used.
Verdict: medium priority. Either wire it into the current PGO flow or delete it.

11. `src/profiler.rs:508` `ProgStatsPoller` is never constructed.
Verdict: medium priority. Strong sign the standalone poller path is now dead.

12. `src/profiler.rs:515` `ProgStatsPoller::{open, poll_stats, snapshot, poll_delta, collect_deltas}` are never used.
Verdict: medium priority. Same dead-path cluster as 10 and 11.

## Grep Audit

- No hits for:
  - `collect_mutable_maps_with_lookup_value_writes`
  - `TransformAttribution`
  - `attribute_verifier_failure`
  - `should_retry_post_verify_rejit_failure`
  - `attribute_post_verify_rejit_failure`
- `run_case_lifecycle(` appears in all 6 case files.
- Residual old-protocol fields still exist in runner code:
  - `verifier_retries`
  - `final_disabled_passes`

## Bottom Line

- The big refactors mostly landed cleanly in the current final state: imports work, serve-only daemon works, per-pass verify looks correct, PGO socket lifecycle looks coherent, all 6 E2E cases use the shared lifecycle, mutable writeback logic is now site-local, and both requested test suites pass.
- The main remaining correctness bug is the Rust-daemon/C++-runner protocol mismatch.
- The main remaining API/behavior regression is the explicit-empty-pass-list handling in `run_case_lifecycle()`.
