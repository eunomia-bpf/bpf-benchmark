# Phase 3 BBProgram Migration Architecture Review 2 - 2026-05-11

Verdict: NOT-CONVERGED

Method: I read the mandatory files end to end before running targeted confirmation scans. Grep output was used only to make line references complete after source reading.

## Gate Results

- `cd bpfopt && cargo build --release`: PASS, exit 0.
- `cd bpfopt && cargo test --release`: PASS, exit 0. Observed 217 tests passed plus 0 doctests.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: PASS, exit 0.
- `cd bpfopt && cargo fmt --all --check`: FAIL, exit 1. `crates/bpfopt/src/passes/prefetch.rs:177` needs rustfmt line wrapping for `prefetch_score_for_site(...)`.

Net LOC:

```text
$ find bpfopt/crates/bpfopt/src -name '*.rs' -not -name '*_tests.rs' -not -name 'test_helpers.rs' -not -name 'pass_tests.rs' -print0 | xargs -0 wc -l | tail -1
 18812 total
```

Baseline was 18994, so current non-test source is -182 LOC.

## A. Identity Opacity

- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:963` uses `start.block` to call `prog.block_frame(start.block)?`. This interprets an `InsnSite` field in pass code. Fix: add a `BBProgram::site_frame(site)` or frame-order iterator API and keep `InsnSite` opaque.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:985` uses `end.block` for the same frame lookup. Same fix as above.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2913` calls `prog.replace_terminator(replacement.site.block, terminator)`. Fix: provide `replace_terminator_at_site(site, terminator)` that checks terminator-ness internally.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2919` and `2929` read `site.block` to inspect and replace a terminator. Fix: expose `terminator_at_site(site)` and `replace_terminator_at_site`.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2948` reads `site.block` in `terminator_for_site_replacement`. Fix: expose a site-keyed terminator query.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3341` compares `null_check_site.block != call_site.block`. Fix: expose `same_block(a, b)` or a higher-level "immediate same-block successor" query.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4767` and `4785` call `prog.terminator(null_check_site.block)?`. Fix: expose a null-check successor API that takes the branch site.
- REAL: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:228`, `234`, `259`, and `263` use `jcc_site.block` or `start_site.block`. Fix: add site-keyed block split/query helpers so the pass never reads `InsnSite.block`.
- REAL: `bpfopt/crates/bpfopt/src/passes/ccmp.rs:307` uses `site.start_site.block`. Fix: same site-keyed terminator/split API.
- REAL: `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:146`, `156`, and `279` use `site.block`. Fix: expose "block containing site", grouped deletion, or branch deletion helpers that take `InsnSite`.
- REAL: `bpfopt/crates/bpfopt/src/passes/endian.rs:413`, `417`, and `443` use `start.block` or `site.block`. Fix: add next-body-site and fallthrough-successor APIs keyed by site.
- REAL: `bpfopt/crates/bpfopt/src/passes/extract.rs:146`, `150`, and `171` use `start.block` or `site.block`. Same fix as endian.
- FALSE-ALARM: `bpfopt/crates/bpfopt/src/passes/ccmp.rs:401`, `404`, `414`, `423`, `439`, and `443` access `BranchTerm.block`, a pass-local `BlockId` field, not `InsnSite.block` or a numeric identity field. It is not PC arithmetic.
- FALSE-ALARM: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:355` and `382` access `CondBranchShape.block`, a pass-local `BlockId` field built from `prog.blocks()` and used as a CFG node handle. It is not a hidden PC or raw `InsnSite` destructure.

No production pass directly accesses `InsnSite.idx`, `BlockId.0`, or `FrameId.0`.

## B. PC Arithmetic In Disguise

- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:78` defines public `MapReference.slot: usize`; `110` defines `MapBinding.pc_load: usize`; `158` computes it from `program.rep_site_slot(site)`; `163` stores it; `246` copies it back into `slot`. This is a renamed program PC/slot. Fix: report map references by `InsnSite` only and materialize PCs only in `PassManager::finalize_reports`.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:25-27` exposes `MapInlineHintAnchor::Pc(usize)`. `145-149` parses numeric anchors to a PC. `1499-1508` walks `prog.all_sites()` with `current_pc += insn_width(insn)`. `1700-1708` resolves that PC anchor during the pass. Fix: parse external PC hints at the lift/main boundary into side-input `InsnSite` or map-name anchors; pass code should not convert PC to site.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1007-1011` defines `position_in_sites(...) -> usize` over a program-order `Vec<InsnSite>`. This helper feeds program-order arithmetic in pass code. Fix: move these window queries into `BBProgram` and return opaque site iterators or semantic answers.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4090-4099` builds `sites = prog.all_sites().collect::<Vec<_>>()`, computes `min_removed_pos` and `lookup_pos`, then slices `sites[min_removed_pos..=lookup_pos]`. This is whole-program order arithmetic disguised as vector indexing. Fix: add a BBProgram query for "sites between these sites in same frame/path" or a specific lookup-pattern safety API.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4578-4612`, `4629`, `4639`, `4654`, `4660`, `4677`, and `4690` iterate a frame/program-order site vector with `pos += 1` and `pos = next_pos`. Fix: expose a BBProgram cursor/iterator for successor traversal instead of indexing a program-order vector in pass code.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4884-4895` repeats the same pattern for null-check window scanning using `position_in_sites`, `target_pos`, `pos`, and `sites[pos]`. Fix: move the null-check window traversal into BBProgram.
- REAL: `bpfopt/crates/bpfopt/src/passes/rotate.rs:87-100` accepts `admission_range: Range<usize>` from `prog.rep_admit_kinsn_site_window(...)`, uses `admission_range.end.checked_sub(1)`, and indexes `block_sites.get(last_idx)`. This is a BBProgram-derived body/program position leaking into the pass. Fix: have BBProgram return the final `InsnSite` or perform the admission plus live-out check behind an opaque method.
- REAL: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1517-1541` exposes `rep_admit_kinsn_site_window(...) -> Option<(BlockId, Range<usize>)>`. Even though the arithmetic is inside BBProgram, the returned `Range<usize>` is a direct leak of block-local instruction position. Fix: replace this API with site-keyed/semantic admission helpers.
- FALSE-ALARM: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:13-16` (`start_idx`, `old_len`) and the local `idx + 1` uses are block-local matching over `block_insns`/`block_sites`, not a PC alias. They do not come from `BBProgram` numeric identity fields.
- FALSE-ALARM: `bpfopt/crates/bpfopt/src/passes/ccmp.rs:343-370` uses `idx + 1` and `chain[idx - 1]` over a pass-local CFG chain vector. It does not derive a numeric PC or `InsnSite.idx` from `BBProgram`.

## C. Verifier And Profile Surface

- REAL: `bpfopt/crates/bpfopt/src/verifier_log.rs:17`, `24`, `30`, `35`, `46`, `56`, and `96` declare raw verifier types as `pub`: `VerifierInsnKind`, `VerifierValueWidth`, `Tnum`, `ScalarRange`, `VerifierInsn`, `RegState`, and `StackState`. Contract says these should be `pub(crate)` and invisible to production passes. Fix: make raw verifier structures crate-private and keep pass-facing typed projections in `BBProgram`.
- REAL: `bpfopt/crates/bpfopt/src/pass.rs:22-24` publicly re-export raw verifier types. This directly violates the pass surface: production passes should see only typed products such as `MapPtr`, `RegKind`, and `PrefetchHint`. Fix: remove the public re-export.
- REAL: `bpfopt/crates/bpfopt/src/pass.rs:453` exposes `PassContext.verifier_states: Arc<[VerifierInsn]>` to pass implementations. Even if current passes mostly avoid it, the surface still permits raw verifier reads. Fix: keep raw states at lift/PassManager only, then attach the typed oracle to `BBProgram`.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1228` binds `_r2_kind` only to test presence, and `1234` binds `_r2_bounds` but never uses it. These are discarded typed queries. Fix: either use the `RegKind`/bounds result in the key proof or remove the query and fail based on the real condition.
- FALSE-ALARM: production pass files do not import or name `RegState`, `Tnum`, `ScalarRange`, `StackState`, `VerifierInsn`, `VerifierOracle`, `PmuRecord`, or `PrefetchProfile` directly after reading. The remaining violation is the public surface in `pass.rs`/`verifier_log.rs`.

## D. JSON / IO At Pass Time

- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:19-21` defines pass-local `read_json_from_path` using `fs::read` and `serde_json::from_slice`.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:48-52` constructs `MapInlineCliPass` by parsing CLI args and reading map values inside the pass module.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:460` reads bpftool map show JSON through the pass-local loader.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:477-488`, `497`, and `513-519` read and parse bpftool map dump JSON in the pass module.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:544-553` reads and parses the optional inner-map-id supplement in the pass module.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:615-623` reads and parses `overlays.json` in the pass module.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:682` parses compressed overlay JSON in the pass module.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:940` reads `prog_info` JSON from `--map-ids`.

Fix: move all JSON/IO parsing to `main.rs`/lift-time side-input construction and pass only typed side-inputs through `PassContext`/`BBProgram`.

## E. BBProgram Internal Field Access

- REAL: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:50` leaves `ldimm64_second_slots` as `pub(crate)`, allowing pass modules to reach internal metadata directly.
- REAL: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:492-494` reads `prog.ldimm64_second_slots.get(&site)`. Fix: use `prog.ldimm64_second_slot(site)` and make the field private.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4345-4348` reads `prog.ldimm64_second_slots.get(&site)` while resolving pseudo-map-value origins. Fix: use a BBProgram method.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4465-4468` reads `prog.ldimm64_second_slots.get(&site)` in `decode_ldimm64`. Fix: use `prog.ldimm64_second_slot(site)`.

No production pass directly accessed `blocks` or `oracle_map`.

## F. Escape Patterns

- REAL: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:859-860` uses `i64::try_from(...).ok()?` in `proven_bounds_from_reg_state`. That silently converts an out-of-range unsigned bound into "no bounds". Fix: return `Result<Option<_>>` or explicitly preserve unsigned-only bounds; do not discard conversion errors.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:546` and `617` treat missing optional JSON side files as `Ok(())`. In combination with pass-local JSON loading, this is a fallback/optional side-input path hidden inside the pass. Fix: lift side inputs once and make optionality explicit in the typed input contract.
- TEST-ONLY: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:219`, `231`, `243`, and `458` use `panic!` inside `#[cfg(test)]` helper wrappers. These are not production pass violations.

No production pass `todo!()`, `unimplemented!()`, `unwrap_or_default`, `#[allow(dead_code)]`, or `#[ignore]` target was found in the mandatory pass files.

## G. Lifecycle Methods

- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2867` calls `reset_btf_to_current_pcs(&mut next)?`, and `2933-2934` wraps `prog.reset_btf_to_current_pcs()`. Contract says lifecycle methods should be invoked only by lift/lower/PassManager. Fix: make BTF reset part of the BBProgram mutation/lower pipeline or a PassManager post-pass step, not pass code.
- FALSE-ALARM: `bpfopt/crates/bpfopt/src/pass.rs:709` calls `program.invalidate_oracle()` in PassManager after instruction count changes. This is allowed by the lifecycle boundary.

No production pass call to `attach_side_inputs`, `invalidate_oracle`, `rebuild_use_def_after_mutation`, `attach_profile_data`, `attach_prefetch_profile_from_original_pcs`, or `attach_profile_from_annotations` was found.

## H. Report PC Conversion

- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1499-1508` implements `lookup_call_site_at_pc` by walking all sites and accumulating instruction widths. This is PC conversion in pass code. Fix: resolve external PC hints before pass execution.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:158` calls `program.rep_site_slot(site)` and stores the result as `pc_load`. Fix: do not compute report/current PCs in map-info analysis.
- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:218-226` embeds `binding.pc_load` in diagnostics, and `244-247` exposes it as `MapReference.slot`. Fix: store `InsnSite`; format current PCs only in the report sink.
- TEST-ONLY: `bpfopt/crates/bpfopt/src/test_helpers.rs:269-277` uses `report_prog.rep_site_slot(skip.site)` to materialize skip PCs for tests. The request explicitly allowed test helpers to use crate-visible APIs.
- OK: `bpfopt/crates/bpfopt/src/pass.rs:715-733` uses `prog.site_current_pc(report.site)` in `PassManager::finalize_reports`; this is the intended boundary.

## I. Helper Relocation Correctness

- OK: `bpfopt/crates/bpfopt/src/insn.rs:86-125` contains `PacketCtxLayout`, `PacketCtxLayoutScope`, and `packet_ctx_layout`, all `pub(crate)`.
- OK: `bpfopt/crates/bpfopt/src/insn.rs:644-704` contains `SimpleRegValue`, `advance_reg_state`, `advance_alu64_state`, and `advance_alu32_state`. `advance_reg_state` and `SimpleRegValue` are `pub(crate)`; the ALU helpers are private implementation details.
- OK: no `program_sites` or `control_flow_target_sites` helper remains in production source.
- OK: `bpfopt/crates/bpfopt/src/main.rs:1067-1071` has a private `read_json_file`, and pass files do not use that symbol.
- OK: `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs` does not exist in the filesystem.

No relocation violation found here.

## J. Single-Path Mutation Enforcement

- OK: the old public `replace_range(block, Range<usize>, ...)` API is gone. `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:49-80` exposes only `replace_range_at(site, len, replacement)`, and `82-89` keeps `replace_range_in_place` private.
- REAL: `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1517-1541` exposes `rep_admit_kinsn_site_window(...) -> Option<(BlockId, Range<usize>)>`, leaking mutation-window ranges to passes.
- REAL: `bpfopt/crates/bpfopt/src/passes/rotate.rs:87-100` holds and indexes a BBProgram-derived `Range<usize>` as described in section B.

No other pass-held `Range<usize>` derived from BBProgram state was found.

## K. CFG Mutation API Coverage

- OK with identity caveats: every production pass mutation I read goes through public BBProgram mutation methods: `replace_range_at`, `delete_insn`, `replace_terminator`, `split_block`, `merge_linear_chain`, `permute_blocks`, `delete_unreachable_blocks`, `delete_cond_branch`, or `replace_diamond_with_insns`.
- REAL by overlap with A: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2913` and `2929` call public `replace_terminator`, but they obtain the `BlockId` through `InsnSite.block`. The mutation primitive is public, but the call path still violates identity opacity. Fix: add site-keyed mutation methods.

No pass called lower-level private mutation primitives such as `replace_range_in_place` or metadata shifters.

## L. Map Inline Subdirectory Deep Audit

Files read: `bpfopt/crates/bpfopt/src/passes/map_inline.rs` and `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`.

Struct and enum definitions in `map_inline.rs`:

- `MapInlineHintAnchor` (`25-28`): `Pc(usize)` is a REAL PC alias.
- `MapInlineHintMode` (`30-33`): no `usize`.
- `MapInlineHint` (`35-39`): no `usize` field, but `anchor` can carry `Pc(usize)`.
- `MapInlinePass` (`40`): unit struct.
- `MapInlineCliPass` (`42-46`): no `usize`.
- `MapInlineCliArgs` (`75-139`): no `usize`.
- `MapSnapshot` (`303-309`): no `usize`.
- `ProgInfoMapIdsJson` (`311-314`): no `usize`.
- `BpftoolMapShowJson` (`316-325`): no `usize`; sizes are `u32`.
- `BpftoolMapEntryJson` (`327-335`): no `usize`.
- `InnerMapIdJson` (`338-341`): no `usize`.
- `BpftoolMapDumpSkipMarker` (`344-348`): no `usize`; sizes are `u64`.
- `BpftoolMapDumpSnapshot` (`350-354`): no `usize`.
- `BpftoolPerCpuValueJson` (`356-358`): no `usize`.
- `BpftoolMapValueJson` (`361-364`): no `usize`.
- `CompressedMapValuesJson` (`367-375`): `value_size: usize` at `369`, semantic byte length. Assignment/use at `754` and validation at `684-689` are byte-size semantics, not PC.
- `MapTypeJson` (`379-382`): no `usize`.
- `MapLookupSite` (`957-960`): no `usize`.
- `MapInMapChain` (`1014-1019`): no `usize`.
- `ConstantKey` (`1021-1031`): `width: usize` at `1023`, assigned from `key_width` at `1222-1224` and carried through `1258-1263`. This is semantic key width, not PC.
- `ExtractedConstantKey` (`1033-1036`): no `usize`.
- `KeyExtractionError` (`1038-1041`): no `usize`.
- `FixedLoadUse` (`1043-1048`): no `usize`.
- `R0UseClassification` (`1050-1055`): no `usize`.
- `ConstantRegValue` (`1057-1060`): no `usize`.
- `ConstantStackBytes` (`1062-1067`): no `usize`.
- `SnapshotMapValue` (`1069-1073`): no `usize`.
- `SiteReplacement` (`1075-1078`): no `usize`.
- `DirectMapValueLoadRewriteResult` (`1080-1084`): `sites_applied: usize` at `1082`, assigned from counts such as `3753`; semantic count, not PC.
- `KeyPointerOrigin` (`1087-1094`): no `usize`.
- `MapRefKey` (`1096-1099`): no `usize`.
- `SiteRewrite` (`1415-1422`): no `usize`.
- `SiteRewriteError` (`1424-1428`): no `usize`.
- `KernelMutableMaps` (`1444-1447`): no `usize`.
- `ResolvedInlineHints` (`1449-1451`): no `usize`.
- `HintedMapInMapRoute` (`1453-1456`): no `usize`.
- `ResolvedHintAnchor` (`1458-1461`): no `usize`.
- `BoundaryResolvedInlineHint` (`1463-1468`): no `usize`.
- `ResolvedInlineValue` (`1470-1473`): no `usize`.
- `ResolvedInlineHint` (`1475-1479`): no `usize`.
- `SoftNullHandler` (`3330-3332`): no `usize`.
- `MapInMapRewriteState` (`3408-3414`): no `usize`.

Other `usize` values in `map_inline.rs`:

- REAL: PC anchor parse and resolution at `145-149`, `1499-1508`, and `1700-1708`.
- REAL: program-order positions at `1007-1011`, `4090-4099`, `4578-4612`, and `4884-4895`.
- FALSE-ALARM: constants `R2_SETUP_LOOKBACK_LIMIT`, `REG_RESOLUTION_LIMIT`, `CONST_STACK_VALUE_LOOKBACK_LIMIT`, `MAP_INLINE_FIXED_POINT_MAX_ITERS`, and `VALUE_PREVIEW_BYTES` at `14-18` are semantic limits/sizes.
- FALSE-ALARM: `key_size`, `value_size`, `offset`, `budget`, `limit`, `slot_count`, and preview-length `usize` values throughout the file are byte sizes, counts, or bounded lookback counters, not program PCs.

Struct definitions in `map_info.rs`:

- `MapInfo` (`22-63`): no `usize` fields; map layout sizes are `u32`.
- `MapReference` (`76-84`): `slot: usize` at `78` is a REAL program PC/slot alias; `map_ordinal: usize` at `81` is semantic map index.
- `MapInfoResult` (`88-91`): no `usize`.
- `MapInfoAnalysis` (`103`): unit struct.
- `MapBinding` (`108-116`): `pc_load: usize` at `110` is a REAL program PC/slot alias; `map_ordinal: Option<usize>` at `114` is semantic map index.

Assignments in `map_info.rs`:

- REAL: `158` assigns `pc = program.rep_site_slot(site)`; `163` stores `pc_load: pc`; `246` stores `slot: binding.pc_load`.
- FALSE-ALARM: `184` parses `imm` to `usize` for a map-id index; `202` `map_id_count: usize` and `210` `BTreeMap<usize, Option<MapInfo>>` are map-order/index semantics, not PC.

## M. Architecture-Level Smells

- REAL: `bpfopt/crates/bpfopt/src/passes/map_inline.rs` is 4997 LOC. It contains CLI parsing, JSON snapshot IO, map metadata analysis coupling, hint resolution, key extraction, verifier-guided rewriting, CFG mutation, BTF reset, diagnostics, and compressed overlay logic. This size is not automatically wrong, but the discrete responsibilities are now hiding multiple contract violations. Fix: split loader/side-input parsing out first, then split map-info and rewrite logic behind BBProgram-facing APIs.
- REAL: `bpfopt/crates/bpfopt/src/pass.rs:18-20` publicly re-exports map-inline hint types from a pass module, including the PC-capable hint anchor. Fix: move external hint parsing types out of pass code or make the pass receive already-resolved opaque inputs.
- REAL: `bpfopt/crates/bpfopt/src/pass.rs:318-321` keeps both `sites_skipped: Vec<SkipReason>` and `site_skipped: Vec<SiteSkipReason>`, while `360-362` keeps `SkipReason { pc: usize }` public. Current production passes use `SiteSkipReason`, but the public PC skip channel still lets future passes bypass `PassManager::finalize_reports`. Fix: remove or crate-restrict the legacy PC path once callers are migrated.
- REAL: `bpfopt/crates/bpfopt/src/pass.rs:441-476` exposes a wide public `PassContext` with raw side-input fields, including raw verifier states and map snapshots. This makes pass modules responsible for side-input interpretation instead of BBProgram/lift. Fix: shrink the pass-facing context to policy/platform and typed handles; attach raw side inputs to BBProgram at lift.

## Final Top 10 Issues To Fix

1. Move all `map_inline` JSON/IO out of `passes/map_inline.rs` and into main/lift side-input construction.
2. Remove `MapInlineHintAnchor::Pc(usize)` from pass code; resolve external PC hints before pass execution.
3. Delete `MapReference.slot` and `MapBinding.pc_load`; map-info should carry `InsnSite`, not current PC/slot.
4. Remove pass-side program-order indexing in `map_inline` (`position_in_sites`, `lookup_pattern_removal_is_safe`, `classify_r0_uses_with_options`, `null_check_removal_window_is_trivial`) by adding BBProgram semantic traversal APIs.
5. Eliminate all production pass reads of `InsnSite.block`; add site-keyed BBProgram methods for terminator queries, same-block checks, splits, and replacements.
6. Make raw verifier types private/crate-private and remove their public re-export from `pass.rs`; hide `PassContext.verifier_states` from passes.
7. Replace discarded typed queries in `map_inline` (`_r2_kind`, `_r2_bounds`) with real proof logic or remove them.
8. Make `BBProgram::ldimm64_second_slots` private and migrate `const_prop` and `map_inline` to `ldimm64_second_slot(site)`.
9. Replace `rep_admit_kinsn_site_window` so it no longer returns `(BlockId, Range<usize>)`; fix `rotate` to consume an opaque site result instead of a range.
10. Move `reset_btf_to_current_pcs` out of `map_inline` and into the BBProgram/PassManager lifecycle boundary.

