# Phase 3 BBProgram Migration Wave-4 Review

Date: 2026-05-10  
Repository: `/home/yunwei37/workspace/bpf-benchmark`  
Branch: `main`  
Mode: read-only audit, except writing this report.

## Evidence Commands

Commands used:

- `git status --short --branch`
- `rg` for wave-3 legacy names, PC-keyed map-inline state, BBProgram atomicity, kop registry, unchecked query APIs, helper duplication, and fallback patterns
- `wc -l`
- `git diff --numstat`
- `cargo test --release --manifest-path bpfopt/Cargo.toml`
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`

State caveat: the tree is still dirty and branch state is `main...origin/main [ahead 3]`. Several Phase 3 files are staged/modified (`MM`), and the wave-4 docs are untracked. Conclusions below use current filesystem line numbers.

Verification:

- `cargo test --release --manifest-path bpfopt/Cargo.toml`: PASS, `217` tests (`188 + 16 + 1 + 12`)
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`: PASS

Current LOC:

- `rg --files bpfopt/crates/bpfopt/src | xargs wc -l`: `26279 total`
- `rg --files bpfopt/crates/bpfopt/src | rg -v '(_tests\.rs$|/tests/|test_helpers\.rs$)' | xargs wc -l`: `22211 total`
- `wc -l bpfopt/crates/bpfopt/src/passes/map_inline.rs`: `5710`
- `wc -l bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`: `690`

## 1. Per-Pass Rating

Rating key, same as wave 3:

- A: production path operates on `BBProgram`; no old flat pass wrapper, no production `BpfProgram::new(insns)`, no full-program flat scan as edit identity, and mutations use BBProgram APIs.
- B: no old flat wrapper, but still carries a private linear/current-PC view, PC-keyed analysis state, or local address-plan compatibility layer.
- C: production path lowers to flat bytecode or relies on full-program flat rewrite shims.
- D: wrapper around the old flat `BpfProgram` pass.

| Pass | Wave 3 | Wave 4 | Delta | Evidence |
| --- | --- | --- | --- | --- |
| `noop.rs` | A | A | stayed | Direct `BBProgram` pass entry at `bpfopt/crates/bpfopt/src/passes/noop.rs:19`. |
| `dce.rs` | A | A | stayed | Direct `BBProgram` entry at `dce.rs:20`; deletes through `prog.delete_insn(def)?` at `dce.rs:42`. |
| `const_prop.rs` | A | A | stayed | Direct entry at `const_prop.rs:459`; replacement uses `prog.replace_range(...)` at `const_prop.rs:511`; logical-site scan at `const_prop.rs:590`. |
| `bounds_check_merge.rs` | A | A | stayed | Direct entry at `bounds_check_merge.rs:60`; mutates via `replace_range` / `delete_cond_branch` at `bounds_check_merge.rs:170-199`; scans `logical_sites_in_block` at `bounds_check_merge.rs:257`. |
| `branch_flip.rs` | A | A | stayed | Direct entry at `branch_flip.rs:214`; uses `replace_terminator` and `permute_blocks` at `branch_flip.rs:455-477`; scans blocks at `branch_flip.rs:517`. |
| `rotate.rs` | A | A | stayed | Direct entry at `rotate.rs:75`; scans `sites_in_block` at `rotate.rs:85-86`; applies with `replace_range` at `rotate.rs:152`. |
| `extract.rs` | A | A | stayed | Direct entry at `extract.rs:110`; scans `sites_in_block` at `extract.rs:122-123`; applies with `replace_range` at `extract.rs:178`. |
| `endian.rs` | A | A | stayed | Direct entry at `endian.rs:370`; scans `sites_in_block` at `endian.rs:383-384`; applies with `replace_range` at `endian.rs:451`. |
| `bulk_memory.rs` | A | A | stayed | Direct entry at `bulk_memory.rs:240`; scans blocks/sites at `bulk_memory.rs:298-305`; applies with `replace_range` at `bulk_memory.rs:279`. |
| `prefetch.rs` | A | A | stayed | Direct entry at `prefetch.rs:203`; scans `sites_in_block` at `prefetch.rs:358-359`; applies with `replace_range` at `prefetch.rs:277`. |
| `wide_mem.rs` | A | A | stayed | Direct entry at `wide_mem.rs:496`; uses per-block `block_body_linear_view` at `wide_mem.rs:514`; applies with `replace_range` at `wide_mem.rs:635`. |
| `skb_load_bytes.rs` | A | A | stayed | Direct entry at `skb_load_bytes.rs:80`; applies with `replace_range` at `skb_load_bytes.rs:111`; scans per-block body views at `skb_load_bytes.rs:124-125`. |
| `cond_select.rs` | A | A | stayed | Direct entry at `cond_select.rs:116`; mutates through `replace_diamond_with_insns` at `cond_select.rs:197`; scans blocks at `cond_select.rs:301`. |
| `ccmp.rs` | A | A | stayed | Direct entry at `ccmp.rs:160`; uses `replace_terminator`, `merge_linear_chain`, and `replace_range` at `ccmp.rs:276-304`; scans blocks at `ccmp.rs:406`. |
| `map_inline.rs` | B | B | stayed | The named wave-3 shims are gone, but production still carries a private current-PC layer and PC-keyed analyses. See below. |

`map_inline` checklist result:

- Clean: `rg "ProgramLinearView|MapInlineProgram|linear_insn_sites|lookup_call_pcs|by_call_pc|skipped_pcs|reference_at_pc|program\.linear|\.ok\(\)" bpfopt/crates/bpfopt/src/passes/map_inline.rs bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` returns no matches.
- Clean enough: `BpfProgram::new` appears only in `#[cfg(test)]` paths. `collect_map_references_with_bindings()` is `#[cfg(test)]` at `map_info.rs:166-188`; the other hits are tests at `map_info.rs:474`, `map_info.rs:518`, `map_info.rs:532`, and `map_info.rs:554`.
- Not clean: `MapInlineView` still stores flattened bytecode plus PC/site maps: `insns`, `pc_to_site`, `site_to_pc`, and related fields at `map_inline.rs:249-257`, populated by a current-PC reconstruction loop at `map_inline.rs:263-327`.
- Not clean: core map-inline records still retain production PC identity: `MapLookupSite.call_pc` / `map_load_pc`, `MapInMapChain.inner_call_pc` / `outer_alias_copy_pcs`, and `ConstantKey.materialization_pcs` / `r2_*_pc` at `map_inline.rs:1209-1238`; `R0UseClassification` still records PC vectors at `map_inline.rs:1252-1260`.
- Not clean: direct PC indexing remains in production rewrite decisions at `map_inline.rs:3586` and `map_inline.rs:4215`.
- Not clean: `HashMap<usize, &MapLookupSite>` is used to resolve PC inline hints at `map_inline.rs:2390-2403`, not just diagnostics.
- Not clean: `HashSet<usize>` remains for materialization PCs at `map_inline.rs:1753-1819` and `map_inline.rs:4655-4663`; those PCs are converted to sites by `sites_for_pc_iter()` / `attach_constant_key_sites()` at `map_inline.rs:1924-1949`.
- Not clean: large analyses still iterate `pc` over `program.insns`, for example map-in-map chain discovery at `map_inline.rs:1375-1455`, verifier-guided key extraction at `map_inline.rs:1459-1530`, direct map-load resolution at `map_inline.rs:4485-4561`, and R0-use classification at `map_inline.rs:5238-5365`.

Conclusion: `map_inline` did not actually move from B to A. It removed the old named `ProgramLinearView` wrapper and moved edit identity closer to `InsnSite`, but the production analysis substrate remains PC-first.

## 2. LOC Investigation

Current `map_inline.rs` is `5710` LOC. Wave 3 reported `5573`, so the file grew by `+137`.

The current unstaged wave-4 source diff explains the exact net:

- `git diff --numstat -- bpfopt/crates/bpfopt/src/passes/map_inline.rs`: `446` insertions, `309` deletions, net `+137`.
- `git diff --numstat -- bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`: `62` insertions, `27` deletions, net `+35`.

Where the `+137` came from:

- The old `ProgramLinearView` field was replaced by a larger local compatibility view: `insns`, `sites`, `site_positions`, `pc_to_site`, `site_insns`, `site_to_pc`, `site_to_frame`, `frame_bounds`, and `lookup_call_sites` at `map_inline.rs:249-257`.
- `MapInlineView::from_bbprogram()` now rebuilds a full linear instruction stream and bidirectional PC/site maps from BBProgram sites at `map_inline.rs:263-327`.
- New accessors and fail-fast bridge helpers were added: `site_for_pc`, `pc_for_site`, `insn_at`, `site_position`, and `subprog_bounds` at `map_inline.rs:332-369`.
- Site fields were added beside, not instead of, existing PC fields in `MapLookupSite`, `MapInMapChain`, `ConstantKey`, `FixedLoadUse`, and `R0UseClassification` at `map_inline.rs:1209-1260`.
- PC-to-site bridge helpers were added at `map_inline.rs:1924-1949`.
- The apply path is site-keyed now: `apply_replacements_and_deletions()` keys replacements and deletes by `InsnSite` at `map_inline.rs:3270-3314`, and `delete_site()` / `replace_site()` mutate BBProgram directly at `map_inline.rs:3315-3344`.

Was the old PC-keyed code deleted or does it coexist?

It coexists. Wave 4 deleted the old names and some apply-time PC deletion sets, but the deeper PC analyses still drive production behavior. Evidence:

- `program.insns` is still the analysis stream at `map_inline.rs:1375`, `map_inline.rs:1466`, `map_inline.rs:3789`, and `map_inline.rs:5238`.
- Loops still advance raw `pc` until `insns.len()` at `map_inline.rs:1383` and `map_inline.rs:5245`.
- Direct `program.insns[pc]` reads remain at `map_inline.rs:3586` and `map_inline.rs:4215`.
- PC-keyed hint resolution remains at `map_inline.rs:2390-2403`.
- PC materialization sets remain at `map_inline.rs:1753-1819` and `map_inline.rs:4655-4663`.

So the LOC increase is not surprising: wave 4 added a site-native layer and kept much of the old PC-keyed analysis underneath it.

## 3. Remaining P0/P1

Wave 3 had `3` P0 and `1` P1. Wave 4 fixed the three P0s.

Fixed P0: BBProgram atomicity

- `delete_insn()` clone-swaps: `let mut next = self.clone()` at `bbprogram_api.rs:21`, in-place mutation at `bbprogram_api.rs:22`, and `*self = next` only after success at `bbprogram_api.rs:23`.
- `delete_cond_branch()` clone-swaps at `bbprogram_api.rs:127-130`.
- `replace_terminator()` clone-swaps at `bbprogram_api.rs:155-162`.
- `permute_blocks()` clone-swaps at `bbprogram_api.rs:183-186`; validation/remap happens inside `permute_blocks_in_place()` at `bbprogram_api.rs:190-225`.

Fixed P0: kop duplicate registration

- `KopRegistry::new()` now returns `anyhow::Result<Self>` and propagates duplicate registration errors at `pass.rs:736-747`.
- Duplicate names now `bail!` instead of panicking at `pass.rs:812-829`.
- Panic-only `Default` is test-only at `pass.rs:731-735`.
- Production callers use `PassContext::try_baseline()` and `KopRegistry::unavailable()?` at `pass.rs:1089-1092`, `main.rs:725`, `main.rs:865`, and `main.rs:895`.

Fixed P0: unchecked query API gating

- Panic wrappers are `#[cfg(test)]`: `live_in()` at `bbprogram.rs:228-232`, `live_out()` at `bbprogram.rs:242-246`, `live_out_site()` at `bbprogram.rs:256-260`, and `btf_records()` at `bbprogram.rs:305-309`.
- Checked production APIs remain visible: `live_in_checked()` at `bbprogram.rs:234-240`, `live_out_checked()` at `bbprogram.rs:248-254`, `live_out_site_checked()` at `bbprogram.rs:262-269`, and `btf_records_checked()` at `bbprogram.rs:311`.

Remaining P0: none found.

Remaining P1:

1. `map_inline` remains B-rated. The wave-4 checklist still fails on production PC-indexed analysis and direct `program.insns[pc]` reads. Evidence is listed in section 1.

No new P0 was introduced by this wave. The new direct PC indexing is a migration-quality blocker for A-rating, but the observed `pc` sources are still produced by local scans/bounds and did not surface as a new fail-fast correctness P0 in this audit.

## 4. Convergence Verdict

Verdict: **progress**.

State:

- Pass ratings: `14A + 1B`
- P0: `0`
- P1: `1`

This is not converged because convergence requires `15A + 0 P0/P1`. It is not stuck because wave 4 fixed the wave-3 P0s and moved map-inline edit application and metadata references toward `InsnSite`. But the only non-A pass remains non-A, so Phase 3 should not be declared done.

## 5. Wave-5 Blockers and Narrow Fix Scope

Top blockers:

1. `MapInlineView` is still a private linear program view. It no longer imports `ProgramLinearView`, but it reconstructs equivalent flattened bytecode and PC/site maps at `map_inline.rs:249-327`.
2. Core map-inline data structs still carry both site and PC identity. `call_pc`, `map_load_pc`, `inner_call_pc`, `materialization_pcs`, `alias_copy_pcs`, `r2_*_pc`, and `null_check_pc` continue to drive planning at `map_inline.rs:1209-1260`.
3. The expensive analyses still use raw PC cursors over `program.insns`: map-in-map chain discovery, verifier key extraction, direct map-load resolution, and R0-use classification.
4. PC-to-site bridge helpers (`sites_for_pc_iter()` / `attach_constant_key_sites()`) are now the compatibility layer that hides the remaining migration debt.

Narrow wave-5 scope:

1. Convert core records to site-first: `MapLookupSite`, `MapInMapChain`, `ConstantKey`, `FixedLoadUse`, `R0UseClassification`, and `SoftNullHandler` should store `InsnSite` for edit/analysis identity; compute PC only at verifier/hint/diagnostic boundaries.
2. Replace `find_map_in_map_chain_for_outer()`, `find_direct_map_load_for_reg_before_pc_inner()`, `classify_r0_uses_with_options()`, and null-check window scans with same-frame/site-order iterators. Do not keep an `insns: Vec<BpfInsn>` analysis substrate inside `MapInlineView`.
3. Resolve PC inline hints once at the boundary into `InsnSite`, then delete `HashMap<usize, &MapLookupSite>` from the production planning path.
4. Delete `sites_for_pc_iter()` and `attach_constant_key_sites()` after the upstream analyses emit sites directly.
5. Keep the patch focused to `map_inline.rs` and `map_inline/map_info.rs`. Add a small BBProgram traversal helper only if it removes the local current-PC reconstruction rather than becoming another bridge.

## 6. Cross-Pass Duplicate Code, Abstractions, and Fallbacks

Duplicate/helper scan:

- No new wave-4 helper directly duplicates a `bbprogram_helpers.rs` helper by name.
- The existing `read_json_file()` duplicate remains in three places: shared helper at `bbprogram_helpers.rs:80`, main-local helper at `main.rs:1048`, and map-inline-local helper at `map_inline.rs:1200`.
- `MapInlineView` now locally reconstructs current-PC state even though BBProgram already exposes `current_site_pcs()` and `current_pc_sites()` at `bbprogram.rs:369-374`. BBProgram also still has `program_linear_view()` at `bbprogram.rs:439` and internal block slot helpers at `bbprogram.rs:550` / `bbprogram.rs:927`; map-inline has local `current_block_start_pcs()` / `current_subprog_bounds()` / `block_slot_len()` at `map_inline.rs:457-505`.

Fallback/legacy scan:

- `rg "ProgramLinearView|MapInlineProgram|linear_insn_sites|lookup_call_pcs|by_call_pc|skipped_pcs|reference_at_pc|program\.linear|\.ok\(\)" ...` found no map-inline/map-info matches.
- `MapInlineView::subprog_bounds()` is now fail-fast and returns `anyhow::Result` at `map_inline.rs:359-369`; the wave-3 whole-program fallback is gone.
- `git diff -U0 ... | rg "^\+.*(unwrap_or|unwrap_or_default|\.ok\(\)|fallback|fall back|legacy|compat|ProgramLinearView|BpfProgram::new|program\.insns\[pc\])"` found no new fallback/legacy additions. The only notable new additions matching that broader search were direct `program.insns[pc]` reads, which are rating evidence rather than a new fallback.

Bottom line: wave 4 did not introduce a new P0 fallback, but it did introduce/retain a compatibility layer that overlaps existing BBProgram current-PC capabilities and keeps `map_inline` B-rated.
