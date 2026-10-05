# Phase 3 BBProgram Fix: branch_flip + prefetch

Date: 2026-05-11

## Gates

All commands run from `/home/yunwei37/workspace/bpf-benchmark`.

1. `cd bpfopt && cargo build --release`
   - PASS: `Finished release profile [optimized] target(s)`.

2. `cd bpfopt && cargo test --release`
   - PASS:
     - lib tests: `188 passed; 0 failed`
     - main tests: `16 passed; 0 failed`
     - `tests/bbprogram_roundtrip.rs`: `1 passed; 0 failed`
     - `tests/cli_pipeline.rs`: `12 passed; 0 failed`
     - doc tests: `0 passed; 0 failed`

3. `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`
   - PASS: `Finished release profile [optimized] target(s)`.

4. `rg "site_pc\(|site_current_pc\(" bpfopt/crates/bpfopt/src/passes/branch_flip.rs bpfopt/crates/bpfopt/src/passes/prefetch.rs`
   - PASS: zero matches.

5. `rg "HashMap<usize" bpfopt/crates/bpfopt/src/passes/prefetch.rs`
   - PASS: zero matches.

6. LOC:
   - `branch_flip.rs`: 638 -> 587
   - `prefetch.rs`: 648 -> 586
   - combined: 1286 -> 1173

## Code Changes

`branch_flip.rs`
- Removed PC window math from candidate discovery.
- Scans conditional block diamonds by `BlockId`, `Terminator`, adjacency, body-site presence, and `sites_in_block_with_terminator`.
- Replaced interior-target detection with block-range/site membership checks.
- Reports skips as `SiteSkipReason`; PC materialization is left to the report/test sink.

`prefetch.rs`
- Removed the pass-owned `HashMap<usize, PrefetchProfile>`.
- Profiled pass now carries the profile path; profile JSON is lifted to `BTreeMap<InsnSite, PrefetchProfile>` at run time.
- Alias tracking now stores pointer definition `InsnSite`s, not end slots.
- Insertion window selection uses BBProgram prefetch window helpers instead of pass-side slot windows.
- Reports skips as `SiteSkipReason`.

`bbprogram_lift.rs`
- Added `lift_prefetch_profiles_from_original_pc_strings`, which parses profile PC keys and converts them to `InsnSite` via `original_pc_to_site`.

`bbprogram.rs`
- Added prefixed `bf_*` helpers for branch-flip block/range validation and site-keyed skip construction.
- Added prefixed `pf_*` helpers for site-keyed prefetch profile attachment, post-anchor scans, insertion-window selection, and nearest insertion-site selection.

## PC-Removal Evidence

- No `site_pc(` or `site_current_pc(` calls remain in either migrated pass.
- No `HashMap<usize` remains in `prefetch.rs`.
- Additional scan for pass-local slot-window names also returned zero matches:
  `site_pc`, `site_current_pc`, `ptr_def_end_slot`, `def_end_slot`, `start_slot`, `end_slot`, `valid_start`, `target_slot`, `nearest_instruction_boundary`.

## Self-Rating

- `branch_flip`: A
- `prefetch`: A

Both passes are BBProgram-native in production paths: candidates and windows are expressed in blocks, terminators, and `InsnSite` ranges; PC conversion is outside the pass body.
