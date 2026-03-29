# Daemon Rust Cleanup Report (2026-03-29)

## Scope

Cleanup target: daemon Rust-side dead code and stale protocol/CLI remnants.

## Audit Results

- `daemon/src/passes/dangerous_helper_firewall.rs` was already absent.
- `daemon/src/passes/live_patch.rs` was already absent.
- `daemon/src/passes/speculation_barrier.rs` was already absent.
- `daemon/src/passes/mod.rs` contained no module declarations or pipeline registrations for the three out-of-scope security passes.
- `daemon/src/main.rs` already exposed only the `serve` subcommand. No `watch`/`apply`/`apply-all`/`enumerate`/`rewrite` CLI match arms remained.
- `daemon/src/commands.rs` had no helper functions that were only reachable from deleted CLI subcommands.
- `daemon/src/server.rs` had no old command handlers matching removed CLI subcommands. The remaining stale protocol residue was legacy request parsing for the `apply` boolean field.

## Changes Made

- Removed legacy `apply` request-field compatibility from `daemon/src/server.rs`.
- Kept `dry_run` as the only explicit mode selector; absent `dry_run` now uses the default apply path.

## Validation

- `RUSTFLAGS='-D warnings' make daemon`
- `RUSTFLAGS='-D warnings' make daemon-tests`
- Result: build passed with warnings denied.
- Result: `daemon-tests` passed, `535 passed; 0 failed`.

## Deleted Line Count

- Rust daemon source lines deleted this change: 11
- Rust daemon source lines added this change: 0
- Count source: `git diff --numstat -- daemon/src/server.rs`

## Notes

- No vendor files were modified.
- The security-pass cleanup requested in scope had effectively already happened before this change; this report records the audit outcome explicitly so the tree state is unambiguous.
