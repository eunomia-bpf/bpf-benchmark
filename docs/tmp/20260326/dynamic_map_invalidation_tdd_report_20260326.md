# Dynamic Map Invalidation TDD Report (2026-03-26)

## Scope

- Added a new stub module at `daemon/src/invalidation.rs`.
- Registered the module in `daemon/src/main.rs`.
- Added the requested unit tests for dynamic map invalidation tracking.
- Intentionally did not implement invalidation logic. The tracker methods remain stubs.

## Stubbed API Added

- `TrackedInlineSite`
- `BatchLookupValue`
- `MapValueReader`
- `MapInvalidationTracker`

The tracker currently exposes the minimum shape needed for TDD:

- `new`
- `is_empty`
- `entry_count`
- `record_inline_site`
- `check_for_invalidations`
- `remove_prog`

## Tests Added

All new tests live in `daemon/src/invalidation.rs`:

- `test_tracker_empty`
- `test_record_inline_site`
- `test_record_multiple_sites`
- `test_check_unchanged_returns_empty`
- `test_check_changed_returns_affected_progs`
- `test_check_multiple_maps_independent`
- `test_remove_prog_clears_entries`
- `test_duplicate_key_updates_value`
- `test_batch_check_efficiency`

## Verification

Command run:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml invalidation
```

Result:

- Compilation succeeded.
- The test run failed as expected because the tracker is still stubbed.
- Cargo ran 12 tests total because the `invalidation` substring also matched 3 pre-existing tests outside the new module.

Observed summary from the run:

- New invalidation tests: 9 total
- New invalidation tests passed: 1
- New invalidation tests failed: 8
- Pre-existing non-invalidation tests that also matched the filter: 3 passed

Failing new tests:

- `test_record_inline_site`
- `test_record_multiple_sites`
- `test_check_unchanged_returns_empty`
- `test_check_changed_returns_affected_progs`
- `test_check_multiple_maps_independent`
- `test_remove_prog_clears_entries`
- `test_duplicate_key_updates_value`
- `test_batch_check_efficiency`

Passing new test:

- `test_tracker_empty`

## Why The Tests Fail

This is the intended red-state for TDD:

- `record_inline_site()` is a no-op, so no entries are stored.
- `check_for_invalidations()` always returns an empty `Vec<u32>`.
- `remove_prog()` is a no-op.

Those stubs are enough to compile the contract, while leaving the required behavior unimplemented.

## Design Note

The test seam uses a mockable trait with a batch-oriented method:

```rust
fn lookup_values_batch(&self, map_fd: u32, keys: &[Vec<u8>]) -> Result<Vec<BatchLookupValue>>;
```

That choice was made to satisfy the requested batching test. It is slightly stricter than the current design doc, which describes v1 polling as:

- dedupe by `(map_id, key)`
- group work per map
- still issue one lookup per key at the syscall layer

When implementation starts, that mismatch will need an explicit decision:

- keep batching as a tracker-level abstraction only, or
- change the tests and seam to reflect per-key syscalls inside per-map polling.
