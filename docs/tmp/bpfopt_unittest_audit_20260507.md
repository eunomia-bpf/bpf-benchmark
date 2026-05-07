# bpfopt unit test audit - 2026-05-07

Scope: `bpfopt/crates/bpfopt/src/pass_tests.rs`, `passes/mod_tests.rs`, `passes/bulk_memory_tests.rs`, `passes/cond_select_tests.rs`, `passes/wide_mem_tests.rs`, and `passes/map_inline_tests.rs`.

Rule applied: `CLAUDE.md` "Unit Test Quality". Tests survive only when they catch a specific logic branch, state transition, boundary, error path, external encoding/ABI contract, or bug regression. `docs/kernel-jit-optimization-plan.md` was used as context for v3 CLI-first design, fail-fast behavior, and the split between unit tests and CLI integration tests.

MERGE means the coverage is worth preserving, but the existing separate test should be folded into a table-driven or broader neighboring test to cut LoC.

## Summary

| File | Total | Keep | Delete | Merge |
| --- | ---: | ---: | ---: | ---: |
| `bpfopt/crates/bpfopt/src/pass_tests.rs` | 16 | 12 | 1 | 3 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 13 | 9 | 3 | 1 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs` | 21 | 8 | 2 | 11 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 27 | 12 | 6 | 9 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs` | 31 | 16 | 2 | 13 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 59 | 47 | 2 | 10 |
| **Total** | **167** | **104** | **16** | **47** |

Specific audit flags:

- No `size_of`-only ABI/layout unit tests were found in the requested files.
- No direct self-equality or tautological `assert_eq!(x, x)` tests were found.
- No standalone debug-formatting tests were found.
- CLI integration duplicates exist and should be cut from unit coverage where noted below.
- Exact diagnostic-string assertions should survive only for fail-fast user-facing errors. Pure progress/skip formatting should be dropped when the owning test is merged.

## Recommended deletions

| Test | File:line | Reason |
| --- | --- | --- |
| `test_pass_manager_empty_pipeline` | `bpfopt/crates/bpfopt/src/pass_tests.rs:328` | Mock-only no-op pipeline smoke; no distinct bug beyond "zero passes returns zero results". |
| `test_default_pipeline_wide_mem` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:269` | Just runs the broad default pipeline without behavioral assertions; belongs in integration, not unit. |
| `test_map_inline_only_pipeline_contains_only_map_inline` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:278` | Trivial one-entry registry/pass-name check, covered by custom-order and CLI single-pass tests. |
| `cascade_map_inline_emits_non_zero_mov_constant` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:311` | Duplicate of map-inline scalar rewrite coverage; despite the name it is not a cascade test. |
| `test_empty_program` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:337` | Empty no-op behavior with no optimizer branch beyond iterating an empty vector. |
| `test_kfunc_not_available_skipped` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:529` | Duplicates `tests/cli_pipeline.rs:468`; v3 CLI fail-fast owns missing-kinsn behavior. |
| `test_cond_select_short_pattern_c_emit_jne` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:161` | Only verifies that some kfunc call exists; stronger sidecar/payload tests cover the emitted contract. |
| `test_cond_select_no_emit_3insn_pattern_b` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:375` | Duplicate of `test_cond_select_pattern_b_removed`; if analyzer rejects the pattern, the pass cannot emit it. |
| `test_cond_select_emit_with_reg_values` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:482` | Duplicate of alias-overlap and payload tests; non-overlap r6/r7 variant adds no new branch. |
| `test_cond_select_packed_keeps_live_regs` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:510` | Assertion only checks `sites_applied`; it does not verify preserved live-register semantics. |
| `test_cond_select_packed_no_callee_saved_dependency` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:529` | Assertion only checks `sites_applied`; no callee-saved dependency is actually verified. |
| `test_cond_select_no_sites_linear` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:552` | Duplicate no-site pass wrapper around analyzer no-site coverage. |
| `test_wide_mem_pass_no_sites` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:260` | Duplicate no-op wrapper around `scan_wide_mem` no-match coverage. |
| `test_is_packet_unsafe_prog_type` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:560` | Pure prog-type classification/const alias check; pass-level packet-gate tests cover behavior. |
| `map_inline_pass_errors_when_array_snapshot_key_is_absent` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2005` | Duplicates CLI integration error-path coverage in `tests/cli_pipeline.rs:343`. |
| `map_inline_pass_records_inlined_sites` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2069` | Metadata-only duplicate; inlined record contracts are already checked by pseudo-value, stack-snapshot, and percpu tests. |

## Recommended merges

| Test | File:line | Merge target | Reason |
| --- | --- | --- | --- |
| `test_bpf_program_sync_annotations_grow` | `bpfopt/crates/bpfopt/src/pass_tests.rs:261` | `sync_annotations_resizes_both_directions` | Grow and shrink are the same resize state machine; one table covers both. |
| `test_bpf_program_sync_annotations_shrink` | `bpfopt/crates/bpfopt/src/pass_tests.rs:271` | `sync_annotations_resizes_both_directions` | Same resize branch family as grow. |
| `test_pass_skips_without_branchless_select_capability` | `bpfopt/crates/bpfopt/src/pass_tests.rs:494` | cond-select capability matrix | This belongs with cond-select kfunc/cmov availability tests, not pass-manager tests. |
| `cascade_hash_map_removes_lookup_and_null_path_then_folds_non_null_path` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:434` | cascade map-inline/const-prop/dce matrix | Duplicate cascade shape; hash-specific behavior is already covered in map-inline units. |
| `test_no_consecutive_stores` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:346` | bulk-memory negative-pattern matrix | Same "do not rewrite this run" family as threshold and non-repeated immediate cases. |
| `test_memset_nonzero_immediate_pattern` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:390` | memset fill-encoding matrix | Immediate-fill variants can be table-driven. |
| `test_memset_byte_immediate_truncates_to_imm8` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:401` | memset fill-encoding matrix | Boundary case worth keeping, not as a separate body. |
| `test_memset_negative_dw_immediate_uses_ff_fill` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:412` | memset fill-encoding matrix | Sign-extension boundary fits the same encoding table. |
| `test_memset_non_repeated_immediate_unchanged` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:423` | bulk-memory negative-pattern matrix | Negative immediate-repeat guard can share setup/assertion. |
| `test_below_threshold_unchanged` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:433` | bulk-memory negative-pattern matrix | Threshold guard is one row in the negative matrix. |
| `test_different_base_regs_not_merged` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:443` | bulk-memory segmentation matrix | Same split/rewrite assertion style as non-consecutive and interleaved runs. |
| `test_non_consecutive_offsets_split` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:469` | bulk-memory segmentation matrix | Same split/rewrite assertion style as different-base and interleaved runs. |
| `test_memcpy_preserves_surrounding` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:492` | canonical memcpy rewrite test | Prefix/suffix preservation can be built into the primary memcpy transform test. |
| `test_interleaved_non_store_splits` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:515` | bulk-memory segmentation matrix | Same split/rewrite branch family. |
| `test_memset_nonzero_reg_pattern` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:556` | memset fill-encoding matrix | Register-fill payload is another row in the fill encoding table. |
| `test_cond_select_short_pattern_c_with_reg_values` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:127` | cond-select Pattern C analyzer table | Reg/imm value source is a table input, not a standalone branch. |
| `test_cond_select_analyze_no_match_different_dst` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:183` | cond-select no-match analyzer matrix | Same "reject malformed diamond" family. |
| `test_cond_select_analyze_reg_values_4insn` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:196` | cond-select Pattern A analyzer table | Register-valued diamond is a row in the Pattern A table. |
| `test_cond_select_analyze_no_sites_in_linear_program` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:236` | cond-select no-match analyzer matrix | Linear no-site case can share no-match assertions. |
| `test_cond_select_emit_imm_true_reg_false` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:295` | cond-select value-materialization table | Immediate/register combinations can be table-driven over expected payload regs. |
| `test_cond_select_emit_reg_true_imm_false` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:314` | cond-select value-materialization table | Same branch family as the other materialization combinations. |
| `test_cond_select_emit_reg32_true_imm_false` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:334` | cond-select value-materialization table | Width-specific row in the materialization table. |
| `test_cond_select_emit_both_immediate_values` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:355` | cond-select value-materialization table | Both-immediate row in the same materialization table. |
| `test_cond_select_emit_cond_reg_is_r3` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:563` | `test_cond_select_alias_all_overlap_combinations` | `cond_reg == r3` is already inside the exhaustive alias space. |
| `test_scan_wide_mem_2byte` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:67` | low-first wide-mem scan table | Width 2 and width 4 share matcher assertions. |
| `test_scan_wide_mem_embedded_in_program` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:93` | wide-mem scan-position table | Embedded start-PC assertion can be covered with multi-site/offset cases. |
| `test_wide_mem_pass_multiple_sites` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:338` | wide-mem pass transform matrix | Multiple-site apply count can be one pass-transform row. |
| `test_branch_fixup_forward_across_site` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:389` | wide-mem branch-fixup table | Forward/backward/conditional fixups share setup and expected offset logic. |
| `test_branch_fixup_backward_across_site` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:408` | wide-mem branch-fixup table | Same fixup table as forward branch. |
| `test_conditional_branch_fixup` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:428` | wide-mem branch-fixup table | Same fixup table as unconditional branches. |
| `test_wide_mem_pass_skips_unsupported_width_3` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:483` | unsupported/mixed-width table | Width-3 skip should be a row beside the width4-applies/width3-skips mixed case. |
| `test_wide_mem_skips_non_stack_in_xdp` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:575` | packet-pointer gate matrix | Packet safety cases should be table-driven by prog type and base provenance. |
| `test_wide_mem_allows_stack_base_in_xdp` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:599` | packet-pointer gate matrix | Same gate family as non-stack XDP and tracing cases. |
| `test_wide_mem_allows_map_value_base_in_xdp` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:628` | packet-pointer gate matrix | Map-value provenance is a packet-gate row. |
| `test_wide_mem_allows_non_stack_in_tracing` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:651` | packet-pointer gate matrix | Non-packet prog type is a packet-gate row. |
| `test_wide_mem_applies_without_verifier_states` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:783` | verifier-state pointer-type gate matrix | No-state and scalar-state positive cases can sit beside the BTF-pointer negative regression. |
| `test_wide_mem_applies_when_verifier_shows_scalar_base` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:803` | verifier-state pointer-type gate matrix | Same matrix as no-state and BTF-pointer cases. |
| `map_inline_constantizes_snapshot_pseudo_map_idx_value_loads` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:532` | pseudo-map-value source matrix | `PSEUDO_MAP_VALUE` and `PSEUDO_MAP_IDX_VALUE` differ only by source flavor. |
| `verifier_guided_key_extracts_store_via_fp_alias_base` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:701` | verifier-guided key extraction matrix | Same verifier-guided extraction branch family as wide-zero and fp-alias cases. |
| `map_inline_pass_rewrites_lookup_with_fp_alias_store_key_and_offset_load` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:990` | map-inline lookup rewrite matrix | Helper branches are already kept; this can be a compact end-to-end row. |
| `map_inline_pass_emits_ldimm64_for_wide_constants` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1156` | struct-value/wide-constant emission matrix | `LDIMM64` emission is already asserted by the struct multi-field case; keep boundary as a row. |
| `map_inline_runtime_key_readonly_large_snapshot_has_no_entry_limit` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1252` | runtime-key readonly snapshot matrix | The no-entry-limit case can be folded into the runtime-key snapshot test with `>64` entries. |
| `map_inline_pass_uses_stack_snapshot_for_256_byte_key` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1394` | stack-snapshot key-size matrix | Large key-size boundary belongs with 16-byte and 20-byte snapshot cases. |
| `map_inline_pass_uses_verifier_guided_wide_zero_store_key` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1645` | verifier-guided stack-snapshot pass matrix | Pass-level version of earlier verifier-guided key extraction; fold into one pass matrix. |
| `map_inline_pass_removes_hash_lookup_and_null_path_when_entry_present` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1683` | null-path removal array/hash matrix | Same rewrite shape as the array null-path test; drop pure diagnostic-string assertions. |
| `map_inline_pass_uses_stack_snapshot_for_20_byte_key` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1723` | stack-snapshot key-size matrix | Another key-size row, not a separate body. |
| `map_inline_pass_errors_when_percpu_array_default_snapshot_is_absent` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2132` | snapshot-missing error matrix | Same fail-fast error family as missing array snapshot; keep percpu as a row. |

## Justified keeps

| Test | File:line | What bug would this catch |
| --- | --- | --- |
| `test_prepend_nop_pass_shifts_annotations_forward` | `bpfopt/crates/bpfopt/src/pass_tests.rs:150` | A transform inserting instructions but leaving PGO/profile annotations attached to stale PCs. |
| `test_analysis_cache_basic` | `bpfopt/crates/bpfopt/src/pass_tests.rs:282` | Analysis results not being cached by result type, causing stale/missing analysis reuse behavior. |
| `test_analysis_cache_targeted_invalidation_for_known_types` | `bpfopt/crates/bpfopt/src/pass_tests.rs:294` | Targeted invalidation accidentally clearing unrelated analyses or failing to clear the requested one. |
| `test_pass_manager_multiple_passes_sequential` | `bpfopt/crates/bpfopt/src/pass_tests.rs:341` | Pass manager running passes out of order or failing to propagate prior program mutations. |
| `test_pass_manager_analysis_cache_invalidation` | `bpfopt/crates/bpfopt/src/pass_tests.rs:365` | A transform leaving cached analysis stale for a later pass. |
| `test_pass_manager_rejects_unregistered_required_analysis` | `bpfopt/crates/bpfopt/src/pass_tests.rs:392` | Silent success when a pass declares an analysis dependency that the manager cannot provide. |
| `test_pass_manager_invalidates_verifier_states_after_transform` | `bpfopt/crates/bpfopt/src/pass_tests.rs:408` | Reusing verifier states after bytecode mutation, which would poison verifier-guided passes. |
| `test_pass_manager_enabled_pass_policy` | `bpfopt/crates/bpfopt/src/pass_tests.rs:435` | Disabled passes running despite policy filtering. |
| `test_remap_annotations_deleted_instruction` | `bpfopt/crates/bpfopt/src/pass_tests.rs:456` | Annotation remap losing branch profiles or indexing past the new program after deletion. |
| `test_profiling_data_injection` | `bpfopt/crates/bpfopt/src/pass_tests.rs:476` | PGO branch profiles being injected into the wrong instruction annotation. |
| `test_invalid_policy_pass_name_is_rejected` | `bpfopt/crates/bpfopt/src/pass_tests.rs:530` | Legacy/unknown pass aliases being silently ignored instead of rejected fail-fast. |
| `test_pass_result_insns_before_after_filled_by_pass_manager` | `bpfopt/crates/bpfopt/src/pass_tests.rs:547` | Per-pass report metadata recording wrong before/after instruction counts. |
| `pass_registry_declares_all_emitted_kinsn_probe_names` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:170` | Registry metadata missing a kinsn probe alias needed for target capability discovery. |
| `test_cfg_analysis_with_subprogs` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:192` | CFG analysis failing to discover a normal pseudo-call subprogram boundary. |
| `test_cfg_analysis_with_callback_subprog_refs` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:212` | CFG analysis ignoring `BPF_PSEUDO_FUNC` callback references. |
| `test_liveness_across_branch` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:234` | Liveness analysis losing registers across branch joins. |
| `test_branch_targets_backward_jump` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:255` | Branch-target analysis failing on negative jump offsets. |
| `test_build_custom_pipeline_respects_registry_order` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:286` | Custom pipeline construction using caller order instead of canonical registry order. |
| `test_build_custom_pipeline_rejects_unknown_pass_name` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:301` | Unknown pass names being accepted or partially ignored. |
| `cascade_const_prop_folds_non_zero_map_inline_output` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:335` | `const_prop` failing to consume constants emitted by a prior `map_inline` pass. |
| `cascade_full_pipeline_materializes_alu_and_leaves_branch_cleanup_to_kernel` | `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:370` | The pass cascade changing sequencing, losing DCE, or performing forbidden framework-side branch cleanup. |
| `test_memcpy_pattern_8_pairs` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:356` | Bulk memcpy lowering emitting the wrong packed kinsn payload for a normal run. |
| `test_memcpy_pattern_inside_multi_subprog_program` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:367` | Scanner/rewrite logic crossing or missing subprogram boundaries. |
| `test_memset_zero_pattern` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:379` | Zero-fill store runs lowering to the wrong memset payload. |
| `test_non_stack_base_memcpy_skipped_by_alias_gate` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:456` | Rewriting memcpy when alias safety cannot be proven. |
| `test_mixed_widths_handled` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:482` | Mixed-width store runs being merged incorrectly or losing the valid segment. |
| `test_branch_fixup_after_replacement` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:505` | Branch offsets not being repaired after a bulk-memory replacement shrinks code. |
| `test_same_base_chunked_overlap_skipped` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:543` | Rewriting same-base overlapping memcpy runs that could clobber source bytes. |
| `test_memcpy_proof_tmp_live_out_skipped` | `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:569` | Rewriting when the temporary load register is live after the candidate site. |
| `test_cond_select_analyze_4insn_diamond` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:72` | Failing to detect the canonical four-instruction conditional-select diamond. |
| `test_cond_select_pattern_b_removed` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:92` | Reintroducing the semantically wrong Pattern B match. |
| `test_cond_select_analyze_short_pattern_c` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:107` | Failing to detect the valid short Pattern C form. |
| `test_cond_select_short_pattern_c_no_match_cond_clobbered` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:142` | Rewriting a Pattern C candidate that changes the condition register before testing it. |
| `test_cond_select_analyze_multiple_sites` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:213` | Scanner stopping after the first conditional-select site. |
| `test_cond_select_skip_when_kfunc_unavailable` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:250` | Emitting cond-select kinsns when the required kfunc id is unavailable. |
| `test_cond_select_emit_on_arm64_select_kfunc_without_cmov` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:272` | Incorrectly requiring x86 CMOV when arm64 has a select kinsn. |
| `test_cond_select_emit_jeq_swaps_args` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:392` | JEQ lowering swapping true/false operands incorrectly. |
| `test_cond_select_emit_non_zero_compare_imm` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:419` | Non-zero compare immediate lowering losing the XOR predicate normalization. |
| `test_cond_select_emit_jmp32_zero_compare_predicate` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:440` | JMP32 predicate lowering using 64-bit register semantics. |
| `test_cond_select_emit_jgt_predicate_prefix` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:460` | Non-equality predicates being normalized with the wrong prefix branch. |
| `test_cond_select_alias_all_overlap_combinations` | `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:614` | Parallel-copy alias hazards when cond/true/false operands overlap in r1/r2/r3. |
| `test_scan_wide_mem_4byte` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:53` | Low-first wide-memory matcher recording wrong bindings for the canonical 4-byte pattern. |
| `test_scan_wide_mem_no_match` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:81` | False-positive wide-memory matches on non-consecutive offsets. |
| `test_scan_wide_mem_multiple_sites` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:104` | Scanner missing later independent wide-memory sites. |
| `test_scan_high_first_2byte` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:135` | High-byte-first two-byte pattern not being recognized. |
| `test_scan_high_first_matches_clang_output` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:149` | Regression against real Clang-style high-first byte-ladder output. |
| `test_scan_high_first_no_false_positive` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:174` | Accidentally widening across a malformed high-first sequence. |
| `test_emit_wide_mem_supported_widths` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:193` | Emitting the wrong load opcode/register/offset for supported widths. |
| `test_emit_wide_mem_unsupported_width` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:231` | Unsupported width being emitted instead of rejected. |
| `test_wide_mem_pass_transforms_correctly` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:272` | End-to-end wide-memory pass emitting the wrong halfword load. |
| `test_wide_mem_pass_skips_misaligned_halfword_site` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:294` | Rewriting a misaligned wide load that verifier/hardware semantics may reject. |
| `test_wide_mem_pass_skips_site_with_interior_branch_target` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:316` | Rewriting a region with an interior branch target. |
| `test_wide_mem_pass_skips_site_with_live_scratch_reg` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:360` | Clobbering a scratch register that is live after the candidate site. |
| `test_wide_mem_skips_byte_ladder_with_pseudo_func_boundary_inside` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:452` | Treating the second half of a pseudo-function `LDIMM64` as ordinary code during rewrite. |
| `test_wide_mem_pass_applies_width4_skips_width3_mixed` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:517` | One unsupported site preventing an independent supported site from applying. |
| `test_wide_mem_mixed_sites_xdp_some_skipped` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:670` | Mixed packet-safe and packet-unsafe sites being all-applied or all-skipped. |
| `test_wide_mem_skips_merge_when_base_is_btf_struct_ptr` | `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:742` | Cilium-style BTF struct pointer field-boundary violation from unsafe widening. |
| `find_map_lookup_sites_matches_helper_one_with_map_arg` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:389` | Map-lookup scanner missing a helper-1 call with a preceding pseudo map load. |
| `find_map_lookup_sites_ignores_calls_without_map_load` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:411` | False-positive map-lookup sites when r1 is not a map pointer. |
| `find_map_in_map_chains_detects_r0_to_r1_alias` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:423` | Map-in-map chain discovery missing the direct r0-to-r1 alias path. |
| `find_map_in_map_chains_detects_stack_spilled_r0_to_r1_alias` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:452` | Map-in-map chain discovery missing stack-spilled inner-map pointer aliases. |
| `find_map_in_map_chains_ignores_absent_alias` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:482` | False-positive map-in-map chains when the inner lookup uses a different map source. |
| `map_inline_constantizes_snapshot_pseudo_map_value_loads` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:505` | Pseudo map-value loads resolving the wrong map/key/value and record metadata. |
| `map_inline_pseudo_map_value_feeds_const_prop_and_dce_without_branch_cleanup` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:559` | Pseudo map-value constants failing to feed later passes while preserving kernel-owned branch cleanup. |
| `extract_constant_key_from_direct_stack_store` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:592` | Constant key extraction missing a direct stack immediate store. |
| `extract_constant_key_from_stx_stack_store` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:612` | Constant key extraction missing an STX store from a known scalar register. |
| `extract_constant_key_from_r2_copy_chain` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:631` | Constant key extraction failing when r2 is reached through a copied frame-pointer chain. |
| `verifier_guided_key_extracts_wide_zero_store_subrange` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:651` | Verifier-guided extraction losing a subrange of a wider zero store. |
| `extract_constant_key_from_fp_alias_store_base` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:682` | Constant key extraction missing a store through an fp alias base. |
| `extract_constant_key_from_ldimm64_stack_store` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:727` | Constant key extraction truncating or missing 64-bit `LDIMM64` key stores. |
| `classify_r0_uses_collects_fixed_loads_until_redefinition` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:749` | R0-use classifier reading loads past an r0 redefinition or missing earlier fixed loads. |
| `classify_r0_uses_tracks_alias_copies_and_guarded_loads` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:780` | R0-use classifier missing alias copies and the guarding null check. |
| `classify_r0_uses_tracks_alias_offset_loads` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:797` | Offset aliases losing the accumulated value offset. |
| `classify_r0_uses_does_not_treat_non_zero_alias_offset_as_null_check` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:820` | Treating a null check on an offset alias as proof that the original lookup pointer is non-null. |
| `classify_r0_uses_can_follow_callee_saved_alias_across_helper_when_enabled` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:844` | Either following unsafe aliases in strict mode or failing the explicit relaxed path. |
| `classify_r0_uses_tracks_stack_spill_and_reload_across_helper` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:872` | Losing lookup-value aliases spilled to stack across helper calls. |
| `classify_r0_uses_allows_helper_argument_loaded_from_lookup_value` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:897` | Marking a scalar loaded from the lookup value and passed to a helper as pointer escape. |
| `classify_r0_uses_marks_pointer_escape_after_null_check_as_other` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:920` | Removing a lookup whose pointer escapes to a helper after the null check. |
| `classify_r0_uses_marks_store_back_as_other_use` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:936` | Removing a lookup when the program writes back through the map-value pointer. |
| `map_inline_pass_rewrites_lookup_and_scalar_loads` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:959` | Canonical array lookup rewrite failing to replace fixed scalar loads and remove setup. |
| `map_inline_pass_rewrites_struct_value_multiple_fields` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1025` | Multi-field values emitting wrong 32-bit or 64-bit constants. |
| `map_inline_pass_rewrites_u32_max_with_mov32_imm` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1058` | `0xffffffff` being emitted with the wrong 32-bit immediate semantics. |
| `map_inline_pass_removes_null_check_and_dead_cold_block` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1091` | Proven-present array lookup leaving dead null path or stale helper setup. |
| `map_inline_pass_keeps_null_check_when_non_null_window_has_side_effects` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1124` | Removing a lookup/null check when the non-null window has side effects. |
| `map_inline_pass_skips_non_constant_key` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1182` | Inlining when the lookup key is not verifier-proven constant. |
| `map_inline_runtime_key_readonly_small_snapshot_emits_chain` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1210` | Runtime-key read-only snapshots failing to emit a lookup-free key dispatch chain. |
| `map_inline_runtime_key_ignores_bpf_writable_map` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1290` | Inlining a runtime-key map that BPF code can mutate. |
| `map_inline_pass_skips_pseudo_map_value_lookup_key_without_verifier_state` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1321` | Using a pseudo-map-value key without verifier stack/state proof. |
| `map_inline_pass_uses_stack_snapshot_for_16_byte_key` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1353` | Multi-slot verifier stack snapshots being decoded in the wrong byte order. |
| `map_inline_pass_uses_full_state_stack_snapshot_for_key` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1424` | Ignoring edge/full verifier states and only reading delta states. |
| `map_inline_pass_reports_unavailable_when_call_stack_snapshot_is_absent` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1459` | Treating an fp register state without stack bytes as a concrete key. |
| `map_inline_pass_requires_explicit_precise_stack_scalar` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1490` | Inlining from imprecise verifier stack scalar data. |
| `map_inline_pass_rewrites_map_in_map_chain_loads` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1529` | Map-in-map chains failing to resolve the live inner map id and inner key. |
| `map_inline_pass_skips_missing_outer_map_in_map_entry` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1601` | Inlining a map-in-map chain when the outer snapshot has no live inner-map entry. |
| `map_inline_pass_keeps_hash_lookup_and_rewrites_jne_guarded_load` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1757` | Hash lookup with JNE guard losing the lookup or failing to rewrite the guarded load. |
| `map_inline_pass_keeps_lookup_and_rewrites_load_when_setup_has_branch_target` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1796` | Removing helper setup that contains a branch target instead of only rewriting safe loads. |
| `map_inline_pass_removes_hash_lookup_before_helper_using_loaded_scalar` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1849` | Over-conservative pointer-escape handling when only a loaded scalar is passed to a helper. |
| `map_inline_pass_does_not_use_non_verifier_fixpoint_fallback` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1885` | Reintroducing a non-verifier fallback contrary to v3 fail-fast design. |
| `map_inline_pass_rewrites_lookup_inside_subprog` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1935` | Subprogram rewrite changing pseudo-call offsets or missing lookup sites inside subprogs. |
| `map_inline_pass_inlines_mutable_array_across_readonly_helper_call` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1973` | Treating a read-only helper call as a possible map mutation and blocking safe inlining. |
| `map_inline_pass_skips_size_skipped_array_map` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2030` | Inlining a map whose snapshot was explicitly skipped by size policy. |
| `map_inline_pass_inlines_uniform_percpu_array_maps` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2099` | Failing to inline a `PERCPU_ARRAY` whose per-CPU values are uniform. |
| `map_inline_pass_skips_mixed_percpu_array_maps` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2156` | Inlining a `PERCPU_ARRAY` whose per-CPU values differ. |
| `map_inline_pass_skips_percpu_hash_family_maps` | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:2190` | Inlining unsupported percpu hash-family map types. |
