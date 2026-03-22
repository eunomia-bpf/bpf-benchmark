# Corpus llvmbpf Removal Report

Date: 2026-03-19

## Scope

Removed `llvmbpf` from the live corpus benchmark pipeline. The corpus-facing standalone scripts now measure `kernel` vs `kernel-recompile`, and the ARM64 corpus CI path no longer invokes `llvmbpf`.

## Removed or Updated

- `corpus/run_real_world_code_size.py`
  - Removed the `llvmbpf` runtime option and `run-llvmbpf` path.
  - Added `kernel-recompile` as the paired comparison lane for compile-only code-size inspection.
  - Updated summaries and Markdown reporting from `llvmbpf/kernel` to `kernel-recompile/kernel`.

- `corpus/run_real_world_exec_time.py`
  - Removed the `llvmbpf` runtime path entirely.
  - Reworked runtime selection to use `kernel` and `kernel-recompile` only.
  - Updated summaries and Markdown reporting from `llvmbpf/kernel` to `kernel-recompile/kernel`.
  - Kept single-runtime execution support so ARM64 corpus CI can stay kernel-only without reintroducing `llvmbpf`.

- `.github/workflows/arm64-benchmark.yml`
  - Corpus code-size step changed from `llvmbpf + kernel` to `kernel` only.
  - Corpus exec-time step changed to `kernel` only.
  - Step summary logic no longer expects corpus-side `llvmbpf` status fields.

- `corpus/README.md`
  - Updated the real-world script descriptions to state `kernel` vs `kernel-recompile`.

- `docs/micro-bench-status.md`
  - Added a note that the two corpus external-validation script paths have been repurposed to `kernel` vs `kernel-recompile`.
  - Kept the old `llvmbpf` results as historical context instead of rewriting that research section.

## Checked, No Change Needed

- `corpus/config/macro_corpus.yaml`
  - Already defines only `kernel` and `kernel_recompile_v5`.

- `corpus/_driver_impl_run_macro_corpus.py`
  - Already uses `run-kernel` plus `--recompile-v5 --recompile-all`; no `llvmbpf` path.

- `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
  - Already kernel-only and policy/recompile based; no `llvmbpf` runtime path.

- `Makefile`
  - `vm-corpus` already dispatches `micro/driver.py corpus v5-vm-batch` without any corpus-side `llvmbpf` runtime list.
  - Existing `llvmbpf` references are micro-only (`smoke`, `vm-micro`) and were intentionally left alone.

- `scripts/`
  - No corpus-specific `llvmbpf` references found.

- `.github/workflows/x86-benchmark.yml`
  - Left unchanged because it is micro characterization CI, not corpus CI.

## Verification

- Python syntax:
  - `source /home/yunwei37/workspace/.venv/bin/activate && python -m py_compile corpus/run_real_world_code_size.py corpus/run_real_world_exec_time.py`

- Workflow YAML:
  - Parsed `.github/workflows/arm64-benchmark.yml` with `yaml.safe_load()`.

- `vm-corpus` target:
  - `make -n vm-corpus` still expands to `python3 micro/driver.py corpus v5-vm-batch ... --use-policy ...`
  - Dry-run output contains no corpus-side `llvmbpf` runtime invocation.

- Live smoke runs:
  - `python corpus/run_real_world_code_size.py --repo libbpf-bootstrap --runtime kernel --max-sources 1 ...`
  - `python corpus/run_real_world_code_size.py --repo libbpf-bootstrap --runtime kernel-recompile --max-sources 1 ...`
  - `python corpus/run_real_world_code_size.py --repo libbpf-bootstrap --runtime kernel --runtime kernel-recompile --max-sources 1 ...`
  - `python corpus/run_real_world_exec_time.py --input corpus/results/dev/real_world_code_size_kernel_smoke.json --runtime kernel --max-programs 1 --iterations 1 --repeat 1 ...`
  - `python corpus/run_real_world_exec_time.py --input corpus/results/dev/real_world_code_size_pair_smoke.json --runtime kernel --runtime kernel-recompile --max-programs 1 --iterations 1 --repeat 1 ...`

## Result

The live corpus pipeline no longer depends on `llvmbpf`. Remaining `llvmbpf` references in the repository are limited to micro-characterization paths and historical documentation.
