# Strict Review Second Pass 2026-03-29

## Scope

- Read and cross-checked:
  - `docs/tmp/20260329/strict_final_review_20260329.md`
  - `docs/tmp/20260329/strict_review_fixes_20260329.md`
- No VM work, no kernel/BPF runtime actions on host, no `vendor/linux-framework` edits, no commits.

## Step 1 Verification

  - First verification run: `70 passed`
  - After one second-pass fix described below: `71 passed`
- `make daemon-tests`
  - Passed: `535 passed; 0 failed`
- Import / dangling reference audit:
    - `runner/libs/catalog.py`
    - `runner/libs/commands.py`
    - `runner/libs/object_discovery.py`
  - Package import sweep over live repo modules succeeded:
    - `checked=70`
    - `all package imports loaded successfully`

## CRITICAL / HIGH Cross-check

### CRITICAL

- Remote benchmark loaders: fixed.
  - `runner/scripts/x86_remote_benchmark.py` and `runner/scripts/arm64_t4g_remote_benchmark.py` are deleted.
  - `runner/scripts/aws_x86.sh` and `runner/scripts/aws_arm64.sh` now hard-fail with retirement messages instead of routing into the deleted loader flow.
- `corpus/orchestrator.py` repeat bug: fixed.
  - `_run_app()` now executes baseline and post-ReJIT workloads inside `for _ in range(repeat)` loops and records `baseline_workloads` / `rejit_workloads`.
- Loader-instance `prog_fds` identity: fixed.
  - `runner/libs/daemon_session.py` passes `prog_fds` through to live scan.
  - `runner/libs/rejit.py` now rejects scan requests that do not provide loader-owned FDs for all requested programs.
  - `runner/libs/app_runners/tracee_support.py` duplicates loader-owned FDs with `pidfd_getfd` and fails if a program FD cannot be obtained or closed cleanly.
- Tracee fallback / silent skip path: fixed.
  - No `/proc/<pid>/fd` fallback remains.
  - Missing owner FDs, failed `pidfd_getfd`, and close failures now raise explicit errors.

### HIGH

- `runner/libs/agent.py` health check swallowing: fixed.
  - `wait_healthy()` now directly propagates `health_check_fn()` exceptions instead of retrying silently until timeout.
- `runner/libs/app_runners/scx_support.py` fallback cleanup: fixed, with one additional second-pass correction.
  - First-pass fixes correctly made unreadable sched_ext state / ops fatal.
  - Second pass found one incomplete shell path: `ulimit -l unlimited; exec ...` still continued after `ulimit` failure because of shell sequencing.
  - Fixed in this pass by switching to `set -euo pipefail; ulimit -l unlimited; exec ...`.
- `e2e/cases/scx/case.py` degraded payload path: fixed.
  - Missing per-program runtime counters now abort with `RuntimeError` instead of being downgraded into a limitations payload.
- Shared lifecycle / kinsn silent fallback: fixed.
  - `runner/libs/kinsn.py` now raises on missing module directories, missing loader script, incomplete module loads, and missing daemon discovery output.
  - `runner/libs/case_common.py` now preserves these failures as explicit lifecycle errors instead of collapsing them to `"missing"` / `"unknown"` placeholders.
- `runner/libs/bpf_stats.py` opportunistic fallback: fixed.
  - Stats collection now hard-requires usable libbpf entrypoints and raises if any requested program stat cannot be read.
- `runner/libs/workload.py` partial connect-failure masking: fixed.
  - `run_rapid_connect_storm()` now raises if any connection attempt fails, even if some operations succeeded.
- `runner/Makefile` Tracee/Tetragon setup caching fallback: fixed.
  - `e2e-tracee-setup` and `e2e-tetragon-setup` now invoke the setup scripts directly; they no longer silently reuse cached/system binaries.
- Tracee/Tetragon binary fallback chains: fixed.
  - `runner/libs/app_runners/tracee_support.py` now resolves Tracee only from explicit path or setup-script output.
  - `runner/libs/app_runners/tetragon_support.py` now resolves Tetragon only from explicit path or setup-script output.
- `runner/src/kernel_runner.cpp` degraded skip / degraded BTF mode: fixed.
  - Katran fixture initialization now fails if required maps or FDs are missing.
  - vmlinux BTF preload failure now aborts construction instead of logging and continuing.
- Shared object-centric helper leftovers: fixed in live framework code.
  - Deleted `runner/libs/catalog.py`, `runner/libs/commands.py`, `runner/libs/object_discovery.py`.
  - Micro-only manifest handling now lives in `micro/catalog.py`.
- `e2e/cases/bpftrace/case.py` stale micro/runner coupling: fixed.
  - No live `--runner`, `micro_exec`, or `runner/build/micro_exec` coupling remains in `e2e/run.py`, `e2e/cases/bpftrace/case.py`, `e2e/cases/tetragon/case.py`, `e2e/cases/tracee/case.py`, or the Python tests.

## Misdelete / Leftover Audit

- `micro/catalog.py` is required and present. No restore was needed.
- The micro entrypoints now correctly import it:
  - `micro/driver.py`
  - `micro/summarize_rq.py`
  - `micro/generate_figures.py`
  - `runner/libs/reporting.py`
- No live-code references to deleted `runner/libs/catalog.py` remain.
- No live-code references to deleted `runner/libs/commands.py` or `runner/libs/object_discovery.py` remain.
- No live-code `bpftool prog loadall` path remains in the reviewed Python/shell entrypoints.
- Remaining `object_path` references are confined to the micro-only flow (`micro/catalog.py`, `micro/driver.py`), which is acceptable and matches the requested “if micro still needs catalog.py, restore or move it under micro”.
- Historical material still contains old names and object-centric terms:
  - `docs/tmp/**`
  - historical JSON outputs under `micro/results/` and `corpus/results/`
  - some README text
  - These are not live runtime/import paths and were not changed in this pass.

## Additional Finding Fixed In This Pass

- `runner/libs/app_runners/scx_support.py`
  - Problem: memlock setup was still not truly fail-fast because `ulimit -l unlimited; exec ...` continues on shell failure.
  - Fix: prepend `set -euo pipefail;` so a failing `ulimit` aborts the scheduler launch immediately.

## Outcome

- One real issue remained after the first fix batch: incomplete SCX fail-fast shell handling.
- That issue is fixed.
- Final Python regression status: `71 passed`.
- `make daemon-tests` had already passed earlier in this pass, and the follow-up fix touched Python-only SCX wrapper code plus a Python test; no daemon/Rust/C++ files changed afterward.
- In the reviewed scope, I did not find any remaining unfixed CRITICAL/HIGH items from the first strict review.
