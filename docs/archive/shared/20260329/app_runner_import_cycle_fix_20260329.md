# App Runner Import Cycle Fix

Date: 2026-03-29

## Summary

Fixed the five runner-to-E2E import cycles by moving runner-owned lifecycle logic out of the E2E cases and into `runner/libs/app_runners/`.

Affected runners:

- `tracee`
- `katran`
- `tetragon`
- `bpftrace`
- `scx`

Reference runner kept unchanged in architecture:

- `bcc`

## What Changed

### 1. Runner-owned support modules

Added runner-side helper modules so the app runner package now owns the real loader / attach / workload helpers:

- `runner/libs/app_runners/tracee_support.py`
- `runner/libs/app_runners/tetragon_support.py`
- `runner/libs/app_runners/katran_support.py`

Reused existing tracked support modules and wired them into the active runners:

- `runner/libs/app_runners/bpftrace_support.py`
- `runner/libs/app_runners/scx_support.py`

These modules now own the runner-specific logic that previously lived in `e2e/cases/*/case.py`, including:

- process/session startup and health checks
- binary/setup resolution
- policy/materialization helpers
- topology / namespace / direct-load helpers for Katran
- workload dispatch helpers used by `run_workload()`

### 2. Main runner interfaces

Kept the public runner interface uniform:

- `start() -> list[int]`
- `run_workload(seconds)`
- `stop()`

Updated runner implementations:

- `runner/libs/app_runners/tracee.py`
- `runner/libs/app_runners/katran.py`
- `runner/libs/app_runners/tetragon.py`
- `runner/libs/app_runners/bpftrace.py`
- `runner/libs/app_runners/scx.py`

All five runners are now self-contained from the runner package side and no longer import `e2e`.

### 3. E2E cases now depend on runners

Updated E2E cases so their imports point into `runner.libs.app_runners.*` and their logic stays focused on E2E-specific measurement / comparison / reporting.

Updated cases:

- `e2e/cases/tracee/case.py`
- `e2e/cases/katran/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/scx/case.py`

Specific notes:

- `tracee`: case-owned session/binary/workload helpers moved to runner package; phase measurement now routes runtime workload generation through `TraceeRunner.run_workload()`.
- `tetragon`: case-owned session/setup/policy helpers moved to runner package; runtime measurement now routes through `TetragonRunner.run_workload()`.
- `bpftrace`: script registry / attach wait / process finalization live in the runner package; case measurement now uses `BpftraceRunner.run_workload()`.
- `scx`: scheduler session and workload helpers live in the runner package; case measurement now uses `ScxRunner.run_workload()`.
- `katran`: runner startup/topology/direct-load/traffic helpers moved to the runner package; case measurement now drives live traffic through `KatranRunner.run_workload()`.

### 4. Tests


## Validation

### Python compile

Ran:

```bash
python3 -m py_compile \
  runner/libs/app_runners/tracee.py \
  runner/libs/app_runners/tracee_support.py \
  runner/libs/app_runners/tetragon.py \
  runner/libs/app_runners/tetragon_support.py \
  runner/libs/app_runners/bpftrace.py \
  runner/libs/app_runners/bpftrace_support.py \
  runner/libs/app_runners/scx.py \
  runner/libs/app_runners/scx_support.py \
  runner/libs/app_runners/katran.py \
  runner/libs/app_runners/katran_support.py \
  e2e/cases/tracee/case.py \
  e2e/cases/tetragon/case.py \
  e2e/cases/bpftrace/case.py \
  e2e/cases/scx/case.py \
  e2e/cases/katran/case.py \
```

Result:

- success

### Python tests

Ran:

```bash
```

Result:

- `73 passed`

### Import direction checks

Ran:

```bash
rg -n "from e2e" runner/libs/app_runners
```

Result:

- no matches

Ran on the five repaired cases:

```bash
rg -n "from runner\.libs\.app_runners" e2e/cases/{tracee,katran,tetragon,bpftrace,scx}
```

Result:

- 5 matches

Ran on all `e2e/cases`:

```bash
rg -n "from runner\.libs\.app_runners" e2e/cases
```

Result:

- 6 matches

Explanation:

- the extra sixth match is `e2e/cases/bcc/case.py`, which was already the correct one-way direction before this change and remains correct.

## Scope Notes

- No changes were made under `vendor/linux-framework`.
- No commit or push was performed.
- `runner/libs/app_runners/__init__.py` and `get_app_runner()` were not changed.
- Existing unrelated dirty worktree entries were left untouched.
