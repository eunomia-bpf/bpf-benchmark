# Review Delete A Summary

Base context: work started from `014ed4aa` on `main`. During the pass, concurrent work advanced `main` to `75ea0fdd` (`[review-B] delete e2e micro vendor leftovers`), so this commit is based on that HEAD and does not revert any concurrent changes.

## Line Counts

Scope files changed:

| Path | Added | Deleted |
| --- | ---: | ---: |
| `runner/libs/__init__.py` | 2 | 7 |
| `runner/libs/app_runners/__init__.py` | 1 | 11 |
| `runner/libs/app_runners/base.py` | 0 | 3 |
| `runner/libs/app_runners/katran.py` | 5 | 22 |
| `runner/libs/benchmarks.py` | 6 | 18 |
| `runner/libs/bpf_stats.py` | 7 | 23 |
| `runner/libs/case_common.py` | 12 | 34 |
| `runner/libs/environment.py` | 0 | 8 |
| `runner/libs/input_generators.py` | 17 | 44 |
| `runner/libs/metrics.py` | 0 | 12 |
| `runner/libs/process_fd.py` | 0 | 3 |
| `runner/libs/results.py` | 1 | 70 |
| `runner/libs/run_artifacts.py` | 28 | 94 |
| `runner/libs/state_file.py` | 0 | 49 |
| `runner/libs/statistics.py` | 0 | 25 |

Total: 79 added, 423 deleted, net -344 lines.

## Deleted Symbols

- `runner/libs/results.py`: removed unused TypedDict exports `CodeSizeSummary`, `PerfCounterMeta`, `RejitSummary`, `RunnerSample`; removed unused `load_json`; removed statistics re-export imports.
- `runner/libs/statistics.py`: removed unused `float_summary`.
- `runner/libs/metrics.py`: removed unused bpf_stats re-export imports and `__all__`.
- `runner/libs/bpf_stats.py`: removed unused public `read_program_stats`; removed private `_bpftool_command`; removed `__all__`.
- `runner/libs/state_file.py`: removed unused `merge_state`; removed unused CLI `main`; removed unused `sys` import.
- `runner/libs/case_common.py`: removed public-but-unreferenced `aggregate_scan_site_totals`; removed private `_current_program_ids`; removed private `_lifecycle_metadata_payload`.
- `runner/libs/input_generators.py`: removed `_build_simple_lcg_u64_ii`, `_build_branch_flip_dense`, `_build_extract_dense`; removed generator globals injection boilerplate.
- `runner/libs/run_artifacts.py`: removed `result_root_for_output`, `create_run_artifact_dir`, `update_run_artifact`, `_read_proc_start_ticks`, `_read_boot_id`.
- `runner/libs/benchmarks.py`: removed unused protocol/type boilerplate `BenchmarkLike`, `SuiteLike`, `BenchmarkT`.
- `runner/libs/app_runners/katran.py`: removed one-use helpers `default_katran_balancer_prog_path`, `default_katran_server_binary_path`, `_program_name_variants`, `pack_mac`, `_bytes_to_hex_args`.
- `runner/libs/app_runners/__init__.py`, `runner/libs/app_runners/base.py`, `runner/libs/environment.py`, `runner/libs/process_fd.py`: removed unused `__all__` / registry typing boilerplate.
- `runner/libs/__init__.py`: removed `result_date_stamp`.

## Merged / Inlined Boilerplate

- `simple_lcg_u64_ii`, `dep_chain`, `multi_acc`, `stride_load`, `large_mixed`, and `load_isolation` now share `_build_lcg_u64_ii`; the deleted simple builder was only parameter defaulting and metadata naming.
- `branch_flip_dense` and `extract_dense` now map directly to the existing groups/lanes generator path instead of maintaining wrapper functions.
- `read_program_stats` was inlined into `sample_bpf_stats`; no external caller referenced the old public helper.
- `aggregate_scan_site_totals` was inlined into `run_app_runner_phase_records`; no external caller referenced it.
- Artifact directory creation and artifact JSON updates were inlined into `ArtifactSession`, which was the only user of those helpers.
- Proc identity reads were inlined into `current_process_identity`.
- Katran path/name/byte helpers were inlined at their single call sites.

## `case_common.py` Public Symbol Review

Removed public symbol:

- `aggregate_scan_site_totals`: no non-doc, non-vendor references found outside `case_common.py`; only internal caller was `run_app_runner_phase_records`, so it was inlined and deleted.

Kept public symbols because they still have live callers:

- `reset_pending_result_metadata`: corpus/e2e driver flow.
- `attach_pending_result_metadata`: corpus/e2e driver flow.
- `wait_for_suite_quiescence`: corpus/e2e driver flow.
- `rejit_result_has_any_apply`, `rejit_program_result`: e2e/corpus REJIT result handling.
- `CaseLifecycleState`, `PreparedDaemonSession`, `LifecycleAbort`, `LifecycleRunResult`: lifecycle orchestration and app runner call contracts.
- `prepare_daemon_session`, `run_case_lifecycle`, `run_app_runner_lifecycle`: corpus/e2e case lifecycle entry points.
- `measure_app_runner_workload`, `run_app_runner_phase_records`, `zero_site_totals`: app runner metric collection.
- `git_sha`, `host_metadata`, `summarize_numbers`, `percent_delta`, `percentile`, `speedup_ratio`: reporting and e2e result summaries.

## Candidates Left

- The target of 1500 deleted lines was not reachable from safe dead-code removal in this scope. Remaining large blocks are live through config-driven input generator names, corpus/e2e lifecycle entry points, or app runner contracts.
- `results.py` could be folded further if off-scope callers stop importing it.
- `run_artifacts.py` could be simplified more, but further deletion would change the artifact session API rather than just remove dead code.
- `katran.py` still has large setup/test-run logic, but splitting or deleting more would be a behavior rewrite.
- `case_common.py` remains broad, but the remaining public helpers have live callers; further work should be a coordinated owner refactor, not this delete pass.

## Off-Scope Patches

No pending off-scope patch files. Import cleanups that would otherwise have been needed in off-scope callers were already present in concurrent HEAD `75ea0fdd`, so there was nothing left to write under `offscope-patches/`.

## Verification

- `python -m compileall runner/libs runner/libs/app_runners`: passed.
- `python -c "from runner.libs import run_target_suite, case_common, reporting, kinsn, rejit"`: passed.
