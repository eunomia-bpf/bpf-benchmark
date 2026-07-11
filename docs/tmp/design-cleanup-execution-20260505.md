# Design Cleanup Execution, 2026-05-05

## Per-Item Execution

DONE: daemon/src/commands.rs:530 — delete — Delta -14 / +0 lines — removed optimize snapshot id and instruction-count cross-checks.
DONE: daemon/src/commands.rs:713 — delete — Delta -25 / +0 lines — removed candidate kop output scan guard and its helper/test.
DONE: bpfopt/crates/bpfopt/src/main.rs:263 — delete — Delta -28 / +2 lines — removed bpfopt/pass panic-catching wrappers.
DONE: daemon/src/commands.rs:447 and daemon/src/server.rs:79 — delete — Delta -67 / +9 lines — removed daemon request/worker panic recovery.
DONE: bpfopt/crates/bpfprof/src/main.rs:982 — refactor — Delta -17 / +20 lines — removed impossible slice-length-changed error branches.
DONE: runner/libs/rejit.py:649 — delete — Delta -44 / +6 lines — removed runner summary-vs-pass defensive cross-checks.
DONE: bpfopt/crates/bpfopt/src/passes/map_inline.rs:94 — rename — Delta -8 / +8 lines — renamed FrozenMapValue to SnapshotMapValue and resolve_snapshot_map_value.
DONE: bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:348 — rename — Delta -2 / +2 lines — renamed frozen pseudo-map-value tests to snapshot wording.
DONE: bpfopt/crates/bpfopt/src/pass.rs:538 — delete — Delta -8 / +0 lines — removed PassResult::skip_reason_counts.
DONE: bpfopt/crates/bpfopt/src/pass.rs:637 — delete — Delta -25 / +20 lines — removed implicit packed-call encoding fallback and required explicit target encodings.
DONE: bpfopt/crates/bpfopt/src/main.rs:332 — delete — Delta -25 / +3 lines — removed unchanged_report fallback for missing pass reports.
DONE: bpfopt/crates/bpfprof/src/main.rs:578 — refactor — Delta -5 / +13 lines — changed relative_branch_target to propagate conversion errors.
DONE: runner/libs/rejit.py:276 — delete — Delta -130 / +20 lines — removed legacy sites_found/action/summary compatibility fallbacks.
DONE: daemon/src/commands.rs:993 — delete — Delta -29 / +1 lines — removed map-scan overflow warning-and-continue path.
DONE: daemon/src/commands.rs:126 — delete — Delta -52 / +1 lines — removed OptimizeSummary, passes_applied, and per-program derived counts.
DONE: daemon/src/server.rs:230 — delete — Delta -29 / +4 lines — removed multi-program program_counts rollup.
DONE: runner/libs/rejit.py:473 — delete — Delta -109 / +8 lines — removed runner site aggregation and summary/program-count artifact fields.
DONE: bpfopt/crates/bpfopt/src/pass.rs:786 — delete — Delta -70 / +0 lines — removed PipelineResult.total_sites_applied and related assertions.
DONE: corpus/driver.py:153 — delete — Delta -98 / +3 lines — removed result.md generation and stale Python assertions.
DONE: runner/src/common.cpp:60 — delete — Delta -7 / +1 lines — removed code_size.inflation_ratio.
DONE: docs/bpfrejit-story.md:182 — refactor — Delta -1 / +1 lines — rewrote stale map invalidation story to snapshot benchmark wording.
DONE: bpfopt/crates/bpfopt/src/pass_tests.rs:473 — delete — Delta -25 / +0 lines — deleted trivial kop registry call-offset test.
DONE: bpfopt/crates/bpfopt/src/pass_tests.rs:651 — delete — Delta -37 / +0 lines — deleted skip_reason_counts test with the dead helper.
DONE: bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:482 — delete — Delta -29 / +0 lines — deleted duplicate cond_select register alias test.
DONE: bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:689 — delete — Delta -29 / +0 lines — deleted duplicate cond_select r1/r2 alias-cycle test.
DONE: bpfopt/crates/bpfopt/src/passes/rotate.rs:650 — delete — Delta -118 / +5 lines — deleted pass-manager plumbing tests and now-dead test helpers/imports across rotate, wide_mem, extract, endian, and prefetch.
DONE: runner/src/bpf_helpers.cpp:23 — move — Delta -22 / +13 lines — replaced direct BPF_OBJ_GET_INFO_BY_FD syscalls with libbpf bpf_obj_get_info_by_fd.
DONE: daemon/src/commands.rs:137 — delete — Delta -0 / +0 lines — skipped_maps informational field deletion was covered by the map-scan fail-fast delete above.

## Items Not Executed

None. All 28 HIGH/MED/LOW design-review rows were executed. The concurrent try_apply_one pass-loop body was not edited beyond the non-loop regions explicitly listed in the task.

## Diff Totals

Exact staged git numstat for the commit, excluding pre-existing generated corpus results and docs/paper submodule dirt:

- Total lines deleted: 1100
- Total lines added: 254
- Net LoC delta: -846

Cleanup-only code/doc delta excluding this report file: 1100 deleted, 187 added, net -913.

## Test Counts

- Cargo test before: not rerun before edits; inferred from deleted test inventory as bpfopt 415 and daemon 28, total 443.
- Cargo test after: bpfopt 406 and daemon 26, total 432.
- Cargo test delta: -11 tests, matching the deleted trivial/plumbing daemon+bpfopt tests.

## Validation

- PASS: cargo build --release --workspace --manifest-path bpfopt/Cargo.toml
- PASS: cargo build --release --workspace --manifest-path daemon/Cargo.toml
- PASS: cargo test --release --workspace --manifest-path bpfopt/Cargo.toml
- PASS: cargo test --release --workspace --manifest-path daemon/Cargo.toml
- PASS: C++ runner project target BPFREJIT_IMAGE_BUILD=1 make image-runner-artifacts
- NOTE: make -C runner is not a valid target in this tree because runner/ has no Makefile.
- PASS: python -m pytest tests/python/ -v (17 passed, 1 subtest passed)
- Smoke: deferred; concurrent try_apply_one refactor completion was not confirmed.

## Commit

- Commit hash(es): final pushed commit hash is reported after commit in the final response; a commit cannot embed its own hash in a tracked report file.
