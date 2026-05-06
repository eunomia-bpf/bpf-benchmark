+ post-dump size filter (file-size check, no JSON parse) at daemon/src/commands.rs:864.

# bpftool Map Dump Passthrough

Date: 2026-05-06

## Summary

The daemon no longer walks map keys or serializes a private `map-values.json`
schema. It now writes raw bpftool JSON into the per-step workdir and passes the
existing `${MAP_VALUES}` path through to bpfopt as a directory:

- `map-values/map-<id>.show.json`: raw stdout from `bpftool -j map show id <id>`
- `map-values/map-<id>.dump.json`: raw stdout from `bpftool -j map dump id <id>`

The daemon writes `show` for every referenced map so bpfopt has metadata and
BPF-side mutability for unsupported map types. It writes `dump` only for map
types whose values `map_inline` can consume: hash, array, percpu array, lru
hash, array-of-maps, and hash-of-maps.

## Data Flow

Before:

1. Daemon opened map fds and iterated keys with BPF map syscalls.
2. Daemon looked up each value, tolerated races with `entries_partial`, decoded
   inner map IDs, and serialized a private JSON schema.
3. bpfopt parsed that private schema, mirrored partial/null/missing sentinels,
   and used string-prefix veto errors for site-level skip handling.

After:

1. Daemon shells out to bpftool with explicit `std::process::Command` args.
2. Daemon stores raw bpftool stdout files in `map-values/`.
3. bpfopt parses bpftool `show`/`dump` JSON directly, derives writable status
   from the `flags` field, and reports typed missing-key/snapshot errors.

## Deleted Structs and Functions

Daemon:

- `MapValuesJson`, `MapValuesMapJson`, `MapValuesEntryJson`
- `MapValueSnapshotEntry`, `MapKeySnapshot`
- `live_bpf_map_lookup`, `live_bpf_map_keys`, `live_bpf_map_keys_with`
- `write_live_map_values`, `write_map_values_snapshot`
- `insert_snapshot_map_metadata`, `decode_inner_map_id_from_outer_value`
- `is_array_like_map`, `is_map_snapshot_map_type`
- `is_direct_value_inlineable_map_type`, `is_map_in_map_type`
- `LiveProgramBytecode`, `live_program_bytecode_snapshots`
- `detect_bpf_writable_maps`
- `TrackedPtr`, `MapWriteScanState`, and the BPF write-scanner helper family
- `bpf_map_lookup_elem_optional`, `bpf_map_get_next_key`
- `bpf_map_lookup_value_size`, percpu CPU-count helpers used only by snapshots

bpfopt:

- private `MapValuesJson`, `MapSnapshotJson`, `MapEntryJson`
- `map_value_nulls`, `map_entries_partial`
- `missing_map_value_snapshot_message`, `null_map_value_snapshot_message`
- `partial_map_value_snapshot_message`
- `is_missing_map_value_snapshot_error`, `is_null_map_value_snapshot_error`
- `is_partial_map_value_snapshot_error`
- `SITE_LEVEL_INLINE_VETO_PREFIX`, `site_level_inline_veto_reason`
- runtime-key fallback branch that converted non-veto lookup errors into skips

## Cleanup Map

- Deleted `daemon/src/commands.rs:230-264`: private map snapshot JSON structs
  and `entries_partial` fields.
- Deleted `daemon/src/commands.rs:338-385`: live map lookup/key snapshot glue.
- Deleted `daemon/src/commands.rs:948-1092`: hand-rolled snapshot writer and
  private JSON serializer.
- Deleted `daemon/src/commands.rs:1094-1174`: inner-map metadata replay and old
  map-type gates.
- Deleted `daemon/src/bpf.rs:49-145`: live program bytecode snapshots and
  daemon-side writable-map detection entrypoints.
- Deleted `daemon/src/bpf.rs:546-918`: bytecode write scanner used only for
  daemon-side writable detection.
- Deleted `daemon/src/bpf.rs:930-1022`: map lookup/get-next-key/value-size and
  percpu CPU-count helpers used only by hand snapshots.
- Deleted `bpfopt/crates/bpfopt/src/main.rs:236-258`: old private map-values
  schema structs.
- Deleted `bpfopt/crates/bpfopt/src/main.rs:1071-1152`: old private schema
  parser and hex decoder.
- Deleted `bpfopt/crates/bpfopt/src/pass.rs:118-122`: null and partial snapshot
  state in `BpfProgram`.
- Deleted `bpfopt/crates/bpfopt/src/pass.rs:246-280`: missing/null/partial
  string-message helpers.
- Deleted `bpfopt/crates/bpfopt/src/passes/map_inline.rs:26`: string-prefix
  sentinel constant.
- Deleted `bpfopt/crates/bpfopt/src/passes/map_inline.rs:905-1050`: string
  sentinel handling at site and runtime-key boundaries.
- Deleted `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1298-1339`: null and
  partial snapshot checks around direct map lookup.
- Deleted `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1690-1805`: map-in-map
  null/partial veto checks.
- Deleted `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2071-2076`: direct
  value partial/null filters.
- Deleted `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2203-2213`: sentinel
  creation and string-prefix stripping helpers.

## LoC

Refactor diff under `bpfopt/ daemon/` before this note:

```text
10 files changed, 465 insertions(+), 1510 deletions(-)
Net delta: -1045 LoC
```

The branch already had earlier bpfopt/daemon commits ahead of `origin/main`.
Those are separate from this refactor and remain visible in an
`origin/main..HEAD` aggregate stat.

## Surprises

- `bpftool -j map show id <id>` emits one object for a single map; `bpftool -j
  map dump id <id>` emits an array of entries. I confirmed this from the
  vendored bpftool source because the local kernel denied temporary map
  creation with `EPERM`.
- Dumping every referenced map would make unsupported map types fail before
  `map_inline` can skip them. The final path writes metadata for every map but
  only writes dump files for value-readable map types.
