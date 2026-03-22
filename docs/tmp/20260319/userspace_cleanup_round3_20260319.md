# Userspace Cleanup Round 3 (2026-03-19)

## Scope

Follow-up on `docs/tmp/userspace_post_cleanup_review_20260319.md`, limited to userspace code and docs. No kernel files were modified.

## Review Items: Final Status

- `P0` `corpus/run_corpus_runnability.py`
  - The broken deleted-wrapper import from the review no longer exists in the current checkout.
  - `python3 corpus/run_corpus_runnability.py --help` works, so the script was kept rather than deleted.

- `P1` `corpus/_driver_impl_run_production_corpus_v5_framework.py`
  - `extract_error` was already imported in the current tree, so the original `NameError` report was stale.
  - A real regression remained in the same failure path: `discover_programs()` still called `directive_census.analyze_object()` with the old signature and crashed before returning fallback census data.
  - Fixed by threading the scanner path into `discover_programs()` and the `analyze_object(...)` call.

- `P1` stale docs in `README.md`, `CLAUDE.md`, `micro/README.md`, `corpus/README.md`
  - Rechecked for references to deleted wrappers/dirs such as `run_micro.py`, `config/ablation/`, `micro/programs/archive/runtime/`, `run_corpus_perf.py`, `run_corpus_tracing.py`, `run_corpus_v5_vm_batch.py`, etc.
  - No remaining matches were present in these four files in the current checkout, so no doc edit was required here.

- `P2` `micro/_driver_impl_run_pass_ablation.py`
  - The file is already absent in the current checkout, so there was no remaining orphaned backend to delete.

- `P2` `corpus/_driver_impl_run_corpus_v5_vm_batch.py` duplicate `text_invocation_summary`
  - The current file no longer imports a shared `text_invocation_summary`, so the reported duplicate redefinition is already gone.

- `P2` `micro/orchestrator/rigorous.py`
  - The unused `select_benchmarks` import is already gone in the current checkout.

## Actual Fixes Applied

- Fixed the production corpus failure-path regression in `corpus/_driver_impl_run_production_corpus_v5_framework.py`.
- Cleaned remaining active userspace Python dead imports / unused locals / no-op f-strings found via `pyflakes`:
  - `micro/_driver_impl_run_micro.py`
  - `micro/compare_results.py`
  - `micro/generate_figures.py`
  - `corpus/common.py`
  - `corpus/run_real_world_code_size.py`
  - `corpus/analyze_bytecode.py`
  - `corpus/_driver_impl_run_tracing_corpus_vm.py`
  - `corpus/_driver_impl_run_corpus_v5_framework.py`
  - `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
  - `corpus/_driver_impl_run_corpus_tracing.py`
  - `corpus/_driver_impl_run_corpus_tracing_exec.py`
  - `e2e/cases/scx/case.py`
  - `e2e/cases/tetragon/case.py`
  - `e2e/cases/bpftrace/case.py`
  - `e2e/cases/tracee/case.py`
  - `e2e/run_e2e_tracee.py`

## Extra Targeted Checks

- `python3 corpus/run_corpus_runnability.py --help`
  - Passes.

- Production corpus failure-path repro:
  - Reproduced against a real ELF object with `/bin/false` as the runner.
  - After the fix, `discover_programs()` returns a normal failure record plus fallback section totals instead of crashing.

- `python3 -m pyflakes` over active `micro/`, `corpus/`, and `e2e/` Python files
  - Clean (`EXIT=0`) after the fixes.

## Requested Verification

1. `source /home/yunwei37/workspace/.venv/bin/activate`
   - Used for the Python verification commands below.

2. `rg --files -g '*.py' -0 | xargs -0 -n 200 python3 -m py_compile`
   - Pass.
   - Same pre-existing vendor `SyntaxWarning` messages remain under `vendor/linux*/*/convert_csv_to_c.py`, but the command exits successfully and userspace Python compiles cleanly.

3. `python3 micro/driver.py suite --help`
   - Pass.

4. `python3 micro/driver.py corpus v5-vm-batch --help`
   - Pass.

5. `python3 e2e/run.py --help`
   - Pass.

6. `make -n vm-micro`
   - Pass.
   - Dry-run output uses `python3 .../micro/driver.py suite`.
   - No deleted wrapper names were referenced.

7. `make -n vm-corpus`
   - Pass.
   - Dry-run output uses `python3 .../micro/driver.py corpus v5-vm-batch`.
   - No deleted wrapper names were referenced.

## Notes

- No kernel code was modified.
- No commit was created.
