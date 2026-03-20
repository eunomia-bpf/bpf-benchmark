# Benchmark Post-Refactor Audit

Date: 2026-03-20

## Scope

Audit target: post-refactor cleanup after `runner/` extraction, corpus driver consolidation, and migration of shared E2E helpers into `runner.libs`.

Requested checks:

- Python compile/import fallout
- Stale path references
- Directory placement for `scripts/`, `docker/`, `legacy/`, `micro/archive/`, and `corpus/tmp/`
- Verification via `make smoke`, `make scanner-tests`, and `python3 micro/driver.py --help`

## Findings And Fixes

### 1. Broken imports / runtime entrypoints

`find . -name '*.py' ... -exec python3 -m py_compile {} \; 2>&1 | grep -i error`

- Result: no errors in the active tree.
- Note: `py_compile` did not catch direct-script import failures caused by the new `runner.libs` package layout.

Fixed:

- `micro/driver.py`
  - `census --help` now forwards to `corpus/directive_census.py --help` instead of failing with `unknown census mode`.
  - `corpus --help` now forwards to the corpus driver help text instead of raising `corpus mode required`.
- `corpus/directive_census.py`
  - Added repo-root `sys.path` bootstrap so direct script execution can import `runner.libs.*`.
- Added the same repo-root bootstrap to direct `micro/` entrypoints that import `runner.libs.*`:
  - `micro/_driver_impl_run_micro.py`
  - `micro/_driver_impl_run_rigorous.py`
  - `micro/_driver_impl_run_rigorous_framework_vm.py`
  - `micro/generate_figures.py`
  - `micro/summarize_rq.py`

Additional spot checks after the fix:

- `python3 corpus/directive_census.py --help` → OK
- `python3 micro/driver.py census --help` → OK
- `python3 micro/generate_figures.py --help` → OK
- `python3 micro/summarize_rq.py --help` → OK

### 2. Stale path references

Raw requested grep after cleanup:

- Total matches: `503`
- Matches in current docs: `0`
- Matches outside docs and archive: `0`
- Matches remaining in `docs/tmp/`: `503` across `93` files

Interpretation:

- Active repo docs are now clean.
- Remaining matches are historical design/review/research records under `docs/tmp/`.
- I left those archive files intact to preserve pre-refactor history instead of rewriting historical references in bulk.

Fixed active references in:

- `corpus/README.md`
  - Removed the stale checked-in `corpus/tmp/` description.
- `docs/micro-bench-status.md`
  - Replaced removed `micro/archive/...` references with surviving archived reports.
  - Updated `micro/runner/...` references to `runner/...`.
- `docs/kernel-jit-optimization-plan.md`
  - Reworded current plan/history entries so active docs no longer point at removed paths.
  - Marked item `277` complete and linked this audit report.

Also removed two stale scratch markdown files from top-level `tmp/` that still matched the raw grep:

- `tmp/bpf_roundtrip_feasibility.md`
- `tmp/ebpf_profiling_tools_analysis.md`

## Directory Placement

### `scripts/`

Kept:

- `scripts/aws_arm64.sh`
  - Still used by the root `Makefile` for `make aws-arm64-*`.
- `scripts/arm64_qemu_smoke.py`
  - Still used by the root `Makefile` for ARM64 QEMU smoke/selftest targets.

Decision:

- `aws_arm64.sh` should stay in `scripts/`.
- No dead tracked scripts remain in `scripts/`.

### `docker/`

Kept:

- `docker/arm64-crossbuild.Dockerfile`
  - Still used by the root `Makefile` for `make arm64-crossbuild-image` and `make selftest-arm64`.

Decision:

- `docker/` is still needed.
- No dead tracked files remain there.

### `legacy/`

Observed:

- Historical benchmark code and third-party references only.
- Still explicitly documented in `README.md` and `CLAUDE.md` as inactive historical material.

Decision:

- Keep `legacy/` as-is.
- No safe tracked deletions were made there during this audit.

### `micro/archive/`

Observed:

- Directory is already absent.

Decision:

- Treat as dead and keep deleted.
- Active docs were updated to stop referencing it.

### `corpus/tmp/`

Observed:

- Directory is already absent.

Decision:

- Treat as dead and keep deleted.
- `corpus/README.md` now matches the filesystem.

## Verification

### Requested checks

- `make smoke` → PASS
  - `simple` llvmbpf smoke completed.
  - Reported `exec median 74 ns`, `compile median 4.688 ms`, result `12345678`.
- `make scanner-tests` → PASS
  - `ctest` reported `100% tests passed, 0 tests failed out of 1`.
- `python3 micro/driver.py --help` → PASS

### Import / compile checks

- Exact `py_compile` scan requested in the task → no errors
- Post-fix direct entrypoint checks listed above → PASS

## Summary

The active post-refactor tree is clean:

- No active Python compile errors
- No active stale path references in current docs
- Direct script entrypoints importing `runner.libs` now work
- `scripts/` and `docker/` are still correctly placed and live
- `micro/archive/` and checked-in `corpus/tmp/` are confirmed gone

Residual note:

- The raw stale-path grep still returns `503` matches, all under `docs/tmp/` historical archive material. Those were intentionally left untouched.
