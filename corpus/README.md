# Real-World Corpus

`corpus/` owns the real-world program layer: collection, declarative configs, measurement, and analysis.

## What Lives Here

- `config/macro_corpus.yaml`: declarative corpus measurement suite
- `config/corpus_manifest.yaml`: 23-project corpus snapshot / metadata manifest
- `repos.yaml`: upstream repo harvest manifest
- `fetch_real_world_corpus.py`: shallow sparse checkout fetcher + inventory generator
- `build_expanded_corpus.py`: corpus-wide `.bpf.c` build sweep into `corpus/build/`
- `run_corpus_perf.py`: stock-vs-recompile packet-test-run corpus measurements
- `run_corpus_tracing.py`: tracing attach/trigger corpus measurements
- `run_corpus_runnability.py`: runnable-program inventory + paired measurement feasibility
- `run_corpus_v5_framework.py`: 40-program framework-kernel corpus union
- `run_production_corpus_v5_framework.py`: production-skewed framework-kernel corpus run
- `run_corpus_v5_vm_batch.py`: VM batch recompile harness
- `run_macro_corpus.py`: declarative macro/corpus suite runner
- `directive_census.py` / `cross_domain_census.py`: corpus-wide directive analysis

The active corpus currently spans 23 source projects and stores fetched repos under `corpus/repos/`, built objects under `corpus/build/`, and measurement outputs under `corpus/results/` plus `docs/tmp/`.

`corpus/build/<repo>/` is also the object root consumed by the `e2e/` layer for cases such as `tracee`, `tetragon`, and `scx`.

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
python3 corpus/directive_census.py
```

Run the packet-test-run corpus perf harness:

```bash
python3 corpus/run_corpus_perf.py --help
```

List the declarative macro suite:

```bash
python3 corpus/run_macro_corpus.py --list
```
