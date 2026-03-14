# P0 Bugfix Report

## Scope

- Reviewed `docs/tmp/benchmark-framework-analysis.md`.
- Applied Python-only fixes in:
  - `micro/generate_figures.py`
  - `micro/run_macro_corpus.py`
  - `micro/summarize_rq.py`

## P0-1: `generate_figures.py` missing `call-overhead` category mapping

### Fix

- Replaced the split category tables with a single `CATEGORY_MAP` registry.
- Added the missing `call-overhead` entry.
- Derived `CATEGORY_ORDER`, `CATEGORY_LABELS`, and `CATEGORY_COLORS` from that registry so the mapping cannot silently drift.
- Added an explicit unknown-category guard so future category drift fails loudly instead of silently dropping benchmarks.

### Result

- `bpf_call_chain` and `local_call_fanout` are now recognized as `call-overhead` benchmarks.
- Category breakdown and scatter plots no longer omit that category.

### Minimal validation

- `python3 micro/generate_figures.py --figures-dir docs/tmp/p0-figures-smoke --bootstrap-iterations 32`
- Static check on `micro/results/pure_jit_with_cmov.json` confirmed:
  - categories include `call-overhead`
  - mapped benchmarks include `bpf_call_chain` and `local_call_fanout`

## P0-2: macro `repeat` did not take effect

### Fix

- Threaded `repeat` through `build_runner_command()`.
- Removed the hardcoded `--repeat 1` in the `micro_exec run-kernel` path.
- Passed `repeat` through `execute_sample()` into `run_micro_exec_sample()`.
- Added `effective_repeat` to samples and run records so the JSON records what actually took effect.

### Result

- `bpf_prog_test_run` executions now honor CLI/YAML `repeat`.
- Output JSON exposes both configured `repeat` and computed `effective_repeat`.

### Minimal validation

- Static check of `build_runner_command(... repeat=7, ...)` returned a command containing `--repeat 7`.

## P0-3: broken default paths

### Fix

- `micro/summarize_rq.py`
  - Switched defaults to repo-relative `Path(__file__)` resolution rooted at the project tree.
  - Replaced the broken `micro/results/latest.json` default with first-existing fallback:
    - `micro/results/pure_jit.latest.json`
    - `micro/results/runtime.latest.json`
    - `micro/results/latest.json`
- `micro/generate_figures.py`
  - Kept repo-relative path resolution via `Path(__file__)`.
  - Replaced the broken standalone causal default with first-existing fallback:
    - `micro/results/causal_isolation_authoritative.json`
    - `micro/results/pure_jit_with_cmov.json`
    - `micro/results/pure_jit.latest.json`

### Result

- `summarize_rq.py` now defaults to an existing results JSON in this repository.
- `generate_figures.py` now defaults to an existing causal-capable results JSON in this repository.

### Minimal validation

- `python3 micro/summarize_rq.py --output docs/tmp/p0-summary-smoke.md`
- `python3 micro/generate_figures.py --figures-dir docs/tmp/p0-figures-smoke --bootstrap-iterations 32`
- Static checks confirmed:
  - `summarize_rq.py` default results path resolves to `micro/results/pure_jit.latest.json`
  - `generate_figures.py` default causal path resolves to `micro/results/pure_jit_with_cmov.json`

## P0-4: unnecessary root/scanner dependencies

### Fix

- Moved `--list` handling ahead of root re-exec, runner build, and scanner checks.
- Deferred root re-exec until the script is actually going to execute benchmarks.
- Made scanner existence checks conditional on selected runtimes containing `kernel-recompile-v5`.
- Made `LibbpfHandle()` initialization conditional on both:
  - selected runtimes containing `kernel-recompile-v5`
  - selected benchmarks actually using recompile paths that need Python-side libbpf (`attach_trigger` / `bpftool_loadall`)
- Added explicit runtime guards in the recompile-specific code paths so accidental `None` libbpf usage fails clearly.

### Result

- `--list` no longer requires root or passwordless sudo.
- Baseline-only runs are no longer blocked by scanner/libbpf setup that they do not use.

### Minimal validation

- `python3 micro/run_macro_corpus.py --list --suite config/macro_corpus.yaml`
- Static checks confirmed:
  - `runtimes_require_recompile_support([kernel]) == False`
  - `runtimes_require_recompile_support([kernel_recompile_v5]) == True`

## P0-5: stats inconsistency (`median` vs `mean`)

### Fix

- `micro/generate_figures.py`
  - Switched `exec_ratio` from sample-mean ratio to median-based ratio.
  - Switched `compile_ratio` from sample-mean ratio to median-based ratio.
  - Used recorded run summaries when available and sample medians as fallback.
  - Switched causal-isolation figure center from mean to median.
  - Switched causal-isolation bootstrap interval from mean CI to median CI.
  - Updated axis/help text accordingly.

### Result

- Figure generation now matches the framework’s median-first aggregation used by `run_micro.py` and `summarize_rq.py`.
- The causal-isolation figure no longer mixes a different central-tendency definition into the plotting path.

### Minimal validation

- `python3 micro/generate_figures.py --figures-dir docs/tmp/p0-figures-smoke --bootstrap-iterations 32`

## Verification artifacts

- `docs/tmp/p0-figures-smoke/`
- `docs/tmp/p0-summary-smoke.md`

## Notes

- No non-Python production code was modified.
- The repository currently does not contain a standalone `micro/results/causal_isolation_authoritative.json`; the new default therefore falls back to the first existing causal-capable results file instead of pointing at a nonexistent path.
