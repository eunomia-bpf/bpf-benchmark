# Fix Corpus/SCX Blockers 2026-04-24

## Scope

- only modified:
  - `corpus/driver.py`
  - `e2e/cases/scx/case.py`
- not touched:
  - `runner/libs/app_runners/tetragon.py`
  - `runner/containers/runner-runtime.Dockerfile`
  - `runner/mk/build.mk`
  - `e2e/cases/tetragon/*`
  - `runner/libs/app_runners/tracee.py`
- forbidden commands not run:
  - no `make vm-*`
  - no `make aws-*`

## Changes

- `corpus/driver.py`
  - deleted `_comparison_exclusion_reason()` and the entire no-change/comparison-exclusion taxonomy chain
  - deleted `comparable_rows / applied_rows / excluded_rows` split
  - deleted summary/per-app `applied_only_geomean`, `all_comparable_geomean`, and `comparison_exclusions`
  - summary now uses one unconditional per-app baseline/post comparison row and one `geomean`
  - each app result now reports `baseline_ns`, `post_rejit_ns`, and `speedup`
  - removed the `changed && !has_comparable_measurement` hard failure
  - any real apply error now still fails loud via app `status=error`
- `e2e/cases/scx/case.py`
  - deleted the `applied_site_total > 0` comparison gate
  - `compare_phases(baseline, post_rejit)` now runs whenever `post_rejit` exists, regardless of site count

## Validation

- compile:
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile corpus/driver.py`
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile e2e/cases/scx/case.py`
  - both succeeded
- repo check:
  - `source /home/yunwei37/workspace/.venv/bin/activate && make check`
  - succeeded
- live-code grep:
  - `rg -n 'comparison_exclusion_reason|applied_only_geomean|all_comparable_geomean|comparison_exclusions|_comparison_exclusion_reason|has_comparable_measurement' runner/ e2e/ corpus/ --glob '!corpus/results/**' --glob '!e2e/results/**' --glob '!runner/build-*/**'`
  - result: `0` hits
- scx gate grep:
  - `rg -n 'applied_site_total > 0' e2e/cases/scx/`
  - result: `0` hits
- shortstat across the two commits:
  - `git diff --shortstat HEAD~2..HEAD`
  - result: `2 files changed, 61 insertions(+), 260 deletions(-)`

## Commits

- `04d03a0a` `corpus: report unconditional baseline/post comparisons`
- `c89bd459` `e2e/scx: always compare baseline and post phases`
