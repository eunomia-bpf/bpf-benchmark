# Activity Review / Fallback Purge (2026-04-24)

## Scope
- Read required context docs first, then scanned A-D for lazy activity renames and E-J for fallback/compat residue.
- Honored conflict rules: skipped forbidden or concurrently dirty files (`runner/libs/app_runners/tracee.py`, `e2e/cases/tracee/case.py`, `Makefile`, `corpus/driver.py`, `e2e/cases/{katran,scx,tetragon}/case.py`, `e2e/driver.py`).

## Task 1: Activity Gate Rename Review
- Result: no live lazy rename found.
- Pattern B/C reruns are clean: no `run_cnt == 0` gate residue, no renamed activity summary fields.
- Pattern A/D remaining hits are non-activity semantics:
  - `runner/libs/{rejit.py,reporting.py,suite_args.py}` `warmups`: micro benchmark sample defaults, not preflight/activity gating.
  - `e2e/cases/tracee/{config.yaml,case.py}` `warmup_*`: startup/workload warmup window; measurement verify still runs after warmup, so this is not a renamed activity gate.

## Task 2: Fallback / Defensive / Compat Purge
- Deleted Python compat/shim paths:
  - `runner/libs/rejit.py`: removed policy-context aliases (`object_basename`, `program_name`, `section_name`, `prog_type_name`), env alias `benchmark-default`, and `passes.active` fallback.
  - `runner/libs/case_common.py`: removed `object_basename`, `prog_name`, and `prog_type_name` fallback reads.
  - `corpus/driver.py`: removed the last live `prog_type_name` consumer; corpus program-type inference now uses section-name inference only.
  - `runner/suites/{corpus,e2e,test}.py`, `runner/libs/suite_commands.py`, `runner/suites/_common.py`: removed singular repeated CLI shims (`--native-repo`, `--scx-package`) and dead merge helper; kept only canonical plural CSV form.
  - `runner/suites/corpus.py`: removed suite-level `--workload-seconds` alias; canonical input is `--corpus-workload-seconds`.
  - `micro/driver.py`: removed silent missing-baseline fallback; now hard-fails when configured baseline is absent.
- Deleted Rust defensive paths:
  - `daemon/src/elf_parser.rs`: removed saturating global-data size fallback; oversize sections now error loudly.
  - `daemon/src/profiler.rs`: removed silent drop-path failure swallowing; now emits stderr on shutdown/join failure.
- Deleted dead config shim:
  - `corpus/config/benchmark_config.yaml`: removed obsolete `passes.active: performance`.
- Retained on purpose:
  - `daemon/src/passes/{branch_flip,map_inline}.rs`: algorithmic fallback required for missing profile / verifier-guided miss cases.
  - `runner/libs/app_runners/bcc.py`: runtime compatibility layer required by BCC reduced-header/Python setup, not old-caller glue.
  - `runner/libs/workload.py` `run_{open,connect,bind}_storm`: still live imports in `tracee.py` and `tetragon.py`; `tracee.py` is forbidden this round, so no partial alias purge.
  - `runner/libs/case_common.py` `section_name` fallback: kept because `corpus/driver.py` is still a live consumer and is concurrently dirty.

## Validation
- `python3 -m py_compile runner/libs/rejit.py runner/libs/case_common.py runner/libs/suite_commands.py runner/suites/_common.py runner/suites/corpus.py runner/suites/e2e.py runner/suites/test.py micro/driver.py`
- `cargo test` in `daemon/`: `499 passed; 0 failed`
- `make check`: passed
- Exact zero-hit checks after purge in source tree:
  - `benchmark-default`
  - `--native-repo`
  - `--scx-package`
  - `object_basename`
  - `passes.active`
  - `active: performance`
  - `prog_type_name`
  - activity patterns B/C

## Diff Proof / Self Review
- Code-only diff shortstat: `12 files changed, 69 insertions(+), 74 deletions(-)`.
- Removed fields/options were checked for live source-tree consumers before deletion; no remaining source-tree producer/consumer pair was found for `benchmark-default`, `object_basename`, `prog_type_name`, singular repo/package flags, or `passes.active`.
- Residual compat-looking hits are either algorithmic necessities, required runtime integration, or blocked by the explicit conflict-avoidance rules above.
