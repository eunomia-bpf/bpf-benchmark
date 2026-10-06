# Full Repo Review - 2026-03-29

## Scope

- Repo reviewed: `/home/yunwei37/workspace/bpf-benchmark`
- Forbidden paths respected: no edits under `vendor/linux-framework` and no edits under `docs/paper`
- `git -C vendor/linux-framework diff --stat HEAD` returned empty output; no unauthorized kernel-tree changes were present

## Verification Run

- `make daemon-tests`: passed, `527/527`
- `make runner`: passed
- `cargo test` output was warning-free in this run, so the current `daemon` tree meets the "zero cargo warnings" bar for the exercised path

## Overall Status

- Daemon goals: `7/7 PASS`
- E2E goals: `4/5 PASS`, `1 FAIL`
- Corpus goals: `6/6 PASS`
- Source fixes applied in this review: none
- Remaining gap: existing March 29, 2026 E2E artifacts do not yet contain `kinsn_modules` evidence, even though the current code path and tests support it

## Daemon Goals

| Goal | Status | Evidence | Fix / Notes |
| --- | --- | --- | --- |
| 2. Per-pass verify uses `BPF_PROG_LOAD` dry-run, not `REJIT` | PASS | Per-pass verifier callback in `daemon/src/commands.rs:520-560` calls `bpf::bpf_prog_load_verify(...)`; the implementation in `daemon/src/bpf.rs:1405-1527` issues `SYS_bpf(BPF_PROG_LOAD, ...)` and only final apply uses `BPF_PROG_REJIT` in `daemon/src/commands.rs:662-665` / `daemon/src/bpf.rs:1530-1642` | No source change needed |
| 3. Structured per-pass record includes `pass/changed/sites_applied/insn_delta/verify_result/verify_error/action` | PASS | `PassDetail` in `daemon/src/commands.rs:77-97` contains the required fields, and `From<&PassResult>` in `daemon/src/commands.rs:99-129` fills them from pipeline results | No source change needed |
| 4. Rollback only reverts rejected pass and preserves earlier accepted edits | PASS | `run_single_pass()` snapshots the whole pre-pass program, verifies the tentative result, and restores only that snapshot on rejection: `daemon/src/pass.rs:882-940`; fixed-point pass ordering still preserves accepted earlier passes: `daemon/src/pass.rs:791-826`; regression coverage exists in `daemon/src/pass_tests.rs` (`test_verify_rejection_rolls_back_and_continues_pipeline`, `test_verify_rejection_restores_last_accepted_snapshot_before_next_pass`) and passed in `make daemon-tests` | No source change needed |
| 5. `lkm_seeker` `EINVAL` fix via complete `BPF_PROG_LOAD` metadata | PASS | Load metadata reconstruction now captures attach metadata plus full BTF / func info / line info in `daemon/src/bpf.rs:1109-1167`; `populate_prog_load_attr()` forwards `prog_btf_fd`, `func_info*`, `line_info*`, `attach_btf_id`, `attach_fd`, and `fd_array` in `daemon/src/bpf.rs:1452-1495`; explicit unit coverage passed in `daemon/src/bpf_tests.rs` (`test_populate_prog_load_attr_includes_btf_and_debug_info`) | No source change needed |
| 6. BCC DCE fix removes dead-def residue | PASS | `DcePass` now removes unreachable code, dead defs, tail-call-safe dead defs, and nop residue in `daemon/src/passes/dce.rs:30-131`; dead-def elimination runs to a fixed point in `daemon/src/passes/utils.rs:235-288`; pass manager also iterates `const_prop + dce` to fixed point in `daemon/src/pass.rs:791-826` | No source change needed |
| 7. Zero cargo warnings | PASS | `make daemon-tests` completed without Rust warnings in this review, and all `527` daemon tests passed | No source change needed |

## E2E Goals

| Goal | Status | Evidence | Fix / Notes |
| --- | --- | --- | --- |
| 1. 6/6 cases all pass | PASS | Stored March 29, 2026 authoritative outputs all end in top-level `"status": "ok"`: `e2e/results/bcc_authoritative_20260329.json:28000`, `e2e/results/bpftrace_authoritative_20260329.json:9680`, `e2e/results/katran_authoritative_20260329.json:18024`, `e2e/results/scx_authoritative_20260329.json:4454`, `e2e/results/tetragon_authoritative_20260329.json:1433`, `e2e/results/tracee_authoritative_20260329.json:630640` | No source change needed |
| 4. Tracee methodology upgraded to 5 rounds + CI + significance | PASS | Tracee config sets `sample_count: 5` and bootstrap statistics in `e2e/cases/tracee/config.yaml:6-18`; runtime consumes those settings in `e2e/cases/tracee/case.py:1556-1574`, runs per-cycle paired control/baseline/post-rejit measurements in `e2e/cases/tracee/case.py:1641-1909`, and emits significance metadata in `e2e/cases/tracee/case.py:1911-1945`; the stored March 29, 2026 authoritative result shows `sample_count: 5` and `exact_paired_permutation_on_signed_deltas` at `e2e/results/tracee_authoritative_20260329.json:625576-630640` | No source change needed |

## Corpus Goals

| Goal | Status | Evidence | Fix / Notes |
| --- | --- | --- | --- |
| 3. `RLIMIT_NOFILE >= 65536` | PASS | `runner/src/batch_runner.cpp:40` defines the minimum, and `ensure_batch_runner_nofile_limit()` enforces / raises to `65536` in `runner/src/batch_runner.cpp:284-305` | No source change needed |
| 4. `linux-selftests` removed from default corpus | PASS | Default macro corpus only references `linux-selftests` under `optional_manifests` in `corpus/config/macro_corpus.yaml:19-22`; `repo: linux-selftests` entries live in the separate opt-in manifest `corpus/config/macro_corpus_linux_selftests.yaml` and are absent from the default manifest | No source change needed |
| 5. `results.py` uses applied-only geomean as primary metric | PASS | `runner/libs/results.py:254-291` computes `exec_ratio_geomean` from `applied_comparable_pairs`, while `all_exec_ratio_geomean` is tracked separately; corpus markdown also presents applied-only first in `corpus/modes.py:408-419` | No source change needed |

## Review Outcome

- No source regression was reproduced in the required build/test set
- No code edit was necessary to satisfy the checked implementation goals
- The only remaining gap I could confirm is artifact evidence for `kinsn_modules`: the implementation is present and tested, but the stored March 29, 2026 authoritative E2E artifacts in the repo do not yet show it
