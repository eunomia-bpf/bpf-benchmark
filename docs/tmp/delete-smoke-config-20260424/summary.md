# Delete Smoke Config Summary (2026-04-24)

## Scope

Goal:
- Delete the `smoke vs full` split for the benchmark surfaces touched in this change.
- Keep exactly one default parameter set: small/minimal by default; large runs must be explicit CLI/env overrides.

Pre-existing concurrent dirty state observed before edits:
- `e2e/driver.py`
- `e2e/cases/bpftrace/case.py`

Those diffs were unrelated to smoke cleanup. This change kept those edits intact and layered the smoke deletion on top without reverting them.

## Deleted Surfaces

### 1. Root entrypoints

Files:
- `Makefile`
- `runner/libs/suite_args.py`
- `runner/suites/e2e.py`

Removed:
- `E2E_SMOKE`
- `VM_MICRO_SMOKE_SUITE_ARGS`
- `vm-micro-smoke`
- `--e2e-smoke`
- root `vm-e2e` smoke arg emission

Unified defaults:
- `vm-micro` already inherits minimal defaults from `runner/libs/suite_args.py`
- `vm-corpus` default samples lowered from `30` to `1`
- `vm-e2e` now has no smoke gate; duration overrides must come from explicit `E2E_ARGS`

### 2. E2E case config / driver logic

Files:
- `e2e/driver.py`
- `e2e/cases/bcc/config.yaml`
- `e2e/cases/bcc/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/katran/case.py`
- `e2e/cases/scx/case.py`

Removed:
- `e2e/driver.py --smoke`
- default-output smoke path branch
- all payload / progress / metadata `smoke` fields in touched e2e code
- BCC `smoke_duration_s` config field
- all `if args.smoke` duration-selection branches in touched non-tracee/non-tetragon cases
- all markdown/report `Mode: smoke/full` or `Smoke: ...` text in touched cases

New single defaults:
- BCC duration: `10s`
- bpftrace duration: `5s`
- Katran duration: `5s`
- SCX duration: `10s`

### 3. Dead smoke helpers

Files:
- `micro/driver.py`
- `runner/libs/__init__.py`
- `runner/libs/run_artifacts.py`

Removed:
- micro output-name special casing through `smoke_output_path()`
- dead helper `runner.libs.smoke_output_path()`
- `_smoke_` artifact suffix parsing in `runner/libs/run_artifacts.py`

Result:
- After the CLI/config cleanup, no live caller still needed smoke-specific output naming.

## New Default Param Set

Canonical minimal defaults after this change:
- micro: `SAMPLES=1`, `WARMUPS=0`, `INNER_REPEAT=10`
- corpus: `SAMPLES=1`
- corpus suite default workload duration remains `1s` from `corpus/config/macro_apps.yaml`
- e2e:
  - bcc `10s`
  - bpftrace `5s`
  - katran `5s`
  - scx `10s`

Explicit large-run examples:
- `make vm-micro SAMPLES=30`
- `make vm-corpus SAMPLES=30`
- `make vm-e2e E2E_ARGS="--duration 30"`

## Validation

Commands run:
- `python3 -m py_compile runner/libs/suite_args.py runner/suites/e2e.py micro/driver.py`
- `python3 -m py_compile runner/libs/__init__.py runner/libs/run_artifacts.py runner/libs/suite_args.py runner/suites/e2e.py micro/driver.py e2e/driver.py e2e/cases/bcc/case.py e2e/cases/bpftrace/case.py e2e/cases/katran/case.py e2e/cases/scx/case.py`
- `make check`
- `make -n vm-e2e`
- `make -n vm-micro`
- `make -n vm-corpus`

Results:
- `make check`: passed
- `make -n vm-e2e`: `python3 -m runner.libs.run_target_suite run x86-kvm e2e --`
- `make -n vm-micro`: `python3 -m runner.libs.run_target_suite run x86-kvm micro`
- `make -n vm-corpus`: `python3 -m runner.libs.run_target_suite run x86-kvm corpus -- --samples "1"`

Touched-file grep:
- `rg -n 'smoke|SMOKE|--e2e-smoke|vm-micro-smoke' Makefile runner/libs/suite_args.py runner/suites/e2e.py micro/driver.py e2e/driver.py e2e/cases/bcc/config.yaml e2e/cases/bcc/case.py e2e/cases/bpftrace/case.py e2e/cases/katran/case.py e2e/cases/scx/case.py runner/libs/__init__.py runner/libs/run_artifacts.py`
- result: `0` matches

Repository-wide residual grep after this change:
- `e2e/cases/tetragon/*` and `e2e/cases/tracee/*`
- `e2e/README.md`
- `micro/README.md`

Reason:
- Tetragon and Tracee were explicitly out of scope for this change.
- README examples were not touched.

## Diff Stats

Targeted files only:
- `git diff --shortstat -- Makefile runner/libs/suite_args.py runner/suites/e2e.py micro/driver.py e2e/driver.py e2e/cases/bcc/config.yaml e2e/cases/bcc/case.py e2e/cases/bpftrace/case.py e2e/cases/katran/case.py e2e/cases/scx/case.py runner/libs/__init__.py runner/libs/run_artifacts.py`
- result: `12 files changed, 44 insertions(+), 127 deletions(-)`

Whole worktree at report time:
- `git diff --shortstat`
- result: `18 files changed, 72 insertions(+), 199 deletions(-)`

Note:
- The whole-worktree stat includes unrelated concurrent dirty files from other codex sessions.

## Self Review

Questions:
- Did this leave a hidden replacement mode such as `fast/minimal/quick`?  
  No. The touched code now has a single default path.
- Did any touched entrypoint still accept smoke flags/env?  
  No. `vm-micro-smoke`, `E2E_SMOKE`, `--e2e-smoke`, and `e2e/driver.py --smoke` are all removed.
- Did the touched e2e cases still choose between two default durations?  
  No. They now use `CLI override -> single default`.
- Is the default run now the small run?  
  Yes, for touched surfaces:
  - micro defaults already minimal
  - corpus default samples now `1`
  - touched e2e defaults were reduced to prior smoke durations

Residual non-unified surfaces:
- Tracee smoke config remains.
- Tetragon smoke config remains.

Those are intentional residuals caused by the explicit "do not touch tracee/tetragon" constraint, not by incomplete deletion inside the files changed here.
