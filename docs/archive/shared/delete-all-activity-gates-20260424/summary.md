# Delete All Activity Gates 2026-04-24

## 1. Context

- Required docs read before changes:
  - `docs/kernel-jit-optimization-plan.md`
  - `docs/tmp/tracee-activity-gate-delete-20260424/summary.md`
  - `docs/tmp/tetragon-revert-20260423/summary.md`
- Initial repo checks run:
  - `git status --short`
  - `git log --oneline -15`
  - repo-wide `rg` over `preflight|program_activity|activity|_zero_drops|active_count|application_overhead`

## 2. What Was Deleted

- `e2e/cases/tracee/case.py`
  - deleted `preflight` phase plumbing
  - deleted `summarize_program_activity()`
  - deleted `preflight.program_activity` payload/report generation
  - deleted `total_run_cnt <= 0` loud-fail gate
  - deleted `control` phase plumbing and all `application_overhead_pct` derivation
  - baseline/post comparison now reads directly from paired baseline/post samples
- `e2e/cases/tracee/config.yaml`
  - deleted `preflight_duration_s`

- `e2e/cases/tetragon/case.py`
  - deleted `summarize_program_activity()`
  - deleted `before_baseline` preflight run
  - deleted `preflight` payload/markdown/error-path plumbing
  - kept baseline/post BPF runtime measurement and crash/attach hard failures
- `e2e/cases/tetragon/config.yaml`
  - deleted `preflight_duration_s`

- `e2e/cases/scx/case.py`
  - deleted remaining top-level `preflight` payload block
  - deleted markdown `## Preflight` section
  - left baseline/post scheduler measurement unchanged

## 3. Cases With No Remaining Activity-Gate Code

- `e2e/cases/bcc/`
  - repo grep found no `preflight|program_activity|activity|_zero_drops|active_count|application_overhead|total_run_cnt <= 0` hits
  - no code change needed
- `e2e/cases/bpftrace/`
  - repo grep found no remaining activity-gate hits
  - no code change needed
- `e2e/cases/katran/`
  - repo grep found no remaining activity-gate hits
  - no code change needed

## 4. Concurrent Dirty Files Skipped

- `corpus/driver.py`
  - dirty before this round and unrelated to remaining live activity-gate hits
  - not modified
- `runner/libs/app_runners/tracee.py`
  - dirty before this round
  - not modified
- `runner/libs/app_runners/bcc.py`
  - dirty before commit phase, unrelated to this delete
  - not modified
- `runner/libs/app_runners/bpftrace.py`
  - dirty before commit phase, unrelated to this delete
  - not modified
- `runner/libs/app_runners/scx.py`
  - dirty before commit phase, unrelated to this delete
  - not modified
- `runner/libs/app_suite_schema.py`
  - dirty before commit phase, unrelated to this delete
  - not modified

## 5. Validation

- grep:
  - `rg -n -S 'preflight|program_activity|_zero_drops|active_count|application_overhead' e2e/cases/ runner/libs/ corpus/driver.py Makefile runner/mk/ runner/libs/suite_args.py --glob '!e2e/results/**'`
  - result after edits: only `e2e/cases/scx/case.py` hit before the final SCX cleanup; `0` hits after SCX cleanup
- per-case grep:
  - `rg -n -S 'preflight|program_activity|activity|_zero_drops|active_count|application_overhead|run_cnt <= 0|total_run_cnt <= 0' e2e/cases/bcc/ e2e/cases/bpftrace/ e2e/cases/katran/`
  - result: `0` hits
- compile:
  - `python3 -m py_compile e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/scx/case.py`
  - result: success
- repo checks:
  - `make check`
  - result: success
- forbidden commands not run:
  - no `make vm-*`

## 6. Diff Size

- focused shortstat:
  - `git diff --stat -- e2e/cases/tracee/case.py e2e/cases/tracee/config.yaml e2e/cases/tetragon/case.py e2e/cases/tetragon/config.yaml e2e/cases/scx/case.py`
  - result: `5 files changed, 24 insertions(+), 353 deletions(-)`
- repo shortstat at validation point:
  - `git diff --shortstat`
  - result: `11 files changed, 55 insertions(+), 428 deletions(-)`

## 7. Commit Notes

- commits will be split by changed case:
  - `tracee`
  - `tetragon`
  - `scx`
- `bcc` / `bpftrace` / `katran` had no live activity-gate code left to commit
- each commit message will include:
  - `Co-Authored-By: Claude Opus 4.7 (1M context) <noreply@anthropic.com>`
