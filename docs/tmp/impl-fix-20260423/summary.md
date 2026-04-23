# Impl Fix Summary (2026-04-23)

## Applied fixes

### BLOCKER — Katran runner import-time `NameError`

- File:line:
  - `runner/libs/app_runners/katran.py:72-74`
  - `runner/libs/app_runners/katran.py:459-460`
  - `runner/libs/app_runners/katran.py:773-778`
- Before:
  - `KatranServerSession.__init__(..., root_map_pos=DEFAULT_ROOT_MAP_POS)` referenced `DEFAULT_ROOT_MAP_POS` before that constant existed.
  - The `DEFAULT_ROOT_MAP_POS` / `DEFAULT_HC_V4_TUN_IFACE` / `DEFAULT_HC_V6_TUN_IFACE` definitions only appeared later near the runner defaults, so importing `runner.libs.app_runners.katran` failed at module load time.
- After:
  - Hoisted those constants to `katran.py:72-74`, above the class definition that uses them.
  - Removed the later duplicate definitions so there is a single source of truth.
  - Import smoke now succeeds.

### HIGH — Tracee `--events all` must fail loud on partial stabilization

- File:line:
  - `runner/libs/app_runners/process_support.py:45-50`
  - `runner/libs/app_runners/tracee.py:494-496`
  - `e2e/cases/tracee/case.py:66`
- Before:
  - `wait_until_program_set_stable()` returned the last partial program set on timeout, so a slow `--events all` attach could silently undercount instead of failing.
  - Tracee load timeout stayed at `60s`.
- After:
  - Stabilization timeout now raises `RuntimeError` with the timeout, last program count, and a preview of the last seen ids.
  - Raised Tracee runner and e2e load timeouts from `60s` to `120s`.

### HIGH — `macro_apps.yaml` e2e workload names restored to real case-config names

- File:line:
  - `corpus/config/macro_apps.yaml:86-102`
- Before:
  - `tetragon/default` used `e2e: tetragon_exec_connect_mix`, but `e2e/cases/tetragon/config_execve_rate.yaml` only exposes `exec_storm`.
  - `tracee/default` used `e2e: tracee_system_edge_mix`, but `e2e/cases/tracee/config.yaml` only exposes `tracee_default`.
- After:
  - `tetragon/default` now uses `e2e: exec_storm`.
  - `tracee/default` now uses `e2e: tracee_default`.

### MEDIUM — workload variants now fail loud instead of silently degrading

- File:line:
  - `runner/libs/workload.py:218-241`
  - `runner/libs/workload.py:263-288`
  - `runner/libs/workload.py:752-788`
  - `runner/libs/workload.py:980-1000`
- Before:
  - `tracee_system_edge_mix` recorded cgroup mkdir/rmdir failure as a note and kept going.
  - `open_family_storm` recorded `openat2` failure as a note and kept going.
  - `tracee_module_load_loop` only checked `modprobe` inline during the cycle and could collapse missing repo module tree into the generic “no eligible module candidates” path.
- After:
  - `_exercise_cgroup_mkdir_rmdir_once()` now reports failure text, and `run_tracee_system_edge_mix_workload()` raises immediately if cgroup create/remove cannot be exercised.
  - `run_open_family_storm_workload()` now raises immediately on `openat2` failure with `open_family_storm requires openat2: ...`.
  - Added `_ensure_tracee_module_load_prereqs()` to fail early unless `modprobe` exists and `repo_kernel_modules_root()/lib/modules/$(uname -r)` is present.
  - `run_tracee_module_load_loop_workload()` calls that explicit prereq check before starting the loop, and `_run_module_load_cycle()` reuses it.

### LOW — `map_inline` relaxed alias handling now has the missing negative test

- File:line:
  - `daemon/src/passes/map_inline_tests.rs:647-669`
- Before:
  - Tests covered positive alias-offset loads, but did not lock in that a non-zero-offset alias must not be treated as a removable null check.
- After:
  - Added `classify_r0_uses_does_not_treat_non_zero_alias_offset_as_null_check()`.
  - The test asserts `null_check_pc == None`, keeps the load in `other_uses`, and still recognizes the effective fixed load offset.

## Validation

- `python3 -m py_compile runner/libs/app_runners/process_support.py runner/libs/app_runners/tracee.py runner/libs/app_runners/katran.py runner/libs/workload.py e2e/cases/tracee/case.py`
  - passed
- `make check`
  - passed
- `cargo test --manifest-path daemon/Cargo.toml`
  - passed
  - result: `499 passed; 0 failed`
- `make -C daemon release`
  - passed
- `python3 -c 'from runner.libs.app_runners.katran import KatranRunner; print("ok")'`
  - passed
  - output: `ok`

Not run, per instruction:

- `vm-e2e`
- `vm-corpus`

## Diff stat

- `git diff --shortstat`
  - `12 files changed, 1221 insertions(+), 164 deletions(-)`
  - This is the full current worktree shortstat, which includes the earlier in-progress implementation edits already present before this fix-up turn.
