# Daemon Quality Fixes 2026-03-28

## Scope

This change set tightened daemon-side error handling, rollback attribution, CLI shape, and pass-name validation across:

- `daemon/src/analysis/map_info.rs`
- `daemon/src/bpf.rs`
- `daemon/src/commands.rs`
- `daemon/src/main.rs`
- `daemon/src/pass.rs`
- `daemon/src/passes/map_inline.rs`
- `daemon/src/passes/mod.rs`
- `daemon/src/server.rs`

## Fixes

### 1. Error propagation, no silent fallback

- `commands.rs`: all `bpf_prog_get_map_ids(...).unwrap_or_default()` sites now propagate errors with context.
- `bpf.rs`: `relocate_map_fds_with_bindings()` now fails hard on unresolved map IDs and on any `BPF_MAP_GET_FD_BY_ID` failure.
- `commands.rs`: relocation failure now aborts apply / identity-REJIT instead of warning and continuing.
- `bpf.rs`: `bpf_prog_get_next_id()` now returns `Result<Option<u32>>`, so end-of-list is distinct from real syscall failure; `iter_prog_ids()` now yields `Result<u32>`.
- `analysis/map_info.rs`: `resolve_live_map_info()` now propagates live-map lookup failures instead of swallowing them via `.ok()?`; `MapInfoAnalysis` forwards that error to `map_inline`.

### 2. Rollback attribution no longer covers the whole program

- `pass.rs`: removed the old "whole final program" attribution fallback.
- `pass.rs`: `PassManager` now diffs pre/post instruction streams for each changed pass and records only changed PC ranges.
- `commands.rs`: verifier-failure attribution now matches against those real changed ranges.

### 3. CLI cleanup

- Removed global CLI flags.
- `--no-rollback` is now subcommand-local on the REJIT-producing commands.
- Removed `PolicyConfig.pipeline_profile`.
- Removed `build_pipeline_for_profile()` and `selected_pass_names()` dead/legacy plumbing.

### 4. Pass alias / unknown-pass handling

- `passes/mod.rs`: pass selection stays one-name-per-pass; legacy alias acceptance is gone.
- `server.rs`: `enabled_passes` and `disabled_passes` are both validated; unknown names and aliases are rejected explicitly.
- `pass.rs`: pass policy validation rejects unknown configured names instead of silently no-oping.

## Tests

- Ran `make daemon-tests`
- Result: `503 passed, 0 failed, 13 ignored`

## Line Count

Measured against the pre-task index state for the touched source files:

- Diff stat: `+505 / -247`, net `+258` lines
- Production-only lines before first `#[cfg(test)]`: net `+143` lines

The requested net line reduction goal was not met. The main driver is the new per-pass changed-range attribution logic in `pass.rs`, which replaced the previous whole-program fallback with explicit diff tracking.
