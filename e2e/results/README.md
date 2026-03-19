# E2E Results

Top-level `e2e/results/` keeps only checked-in authoritative JSON plus this README.

- `archive/` stores superseded runs, analysis markdown, and historical artifacts.
- `dev/` is the default output location for `make vm-e2e`.
- `YYYYMMDD` in authoritative filenames comes from the payload `generated_at` date in UTC.

Current top-level authoritative JSON:

- `tracee_authoritative_20260313_postfix.json`
- `bpftrace_authoritative_20260312.json`
- `scx_authoritative_20260311.json`

`tracee_authoritative_20260313_postfix.json` is the kept replacement for the older
same-day `tracee_authoritative_20260313.json`, which now lives in `archive/`.

The retired XDP dataplane E2E case was removed on 2026-03-18, so its checked-in artifacts are no longer kept under `e2e/results/`.
