# Micro Results

Top-level `micro/results/` stores one timestamped directory per run.

- Each run lives under `micro/results/<run_type>_<timestamp>/`.
- `metadata.json` is the canonical run summary.
- `details/` holds `result.json`, progress payloads, and any large per-sample logs.
- Older runs of the same `run_type` are left intact.

There is no top-level authoritative alias, latest pointer, or duplicated JSON copy.
If a document needs to cite a micro run, cite the concrete timestamped directory.
