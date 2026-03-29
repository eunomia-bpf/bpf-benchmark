# E2E / Corpus Quality Review

Date: `2026-03-29`

## Scope

Reviewed:

- `e2e/run.py`
- `e2e/case_common.py`
- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/katran/case.py`
- `e2e/cases/bcc/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/scx/case.py`
- `corpus/driver.py`
- `corpus/modes.py`
- `corpus/config/macro_corpus.yaml`
- `corpus/config/benchmark_config.yaml`
- `runner/libs/corpus.py`
- `runner/libs/rejit.py`
- `runner/libs/results.py`
- `runner/libs/vm.py`

Also touched the daemon client call path used by corpus static verify:

- `runner/include/daemon_client.hpp`
- `runner/src/daemon_client.cpp`
- `runner/src/batch_runner.cpp`
- `runner/src/kernel_runner.cpp`
- `runner/machines.yaml`

## Findings And Fixes

### 1. E2E was still allowing non-failing `skipped` results

Fixed.

- `e2e/run.py` no longer treats `status=skipped` as a successful case result.
- `tracee` no longer returns `skip_payload()` for missing binary or failed preflight activity checks. These now return `error` payloads and fail the case.
- `tracee` preflight abort paths now use `LifecycleAbort(status="error")`.
- `tetragon` markdown/error rendering no longer preserves a fake `SKIP` success path.

Impact:

- E2E failures now propagate as failures instead of being disguised as skips.

### 2. Tetragon and Katran could finish `ok` without a valid post-ReJIT phase

Fixed.

- `e2e/cases/tetragon/case.py` now marks the payload as `error` if ReJIT did not apply or if `post_rejit` is missing.
- `e2e/cases/katran/case.py` no longer downgrades post-ReJIT measurement failures into a limitation string.
- `katran` now raises when a cycle has no applied ReJIT result or no post-ReJIT phase.

Impact:

- Zero Silent Failure is restored for same-image paired E2E runs.

### 3. BCC still swallowed cleanup/output-finalization errors

Fixed.

- `e2e/cases/bcc/case.py` no longer uses `except Exception: pass` when flushing/closing or reading captured output.
- Cleanup/finalization failures are now surfaced as `RuntimeError`s.

Impact:

- Log capture and teardown failures are visible and fail the phase.

### 4. Corpus site-scan policy resolution could silently fail open

Fixed.

- `runner/libs/corpus.py::scan_program_site_counts()` now raises on:
  - failed batch runs
  - timeouts
  - job-level errors
  - malformed payloads
  - missing per-program static-verify records

Impact:

- YAML policy resolution no longer silently falls back to default passes when static verify data is missing or broken.

### 5. Corpus local daemon crash was not fail-fast

Fixed.

- `runner/libs/corpus.py::run_objects_locally_batch()` now checks the locally started daemon process after policy scan, after generic batch execution, and around app-native object execution.
- If the daemon exits, the run aborts immediately with daemon log context.

Impact:

- Corpus runs now fail the whole session when the daemon crashes, instead of drifting into partial/broken later batches.

### 6. Guest batch mode still returned success on job errors

Fixed.

- `corpus/modes.py::run_guest_batch_mode()` now raises `SystemExit` on `completed_with_job_errors` instead of printing to `stderr` and returning `0`.

Impact:

- VM corpus mode now obeys Zero Silent Failure end-to-end.

### 7. Misleading default `compile_only` behavior remained in manifest resolution

Fixed.

- `runner/libs/corpus.py::resolve_manifest_object()` no longer defaults missing object test methods to `compile_only`.
- Object-only manifest entries now resolve to `test_method="object_only"`.
- Program-bearing manifest entries without an explicit object-level `test_method` now fail loudly during manifest resolution.

Impact:

- Old v1-style implicit compile-only behavior is removed from default manifest handling.

### 8. Default macro corpus still contained dead/manual and compile-only entries

Fixed.

Removed from `corpus/config/macro_corpus.yaml`:

- `corpus/build/manual-test/fentry.gen.bpf.o`
- `corpus/build/manual-test/fentry.tmp.bpf.o`
- `corpus/build/tetragon/bpf_execve_map_update.bpf.o`

Impact:

- Default corpus no longer advertises manual-test artifacts or the known compile-only Tetragon seccomp object.

### 9. Static verify was not using daemon dry-run at the C++ socket client boundary

Fixed.

- Added a `dry_run` flag to `daemon_socket_optimize(...)`.
- `runner/src/batch_runner.cpp` now sends `dry_run=true` for `static_verify_object`.
- `runner/src/kernel_runner.cpp` keeps normal optimize requests on `dry_run=false`.

Impact:

- Per-pass verify now correctly uses the daemon dry-run path backed by `BPF_PROG_LOAD` validation semantics.

### 10. Missing benchmark config still had a silent fallback path

Fixed.

- `runner/libs/rejit.py` now fails loudly if `corpus/config/benchmark_config.yaml` is missing instead of silently loading a fallback root config.

Impact:

- Missing repo-owned benchmark config is now a hard error.

### 11. ARM64 alias default still pointed to local QEMU

Fixed.

- `runner/machines.yaml` now maps `arm64` to `aws-arm64`.

Impact:

- The default ARM64 alias now follows the documented AWS-remote path.

## Confirmed Requirements

Verified and left unchanged:

- `corpus/config/benchmark_config.yaml` default pipeline does not include out-of-scope security passes (`speculation_barrier`, `dangerous_helper_firewall`, `live_patch`).
- `corpus/config/macro_corpus.yaml` does not include `linux-selftests` in the default object list; it remains optional.
- `runner/libs/results.py` already uses applied-only exec geomean as the main metric and also reports all-comparable separately.
- `runner/libs/vm.py` already enforces `RLIMIT_NOFILE >= 65536` for guest corpus batch execution.
- `runner/libs/corpus.py` already reuses one daemon session across corpus bulk prepare/apply/measure flow.
- `e2e/case_common.py` already persists kinsn module evidence into E2E result metadata; `tests/python/test_e2e_run.py` covers this path.

## Dead Code / Hygiene Notes

- Removed dead `skip_payload()` usage from Tracee case flow.
- Removed the now-misleading `skipped` success handling from `e2e/run.py`.
- Removed dead default-corpus manual-test entries.
- No `TODO` / `FIXME` markers were found in the reviewed Python scope. The only `HACK`-named item observed was `HACKBENCH_TIME_RE` in `scx`, which is just a regex symbol name, not a pending-work marker.

## Validation

Executed:

```bash
python3 -m py_compile \
  e2e/run.py \
  e2e/cases/tracee/case.py \
  e2e/cases/tetragon/case.py \
  e2e/cases/katran/case.py \
  e2e/cases/bcc/case.py \
  runner/libs/rejit.py \
  runner/libs/corpus.py \
  corpus/modes.py \
  tests/python/test_tracee_case.py \
  tests/python/test_e2e_run.py \
  tests/python/test_corpus_modes.py \
  tests/python/test_rejit.py
```

Result: passed

Executed:

```bash
pytest tests/python/ -q
```

Result: `78 passed`

## Residual Risk

- I did not change `e2e/cases/bpftrace/case.py` or `e2e/cases/scx/case.py` because the reviewed paths there were already aligned with the checked constraints and did not exhibit the same silent-failure issues found in Tracee/Tetragon/Katran/BCC.
- I did not modify `corpus/config/benchmark_config.yaml` because all referenced default passes were present and in-scope.
