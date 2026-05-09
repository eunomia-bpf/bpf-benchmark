# bpfopt compressed overlay reader

Date: 2026-05-08

## Changed files

- `bpfopt/crates/bpfopt/src/pass.rs`
- `bpfopt/crates/bpfopt/src/mock_maps.rs`
- `bpfopt/crates/bpfopt/src/pass_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs`
- `docs/tmp/bpfopt_overlay_reader_2026-05-08.md`

Current `git diff --numstat` for the touched bpfopt code files:

| file | added | deleted |
| --- | ---: | ---: |
| `bpfopt/crates/bpfopt/src/mock_maps.rs` | 23 | 0 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 66 | 20 |
| `bpfopt/crates/bpfopt/src/pass_tests.rs` | 99 | 0 |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | 1401 | 334 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 345 | 76 |

Note: `pass.rs`, `map_inline.rs`, and `map_inline_tests.rs` already had dirty #244-era edits at task start. The table is the worktree-vs-HEAD numstat for the final touched files, not a claim that every listed line was introduced in this task.

## Implementation

- Added `CompressedMapValues` / `CompressedMapValuesKind` to `BpfProgram`.
- `SnapshotMapProvider` and the test `MockMapProvider` now resolve lookup values in this order:
  1. compressed overlay
  2. raw snapshot entries
  3. missing key / skipped-by-size / metadata error
- `map_inline` reads compressed overlays from either:
  - a per-map `map-<id>.dump.json` object with `compression`, or
  - `overlays.json` inside the existing `--map-values` directory, keyed by map id.
- Size-skipped maps with no overlay now emit per-site skips:
  `site at PC=N: skip reason: map snapshot skipped by size and no overlay provided (map_name=X, map_id=Y)`.
- Size-skipped maps with an overlay are no longer counted as unresolved `maps_skipped_by_size` and can inline normally.

## Schema Validation Coverage

Covered by `compressed_overlay_schema_validation_fail_fast`:

- unknown `compression`
- `uniform` missing `value_hex`
- `sparse` missing `default_hex`
- `enumerated` missing `entries`
- `value_hex` length mismatch
- `default_hex` length mismatch
- `entries` value length mismatch
- same map payload containing raw entries plus `compression`

Covered by `map_values_overlay_rejects_raw_entries_and_compression_for_same_map`:

- same map id has raw bpftool entries and a compression overlay in `overlays.json`

Covered by `snapshot_provider_lookup_compressed_overlays`:

- `uniform` returns the same value for any key
- `sparse` returns explicit entries and default fallback
- `enumerated` returns explicit entries and reports missing keys as entry-not-exist

Covered by `map_inline_pass_skips_size_skipped_array_map` and `map_inline_pass_uses_overlay_for_size_skipped_array_map`:

- per-site size-skip diagnostic when no overlay exists
- overlay bypasses daemon size-skip and enables inline

## Test Output

Command:

```bash
cargo test -p bpfopt
```

Result:

```text
test result: ok. 310 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
Doc-tests bpfopt: 0 passed; 0 failed
```

No corpus benchmark was run.

## Edge Cases

- Overlay `value_size` must match bpftool `bytes_value`.
- Overlay entry keys must be exact `bytes_key` length.
- Overlay value hex strings must be exact `value_size * 2` hex digits.
- `sparse` missing key returns `default_hex`.
- `enumerated` missing key stays a missing snapshot entry, so hash-like maps keep entry-not-exist semantics.
- A daemon size-skip marker does not block lookup when a compression overlay exists for the same map id.
- Raw entries plus compression for the same map id is rejected instead of choosing precedence.
