# Dynamic Map Invalidation Implementation Report

Date: 2026-03-26

## Scope

Implemented `MapInvalidationTracker` in `daemon/src/invalidation.rs` to satisfy the current TDD coverage for invalidation tracking:

- `record_inline_site(prog_id, map_fd, key, expected_value)`
- `remove_prog(prog_id)`
- batched invalidation checking via `MapValueReader`
- duplicate `(prog_id, map_fd, key)` updates
- deduplicated invalidated program ID output

This change is intentionally scoped to the tracker and its test-side reader mock. Runtime wiring into `cmd_apply`, `cmd_watch`, or `cmd_serve` was not added in this patch because the current failing tests were limited to tracker behavior.

## Implementation Details

File changed:

- `daemon/src/invalidation.rs`

Key behaviors implemented:

1. Entry recording and duplicate updates
   - Tracks each inline site as a `TrackedInlineSite`.
   - If the same `(prog_id, map_fd, key)` is recorded again, the stored `expected_value` is updated in place instead of adding a duplicate entry.

2. Program removal
   - `remove_prog(prog_id)` now removes all tracked entries owned by that program.

3. Batched invalidation checks
   - Added `check_all<R: MapValueReader>(&self, reader: &R) -> Result<Vec<u32>>`.
   - Groups tracked keys by `map_fd`.
   - Deduplicates keys per map before issuing lookups.
   - Performs exactly one `lookup_values_batch()` call per map bucket.
   - Compares returned live values against tracked `expected_value`.
   - Treats missing values as invalidations.

4. Deterministic invalidation fanout
   - Invalidated program IDs are collected in a `BTreeSet`, producing a deduplicated and deterministic result list.

5. Test-side mock reader
   - Added `MockMapValueReader` in the invalidation test module.
   - It supports configurable per-map key/value state and records batch call counts for the batch-efficiency assertions.

## Verification

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml invalidation
```

Result:

- Passed
- Invalidation-specific tests passed: 9/9

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Result:

- Passed
- Full daemon test suite: 404 passed, 0 failed, 12 ignored

## Notes

- The current tracker interface still stores a reader instance internally and keeps `check_for_invalidations()` as the main convenience entry point.
- `check_all()` was added as a reusable explicit-reader helper so the batched comparison logic is available independently of the internal reader field.
