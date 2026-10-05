# Repo Restructure Report

Date: 2026-03-11
Task: `#71` three-layer repository separation

## Summary

The active benchmark code is now split into:

- `micro/`: isolated micro-benchmarks and shared `micro/orchestrator/`
- `corpus/`: real-world corpus config, collection, measurement, and analysis
- `e2e/`: end-to-end probe/deployment harnesses and placeholders
- `legacy/`: inactive historical code

## Moves Completed

- Moved corpus measurement entrypoints and their `_driver_impl_*` modules from `micro/` to `corpus/`
- Moved Tracee / Tetragon / bpftrace e2e harnesses from `micro/` to `e2e/`
- Moved `config/corpus_manifest.yaml` and `config/macro_corpus.yaml` to `corpus/config/`
- Moved `user_bpf_benchmark/` to `legacy/user_bpf_benchmark/`

## Import / Path Fixes

- Updated `micro/driver.py` so the `corpus` subcommand dispatches to `corpus/` modules and the `census` subcommand runs `corpus/directive_census.py` and `corpus/cross_domain_census.py`
- Added repo-root / layer bootstrap `sys.path` setup to moved corpus and e2e scripts so direct script execution still works
- Updated manifest loader defaults for the moved macro config:
  - `micro/orchestrator/catalog.py`
  - `micro/benchmark_catalog.py`
  - `corpus/build_expanded_corpus.py`
  - `corpus/fetch_real_world_corpus.py`
- Updated corpus defaults that still pointed at the old locations:
  - `corpus/_driver_impl_run_macro_corpus.py`
  - `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
  - `corpus/config/macro_corpus.yaml`
  - `corpus/compute_combined_40_summary.py`
- Updated stale self-references from `micro/directive_census.py` to `corpus/directive_census.py`
- Updated `micro/run_corpus_tracing.sh` to invoke `corpus/run_corpus_tracing.py`

## Documentation

- Rewrote the top-level `README.md` around the three-layer architecture
- Rewrote `micro/README.md` to describe only the isolated micro layer
- Rewrote `corpus/README.md` to describe corpus collection, configs, measurement, and analysis
- Added `e2e/README.md`
- Added `legacy/README.md`
- Added tracked placeholders for:
  - `e2e/common/`
  - `e2e/cases/`
  - `e2e/results/`

## Verification

Passed:

- `python3 -m py_compile micro/run_micro.py`
- `python3 -m py_compile micro/driver.py`
- `python3 micro/run_micro.py --list`
- `python3 -c "from micro.orchestrator import commands, results, environment, inventory; print('OK')"`
- `python3 -m py_compile corpus/run_corpus_perf.py`
- `python3 -m py_compile corpus/directive_census.py`
- `python3 -m py_compile e2e/run_e2e_tracee.py`
- `python3 corpus/directive_census.py --help`
- `python3 corpus/run_corpus_perf.py --help`
- `python3 corpus/run_corpus_runnability.py --help`
- `python3 e2e/run_e2e_tracee.py --help`
- `python3 e2e/run_e2e_tetragon.py --help`
- `python3 e2e/run_e2e_bpftrace.py --help`
- `make -C micro micro_exec programs`
- `python3 micro/run_micro.py --bench simple --runtime llvmbpf --iterations 1 --warmups 0 --repeat 1 --output /tmp/restructure_smoke.json`

Smoke result:

- `/tmp/restructure_smoke.json` was produced successfully
- JSON parsing validation passed (`JSON_OK`)

## Notes

- `third-party/` exists in this checkout only as nested external repos and is not tracked by the outer Git repository, so `git mv` could not record that move. It was relocated with `mv` to `legacy/third-party/` and is documented here explicitly.
