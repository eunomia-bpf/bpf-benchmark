# MapInline Speculative Refactor Report

Date: 2026-03-26

## Summary

Refactored `MapInlinePass` to support speculative map inlining for any directly readable map value, not just frozen maps, and connected successful map-inline specializations to `MapInvalidationTracker` so long-running daemon modes can re-optimize when backing map contents change.

## Key Changes

### 1. Speculative map inlining

- Removed the frozen/immutable requirement from `MapInfo::is_inlineable_v1()`.
- `MapInlinePass` now inlines:
  - `ARRAY` values when the element can be read directly.
  - `HASH` / `LRU_HASH` values speculatively, preserving the existing immediate null-check requirement and keeping the lookup/null-check sequence in place.
- PERCPU map filtering remains unchanged and still rejects `PERCPU_*` map types.

### 2. Pass-to-tracker plumbing

- Chose the `PassResult` route instead of mutating tracker state through `PassContext`.
- Added `pass::MapInlineRecord` and `PassResult::map_inline_records`.
- `MapInlinePass` now emits one record per successfully specialized lookup site:
  - `map_id`
  - encoded lookup key bytes
  - full map value bytes read during specialization
- `commands::try_apply_one()` collects these records from the final successful pipeline attempt and refreshes tracking after successful REJIT.

Reason for this design:

- Keeps `MapInlinePass` pure and testable.
- Avoids threading interior-mutability state through `PassContext`.
- Ensures tracker state reflects the final successful rollback-adjusted attempt, not intermediate failed attempts.

### 3. Invalidation tracker integration

- Added a production `BpfMapValueReader`.
- Added `bpf::bpf_map_lookup_elem_optional()` so missing keys can be represented as `None`.
- Extended `MapInvalidationTracker` to retain owned map FDs for tracked entries, so periodic checks have valid live descriptors.
- Added command-side helpers to:
  - remove stale entries for a program on successful reapply
  - open/retain map FDs by map ID
  - record new inline dependencies for the updated specialization

### 4. Serve/watch re-optimization loop

- `serve` and `watch` now allocate a shared invalidation tracker.
- Added a periodic invalidation tick (1 second cadence) that:
  - calls `check_for_invalidations()`
  - re-runs `try_apply_one()` for each invalidated program
  - refreshes tracker state from the new successful specialization
- One-shot CLI `apply-all` remains unchanged and does not keep invalidation state.
- Serve-mode request handlers now also record invalidation state for `optimize` and `optimize-all`.

## Files Updated

- `daemon/src/passes/map_inline.rs`
- `daemon/src/analysis/map_info.rs`
- `daemon/src/pass.rs`
- `daemon/src/invalidation.rs`
- `daemon/src/bpf.rs`
- `daemon/src/commands.rs`
- `daemon/src/server.rs`

## Tests Added/Updated

- `map_inline_pass_inlines_non_frozen_array_maps`
- `map_inline_pass_records_inlined_sites_for_tracker`
- existing PERCPU map-inline rejection tests remain and pass
- `test_record_map_inline_records_updates_tracker`
- `process_invalidation_tick_reoptimizes_invalidated_programs`
- updated `MapInfo` mutability test to reflect speculative inlining

## Verification

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml map_inline
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml invalidation
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- `map_inline`: passed
- `invalidation`: passed
- full daemon test suite: passed (`434 passed`, `0 failed`, `12 ignored`)

## Notes

- The daemon test suite still emits a few pre-existing dead-code warnings unrelated to this refactor.
- No git commit or push was performed.
