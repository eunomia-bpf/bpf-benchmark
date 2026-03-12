# E2E Results

Canonical end-to-end JSON payloads use these names:

- `<case>_authoritative_YYYYMMDD.json`: authoritative non-smoke run for an e2e case.
- `<case>_smoke_YYYYMMDD.json`: smoke or spotcheck run.
- `<case>.latest.json`: symlink to the newest authoritative JSON for that case.

Conventions:

- `YYYYMMDD` is the UTC calendar date from the payload's `generated_at` timestamp.
- Cases without an authoritative checked-in run do not get a `*.latest.json` alias yet.
- Markdown summaries are supporting artifacts and keep descriptive names.

Current authoritative aliases:

- `bpftrace.latest.json` -> `bpftrace_authoritative_20260311.json`
- `scx.latest.json` -> `scx_authoritative_20260311.json`

Current smoke-only checked-in cases:

- `tracee_smoke_20260311.json`
- `tetragon_smoke_20260311.json`
