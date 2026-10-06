# P3 Single-Block Kinsn Pass BBProgram Migration

Date: 2026-05-10

## Summary

Migrated the five single-block C-rated kinsn passes to BBProgram-native production paths. The pass entries now iterate `prog.blocks()` / `prog.sites_in_block(...)` and apply edits with `prog.replace_range(...)`; the old lowering, flat linear views, local original-PC replacement shims, and local prefetch CFG are gone from these files.

## Per-Pass Status

| Pass | Rating | LOC delta |
| --- | --- | ---: |
| `rotate.rs` | C -> A | -4 |
| `extract.rs` | C -> A | +25 |
| `endian.rs` | C -> A | +42 |
| `bulk_memory.rs` | C -> A | +31 |
| `prefetch.rs` | C -> A | +13 |

LOC deltas are from `git diff --numstat` against the current branch baseline for the five pass files.

## Private Helpers Added

- `rotate.rs`: `rotate_site_at`, `block_slot_offset`, `site_current_pc`.
- `extract.rs`: `extract_site_from_pair`, `cross_block_extract_skip`, `block_slot_offset`, `site_current_pc`.
- `endian.rs`: native `find_blocked_narrow_sites`, `cross_block_endian_skip`, `block_slot_offset`, `site_current_pc`.
- `bulk_memory.rs`: `should_reset_reg_state_at_block`, BBProgram-native `advance_reg_state_range` / `advance_reg_state`, `block_slot_offset`, `site_current_pc`.
- `prefetch.rs`: `choose_prefetch_insert_site`, `sites_in_frame_pc_range`, `sites_in_block_pc_range`, `frame_bounds`, `block_slot_bounds`, `site_current_pc`, `should_reset_tracked_packet_state_at_block`.

## BBProgram Method Gaps

- A shared `block_slot_offset(site)` / current-PC lookup helper would remove repeated pass-private helpers.
- A shared block/frame ordered-site iterator with PC bounds would simplify `prefetch`.
- A shared cross-block diagnostic helper for “same flat pattern, different block” would remove the local extract/endian skip compatibility helpers.
- A public fallthrough/lexical predecessor query would avoid local state-reset predicates in `bulk_memory` and `prefetch`.

## Test Status

- `cargo test --release` after `rotate.rs`: initially exposed a rotate range bug; after fixing it, rotate tests passed, but out-of-scope `wide_mem` skip tests failed when run alone.
- `cargo test --release` after later pass migrations is currently blocked by out-of-scope compile errors in `bpfopt/crates/bpfopt/src/passes/map_inline.rs` from concurrent dirty-tree edits. I did not modify `map_inline.rs`.
- `git diff --check --` the five migrated pass files: passed.
