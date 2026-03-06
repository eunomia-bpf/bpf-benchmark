# Real-World Corpus

This directory tracks real-world eBPF program-source candidates used by the characterization pipeline.

- `repos.yaml` describes upstream repos, sparse checkout paths, harvest globs, and optional excludes.
- `fetch_real_world_corpus.py` performs shallow partial clones and emits `inventory.json`.
- `repos/` is ignored and stores local working copies.
- `../config/macro_corpus.yaml` is the macro-layer config entrypoint for corpus fetching.

Use:

```bash
python3 corpus/fetch_real_world_corpus.py
```

The current manifest covers `xdp-examples`, `bcc`, `katran`, `tetragon`, `cilium`, and `libbpf-bootstrap`.
