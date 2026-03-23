# E2E Results

Top-level `e2e/results/` stores one timestamped directory per run.

- Each run lives under `e2e/results/<run_type>_<timestamp>/`.
- `metadata.json` is always kept.
- Older runs of the same type keep `metadata.json` but have `details/` pruned.
- Per-case markdown and JSON details live under `details/`.

Current top-level authoritative JSON:

- `tracee_authoritative_20260313_postfix.json`
- `bpftrace_authoritative_20260312.json`
- `scx_authoritative_20260311.json`

`tracee_authoritative_20260313_postfix.json` is the kept replacement for the older
same-day `tracee_authoritative_20260313.json`, which now lives in `archive/`.

The retired XDP dataplane E2E case was removed on 2026-03-18, so its checked-in artifacts are no longer kept under `e2e/results/`.
