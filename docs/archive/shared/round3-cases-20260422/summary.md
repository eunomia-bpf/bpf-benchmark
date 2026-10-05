# 2026-04-22 Round 3 Cases Cleanup

Status: completed

Scope:
- Static cleanup only.
- No VM runs.
- Validation limited to per-step `python3 -m py_compile` and final `make check`.

## 1. Tracee strict event parser + accommodations removed

Changed locations:
- `runner/libs/app_runners/tracee.py:69-221`
  - deleted strict parse failure accumulation/wakeup path
  - deleted partial-line buffering
  - deleted file identity + size-shrink reopen logic
  - deleted low-frequency rollover checks
  - reverted event-file parsing to the same silent-skip behavior as stdout/stderr (`json.JSONDecodeError -> return`)
- `runner/libs/app_runners/tracee.py:180-221`
  - `snapshot()` no longer emits `event_file_parse_errors`
  - `wait_for_event()` no longer has a parse-error fast path
- `runner/libs/app_runners/tracee.py:233-283`
  - Tracee health check / startup no longer routes through collector parse-error state
- `e2e/cases/tracee/case.py:467-504`
  - deleted pre/post workload `collector.raise_event_file_error()` checks

Removed fields / helpers / paths:
- `event_file_parse_errors`
- `_strict_event_file_error()`
- `_record_event_file_parse_error()`
- `_event_file_error_unlocked()`
- `raise_event_file_error()`
- `strict=True` path in `_parse_event_line()`
- `TraceeOutputCollector(event_output_path=...)` dead constructor arg

Grep verification:
- `rg -n "strict|event_file_parse_errors|raise_event_file_error|_strict_event_file_error|_record_event_file_parse_error|_event_file_error_unlocked|partial|rollover|reopen|size-shrink" runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py`
- Result: no matches

Estimated deleted lines:
- about 90 lines

Breakage + fix:
- None surfaced in static checks after simplification.

## 2. 9 dead e2e override fields removed

Changed locations:
- `e2e/cases/bpftrace/case.py:430-432`
  - removed `smoke_duration` and `attach_timeout` override reads
- `e2e/cases/bcc/case.py:441-455`
  - removed `tools_dir`, `smoke_duration`, and `attach_timeout` override reads
- `e2e/cases/tracee/case.py:1215-1216,1255-1256,1288-1293`
  - removed `tracee_binary`, `tracee_extra_arg`, and `load_timeout` override reads
- `e2e/cases/tetragon/case.py:818-824,860-862`
  - removed `tetragon_binary` and `load_timeout` override reads
- `e2e/cases/scx/case.py:579-600`
  - removed `scheduler_binary`, `scheduler_extra_arg`, and `load_timeout` override reads

Deleted override fields:
- `smoke_duration`
- `attach_timeout`
- `load_timeout`
- `tracee_binary`
- `tetragon_binary`
- `tracee_extra_arg`
- `scheduler_binary`
- `scheduler_extra_arg`
- `tools_dir`

Grep verification:
- `rg -n "getattr\\(args, \\\"(smoke_duration|attach_timeout|load_timeout|tracee_binary|tetragon_binary|tracee_extra_arg|scheduler_binary|scheduler_extra_arg|tools_dir)\\\"" e2e/cases/bpftrace/case.py e2e/cases/bcc/case.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/scx/case.py`
- Result: no matches

Estimated deleted lines:
- about 35 lines

Breakage + fix:
- None. All five cases still compile after collapsing to config/default constants.

## 3. Tetragon double setup inspect removed

Changed locations:
- `e2e/cases/tetragon/case.py:605-609`
  - `TetragonRunner(...)` now receives `setup_result=setup_result`
- `runner/libs/app_runners/tetragon.py:230-258`
  - constructor now stores caller-provided `setup_result`
  - `_resolve_binary()` no longer falls back to `inspect_tetragon_setup()`
  - runner now raises immediately if caller omitted `setup_result`

Deleted behavior:
- implicit runner-owned `inspect_tetragon_setup()` fallback

Grep verification:
- `rg -n "if self\\.setup_result is None: self\\.setup_result = inspect_tetragon_setup\\(" runner/libs/app_runners/tetragon.py`
- Result: no matches
- `rg -n "setup_result=setup_result|requires setup_result from the caller" runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
- Result:
  - `e2e/cases/tetragon/case.py:609`
  - `runner/libs/app_runners/tetragon.py:254`

Estimated deleted lines:
- about 4 lines

Breakage + fix:
- Tightening the runner contract would have broken the only live caller.
- Fixed by threading `setup_result` from `e2e/cases/tetragon/case.py` into `TetragonRunner(...)`.

## 4. Katran `_select_program()` helper removed

Changed locations:
- `runner/libs/app_runners/katran.py:19-24`
  - deleted helper-only constants `DEFAULT_KATRAN_PROGRAM_NAME` and `BPF_OBJECT_NAME_LIMIT`
- `runner/libs/app_runners/katran.py:426-464`
  - deleted `self.program`
  - deleted `_select_program()`
  - startup now keeps the full `session.programs` set only
  - `prog_id` now resolves from attached XDP metadata instead of a selected single-program cache
- `runner/libs/app_runners/katran.py:490-494`
  - deleted metadata echo of `"program": dict(self.program)`

Deleted functions / fields / constants:
- `_select_program()`
- `self.program`
- metadata field `program`
- `DEFAULT_KATRAN_PROGRAM_NAME`
- `BPF_OBJECT_NAME_LIMIT`

Grep verification:
- `rg -n "_select_program\\(|DEFAULT_KATRAN_PROGRAM_NAME|BPF_OBJECT_NAME_LIMIT|self\\.program\\b|\\\"program\\\": dict\\(self\\.program\\)" runner/libs/app_runners/katran.py`
- Result: no matches

Estimated deleted lines:
- about 25 lines

Breakage + fix:
- Removing `self.program` would have broken `reattach_xdpgeneric()` / `prog_test_run()` because both still need a live `prog_id`.
- Fixed by deriving `prog_id` from `attach_info.xdp[*].id/prog_id` in `KatranServerSession.prog_id` (`runner/libs/app_runners/katran.py:452-464`).

## 5. `find_bpf_programs()` dead export removed

Changed locations:
- `runner/libs/agent.py:1-87`
  - deleted `find_bpf_programs()`
  - deleted `_resolve_pids()`
  - deleted `_program_refs_from_pid()`
  - deleted dead `Path` import
  - removed `find_bpf_programs` from `__all__`

Deleted functions / exports:
- `find_bpf_programs()`
- `_resolve_pids()`
- `_program_refs_from_pid()`
- `__all__` export entry for `find_bpf_programs`

Grep verification:
- `rg -n "find_bpf_programs|_resolve_pids|_program_refs_from_pid" runner/libs/agent.py runner/libs/app_runners/*.py e2e/cases/*/case.py Makefile`
- Result: no matches

Estimated deleted lines:
- about 80 lines

Breakage + fix:
- None. There were no live callers left to update.

## 6. Makefile dead variables removed

Changed locations:
- `Makefile:6-11`
  - deleted `REPO_ROOT`
  - deleted `KERNEL_TEST_DIR`
- `Makefile:39-43`
  - deleted `REPOS`
- `Makefile:64-71`
  - deleted `VENV_ACTIVATE`

Deleted variables:
- `REPO_ROOT`
- `KERNEL_TEST_DIR`
- `REPOS`
- `VENV_ACTIVATE`

Grep verification:
- `rg -n '\\$\\((REPO_ROOT|KERNEL_TEST_DIR|REPOS|VENV_ACTIVATE)\\)' Makefile runner e2e daemon corpus --glob '!**/results/**' --glob '!runner/build-*/**'`
- Result: no matches

Estimated deleted lines:
- 4 lines

Breakage + fix:
- None.

## Validation

Completed:
- `python3 -m py_compile runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py`
- `python3 -m py_compile e2e/cases/bpftrace/case.py e2e/cases/bcc/case.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/scx/case.py`
- `python3 -m py_compile runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
- `python3 -m py_compile runner/libs/app_runners/katran.py`
- `python3 -m py_compile runner/libs/agent.py`
- `python3 -m py_compile runner/libs/app_runners/tracee.py runner/libs/app_runners/tetragon.py runner/libs/app_runners/katran.py runner/libs/agent.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/bcc/case.py e2e/cases/bpftrace/case.py e2e/cases/scx/case.py`
- `make check`

Not run:
- `make vm-e2e`
- `make vm-corpus`

## Totals

`git diff --numstat` on the touched files:
- insertions: 78
- deletions: 252
- net change: -174 lines

Net-delete target:
- satisfied
- `252 > 78 * 3`
