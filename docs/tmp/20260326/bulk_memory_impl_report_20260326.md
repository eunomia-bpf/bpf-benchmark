# BulkMemoryPass Implementation Report

Date: 2026-03-26

## Scope

- Implemented `BulkMemoryPass::run()` in `daemon/src/passes/bulk_memory.rs`.
- Added end-to-end bulk-memory site scanning, filtering, rewriting, and branch fixup.

## Implemented Behavior

- Detects straight-line scalarized `memcpy` runs formed by adjacent `LDX_MEM + STX_MEM` pairs with stable bases and contiguous offsets.
- Detects straight-line scalarized zeroing `memset` runs formed by contiguous `ST_MEM` / `STX_MEM` stores with a stable base.
- Enforces the `32B` minimum threshold.
- Chunks long runs into packed kinsn calls with a `128B` maximum chunk size.
- Emits packed `sidecar + BPF_PSEUDO_KINSN_CALL` replacements for:
  - `bpf_memcpy_bulk`
  - `bpf_memset_bulk`
- Skips safely when the required kfunc or packed ABI support is unavailable.
- Fixes branch offsets after instruction-count changes.
- Preserves memcpy correctness with:
  - tmp-register live-out checking
  - same-base overlap rejection across the full matched run
  - different-base alias gate: only stack-vs-non-stack copies are accepted without richer pointer provenance
- Handles the test-covered split cases:
  - different base registers
  - offset gaps
  - interleaved non-store instructions
  - mixed-width memset byte counting

## Review Fixes

- Tightened `memset` lowering to zero-fill only. The earlier matcher accepted non-zero repeated-byte stores, which was outside the v1 daemon scope.
- Fixed chunked same-base `memcpy` overlap handling. The earlier code checked only the emitted prefix length, which could clobber source bytes needed by an untouched scalar tail.
- Fixed discovery integration so `kfunc_discovery.rs` now includes the bulk-memory kfunc targets instead of leaving the new registry slots permanently undiscoverable.

## Verification

- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml bulk_memory`
  - Result: `16 passed, 0 failed`
- `make daemon-tests`
  - This is the repo's canonical wrapper for `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml`
  - Result: `395 passed, 0 failed, 12 ignored`

## Notes

- The remaining Rust warnings reported by the full daemon test run are pre-existing and unrelated to `BulkMemoryPass`.
