# Broken Smoke Shim Fix Summary (2026-04-24)

## Scope

Targeted fixes from meta-review:
- BLOCKER: delete the broken `runner/suites/e2e.py --e2e-smoke` shim added in `ccd8debe`
- SHOULD: delete remaining Tracee/Tetragon smoke branches and `smoke_*` config fields

Files changed:
- `runner/suites/e2e.py`
- `e2e/cases/tracee/case.py`
- `e2e/cases/tracee/config.yaml`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/tetragon/config.yaml`

Concurrency checks before edits:
- `git diff -- <file>` returned clean for all 5 target files
- existing dirty state was left untouched in:
  - `Makefile`
  - `e2e/driver.py`
  - `runner/libs/app_runners/tracee.py`
  - `runner/libs/app_runners/tetragon.py`
  - `e2e/results/*`

## Changes

### 1. Blocker: remove the broken suite shim

File:
- `runner/suites/e2e.py`

Deleted:
- argparse `--e2e-smoke`
- forwarding of `--smoke` into `e2e/driver.py`
- the stale help text describing smoke mode

Result:
- `runner/suites/e2e.py` now forwards only explicit `e2e_argv`
- `make -n vm-e2e` no longer emits `--smoke` or `--e2e-smoke`

### 2. Should: collapse Tracee to one minimal default path

Files:
- `e2e/cases/tracee/case.py`
- `e2e/cases/tracee/config.yaml`

Deleted:
- all `args.smoke` branches
- `smoke_duration_s`
- `smoke_sample_count`
- `smoke_warmup_duration_s`
- `smoke_latency_probe_count`
- smoke-only result payload and markdown fields

Unified defaults:
- `measurement_duration_s: 6`
- `sample_count: 2`
- `warmup_duration_s: 2`
- `latency_probe_count: 0`

### 3. Should: collapse Tetragon to one minimal default path

Files:
- `e2e/cases/tetragon/case.py`
- `e2e/cases/tetragon/config.yaml`

Deleted:
- `args.smoke` duration branch
- `smoke_duration_s`
- smoke-only result payload and markdown fields

Unified default:
- `measurement_duration_s: 8`

## Validation

Commands run:
- `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/suites/e2e.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py`
- `source /home/yunwei37/workspace/.venv/bin/activate && make check`
- `source /home/yunwei37/workspace/.venv/bin/activate && make -n vm-e2e`
- `rg -n -- '--e2e-smoke|--smoke\\b|smoke_duration_s|smoke_sample_count|smoke_warmup|smoke_latency_probe' runner/suites e2e/cases/tracee e2e/cases/tetragon`

Results:
- `py_compile`: passed
- `make check`: passed
- `make -n vm-e2e`: `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e --`
- final grep on live code: `0` matches

## Diff Stats

Targeted files:
- `git diff --shortstat f353be39^..13d2930c -- runner/suites/e2e.py e2e/cases/tracee/case.py e2e/cases/tracee/config.yaml e2e/cases/tetragon/case.py e2e/cases/tetragon/config.yaml`
- expected net: `5 files changed, 15 insertions(+), 59 deletions(-)`

Whole worktree after commits:
- `git diff --shortstat`
- current result excludes the two new commits and reflects only unrelated concurrent dirty files

## Commits

- `f353be39` `runner/e2e: remove broken smoke wrapper shim`
- `13d2930c` `e2e: collapse tracee and tetragon to one minimal default path`
