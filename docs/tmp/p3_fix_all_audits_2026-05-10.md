# Phase 3 BBProgram Final Cleanup Fix

Date: 2026-05-10
Branch: main
Commit: none

## Summary

- Final non-test LOC: 20680, target <= 21099, delta from 22099: -1419.
- Verification passed:
  - `cargo build --release --manifest-path bpfopt/Cargo.toml`
  - `cargo test --release --manifest-path bpfopt/Cargo.toml` (217 tests: 188 lib + 16 main + 1 roundtrip + 12 CLI)
  - `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`
  - `target/release/bpfopt list-passes` printed 15 passes
  - DCE smoke command exited 0

## LOC Running Total

- Start: 22099.
- After deleting linear views / adding checked BBProgram site APIs: 22033.
- After pass wrapper / fallback / fail-fast cleanup before test relocation: 21905.
- After moving inline test modules to excluded `*_tests.rs`: 20608.
- After final PassManager, BTF, map_inline, ccmp cleanup: 20680.

## Fresh-Eyes Section 12

- 1. Delete `program_linear_view`: yes. Deleted `ProgramLinearView` / `BlockBodyLinearView`; no remaining `rg` hits. Replacement BBProgram APIs are in `bbprogram.rs:280`, `bbprogram.rs:285`, `bbprogram.rs:474`, and call sites in `wide_mem.rs:512`, `skb_load_bytes.rs:128`.
- 2. Delete old linear kop subprogram helper in `pass.rs`: yes. Removed old `kop_candidate_subprog_starts` / flat `kop_replacement_subprog_skip_reason`; the only remaining helper is BBProgram-native at `bbprogram.rs:348`.
- 3. Replace `block_body_linear_view`: yes. `wide_mem` uses `sites_in_block` at `wide_mem.rs:512`; `skb_load_bytes` uses `sites_in_block` at `skb_load_bytes.rs:128`; no remaining view hits.
- 4. Add BBProgram helpers and delete local copies: yes. Added slot/site helpers at `bbprogram.rs:429`, `bbprogram.rs:474`, `bbprogram.rs:534`, `bbprogram.rs:575`; ccmp block-remap helpers at `bbprogram.rs:435` and `bbprogram.rs:449`; pass-local copies deleted.
- 5. CFG rebuild and site enumeration fail-fast: yes. Mutation paths propagate `rebuild_cfg_edges()?` at `bbprogram_api.rs:151`, `bbprogram_api.rs:179`, `bbprogram_api.rs:224`, `bbprogram_api.rs:409`, `bbprogram_api.rs:556`; CFG rebuild bails on invalid successors at `bbprogram.rs:617`; logical site enumeration validates blocks at `bbprogram.rs:696`.
- 6. Canonicalize-map-refs contract: yes. Explicit raw-Vec exemption documented at `main.rs:444`.
- 7. Simplify production `PassManager` out of single-pass CLI path: yes. CLI now builds one pass and calls `run_pass_once` at `main.rs:313`; pass bookkeeping is shared at `pass.rs:926`. `PassManager` remains for tests/library pipelines at `pass.rs:914`.
- 8. Verifier oracle absence explicit for `const_prop` / `wide_mem`: yes. `const_prop` handles `None` explicitly at `const_prop.rs:477`; `wide_mem` uses `Option` at `wide_mem.rs:505`.
- 9. `map_inline` unknown-byte/key defaults: yes. `ConstantKey.stack_off` is `Option<i16>` at `map_inline.rs:1123`; materialization errors propagate via `materialization_for_snapshot_key` at `map_inline.rs:1582`; key-pointer resolution now returns `Option` for non-candidates and errors only for hard failures at `map_inline.rs:4765`.
- 10. Pass-equivalence restore: skipped by user request.
- 11. BTF remap ownership near lowering: yes. Byte-record remapping moved to `bbprogram_lower.rs:54`; missing deleted records are documented/drop-only there, malformed surviving order bails.
- 12. Git artifacts: skipped by user request.

## X1 Audit

- noop wrapper: yes. Deleted `noop::run_on_bbprogram` and registry wrapper export; no remaining `run_noop_on_bbprogram` hit.
- const_prop wrapper/helpers: yes. Inlined `run_on_bbprogram_inner`; hoisted shared helpers to `insn.rs:735`, `insn.rs:739`, `insn.rs:751`; const_prop call sites at `const_prop.rs:723`, `const_prop.rs:789`, `const_prop.rs:905`.
- bounds_check_merge duplicate helpers / PC loop: yes. Uses `prog.is_terminator_site` and `sites_in_frame_pc_range` at `bounds_check_merge.rs:486`; program length uses `program_slot_len` through BBProgram.
- branch_flip PC interval scan: yes. Uses `sites_in_frame_pc_range` at `branch_flip.rs:281`.
- map_inline wrappers/defaults: yes. Deleted `run_bbprogram`, `insert_materialization_site`, `missing_snapshot_anyhow`, and `supports_direct_value_inline`; direct access API is `supports_direct_value_access` at `map_info.rs:54`. Map-inline site scans use BBProgram sites at `map_inline.rs:1225` and `map_inline.rs:4145`.
- ReJIT filtering P0: verified. No bpfopt ReJIT filtering implementation was added or changed.

## X2 Audit

- rotate/extract/endian kop subprogram helper duplication: yes. All use BBProgram helper `kop_replacement_subprog_skip_reason` at `bbprogram.rs:348`; representative call sites: `rotate.rs:99`, `extract.rs:137`, `endian.rs:403`.
- extract/endian cross-block scan fail-fast and PC map removal: yes. Both use `site_at_current_pc` instead of `current_pc_sites`: `extract.rs:201`, `endian.rs:472`.
- bulk_memory fallbacks: yes. Reset helper uses `should_reset_linear_state_at_block` at `bulk_memory.rs:299`; invalid widths bail via `width_class` / `width_bytes` at `bulk_memory.rs:685` and `bulk_memory.rs:775`; match routines propagate `Result` at `bulk_memory.rs:380` and `bulk_memory.rs:462`.
- prefetch duplicate helpers / silent errors: yes. Insert selection and range checks return `Result`: `prefetch.rs:600`, `prefetch.rs:647`, `prefetch.rs:668`, `prefetch.rs:689`; reset helper uses BBProgram at `prefetch.rs:468`.
- endian fallback/legacy wording: yes. Removed fallback/legacy comment wording; no production `legacy` / `fallback` hits remain outside tests.

## X3 Audit

- wide_mem `block_body_linear_view` and oracle default: yes. Uses `sites_in_block` at `wide_mem.rs:512` and verifier-state `Option` at `wide_mem.rs:505`.
- skb_load_bytes P0 state leak: yes. Per-block linear state reset uses `should_reset_linear_state_at_block` at `skb_load_bytes.rs:125`; body iteration uses `sites_in_block` at `skb_load_bytes.rs:128`.
- cond_select unreachable arm: yes. `unreachable!()` removed; register value returns directly at `cond_select.rs:672`.
- ccmp wrapper/over-specific checks/remap helpers: yes. `split_off(0)` and impossible mode check removed; packed call emitted directly at `ccmp.rs:282`; remaps hoisted to BBProgram and used at `ccmp.rs:275`, `ccmp.rs:316`.
- PC-keyed production scans: yes for audited pass paths. `current_pc_sites` was deleted; remaining current-PC lookup goes through `site_at_current_pc` at `bbprogram.rs:575`.

## Cross-Pass Helpers Hoisted

- LDIMM64 decode: `const_prop` / `map_inline` / helper copies -> `decode_ldimm64_value` in `insn.rs:735`.
- Constant scalar load emission: `const_prop` / `map_inline` copies -> `emit_scalar_const_load` in `insn.rs:739`.
- Binary ALU constant evaluation: `const_prop` / `map_inline` copies -> `eval_binary_alu_const` in `insn.rs:751`.
- Block/site slot helpers: local pass logic -> `BBProgram::{block_slot_bounds, program_slot_len, site_at_current_pc, is_terminator_site}` in `bbprogram.rs`.
- Linear-state reset helper: `bulk_memory`, `prefetch`, `skb_load_bytes` copies -> `BBProgram::should_reset_linear_state_at_block` at `bbprogram.rs:129`.
- ccmp block remap helpers: local ccmp helpers -> `BBProgram::remap_block_after_insert` / `remap_block_after_remove` at `bbprogram.rs:435` and `bbprogram.rs:449`.

## Wrappers Deleted

- `noop::run_on_bbprogram`: deleted from `passes/noop.rs`.
- `run_noop_on_bbprogram`: deleted from `passes/mod.rs`.
- `const_prop::run_on_bbprogram_inner`: deleted; body lives in `const_prop.rs:474`.
- `MapInlinePass::run_bbprogram`: deleted; body lives in `map_inline.rs`.
- `insert_materialization_site`: deleted; insertion is direct at call site.
- `missing_snapshot_anyhow`: deleted; call sites construct `SiteRewriteError::MissingSnapshot` directly.
- `MapInfo::supports_direct_value_inline`: deleted; use `supports_direct_value_access`.
- `BBProgram::try_split_block`: deleted; callers use `split_block`.

## Fallback / Legacy / Silenced Patterns Fixed

- Production search for `unwrap_or`, `unwrap_or_default`, `.ok()`, `unreachable!`, `legacy`, and `fallback` is clean except four `#[cfg(test)]` BBProgram convenience wrappers.
- `const_prop` no longer defaults verifier states through `unwrap_or(&[])`; it explicitly returns unchanged when absent and uses real oracle data when present.
- `wide_mem` no longer defaults verifier states through `unwrap_or(&[])`; BTF-pointer filtering only runs when states exist.
- `map_inline` no longer fabricates `stack_off=0` for hard hints; unknown/non-candidate pointer origins are represented as `None`, and hard materialization/snapshot failures still return errors.
- `bulk_memory` invalid width classes now bail instead of becoming zero; live-out and range errors propagate.
- `prefetch` no longer uses invalid-block empty iterator behavior or warning-style range skips.

## Test Relocation

Moved inline test modules out of LOC-counted production files:

- `main.rs:1095` -> `main_tests.rs`
- `verifier_log.rs:888` -> `verifier_log_tests.rs`
- `insn.rs:823` -> `insn_tests.rs`
- `bbprogram_lift.rs:368` -> `bbprogram_lift_tests.rs`
- `map_info.rs:368` -> `map_info_tests.rs`

## Skipped / Blocked

- Skipped: pass-equivalence restore, explicitly out of scope for this run.
- Skipped: git artifact cleanup, explicitly out of scope for this run.
- Blocked: none.

