# Round 3 Core Cleanup 2026-04-22

Scope:
- only touched `daemon/src/commands.rs`
- only touched `daemon/src/commands_tests.rs`
- only touched `runner/libs/rejit.py`
- only touched `runner/libs/case_common.py`
- only touched `corpus/driver.py`
- only touched `e2e/driver.py`
- did not run `vm-e2e` or `vm-corpus`

Static checks:
- per-step `python3 -m py_compile` on changed `.py` files: PASS after steps 1-7
- `make check`: PASS
- `cargo test --manifest-path daemon/Cargo.toml`: PASS (`494 passed; 0 failed`)
- `make -C daemon release`: PASS

## 1. Delete `summary.program_changed`, keep top-level `changed`

Changed:
- `daemon/src/commands.rs:106-111,493-526`
  - deleted `OptimizeSummary.program_changed`
  - `make_result(...)` now writes only top-level `changed`
- `daemon/src/commands_tests.rs:65-70,185-190,269-272`
  - removed `program_changed` from `OptimizeSummary` test fixtures
- `runner/libs/rejit.py:582-625`
  - deleted `summary.program_changed` type-check and `changed != summary.program_changed` hard-fail
- `runner/libs/case_common.py:54-78`
  - removed `summary/debug_summary.program_changed` reader branches from `rejit_result_has_any_apply()`
- `corpus/driver.py:455-472`
  - removed `summary/debug_summary.program_changed` reader branches from `_apply_record_changed()`

Deleted fields/functions/constants:
- field: `summary.program_changed`
- hard-fail: `"daemon response fields 'changed' and 'summary.program_changed' disagree"`
- reader branches over `summary.get("program_changed")`

Rename:
- no

Grep verification:
- pattern: `summary\.program_changed|get\("program_changed"\)|summary\.get\("program_changed"\)|debug_summary\.get\("program_changed"\)`
- result: no output

Estimated deleted lines:
- about 25

## 2. Delete synthetic `counts.total_sites` / `counts.applied_sites`

Changed:
- `runner/libs/rejit.py:515-546`
  - deleted `_strict_non_negative_int_field()`
  - deleted `_adjust_counts_from_raw()`
  - `applied_site_totals_from_rejit_result()` now aggregates from `passes`, with a minimal fallback to `summary.total_sites_applied`
- `runner/libs/rejit.py:577-626`
  - `_apply_result_from_response()` no longer synthesizes `counts`
- `runner/libs/rejit.py:766-811`
  - `apply_daemon_rejit()` no longer returns top-level/per-program synthetic `counts`
- `runner/libs/case_common.py:291-349`
  - `_merge_group_rejit_results()` no longer aggregates or emits synthetic `counts`
- `corpus/driver.py:455-472,900-940`
  - removed `counts.applied_sites` read from `_apply_record_changed()`
  - `_slice_rejit_result()` no longer reads or emits `counts.total_sites` / `counts.applied_sites`

Deleted fields/functions/constants:
- helper: `_strict_non_negative_int_field`
- helper: `_adjust_counts_from_raw`
- synthetic field: apply-result `counts.total_sites`
- synthetic field: apply-result `counts.applied_sites`

Rename:
- no

Grep verification:
- pattern: `_adjust_counts_from_raw|_strict_non_negative_int_field|counts\.get\("total_sites"\)|counts\.get\("applied_sites"\)|"counts": \{"total_sites"|\"counts\": zc`
- result: no output

Estimated deleted lines:
- about 70

## 3. Delete `passes[].pass` alias, keep `pass_name`

Changed:
- `daemon/src/commands.rs:122-146`
  - deleted `PassDetail.pass`
  - serializer now emits only `pass_name`
- `runner/libs/rejit.py:455-475`
  - `_accumulate_pass_site_counts()` now accepts only `pass_name`
- `daemon/src/commands_tests.rs:73-105,142-147,192-207,275-309,542-575`
  - removed `pass:` fixture fields
  - serialization assertions now check only `pass_name`

Deleted fields/functions/constants:
- field: `passes[].pass`
- fallback reader: `pass_name_key = "pass_name" if "pass_name" in item else "pass"`

Rename:
- no

Grep verification:
- pattern: `pass_name_key|\["pass"\]|get\("pass"\)|pub pass:|pass: "`
- result: no output

Estimated deleted lines:
- about 22

## 4. Rename `requested_prog_ids` residue to `prog_ids`

Changed:
- `runner/libs/case_common.py:111-113`
  - renamed `CaseLifecycleState.requested_prog_ids()` -> `prog_ids()`
- `runner/libs/case_common.py:261-354,391-462`
  - renamed helper params/locals from `requested_prog_ids` to `prog_ids`
- `runner/libs/rejit.py:766-810`
  - renamed local `requested_prog_ids` -> `prog_ids`
- `corpus/driver.py:900-940,1056-1057,1263-1317`
  - renamed local/helper/session accessor `requested_prog_ids` -> `prog_ids`

Deleted fields/functions/constants:
- accessor name: `requested_prog_ids()`
- variable/parameter name: `requested_prog_ids`

Rename:
- yes

Grep verification:
- pattern: `\brequested_prog_ids\b|requested_prog_ids\(`
- result: no output

Estimated deleted lines:
- about 45 (rename churn; mostly delete+add of the old name)

## 5. Delete pending kinsn metadata overlay

Changed:
- `runner/libs/case_common.py:21-24,142-158`
  - deleted `_PENDING_KINSN_METADATA`
  - deleted `reset_pending_result_metadata()`
  - deleted `attach_pending_result_metadata()`
  - deleted `_append_pending_kinsn_metadata()`
  - `prepare_daemon_session()` / `_clone_daemon_metadata()` now keep only static metadata and `daemon_binary`
- `runner/libs/case_common.py:357-480`
  - `run_case_lifecycle()` no longer writes `captured_at`, `status`, `abort_phase`, queue metadata, or lifecycle overlays
  - metadata passthrough is now plain `{"kinsn_modules": ...}` when enabled
- `runner/libs/rejit.py:827-837`
  - `DaemonSession.start()` no longer writes `daemon_kinsn_discovery` / `status`; keeps `daemon_binary`
- `e2e/driver.py:73-75,506-590`
  - removed pending-metadata attach/reset calls from single-case artifact path
- `corpus/driver.py:22-31,1041-1057,1139-1431`
  - removed pending overlay imports/calls
  - removed per-session `kinsn_metadata` / `kinsn_recorded`
  - kept only top-level `payload["kinsn_modules"] = dict(prepared_daemon_session.metadata)`

Deleted fields/functions/constants:
- constant: `_PENDING_KINSN_METADATA`
- function: `reset_pending_result_metadata`
- function: `attach_pending_result_metadata`
- function: `_append_pending_kinsn_metadata`
- metadata writes: `captured_at`
- metadata writes: `lifecycle_index`
- metadata writes: `count`
- metadata writes: `lifecycle_runs`
- metadata writes: `daemon_kinsn_discovery`
- metadata writes: `abort_phase`
- corpus session fields: `kinsn_metadata`, `kinsn_recorded`

Rename:
- no

Grep verification:
- pattern: `attach_pending_result_metadata|reset_pending_result_metadata|_append_pending_kinsn_metadata|lifecycle_runs|lifecycle_index|abort_phase|daemon_kinsn_discovery|captured_at`
- result: no output
- retained grep: `\bkinsn_modules\b|daemon_binary`
- remaining hits are only the static keepers:
  - `runner/libs/rejit.py:834`
  - `runner/libs/case_common.py:153,398`
  - `corpus/driver.py:1431`

Estimated deleted lines:
- about 135

## 6. Remove tracee EINVAL degradation

Changed:
- `corpus/driver.py:1000-1007`
  - changed `fatal_apply_error` from `bool(apply_error) and not has_comparable_measurement`
  - now any non-empty `apply_error` marks the app result as `status="error"`

Deleted fields/functions/constants:
- none
- deleted conditional degradation branch that masked app-level apply errors

Rename:
- no

Grep verification:
- pattern: `fatal_apply_error = bool\(apply_error\) and not has_comparable_measurement|fatal_apply_error = bool\(apply_error\)`
- result:
  - `1005:    fatal_apply_error = bool(apply_error)`

Estimated deleted lines:
- about 1

## 7. Delete `_suite_cleanup_errors`

Changed:
- `e2e/driver.py:254-259`
  - `_cleanup_suite_temp_paths()` now only `except FileNotFoundError: pass`
  - any other `OSError` now propagates
- `e2e/driver.py:73-75`
  - imports already simplified as part of step 5; no cleanup-error scaffolding remains

Deleted fields/functions/constants:
- attr: `_suite_cleanup_errors`
- stderr diagnostic `print(...)`
- `unlink(missing_ok=True)` fallback behavior

Rename:
- no

Grep verification:
- pattern: `_suite_cleanup_errors|print\(message, file=sys\.stderr\)|unlink\(missing_ok=True\)`
- result: no output

Estimated deleted lines:
- about 8

## Breakage And Fixes

- Removing synthetic apply-side `counts` would have left some consumers with no aggregate site total when only `summary.total_sites_applied` remained. Fixed by teaching `runner/libs/rejit.py:515-546` to fall back to `summary.total_sites_applied` inside `applied_site_totals_from_rejit_result()`.
- Removing the kinsn lifecycle overlay would have dropped all metadata if `kinsn_modules` were deleted wholesale. Fixed by keeping only static passthrough metadata plus `daemon_binary` (`runner/libs/rejit.py:834`, `runner/libs/case_common.py:153,398`, `corpus/driver.py:1431`).
- No additional code/test breakage surfaced after the final static checks.

## Totals

Code diff summary:
- insertions: 111
- deletions: 310
- net: -199

Requested shortstat:
- command: `git diff HEAD --shortstat -- daemon/src/commands.rs daemon/src/commands_tests.rs runner/libs/rejit.py runner/libs/case_common.py corpus/driver.py e2e/driver.py`
- output: `6 files changed, 111 insertions(+), 310 deletions(-)`
