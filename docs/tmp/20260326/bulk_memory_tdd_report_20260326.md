# BulkMemoryPass TDD Report

Date: 2026-03-26

## Scope

- Added `daemon/src/passes/bulk_memory.rs`
  - `BulkMemoryPass` stub implementing `BpfPass`
  - 12 TDD unit tests covering the requested bulk memcpy/memset scenarios
- Registered the pass in `daemon/src/passes/mod.rs`
  - exported `BulkMemoryPass`
  - inserted `bulk_memory` into `PASS_REGISTRY` after `wide_mem`
  - added alias `bulk_mem`
- Added minimal registry scaffolding in `daemon/src/pass.rs`
  - `memcpy_bulk_btf_id`
  - `memset_bulk_btf_id`
  - `btf_fd_for_target_name()`
- Updated `daemon/src/kfunc_discovery.rs` initializer so the crate still compiles with the new registry fields

## Test Command

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml bulk_memory
```

## Result

The test target compiled successfully and produced the intended TDD red state.

- Passed: 3
- Failed: 9

Passed tests:

- `test_empty_program`
- `test_no_consecutive_stores`
- `test_below_threshold_unchanged`

Failing tests:

- `test_memcpy_pattern_8_pairs`
- `test_memset_zero_pattern`
- `test_different_base_regs_not_merged`
- `test_non_consecutive_offsets_split`
- `test_mixed_widths_handled`
- `test_memcpy_preserves_surrounding`
- `test_branch_fixup_after_replacement`
- `test_interleaved_non_store_splits`
- `test_kfunc_not_available_skipped`

## Why It Is Red

`BulkMemoryPass::run()` is still a stub and returns the input program unchanged with no skip diagnostics. The failing tests are the ones that expect:

- bulk memcpy/memset replacement to occur
- multi-run splitting behavior
- branch fixup after instruction-count reduction
- explicit skip reporting when bulk kfuncs are unavailable

This is the expected state before implementing the actual pass logic.
