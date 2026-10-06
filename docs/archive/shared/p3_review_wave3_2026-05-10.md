# Phase 3 BBProgram Migration Wave-3 Review

Date: 2026-05-10  
Repository: `/home/yunwei37/workspace/bpf-benchmark`  
Branch: `main`  
Mode: read-only audit, except writing this report.

## Evidence Commands

Commands used:

- `git status --short --branch`
- `git diff bfa802c9..HEAD --stat`
- `rg` for legacy flat-mode, PC-keyed, helper, panic/fallback, and stale-comment patterns
- `wc -l`
- `cargo test --release --manifest-path bpfopt/Cargo.toml`
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`

State caveat: `git status --short --branch` still shows `main...origin/main [ahead 3]` with a large dirty/indexed tree. `git diff bfa802c9..HEAD --stat` is dominated by corpus JSON and docs, reporting `62619 insertions(+), 7 deletions(-)` across 33 files, so source conclusions below are from current filesystem line numbers.

Current source LOC:

- `rg --files bpfopt/crates/bpfopt/src | xargs wc -l`: `26061 total`
- `rg --files bpfopt/crates/bpfopt/src | rg -v '(_tests\.rs$|/tests/|test_helpers\.rs$)' | xargs wc -l`: `21993 total`
- `wc -l bpfopt/crates/bpfopt/src/passes/map_inline.rs ...`: `map_inline.rs` is `5573` LOC, `bbprogram_helpers.rs` is `173`, `pass.rs` is `1111`, `bbprogram.rs` is `1131`, `bbprogram_api.rs` is `800`

Verification:

- `cargo test --release --manifest-path bpfopt/Cargo.toml`: PASS, `217` tests (`188 + 16 + 1 + 12`)
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`: PASS

## 1. Per-Pass Rating

Rating key, same as wave 2:

- A: production path operates on `BBProgram`; no `lower(prog)` in pass body, no `BpfProgram::new(insns)`, no full-program `linear_insn_sites` scan, and mutations use BBProgram APIs.
- B: no old flat pass wrapper, but still carries a private linear view, PC-keyed analysis, or local address-plan layer.
- C: production path lowers to flat bytecode or relies on full-program flat scan/rewrite shims.
- D: wrapper around the old flat `BpfProgram` pass.

| Pass | Wave 1 | Wave 2 | Wave 3 | Delta vs wave 2 | Evidence |
| --- | --- | --- | --- | --- | --- |
| `noop.rs` | A | A | A | stayed | Direct `BBProgram` pass entry at `bpfopt/crates/bpfopt/src/passes/noop.rs:19`; no scan or mutation. |
| `dce.rs` | A | A | A | stayed | Runs on `BBProgram` at `dce.rs:20`, deletes with `prog.delete_insn(def)?` at `dce.rs:42`, and validates sites via `prog.blocks()` at `dce.rs:63`. |
| `const_prop.rs` | B | A | A | stayed | Entry is `BBProgram` at `const_prop.rs:459`; scans blocks at `const_prop.rs:481`; applies with `prog.replace_range(...)` at `const_prop.rs:511`; logical-site scan is at `const_prop.rs:590`. |
| `bounds_check_merge.rs` | B | A | A | stayed | Entry is `BBProgram` at `bounds_check_merge.rs:60`; edits use `replace_range` at `bounds_check_merge.rs:170` and `delete_cond_branch` at `bounds_check_merge.rs:199`; scan walks `prog.blocks()`/`logical_sites_in_block` at `bounds_check_merge.rs:250-257`. |
| `branch_flip.rs` | B | A | A | stayed | Rewrite uses BBProgram terminators and block permutation at `branch_flip.rs:455-477`; candidate scan uses BBProgram blocks at `branch_flip.rs:517`. |
| `rotate.rs` | C | A | A | stayed | Scans `prog.blocks()` / `prog.sites_in_block` at `rotate.rs:85-86`; applies with `replace_range` at `rotate.rs:152`. |
| `extract.rs` | C | A | A | stayed | Scans blocks/sites at `extract.rs:122-123`; applies with `replace_range` at `extract.rs:178`. |
| `endian.rs` | C | A | A | stayed | Scans blocks/sites at `endian.rs:383-384`; applies with `replace_range` at `endian.rs:451`. |
| `bulk_memory.rs` | C | A | A | stayed | Entry is `BBProgram` at `bulk_memory.rs:240`; scans blocks/sites at `bulk_memory.rs:298-305`; applies with `replace_range` at `bulk_memory.rs:279`. |
| `prefetch.rs` | C | A | A | stayed | Entry is `BBProgram` at `prefetch.rs:203`; inserts with `replace_range` at `prefetch.rs:277`; scans blocks/sites at `prefetch.rs:358-359` and site PC windows at `prefetch.rs:748-756`. |
| `wide_mem.rs` | C | A | A | stayed | Uses per-block `block_body_linear_view` at `wide_mem.rs:514`; applies with `replace_range` at `wide_mem.rs:635`; cross-block checks use BBProgram blocks at `wide_mem.rs:652`. |
| `skb_load_bytes.rs` | C | A | A | stayed | Entry is `BBProgram` at `skb_load_bytes.rs:80`; applies with `replace_range` at `skb_load_bytes.rs:111`; scans per-block body views at `skb_load_bytes.rs:124-125`. |
| `cond_select.rs` | C | A | A | stayed | Entry is `BBProgram` at `cond_select.rs:116`; rewrite is `replace_diamond_with_insns` at `cond_select.rs:197`; scan walks BBProgram blocks at `cond_select.rs:301`. |
| `ccmp.rs` | C | A | A | stayed | Entry is `BBProgram` at `ccmp.rs:160`; uses `replace_terminator`, `merge_linear_chain`, and `replace_range` at `ccmp.rs:276-304`; scans blocks at `ccmp.rs:406`. |
| `map_inline.rs` | D | B | B | stayed B | Old `MapInlineProgram`/`pc_to_site` adapter is gone, but production still carries `MapInlineView { linear: ProgramLinearView, site_to_pc, frame_bounds, lookup_call_pcs }` at `map_inline.rs:250-317`; it rebuilds that view each fixed-point round at `map_inline.rs:2543-2557`; deeper helpers still scan `program.linear.insns`, for example `map_inline.rs:1306-1387`, `map_inline.rs:1886-1950`, `map_inline.rs:4087-4111`, and `map_inline.rs:5107-5243`. |

Summary: wave 3 remains `14A + 1B`. There are still no C/D-rated passes. `map_inline` is the only non-A pass.

## 2. Remaining P0/P1/P2/P3

### P0 - correctness / safety

1. `map_inline` still has a production fallback that violates fail-fast.
   - Evidence: `MapInlineView::subprog_bounds()` converts `site_for_pc(pc)` to `.ok()` and falls back to `(0, self.linear.insns.len())` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:311-316`.
   - Risk: an invalid or non-site PC silently widens analysis to the whole program, which can cross frame/subprogram boundaries in key, alias, or stack scans.
   - Fix: make `subprog_bounds()` return `anyhow::Result<(usize, usize)>` and propagate errors. Do not default to whole-program bounds.

2. Several BBProgram mutation APIs are still non-transactional.
   - Evidence: `delete_insn()` removes the instruction at `bbprogram_api.rs:28` before fallible rebuild at `bbprogram_api.rs:38`; `delete_cond_branch()` mutates metadata/terminator at `bbprogram_api.rs:133-137` before fallible rebuild at `bbprogram_api.rs:138`; `replace_terminator()` mutates at `bbprogram_api.rs:150-154` before fallible rebuild at `bbprogram_api.rs:155`; `permute_blocks()` assigns `self.blocks`/`self.entry` at `bbprogram_api.rs:183-184` before fallible remap/rebuild at `bbprogram_api.rs:191-193`.
   - Production callers include `dce.rs:42`, `bounds_check_merge.rs:199`, `branch_flip.rs:455-477`, `ccmp.rs:276-304`, and `map_inline.rs:3191-3297`.
   - Wave 3 fixed the biggest offenders (`merge_linear_chain`, `remove_blocks`, and map-inline batch application), but the API is not uniformly clone-swap.

3. KOperation duplicate target registration still panics.
   - Evidence: `assert!(previous.is_none(), "duplicate kop target name {name}")` remains at `bpfopt/crates/bpfopt/src/pass.rs:820-828`.
   - Fix: return `Result` through registry construction and surface duplicate names as a friendly CLI error.

### P1 - design contract

1. `map_inline` is still B-rated.
   - It has no old flat wrapper, but it is still organized around current-PC dataflow and `ProgramLinearView`.
   - This is the only remaining B/C/D pass and blocks Phase 3 convergence under the stated verdict rule.

### P2 - LOC opportunities

1. Finish the `map_inline` site-native migration. The residual PC-keyed subsystems below are the largest real trim opportunity. Gross subsystem estimates overlap; realistic total trim is about `-600` to `-1000` LOC if the pass becomes site-first instead of PC-first.
2. Reuse or relocate shared JSON helpers. `bbprogram_helpers.rs:80-84` is used by `branch_flip.rs:131` and `prefetch.rs:120`, but `map_inline.rs` still has a local duplicate at `map_inline.rs:1147-1153`, used at `map_inline.rs:628` and `map_inline.rs:1129`; `main.rs` has another duplicate at `main.rs:1048`.
3. `BpfProgram`, `MapProvider`, `SnapshotMapProvider`, and `build_map_fd_bindings` are correctly `#[cfg(test)]` now (`pass.rs:291-324`, `pass.rs:371-429`, `pass.rs:534-561`), but they still add total LOC for map-info tests. Converting those tests to BBProgram or direct binding fixtures could remove another `-150` to `-250` total LOC.
4. Public unchecked liveness/BTF query APIs still panic but are currently test-only callers by `rg`. Evidence: `live_in`, `live_out`, `live_out_site`, and `btf_records` panic at `bbprogram.rs:228-304`; callers are tests only (`bbprogram_liveness_tests.rs`, `pass_tests.rs`, `bounds_check_merge_tests.rs`). Move them behind `#[cfg(test)]` or delete in favor of checked APIs.

### P3 - polish

1. Stale `IMPL:` breadcrumbs remain in tests, for example `analysis/bbprogram_map_refs_tests.rs:14`, `analysis/bbprogram_site_scan_tests.rs:12`, `analysis/bbprogram_cfg_tests.rs:20`, `pass_tests.rs:22`, `pass_tests.rs:317`, `passes/mod_tests.rs:87`, and `passes/map_inline_tests.rs:580`.
2. `docs/bbprogram-architecture-design.md` still describes `legacy_cleanup` and temporary legacy implementation stages at `docs/bbprogram-architecture-design.md:326`, `docs/bbprogram-architecture-design.md:345-356`.
3. `bbprogram_helpers.rs` is an analysis module but now contains generic JSON/profile/pass helpers. That is acceptable short-term, but a neutral shared helper module would be cleaner if more non-BBProgram utilities are added.

## 3. `map_inline` Residual Debt

Even after the wave-3 `-151` LOC trim, `map_inline.rs` is still `5573` LOC and B-rated because the central abstraction is still current-PC indexed.

Remaining PC-keyed subsystems:

1. Linear current-PC substrate.
   - Evidence: `MapInlineView` stores `linear: ProgramLinearView`, `site_to_pc`, `frame_bounds`, and `lookup_call_pcs` at `map_inline.rs:250-317`; current subprogram bounds are computed from flattened block start PCs at `map_inline.rs:404-442`; block slot lengths are recomputed at `map_inline.rs:444-453`.
   - Trim potential: `-120` to `-220` LOC, plus one P0 fix, by moving to site/frame queries and returning `Result` for bounds.

2. Map metadata/reference analysis.
   - Evidence: `MapReference` is keyed by `pc` at `map_inline/map_info.rs:87-107`; production analysis scans `program.linear.insns` at `map_inline/map_info.rs:131-144`; `collect_map_bindings()` walks a flat PC loop at `map_inline/map_info.rs:192-215`.
   - Trim potential: `-80` to `-140` LOC by keying map references by `InsnSite` and preserving PC only as diagnostic/original-coordinate data.

3. Lookup discovery and direct map-load resolution.
   - Evidence: lookup discovery maps sites back to PCs at `map_inline.rs:1265-1288`; direct map-load resolution scans backwards through flat PCs at `map_inline.rs:4346-4437`; generic previous-PC helpers live at `map_inline.rs:4737-4767`.
   - Trim potential: `-120` to `-200` LOC with a BBProgram block/frame predecessor-site iterator.

4. Verifier-guided key and stack materialization.
   - Evidence: verifier state matching is `call_pc` keyed at `map_inline.rs:1389-1471`; occurrence extraction and stack materialization operate over `insns: &[BpfInsn]` plus `call_pc`/bounds at `map_inline.rs:1474-1795`; R2 setup and constant-reg helpers scan previous flat PCs at `map_inline.rs:4545-4947`.
   - Trim potential: `-220` to `-350` LOC if key extraction takes a call `InsnSite`, a frame-local site cursor, and a separate verifier-PC coordinate.

5. Inline hint resolution.
   - Evidence: `ResolvedInlineHints` is `by_call_pc: HashMap<usize, ...>` at `map_inline.rs:1849-1879`; hint resolution builds `sites_by_pc` at `map_inline.rs:2036-2040`; PC anchors are validated against `program.linear.insns.get(call_pc)` at `map_inline.rs:2278-2297`; resolved hints are inserted by `call_pc` at `map_inline.rs:2374-2438`.
   - Trim potential: `-100` to `-180` LOC by resolving user PC anchors once into `InsnSite` and keeping the raw PC only for diagnostics.

6. Rewrite planning and deletion sets.
   - Evidence: `SiteRewrite` still stores `call_pc` and `skipped_pcs: HashSet<usize>` at `map_inline.rs:1806-1813`; `site_replacement()` converts PC to site at `map_inline.rs:1830-1839`; the round loop reasons over `skipped_pcs` at `map_inline.rs:2655-3100`; skipped PCs are converted back to sites at `map_inline.rs:3053-3058`.
   - Trim potential: `-180` to `-300` LOC by representing planned edits as `InsnSite`/logical-site sets from the start.

7. Direct pseudo-map-value constantization.
   - Evidence: scan is now BBProgram-site based at `map_inline.rs:4098-4103`, but origin resolution immediately drops to `resolve_key_pointer_origin(&program.linear.insns, pc, ...)` at `map_inline.rs:4108-4111`; map references are still resolved by `MapRefKey`/PC at `map_inline.rs:4246-4264` and `map_inline.rs:4769-4881`.
   - Trim potential: `-120` to `-220` LOC by using a site-keyed def/origin analysis instead of flat backward scans.

8. R0 use, null-check, and lookup-removal window analysis.
   - Evidence: `build_site_rewrite()` builds PC sets at `map_inline.rs:3403-3535`; hard/soft/null handling uses `program.linear.insns[...]` at `map_inline.rs:3544-3678`; map-in-map rewrite builds outer/inner PC sets at `map_inline.rs:3742-3999`; lookup-removal safety scans flat PCs at `map_inline.rs:4482-4528`; R0 use classification is a flat forward scan at `map_inline.rs:5107-5243`; null-check guarded window analysis is flat PC based at `map_inline.rs:5428-5495`.
   - Trim potential: `-250` to `-450` LOC, overlapping with items 4 and 6, once lookup-removal is expressed as same-block or same-frame site windows.

Soft-fold status: still fail-closed, not implemented. Evidence: `build_soft_hint_site_rewrite()` validates the preconditions and returns `soft fold requires BBProgram CFG insertion` at `map_inline.rs:3604-3654`. This is acceptable as a guarded behavior, but it is not A-grade migration work.

## 4. `bbprogram_helpers.rs` Audit

Current helper file: `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs`.

Export shape:

- All shared helpers are `pub(crate)`, not public API. Re-export is crate-private at `analysis/mod.rs:18-21`.
- Private internals remain private: `advance_alu64_state()` at `bbprogram_helpers.rs:144`, `advance_alu32_state()` at `bbprogram_helpers.rs:156`, and `combine_ldimm64()` at `bbprogram_helpers.rs:169`.

Callers:

- `block_slot_offset()` at `bbprogram_helpers.rs:28` is used by `rotate.rs`, `bulk_memory.rs`, `extract.rs`, and `endian.rs`.
- `site_current_pc()` at `bbprogram_helpers.rs:39` is used by `rotate.rs`, `bulk_memory.rs`, `prefetch.rs`, `extract.rs`, and `endian.rs`.
- `packet_ctx_layout()` plus `PacketCtxLayoutScope` at `bbprogram_helpers.rs:16-78` are used by `bounds_check_merge.rs:69`, `prefetch.rs:297`, and `skb_load_bytes.rs:86`.
- `read_json_file()` at `bbprogram_helpers.rs:80` is used by `branch_flip.rs:131` and `prefetch.rs:120`.
- `annotations_from_profile()` at `bbprogram_helpers.rs:86` is used by `branch_flip.rs:78` and `prefetch.rs:79`.
- `SimpleRegValue` and `advance_reg_state()` at `bbprogram_helpers.rs:104-142` are used by `bulk_memory.rs` and `skb_load_bytes.rs`.

Dead-helper check:

- No dead helpers were found. `cargo clippy --all-targets -- -D dead_code -D warnings` is clean.
- The previous dead `BBProgramAddressView` is gone.

Visibility judgment:

- No helper should become `pub`; crate-private is the right ceiling.
- Nothing obviously needs to be made private inside the module beyond the internals that already are private.
- The only cleanup concern is placement/naming: `read_json_file()` and `annotations_from_profile()` are shared pass utilities, not BBProgram-specific analysis helpers. That is polish, not correctness.

## 5. Convergence

Progression:

| Wave | A-rated passes | Non-A passes | P0/P1 state |
| --- | ---: | ---: | --- |
| Wave 1 | 2 | 13 (`3B + 9C + 1D`) | Major migration blockers remained; exact issue count was not restated in the read-first wave-2 review. |
| Wave 2 | 14 | 1 (`map_inline` B) | Wave-2 review listed `6` P0 and `2` P1 items. |
| Wave 3 | 14 | 1 (`map_inline` B) | This audit finds `3` P0 and `1` P1 item. |

Fixed since wave 2:

- `cargo clippy --all-targets -D dead_code -D warnings` is clean.
- `merge_linear_chain()` is clone-swap atomic at `bbprogram_api.rs:196-200`.
- `remove_blocks()` is clone-swap atomic at `bbprogram_api.rs:479-483`.
- `apply_map_inline_edit()` is clone-swap atomic at `map_inline.rs:3129-3145`.
- `BpfProgram`, `MapProvider`, `SnapshotMapProvider`, and `build_map_fd_bindings` are test-gated at `pass.rs:291-324`, `pass.rs:371-429`, and `pass.rs:534-561`.
- Duplicate helpers were hoisted into `bbprogram_helpers.rs`.

Verdict: **progress**.

Reason: wave 3 made real progress, but convergence requires `0` B/C/D passes. `map_inline` is still B-rated, and there are still `3` P0 fail-fast/atomicity issues. Do not declare Phase 3 done yet. Run one narrow wave 4.

## 6. Next Wave Plan

Recommended wave 4:

1. Codex 1 - BBProgram fail-fast and atomicity lane.
   - Scope: `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`, `bpfopt/crates/bpfopt/src/pass.rs`, targeted tests only.
   - Tasks: clone-swap `delete_insn`, `delete_cond_branch`, `replace_terminator`, and `permute_blocks`; convert duplicate kop-name registration panic into `Result`; delete or `#[cfg(test)]` unchecked panic APIs if production still has no callers.
   - Risk: medium. Expected LOC delta: neutral to `+60`, with possible total LOC reduction if test-only APIs are removed.

2. Codex 2 - `map_inline` B-to-A core.
   - Scope: `bpfopt/crates/bpfopt/src/passes/map_inline.rs` lines `250-1839`, `4346-4947`, and `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`.
   - Tasks: make `MapInlineView::subprog_bounds()` fail-fast; convert map references and lookup/key extraction to `InsnSite` keyed data; remove `lookup_call_pcs`; keep raw PC only for diagnostics/verifier correlation.
   - Risk: high. Expected LOC delta: `-250` to `-450`.

3. Codex 3 - `map_inline` rewrite-plan cleanup, after Codex 2's site types are settled.
   - Scope: `bpfopt/crates/bpfopt/src/passes/map_inline.rs` lines `1806-4245` and `4482-5573`.
   - Tasks: replace `skipped_pcs: HashSet<usize>` and `by_call_pc` rewrite planning with `InsnSite` sets; make lookup-removal and null-check windows use same-block/frame site iterators; delete PC-to-site conversion at apply time.
   - Risk: high and likely conflicts with Codex 2 if run fully in parallel. If strict parallelism is required, run Codex 1 and Codex 2 first, then Codex 3 as the follow-up integration lane.

## 7. Top Blockers

1. `map_inline` still conflates mutable current PCs, verifier/original PC coordinates, diagnostics, and edit identity. Until those are separated, the pass keeps needing `ProgramLinearView` and PC-keyed helper layers.
2. BBProgram does not yet expose enough site-native traversal/dataflow utilities for map-inline's deeper analyses: frame-bounded previous-site scans, alias/key origin queries, and same-block/null-check window iterators.
3. Mutation API atomicity is only partially normalized. Wave 3 fixed the largest operations, but production passes still call smaller fallible mutators that can leave partial state if a rebuild/remap fails.
4. The remaining work is concentrated in one large file. `map_inline.rs` is large enough that parallel edits are conflict-prone unless the wave explicitly splits analysis/type changes from rewrite-plan changes.
