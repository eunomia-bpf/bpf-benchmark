# Real-World Corpus

This directory tracks real-world eBPF program-source candidates used by the characterization pipeline.

- `repos.yaml` describes upstream repos, sparse checkout paths, harvest globs, and optional excludes.
- `fetch_real_world_corpus.py` performs shallow partial clones and emits `inventory.json`.
- `run_real_world_code_size.py` compiles supported real-world `.bpf.c` sources and compares per-program native code size across `llvmbpf` and `kernel`.
- `repos/` is ignored and stores local working copies.
- `../config/macro_corpus.yaml` is the macro-layer config entrypoint for corpus fetching.

Use:

```bash
python3 corpus/fetch_real_world_corpus.py
```

Run the current first-wave code-size validation:

```bash
python3 corpus/run_real_world_code_size.py --repo libbpf-bootstrap
```

Outputs:

- `corpus/results/real_world_code_size.json`
- `corpus/results/real_world_code_size.md`

The current manifest covers `xdp-examples`, `bcc`, `katran`, `tetragon`, `cilium`, and `libbpf-bootstrap`.
