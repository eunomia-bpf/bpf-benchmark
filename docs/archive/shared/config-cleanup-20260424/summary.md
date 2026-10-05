# Config Cleanup Summary

Date: 2026-04-24

## Scope

- Reviewed:
  - `e2e/cases/tracee/config.yaml`
  - `e2e/cases/tetragon/config.yaml`
  - `e2e/cases/bcc/config.yaml`
  - `corpus/config/macro_apps.yaml`
  - `runner/libs/suite_args.py`
- Confirmed absent, so no file-level cleanup was needed:
  - `e2e/cases/bpftrace/config.yaml`
  - `e2e/cases/scx/config.yaml`
  - `e2e/cases/katran/config.yaml`
- Also cleaned the direct/standalone entrypoints that were still exposing the same config surface:
  - `corpus/driver.py`
  - `runner/suites/corpus.py`
  - `runner/suites/e2e.py`
  - `e2e/driver.py`

## Decisions

### E2E case configs

- `tracee`:
  - Deleted `e2e/cases/tracee/config.yaml`.
  - Hardcoded fixed values into code:
    - `measurement_duration_s = 6`
    - `sample_count = 2`
    - `warmup_duration_s = 2`
    - single workload `tracee_default`
  - Rationale: no case-specific config override is exposed anymore; the file only contained one fixed benchmark plan.

- `tetragon`:
  - Deleted `e2e/cases/tetragon/config.yaml`.
  - Hardcoded fixed values into code:
    - `measurement_duration_s = 8`
    - single workload `exec_storm`
    - fixed `value = 2`
  - Rationale: current checked-in config always forced the same one-workload plan.

- `bcc`:
  - Deleted `e2e/cases/bcc/config.yaml`.
  - Hardcoded fixed values into code:
    - full tool matrix
    - `measurement_duration_s = 10`
    - `attach_timeout_s = 20`
    - fixed per-tool `workload_spec` and `tool_args`
  - Rationale: this YAML was just a static catalog, not a real runtime config.

### Corpus app suite structure

- Added `runner/libs/benchmark_catalog.py` as the single source of truth for:
  - corpus default samples/duration
  - fixed macro app definitions
  - fixed BCC e2e tool matrix
  - fixed Tracee/Tetragon e2e workload plans
- Changed `corpus/config/macro_apps.yaml` from verbose schema v1 to minimal schema v2:
  - kept only the ordered app list
  - removed:
    - `defaults.duration_s`
    - `defaults.samples`
    - per-app `runner`
    - per-app `workload.corpus`
    - per-app `workload.e2e`
    - per-app `tool`
    - per-app `script`
    - per-app `scheduler`
    - per-app `duration_s`
- Rationale: those values are fixed facts derived from the app identity, not user-tunable config.

### Suite args / CLI cleanup

- Removed from `runner/libs/suite_args.py`:
  - `VM_CORPUS_WORKLOAD_SECONDS`
  - `VM_CORPUS_ARGS`
  - `E2E_ARGS`
- Kept:
  - micro benchmark knobs
  - corpus sample count
  - test suite knobs (`TEST_MODE`, `FUZZ_ROUNDS`, `SCX_PROG_SHOW_RACE_*`)
- Removed direct pass-through CLI surfaces:
  - `runner/suites/corpus.py`: `--corpus-workload-seconds`, `--corpus-argv`
  - `runner/suites/e2e.py`: `--e2e-argv`
  - `corpus/driver.py`: `--workload-seconds`
- Removed dead config plumbing from `e2e/driver.py`.
  - `default_config` injection no longer exists because no e2e case reads checked-in YAML config anymore.
- Left `e2e/driver.py --duration` intact.
  - Reason: unlike the removed pass-throughs, this is still an explicit debug/experiment knob on the direct developer entrypoint.

## Net effect

- The user-facing top-level benchmark surface is narrower.
- Checked-in YAML no longer stores fixed durations, workloads, tool names, or runner-specific switches.
- Corpus and e2e now read their fixed benchmark plans from code, not from static YAML wrappers.
- The same fixed facts are no longer duplicated across:
  - e2e YAML
  - corpus manifest
  - runner adapters
  - suite env pass-throughs

## Verification

- Passed:

```bash
python3 -m py_compile \
  runner/libs/benchmark_catalog.py \
  runner/libs/app_suite_schema.py \
  corpus/driver.py \
  runner/libs/app_runners/bcc.py \
  e2e/cases/bcc/case.py \
  e2e/cases/tracee/case.py \
  e2e/cases/tetragon/case.py \
  e2e/driver.py \
  runner/libs/suite_args.py \
  runner/suites/e2e.py \
  runner/suites/corpus.py
```

- Passed:

```bash
make check
```
