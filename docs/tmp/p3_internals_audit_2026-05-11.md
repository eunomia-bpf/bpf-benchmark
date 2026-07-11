# P3 Internals Audit — BBProgram / pass.rs / main.rs / verifier_log.rs

Date: 2026-05-11

Scope: read-only audit of non-pass files in `bpfopt/crates/bpfopt/src/` for residual bloat after Phase 3 BBProgram migration. Captured by codex run `btuzkl933` (originally written to log; rescued here because the read-only constraint prevented direct file write).

## Executive Verdict

The core pipeline is coherent: `main.rs` loads inputs and calls lift [main.rs:303], lift builds `BBProgram` [bbprogram_lift.rs:140], pass execution mutates it through `run_pass_once()` [pass.rs:706], and lower emits bytecode [bbprogram_lower.rs:12].

The leaks are visible but fixable:

- `BBProgram` contains pass-named helpers.
- `BBProgram` imports `MapInlineSideInput` from a pass module [bbprogram.rs:13].
- `PassContext` carries too many pass-specific side inputs.
- `main.rs` owns too much map-inline JSON/snapshot parsing.
- Old verifier/oracle accessors remained after typed verifier queries landed.

**The biggest issue is not the lift/pass/lower pipeline; it is pass-specific knowledge leaking into `BBProgram`, `PassContext`, and `main.rs`.**

## A. BBProgram Surface

Must-fix:
- Delete zero-call production APIs: `entry()` [bbprogram.rs:137], `block_body_len()` [bbprogram.rs:152], `block_body_insns()` [bbprogram.rs:180], `body_insn_window()` [bbprogram.rs:194], `block_entry_site()` [bbprogram.rs:614], `kop_registry()` [bbprogram.rs:499], `delete_cond_branch_at_site()` [bbprogram_api.rs:145], `split_block_at_site()` [bbprogram_api.rs:394]. Estimated delta: `-70..100 LOC`.
- Delete old typed-verifier/oracle residue: `reg_known_map_ptr()` [bbprogram.rs:321], `reg_proven_bounds()` [bbprogram.rs:331], `MapPtr` [pass.rs:27], `map_ptr_from_reg_state()` [bbprogram.rs:935], `proven_bounds_from_reg_state()` [bbprogram.rs:943]. No production callers. Estimated delta: `-60..80 LOC`.
- Gate or delete test-only liveness/oracle helpers: `oracle()` [bbprogram.rs:304], `live_out_site()` [bbprogram.rs:270], `reaching_defs()` [bbprogram.rs:283], `dominance()` [bbprogram.rs:243]. Estimated delta: `-40..70 LOC`.

Nice-to-have:
- `block_count()` [bbprogram.rs:143] has one weak caller for capacity sizing in `branch_flip.rs:311`; replace with iterator sizing or local count. Estimated delta: `-3 LOC`.
- `live_in`/`live_in_checked` and `live_out`/`live_out_checked` [bbprogram.rs:246-269] are only test-facing wrappers over checked APIs. Collapse or keep entirely under `cfg(test)`. Estimated delta: `-15..25 LOC`.
- `btf_records`/`btf_records_checked` [bbprogram.rs:514-525] are both `cfg(test)` and redundant. Keep one. Estimated delta: `-8 LOC`.

Keep:
- `sites_in_block()` [bbprogram.rs:562] and `sites_in_block_with_terminator()` [bbprogram.rs:566] are not duplicates. Body-only callers differ from terminator-aware callers.
- `successors()` [bbprogram.rs:221] and `dataflow_successors()` [bbprogram.rs:844] are not duplicates. `dataflow_successors()` intentionally treats calls differently for use-def flow [bbprogram.rs:1092].
- `insn_at()` [bbprogram.rs:625] and `insn()` [bbprogram.rs:634] serve different contracts: optional probing vs fail-fast mutation validation.
- `copied_body_insns()` [bbprogram.rs:191] is still used by `rotate.rs` and `bulk_memory.rs`; `block_body_insns()`/`body_insn_window()` are dead.

## B. Pass-Specific Leakage

Must-fix / high ROI:
- Branch-flip helpers live on `BBProgram`: `bf_skip_reason()` [bbprogram.rs:1471], `bf_blocks_are_adjacent()` [bbprogram.rs:1480], `bf_block_range_has_body_site()` [bbprogram.rs:1490], `bf_validate_flipped_branch_deltas()` [bbprogram.rs:1510]. These are branch-flip policy, not BBProgram structure. Move into `branch_flip.rs`. BBProgram delta: about `-90 LOC`.
- Prefetch helpers live on `BBProgram`: `pf_skip_reason()` [bbprogram.rs:1565], `pf_sites_after_in_frame()` [bbprogram.rs:1574], `pf_prefetch_window_sites()` [bbprogram.rs:1601], `pf_nearest_prefetch_insert_site()` [bbprogram.rs:1648]. Move into `prefetch.rs` or expose one neutral site-slot iterator. BBProgram delta: about `-110 LOC`.
- `bcm_sites_between()` [bbprogram.rs:1725] has one caller in bounds-check-merge. Move it back to that pass. Delta: about `-35 LOC`.
- `rep_site_slot()` [bbprogram.rs:1682] only supports prefetch internals through `pf_*`; remove or privatize after moving `pf_*`.

Keep:
- `rep_admit_kop_site_window()` [bbprogram.rs:1687] is shared by several kop-class passes, so it is real shared infrastructure. Rename to a non-`rep_` name if cleaning surface.

## C. Lifecycle / Mutation

Nice-to-have:
- `rebuild_use_def()` [bbprogram.rs:800] is only a local implementation detail behind `new()` and `rebuild_use_def_after_mutation()` [bbprogram.rs:820]. Make it private. LOC delta: none, surface reduction.
- Profile attach path is over-layered: `attach_profile_from_annotations()` [bbprogram.rs:438] calls `attach_profile_data()` [bbprogram.rs:473], which calls `attach_prefetch_profile_from_original_pcs()` [bbprogram.rs:455]. Collapse to one attach path. Estimated delta: `-25..35 LOC`.
- `invalidate_oracle()` [bbprogram.rs:816] plus mutation APIs are coherent, but `run_pass_once()` also invalidates when instruction count changes [pass.rs:722]. Defensive rather than dead; keep unless mutation discipline is made stricter.

## D. Dead Code / Visibility

Must-fix:
- `verifier_states_at()` is `pub(crate)` [bbprogram.rs:308] but only used inside `bbprogram.rs`; make private.
- `block_start_pc()` [bbprogram.rs:678] is only used by private logical-slot helpers; make private.
- `original_pc()` [bbprogram.rs:572], `original_pc_to_site()` [bbprogram.rs:578], remap helpers [bbprogram.rs:733,746], metadata shifters [bbprogram.rs:851,871], `attach_side_inputs()` [bbprogram.rs:804], `rebuild_cfg_edges()` [bbprogram.rs:773], and `rebuild_use_def_after_mutation()` [bbprogram.rs:820] can mostly be narrowed to `pub(super)`.

## E. pass.rs Surface

Must-fix:
- `MapPtr` [pass.rs:27] exists only to support dead `reg_known_map_ptr()`; delete both.

Nice-to-have:
- `PassContext` [pass.rs:453] is acting as a broad side-input bus. Map-inline fields dominate: `map_ids`, `map_metadata`, `map_values`, `map_value_overlays`, `map_inner_map_ids`, `map_snapshots_skipped_by_size`, `map_inline_hints` [pass.rs:471-478]. Move these into a typed map-inline side input attached during lift. Estimated cleanup: `-80..150 LOC` net, plus much less surface.
- `PassContext.verifier_states` is `pub(crate)` [pass.rs:466] only because lift reaches into it [bbprogram_lift.rs:144]. Prefer an accessor or a lift-side input object.
- `PassManager` is an empty struct [pass.rs:410] with only `finalize_reports()` [pass.rs:728]. A free function would be simpler. Estimated delta: `-8..12 LOC`.

## F. insn.rs Surface

Must-fix:
- Delete zero-call helpers: `MapPseudo::has_value_offset()` [insn.rs:178], `BpfInsn::is_map_pseudo()` [insn.rs:402], `call_kfunc_with_off()` [insn.rs:451], `call_kfunc()` [insn.rs:461]. Estimated delta: `-20..35 LOC`.
- `map_pseudo_kind()` [insn.rs:406] overlaps `map_pseudo()` [insn.rs:397]. Collapse callers to `map_pseudo()`.

Keep:
- `pack_u4/u8/u16/u32` and `unpack_u4/u8/u16/u32` [insn.rs:608-639] are used by kop payload code and sidecar decoding.
- `packet_ctx_layout()` [insn.rs:109] is shared by packet-access passes and belongs in common instruction/layout code.
- `SimpleRegValue` [insn.rs:644] is justified because it shares one register-state transition implementation across const-prop and map-inline style analysis.

## G. verifier_log.rs Surface

Mostly fine:
- Raw verifier internals are `pub(crate)` [verifier_log.rs:17-65], while production passes now query through typed `BBProgram` methods.
- `VerifierStatesJson` and related JSON structs [verifier_log.rs:100-140] are public because `main.rs` imports them [main.rs:20].
- `parse_verifier_log()` [verifier_log.rs:147] is `pub(crate)` but only used by `verifier_states_from_log()` [verifier_log.rs:151]. Make it private.

## H. main.rs CLI Bloat

Nice-to-have / high ROI:
- `main.rs` is doing too much map-inline-specific work: CLI side-input attach [main.rs:771], hint parsing [main.rs:855], snapshot structs [main.rs:955], map dump reading [main.rs:1137], compressed value parsing [main.rs:1349], map type parsing [main.rs:1571]. Move this into a map-inline side-input module. Main-file delta: `-500..700 LOC`; net repo delta depends on how much is moved vs deleted.
- Hint validation is duplicated in `main.rs` [main.rs:921] and lift [bbprogram_lift.rs:203]. Centralize it. Estimated delta: `-20..30 LOC`.
- `parse_inline_hint_hex()` [main.rs:895] is reused for non-hint map JSON parsing [main.rs:1261,1461,1479]; rename/generalize.
- Pass name/alias logic is split between `PASS_ALIASES` [main.rs:24] and `cli_name_for_pass()` [main.rs:359]. Put alias metadata with the pass registry. Estimated delta: `-20..30 LOC`.

## I. lib.rs / Module Tree

Nice-to-have:
- `lib.rs` publicly exposes `analysis`, `insn`, `pass`, `passes`, `verifier_log` [lib.rs:8-12]. `pub mod passes` is currently needed because `main.rs` imports `PASS_REGISTRY` [main.rs:19], but a narrower registry export would let `passes` become internal later.
- `analysis/mod.rs` publicly exposes `bbprogram_lift` and `bbprogram_lower` modules [analysis/mod.rs:7-8] while also re-exporting only `lift_with_pass_context` and `lower` [analysis/mod.rs:16-17]. The modules can likely become private.

## J. Visibility Tightening

Highest-confidence changes:
- `verifier_states_at`: `pub(crate)` to private.
- `original_pc`, `original_pc_to_site`, remap helpers, metadata shifters: `pub(crate)` to `pub(super)` where sibling analysis modules need them.
- `PassContext.verifier_states`: make private once lift stops reading the field directly.
- Test-only constructors/helpers in `insn.rs` should be `cfg(test)` or test-helper-local where integration tests do not need them.

## K. Code Volume

Mandatory file LOC total: `8555 LOC`.

Largest non-test source files:
- `passes/map_inline.rs`: `3282` (K still in flight; will drop further)
- `analysis/bbprogram.rs`: `1955`
- `main.rs`: `1905`
- `analysis/bbprogram_api.rs`: `859`
- `verifier_log.rs`: `853`

Longest functions in audited files:
- `lift_with_kop_registry()` [bbprogram_lift.rs:27], about `112 LOC`
- `merge_linear_chain_in_place()` [bbprogram_api.rs:264], about `99 LOC`
- `parse_compressed_map_values_json()` [main.rs:1349], about `81 LOC`
- `replace_diamond_with_insns_in_place()` [bbprogram_api.rs:458], about `81 LOC`
- `read_map_values()` [main.rs:1047], about `75 LOC`

Estimated cleanup:
- Conservative true deletion: `300..450 LOC`
- With map-inline parser/module cleanup and pass-specific helper relocation: main/BBProgram shrink `800..1000 LOC`, net repo reduction around `350..550 LOC`

## L. Architecture Coherence

See Executive Verdict.

## Top 10 Cleanup Items

1. Delete dead verifier/oracle APIs and `MapPtr`.
2. Delete zero-call BBProgram/API methods.
3. Move `bf_*`, `pf_*`, and `bcm_*` helpers out of `BBProgram`.
4. Move map-inline side inputs out of generic `PassContext`.
5. Split map snapshot parsing out of `main.rs`.
6. Centralize inline hint parsing/validation.
7. Tighten `BBProgram` helper visibility.
8. Delete/collapse dead `insn.rs` helpers.
9. Replace empty `PassManager` with a free function.
10. Narrow `lib.rs`/`analysis` public module exports.
