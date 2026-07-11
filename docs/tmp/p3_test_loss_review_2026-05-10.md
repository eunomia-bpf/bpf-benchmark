# Phase 3 BBProgram test-loss review

Date: 2026-05-10
Branch: `main`
HEAD inspected: `01115ca9 feat(docs): Add design document for BBProgram architecture flip and OTEL eBPF profiler investigation`

## Scope and method

This is investigation and restoration planning only. No test restoration was
implemented.

I inspected the deleted tracked files with `git show HEAD:<path>`, current
production code with `rg`/`sed`, and the Unit Test Quality rule in
`CLAUDE.md`: tests should cover real bug-detection value, not trivial getters,
tautologies, or duplicate coverage.

Count note: the prompt says 22 deleted per-pass/per-analysis test files, but
`git status` and the provided list contain 21 deleted `*_tests.rs` /
`pass_tests.rs` files, plus `mock_maps.rs` and `test_helpers.rs`. In addition,
`bpfopt/crates/bpfopt/src/rewrite.rs` is deleted and contained 7 branch-fixup
unit tests; it is not in the prompt list but matters for P1-G defect coverage.

Raw deleted test attrs from the 21 listed test files: 312. Deleted
`rewrite.rs` tests: 7. The canonical post-Phase-3 report says final cargo test
count was 78. The current filesystem also has an untracked
`bpfopt/crates/bpfopt/tests/bounds_check_merge_unit.rs` with 15 tests copied
from the deleted bounds-check file; that explains why local `#[test]` grep is
higher than 78.

## 1. Deleted-file categorization

Legend:

- (a) legacy-API-only: old `Analysis`, `AnalysisCache`, `RewritePlan`,
  or pass-manager mechanics with no semantic coverage beyond that API.
- (b) pass-behavior regression value: specific bug fix, fail-fast rule,
  edge case, branch fixup, BTF remap, verifier-state, PMU, map snapshot, or
  side-input behavior.
- (c) synthetic happy-path fixture: toy pass pattern tests with limited
  marginal value if equivalent testbin/corpus coverage exists.
- (d) analysis-internal data structure: CFG/liveness/branch/map/site compute
  logic. Restore if still live.

| Deleted file | Tests | Categorization and restoration disposition |
| --- | ---: | --- |
| `analysis/branch_target_tests.rs` | 5 | (d) compute API still exists in `analysis/branch_target.rs` and is still consumed by BBProgram passes. `branch_target_ja32_uses_imm_target` is (b), P1-G defect coverage. `branch_target_pseudo_func_callback` is (b)/(d). Simple JA/conditional/no-branch cases are (d)/(c). Restore in Tier B; JA32 in Tier A. |
| `analysis/cfg_tests.rs` | 3 | (d) compute API still exists in `analysis/cfg.rs`. `cfg_edges_use_ja32_imm_target` is (b), P1-G defect coverage. `cfg_subprog_bounds_maps_pc_to_range` is (b)/(d), P1-H strengthened fixture. Restore all in Tier B; JA32 and subprog fixture in Tier A. |
| `analysis/liveness_tests.rs` | 10 | (d) flat liveness is still live and still used by migrated passes for scan/admission checks. Basic use/def cases are (d)/(c); `liveness_call_clobbers_caller_saved` is (b) because call clobber modeling affects const-prop/DCE safety. Restore representative coverage in Tier B, not necessarily every toy case. |
| `analysis/map_refs_tests.rs` | 2 | (d)/(b). `MapRefsAnalysis` is still production-consumed by `map_inline/map_info.rs`; the "deleted fd prefix" test protects stable old-fd-to-map-id binding after transforms. Restore in Tier B; the stable-binding test is Tier A if map-inline tests are restored. |
| `analysis/site_scan_tests.rs` | 2 | (d)/(c). `iter_sites` still exists and controls LDIMM64 second-slot-safe scanning. Small tests are cheap and meaningful as instruction-boundary contracts. Tier B. |
| `pass_tests.rs` | 21 | Mixed. (a): `test_analysis_cache_basic`, cache invalidation, old typed-analysis dummy pass tests, several old PassManager mechanics can stay deleted because `AnalysisCache` and `Analysis` are gone. (b): `snapshot_provider_lookup_compressed_overlays`, KopRegistry call-key tests, `kop_replacement_subprog_*`, `remap_btf_metadata_*`, `remap_kop_btf_metadata_*`, `test_pass_manager_invalidates_verifier_states_after_transform`, annotation/profile remap tests. Restore selected production-behavior tests in Tier B/C. |
| `passes/bounds_check_merge_tests.rs` | 15 | Mostly (b)/(c). Current untracked integration file already preserves these 15 tests, but it is not a tracked restoration. Critical (b): `test_branch_fixup_after_merge`, `test_merge_remaps_btf_metadata`, packet ctx layouts, rejection matrices. Keep/restage as tracked BBProgram-aware integration or unit tests. |
| `passes/branch_flip_tests.rs` | 17 | Strong (b) value. Critical: real per-site PMU missing data errors, program/site miss-rate gates, high-miss skip, PGO-biased flip, actual oversized pass rejection, multiple-site/output-layout correctness. Pure scan diamond cases are (c) but useful because branch_flip is profile-gated and not in default corpus policy. Restore a focused subset in Tier A/B. |
| `passes/bulk_memory_tests.rs` | 11 | Mixed (b)/(c). Encoding/fill matrix, negative matrix, segmentation, alias gate, branch fixup, and proof-temp-live-out are (b). Simple memcpy/memset happy paths are (c). Restore selected edge cases in Tier C; branch-fixup/proof-temp in Tier A/B if kop pass coverage is otherwise thin. |
| `passes/ccmp_tests.rs` | 8 | Mixed (b)/(c). Payload canonical/reject tests, arch gate, overlong-chain no-partial rewrite, and subprog-boundary skip are (b). Basic scan/happy emit are (c). Restore selected in Tier C; subprog-boundary and payload reject are good Tier B candidates. |
| `passes/cond_select_tests.rs` | 13 | Mixed (b)/(c). Alias overlap matrix, value materialization, JEQ swap/non-zero/JMP32/JGT predicate emission, cond-clobber rejection, and capability matrix are (b). Analyzer happy paths are (c). Restore selected Tier C; alias matrix is a strong Tier B candidate. |
| `passes/const_prop_tests.rs` | 17 | Predominantly (b). This file is the highest-priority loss. The comments explicitly mark real bugs: caller-saved post-state seeding, MOV provenance oracle misuse, packet/frame pointer materialization, shifted post-state pointer evidence, edge/full-state visit handling, cross-frame disagreement, and zero divisor non-panic. Restore most of this file, migrated to BBProgram oracle setup. |
| `passes/dce_tests.rs` | 2 | (b). `dce_preserves_kop_implicit_register_uses` is P1-F critical. The const-prop-then-DCE cleanup fixture is smaller but still checks semantic dead-def cleanup after simplification. Restore P1-F in Tier A. |
| `passes/endian_tests.rs` | 24 | Mixed. (b): narrowing cases, packed live-reg/no-callee-saved behavior, interior branch target, branch fixup, static/per-size call offsets, missing size target, dst `r0`, consecutive/all-size sites. (c): simple scan and happy emit cases. Restore selected Tier C; branch-fixup/call-offset cases are Tier B candidates. |
| `passes/extract_tests.rs` | 26 | Mixed. (b): mask edge cases, sign-extended all-ones, width 1, shift 0, multi-subprog, caller-saved save/restore, packed no callee-saved, interior branch target, branch fixup, static call offset, dst `r0`, consecutive sites. (c): basic scan/happy path. Restore selected Tier C. |
| `passes/map_inline_tests.rs` | 67 | Predominantly (b). This is the second-highest-priority loss after const_prop. It covers hint fail-fast behavior, compressed map-value schema, map-in-map route A, verifier-guided key extraction, no non-verifier fixpoint fallback, stack/full-state key snapshots, map snapshot missing/skipped errors, per-CPU safety, mutable map skips, CFG-unreachable soft-fold bug, and pseudo-map-value sources. Some `find_*` / `classify_*` toy tests are (c)/(d) helper coverage. Restore a focused subset in Tier A/C; do not discard the whole file as legacy. |
| `passes/mod_tests.rs` | 9 | Mixed. (b): `pass_registry_declares_all_emitted_kop_probe_names`, custom pipeline unknown-name rejection, map_inline -> const_prop cascade tests. (d): CFG/liveness cross-checks. Some simple pipeline ordering is (c). Restore registry/cascade tests in Tier B/C. |
| `passes/prefetch_tests.rs` | 6 | Mixed (b)/(c). Payload reserved-bit test, profile cold-filter, alias register selection, and instruction-boundary insertion are (b). Simple map/packet emits are (c). Restore selected Tier C. |
| `passes/rotate_tests.rs` | 23 | Mixed. (b): provenance MOV adjacency, no wrong provenance, packed live-reg/no-callee-saved, live-out temp conflict, multi-subprog, overwritten dst by MOV/LDX, intervening instruction rejection. (c): basic scan/happy emit matrix. Restore selected Tier C. |
| `passes/skb_load_bytes_tests.rs` | 13 | Mixed. (b): constant offset/len gating, ctx reload after prior helper, callee-saved ctx reload, length gating, tc-only gate, supported lengths, error-check preservation, branch fixup. (c): empty/no-helper/non-helper/single-call happy fixtures. Restore selected Tier C; branch fixup and prior-helper ctx reload are Tier B. |
| `passes/wide_mem_tests.rs` | 18 | Mixed. (b): branch fixup table, pseudo-func boundary skip, packet pointer gate matrix, BTF struct pointer field-boundary gate, live scratch skip, misaligned halfword skip. (c): byte-ladder scan/emit matrices. Restore selected Tier A/B/C; BTF pointer and pseudo-func-boundary are high value. |

Out-of-list but important:

| Deleted file | Tests | Categorization and restoration disposition |
| --- | ---: | --- |
| `rewrite.rs` | 7 | Old `RewritePlan` itself is deleted, but `fixup_all_branches_rewrites_ja32_imm_after_growth`, `fixup_all_branches_rejects_i16_overflow`, and `fixup_all_branches_rejects_ja32_i32_overflow` are (b) P1-G critical. Re-express against `analysis::lower()` / `BpfInsn::set_branch_target_delta()` / BBProgram mutation paths rather than restoring `RewritePlan`. Other helper tests are legacy-ish but still encode branch-fixup invariants. |

## 2. Critical regression tests that must be restored

These are not "nice to have" fixtures. They protect actual regressions from
Phase 1 or fail-fast violations fixed during P1-G/P1-H.

| Old file:test | Bug protected | Assertion | BBProgram re-expression |
| --- | --- | --- | --- |
| `passes/dce_tests.rs:dce_preserves_kop_implicit_register_uses` | P1-F: DCE deleted `r6 = 0` / `r0 = 1` operands consumed only through a `bpf_select64` sidecar+kop call, later producing pointer-as-scalar verifier rejection. Current relevant code is `passes/dce.rs:34-49` and `analysis/bbprogram_use_def.rs:164-210`. | DCE preserves the materialization insns before `kop_sidecar(0x1066)` and `call_kop`. | Yes. Build `BpfProgram`, set `KopRegistry`, call `DcePass::run(&mut program, &ctx)` or lift with `lift_with_kop_registry()` and call `run_dce_on_bbprogram()`. |
| `passes/const_prop_tests.rs:const_prop_skips_frame_pointer_arithmetic_materialization` | P1-K round 1 / P1-F const_prop: stale scalar verifier fact at raw PC must not beat shifted `fp` post-state for helper memory arg. Current relevant code is `const_prop.rs:12-18`, `:631-693`, `:862-893`. | No rewrite; skip reason `register has pointer type, cannot materialize`; original `r1 = r10; r1 += -16` remains. | Yes. Use `program.set_verifier_states(...)`; wrapper already lifts to BBProgram and remaps BTF/annotations. |
| `passes/const_prop_tests.rs:const_prop_skips_frame_pointer_plus_eight_with_shifted_post_state` | P1-K round 2: local `may_pointer` provenance must stop scalar materialization even when stale exact scalar exists at raw PC and pointer state is shifted outside the original small window. | No rewrite; skip reason at ALU PC; original `r1 = r10; r1 += 8` remains. | Yes. Same as above. |
| `passes/const_prop_tests.rs:const_prop_post_state_guard_rejects_packet_pointer_copy_materialization` | Pointer provenance bug: packet pointer copy must not be turned into scalar immediate before packet memory access. | `sites_applied == 0`, skip reason pointer type, original bytecode unchanged. | Yes. |
| `passes/const_prop_tests.rs:const_prop_does_not_use_oracle_for_register_mov_provenance` | MOV-X destination pre-state oracle fact must not replace a register copy that may transfer pointer provenance. | MOV remains; no unsafe scalarization from oracle pre-state. | Yes. |
| `passes/const_prop_tests.rs:const_prop_does_not_seed_caller_saved_regs_from_call_post_state` | Helper-call post-state for `r0-r5` must not repopulate caller-saved local facts after a call. | Later fold is rejected/unchanged instead of using stale call result facts. | Yes. |
| `passes/const_prop_tests.rs:const_prop_rejects_edge_state_only_pointer_arithmetic_materialization` | Edge/full states describe entry state, not post-state; using them for ALU post-state can scalarize pointer arithmetic. | Pointer arithmetic replacement rejected. | Yes. |
| `passes/const_prop_tests.rs:const_prop_rejects_replacement_when_observation_missing_at_some_visit` | Verifier deltas from one diamond arm must not prove a join PC across all visits. | Replacement rejected when one visit lacks observation. | Yes. |
| `passes/const_prop_tests.rs:const_prop_rejects_replacement_when_full_state_visit_omits_reg` | Full-state visits count; ignoring one can falsely prove consensus. | Replacement rejected when a full-state visit omits the reg. | Yes. |
| `passes/const_prop_tests.rs:const_prop_rejects_replacement_across_disagreeing_frames` | Context-insensitive replacement must not apply when frame visits disagree. | Replacement rejected across conflicting frames. | Yes. |
| `analysis/branch_target_tests.rs:branch_target_ja32_uses_imm_target` | P1-G defect 2: JA32 target stored in `imm`, not `off`. Current helper is `insn.rs:347-378`. | Target PC from JA32 `imm` is marked as branch target. | Yes. Could test flat helper and BBProgram lift/lower. |
| `analysis/cfg_tests.rs:cfg_edges_use_ja32_imm_target` | Same JA32 bug in CFG edge construction. | Entry block successor is target block at PC 3. | Yes. |
| `rewrite.rs:fixup_all_branches_rewrites_ja32_imm_after_growth` | P1-G defect 2 in branch rewrite: old code could leave JA32 `imm` stale or write `off`. | After growth, JA32 `imm` is rewritten, `off` remains 0. | Yes. Re-express through BBProgram lower on a mutated/lifted program or through `BpfInsn::set_branch_target_delta()`. |
| `rewrite.rs:fixup_all_branches_rejects_i16_overflow` | P1-G defect 1: branch delta truncation to i16. | Oversized off16 delta returns error containing `exceeds i16`. | Yes. `lower()` calls `set_branch_target_delta()` and should fail. |
| `rewrite.rs:fixup_all_branches_rejects_ja32_i32_overflow` | P1-G defect 2: JA32 `imm` overflow must fail, not truncate. | Oversized JA32 delta returns error containing `exceeds i32`. | Yes. Direct helper or lowered BBProgram path. |
| `passes/branch_flip_tests.rs:test_branch_flip_pass_rejects_oversized_else_delta` | P1-H: helper-only branch overflow test was insufficient; actual branch_flip transform path must fail fast. Current path is `branch_flip.rs:228-353`, apply at `:390-469`, lower at `bbprogram_lower.rs:88-111`. | Real pass run errors with `exceeds i16`. | Yes. Use BBProgram `run_branch_flip_on_bbprogram()` or wrapper with annotations/PMU. |
| `passes/bounds_check_merge_tests.rs:test_merge_remaps_btf_metadata` | P1-H: bounds_check_merge direct commit/cleanup path skipped BTF remap. Current wrapper remaps at `bounds_check_merge.rs:93-99`. | `func_info` and `line_info` offsets are remapped after merge. | Yes. Current untracked integration already has this test; make it tracked. |
| `analysis/cfg_tests.rs:cfg_subprog_bounds_maps_pc_to_range` | P1-H: previous pseudo-func fixture was malformed/weak; subprog range mapping must cover real callback body. | PCs 4 and 5 map to callback range `4..7`. | Yes. |
| `passes/map_inline_tests.rs:map_inline_pass_does_not_use_non_verifier_fixpoint_fallback` | P1-H/fail-fast: map_inline must not keep folding through a non-verifier fallback after a prior rewrite invalidates verifier state. | Later lookup helper remains; final load is not constantized without refreshed verifier state. | Yes. Requires mock map/test helper restoration. |
| `passes/map_inline_tests.rs:map_inline_consumes_hint_when_verifier_state_unavailable` | Operator hard hint was ignored when verifier stack state was absent. | Hint is consumed and rewrite applies without synthetic verifier state. | Yes. |
| `passes/map_inline_tests.rs:map_inline_rejects_hint_with_wrong_key_size` | Malformed hints must fail fast rather than silently degrade to normal key extraction. | Pass returns error naming wrong key size. | Yes. |
| `passes/map_inline_tests.rs:map_inline_rejects_hint_pointing_at_non_lookup_call` | Hint call PC typo must fail fast rather than leave hint unused. | Pass returns error naming non-lookup call. | Yes. |
| `passes/map_inline_tests.rs:map_inline_soft_hint_requires_immediate_null_check_when_hard_fold_coexists` | Soft fold emitted unreachable CFG in mixed hard/soft hint scenario. | Hard fold applies, soft lookup remains, diagnostics mention missing null handler, CFG unreachable set empty. | Yes. |
| `passes/map_inline_tests.rs:map_inline_route_a_rejects_missing_outer_entry_for_hint` | Map-in-map route A hard hint must fail when outer entry is absent. | Error contains `has no live inner map`. | Yes. |
| `passes/map_inline_tests.rs:map_inline_route_a_rejects_kernel_mutable_inner_hint` | Hard hint must not inline mutable inner maps. | Error/skip for kernel-mutable inner map. | Yes. |
| `passes/map_inline_tests.rs:map_inline_route_a_rejects_orphan_inner_hint` | Inner hint without matching outer map-in-map hint must fail. | Error contains no matching map-in-map outer hint. | Yes. |
| `passes/wide_mem_tests.rs:test_wide_mem_skips_byte_ladder_with_pseudo_func_boundary_inside` | KOperation/pass replacement must not cross pseudo-func subprog boundary. | Site skipped with subprog/interior target reason; pseudo-func metadata preserved. | Yes. |
| `passes/wide_mem_tests.rs:test_wide_mem_verifier_state_pointer_type_gate_matrix` | P1-H sentinel/fail-fast class: wide_mem must skip BTF struct pointer field loads instead of treating missing binding/sentinel as OK. | BTF pointer case skipped with reason; scalar/no-state cases behave as expected. | Yes. |

Minimum Tier A should restore all rows above or an equivalent BBProgram-native
test that fails for the same bug.

## 3. Mock infrastructure

`mock_maps.rs` was not intrinsically obsolete. It became unused only because
all tests that exercised map providers were deleted. `map_inline` still depends
on map metadata/value resolution through `MapProvider`, and meaningful unit
tests need deterministic map contents, map type, per-CPU layout, skipped
snapshot behavior, and map-in-map inner IDs without a live kernel. The old
`MockMapProvider` supplied exactly that for tests.

Deleting `mock_maps.rs` was premature if any `map_inline_tests.rs` behavior is
restored. A cleaner restoration can avoid reintroducing a crate-root public
`cfg(test) mod bpf` by moving the mock provider into an integration-test
support module, but the capability is still necessary.

`test_helpers.rs` was similarly not pure legacy. Parts are still needed:

- `scalar_reg`, `fp_reg`, verifier delta/full-state constructors.
- `stack_snapshot_from_key` for verifier-guided map key extraction.
- `install_map` / `install_array_map` helpers if the old mock provider is used.
- `make_program` is trivial and can stay local to tests.

Do not restore helper APIs wholesale if they are only convenience wrappers.
Restore a minimal `tests/support` or focused `#[cfg(test)]` module whose
functions each serve a concrete regression test.

## 4. Restoration plan

All tiers should migrate tests away from `AnalysisCache`, old `Analysis`, and
`RewritePlan`. For pass tests, prefer current wrappers only when the test needs
`BpfProgram` side data (`verifier_states`, annotations, map values). Otherwise
lift with `lift_with_kop_registry()`, call the exported
`run_*_on_bbprogram()` function, and lower with `analysis::lower()`.

### Tier A - minimal critical guard rails

Scope:

- Restore the critical tests listed in Section 2 or equivalent BBProgram-native
  forms.
- Include minimal map/verifier test support needed by const_prop, DCE, map_inline,
  branch_flip, bounds_check_merge, and wide_mem.
- Make the existing untracked `bounds_check_merge_unit.rs` tracked or fold the
  critical BTF/branch-fixup tests into the new Tier A test module.

Estimated restored tests: 28-35.

Estimated migration LOC: 700-1,100 LOC, mostly fixtures and support. More than
half is map_inline support unless that subset is moved to one compact
integration fixture file.

Effort: 3-5 codex-hours.

Projected test count: 106-113 from the canonical 78 baseline. This crosses the
`>= 100` sanity floor but does not restore historical norms.

### Tier B - medium analysis and infrastructure restoration

Scope:

- Tier A.
- Restore live analysis-internal tests for branch targets, CFG, liveness,
  map_refs, and site_scan.
- Restore selected production infrastructure tests from `pass_tests.rs`:
  KopRegistry call-key/call-offset behavior, annotation/profile remap,
  snapshot compressed overlays, BTF metadata remap, verifier-state invalidation.
- Restore pass registry/cascade tests from `passes/mod_tests.rs`.

Estimated restored tests: Tier A + 45-60, total 75-95 restored.

Estimated migration LOC: 1,500-2,200 LOC.

Effort: 6-9 codex-hours.

Projected test count: 153-173. This is meaningfully safer than Tier A but still
below historical 386-test density and below the `>= 200` historical-norm target.

### Tier C - aggressive semantic restoration

Scope:

- Tier A and Tier B.
- Restore selected pass-behavior fixtures with real edge-case value from
  rotate, extract, endian_fusion, bulk_memory, ccmp, cond_select, prefetch,
  skb_load_bytes_spec, wide_mem, and map_inline.
- Do not blindly restore every synthetic happy path. Keep tests that answer the
  Unit Test Quality question: "what specific bug would this failure identify?"
- Prefer table-driven tests that combine old one-off toy fixtures where that
  preserves the same bug signal.

Estimated restored tests: Tier A + B + 80-120, total 155-215 restored.

Estimated migration LOC: 3,000-4,500 LOC.

Effort: 12-18 codex-hours.

Projected test count: 233-293. This reaches historical-norm territory without
restoring all 312 deleted listed tests.

## 5. Decision summary

Recommend Tier C, implemented in two commits/steps if commits are later allowed:
first Tier A, then Tier B/C expansion. For this requested run, do not implement.

Reasoning:

- Phase 1 already hit multiple real bugs that unit tests caught or should have
  caught: P1-F DCE kop-aware liveness, P1-K const_prop pointer-skip rounds 1
  and 2, P1-G JA32/i16 branch fixup defects, and P1-H fail-fast/BTF/remap
  violations. Deleting those tests removes proven regression protection.
- Corpus runs are good at verifier-reject regressions. They are weak for silent
  correctness divergences where a pass emits verifier-valid but semantically
  wrong bytecode, such as deleting a value materialization used only through a
  sidecar or folding through stale verifier facts.
- BBProgram roundtrip plus corpus is a necessary end-to-end safety net, but it
  does not replace mid-pipeline guard rails. Bugs in use-def, branch target
  accounting, map side-input handling, profile admission, and verifier-oracle
  interpretation need small, direct tests with failure messages pointing at the
  broken rule.
- Tier A gets the suite above 100 tests quickly, but leaves too much pass-local
  semantic surface uncovered. Tier B restores core analyses but still leaves
  migrated kop passes thin. Tier C is the best balance: restore high-signal
  edge cases, skip pure legacy mechanics, and avoid wholesale resurrection of
  low-value toy cases.

