# Phase 3 BBProgram TDD Review

Date: 2026-05-10
Branch: `main`
Scope: review only. No production or test code was modified.

## Verdict

**NEEDS RE-DO.**

The migrated suite is much better than the pre-Step-A deletion state: the
Section 2 critical regressions from `p3_test_loss_review_2026-05-10.md` are
mostly represented, and most retained pass tests now use a future
`BBProgram`-first helper path.

However, the suite is not yet a safe post-Phase-3 specification:

- The deletion sample found more than 5 wrong-call removals. Several removed
  tests guarded real pass semantics, ABI payload encoding, alias handling, and
  safety gates that are not covered by the retained tests.
- Some new test APIs are reasonable implementation requirements, but are not in
  `docs/bbprogram-architecture-design.md` section 5 and need to be made explicit
  before Codex C implements against them.
- The verifier-state contract is muddled: the design puts verifier facts into
  `BBProgram.oracle` at lift time, while the tests put raw `verifier_states` on
  `PassContext` and the test lift helper currently ignores them.

Recommendation: Codex A should re-run or patch the test migration with stricter
retention rules before Codex C treats this suite as the implementation contract.

## 1. Critical Regression Coverage Check

| Required regression from loss review section 2 | Current migrated coverage | Review |
| --- | --- | --- |
| P1-F DCE preserves kinsn implicit register uses | `passes/dce_tests.rs:dce_preserves_kinsn_implicit_register_uses`; also `analysis/liveness_tests.rs:bbprogram_liveness_includes_kinsn_implicit_register_uses` | Covered. The pass test checks materialization insns remain before sidecar + kinsn call. |
| P1-K round 1 frame-pointer arithmetic materialization skip | `passes/const_prop_tests.rs:const_prop_skips_frame_pointer_arithmetic_materialization` | Covered. Asserts no rewrite, pointer skip reason, original bytecode. |
| P1-K round 2 shifted frame-pointer post-state skip | `passes/const_prop_tests.rs:const_prop_skips_frame_pointer_plus_eight_with_shifted_post_state` | Covered. Asserts no rewrite despite stale scalar evidence. |
| Packet pointer copy must not scalarize | `passes/const_prop_tests.rs:const_prop_post_state_guard_rejects_packet_pointer_copy_materialization` | Covered. Asserts `sites_applied == 0`, pointer skip reason, unchanged bytecode. |
| MOV-X oracle provenance misuse | `passes/const_prop_tests.rs:const_prop_does_not_use_oracle_for_register_mov_provenance` | Covered. Asserts unchanged MOV/provenance sequence. |
| Caller-saved regs not seeded from call post-state | `passes/const_prop_tests.rs:const_prop_does_not_seed_caller_saved_regs_from_call_post_state` | Covered. |
| Edge-state-only pointer arithmetic rejection | `passes/const_prop_tests.rs:const_prop_rejects_edge_state_only_pointer_arithmetic_materialization` | Covered. |
| Missing observation at one visit rejects replacement | `passes/const_prop_tests.rs:const_prop_rejects_replacement_when_observation_missing_at_some_visit` | Covered. |
| Full-state visit omits reg rejects replacement | `passes/const_prop_tests.rs:const_prop_rejects_replacement_when_full_state_visit_omits_reg` | Covered. |
| Disagreeing frames reject replacement | `passes/const_prop_tests.rs:const_prop_rejects_replacement_across_disagreeing_frames` | Covered. |
| JA32 branch target uses `imm` | `analysis/branch_target_tests.rs:bbprogram_ja32_successor_uses_imm_target` | Covered at BB successor/terminator level. |
| CFG edges use JA32 `imm` | `analysis/cfg_tests.rs:bbprogram_cfg_edges_use_ja32_imm_target` | Covered. |
| JA32 branch rewrite writes `imm`, not `off` | `analysis/lower_tests.rs:fixup_all_branches_rewrites_ja32_imm_after_growth` | Covered only through `BpfInsn::set_branch_target_delta()`. Acceptable per loss-review re-expression, but weaker than a real BB lower-after-growth test. |
| i16 branch overflow fails | `analysis/lower_tests.rs:fixup_all_branches_rejects_i16_overflow` | Covered through helper. |
| JA32 i32 overflow fails | `analysis/lower_tests.rs:fixup_all_branches_rejects_ja32_i32_overflow` | Covered through helper. |
| Branch-flip oversized pass path fails fast | `passes/branch_flip_tests.rs:branch_flip_rejects_oversized_else_delta_through_pass_path` | Covered through pass helper and expected error text. |
| Bounds-check merge remaps BTF metadata | `passes/bounds_check_merge_tests.rs:bounds_check_merge_remaps_btf_metadata_on_bbprogram` | Covered, but depends on new `BBProgram::btf_records()` API not in design section 5. |
| Subprog body range mapping | `analysis/cfg_tests.rs:bbprogram_subprog_blocks_cover_callback_body_range` | Partially covered. It verifies the callback block is in `FrameId(1)`, but no longer asserts exact PC range membership for every callback PC. |
| map_inline no non-verifier fixpoint fallback | `passes/map_inline_tests.rs:map_inline_pass_does_not_use_non_verifier_fixpoint_fallback` | Covered. |
| map_inline hard hint works without verifier state | `passes/map_inline_tests.rs:map_inline_consumes_hint_when_verifier_state_unavailable` | Covered. |
| map_inline wrong key-size hint fails fast | `passes/map_inline_tests.rs:map_inline_rejects_hint_with_wrong_key_size` | Covered. |
| map_inline non-lookup hint fails fast | `passes/map_inline_tests.rs:map_inline_rejects_hint_pointing_at_non_lookup_call` | Covered. |
| map_inline mixed hard/soft hint CFG safety | `passes/map_inline_tests.rs:map_inline_soft_hint_requires_immediate_null_check_when_hard_fold_coexists` | Covered, but depends on new `BBProgram::unreachable_blocks()` API not in design section 5. |
| map-in-map route A missing outer entry fails | `passes/map_inline_tests.rs:map_inline_route_a_rejects_missing_outer_entry_for_hint` | Covered. |
| map-in-map route A mutable inner fails | `passes/map_inline_tests.rs:map_inline_route_a_rejects_kernel_mutable_inner_hint` | Covered. |
| map-in-map orphan inner hint fails | `passes/map_inline_tests.rs:map_inline_route_a_rejects_orphan_inner_hint` | Covered. |
| wide_mem skips pseudo-func boundary inside site | `passes/wide_mem_tests.rs:wide_mem_skips_byte_ladder_with_pseudo_func_boundary_inside` | Covered. |
| wide_mem BTF pointer gate matrix | `passes/wide_mem_tests.rs:wide_mem_skips_btf_struct_pointer_field_loads` plus `wide_mem_collapses_halfword_byte_ladder` | Partially covered. BTF skip and no-state positive are covered; scalar verifier-state positive leg from the old matrix is not. |

No Section 2 row is completely missing, but the partial rows above should be
tightened if Codex A does another retention pass.

## 2. Aggressive Culling Sanity Check

Sampled deletion sites and judgment:

| Deleted file:test | Judgment | Reason |
| --- | --- | --- |
| `pass_tests.rs:test_analysis_cache_basic` | Right call | `AnalysisCache` is explicitly deleted by the design. |
| `pass_tests.rs:test_pass_manager_analysis_cache_invalidation` | Right call | Legacy cache invalidation mechanics; future contract is recomputed BBProgram queries. |
| `pass_tests.rs:sync_annotations_resizes_both_directions` | Right call | Old `BpfProgram` vector-resize behavior, not a Phase-3 invariant. |
| `pass_tests.rs:test_pass_manager_invalidates_verifier_states_after_transform` | Wrong call | The exact old mechanism is gone, but the behavior remains: verifier/oracle facts must not be reused after a transform unless refreshed. Retained tests only imply this through one map_inline scenario. |
| `pass_tests.rs:remap_btf_metadata_drops_deleted_entries_and_shifts_survivors` | Wrong call | BTF remap is a design invariant. One bounds-check test is not enough coverage for generic deletion/shift behavior. |
| `branch_flip_tests.rs:test_scan_finds_diamond` | Right call | Scanner-only toy fixture; pass-path tests cover real behavior. |
| `branch_flip_tests.rs:test_branch_flip_skips_jset` | Wrong call | Unsupported conditional inversion is real behavior and no retained branch_flip test covers it. |
| `branch_flip_tests.rs:test_branch_flip_asymmetric_with_pgo` | Wrong call | Asymmetric layout stresses offset recomputation differently than the retained symmetric diamond. |
| `branch_flip_tests.rs:test_invert_jcc_roundtrip` | Right call | Private helper roundtrip; lower value than pass-path behavior. |
| `bounds_check_merge_tests.rs:test_single_bounds_check_unchanged` | Right call | Low-value baseline; retained tests cover merge and non-merge cases. |
| `bounds_check_merge_tests.rs:test_different_base_regs_not_merged` | Wrong call | Protects against merging checks from different packet roots; not represented in retained tests. |
| `bounds_check_merge_tests.rs:test_different_error_targets_not_merged` | Wrong call | Prevents changing slow-path semantics; not represented in retained tests. |
| `bulk_memory_tests.rs:test_memset_fill_encoding_matrix` | Wrong call | Kinsn payload/constant encoding is ABI-like behavior; retained tests only cover zero memset. |
| `bulk_memory_tests.rs:test_bulk_memory_negative_pattern_matrix` | Right call | Mostly tabled scanner negatives; retained short/alias/temp tests keep the highest-value negatives. |
| `ccmp_tests.rs:ccmp_payload_roundtrips_canonical_encoding` | Wrong call | ABI payload layout should be directly tested; current tests only detect that some kinsn call exists. |
| `ccmp_tests.rs:scan_ccmp_chain_detects_three_term_nez_guard` | Right call | Scanner-only happy path replaced by pass-path emit test. |
| `cond_select_tests.rs:test_cond_select_alias_all_overlap_combinations` | Wrong call | Alias-safe parameter setup is real correctness behavior and not covered by retained tests. |
| `cond_select_tests.rs:test_cond_select_short_pattern_c_no_match_cond_clobbered` | Wrong call | Prevents matching across a clobbered condition register; no retained equivalent. |
| `const_prop_tests.rs:eval_binary_alu_rejects_zero_divisor_without_panicking` | Right call | Replaced by pass-level `const_prop_rejects_zero_divisor_without_panicking`. |
| `endian_tests.rs:test_scan_endian_fusion_basic_32bit` | Right call | Scanner-only happy path replaced by pass-level rewrite tests. |
| `endian_tests.rs:test_endian_fusion_pass_branch_fixup` | Wrong call | Endian expansion still needs branch-target safety; no retained endian branch-fixup test. |
| `extract_tests.rs:test_contiguous_mask_len` | Right call | Private helper coverage; retained pass tests exercise masks. |
| `extract_tests.rs:test_extract_pass_branch_fixup` | Wrong call | Extract expansion branch-fixup is pass-specific and no retained extract test covers it. |
| `map_inline_tests.rs:compressed_overlay_schema_validation_fail_fast` | Wrong call | Fail-fast schema validation is production behavior. Current tests only cover successful uniform overlay use. |
| `map_inline_tests.rs:map_values_overlay_rejects_raw_entries_and_compression_for_same_map` | Wrong call | Fail-fast conflict handling is not covered by retained tests. |
| `map_inline_tests.rs:find_map_lookup_sites_ignores_calls_without_map_load` | Right call | Helper scanner behavior; pass-path hint/non-lookup tests cover higher-value failures. |
| `map_inline_tests.rs:map_inline_pseudo_map_value_feeds_const_prop_and_dce_without_branch_cleanup` | Wrong call | Cross-pass pseudo-map-value cascade is real behavior; retained cascade test does not exercise map_inline or pseudo map values. |
| `map_inline_tests.rs:map_inline_pass_inlines_uniform_percpu_array_maps` | Wrong call | Retained test only skips per-CPU maps. If uniform per-CPU inlining remains allowed, this is a behavioral regression in the spec. |
| `prefetch_tests.rs:prefetch_payload_round_trips_register_and_rejects_reserved_bits` | Wrong call | Payload encoding/reserved-bit validation is ABI-style behavior. |
| `rotate_tests.rs:test_rotate_pass_no_match_dst_overwritten_after_mov` | Wrong call | Protects rotate provenance safety after a destructive write; retained rotate negatives do not cover it. |
| `rotate_tests.rs:test_rotate_pass_no_match_dst_overwritten_by_ldx` | Wrong call | Same provenance-safety class, with a memory load clobber. |
| `skb_load_bytes_tests.rs:test_ctx_reload_from_callee_saved_reg_is_accepted` | Wrong call | Retained suite only rejects missing reload; it lacks the positive saved-ctx reload case. |
| `skb_load_bytes_tests.rs:test_supported_wide_lengths_stay_bytewise` | Wrong call | Length 2/4/8 specialization behavior is not covered by retained tests. |
| `wide_mem_tests.rs:test_emit_wide_mem_supported_widths` | Right call | Emit helper table is lower value once pass-level collapse tests exist. |
| `wide_mem_tests.rs:test_wide_mem_packet_pointer_gate_matrix` | Wrong call | Retained XDP non-stack skip lacks the positive stack/scalar/tracing legs. |

Wrong-call deletions sampled: 18. This exceeds the requested threshold, so the
suite should be re-run or amended with stricter retention rules.

## 3. Design-API Correctness Check

### BBProgram Methods

| API referenced by tests | Consistent with design section 5? | Notes |
| --- | --- | --- |
| `blocks(&self) -> impl Iterator<Item = &Block>` | Yes | Used consistently. |
| `predecessors(BlockId) -> &[BlockId]` | Yes | Used consistently with `BlockId`, not raw `usize`. |
| `successors(BlockId) -> &[BlockId]` | Yes | Used consistently. |
| `dominance() -> Dominance` and `Dominance::dominates(BlockId, BlockId)` | Yes | Explicit in section 5. |
| `live_in(BlockId) -> RegSet` | Yes | Tests use `.contains(&BPF_REG_X)`, consistent with `RegSet`. |
| `live_out(BlockId) -> RegSet` | Yes | Same. |
| `delete_insn(DefSite) -> Result<...>` | Mostly | Section 5 shows no `Result`, but current production has fallible mutation. Tests correctly use `?`/`expect`; keep it fallible. |
| `reaching_defs(BlockId) -> ReachingDefs` with `defs_for(reg)` | Not explicit | Reasonable, but section 5 only exposes `use_def`. Either add this to the design/API contract or rewrite tests to inspect `prog.use_def`. |
| `subprog_blocks(FrameId) -> impl Iterator<Item = BlockId>` | Not explicit | Reasonable frame query, but not in section 5. Add it to the implementation contract if retained. |
| `map_bindings() -> &[MapBinding]` | Inconsistent naming | Design section 8 says `BBProgram::map_refs`; tests use `map_bindings`. Pick one. The tests are otherwise idiomatic. |
| `sites_in_block(BlockId)` | Not explicit | Section 8 says `site_scan` is pass-local, but BBProgram-native passes need logical site iteration. Add to section 5 or keep it `pub(crate)` and test through pass behavior. |
| `sites_in_block_with_terminator(BlockId)` | Not explicit | Same as above. Existing production has `logical_sites_in_block` privately. |
| `btf_records() -> BtfRecordsView` | Not explicit | Tests need a lowered BTF metadata view. The design says BTF is remapped through `prog.btf`/lower but does not name this API. |
| `unreachable_blocks() -> impl Iterator<Item = BlockId>` | Not explicit | Useful CFG sanity view for map_inline, but not in section 5. |

No inconsistency like `live_in(0)` vs `live_in(BlockId(0))` was found. The tests
consistently use typed IDs.

### PassContext Fields

The tests consistently move side inputs from `BpfProgram` to `PassContext`:

- `verifier_states: Arc<[VerifierInsn]>`
- `annotations: Vec<InsnAnnotation>`
- `branch_miss_rate: Option<f64>`
- `map_ids: Vec<u32>`
- `map_metadata: HashMap<u32, MapMetadata>`
- `map_values: HashMap<(u32, Vec<u8>), Vec<u8>>`
- `map_value_overlays: HashMap<u32, CompressedMapValues>`
- `map_inner_map_ids: HashMap<(u32, Vec<u8>), u32>`
- `map_snapshots_skipped_by_size: HashSet<u32>`
- `map_inline_hints: Vec<MapInlineHint>`
- `func_info: Option<BtfInfoRecords>`
- `line_info: Option<BtfInfoRecords>`

The main design mismatch is verifier-state placement. The design defines
`BBProgram.oracle` and `lift(insns, oracle)`. Tests instead set
`ctx.verifier_states`, and `lift_test_program()` passes `None` as the oracle.
Codex C must not leave this ambiguous. Preferred resolution: the pipeline
constructs `VerifierOracle` from `PassContext::verifier_states` at the single
lift boundary, so passes read `prog.oracle`, not raw verifier state from `ctx`.

## 4. Migration Quality Check

| File | Review |
| --- | --- |
| `analysis/branch_target_tests.rs` | Good BBProgram migration. JA32 and pseudo-call assertions are meaningful; only simple JA/no-branch old cases were dropped. |
| `analysis/cfg_tests.rs` | Mostly good. Predecessor/successor and JA32 assertions are BB-native. Subprog test is weaker than old PC-range assertion. |
| `analysis/liveness_tests.rs` | Good direction. Tests `live_in/live_out`, call clobbers, kinsn implicit uses, and recompute after mutation. P1-F comment is present. |
| `analysis/map_refs_tests.rs` | Meaningful behavior retained, but API naming (`map_bindings`) is outside the design doc. |
| `analysis/site_scan_tests.rs` | Tests logical-site API, not old scanner. Good LDIMM64 boundary coverage; comments are implementation notes, not bug provenance. |
| `analysis/lower_tests.rs` | Covers P1-G helper behavior, but not full `lower()` or pass-path branch remapping. |
| `passes/bounds_check_merge_tests.rs` | Uses future pass helper. Core merge, non-merge, layout, branch offset, and BTF remap are retained. Missing different-base and different-error-target negatives. |
| `passes/branch_flip_tests.rs` | Good fail-fast PMU and pass-path coverage. Missing unsupported Jcc and asymmetric-layout coverage. |
| `passes/bulk_memory_tests.rs` | Exercises pass path, but culling removed high-value fill encoding and segmentation behavior. |
| `passes/ccmp_tests.rs` | Exercises arch gate, emit, polarity, overlong, subprog boundary. Missing ABI payload tests. |
| `passes/cond_select_tests.rs` | Exercises multi-block rewrite shape and predicate forms. Missing alias-overlap and cond-clobber safety tests. |
| `passes/const_prop_tests.rs` | Strongest migrated file. Assertions still match real P1-K/P1-F bugs and comments cite the protected issues. |
| `passes/dce_tests.rs` | Good. P1-F test is direct; pipeline cleanup test is useful. |
| `passes/endian_tests.rs` | Basic behavior and module call offset retained. Branch fixup and per-size unavailability coverage were wrongly culled. |
| `passes/extract_tests.rs` | Core mask/provenance behaviors retained. Branch fixup, width-1/shift-0, and `r0` emission behavior were culled. |
| `passes/map_inline_tests.rs` | Good critical fail-fast subset. Too much side behavior was removed: overlay schema failure, pseudo-map cascade, uniform per-CPU behavior, and several map-in-map/hash cases. |
| `passes/mod_tests.rs` | Registry and custom-pipeline checks are useful. Cascade test name mentions map_inline but does not run map_inline; that is misleading. |
| `passes/prefetch_tests.rs` | Pass-path behavior retained. Payload reserved-bit ABI test was wrongly culled. |
| `passes/rotate_tests.rs` | Good retained provenance and subprog tests. Missing dst-overwrite/clobber negatives. |
| `passes/skb_load_bytes_tests.rs` | Useful pass-path basics retained. Missing positive ctx-reload and length matrix coverage. |
| `passes/wide_mem_tests.rs` | Good branch fixup and critical skip coverage. Pointer-type matrix is partial. |
| `pass_tests.rs` | Correctly pivots to lift-once/lower-once and BBProgram trait shape. Kinsn registry tests remain useful. Needs clearer contract around verifier oracle and side inputs. |

## 5. Mock Infrastructure Check

`mock_maps.rs` is necessary: map_inline needs deterministic metadata, map values,
overlays, per-CPU metadata, and map-in-map side inputs without a live kernel.
It is much smaller than the old provider-based mock.

Dead or unused helpers in `mock_maps.rs`:

- `install_map_value`
- `install_sparse_overlay`

`test_helpers.rs` is also necessary: it centralizes the future lift/run/lower
test path, verifier-state fixtures, stack snapshots, branch/prefetch profiles,
and common result assertions.

Dead or unused helpers in `test_helpers.rs`:

- `ctx_with_map_snapshot`
- `add_map_overlay`
- `regset`

Those helpers should be removed unless Codex A restores tests that need them.

## 6. Implementation Spec For Codex C

### Required BBProgram Methods

```rust
impl BBProgram {
    pub fn blocks(&self) -> impl Iterator<Item = &Block>;
    pub fn predecessors(&self, b: BlockId) -> &[BlockId];
    pub fn successors(&self, b: BlockId) -> &[BlockId];
    pub fn dominance(&self) -> Dominance;
    pub fn live_in(&self, b: BlockId) -> RegSet;
    pub fn live_out(&self, b: BlockId) -> RegSet;

    pub fn subprog_blocks(&self, frame: FrameId) -> impl Iterator<Item = BlockId>;
    pub fn reaching_defs(&self, b: BlockId) -> ReachingDefs;
    pub fn map_bindings(&self) -> &[MapBinding]; // or rename tests/design to map_refs()
    pub fn sites_in_block(&self, b: BlockId) -> impl Iterator<Item = InsnSite>;
    pub fn sites_in_block_with_terminator(&self, b: BlockId) -> impl Iterator<Item = InsnSite>;
    pub fn btf_records(&self) -> BtfRecordsView;
    pub fn unreachable_blocks(&self) -> impl Iterator<Item = BlockId>;

    pub fn delete_insn(&mut self, site: DefSite) -> anyhow::Result<usize>;
    pub fn replace_range(
        &mut self,
        block: BlockId,
        range: Range<usize>,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()>;
}

pub struct ReachingDefs { /* implementation-owned */ }
impl ReachingDefs {
    pub fn defs_for(&self, reg: u8) -> impl Iterator<Item = DefSite>;
}

pub struct Dominance { /* implementation-owned */ }
impl Dominance {
    pub fn dominates(&self, a: BlockId, b: BlockId) -> bool;
}

pub struct BtfRecordsView { /* implementation-owned */ }
impl BtfRecordsView {
    pub fn func_offsets(&self) -> Vec<u32>;
    pub fn line_offsets(&self) -> Vec<u32>;
}
```

### Required PassContext Fields

```rust
pub struct PassContext {
    pub kinsn_registry: KinsnRegistry,
    pub platform: PlatformCapabilities,
    pub policy: PolicyConfig,
    pub prog_type: u32,

    pub verifier_states: Arc<[VerifierInsn]>,
    pub annotations: Vec<InsnAnnotation>,
    pub branch_miss_rate: Option<f64>,

    pub map_ids: Vec<u32>,
    pub map_metadata: HashMap<u32, MapMetadata>,
    pub map_values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    pub map_value_overlays: HashMap<u32, CompressedMapValues>,
    pub map_inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    pub map_snapshots_skipped_by_size: HashSet<u32>,
    pub map_inline_hints: Vec<MapInlineHint>,

    pub func_info: Option<BtfInfoRecords>,
    pub line_info: Option<BtfInfoRecords>,
}
```

`PassContext::baseline()` must initialize empty/default side inputs.

### Required Trait Change

```rust
pub trait BpfPass: Send + Sync {
    fn name(&self) -> &str;
    fn run(&self, prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult>;
}
```

Every pass implementation must operate on the provided `BBProgram`. The old
`BpfProgram` mutation path should not remain as a production pass boundary.

### Required Pipeline And CLI Changes

- `main.rs` reads bytecode and all side-input CLI files into `PassContext`.
- The CLI lifts once at entry, using `ctx.kinsn_registry` and a verifier oracle
  derived from `ctx.verifier_states`.
- The pipeline runs every requested pass on the same `&mut BBProgram`.
- The pipeline lowers once after all passes.
- BTF func/line records and annotations are remapped through BBProgram/lower,
  not through pass-local address maps.
- `build_custom_bbprogram_pipeline(&[String]) -> Result<Vec<Box<dyn BpfPass>>>`
  or equivalent rejects unknown pass names before running anything.
- `MapInlinePass`, `ConstPropPass`, `DcePass`, kinsn passes, `BranchFlipPass`,
  `PrefetchPass`, `BoundsCheckMergePass`, and `SkbLoadBytesSpecPass` must all
  satisfy the new trait directly.

### Required Semantic Restorations Before C

Before Codex C uses the suite as authoritative, restore or rewrite at least:

- Generic verifier/oracle invalidation after transforms.
- Generic BTF deletion/shift remap behavior.
- Branch-flip unsupported Jcc and asymmetric layout.
- Bounds-check merge different-root and different-error-target negatives.
- ABI payload tests for `ccmp`, `cond_select`, `bulk_memory`, and `prefetch`.
- Rotate dst-overwrite/clobber negatives.
- Extract/endian branch-fixup pass-path tests.
- map_inline overlay fail-fast, pseudo-map cascade, and uniform per-CPU policy.
- skb_load_bytes positive ctx reload and length matrix.
- wide_mem pointer gate matrix positive legs.

These are not all Section 2 critical rows, but they are real behavior guards.
