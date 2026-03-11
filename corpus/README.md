# Real-World Corpus

`corpus/` owns the repository's real-world and external-program layers: repo harvesting, corpus builds, declarative suites, corpus measurements, and supporting analysis.

## Directory Layout

- `config/macro_corpus.yaml`: declarative macro/corpus suite consumed by `run_macro_corpus.py`
- `config/corpus_manifest.yaml`: generated 23-project corpus snapshot and measured-summary manifest
- `repos.yaml`: upstream repo harvest manifest used by `fetch_real_world_corpus.py`
- `repos/`: shallow sparse checkouts of upstream projects
- `build/`: compiled `.bpf.o` outputs under `corpus/build/<repo>/`
- `results/`: committed JSON/Markdown outputs from corpus and supporting analyses
- `inputs/`: reusable packet/context fixtures for macro and corpus runs
- `tmp/`: archived one-off scripts that are no longer part of the supported top-level workflow

`corpus/build/<repo>/` is also the object root consumed by the `e2e/` layer for cases such as `tracee`, `tetragon`, and `scx`.

## Supported Scripts

Core corpus pipeline and measurement entrypoints kept at the top level:

- `fetch_real_world_corpus.py`: fetches/refreshes upstream repos and regenerates `corpus/inventory.json`
- `build_expanded_corpus.py`: compiles harvested `.bpf.c` sources into `corpus/build/`
- `directive_census.py`: scanner-backed directive census over `micro/` objects plus the built corpus
- `run_macro_corpus.py`: declarative macro/corpus suite runner
- `run_corpus_perf.py`: packet-test-run stock vs recompile corpus measurements
- `run_corpus_tracing.py`: tracing attach/trigger corpus measurements
- `run_corpus_runnability.py`: runnable-program inventory and feasibility report
- `run_corpus_v5_framework.py`: 40-program framework-kernel corpus union runner
- `run_production_corpus_v5_framework.py`: production-skewed framework-kernel corpus runner
- `run_corpus_v5_vm_batch.py`: full packet corpus VM batch recompile harness

Long-lived support scripts also kept at the top level:

- `fetch_bcf_dataset.py`: refreshes the BCF object dataset under `corpus/bcf/`
- `analyze_bytecode.py`: extracts static bytecode features from the BCF dataset
- `run_real_world_code_size.py`: compiles curated external programs and compares native code size
- `run_real_world_exec_time.py`: measures exec-time deltas from `real_world_code_size.json`

Private implementation modules retained at the top level:

- `_driver_impl_run_*.py`: concrete implementations imported by `micro/driver.py` and the public `run_*.py` wrappers

Archived one-off scripts moved under `corpus/tmp/`:

- `tmp/compute_combined_40_summary.py`: legacy 40-benchmark summary combiner
- `tmp/cross_domain_census.py`: legacy cross-domain directive census
- `tmp/batch_run.py`: legacy BCF batch runner

## Config Notes

- `config/macro_corpus.yaml` currently defines 13 macro-corpus programs. All listed object paths and test inputs resolve in the repository.
- `config/corpus_manifest.yaml` is a generated snapshot. Its object paths resolve under `corpus/build/`, and its top-level summary matches the recorded measurement inputs referenced in the file.

## Common Commands

Fetch or refresh the upstream corpus working copies:

```bash
python3 corpus/fetch_real_world_corpus.py
```

Build the expanded corpus snapshot:

```bash
python3 corpus/build_expanded_corpus.py
```

Inspect directive-bearing sites across the built corpus:

```bash
python3 corpus/directive_census.py --help
```

Inspect the declarative macro suite:

```bash
python3 corpus/run_macro_corpus.py --list
```

Inspect the corpus perf harness:

```bash
python3 corpus/run_corpus_perf.py --help
```
