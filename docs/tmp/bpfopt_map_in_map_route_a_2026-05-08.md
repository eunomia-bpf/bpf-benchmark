# bpfopt map-in-map Route A

Date: 2026-05-08

## Changed Files and LOC

This task was implemented on top of an already-dirty worktree. Manual task-local
count, excluding pre-existing diffs:

| file | task-local LOC | notes |
|---|---:|---|
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | ~240 | Route A hint binding, outer raw/overlay inner-map-id resolution, hinted fail-fast paths, hard-hint key materialization tracking |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | ~330 | Route A success/error unit tests and small metadata helper |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | ~3 | Restored package test build by importing `Tnum` and selecting the right synthetic const-prop PC after map_inline rewrites |

## Behavior

- `--inline-hint=<outer_map>:!<outer_key_hex>` can now bind a map-in-map outer
  lookup (`ARRAY_OF_MAPS` / `HASH_OF_MAPS`) without reading the outer entry as a
  normal scalar map value.
- `--inline-hint=<inner_map>:!<inner_key_hex>` can be deferred and then attached
  to the dynamic inner lookup whose `r1` map pointer comes from the hinted outer
  lookup.
- Outer key to inner map id resolution uses existing raw `inner_map_id` entries
  first, then compressed/raw value lookup where the value bytes encode a
  little-endian `u32` inner map id.
- Hinted map-in-map outer folds are hard-fold only. Soft outer folds still fail
  fast and remain #249 work.

## Test Coverage

Added unit coverage for:

- `ARRAY_OF_MAPS` outer hard hint plus `ARRAY` inner hard hint; verifies both
  helper calls are removed and the inner value load becomes a constant.
- `HASH_OF_MAPS` outer using a compressed overlay to supply the inner map id,
  plus `ARRAY` inner hard hint.
- Non map-in-map outer hint paired with an inner hint fails.
- Missing outer entry / missing inner map id for a hinted outer fails.
- Kernel-mutable inner map (`LRU_HASH`) fails.
- Orphan inner hint with no matching hinted outer fails.

Validation run:

```text
cargo test -p bpfopt
```

Result: 318 lib tests, 9 bin tests, 11 CLI tests, and 0 doctests passed.

## Edge Cases

- Existing direct map PC/name hints remain direct-map behavior; only unresolved
  hints are deferred as possible map-in-map inner hints.
- Hinted map-in-map outer keys now fail if the snapshot/overlay has no live
  inner map id instead of degrading to a skip.
- Inner map mutability still uses the existing kernel-write/LRU filter.
- Hard hint key materialization now records matching stack key setup PCs, so
  full hard-fold removal can delete both outer and inner lookup setup bytecode.

## Known Leftovers

- Soft fold for map-in-map outer is intentionally unsupported.
- This change does not add new daemon snapshot recursion or benchmark runner
  behavior.
- No corpus benchmark was run.
