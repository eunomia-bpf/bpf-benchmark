# Round A Dead Cleanup 2026-05-09

## LOC delta
Paths are relative to `bpfopt/crates/bpfopt/src/`; `daemon/src` was unchanged. Target scope total: `32766 -> 32719 (-47)`.

| File | LOC | File | LOC | File | LOC |
|---|---:|---|---:|---|---:|
| analysis/branch_target_tests.rs | 60 -> 60 (0) | analysis/liveness_tests.rs | 114 -> 114 (0) | main.rs | 1534 -> 1534 (0) |
| insn.rs | 462 -> 491 (+29) | pass.rs | 1026 -> 1012 (-14) | pass_tests.rs | 619 -> 618 (-1) |
| passes/bounds_check_merge_tests.rs | 392 -> 392 (0) | passes/branch_flip_tests.rs | 489 -> 489 (0) | passes/bulk_memory_tests.rs | 533 -> 548 (+15) |
| passes/ccmp_tests.rs | 216 -> 216 (0) | passes/cond_select.rs | 620 -> 611 (-9) | passes/cond_select_tests.rs | 478 -> 482 (+4) |
| passes/const_prop_tests.rs | 368 -> 384 (+16) | passes/dce_tests.rs | 50 -> 50 (0) | passes/endian_tests.rs | 541 -> 541 (0) |
| passes/extract_tests.rs | 511 -> 511 (0) | passes/map_inline.rs | 5504 -> 5502 (-2) | passes/map_inline_tests.rs | 3142 -> 3145 (+3) |
| passes/mod_tests.rs | 295 -> 294 (-1) | passes/prefetch_tests.rs | 173 -> 173 (0) | passes/rotate_tests.rs | 444 -> 444 (0) |
| passes/skb_load_bytes.rs | 398 -> 389 (-9) | passes/skb_load_bytes_tests.rs | 358 -> 358 (0) | passes/utils.rs | 1531 -> 1532 (+1) |
| passes/wide_mem_tests.rs | 606 -> 606 (0) | test_helpers.rs | 227 -> 148 (-79) | target total | 32766 -> 32719 (-47) |

## Deleted dead/redundant APIs
- Removed `PlatformCapabilities::test_default`; `rg 'PlatformCapabilities::test_default|PassContext::test_default|fn test_default|test_default\(' bpfopt/crates/bpfopt/src/pass.rs bpfopt/crates/bpfopt/src/pass_tests.rs bpfopt/crates/bpfopt/src/passes` returns no matches.
- Removed duplicate helpers `test_helpers::{call_helper,exit_insn,mov32_reg,st_mem}`, `utils::is_kop_sidecar_insn`, `cond_select::mov32_reg`, and `skb_load_bytes::jgt_reg`; targeted `rg` checks return no defining matches.
- Removed map_inline numeric helper constants; `rg 'const HELPER_|HELPER_MAP_' bpfopt/crates/bpfopt/src/passes/map_inline.rs bpfopt/crates/bpfopt/src/passes/mod_tests.rs` returns no matches.
- `rg '#\[allow\(dead_code\)\]' bpfopt/crates/bpfopt/src daemon/src` returns no matches. A caller scan found no additional 0-caller `passes/utils.rs` functions after cleanup.

## BpfInsn constructors
Added and migrated call sites to `BpfInsn::{exit,helper_call,mov32_reg,st_mem,jump_imm,jump_reg}`. `test_helpers.rs` now keeps only thin branch/add aliases where that reduced test LOC.

## Renames and visibility
- Renamed `PassContext::test_default()` to `PassContext::baseline()`.
- Made `MapLookupSite`, `MapInMapChain`, `ConstantKey`, `FixedLoadUse`, `R0UseClassification`, `find_map_lookup_sites`, and `find_map_in_map_chains` private to `map_inline.rs`.
- Made `eliminate_unreachable_blocks_with_cfg` private in `passes/utils.rs`.

## Verification
- `cargo build --workspace --locked`: clean in both `bpfopt/` and `daemon/`.
- `cargo test --workspace --locked`: bpfopt `332 + 12 + 12` passed; daemon `25` passed; total `381` tests.
- `git diff --shortstat -- bpfopt/crates/bpfopt/src daemon/src`: `26 files changed, 706 insertions(+), 753 deletions(-)`.

## Boundary notes
No unit tests, benchmark runs, commits, algorithm changes, or daemon source edits were added. The remaining `HELPER_MAP_LOOKUP_ELEM` alias in `passes/prefetch.rs` is libbpf-sys-backed, non-numeric, and outside the requested map_inline cleanup.
