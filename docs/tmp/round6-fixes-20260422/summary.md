# Round 6 Fixes - 2026-04-22

Scope:
- Applied all 5 requested fixes.
- Validation: per-step `python3 -m py_compile`, then `make check`, then `cargo test --manifest-path daemon/Cargo.toml`.
- Not run: `make vm-e2e`, `make vm-corpus`.

## 1. B1 BLOCKER — Tracee event-file parser structured contract

Files:
- `runner/libs/app_runners/tracee.py:80-88`
- `runner/libs/app_runners/tracee.py:145-161`
- `runner/libs/app_runners/tracee.py:182-190`
- `runner/libs/app_runners/tracee.py:209-219`
- `e2e/cases/tracee/case.py:444-448`
- `e2e/cases/tracee/case.py:525-533`
- `e2e/cases/tracee/case.py:582-587`

Diff summary:
- `runner/libs/app_runners/tracee.py:80-88`
  - added `event_parse_error_count`, `event_parse_error_samples`, and `_record_event_parse_error(reason, line)`.
- `runner/libs/app_runners/tracee.py:145-161`
  - added the minimal idle-path `stat()`/`fstat()` reopen check for inode replacement or size shrink.
- `runner/libs/app_runners/tracee.py:182-190`
  - converted the 3 event-file silent returns into `_record_event_parse_error(...)` + `return`.
- `runner/libs/app_runners/tracee.py:209-219`
  - `snapshot()` now exports `event_parse_error_count` and `event_parse_error_samples`.
- `e2e/cases/tracee/case.py:444-448`
  - `verify_phase_measurement()` now fails the measured phase on any non-zero `event_parse_errors`.
- `e2e/cases/tracee/case.py:525-533`
  - phase delta now records `event_parse_errors = after - before`.
- `e2e/cases/tracee/case.py:582-587`
  - phase record now carries `event_parse_error_samples`.

Minimality check:
- stdout/stderr parsing remains permissive and unchanged.
- I did not restore the old partial-line buffer path.
- I did not restore the old wait-fast-fail / startup-fast-fail strict exception path.
- I did not restore the old low-frequency rollover polling.

Structured-contract line accounting:
- New Round 6 B1 code added now:
  - `runner/libs/app_runners/tracee.py`: 30 non-empty Python lines at `80-81`, `83-88`, `145-161`, `183`, `186`, `190`, `218-219`
  - `e2e/cases/tracee/case.py`: 16 non-empty Python lines at `444-448`, `525-528`, `533`, `582-587`
  - total: 46 non-empty Python lines
- Round 3B deleted strict/accommodation code still absent in the final tree:
  - `runner/libs/app_runners/tracee.py`: 79 non-empty deleted lines from the pre-cleanup strict implementation, counted from `git diff --unified=0 HEAD -- runner/libs/app_runners/tracee.py`
  - `e2e/cases/tracee/case.py`: 4 non-empty deleted lines from the removed `collector.raise_event_file_error()` checks, counted from `git diff --unified=0 HEAD -- e2e/cases/tracee/case.py`
  - total still absent vs the stricter predecessor: 83 non-empty lines
- Final net effect vs the stricter pre-cleanup implementation:
  - reintroduced: 46 lines
  - still deleted: 83 lines
  - net: 37 fewer non-empty lines than the older strict/accommodation version

## 2. M1 MEDIUM — Suite temp cleanup warn instead of raise

Files:
- `e2e/driver.py:254-261`

Diff summary:
- kept `except FileNotFoundError: continue`
- added `except OSError as exc: print(..., file=sys.stderr)` without re-raising

## 3. Tetragon setup_result fallback 回收

Files:
- `runner/libs/app_runners/__init__.py:51-58`

Diff summary:
- `_adapt_tetragon()` now unconditionally imports and calls `inspect_tetragon_setup()`
- removed the old `if "setup_result" not in mapped` conditional fallback shape
- runner contract stays explicit/required; the shared adapter now passes `setup_result` directly for corpus construction

## 4. C1 LOW — SCX dead artifact fields removed

Files:
- `e2e/cases/scx/case.py:593-604`
- `e2e/cases/scx/case.py:623-630`

Diff summary:
- removed `post_rejit_scheduler_programs`
- removed `baseline_live_program_id_map`
- removed `baseline_live_scheduler_programs`
- collapsed `after_baseline()` return payload to `{}` because nothing reads those fields

## 5. C2 LOW — Tracee recent_events dead snapshot field removed

Files:
- `runner/libs/app_runners/tracee.py:211-219`

Diff summary:
- removed `snapshot()["recent_events"]`
- kept `self.events` itself because `wait_for_event()` still reads it

## Grep verification

Commands and results:
- `! rg -n 'if "setup_result" not in mapped|recent_events' runner/libs/app_runners/__init__.py runner/libs/app_runners/tracee.py`
  - result: no matches
- `! rg -n 'post_rejit_scheduler_programs|baseline_live_program_id_map|baseline_live_scheduler_programs' e2e/cases/scx/case.py`
  - result: no matches

## Validation

Per-step compile gates:
- `python3 -m py_compile runner/libs/app_runners/tracee.py e2e/cases/tracee/case.py`
- `python3 -m py_compile e2e/driver.py`
- `python3 -m py_compile runner/libs/app_runners/__init__.py`
- `python3 -m py_compile e2e/cases/scx/case.py`
- `python3 -m py_compile runner/libs/app_runners/tracee.py`
- all passed

Suite/static validation:
- `make check`
  - passed

Rust validation:
- `cargo test --manifest-path daemon/Cargo.toml`
  - passed
  - `494 passed; 0 failed`
  - existing `dead_code` warnings from `daemon/src/elf_parser.rs` and `daemon/src/test_utils.rs` only

VM validation:
- intentionally not run

## Diff stats

- `git diff --shortstat HEAD --`
  - `50 files changed, 4018 insertions(+), 1336 deletions(-)`
- compared with the Round 5 note (`50 files changed, 3971 insertions(+), 1331 deletions(-)`)
  - this round moved the full-worktree shortstat by `+47 insertions` and `+5 deletions`
  - net delta vs the Round 5 checkpoint: `+42` lines
