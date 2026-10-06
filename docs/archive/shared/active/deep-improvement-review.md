# Deep Improvement Review

Date: 2026-03-13

## Summary

Comprehensive review of code quality, architecture, testing, CI, developer experience, reproducibility, and security across the bpf-benchmark project. 4 items fixed inline; 25+ improvement opportunities identified and prioritized.

---

## Fixes Applied (this review)

| Fix | File | Lines Changed |
|-----|------|---------------|
| Add missing return type annotation on `select_runtimes()` | `micro/_driver_impl_run_micro.py:268` | 1 |
| Handle `--help` / `-h` in `corpus` subcommand (was `unknown corpus mode: --help`) | `micro/driver.py:89-108` | 4 |
| Add `timeout-minutes: 60` to x86 CI (ARM64 had it, x86 did not) | `.github/workflows/x86-benchmark.yml` | 1 |

---

## Findings

### P0 -- Critical / Should Fix Before Next Paper Submission

#### 1. CI uses legacy entry point `run_micro.py` instead of `driver.py`

**Files**: `.github/workflows/x86-benchmark.yml`, `.github/workflows/arm64-benchmark.yml`

Both CI workflows call `python3 micro/run_micro.py` directly, while the Makefile and CLAUDE.md recommend `micro/driver.py suite`. `run_micro.py` does delegate to `driver.py` internally, so it works, but it bypasses the unified entry point and creates confusion. The CI also only tests `llvmbpf` and `kernel` runtimes, never `kernel-recompile` -- meaning the core BpfReJIT path has zero CI coverage.

**Effort**: ~15 min. Switch both workflows to `driver.py suite` and add a `kernel-recompile` smoke step (even if it can only run in a VM, a `--list` step validates the import chain).

#### 2. No Python tests for micro/ orchestrator

The project has 1 test file: `corpus/tests/test_policy_utils.py` (4 tests). The entire `micro/` layer -- `_driver_impl_run_micro.py`, `benchmark_catalog.py`, `input_generators.py`, `orchestrator/*.py` -- has zero unit tests. Given these modules compute statistics (median, p95, geomean) and generate deterministic binary inputs, correctness bugs here silently corrupt paper results.

**Effort**: ~2-4 hours. Add `micro/tests/test_input_generators.py` (verify deterministic outputs, expected_result matches), `test_benchmark_catalog.py` (YAML parsing roundtrip), `test_results.py` (ns_summary, derive_perf_metrics).

#### 3. No `requirements.txt` / `pyproject.toml`

No Python dependency management at all. The only dependency is `pyyaml`, but it's not pinned anywhere machine-readable. New contributors have to read CLAUDE.md to discover `pip install pyyaml`. If more dependencies are ever added, this becomes a real problem.

**Effort**: ~5 min. Create `requirements.txt` with `pyyaml>=6.0`.

#### 4. Hardcoded user path in Makefile and README

`Makefile:22` has `VENV ?= /home/yunwei37/workspace/.venv` and `README.md:30` has `source /home/yunwei37/workspace/.venv/bin/activate`. These break for any other developer.

**Effort**: ~5 min. Change Makefile to `VENV ?= $(HOME)/.venv` or auto-detect, update README to use a relative or `$HOME`-based path.

### P1 -- Important / Should Fix Soon

#### 5. No subprocess timeout in benchmark runner

`_driver_impl_run_micro.py:run_command()` calls `subprocess.run()` without any `timeout=` parameter. A hung `micro_exec` process (e.g., kernel deadlock during `bpf_prog_test_run`) will block the entire suite forever. The corpus drivers do have timeouts (`timeout_seconds` parameter).

**Effort**: ~10 min. Add `timeout=300` (5 minutes) default, configurable via CLI flag.

#### 6. Corpus driver implementation duplication (8 files, 8798 lines)

Eight `_driver_impl_run_*.py` files in `corpus/` with massive overlap:
- `run_command()` is defined in 5+ files with slight variations
- `relpath()`, `parse_args()`, `build_runner_command()` duplicated across many
- `size_ratio()`, `size_delta_pct()`, `speedup_ratio()` appear in at least 3 files

Some of this is already factored into `corpus/common.py` (364 lines), but the older driver impls predate it and still inline copies. This makes bug fixes error-prone.

**Effort**: ~4-6 hours. Audit each impl, migrate remaining duplicates to `corpus/common.py`, and verify behavior.

#### 7. No CPU governor / frequency pinning in VM benchmarks

The `Makefile` `vm-micro` target does not set `--cpu` or configure `scaling_governor=performance`. The `_driver_impl_run_micro.py` does log `cpu_governor` into results, but never enforces it. This undermines reproducibility.

The `--strict-env` flag exists but is never used in any Makefile target.

**Effort**: ~30 min. Add `cpufreq.default_governor=performance` to VM kernel cmdline and/or add `--strict-env` to `vm-micro`.

#### 8. No linting or type checking in CI or locally

No `ruff`, `flake8`, `mypy`, `pyright`, or any other linting tool configured. Only 1 function across all of `micro/` was missing a return type annotation (fixed in this review), but there's no enforcement to prevent regressions.

**Effort**: ~1 hour. Add `ruff check` config to `pyproject.toml`, add a `make lint` target.

#### 9. No C++ sanitizer build option

The `micro/runner/CMakeLists.txt` has no option for AddressSanitizer or UBSan. Memory bugs in the C++ runner could produce subtly wrong benchmark numbers.

**Effort**: ~15 min. Add a `cmake -DSANITIZE=ON` option that appends `-fsanitize=address,undefined`.

#### 10. `benchmark_catalog.py` executes `load_suite()` at module import time (line 202)

```python
DEFAULT_SUITE = load_suite()      # line 202
AVAILABLE_BENCHMARKS = DEFAULT_SUITE.benchmarks  # line 203
AVAILABLE_RUNTIMES = DEFAULT_SUITE.runtimes      # line 204
```

This means importing `benchmark_catalog` always reads and parses `config/micro_pure_jit.yaml`. If the YAML file is malformed or missing, `import benchmark_catalog` crashes. This is a side-effect-at-import-time anti-pattern.

**Effort**: ~20 min. Make these lazy (function-call or `functools.lru_cache`).

### P2 -- Nice to Have / Lower Priority

#### 11. No `CONTRIBUTING.md`

A new contributor has to read `CLAUDE.md` (which is an AI instruction file) to understand how to add benchmarks or run tests. A small `CONTRIBUTING.md` pointing to `make help`, the "Adding a new benchmark" section, and the test running instructions would help.

**Effort**: ~30 min.

#### 12. CI does not run `corpus/tests/test_policy_utils.py`

The one existing Python test is never run in CI. The `scanner-tests` target in Makefile runs C++ scanner tests, but there is no equivalent for Python.

**Effort**: ~15 min. Add `make python-tests` target and CI step.

#### 13. `input_generators.py` functions have no docstrings

1207 lines, 60+ generator functions, zero docstrings. Each generates a specific binary layout but the format is only documented implicitly in the corresponding `.bpf.c` file.

**Effort**: ~1-2 hours. Add brief docstrings describing the binary layout.

#### 14. Missing `__init__.py` for `micro/` and `corpus/` packages

`e2e/` has an `__init__.py` but `micro/` and `corpus/` do not. The code works around this with `sys.path` manipulation (`sys.path.insert(0, ...)`) and dual `try/except ImportError` blocks throughout. This is fragile and creates the duplicated import patterns visible in every file header.

**Effort**: ~2-3 hours (requires testing all import paths after adding `__init__.py`).

#### 15. Inconsistent `try/except ImportError` import pattern

Nearly every Python file has a pattern like:
```python
try:
    from benchmark_catalog import ...
except ImportError:
    from micro.benchmark_catalog import ...
```

This exists to support running scripts both as `python3 micro/run_micro.py` (CWD=micro/) and `python3 -m micro.run_micro` (CWD=root). Adding proper `__init__.py` and standardizing on one invocation would eliminate this.

**Effort**: Bundled with #14.

#### 16. `_driver_impl_run_micro.py` `format_ns()` is duplicated

The same `format_ns()` helper exists in `_driver_impl_run_micro.py`, `corpus/common.py`, and several corpus driver impls.

**Effort**: ~15 min. Move to a shared utility module.

#### 17. README references stale scripts

README line 56 references `corpus/run_macro_corpus.py` which may not exist (the actual entry is `driver.py corpus macro`). README line 69 references `corpus/directive_census.py`. These should be verified and updated.

**Effort**: ~15 min.

#### 18. `_lcg()` in `input_generators.py` could benefit from a comment

The LCG constants `6364136223846793005` and `1442695040888963407` are from Knuth's MMIX, but this is not documented. A one-line comment would help.

**Effort**: ~1 min.

#### 19. CI pushes directly to `main` with `--rebase`

Both CI workflows do `git push origin HEAD:main` with a retry loop. This is fragile and can cause race conditions if two workflows run simultaneously. Consider using a dedicated results branch or artifact storage.

**Effort**: ~1-2 hours.

#### 20. No `make test` top-level target

There is `make check` (build + scanner-tests + smoke) but no unified `make test` that runs all available tests (scanner C++ tests + Python unittest tests). `make test` is the conventional target name most developers try first.

**Effort**: ~10 min. Add `test` as an alias or superset of `check`.

#### 21. `_census_entry` has hardcoded script paths

`driver.py:116-118` hardcodes `corpus/directive_census.py` and `corpus/tmp/cross_domain_census.py`. If these scripts move, the error is a runtime `FileNotFoundError`.

**Effort**: ~5 min. Add existence check with a clear error message.

#### 22. VM benchmarks boot a fresh VM per e2e tool

`vm-e2e` boots 4 separate VMs (tracee, tetragon, bpftrace, xdp). Each VM boot takes ~30s. Running all tools in one VM session would save ~90s.

**Effort**: ~1-2 hours. Consolidate into a single `vng` invocation with a wrapper script.

#### 23. No `make clean-results` target

`make clean` removes all build artifacts AND all result JSON files. There is no way to clean just build artifacts while preserving results. This can be surprising.

**Effort**: ~10 min. Split into `make clean-build` and `make clean-results`.

#### 24. `--perf-scope` default is not visible in `--help`

The `--perf-scope` argument says `(default, raw totals)` in the help text but the argparse `default=` value `"full_repeat_raw"` is not shown. Minor UX issue.

**Effort**: ~1 min. Use `%(default)s` in help text.

#### 25. Stale untracked files in working tree

From `git status`: `fix_tmp_and_run.sh`, `run_bextr_fix_validation.sh`, `run_corpus_rerun.sh` at repo root, plus multiple `docs/tmp/*.sh` scripts. These are scratch files that should either be committed or `.gitignore`-d.

**Effort**: ~5 min.

---

## Priority Summary

| Priority | Count | Description |
|----------|-------|-------------|
| **P0** | 4 | CI entry point, no Python tests, no requirements.txt, hardcoded paths |
| **P1** | 6 | No subprocess timeout, corpus duplication, no CPU governor pinning, no linting, no sanitizers, import-time side effects |
| **P2** | 15 | CONTRIBUTING.md, CI test coverage, docstrings, __init__.py, duplicated helpers, stale README, etc. |

## Recommended Action Order

1. Create `requirements.txt` (5 min)
2. Fix hardcoded VENV path in Makefile (5 min)
3. Switch CI to `driver.py suite` (15 min)
4. Add subprocess timeout to `run_command()` (10 min)
5. Add `micro/tests/` with basic unit tests (2-4 hours)
6. Add `ruff` config and `make lint` (1 hour)
7. Deduplicate corpus driver impls (4-6 hours)
