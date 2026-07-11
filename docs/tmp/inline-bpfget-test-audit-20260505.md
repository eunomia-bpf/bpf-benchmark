# Inline bpfget + daemon test audit (2026-05-05)
- LoC delta: `daemon/crates/bpfget/src/lib.rs -420`; `daemon/src/bpf.rs +403`; `daemon/src/commands.rs -13`; `daemon/Cargo.toml -4`.
- Other daemon deltas: `daemon/crates/bpfget/Cargo.toml -11`; `daemon/Cargo.lock -11`; `daemon/README.md -1`.
- Tree before: `daemon/{Cargo.toml,Cargo.lock,README.md,crates/bpfget/{Cargo.toml,src/lib.rs},src/{bpf.rs,commands.rs,main.rs,server.rs}}`.
- Tree after: `daemon/{Cargo.toml,Cargo.lock,README.md,src/{bpf.rs,commands.rs,main.rs,server.rs}}`; `daemon/crates/bpfget/` removed.
- Deleted tests: 2; deleted test lines: 22 (`commands.rs` 13, `bpf.rs` 9).
- Cargo: `cargo build --release --workspace --manifest-path daemon/Cargo.toml` passed; `cargo test --release --workspace --manifest-path daemon/Cargo.toml` passed, 23 tests.
- Net LoC delta: -20 including this report and the audit symlink; commit hash: self-referential, reported after commit creation in final response.

| file:line | test | decision | reason |
|---|---|---|---|
| `daemon/src/server.rs:249` | `optimize_response_keeps_per_program_errors_under_top_level_ok` | KEEP | Catches protocol regression where per-program failures abort or disappear from a top-level OK batch response. |
| `daemon/src/server.rs:310` | `process_request_rejects_blank_enabled_pass_name` | KEEP | Covers request validation for blank pass names before optimization starts. |
| `daemon/src/server.rs:325` | `process_request_rejects_missing_enabled_passes_for_optimize` | KEEP | Covers fail-fast runner contract when `enabled_passes` is absent. |
| `daemon/src/server.rs:339` | `process_request_rejects_empty_enabled_passes_for_optimize` | KEEP | Covers distinct empty-list input at the socket boundary. |
| `daemon/src/server.rs:354` | `process_request_rejects_singular_prog_id_for_optimize` | KEEP | Guards the batch-only `prog_ids` protocol and rejects stale singular API shape. |
| `daemon/src/server.rs:369` | `request_prog_ids_rejects_empty_list` | KEEP | Covers empty program-list validation in the parser helper. |
| `daemon/src/server.rs:380` | `request_prog_ids_rejects_duplicate_ids` | KEEP | Covers duplicate program-id rejection before parallel apply. |
| `daemon/src/bpf.rs:781` | `possible_cpu_list_counts_singletons_and_ranges` | KEEP | Catches CPU-list range/count parsing bugs used for percpu map value sizing. |
| `daemon/src/bpf.rs:788` | `possible_cpu_list_rejects_empty_and_descending_ranges` | KEEP | Covers malformed CPU-list error paths. |
| `daemon/src/bpf.rs:838` | `canonicalize_round129_real_ldimm64_pattern_to_idx_order` | KEEP | Real corpus regression for first-seen loader-FD to map-index ordering. |
| `daemon/src/bpf.rs:866` | `canonicalize_round102_real_pattern_keeps_duplicate_fd_binding` | KEEP | Real corpus regression for duplicate loader-FD binding preservation. |
| `daemon/src/bpf.rs:890` | `canonicalize_remaps_all_four_pseudo_modes_with_loader_fd_array` | KEEP | Covers FD, value, IDX, and IDX_VALUE map reference conversion. |
| `daemon/src/bpf.rs:911` | `canonicalize_preserves_idx_without_loader_fd_array` | KEEP | Covers already-canonical IDX forms without loader fd_array metadata. |
| `daemon/src/bpf.rs:925` | `canonicalize_rejects_pseudo_map_idx_out_of_range` | KEEP | Covers out-of-range map-index error path. |
| `daemon/src/bpf.rs:932` | `canonicalize_rejects_more_unique_loader_fds_than_map_ids` | KEEP | Covers inconsistent loader-FD/map-id metadata error path. |
| `daemon/src/bpf.rs:942 (deleted)` | `canonicalize_with_no_pseudo_map_refs_is_noop` | DELETE | Shallow no-op assertion; stronger canonicalization tests cover meaningful branches and regressions. |
| `daemon/src/commands.rs:1104` | `bytecode_decoder_rejects_unaligned_input` | KEEP | Covers bytecode ABI boundary rejection for non-8-byte instruction streams. |
| `daemon/src/commands.rs:1110 (deleted)` | `rejit_fd_array_builder_keeps_map_fds_without_target` | DELETE | Duplicate shallow map-fd coverage; map ordering is already checked with module fd placement. |
| `daemon/src/commands.rs:1110` | `rejit_fd_array_builder_places_maps_first_and_module_btf_fds_at_call_offsets` | KEEP | Catches fd_array ABI regressions for maps-first and module call-offset placement. |
| `daemon/src/commands.rs:1168` | `rejit_fd_array_builder_uses_btf_placeholder_when_no_maps` | KEEP | Covers verifier fd_array placeholder behavior for no-map programs with module koperation. |
| `daemon/src/commands.rs:1197` | `rejit_fd_array_builder_rejects_missing_module_slot` | KEEP | Covers non-contiguous target call-offset error path. |
| `daemon/src/commands.rs:1222` | `rejit_fd_array_builder_rejects_conflicting_module_offsets` | KEEP | Covers conflicting BTF module slot error path. |
| `daemon/src/commands.rs:1257` | `target_call_offsets_shift_after_map_prefix` | KEEP | Covers target.json call-offset rewrite after map fd prefix insertion. |
| `daemon/src/commands.rs:1297` | `live_map_values_snapshot_writes_values_and_lookup_misses` | KEEP | Catches map-inline JSON serialization for present values and lookup misses. |
| `daemon/src/commands.rs:1346` | `try_apply_programs_converts_failures_to_program_results` | KEEP | Catches batch semantics where per-program apply errors become result payloads instead of aborting the batch. |
