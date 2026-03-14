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

- `bpftrace.latest.json` -> `bpftrace_authoritative_20260312.json`
- `scx.latest.json` -> `scx_authoritative_20260311.json`
- `tracee.latest.json` -> `tracee_authoritative_20260313_postfix.json`
- `xdp_forwarding.latest.json` -> `xdp_forwarding_authoritative_20260312.json`

Note: `tracee_authoritative_20260313.json` contains the primary exec_storm/file_io/network run
(+6.3%/+7.0%/+1.4% geomean 1.049x). The `_postfix` variant used for `tracee.latest.json` is a
supplementary measurement from the same day with slightly different workload timing.
