# Dead Code / Complexity Review (2026-04-24)

- Scope reviewed: `runner/libs/`, `e2e/cases/`, `corpus/`, `runner/suites/`
- Excluded as requested: `__pycache__/`, `e2e/results/`, `corpus/results/`, `docs/tmp/`, `runner/repos/`, `runner/build*`
- Basis: current working tree on disk, `rg`/manual inspection, plus `pyflakes` for unused imports

## 1. Silent skip

- No live silent-skip flow is left in the current scoped Python code. I did not find any active `skip_reason` / `LifecycleAbort` / `status="skipped"` path.
- The only `abort`-named helper in scope is the fail-fast local `_abort()` in `runner/libs/workload.py:657`, `runner/libs/workload.py:659`, `runner/libs/workload.py:660`, `runner/libs/workload.py:661`; it raises immediately and is not a silent skip.

## 2. Fallback / Defensive Redundancy

- `e2e/cases/bcc/case.py:75`, `e2e/cases/bcc/case.py:77`, `e2e/cases/bcc/case.py:80`
  `workload()` still handles the `"no BPF programs are attached"` case, but `build_state()` already rejects empty `started_prog_ids` before the workload phase runs. Once `run_app_runner_lifecycle()` returns successfully, this branch is unreachable.

- `e2e/cases/bpftrace/case.py:108`, `e2e/cases/bpftrace/case.py:110`, `e2e/cases/bpftrace/case.py:93`
  Same dead fallback as BCC: `workload()` defends against missing `prog_ids`, but `build_state()` already guarantees non-empty `prog_ids` or raises.

- `e2e/cases/bcc/case.py:111`, `e2e/cases/bcc/case.py:112`, `e2e/cases/bcc/case.py:114`, `e2e/cases/bcc/case.py:115`
  The `baseline is None` / `post_rejit is None` repair branches are redundant after `run_app_runner_lifecycle()`. The helper stack already raises instead of returning a missing phase result.

- `e2e/cases/bpftrace/case.py:129`, `e2e/cases/bpftrace/case.py:130`, `e2e/cases/bpftrace/case.py:132`, `e2e/cases/bpftrace/case.py:133`
  Same redundant phase-repair logic as BCC.

- `e2e/cases/katran/case.py:118`, `e2e/cases/katran/case.py:119`, `e2e/cases/katran/case.py:126`, `e2e/cases/katran/case.py:127`
  Same redundant `baseline` / `post_rejit` reconstruction after `run_app_runner_lifecycle()`.

- `runner/libs/case_common.py:223`, `runner/libs/case_common.py:245`, `runner/libs/case_common.py:247`, `runner/libs/case_common.py:271`, `runner/libs/case_common.py:284`
  The reason the above branches are dead is contractual: `run_case_lifecycle()` / `run_app_runner_lifecycle()` raise when a phase is missing instead of returning a partial success object. The case files still re-check for impossible `None` states after the helper already enforced them.

- `e2e/cases/katran/case.py:91`, `e2e/cases/katran/case.py:92`, `e2e/cases/katran/case.py:97`
  `getattr(lifecycle, "prog_ids", []) or []` is defensive noise under the same contract. `build_state()` already guarantees `prog_ids` exist before `workload()` can run.

## 3. Dead Code

- `runner/libs/__init__.py:7`
  `timezone` is imported but unused.

- `runner/libs/app_runners/tetragon.py:5`
  `time` is imported but unused.

- `runner/libs/rejit.py:10`, `runner/libs/rejit.py:616`
  `field` is imported from `dataclasses` but never used; later a loop variable named `field` shadows the import, which hides the dead import.

- `runner/libs/__init__.py:148`
  `write_json()` has no call site anywhere in the repository.

- `runner/libs/process_fd.py:10`
  `dup_fd_from_process()` has no call site anywhere in the repository.

- `runner/libs/kinsn.py:189`
  `capture_daemon_kinsn_discovery()` has no call site anywhere in the repository.

- `runner/libs/app_runners/tetragon.py:92`
  `describe_agent_exit()` has no call site anywhere in the repository.

- `runner/libs/rejit.py:284`
  `scan_site_totals_for_passes()` has no call site anywhere in the repository.

- `runner/libs/rejit.py:403`
  `benchmark_policy_candidate_passes()` has no call site anywhere in the repository.

- `runner/libs/rejit.py:425`
  `resolve_program_enabled_passes()` has no call site anywhere in the repository.

- `runner/libs/rejit.py:259`, `runner/libs/rejit.py:299`, `runner/libs/rejit.py:425`
  `_policy_context_text()` and `_policy_rule_matches()` are only reachable through unused `resolve_program_enabled_passes()`, so this policy-resolution branch is transitively dead in the current tree.

- `runner/libs/rejit.py:539`
  `_site_counts_from_optimize_response()` has no call site anywhere in the repository.

## 4. Duplicate Definitions

- `e2e/cases/bcc/case.py:23`, `e2e/cases/bpftrace/case.py:32`, `e2e/cases/tracee/case.py:36`, `e2e/cases/tetragon/case.py:47`
  `ensure_artifacts()` is duplicated four times with the same “daemon binary must exist” check.

- `e2e/cases/bcc/case.py:33`, `e2e/cases/bpftrace/case.py:53`, `e2e/cases/katran/case.py:57`
  `phase_payload()` is byte-for-byte the same helper in three case files.

- `e2e/cases/bcc/case.py:43`, `e2e/cases/bpftrace/case.py:63`
  `lifecycle_programs()` is duplicated exactly.

- `e2e/cases/katran/case.py:67`, `e2e/cases/katran/case.py:71`
  Katran keeps the same `lifecycle_programs()` idea behind an extra `_programs()` wrapper; this is the same helper split into two layers.

- `e2e/cases/bcc/case.py:47`, `e2e/cases/bpftrace/case.py:67`
  `merge_programs()` is duplicated exactly.

- `e2e/cases/bcc/case.py:134`, `e2e/cases/bpftrace/case.py:152`
  `append_json()` is duplicated exactly.

## 5. Unnecessary Abstraction Layers

- `runner/libs/case_common.py:220`, `runner/libs/case_common.py:223`, `runner/libs/case_common.py:224`, `runner/libs/case_common.py:247`
  `run_case_lifecycle()` is mostly a one-session adapter around `run_lifecycle_sessions()`. It creates lambdas only to thread `setup_state` through and then unwraps the single returned result.

- `runner/libs/case_common.py:271`, `runner/libs/case_common.py:280`, `runner/libs/case_common.py:284`
  `run_app_runner_lifecycle()` adds a second wrapper layer on top of `run_case_lifecycle()`, again mostly converting `runner.start()`, `measure()`, and `runner.stop()` into another lambda-shaped interface.

- `e2e/cases/tracee/case.py:276`, `e2e/cases/tracee/case.py:279`, `e2e/cases/tracee/case.py:313`, `e2e/cases/tracee/case.py:318`, `e2e/cases/tracee/case.py:321`
  Tracee pays for that abstraction with nested `setup/start/workload/stop/cleanup` closures, even though `setup()` only returns `{}` and `cleanup()` is a no-op.

- `e2e/cases/tetragon/case.py:197`, `e2e/cases/tetragon/case.py:200`, `e2e/cases/tetragon/case.py:234`, `e2e/cases/tetragon/case.py:240`, `e2e/cases/tetragon/case.py:243`
  Tetragon has the same boilerplate closure stack for the same reason.

- `e2e/cases/scx/case.py:299`, `e2e/cases/scx/case.py:315`, `e2e/cases/scx/case.py:341`, `e2e/cases/scx/case.py:343`, `e2e/cases/scx/case.py:346`, `e2e/cases/scx/case.py:347`, `e2e/cases/scx/case.py:349`
  SCX also has to thread state through closure wrappers and trivial lambdas (`setup=lambda: {}`, `cleanup=lambda _: None`, `resolve_rejit_prog_ids=lambda *_args: list(live_prog_ids)`), which is a strong sign that the lifecycle abstraction is more generic than the call sites actually need.

## Notes

- I did not flag `sys.argv[1:] if argv is None else argv` or `env is None else env` patterns in CLI/entrypoint code; those are real optional-argument branches, not dead defensive code.
- I also did not flag the many `or []` uses in `runner/libs/rejit.py`; there the helper `_policy_pass_list()` explicitly returns `list | None`, so those call sites are exercising a real nullable API rather than impossible fallback logic.
