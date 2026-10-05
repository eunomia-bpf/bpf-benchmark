# Cross-Layer Cleanup Report

Date: 2026-03-20

## Summary

- Removed `corpus` and `census` subcommands from `micro/driver.py`.
- `micro/driver.py` now only exposes `suite` and `rigorous`, and it rejects non-`micro` manifests instead of forwarding into `corpus/`.
- Switched `make vm-corpus` to call `corpus/driver.py` directly.
- Confirmed `make vm-e2e` calls `e2e/run.py` directly and `make vm-micro` calls `micro/driver.py` directly.
- Moved duplicated corpus result/statistics logic onto shared `runner/libs/` helpers by updating `corpus/driver.py` to use `runner.libs.results`.
- Updated active README entrypoint references so they no longer point at `micro/driver.py corpus ...`.

## Files Changed

- `micro/driver.py`
- `corpus/driver.py`
- `Makefile`
- `README.md`
- `corpus/README.md`
- `e2e/cases/tracee/case.py`

## 1. Micro Driver Boundary Fix

`micro/driver.py` previously violated the layer boundary in two ways:

- it imported `corpus.driver`
- it exposed `census` forwarding into `corpus/directive_census.py`

That forwarding has been deleted. The driver now does only:

- `suite`
- `rigorous`

For `suite`, the driver now loads the manifest with `runner.libs.catalog.load_catalog()` and aborts if the manifest kind is not `micro`.

## 2. Cross-Layer Import Scan

Commands run:

```bash
grep -r 'from micro' corpus/ e2e/ --include='*.py' | grep -v __pycache__
grep -r 'from corpus' micro/ e2e/ --include='*.py' | grep -v __pycache__
grep -r 'from e2e' micro/ corpus/ --include='*.py' | grep -v __pycache__
grep -r 'import micro' corpus/ e2e/ --include='*.py' | grep -v __pycache__
grep -r 'import corpus' micro/ e2e/ --include='*.py' | grep -v __pycache__
grep -r 'import e2e' micro/ corpus/ --include='*.py' | grep -v __pycache__
```

Final result:

- all six scans are clean

One intermediate false positive came from a prose string in `e2e/cases/tracee/case.py` that contained the literal text `from corpus/...`; the wording was adjusted so the grep-based audit now reflects actual imports only.

## 3. runner/libs Completeness Check

### Policy loading/parsing

- Centralized already in `runner/libs/policy.py`.
- No cross-layer fix needed here.

### VM boot/exec helpers

- Centralized for shared workflows in `runner/libs/vm.py`.
- `e2e/run.py` already uses it.
- `micro/_driver_impl_run_rigorous_framework_vm.py` still carries a specialized VM script helper because it embeds inline Python payloads and pinning-specific guest execution. That is not a layer violation, but it remains a future consolidation candidate.

### Scanner invocation

- Shared scanner command construction and parsing already live under `runner/libs/corpus.py`, `runner/libs/commands.py`, and `runner/libs/recompile.py`.
- No new cross-layer fix was required.

### Result JSON parsing

- Shared parsing already exists in `runner/libs/results.py`.
- `corpus/driver.py` previously duplicated this locally.
- This cleanup switched `corpus/driver.py` to `parse_runner_sample()`.

### Statistics

- Shared statistics already exist in `runner/libs/statistics.py` and are re-exported from `runner/libs/results.py`.
- `corpus/driver.py` previously duplicated `ns_summary`, `float_summary`, `summarize_phase_timings`, and `summarize_optional_ns`.
- This cleanup switched `corpus/driver.py` to the shared implementations.

### BPF program loading helpers

- This area is still only partially centralized.
- `corpus/driver.py` still contains corpus-local helpers such as:
  - `bpftool_json`
  - `attached_programs_for_pin_dir`
  - `pinned_programs_for_pin_dir`
  - `program_info_by_id`
  - `aggregate_program_infos`
  - loadall/recompile flows for compile-only and attach-trigger modes
- These are the main remaining shared-logic candidate if more of `corpus/` and `e2e/` converge on the same live-program loading path.

## 4. Makefile Dispatch Check

Verified with `make -n`:

- `vm-micro` calls `python3 .../micro/driver.py suite`
- `vm-corpus` calls `python3 .../corpus/driver.py packet`
- `vm-e2e` calls `python3 .../e2e/run.py <case>`

Additional cleanup:

- `vm-corpus` no longer goes through `micro/driver.py`
- `vm-corpus` and `vm-e2e` no longer depend on the micro BPF object stamp as a Make prerequisite

## 5. Verification

Commands run:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 -m py_compile micro/driver.py
python3 -m py_compile corpus/driver.py
python3 micro/driver.py --help
make smoke
make scanner-tests
```

Results:

- `python3 -m py_compile micro/driver.py`: success
- `python3 -m py_compile corpus/driver.py`: success
- `python3 micro/driver.py --help`: success, and help shows only `{suite,rigorous}`
- `make smoke`: success
- `make scanner-tests`: success

## Conclusion

The direct `micro` -> `corpus` dispatch path is gone, the grep-based cross-layer import audit is clean, shared result/statistics logic now lives under `runner/libs/`, and the root Makefile dispatches each layer through its own public entrypoint.
