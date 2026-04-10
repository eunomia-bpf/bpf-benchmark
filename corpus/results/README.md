# Corpus Results

Top-level `corpus/results/` stores one timestamped directory per run.

- Each run lives under `corpus/results/<run_type>_<timestamp>/`.
- `metadata.json` is the canonical run summary.
- `details/` holds `result.json`, `result.md`, and any large per-target payloads.
- Older runs of the same `run_type` are left intact.

There is no top-level authoritative alias, latest pointer, or duplicated JSON copy.
If a document needs to cite a corpus run, cite the concrete timestamped directory.
