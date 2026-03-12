# Micro Results

Canonical micro result payloads use these JSON names:

- `pure_jit_authoritative_YYYYMMDD.json`: full-suite authoritative run.
- `pure_jit_smoke_YYYYMMDD.json`: subset or spotcheck run.
- `pure_jit.latest.json`: symlink to the newest authoritative JSON.

Conventions:

- `YYYYMMDD` is the UTC calendar date from the payload's `generated_at` timestamp.
- `*.latest.json` is only for authoritative results.
- Markdown reports, figures, and the `rigorous/` spotcheck archive are supporting artifacts and keep descriptive names.

Current canonical file:

- `pure_jit.latest.json` -> `pure_jit_authoritative_20260312.json`
