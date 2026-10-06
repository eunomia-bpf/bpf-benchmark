# Final Cleanup Summary (2026-04-23)

Scope:
- Worked only in the allowed paths: `runner/libs/suite_args.py`, `runner/libs/run_contract.py`, `runner/libs/app_runners/{base,scx}.py`, `runner/libs/input_generators.py`, and `Makefile`.
- Did not touch the explicit no-edit set: `corpus/driver.py`, `runner/libs/case_common.py`, `runner/libs/app_runners/tracee.py`, `e2e/cases/tracee/case.py`.
- Did not run any `make vm-*` target.
- Python verification used `/home/yunwei37/workspace/.venv/bin/python3` via `source /home/yunwei37/workspace/.venv/bin/activate`.

## 1. Cleanup performed

### 1. `_normalize_test_mode` + `SuiteSelection`

- Deleted `runner/libs/suite_args.py` helper `_normalize_test_mode()`.
- Replaced its two live call sites with direct normalization: `str(...).strip().lower()`.
- Deleted thin wrapper `SuiteSelection`; `runner/libs/run_contract.py` now carries `run_test_mode: str` directly via `suite_test_mode_from_args()`.
- Reason:
  - `full -> test` was already dead compatibility behavior after `e2cb3ed6` removed `full` mode.
  - Keeping the alias would preserve a shim the plan doc says not to keep.
  - `SuiteSelection` only wrapped one scalar and was immediately unpacked in `run_contract`.

### 2. `program_fds`

- Deleted empty `AppRunner.program_fds` from `runner/libs/app_runners/base.py`.
- Deleted empty `ScxRunner.program_fds` override from `runner/libs/app_runners/scx.py`.
- Proof before deletion:
  - `rg -n --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!**/__pycache__/**' --glob '!**/results/**' 'program_fds\\b' runner e2e corpus`
  - Result only hit the base declaration and the SCX override; there were no consumers.

### 3. Duplicate `ROOT_DIR`

- Deleted the local `ROOT_DIR = Path(__file__).resolve().parents[2]` in `runner/libs/input_generators.py`.
- Switched the file to `from runner.libs import ROOT_DIR`.
- Kept `runner/libs/__init__.py` as the single owner of that repo-root constant.

### 4. Makefile cleanup

- Removed decorative section comments from `Makefile`.
- Removed stale `--rejit-passes ...` help examples and replaced them with current live examples:
  - `VM_CORPUS_ARGS="--no-kinsn"`
  - `E2E_ARGS="--no-kinsn"`
- While in the same file, also deleted dead helper vars `empty`, `space`, and `comma` that were no longer referenced.

### 5. Same-scope dead leftovers found during final sweep

- Deleted unused helper `_merge_csv_and_repeated()` from `runner/libs/suite_args.py`.
- Rationale: repo-wide search showed only its definition, no live caller.

## 2. Verification

- Targeted compile after first edit batch:
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/suite_args.py runner/libs/run_contract.py runner/libs/app_runners/base.py runner/libs/app_runners/scx.py runner/libs/input_generators.py`
- Full repo Python check after cleanup:
  - `source /home/yunwei37/workspace/.venv/bin/activate && make check`
- Live-code grep checks:
  - `rg -n --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!**/__pycache__/**' --glob '!**/results/**' '_normalize_test_mode|program_fds' runner e2e corpus`
  - result: no output
- Additional post-sweep verification:
  - `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile runner/libs/suite_args.py`
  - `source /home/yunwei37/workspace/.venv/bin/activate && make check`

## 3. Commit log

1. `18f36cc6` `runner: delete dead suite test-mode wrapper`
2. `8d462379` `runner: drop dead hooks and stale makefile help`
3. `43c6e581` `[docs] round 8 post-cleanup audit reports`
4. `6f475773` `runner: trim dead suite arg and make vars`

Code-cleanup-only delta across the three runner commits: `+12 / -51`, net `-39 LOC`.

Tracked audit reports:
- `docs/tmp/daemon-rust-audit-20260423/summary.md`
- `docs/tmp/design-cleanliness-audit-20260423/summary.md`
- `docs/tmp/feature-inventory-20260423/summary.md`

## 4. Working tree state after commit set

- Intentionally left untouched:
  - untracked `e2e/results/*` directories produced by parallel verification work outside this cleanup scope
- No source changes remain unstaged after adding this report.
