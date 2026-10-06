# Dynamic Map Invalidation Implementation Report

Date: 2026-03-26

## Scope

Implemented `MapInvalidationTracker` in `daemon/src/invalidation.rs` to satisfy the current TDD coverage for invalidation tracking:

- `record_inline_site(prog_id, map_fd, key, expected_value)`
- `remove_prog(prog_id)`
- batched invalidation checking via `MapValueReader`
- duplicate `(prog_id, map_fd, key)` updates
- deduplicated invalidated program ID output
- immutable polling via `check_for_invalidations(&self)`

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

6. Read-only invalidation polling
   - `check_for_invalidations()` now takes `&self` rather than `&mut self`.
   - This matches the implementation, which only reads tracker state during polling.
   - The change removes an unnecessary exclusive-borrow requirement for callers that want to poll through shared synchronization primitives.

## Verification

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml invalidation
```

Result:

- Passed
- Filtered test run: 12/12 passed
- New invalidation tests passed: 9/9
- Additional pre-existing `*invalidation*` substring matches passed: 3/3

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Result:

- Failed due to pre-existing unrelated `dangerous_helper_firewall` tests
- Full daemon test suite at execution time: 407 passed, 6 failed, 12 ignored
- Failing tests:
  - `passes::dangerous_helper_firewall::tests::test_branch_fixup_after_replacement`
  - `passes::dangerous_helper_firewall::tests::test_override_return_replaced`
  - `passes::dangerous_helper_firewall::tests::test_probe_read_kernel_audit_only`
  - `passes::dangerous_helper_firewall::tests::test_send_signal_replaced`
  - `passes::dangerous_helper_firewall::tests::test_multiple_dangerous_calls`
  - `passes::dangerous_helper_firewall::tests::test_ktime_get_ns_coarseified`

## Notes

- The current tracker interface still stores a reader instance internally and keeps `check_for_invalidations()` as the main convenience entry point.
- `check_all()` was added as a reusable explicit-reader helper so the batched comparison logic is available independently of the internal reader field.
- `main.rs` currently registers the module only; runtime integration into `watch`/`serve` remains follow-on work outside this tracker patch.
