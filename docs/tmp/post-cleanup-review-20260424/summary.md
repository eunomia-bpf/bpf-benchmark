# Post-cleanup Review: `30c43b2e`

Date: 2026-04-24

## Findings

- No blocking regression or obvious new issue found in `30c43b2e` from static review, `rg` caller search, and `python -m py_compile`.
- If “遗漏没删的” is interpreted against the full `docs/tmp/dead-code-review-20260424/summary.md`, the only items still present are the Section 5 abstraction-layer findings. Those are still in tree, but they are not dead-code/helper-merge misses introduced by this commit.

## 1. Deleted Functions: caller search

I searched the tree with `rg` excluding `docs/tmp/**` and `__pycache__/**` for the removed symbols:

- `write_json`
- `dup_fd_from_process`
- `capture_daemon_kinsn_discovery`
- `describe_agent_exit`
- `scan_site_totals_for_passes`
- `benchmark_policy_candidate_passes`
- `resolve_program_enabled_passes`
- `_policy_context_text`
- `_policy_rule_matches`
- `_site_counts_from_optimize_response`
- `process_fd`
- `runner.libs.process_fd`

Result:

- No remaining callers/importers were found.
- This matches the cleanup intent: the deleted functions really were unreferenced in the current tree.

## 2. Merged helpers in `case_common.py`: import/use check

Centralized helper definitions are present in `runner/libs/case_common.py:23`, `runner/libs/case_common.py:28`, `runner/libs/case_common.py:43`, `runner/libs/case_common.py:49`, `runner/libs/case_common.py:59`, and `runner/libs/case_common.py:73`.

Validated current case usage:

- `e2e/cases/bcc/case.py:20` imports `append_json`, `ensure_daemon_binary`, `lifecycle_programs`, `merge_programs`, `phase_payload`, `program_records`; they are used at `e2e/cases/bcc/case.py:58`, `e2e/cases/bcc/case.py:81`, `e2e/cases/bcc/case.py:84`, `e2e/cases/bcc/case.py:85`, `e2e/cases/bcc/case.py:86`, `e2e/cases/bcc/case.py:116`, `e2e/cases/bcc/case.py:126`, and `e2e/cases/bcc/case.py:149`.
- `e2e/cases/bpftrace/case.py:21` imports the same helper set; they are used at `e2e/cases/bpftrace/case.py:75`, `e2e/cases/bpftrace/case.py:100`, `e2e/cases/bpftrace/case.py:103`, `e2e/cases/bpftrace/case.py:104`, `e2e/cases/bpftrace/case.py:105`, `e2e/cases/bpftrace/case.py:133`, `e2e/cases/bpftrace/case.py:143`, and `e2e/cases/bpftrace/case.py:158`.
- `e2e/cases/katran/case.py:19` imports the subset it needs: `lifecycle_programs`, `phase_payload`, `program_records`; they are used at `e2e/cases/katran/case.py:84`, `e2e/cases/katran/case.py:101`, `e2e/cases/katran/case.py:102`, and `e2e/cases/katran/case.py:108`.
- `e2e/cases/tetragon/case.py:21` now imports `ensure_daemon_binary` from common code and uses it at `e2e/cases/tetragon/case.py:149`.
- `e2e/cases/tracee/case.py:26` now imports `ensure_daemon_binary` from common code and uses it at `e2e/cases/tracee/case.py:219`.

Residual duplicate-helper check:

- `rg` no longer finds `def ensure_artifacts`, `def phase_payload`, `def lifecycle_programs`, `def merge_programs`, `def append_json`, or `def program_records` in the targeted case files.
- The only remaining hits are `runner/libs/case_common.py` itself plus `e2e/cases/scx/case.py:29` and `e2e/cases/scx/case.py:46`. Those SCX helpers were not part of the duplicate-helper set flagged in the earlier review.

## 3. `python -m py_compile`

Ran `python -m py_compile` on every non-deleted file changed by `30c43b2e`:

- `e2e/cases/bcc/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/katran/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/tracee/case.py`
- `runner/libs/__init__.py`
- `runner/libs/app_runners/tetragon.py`
- `runner/libs/case_common.py`
- `runner/libs/kinsn.py`
- `runner/libs/rejit.py`

Result:

- Compile succeeded for all of them.

## 4. Comparison with `docs/tmp/dead-code-review-20260424/summary.md`

Addressed from the earlier review:

- Section 2 dead fallback branches in BCC, bpftrace, and Katran were removed.
- Section 3 dead code items called out in `runner/libs/__init__.py`, `runner/libs/app_runners/tetragon.py`, `runner/libs/kinsn.py`, `runner/libs/process_fd.py`, and `runner/libs/rejit.py` were removed.
- Section 4 duplicate helper definitions were merged into `runner/libs/case_common.py`.

Still present from the earlier review:

- `runner/libs/case_common.py:269` and `runner/libs/case_common.py:336` still keep the `run_case_lifecycle()` / `run_app_runner_lifecycle()` wrapper stack.
- `e2e/cases/tetragon/case.py:190`, `e2e/cases/tetragon/case.py:233`, and `e2e/cases/tetragon/case.py:236` still use the nested `setup/start/workload/stop/cleanup` closure style.
- `e2e/cases/tracee/case.py:269`, `e2e/cases/tracee/case.py:311`, and `e2e/cases/tracee/case.py:314` still do the same.
- `e2e/cases/scx/case.py:341`, `e2e/cases/scx/case.py:343`, `e2e/cases/scx/case.py:347`, and `e2e/cases/scx/case.py:349` still keep the lambda-heavy wrapper usage.

Interpretation:

- I do not treat the above as missed deletions for this commit, because they are the Section 5 abstraction findings, not dead-code/helper-merge items.
- Within the dead-code and helper-merge scope, I did not find an additional missed deletion.

## 5. New issues introduced by this commit

- None found from this review.

Residual risk:

- This was a static review only. I did not run the affected e2e cases, so runtime behavior against real daemons/runners is not covered here.
