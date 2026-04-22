# Dead Code Driver Cleanup Summary (2026-04-21)

## Deletions

### 1. Remove unreachable corpus app-measurement path
- Commit: `567df095` (`[corpus] delete unreachable measurement_mode=='app' path`)
- File: `corpus/driver.py`
- Line count: `1850 -> 1765`
- Reachability evidence:
  - `git grep -n -e 'corpus_measurement_mode(' 567df095^ -- runner/libs/app_runners corpus e2e tests`
    returned only:
    - `runner/libs/app_runners/base.py:49`
    - `corpus/driver.py:1286`
    - `corpus/driver.py:1390`
  - `runner/libs/app_runners/base.py:49-50`:
    - `def corpus_measurement_mode(self) -> str:`
    - `return "program"`
  - No in-tree implementation returned any non-`"program"` mode, so corpus app-mode result construction and comparison rows were unreachable.
- Post-delete reference check:
  - `rg -n "_app_measurement_row|app_measurement" corpus e2e runner tests -g '*.py'`
  - Result: no hits.

### 2. Remove unused direct corpus `--rejit-passes` flag
- Commit: `c6e9815c` (`[corpus/e2e] remove unused --rejit-passes CLI flags`)
- File: `corpus/driver.py`
- Line count: `1765 -> 1760`
- Reachability evidence:
  - `git grep -n -e '--rejit-passes' c6e9815c^ -- Makefile README.md e2e runner corpus tests .github/workflows`
    returned only:
    - `Makefile` examples
    - parser definitions in `corpus/driver.py`, `e2e/driver.py`, `e2e/cases/katran/case.py`
    - wrapper env handling in `runner/suites/corpus.py` and `runner/suites/e2e.py`
  - `git grep -n -E 'python3 .*corpus/driver.py.*--rejit-passes|python3 .*e2e/driver.py.*--rejit-passes|python3 .*katran/case.py.*--rejit-passes' c6e9815c^ -- Makefile README.md e2e runner corpus tests .github/workflows`
  - Result: no hits.
- Compatibility note:
  - Same commit updated `runner/suites/corpus.py` to keep exporting `BPFREJIT_BENCH_PASSES` while stripping `--rejit-passes` from the driver passthrough argv.
  - `runner/suites/corpus.py` line count: `141 -> 153`

### 3. Remove unused direct e2e `--rejit-passes` flag
- Commit: `c6e9815c` (`[corpus/e2e] remove unused --rejit-passes CLI flags`)
- File: `e2e/driver.py`
- Line count: `690 -> 685`
- Reachability evidence:
  - Same tracked-callsite grep as item 2 found no direct `python3 e2e/driver.py --rejit-passes ...` usage.
  - The only live pass-selection contract remained the wrapper/env path via `BPFREJIT_BENCH_PASSES`.
- Compatibility note:
  - Same commit updated `runner/suites/e2e.py` to keep exporting `BPFREJIT_BENCH_PASSES` while stripping `--rejit-passes` from the driver passthrough argv.
  - `runner/suites/e2e.py` line count: `139 -> 151`

### 4. Remove unused Katran-local `--rejit-passes` flag
- Commit: `c6e9815c` (`[corpus/e2e] remove unused --rejit-passes CLI flags`)
- File: `e2e/cases/katran/case.py`
- Line count: `249 -> 244`
- Reachability evidence:
  - The tracked-callsite grep in item 2 found no direct `katran/case.py --rejit-passes` usage.
  - `rg -n "run_app_runner_lifecycle\\(|enabled_passes=" runner/libs e2e/cases/katran/case.py -g '*.py'`
    shows `e2e/cases/katran/case.py:187` calling `run_app_runner_lifecycle(` with no `enabled_passes=` argument.
  - The case path therefore had no way to thread its local `--rejit-passes` value into the runner lifecycle.

## Not Deleted

### `e2e/driver.py` empty `selected_rejit_passes` fallback branch
- Status: not deleted
- Reason:
  - Pre-delete code in `a1f2fbc2^:e2e/driver.py:481-487` was:
    - `selected_rejit_passes = collect_effective_enabled_passes(payload)`
    - `if not selected_rejit_passes:`
    - `selected_rejit_passes = list(requested_rejit_passes)`
    - `selected_rejit_passes_provenance = "requested_fallback"`
  - `runner/libs/rejit.py:193-205` shows `collect_effective_enabled_passes(payload)` recursively collects `effective_enabled_passes_by_program` and returns `_ordered_unique_passes(raw)`.
  - When payload has no `effective_enabled_passes_by_program`, that helper can return `[]`, so the fallback branch is reachable.
- Correction history:
  - I initially removed it in `a1f2fbc2` following the review note.
  - After verifying reachability, I restored it in `bf29e010` (`[e2e] keep reachable requested_rejit_passes fallback branch`).

## Validation

- `python3 -c "import corpus.driver, e2e.driver"`
- `python3 -m compileall corpus/ e2e/ runner/libs/`

## Conflicts

- None.
