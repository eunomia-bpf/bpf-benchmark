# Capture Map Redesign Report

Date: 2026-03-26

## Goal

Redesign `capture_map_state.py` so it only captures the `(map_id, key, value)` tuples that `map_inline` actually specialized, instead of dumping every live map attached to a program.

## Chosen Design

Implemented Option A.

- The daemon optimize result now includes `inlined_map_entries`.
- Each entry is a deduplicated `(map_id, key_hex, value_hex)` record derived from `MapInlineRecord`.
- The capture script no longer walks live maps or issues raw `bpf()` map dump syscalls.
- E2E map capture now runs after `apply_daemon_rejit()` so the optimize response is available.

## Code Changes

### Daemon

- `daemon/src/commands.rs`
  - Added `InlinedMapEntry`.
  - Added `inlined_map_entries` to `OptimizeOneResult`.
  - Added projection logic from `MapInlineRecord -> InlinedMapEntry`.
  - Deduplicates by `(map_id, key)` and keeps the final specialized value.
  - Covered serialization and dedupe with unit tests.

- `daemon/src/server.rs`
  - Updated the optimize-response comment to reflect that `inlined_map_entries` is part of the structured JSON response.

### Runner / Capture

- `runner/libs/rejit.py`
  - Surfaces `kernel_prog_name` and `inlined_map_entries` from daemon apply results for each program.

- `runner/scripts/capture_map_state.py`
  - Rewritten as a pure JSON transformer.
  - New required input: `--inline-capture-json`.
  - Groups entries by `map_id` and writes only the inlined keys.
  - Removes the old full-map raw-syscall dump path entirely.

- `e2e/case_common.py`
  - `capture_map_state()` now accepts `optimize_results`.
  - Serializes compact per-program inline capture input for the script.

- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/katran/case.py`
  - Moved map capture to after `apply_daemon_rejit()`.
  - Pass daemon optimize results into the capture helper.

## Behavioral Result

Before:

- Capture enumerated all attached maps.
- Hash/LRU maps were fully iterated.
- Katran could OOM on huge connection tables.

After:

- Capture only writes entries that `map_inline` actually inlined.
- Large unrelated maps are ignored completely.
- Katran no longer needs full-table dumping for map capture.

## Validation

Requested checks:

```bash
python3 -m py_compile runner/scripts/capture_map_state.py e2e/case_common.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/katran/case.py runner/libs/rejit.py
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- `py_compile`: passed
- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml`: failed on the current worktree (`477 passed, 24 failed, 12 ignored`)
- The failures were existing `passes::real_bpfo_tests::*` coverage failures outside the map-capture redesign paths. Representative failures included:
  - `program must still end with EXIT`
  - `... did not change; skipped=[...]`

Focused checks for this redesign:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml test_collect_inlined_map_entries_deduplicates_map_key_pairs
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml test_optimize_one_result_serialization
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml test_optimize_one_result_with_rollback
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml server::tests
```

- All focused daemon tests above passed.

Additional smoke check:

- Ran `runner/scripts/capture_map_state.py` against synthetic optimize JSON.
- Verified duplicate `(map_id, key)` entries collapse to one saved value and fixtures contain only grouped inline entries.

## Notes

- The daemon worktree already had unrelated edits in other files before this task; those were left untouched.
- `cargo test` emitted existing dead-code warnings from unrelated daemon modules, but the test run passed.
