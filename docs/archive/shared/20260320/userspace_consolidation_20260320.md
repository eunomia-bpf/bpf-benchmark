# Userspace Consolidation 2026-03-20

## Summary

- Removed `legacy/` after repo-wide grep showed no live code imports/callers outside documentation.
- Consolidated the active micro suite runner into `micro/driver.py` and deleted the dead rigorous path.
- Deleted `corpus/fetch_bcf_dataset.py` and `corpus/analyze_bytecode.py` as manual one-off scripts with no active automation callers.
- Kept `corpus/build_expanded_corpus.py`, `corpus/fetch_real_world_corpus.py`, `corpus/results_layout.py`, `scripts/aws_arm64.sh`, `scripts/arm64_qemu_smoke.py`, and `docker/arm64-crossbuild.Dockerfile`.
- `e2e/run_e2e_tracee.py` was already deleted in the current worktree; the live Tracee fallback now comes from `e2e/cases/tracee/manual.py`.

## Audit Notes

### `legacy/`

- Repo grep used:
  - `rg -n '\blegacy/' . --glob '!vendor/linux-framework/**' --glob '!legacy/**'`
- Result: only `README.md`, `CLAUDE.md`, and historical docs referenced `legacy/`; there were no live imports or executable entrypoints.
- Pre-delete footprint:
  - `du -sh legacy` -> `85M`
  - `find legacy -type f | wc -l` -> `311`
- `.gitignore` had no legacy-specific ignore rule, so no change was needed there.

### `micro/`

- `micro/driver.py` now owns the suite implementation directly and still accepts the legacy `suite` prefix so the current `Makefile` continues to work unchanged.
- Deleted:
  - `micro/_driver_impl_run_micro.py`
  - `micro/_driver_impl_run_rigorous.py`
  - `micro/_driver_impl_run_rigorous_framework_vm.py`
  - `runner/libs/rigorous.py`
- Deletion evidence for rigorous:
  - repo grep found only `micro/driver.py` importing the rigorous impls
  - no `Makefile` target or GitHub workflow invoked `micro/driver.py rigorous`
- Compatibility check:
  - `python3 micro/driver.py suite --help` -> OK
  - `python3 micro/driver.py rigorous --help` -> expected removal message:
    - `micro/driver.py only supports suite runs; micro rigorous mode was removed as unused consolidation dead code`

### `corpus/`

- Kept `corpus/results_layout.py` because it is still imported by:
  - `corpus/driver.py:25-27`
  - `corpus/modes.py:26-28`
- Kept `corpus/fetch_real_world_corpus.py` because it is still used by:
  - `.github/workflows/arm64-benchmark.yml:164`
  - `corpus/README.md`
- Kept `corpus/build_expanded_corpus.py` because it is still used by:
  - `.github/workflows/arm64-benchmark.yml:165`
  - `e2e/README.md:21`
  - `corpus/README.md`
- Deleted `corpus/fetch_bcf_dataset.py`:
  - no `Makefile`, `corpus/driver.py`, active code, or workflow caller
  - only documentation/historical references remained
- Deleted `corpus/analyze_bytecode.py`:
  - no `Makefile`, `corpus/driver.py`, active code, or workflow caller
  - only documentation/historical references remained
- Note:
  - `docs/micro-bench-status.md` and `docs/benchmark-framework-design.md` still mention the removed BCF analysis path. I left those historical/non-canonical docs untouched; `docs/micro-bench-status.md` is also already dirty in this worktree.

### `scripts/` and `docker/`

- Kept `scripts/aws_arm64.sh` in place because it is wired into:
  - `Makefile:29`
  - `Makefile:525-551`
- Kept `scripts/arm64_qemu_smoke.py` in place because it is wired into:
  - `Makefile:20`
  - `Makefile:503-512`
- Kept `docker/arm64-crossbuild.Dockerfile` in place because it is wired into:
  - `Makefile:23`
  - `Makefile:364-370`
  - `Makefile:473`

### `e2e/`

- `e2e/run_e2e_tracee.py` was already deleted in the current worktree before this consolidation pass.
- The live Tracee manual fallback is now sourced from:
  - `e2e/cases/tracee/case.py:59`
  - `e2e/cases/tracee/case.py:712`
- I made no extra `e2e/` edits here to avoid interfering with the concurrent tracee/katran cleanup already present in the worktree.

## Verification

- `python3 -m py_compile micro/driver.py corpus/driver.py scripts/arm64_qemu_smoke.py` -> passed
- `python3 micro/driver.py suite --help` -> passed
- `python3 micro/driver.py rigorous --help` -> removal message as expected
- `source /home/yunwei37/workspace/.venv/bin/activate && make smoke` -> passed
  - smoke result summary:
    - `simple`
    - `llvmbpf`
    - compile median `4.811 ms`
    - exec median `112 ns`
- `source /home/yunwei37/workspace/.venv/bin/activate && make scanner-tests` -> passed
  - `ctest`: `1/1` tests passed

## Counts

- Deleted on-disk files: `317`
  - `311` files from `legacy/`
  - `6` direct script/library removals outside `legacy/`
- Deleted tracked Git paths in this change set: `121`
- Modified tracked files in this change set: `6`
- Tracked text diff across touched paths:
  - `+615 / -32944`
  - net `-32329` lines
- Legacy footprint removed from the checkout: `85M`
