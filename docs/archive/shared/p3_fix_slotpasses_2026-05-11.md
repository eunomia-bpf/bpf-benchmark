# Phase 3 BBProgram slot-pass migration, 2026-05-11

## Scope

Migrated the four C-rated passes to BBProgram-native matching:

- `bpfopt/crates/bpfopt/src/passes/cond_select.rs`
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs`
- `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs`
- `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs`

## Gate outputs

- `cd bpfopt && cargo build --release`: pass, clean release build.
- `cd bpfopt && cargo test --release`: pass. 188 lib tests, 16 main tests, 1 `bbprogram_roundtrip`, 12 `cli_pipeline`, 0 doctests.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: pass, clean.
- `rg "site_pc\(|site_current_pc\(" ...four pass files`: zero matches.
- `rg "pc\s*[+\-]\s*1|pc\s*==\s*0|pc\s*>\s*0" ...four pass files`: zero matches.

## LOC

| file | before | after |
| --- | ---: | ---: |
| `cond_select.rs` | 693 | 672 |
| `ccmp.rs` | 534 | 518 |
| `bounds_check_merge.rs` | 584 | 561 |
| `skb_load_bytes.rs` | 314 | 306 |
| total | 2125 | 2057 |

## Code changes

- `cond_select`: uses `InsnSite` as the candidate key and reverse-apply order, emits `SiteSkipReason`, and matches diamonds through terminators/successors instead of PC adjacency. Key refs: `cond_select.rs:120`, `cond_select.rs:176`, `cond_select.rs:301`, `cond_select.rs:323`, `cond_select.rs:409`.
- `ccmp`: removed start/target PC fields and chain PC arithmetic. Chain discovery follows `CondBranch.fallthrough`, duplicate starts are rejected through predecessor structure, and target-inside-chain is checked with `site.blocks.contains(&site.target_block)`. Key refs: `ccmp.rs:154`, `ccmp.rs:179`, `ccmp.rs:367`, `ccmp.rs:384`, `ccmp.rs:441`.
- `bounds_check_merge`: guard setup is built from adjacent `sites_in_block_with_terminator(...).windows(3)`, and interleave scanning uses `BBProgram::bcm_sites_between` rather than slot ranges. Key refs: `bounds_check_merge.rs:198`, `bounds_check_merge.rs:417`, `bbprogram.rs:1446`.
- `skb_load_bytes_spec`: scan state is initialized per block, so a new block is a new scan context; helper skips are site-keyed. Key refs: `skb_load_bytes.rs:119`, `skb_load_bytes.rs:122`, `skb_load_bytes.rs:131`.
- Report PC conversion remains at the report sink: `main.rs:1116` materializes `SiteSkipReason` through `report_pc`, and `main.rs:1141` performs the `InsnSite -> pc` conversion. Test helpers materialize site skips only for existing PC-based assertions at `test_helpers.rs:269`.

## Slot-arithmetic evidence

- No `site_pc(` or `site_current_pc(` calls remain in the four pass files.
- No `pc + 1`, `pc - 1`, `pc == 0`, or `pc > 0` patterns remain in the four pass files.
- No `block_start_slot`, `start_pc`, `target_pc`, `start_slot`, `target_slot`, `should_reset_linear_state_at_block`, or `block_entry_site` references remain in the four pass files.
- Unit-test audit: no tests were deleted. Existing tests cover semantic regressions, ABI payload encoding, branch fixup, and skip behavior rather than trivial PC-arithmetic tautologies.

## Self-rating

- `cond_select`: A
- `ccmp`: A
- `bounds_check_merge`: A
- `skb_load_bytes_spec`: A
