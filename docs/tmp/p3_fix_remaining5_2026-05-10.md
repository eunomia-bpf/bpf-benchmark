# Phase 3 Remaining 5 Fix Report

## Issue 1: BBProgram.entry visibility

Addressed:
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:32` changes `BBProgram.entry` to `pub(crate)`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:110` adds `BBProgram::entry()`.

## Issue 2: pass PC bridge removal

Addressed:
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:38` centralizes site-to-PC conversion for diagnostics/profile side effects.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:43` adds block start slot helper.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:47` adds block/site-native program site iteration.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:55` adds ordered site/PC helper for verifier-oracle correlation.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:62` resolves CLI hint PCs to sites.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:75` derives CFG target entry sites without pass-local `branch_target_sites()`.
- `bpfopt/crates/bpfopt/src/analysis/mod.rs:17` exports the helper surface.

Production pass bodies no longer call `current_sites()`, `ordered_site_pcs()`, `branch_target_sites()`, `block_start_pc()`, `report_pc()`, or `site_by_report_pc()`.

Touched pass files:
- `bounds_check_merge.rs`, `branch_flip.rs`, `bulk_memory.rs`, `ccmp.rs`, `cond_select.rs`, `const_prop.rs`, `endian.rs`, `extract.rs`, `map_inline.rs`, `map_inline/map_info.rs`, `prefetch.rs`, `skb_load_bytes.rs`, `wide_mem.rs`.

## Issue 3: short non-pass test files inlined

Mappings:
- `analysis/lower_tests.rs` -> `analysis/bbprogram_lower.rs:219`
- `analysis/bbprogram_branch_target_tests.rs` -> `analysis/bbprogram.rs:1249`
- `analysis/bbprogram_cfg_tests.rs` -> `analysis/bbprogram.rs:1249`
- `analysis/bbprogram_map_refs_tests.rs` -> `analysis/bbprogram.rs:1249`
- `analysis/bbprogram_site_scan_tests.rs` -> `analysis/bbprogram.rs:1249`
- `insn_tests.rs` -> `insn.rs:682`

Deleted standalone files:
- `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_branch_target_tests.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_map_refs_tests.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_site_scan_tests.rs`
- `bpfopt/crates/bpfopt/src/insn_tests.rs`

Remaining short standalone test file is `passes/dce_tests.rs` and is a pass test, so it was kept.

## Issue 4: production expect in parse_bytecode

Addressed:
- `bpfopt/crates/bpfopt/src/main.rs:441` uses fallible `chunk.try_into()?`.
- `bpfopt/crates/bpfopt/src/main.rs:442` feeds the checked array into `BpfInsn::from_raw_bytes`.

## Issue 5: prefetch / kop admission policy

Chosen policy: prefetch remains outside `admit_kop_site_window` because it is insert-only, not a replacement. The existing shared helper remains kop-replacement admission for non-zero old/new instruction windows.

Addressed:
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:276` documents the insert-only exception and points to `choose_prefetch_insert_site` for block/subprogram bounds.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:114` keeps kop replacement admission on the shared diagnostic/site helper path.

`wide_mem` and `skb_load_bytes_spec` remain pure-BPF passes and are not treated as kop admission users.

## LOC

Final non-test LOC:
- `18528` Rust code lines by:
  `cloc bpfopt/crates/bpfopt/src --include-ext=rs --not-match-f='(_tests\\.rs|main_tests\\.rs|verifier_log_tests\\.rs|pass_tests\\.rs)$' --csv --quiet`

## Verification

Passed:
- `cargo build --release --manifest-path bpfopt/Cargo.toml`
- `cargo test --release --manifest-path bpfopt/Cargo.toml`  
  Result: `217` tests passed (`188` lib + `16` main + `1` roundtrip + `12` CLI).
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`
- `target/release/bpfopt list-passes | wc -l` -> `15`
- DCE smoke command exited `0`.

Sanity checks:
- `rg "pub entry:" bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` -> no matches.
- `rg "current_sites\\(|ordered_site_pcs\\(|branch_target_sites\\(|block_start_pc\\(|report_pc\\(" bpfopt/crates/bpfopt/src/passes/` -> no matches.
- `rg "site_by_report_pc\\(" bpfopt/crates/bpfopt/src/passes/` -> no matches.
- `rg "\\.expect\\(" bpfopt/crates/bpfopt/src/main.rs | grep -v "cfg(test)"` -> no matches.
