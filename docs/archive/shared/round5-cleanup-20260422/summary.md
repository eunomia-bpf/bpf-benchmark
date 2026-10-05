# Round 5 Cleanup 2026-04-22

Status: completed

Scope:
- No VM targets were run.
- No commit / push.
- Required docs were read first:
  - `docs/tmp/round34-verification-20260422/summary.md`
  - `docs/tmp/round3-core-20260422/summary.md`
  - `docs/tmp/round3-cases-20260422/summary.md`
  - `docs/tmp/round4-python-20260422/summary.md`
  - `docs/tmp/round4-daemon-20260422/summary.md`
  - `docs/kernel-jit-optimization-plan.md`

Validation:
- Per-step `python3 -m py_compile` after `R1` through `R9`: PASS
- `make check`: PASS
- `cargo test --manifest-path daemon/Cargo.toml`: PASS (`494 passed; 0 failed`)
- Not run:
  - `make vm-e2e`
  - `make vm-corpus`

Actual line-count note:
- `实际删除行数` below means the local hunk-deletion count for this turn only.
- `git diff --shortstat` is the required command output against `HEAD`; these files already carried prior Round 3/4 edits, so that command is cumulative, not Round-5-exclusive.

## R1

- Files/lines:
  - `runner/libs/app_runners/__init__.py:9-17,20-28,31-40,43-48,51-56,59-63,76-90`
  - `corpus/driver.py:1077-1081`
- 删前/删后:
  - six `_adapt_*()` helpers accepted `app_name` and immediately discarded it; now every adapter only accepts `workload` + `kwargs`
  - `get_app_runner()` no longer exposes `app_name`
  - corpus caller now does `get_app_runner(app.runner, workload=..., **app.args)` directly
- 实际删除行数: `15`
- grep 验证:
  - `rg -n 'app_name\\s*:|app_name=' runner/libs/app_runners/__init__.py`
  - `rg -n 'app_name=' corpus/driver.py`
  - Result: no matches

## R2

- Files/lines:
  - `runner/libs/rejit.py:560-572`
  - `runner/libs/case_common.py:204-211,598-602`
- 删前/删后:
  - `scan_programs()` no longer emits both `"sites"` and `"counts"` from the same dict; only canonical `"counts"` remains
  - `_scan_record_counts()` and `run_app_runner_phase_records()` now read only `"counts"`
- 实际删除行数: `5`
- grep 验证:
  - `rg -n '"sites"|get\\("sites"\\)|record\\.get\\("sites"\\)' runner/libs/rejit.py runner/libs/case_common.py`
  - Result: no matches

## R3

- Files/lines:
  - `runner/libs/rejit.py:220-239`
- 删前/删后:
  - `_site_count_for_pass()` used to probe both canonical `*_sites` and bare pass names
  - now it accepts only the canonical counter field from `_PASS_TO_SITE_FIELD`
- 实际删除行数: `15`
- grep 验证:
  - `rg -n 'for key in \\(field_name, pass_name\\)' runner/libs/rejit.py`
  - Result: no matches

## R4

- Files/lines:
  - `e2e/cases/bcc/case.py:430`
  - `e2e/cases/tracee/case.py:1209`
  - `e2e/cases/tetragon/case.py:783`
- 删前/删后:
  - each case used a literal `setup_result = {...}` skeleton and immediately overwrote it with `inspect_*_setup()`
  - each case now assigns `setup_result = inspect_*_setup()` directly
- 实际删除行数: `19`
- grep 验证:
  - `rg -n 'setup_result = \\{' e2e/cases/bcc/case.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py`
  - Result: no matches

## R5

- Files/lines:
  - `corpus/driver.py:24-30`
  - `runner/libs/app_runners/tracee.py:20`
- 删前/删后:
  - dropped dead `run_app_runner_lifecycle` import from corpus driver
  - dropped dead `resolve_bpftool_binary` import from Tracee runner
- 实际删除行数: `2`
- grep 验证:
  - `rg -n 'run_app_runner_lifecycle|resolve_bpftool_binary|^\\s+name:\\s' corpus/driver.py runner/libs/app_runners/tracee.py runner/libs/app_runners/bcc.py`
  - Result: no matches

## R6

- Files/lines:
  - `runner/libs/app_runners/bcc.py:168-170,229-231`
- 删前/删后:
  - `BCCWorkloadSpec` used to store dead field `name`
  - it now keeps only `workload_spec` and `tool_args`
- 实际删除行数: `2`
- grep 验证:
  - same command as `R5`
  - Result: no matches for `BCCWorkloadSpec.name`

## R7

- Files/lines:
  - `e2e/driver.py:394-398`
- 删前/删后:
  - suite config path used to inject dead `args.workload` for Katran
  - `_configure_katran_case_from_suite()` now only preserves the single-instance guard
- 实际删除行数: `1`
- grep 验证:
  - `rg -n 'args\\.workload\\s*=' e2e/driver.py`
  - Result: no matches

## R8

- Files/lines:
  - `corpus/driver.py:1030-1041,1180-1230`
- 删前/删后:
  - `CorpusAppSession.prog_ids()` was a one-line wrapper over state-owned ids
  - wrapper deleted; callers now read `session.state.prog_ids` directly
- 实际删除行数: `6`
- grep 验证:
  - `rg -n '\\.prog_ids\\(' corpus/driver.py`
  - Result: no matches

## R9

- Files/lines:
  - `runner/libs/case_common.py:102-106,396-424,659-668`
  - `corpus/driver.py:215-285,346-357,778-789,815-819,946-947,1132-1245`
  - `e2e/cases/scx/case.py:326-359,553-648,659-668`
  - propagation-only caller updates:
    - `e2e/cases/bcc/case.py:145-183`
    - `e2e/cases/bpftrace/case.py:156-167`
    - `e2e/cases/katran/case.py:118-122`
    - `e2e/cases/tetragon/case.py:587-645`
    - `e2e/cases/tracee/case.py:1295-1357`
- 删前/删后:
  - `CaseLifecycleState` used dual fields `target_prog_ids` / `apply_prog_ids` plus a `prog_ids()` wrapper
  - `CaseLifecycleState` now keeps only `prog_ids`
  - corpus generic state construction, error/finalize paths, and session scan/apply flow now read `state.prog_ids`
  - SCX no longer writes live apply ids back into generic lifecycle state
  - SCX now keeps live remap internal via `scheduler_program_ids` / `scheduler_programs` closure state in `run_scx_case()`
  - generic lifecycle gained `resolve_rejit_prog_ids=...` so SCX can hand scan/apply live ids to the daemon without polluting shared state
- 实际删除行数: `125`
- grep 验证:
  - `rg -n 'target_prog_ids|apply_prog_ids|\\.prog_ids\\(' e2e/driver.py corpus/driver.py runner/libs/case_common.py e2e/cases/scx/case.py e2e/cases/bcc/case.py e2e/cases/bpftrace/case.py e2e/cases/katran/case.py e2e/cases/tetragon/case.py e2e/cases/tracee/case.py`
  - Result: no matches

## Breakage And Fixes

- `R9` field collapse would have broken every case that still read `lifecycle.target_prog_ids`.
  - Fixed by updating all remaining state readers, including two propagation-only files not listed in the initial file set: `e2e/cases/bpftrace/case.py` and `e2e/cases/katran/case.py`.
- SCX still needs live scheduler ids for daemon scan/apply even though shared lifecycle state should stay logical.
  - Fixed by isolating the remap in `e2e/cases/scx/case.py` via `_resolve_scx_scheduler_prog_ids(...)` plus `scheduler_program_ids` closure state and `resolve_rejit_prog_ids=...`.
- No additional compile/test breakage surfaced after the final validation commands.

## Totals

- 本轮手工删除行数合计: `190`
- `git diff --shortstat -- runner/libs/rejit.py runner/libs/case_common.py runner/libs/app_runners/__init__.py runner/libs/app_runners/bcc.py runner/libs/app_runners/tracee.py e2e/cases/bcc/case.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/scx/case.py e2e/driver.py corpus/driver.py e2e/cases/bpftrace/case.py e2e/cases/katran/case.py`
- 输出: `13 files changed, 347 insertions(+), 785 deletions(-)`
- 累计净变化: `-438`
- 说明:
  - 上面的 `git diff --shortstat` 是相对 `HEAD` 的累计值，这些文件在 Round 5 开始前已经带有 Round 3/4 的未提交改动。
  - 就本轮清理目标而言，active residue 已按 `R1-R9` 收口完毕；最终累计净变化明显超过 `> 78 LOC` 下限。
