# Serve Per-Request Passes Report

Date: 2026-03-26

## Summary

Implemented per-request pass selection for the daemon `serve` protocol.

- `optimize` and `optimize-all` now accept an optional `passes` array.
- When `passes` is present, the daemon validates names and builds a request-scoped custom pipeline in `PASS_REGISTRY` order.
- When `passes` is absent, serve mode uses the default full pipeline.
- Invalid pass names now return a structured error response instead of being ignored.
- Single-program optimize responses now expose top-level `prog_id`, `changed`, and `passes_applied`.

## Serve Semantics

Accepted request forms:

```json
{"cmd":"optimize","prog_id":123}
{"cmd":"optimize","prog_id":123,"passes":["map_inline","const_prop","dce","wide_mem"]}
{"cmd":"optimize-all","passes":["map_inline","const_prop","dce"]}
```

Behavior:

- `passes` omitted: full default pipeline.
- `passes` present: only the requested passes run, deduplicated/canonicalized in registry order.
- Unknown pass names: request fails with `{"status":"error","message":"unknown pass name(s): ..."}`.
- `serve` now ignores daemon-wide `--passes`; stderr emits a notice telling callers to use request `passes` instead.

`passes_applied` is reported as the changed passes from the final optimize attempt, in pipeline order.

## Code Changes

- `daemon/src/server.rs`
  - Added request parsing for optional `passes`.
  - Added request-time validation and full-pipeline fallback.
  - Routed `optimize` and `optimize-all` through request-scoped pass selection.
  - Added serve tests for parsing, fallback behavior, override behavior, and invalid-name rejection.

- `daemon/src/commands.rs`
  - Switched pipeline construction to validated helpers.
  - Added `pipeline_pass_names()` helper.
  - Added top-level `prog_id`, `changed`, and `passes_applied` to `OptimizeOneResult`.
  - Cached canonical selected passes before retry loops in `try_apply_one()`.

- `daemon/src/passes/mod.rs`
  - Added pass-name validation and canonical pass resolution helpers.
  - Added `build_full_pipeline()` and `build_custom_pipeline()`.
  - Enforced invalid-pass rejection instead of silently ignoring unknown names.
  - Added tests for registry-order custom pipelines and invalid-pass rejection.

- `daemon/src/main.rs`
  - Kept `--passes` validation for non-serve modes.
  - Added explicit serve-mode notice that `--passes` is ignored there.

## Verification

Ran the requested commands:

1. `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml server`
   - Passed: 5 tests
   - Failed: 0

2. `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml`
   - Passed: 448 tests
   - Failed: 0
   - Ignored: 12

Remaining test warnings are pre-existing `dead_code` warnings in:

- `daemon/src/analysis/cfg.rs`
- `daemon/src/pass.rs`
- `daemon/src/profiler.rs`

## Notes

- The repository had unrelated local modifications before this work; they were left untouched.
- No git commit or push was performed.
