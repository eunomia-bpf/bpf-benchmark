# Post-Cleanup Architecture Review (2026-03-29)

Scope:
- Reviewed `docs/kernel-jit-optimization-plan.md` §5.6.
- Reviewed `docs/tmp/20260329/corpus_e2e_deep_review_20260329.md`.
- Reviewed `docs/tmp/20260329/benchmark_yaml_redesign_20260329.md`.
- Audited the benchmark framework after cleanup commits `8565cbb` and `3101592`.
- Modified code directly where the remaining architecture violations were still on the active corpus/e2e/runner path.

## Executive Summary

The active corpus/e2e benchmark path is now materially closer to the §5.6 target:

1. `macro_corpus.yaml` is gone; the shared suite is `corpus/config/macro_apps.yaml`.
2. The active corpus path is app/YAML driven, not object-planning driven.
3. Katran has been removed from the active corpus/e2e runner surface because the remaining implementation still depended on `bpftool prog loadall`.
4. E2E daemon lifecycle is now explicit and session-scoped instead of being started inside `case_common.py`.
5. Several silent-failure and fallback paths were removed from runners, result parsing, workload selection, and setup helpers.

I also found and fixed a few regressions introduced during the earlier cleanup:
- `bcc`/`bpftrace` phase functions were incorrectly depending on a non-local `args`.
- `tracee` had a lifecycle block accidentally indented inside an error branch.

## Fixed In This Pass

### 1. Katran was still partially present on the active benchmark path

Fixed:
- Removed `katran/default` from `corpus/config/macro_apps.yaml`.
- Removed Katran from `e2e/run.py` dispatch by deleting the remaining case file and dead setup entrypoints.
- Deleted `runner/libs/app_runners/katran.py` and the already-obsolete `runner/libs/app_runners/katran_support.py`.
- Removed Katran from `e2e/README.md`.
- Removed Katran smoke runs from:
  - `runner/scripts/x86_remote_benchmark.py`
  - `runner/scripts/arm64_t4g_remote_benchmark.py`
- Removed Katran-specific E2E bundle handling from:
  - `runner/scripts/aws_x86.sh`
  - `runner/scripts/aws_arm64.sh`

Result:
- There is no active corpus/e2e runner entry that still uses Katran.
- The forbidden `bpftool loadall` Katran loader path is gone from the active benchmark harness.

### 2. E2E daemon lifecycle was still too implicit in some paths

Fixed:
- `runner/libs/case_common.py` is now prepare-only; it no longer starts a daemon.
- `e2e/run.py` already shares one explicit daemon session; this pass fixed the remaining case-level regressions.
- `bcc` and `bpftrace` phase helpers now require an injected prepared daemon session instead of reaching for a stray global.
- `runner/scripts/x86_remote_benchmark.py` now uses one explicit `DaemonSession` for the micro ReJIT run instead of implicit `scan_programs()/apply_daemon_rejit()` auto-start behavior.
- `runner/scripts/arm64_t4g_remote_benchmark.py` now also uses `DaemonSession` instead of manual `_start_daemon_server()` / `_stop_daemon_server()` wiring.

Result:
- Active benchmark paths now follow the §5.6 rule that daemon lifecycle belongs to the benchmark session layer.

### 3. Object-centric compatibility hooks were still present in active app runners

Fixed:
- Earlier cleanup already removed object-derived routing from:
  - `runner/libs/app_runners/__init__.py`
  - `runner/libs/app_runners/libbpf_bootstrap.py`
  - `runner/libs/app_runners/systemd.py`
  - `runner/libs/app_runners/xdp_tools.py`
  - `runner/libs/app_runners/xdp_tutorial.py`
  - `runner/libs/app_runners/scx.py`
- This pass removed the remaining constructor-level `object_path` compatibility from:
  - `runner/libs/app_runners/bcc.py`
  - `runner/libs/app_runners/bpftrace.py`
  - `runner/libs/app_runners/tracee.py`
  - `runner/libs/app_runners/tetragon.py`

Result:
- Active app runners are no longer object-entrypoint compatible shims.
- The active constructor contract is app/tool/script/scheduler oriented.

### 4. Fallback and silent-failure paths still existed

Fixed:
- Removed the default sleep workload fallback from `runner/libs/app_runners/process_support.py`.
- Removed the `stress-ng --switch` scheduler fallback from `runner/libs/workload.py`.
- Made `runner/libs/results.py` fail on malformed JSON-looking lines instead of silently skipping them.
- Made `runner/libs/rejit.py` fail loudly on daemon socket/request errors instead of synthesizing fake error payloads.
- Tightened `runner/libs/app_runners/tetragon_support.py`:
  - no fallback `bpftool` path guessing
  - no empty-list fallback on malformed `bpftool prog show` payloads
- Tightened setup helpers:
  - `e2e/cases/bcc/setup.sh`
  - `e2e/cases/tetragon/setup.sh`
  - `e2e/cases/tracee/setup.sh`
  These now fail on apt install/update errors in the critical package-install path instead of swallowing them.
- `e2e/cases/scx/case.py` now requires a fixed workload tool set instead of silently changing semantics based on which generator happens to be installed.

Result:
- The benchmark meaning is now more stable across environments.
- Missing dependencies fail louder instead of changing workload semantics behind the user’s back.

### 5. Dead Katran-only helper code remained

Fixed:
- Deleted `runner/libs/corpus.py`, which had become an unused Katran packet helper after the YAML redesign.

## Specific Checks Requested By The Review Task

### `macro_corpus.yaml`

Status:
- Confirmed absent from `corpus/config/`.
- Active shared suite is `corpus/config/macro_apps.yaml`.

### Object-layer planning / diversion code

Status:
- The active corpus entrypoint `corpus/orchestrator.py` is app-suite driven via `runner.libs.app_suite_schema`.
- The old object-routing compatibility that still mattered on active runner entrypoints has been removed.

Residual note:
- Object-centric code still exists in micro/test-run infrastructure and low-level build utilities, but not on the active corpus/e2e app-native path.

### `bpftool loadall` as loader

Status:
- Removed from the active Katran corpus/e2e path by removing Katran from runnable benchmark entrypoints.
- Remaining `loadall` references are in the micro remote benchmark path, where the benchmark is intentionally still object/test-run oriented.

### `e2e case_common.py` starting its own daemon

Status:
- Fixed. `case_common.py` no longer starts a daemon.
- It only prepares metadata around an already-started `DaemonSession`.

### Fallback / compatibility / silent failure

Status:
- Major active-path issues fixed in runners, daemon transport, result parsing, SCX workload selection, and setup helpers.

### Duplicate code

Status:
- The worst duplicate Katran support stack was removed by deleting the remaining active Katran case/runner code.
- The earlier runner consolidation remains intact.

## Remaining Architecture Debt

These are no longer on the active corpus/e2e runnable path, but they still exist in the tree:

1. Katran source/build support still exists in build-oriented code:
   - `runner/repos.yaml`
   - `runner/Makefile`
   - `runner/scripts/build_corpus_native.py`
2. Katran-specific test fixture support still exists in `runner/src/kernel_runner.cpp` for micro/test-run style execution.
3. The micro remote benchmark scripts still use `bpftool prog loadall` for object-level micro measurement, which is acceptable for micro/test-run but not aligned with the app-native corpus/e2e design.
4. Some AWS/helper shell scripts still contain `|| true` around cloud or packaging housekeeping. Those are operational cleanup targets, but they are outside the core runnable corpus/e2e correctness path reviewed here.
5. `runner/libs/rejit.py` is still structurally too large even though the active-path daemon semantics are now explicit.

## Validation

Static validation:

```bash
python3 -m py_compile \
  corpus/orchestrator.py e2e/run.py \
  e2e/cases/bcc/case.py e2e/cases/bpftrace/case.py e2e/cases/scx/case.py \
  e2e/cases/tetragon/case.py e2e/cases/tracee/case.py \
  runner/libs/app_runners/bcc.py runner/libs/app_runners/bpftrace.py \
  runner/libs/app_runners/tracee.py runner/libs/app_runners/tetragon.py \
  runner/scripts/x86_remote_benchmark.py runner/scripts/arm64_t4g_remote_benchmark.py
```

Shell syntax validation:

```bash
bash -n \
  runner/scripts/aws_x86.sh runner/scripts/aws_arm64.sh \
  e2e/cases/bcc/setup.sh e2e/cases/tetragon/setup.sh e2e/cases/tracee/setup.sh
```

Targeted tests:

```bash
python3 -m pytest \
  tests/python/test_bcc_runner.py \
  tests/python/test_case_common.py \
  tests/python/test_bcc_case.py \
  tests/python/test_run_artifacts.py \
  tests/python/test_corpus_orchestrator.py \
  -q
```

Result:
- `26 passed`

## Bottom Line

After `8565cbb` and `3101592`, the main remaining active-path architecture problems were:
- lingering Katran entrypoints
- stray object-compat constructors
- daemon lifecycle regressions in case helpers / remote runners
- several fallback and silent-failure paths

Those have now been removed or tightened on the runnable corpus/e2e benchmark path.

What still remains is mostly dead or out-of-path surface:
- Katran build/test-run support
- micro/test-run `loadall` paths
- helper-script cleanup
- the internal size/shape of `runner/libs/rejit.py`
