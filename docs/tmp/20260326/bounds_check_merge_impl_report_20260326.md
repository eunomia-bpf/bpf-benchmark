# BoundsCheckMergePass Implementation Report

Date: 2026-03-26

## Summary

Implemented `BoundsCheckMergePass` in `daemon/src/passes/bounds_check_merge.rs` and registered it in the default pass pipeline after `dce`.

The pass now:

- gates on packet-processing program types: `XDP`, `SCHED_CLS`, `SCHED_ACT`, `LWT_IN`, `LWT_OUT`, `LWT_XMIT`, `SK_SKB`
- tracks `ctx->data` (`ctx + 0`) and `ctx->data_end` (`ctx + 4`) lineage with a lightweight per-register abstract state
- recognizes canonical constant-window guards of the form:
  - `tmp = data`
  - `tmp += const`
  - `if tmp > data_end goto slow`
- recognizes and reports variable-offset guards as non-mergeable in v1
- forms conservative ladders that require:
  - same packet root/base register
  - same `data_end` register lineage
  - same slow target
  - increasing windows
  - safe straight-line interleaving only
- rewrites mergeable ladders by widening the first guard to the largest window and removing later redundant guard triplets when safe
- fixes branch offsets and runs unreachable/NOP cleanup after rewrite

## Notes

Current implementation is intentionally conservative:

- only in-place widening of the dominant guard is implemented
- later setup instructions are removed only when the cursor temp is dead after the compare
- larger window jumps are treated as gapped ladders and skipped in v1

This is enough to satisfy the TDD coverage already added for the pass while keeping the transformation fail-closed.

## Files Changed

- `daemon/src/passes/bounds_check_merge.rs`
- `daemon/src/passes/mod.rs`

## Verification

Ran:

```bash
cd daemon && cargo test bounds_check
cd daemon && cargo test
```

Result:

- `cargo test bounds_check`: 13 passed
- `cargo test`: 364 passed, 12 ignored, 0 failed
