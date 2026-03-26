# BulkMemoryPass Review Report

Date: 2026-03-26

## Scope

- Reviewed `daemon/src/passes/bulk_memory.rs` end to end.
- Verified registration and ordering in `daemon/src/passes/mod.rs`.
- Verified bulk kfunc registry/discovery plumbing in `daemon/src/pass.rs` and `daemon/src/kfunc_discovery.rs`.

## Code Quality Assessment

- Pass ordering is correct: `bulk_memory` sits after `wide_mem` in the canonical pipeline.
- The implementation reuses the existing packed-kinsn emission, BTF-fd slot, and branch-fixup helpers instead of duplicating rewrite machinery.
- After the review fixes below, the control flow is clear and there is no obvious dead code inside `bulk_memory.rs`.

## Issues Found And Fixed

1. Non-zero repeated-byte `memset` was being lowered even though daemon v1 is supposed to stay on the zero-fill path.
   - Fix: `memset_lane_at()` now rejects non-zero fills.
   - Regression test: `test_memset_nonzero_reg_skipped_by_default`.

2. Chunked same-base `memcpy` could incorrectly lower a non-overlapping 128B prefix from a larger overlapping run, clobbering source bytes needed by the untouched scalar tail.
   - Fix: overlap rejection now checks the full matched run length, not just the emitted prefix length.
   - Regression test: `test_same_base_chunked_overlap_skipped`.

3. Different-base `memcpy` had no alias gate and could lower unknown-to-unknown copies.
   - Fix: different-base lowering is now fail-closed unless exactly one side is stack-derived.
   - Regression test: `test_non_stack_base_memcpy_skipped_by_alias_gate`.

4. `kfunc_discovery.rs` initialized the bulk-memory registry slots but never discovered the corresponding targets.
   - Fix: added `bpf_memcpy_bulk` / `bpf_memset_bulk` to `KNOWN_KINSNS` and covered them with a unit guard.

## Test Results

- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml bulk_memory`
  - Result: `16 passed, 0 failed`
- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml`
  - Result: `395 passed, 0 failed, 12 ignored`
- `make daemon-tests`
  - Result: `395 passed, 0 failed, 12 ignored`

## Commit

- Implementation commit: `958bab4528b2`

## Notes

- `BULK_MEMORY_MODULE = "bpf_bulk_memory"` is an inferred family-module name chosen to match the existing multi-target naming pattern used by kinsn modules such as `bpf_endian`.
