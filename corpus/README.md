# Real-World Corpus

This directory tracks real-world eBPF program-source candidates used by the characterization pipeline.

- `repos.yaml` describes upstream repos, sparse checkout paths, harvest globs, and optional excludes.
- `fetch_real_world_corpus.py` performs shallow partial clones and emits `inventory.json`.
- `build_expanded_corpus.py` compiles harvested upstream sources into `corpus/build/<repo>/...` and logs failures without stopping the sweep.
- `run_real_world_code_size.py` compiles supported real-world `.bpf.c` sources and compares per-program native code size across `llvmbpf` and `kernel`.
- `repos/` is ignored and stores local working copies.
- `../config/macro_corpus.yaml` is the macro-layer config entrypoint for corpus fetching.

Use:

```bash
python3 corpus/fetch_real_world_corpus.py
```

Build the broad corpus snapshot:

```bash
python3 corpus/build_expanded_corpus.py
```

Run the current first-wave code-size validation:

```bash
python3 corpus/run_real_world_code_size.py --repo libbpf-bootstrap
```

Outputs:

- `corpus/results/real_world_code_size.json`
- `corpus/results/real_world_code_size.md`
- `corpus/results/expanded_corpus_build.json`
- `corpus/results/expanded_corpus_build.md`

The current manifest covers `xdp-examples`, `xdp-tools`, `xdp-tutorial`, `bcc`, `katran`, `tetragon`, `cilium`, `libbpf-bootstrap`, and `linux-selftests`.
