# Phase 3 map_inline BBProgram Re-Port Report

## 1. Deleted subsystems

- Deleted `linear_program_view` and the `stable_map_fd_bindings` lower-and-copy adapter from old `map_inline.rs:2292-2320`.
- Removed fixed-point clone/diff lowering from old `map_inline.rs:2352-2372`; rounds now rebuild a pass-local BBProgram view and mutate the original `BBProgram` in place.
- Deleted the PC-keyed `DirectMapValueLoadRewrites` alias from old `map_inline.rs:1029-1034`.
- Replaced `SiteRewrite.replacements: BTreeMap<usize, Vec<BpfInsn>>` and deleted `ReplacementBranchPatch` from old `map_inline.rs:1579-1595`.
- Deleted `map_inline_addr_map`, `patch_replacement_branches`, deletion-range synthesis, and old-PC edit dispatch from old `map_inline.rs:2946-3132`.
- Deleted `linear_subprog_bounds` / `linear_subprog_ranges` from old `map_inline.rs:4838-4865`.

## 2. New structure

- `MapInlineProgram` (`map_inline.rs:248-590`) is the per-round BBProgram view. It linearizes current BBProgram sites for existing local analyses, but side inputs come from `PassContext` and map fd bindings come from `BBProgram::map_bindings()`.
- Lookup discovery now iterates `prog.blocks()` plus `prog.sites_in_block(block)` (`map_inline.rs:1402-1424`) instead of scanning `find_map_lookup_sites(&program.insns)`.
- Map metadata analysis uses `MapInlineProgram` plus `PassContext` side inputs (`map_info.rs:131-145`) for production.
- Rewrite plans carry `SiteReplacement { pc, site, replacement }`; final mutation is direct `prog.replace_range` / `prog.replace_terminator` (`map_inline.rs:3286-3370`).
- Subprogram ranges are derived from `prog.subprog_blocks(FrameId)` (`map_inline.rs:459-492`).

## 3. LOC

- `map_inline.rs`: 5724 LOC. Delta from starting 5686 LOC: +38. Target 3500-4000 was not met.
- `map_info.rs`: 655 LOC. Delta from starting 634 LOC: +21.

## 4. BBProgram gaps

- No new BBProgram method was required for hard hint, verifier-guided, direct pseudo-map-value, map-in-map, or deletion/replacement paths.
- Guarded soft-fold hints need a BBProgram-native CFG insertion/splice for generated compare blocks and jumps. I did not add BBProgram APIs per scope. The path now fails closed with `soft fold requires BBProgram CFG insertion` instead of emitting raw in-block jumps.

## 5. Test status

- `cargo build --release --manifest-path bpfopt/Cargo.toml`: pass.
- `cargo test --release --manifest-path bpfopt/Cargo.toml map_inline`: pass, 32 map-inline related tests.
- `cargo test --release --manifest-path bpfopt/Cargo.toml`: pass, 217 tests.
- Requested command `cargo test --release --manifest-path bpfopt/Cargo.toml --test map_inline_tests --release 2>&1 | tail -5`: Cargo rejects it because `--release` is specified twice.
- `cargo test --release --manifest-path bpfopt/Cargo.toml --test map_inline_tests 2>&1 | tail -5`: Cargo reports no integration test target named `map_inline_tests`; these are unit tests.
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D warnings`: fails outside this scope in `const_prop.rs`, `bulk_memory_tests.rs`, and `pass_tests.rs`. No `map_inline` clippy errors remain.
