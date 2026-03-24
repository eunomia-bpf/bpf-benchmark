# Real-World Corpus

`corpus/` owns the repository's real-world benchmark suites, corpus builds, declarative suites, corpus measurements, and supporting analysis. Third-party repo registration and fetch/build orchestration now live under `runner/`.

## Directory Layout

- `driver.py`: declarative macro corpus entrypoint plus corpus mode dispatch
- `modes.py`: consolidated packet, tracing, perf, and code-size corpus modes
- `corpus/config/macro_corpus.yaml`: declarative macro/corpus suite consumed by `python3 corpus/driver.py --suite corpus/config/macro_corpus.yaml`
- `corpus/config/corpus_manifest.yaml`: generated 23-project corpus snapshot and measured-summary manifest
- `build/`: compiled `.bpf.o` outputs under `corpus/build/<repo>/`
- `results/`: committed JSON/Markdown outputs from corpus and supporting analyses
- `inputs/`: reusable packet/context fixtures for macro and corpus runs

Shared runner-owned inputs:

- `runner/repos.yaml`: upstream repo harvest manifest
- `runner/repos/`: shallow sparse checkouts of upstream projects
- `runner/inventory.json`: harvested repo inventory used by corpus object builds

`corpus/build/<repo>/` is also the object root consumed by the `e2e/` layer for cases such as `tracee`, `tetragon`, and `scx`.

## Canonical Entry Points

Use `corpus/driver.py <mode> ...` for the active corpus measurement modes:

- `python3 corpus/driver.py packet`
- `python3 corpus/driver.py perf`
- `python3 corpus/driver.py tracing`
- `python3 corpus/driver.py code-size`

Use `python3 corpus/driver.py --suite corpus/config/macro_corpus.yaml` for the declarative macro suite.

Top-level support scripts retained in `corpus/`:

- `driver.py`: corpus measurement entrypoint
- `modes.py`: corpus mode implementations
- `directive_census.py`: daemon-backed directive census over `micro/` objects plus the built corpus

Runner-owned repo control-plane scripts:

- `runner/scripts/fetch_corpus_repos.py`: fetches/refreshes upstream repos and regenerates `runner/inventory.json`
- `runner/scripts/build_corpus_objects.py`: compiles harvested `.bpf.c` sources into `corpus/build/`

There is no checked-in scratch directory under `corpus/` anymore. Keep any local scratch work untracked, or promote reusable scripts back to the top level.

## Config Notes

- `corpus/config/macro_corpus.yaml` currently defines 13 macro-corpus programs. All listed object paths and test inputs resolve in the repository.
- `corpus/config/corpus_manifest.yaml` is a generated snapshot. Its object paths resolve under `corpus/build/`, and its top-level summary matches the recorded measurement inputs referenced in the file.

## Common Commands

Fetch or refresh the upstream corpus working copies:

```bash
make corpus-fetch
```

Build the expanded corpus snapshot:

```bash
make corpus-build
```

Inspect directive-bearing sites across the built corpus:

```bash
python3 corpus/directive_census.py --help
```

Inspect the declarative macro suite:

```bash
python3 corpus/driver.py --suite corpus/config/macro_corpus.yaml --list
```

Inspect the corpus perf harness:

```bash
python3 corpus/driver.py perf --help
```
