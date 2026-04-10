# E2E Results

Top-level `e2e/results/` stores one timestamped directory per run.

- Each run lives under `e2e/results/<run_type>_<timestamp>/`.
- `metadata.json` is the canonical run summary.
- `details/` holds `result.json`, `result.md`, optional `report.md`, and any per-case payloads.
- Older runs of the same `run_type` are left intact.

There is no top-level authoritative alias, latest pointer, or duplicated JSON copy.
If a document needs to cite an E2E run, cite the concrete timestamped directory.

The retired XDP dataplane E2E case was removed on 2026-03-18, so its checked-in artifacts are no longer kept under `e2e/results/`.
