# Real-World Corpus

`corpus/` owns the repository's real-world benchmark suites, corpus builds, declarative suites, corpus measurements, and supporting analysis. Third-party repo registration and fetch/build orchestration live under `runner/`.

## Directory Layout

- `driver.py`: thin corpus entrypoint that forwards to `orchestrator.py`
- `orchestrator.py`: shared corpus benchmark orchestrator for native app loader instances
- `corpus/config/macro_corpus.yaml`: declarative macro/corpus suite consumed by `python3 corpus/driver.py --suite corpus/config/macro_corpus.yaml`
- `build/`: compiled `.bpf.o` outputs under `corpus/build/<repo>/`
- `results/`: committed JSON/Markdown outputs from corpus and supporting analyses
- `inputs/`: reusable packet/context fixtures for macro and corpus runs

Shared runner-owned inputs:

- `runner/repos.yaml`: upstream repo harvest manifest
- `runner/repos/`: shallow sparse checkouts of upstream projects

`corpus/build/<repo>/` is also the object root consumed by the `e2e/` layer for cases such as `tracee`, `tetragon`, and `scx`.

## Canonical Entry Points

Use `python3 corpus/driver.py --suite corpus/config/macro_corpus.yaml` for the declarative macro suite.

Top-level support scripts retained in `corpus/`:

- `driver.py`: corpus measurement entrypoint
- `orchestrator.py`: native-loader corpus orchestration

Runner-owned repo control-plane scripts:

- `runner/scripts/fetch_corpus_repos.py`: fetches/refreshes upstream repos under `runner/repos/`
- `runner/scripts/build_corpus_objects.py`: compiles source-backed repos and emits the strict object availability report used by `vm-corpus`

There is no checked-in scratch directory under `corpus/` anymore. Keep any local scratch work untracked, or promote reusable scripts back to the top level.

## Config Notes

- `corpus/config/macro_corpus.yaml` is the only active corpus definition consumed by the VM corpus runner.
- `corpus/results/expanded_corpus_build.latest.json` is the strict availability report that binds `vm-corpus` to the objects prepared by `make corpus-build`.

## Common Commands

Fetch or refresh the upstream corpus working copies:

```bash
make corpus-fetch
```

Build the expanded corpus snapshot:

```bash
make corpus-build
```

Inspect the declarative macro suite:

```bash
python3 corpus/driver.py --suite corpus/config/macro_corpus.yaml --list
```

Inspect the corpus orchestrator:

```bash
python3 corpus/driver.py --help
```
