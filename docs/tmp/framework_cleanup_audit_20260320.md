# Benchmark Framework Cleanup Audit

Date: 2026-03-20

Scope: audit and cleanup of scattered files, dead code, and unnecessary directories in the benchmark framework.

## Summary

This cleanup removed the root-level scratch residue, deleted two stale `micro/` helper scripts, and retired the legacy standalone Tracee harness after moving its still-live manual-fallback loader into `e2e/cases/tracee/manual.py`.

Verification after cleanup:

- `source /home/yunwei37/workspace/.venv/bin/activate && make smoke` ✅
- `source /home/yunwei37/workspace/.venv/bin/activate && make scanner-tests` ✅
- `python3 -m py_compile e2e/cases/tracee/manual.py e2e/cases/tracee/case.py micro/driver.py corpus/driver.py scripts/arm64_qemu_smoke.py` ✅

## Audit Results

| Path | Audit Result | Evidence | Final Action |
| --- | --- | --- | --- |
| `build-arm64/` | Untracked empty root directory | Direct filesystem inspection showed it was empty and not tracked by git | Deleted; added root ignore rule |
| `live-xlated-test.64Crqc/` | Untracked empty temp directory | Direct filesystem inspection showed it was empty and not tracked by git | Deleted; added root ignore rule |
| `tmp/` | Untracked root scratch tree with historical JSON/MD/Python/mem artifacts plus Katran build leftovers | Direct filesystem inspection showed only scratch data; root `.gitignore` already treated repo-root `tmp/` as scratch | Deleted entire directory; retained ignore coverage |
| `micro/_driver_impl_run_micro.py` | Active code | Imported by `micro/driver.py` for `suite` dispatch | Kept |
| `micro/_driver_impl_run_rigorous.py` | Active code | Imported by `micro/driver.py` for `rigorous` dispatch | Kept |
| `micro/_driver_impl_run_rigorous_framework_vm.py` | Active code | Imported by `micro/driver.py` for `rigorous --transport vm` | Kept |
| `micro/run_corpus_tracing.sh` | Dead and broken | No references in repo; script called `python3 micro/driver.py corpus tracing`, but `micro/driver.py` only supports `suite` and `rigorous` | Deleted |
| `micro/dump_all_jit.sh` | Dead and broken | No runtime references; only historical docs mentioned it. Script expected `micro/build/runner/micro_exec` and `make -C micro micro_exec`, but current tree builds the runner under `runner/build/` and `micro/Makefile` has no `micro_exec` target | Deleted |
| `corpus/analyze_bytecode.py` | Long-lived support script, not dead | Documented in `corpus/README.md` as the BCF static-analysis tool | Kept |
| `corpus/build_expanded_corpus.py` | Active support/build entrypoint | Referenced by `e2e/README.md`, `corpus/README.md`, and `.github/workflows/arm64-benchmark.yml` | Kept |
| `corpus/fetch_bcf_dataset.py` | Long-lived support script, not dead | Documented in `corpus/README.md` as the BCF refresh step | Kept |
| `corpus/fetch_real_world_corpus.py` | Active support/build entrypoint | Referenced by `corpus/README.md` and `.github/workflows/arm64-benchmark.yml` | Kept |
| `scripts/arm64_qemu_smoke.py` | Active infra script | Used by root `Makefile` via `ARM64_SMOKE_SCRIPT` | Kept in `scripts/` |
| `scripts/aws_arm64.sh` | Active infra script | Used by root `Makefile` via `AWS_ARM64_SCRIPT` | Kept |
| `docker/arm64-crossbuild.Dockerfile` | Active infra asset | Used by root `Makefile` via `ARM64_CROSSBUILD_DOCKERFILE` | Kept |
| `e2e/run_e2e_tracee.py` | Legacy wrapper, partially live before cleanup | `e2e/cases/tracee/case.py` imported `Libbpf` and `ManualTraceeSession` from it, but no active entrypoint called the standalone CLI | Moved the live manual-fallback loader into `e2e/cases/tracee/manual.py`, updated imports, then deleted the legacy wrapper |

## Repo Hygiene Changes

- Added root-only `.gitignore` coverage for `/build-arm64/` and `/live-xlated-test.*/`
- Removed the obsolete `.gitignore` exception for `micro/dump_all_jit.sh`
- Updated `e2e/README.md` to describe the new `e2e/cases/tracee/manual.py` location
- Updated `docs/micro-bench-status.md` so it no longer points at the deleted `micro/dump_all_jit.sh`

## Notes

- Deleting root `tmp/` required `sudo -n` because the old Katran docker worktree contained root-owned build outputs.
- I observed unrelated pre-existing worktree changes outside this cleanup scope, including `corpus/driver.py`, `e2e/cases/katran/case.py`, and `e2e/run.py`. They were left untouched.

## Verification Details

`make smoke` result:

- Passed on 2026-03-20
- Summary line: `SMOKE OK: simple llvmbpf exec 67 ns, compile 4.783 ms, result 12345678`

`make scanner-tests` result:

- Passed on 2026-03-20
- `ctest` summary: `100% tests passed, 0 tests failed out of 1`
