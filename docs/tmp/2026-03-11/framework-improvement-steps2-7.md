# Framework Improvement Steps 2-7

Date: 2026-03-11

## Completed Changes

### Step 2: corpus / rigorous drivers migrated onto orchestrator helpers

- Added `micro/orchestrator/corpus.py` for shared corpus-driver helpers:
  - kernel runner command building
  - dummy packet / context materialization
  - subprocess envelopes
  - invocation summaries
  - section-root normalization
  - directive-scan extraction
- Added `micro/orchestrator/rigorous.py` for shared rigorous / VM helpers:
  - pinning selection
  - governor / turbo snapshots and mutations
  - heavy-process detection
  - micro_exec command construction
  - bootstrap / Wilcoxon / BH statistics
- Extended `micro/orchestrator/commands.py` with `--skip-families` support.
- Extended `micro/orchestrator/results.py` with:
  - JSON file loading
  - JSON-lines parsing
  - directive-scan normalization helpers
  - per-benchmark sample aggregation helpers
  - geometric mean helper
- Extended `micro/orchestrator/inventory.py` with:
  - corpus object discovery preserving `skipped_non_bpf`
  - EM_BPF filtering
  - packet-test-run target loading from corpus inventory JSON
- Migrated:
  - `micro/run_corpus_perf.py` to `orchestrator.inventory` + `orchestrator.results` + shared corpus wrappers
  - `micro/run_rigorous.py` to `orchestrator.commands` for runner command building and `orchestrator.environment.validate_publication_environment()`
  - `micro/run_rigorous_framework_vm.py` to import shared helpers from `micro/orchestrator/rigorous.py` instead of `run_rigorous.py`
  - `micro/run_corpus_v5_vm_batch.py` to `orchestrator.inventory` + `orchestrator.results`

### Step 3: unified driver entry point

- Added `micro/driver.py` with subcommands:
  - `suite`
  - `rigorous`
  - `ablation`
  - `census`
  - `corpus`
- The driver delegates to the existing benchmark drivers through their new `main(argv)` entrypoints.
- Moved the concrete implementations behind private sibling modules (`micro/_driver_impl_run_*.py`).
- The public `micro/run_*.py` entry scripts are now compatibility wrappers:
  - they preserve import-time symbols for existing callers
  - they execute through `micro/driver.py` when invoked as scripts

### Step 4: unified manifest schema

- Added `micro/orchestrator/catalog.py`.
- The shared catalog now parses:
  - `config/micro_pure_jit.yaml`
  - `config/micro_runtime.yaml`
  - `config/macro_corpus.yaml`
- Validation and metadata added:
  - duplicate runtime-name detection
  - runtime-alias collision detection
  - duplicate target-name detection
  - schema-version field support
  - derived dimension summaries for:
    - target kind
    - backend
    - policy mode
    - transport
    - category / family / level / program type / test method
- `micro/run_macro_corpus.py` now loads manifests through `orchestrator.catalog` and uses `orchestrator.inventory` for program discovery.

### Step 5: reporting / aggregation pipeline

- `micro/orchestrator/reporting.py` is now the shared reporting layer for:
  - RQ summary markdown
  - corpus summary markdown
  - per-benchmark statistics
- `micro/summarize_rq.py` now uses the shared manifest + reporting layer.
- `micro/generate_figures.py` now derives defaults from the manifest instead of relying on the old fixed authoritative-file assumptions.

### Step 6: remaining script migrations

- `micro/run_pass_ablation.py` now uses:
  - `orchestrator.commands.build_runner_command()`
  - `orchestrator.results.parse_runner_sample()`
  - `orchestrator.environment.ensure_build_steps()`
- `micro/run_corpus_tracing.py` no longer imports helpers from `run_corpus_perf.py`; it now uses orchestrator-backed helpers directly.

### Step 7: cleanup

- `micro/generate_figures.py` no longer advertises a hardcoded 31-benchmark authoritative JSON as the default path.
- `micro/summarize_rq.py` default paths now come from manifest metadata.
- `micro/README.md` now documents:
  - the orchestrator split
  - the unified `micro/driver.py` entry point
  - manifest/reporting architecture

## Verification

Executed successfully:

- `python3 -m py_compile micro/driver.py micro/generate_figures.py micro/orchestrator/__init__.py micro/orchestrator/catalog.py micro/orchestrator/commands.py micro/orchestrator/corpus.py micro/orchestrator/environment.py micro/orchestrator/inventory.py micro/orchestrator/reporting.py micro/orchestrator/results.py micro/orchestrator/rigorous.py micro/_driver_impl_run_corpus_perf.py micro/_driver_impl_run_corpus_tracing.py micro/_driver_impl_run_corpus_v5_framework.py micro/_driver_impl_run_corpus_v5_vm_batch.py micro/_driver_impl_run_macro_corpus.py micro/_driver_impl_run_micro.py micro/_driver_impl_run_pass_ablation.py micro/_driver_impl_run_production_corpus_v5_framework.py micro/_driver_impl_run_rigorous.py micro/_driver_impl_run_rigorous_framework_vm.py micro/run_corpus_perf.py micro/run_corpus_tracing.py micro/run_corpus_v5_framework.py micro/run_corpus_v5_vm_batch.py micro/run_macro_corpus.py micro/run_micro.py micro/run_pass_ablation.py micro/run_production_corpus_v5_framework.py micro/run_rigorous.py micro/run_rigorous_framework_vm.py micro/summarize_rq.py`
- `python3 -c 'from micro.orchestrator import commands, results, environment, inventory; print("OK")'`
- `python3 micro/run_micro.py --list`
- `python3 micro/run_corpus_perf.py --help`
- `python3 micro/run_corpus_tracing.py --help`
- `python3 micro/run_rigorous.py --help`
- `python3 micro/run_rigorous_framework_vm.py --help`
- `python3 micro/run_corpus_v5_vm_batch.py --help`
- `python3 micro/run_macro_corpus.py --help`
- `python3 micro/summarize_rq.py --help`
- `python3 micro/generate_figures.py --help`
- `python3 micro/driver.py --help`
- `python3 micro/driver.py suite -- --list`
- `python3 micro/driver.py suite --suite config/macro_corpus.yaml -- --list`
- `python3 micro/driver.py ablation -- --help`
- `python3 micro/driver.py corpus macro -- --help`
- `python3 -c 'import sys; sys.path.insert(0, "micro"); import run_corpus_runnability, run_e2e_tetragon; print("OK")'`

Observed results:

- orchestrator import smoke printed `OK`
- `python3 micro/run_micro.py --list` completed successfully after the migrations
- the new `micro/driver.py` dispatches both micro and macro suite entry paths
- the wrapper split preserved downstream imports that still depend on `run_corpus_perf.py` / `run_corpus_tracing.py`
