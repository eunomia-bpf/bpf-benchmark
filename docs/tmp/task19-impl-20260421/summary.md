# Task 19 Implementation Summary

Date: 2026-04-21

## DRY Cleanup

### A) `e2e/driver.py` Tracee/Tetragon workload filter

- Added shared helper `e2e/driver.py:297-325`:
  `_filter_suite_workloads_config(case_label, temp_prefix, args, suite_apps)`
- Replaced Tracee/Tetragon callers with one-line wrappers at:
  - `e2e/driver.py:328-329`
  - `e2e/driver.py:332-333`
- Effect:
  - removed the duplicated YAML load/filter/missing-check/temp-write path
  - preserved case-specific error text and temp-file prefix

### B) `runner/suites/corpus.py` + `runner/suites/e2e.py` `--rejit-passes`

- Added shared argv helper `runner/suites/_common.py:152-165`:
  `strip_option_with_value(argv, option_name)`
- Also extracted the tiny runtime-env wrapper into
  `runner/suites/_common.py:361-370`:
  `suite_runtime_env_with_rejit_passes(...)`
- Updated corpus suite to use the shared helpers at:
  - `runner/suites/corpus.py:83-84`
  - `runner/suites/corpus.py:108`
- Updated e2e suite to use the shared helpers at:
  - `runner/suites/e2e.py:85-86`
  - `runner/suites/e2e.py:95`

### C) `runner/libs/suite_commands.py` base argv + artifact flags

- Added shared base argv builder at `runner/libs/suite_commands.py:42-68`:
  `_build_base_suite_argv(workspace, suite_module, config, die=...)`
- Added shared artifact flag appender at `runner/libs/suite_commands.py:71-80`:
  `_append_artifact_args(argv, native_repos=..., scx_packages=...)`
- Converted builders to keep only suite-specific tails:
  - `runner/libs/suite_commands.py:139-152` `build_micro_suite_argv()`
  - `runner/libs/suite_commands.py:156-177` `build_corpus_suite_argv()`
  - `runner/libs/suite_commands.py:180-194` `build_e2e_suite_argv()`
  - `runner/libs/suite_commands.py:197-214` `build_test_suite_argv()`

### D) Tracee/Tetragon program-selection helper drift

- Added shared helper module `e2e/case_common.py:6-39`:
  `select_configured_programs(...)`
- Tracee now delegates at:
  - import: `e2e/cases/tracee/case.py:44`
  - wrapper: `e2e/cases/tracee/case.py:82-95`
- Tetragon now delegates at:
  - import: `e2e/cases/tetragon/case.py:35`
  - wrapper: `e2e/cases/tetragon/case.py:135-148`

## Dead Code Cleanup

- Deleted `runner/libs/app_runners/setup_support.py:78-84`
  - removed `first_existing_dir()`
  - reason: grep found 0 in-repo references
- Deleted `e2e/cases/tetragon/case.py:52`
  - removed unused `DEFAULT_BPFTOOL`
  - reason: grep found 0 in-repo references
- Deleted unused re-export style import `runner/suites/_common.py:13`
  - removed `inside_runtime_image` import from `_common`
  - callers now import directly:
    - `runner/suites/corpus.py:13`
    - `runner/suites/e2e.py:14`
    - `runner/suites/test.py:17`
  - reason: repo-owned `pyflakes` flagged the import as unused in `_common`

## Additional Cleanup

- `runner/libs/aws_executor.py:190`
  - removed a redundant `f` prefix to clear the remaining repo-owned `pyflakes` warning in this slice

## Dead-Code Search Notes

- `runner/libs/app_runners/` runner classes were checked against YAML references in `corpus/config/macro_apps.yaml:9-142`
  - result: all current runner classes remain referenced (`bcc`, `bpftrace`, `katran`, `scx`, `tetragon`, `tracee`)
  - no runner class deletion
- Repo-owned Python test discovery under `tests/ e2e/ runner/ corpus/`
  - result: no `test_*.py` / `*_test.py` files found
  - no pytest unit-test target to run
- Commented-out-code / remove-marker grep
  - no actionable repo-owned deletion was identified in this slice

## Verification

### Commands run

```bash
python3 -m py_compile \
  e2e/case_common.py \
  e2e/driver.py \
  e2e/cases/tracee/case.py \
  e2e/cases/tetragon/case.py \
  runner/suites/_common.py \
  runner/suites/corpus.py \
  runner/suites/e2e.py \
  runner/suites/test.py \
  runner/libs/suite_commands.py \
  runner/libs/app_runners/setup_support.py \
  runner/libs/aws_executor.py

find runner corpus e2e tests \
  \( -path 'runner/repos' -o -path 'runner/build-x86' -o -path 'runner/build-arm64' -o -path 'vendor' -o -path '.git' \) -prune -o \
  -type f -name '*.py' -print | sort | xargs python3 -m pyflakes

make check

python3 -m pyflakes runner/ corpus/ e2e/ tests/
```

### Results

- `python3 -m py_compile ...`
  - PASS
- repo-owned `pyflakes` (`find ... | xargs python3 -m pyflakes`)
  - PASS
- `make check`
  - PASS
- literal `python3 -m pyflakes runner/ corpus/ e2e/ tests/`
  - exit status: `1`
  - log lines: `1177`
  - diagnostics are still from generated / third-party trees under `runner/build-x86` and `runner/repos`
  - repo-owned Python files touched by this task are clean, so this slice is not worse
- `pytest`
  - not run
  - reason: no repo-owned Python unit-test files were found for `runner/corpus/e2e/tests`

## LOC Change

- Modified tracked files: `+139 / -208`
- New file: `e2e/case_common.py` `+39`
- Total: `+178 / -208` (net `-30` LOC)
