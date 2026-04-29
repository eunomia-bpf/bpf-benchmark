# P71 Test + Mock Audit

Date: 2026-04-29

## Scope

P71 focused on bpfopt test/mock cleanup only. No `daemon/src/`, runner Python, KVM
test path, or `runner-runtime.Dockerfile` changes were made for this task.

## SnapshotMapProvider DI Refactor

`SnapshotMapProvider` is now a production/offline snapshot provider only. The three
test-only fallback branches were removed from `bpfopt/crates/bpfopt/src/pass.rs`.
Missing map metadata/value now surfaces through the snapshot error path.

Clean production shape:

```rust
impl MapInfoProvider for SnapshotMapProvider {
    fn map_info(&self, program: &BpfProgram, map_id: u32) -> Result<Option<MapInfo>, String> {
        let Some(metadata) = program.map_metadata.get(&map_id) else {
            return Err(format!("map_values snapshot has no metadata for map {}", map_id));
        };
        Ok(Some(MapInfo { /* snapshot metadata */ }))
    }
}

impl MapValueProvider for SnapshotMapProvider {
    fn lookup_elem(...) -> Result<Vec<u8>, String> {
        if let Some(value) = program.map_values.get(&(map_id, key.to_vec())) {
            return Ok(value.clone());
        }
        if program.map_value_nulls.contains(&(map_id, key.to_vec())) {
            return Err(null_map_value_snapshot_message(map_id, key));
        }
        Err(missing_map_value_snapshot_message(map_id, key))
    }
}
```

The test-only behavior moved to `bpfopt/crates/bpfopt/src/mock_maps.rs`:

```rust
#[derive(Clone, Debug, Default)]
pub struct MockMapProvider;

impl MapInfoProvider for MockMapProvider { /* snapshot first, then thread-local mock */ }
impl MapValueProvider for MockMapProvider { /* snapshot first, then thread-local mock */ }

pub fn use_mock_maps(program: &mut BpfProgram) {
    program.set_map_providers(Arc::new(MockMapProvider), Arc::new(MockMapProvider));
}
```

Test entry points that need mock maps now inject the provider explicitly:

- `map_inline_tests.rs`: `try_run_map_inline_pass`, `run_map_inline_const_prop_dce`
- `mod_tests.rs`: `run_pipeline_with_passes`, the full-pipeline cascade test
- `const_prop.rs`: `const_prop_folds_branch_after_map_inline`

## mock_maps Decision

`mock_maps.rs` is retained as a shared test fixture and DI provider. This is cleaner
than inlining map fixtures into each pass test because map-inline, const-prop, and
pipeline tests all share the same thread-local mock map model.

Cleanup inside `mock_maps.rs`:

- Added `MockMapProvider` implementing `MapInfoProvider` and `MapValueProvider`.
- Added `use_mock_maps(&mut BpfProgram)` as the explicit DI hook.
- Removed `apply_mock_maps`; no caller remained after provider injection.
- Removed unused fixture fields `BpfMapInfo::id` and `BpfMapInfo::map_flags`.
- Made internal mock lookup helpers private.

## LOC Audit

| Path | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 2663 | 1849 | -814 |
| `bpfopt/crates/bpfopt/src/pass_tests.rs` | 955 | 813 | -142 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs` | 937 | 702 | -235 |
| `bpfopt/crates/bpfopt/tests/cli_pipeline.rs` | 658 | 496 | -162 |
| `bpfopt/crates/bpfopt/src/mock_maps.rs` | 125 | 169 | +44 |
| `bpfopt/crates/bpfprof/tests/cli.rs` | 107 | 47 | -60 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 650 | 650 | 0 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs` | 618 | 618 | 0 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 426 | 427 | +1 |
| `bpfopt/crates/bpfget/tests/cli.rs` | 325 | 325 | 0 |
| `bpfopt/crates/bpfrejit/tests/cli.rs` | 177 | 177 | 0 |
| `bpfopt/crates/bpfverify/tests/cli.rs` | 159 | 159 | 0 |
| `bpfopt/crates/kernel-sys/tests/prog_ids.rs` | 25 | 25 | 0 |
| `bpfopt/crates/kernel-sys/tests/prog_get_original.rs` | 77 | 77 | 0 |
| **Total audited set** | **7902** | **6534** | **-1368** |

## Deleted / Merged Tests

| File | Original line | Test | Reason |
| --- | ---: | --- | --- |
| `map_inline_tests.rs` | 501 | `extract_constant_key_from_r2_add_reg_constant` | Repeated constant key extraction variant; stricter r2 copy, fp-alias, ldimm64, and verifier-guided cases remain. |
| `map_inline_tests.rs` | 834 | `map_inline_pass_rewrites_loads_from_alias_register` | Same alias-load rewrite behavior is covered by classification tests and guarded JNE pass behavior. |
| `map_inline_tests.rs` | 1100 | `map_inline_pass_emits_mov64_imm_for_dw_constants_that_fit_i32` | Emission behavior overlaps scalar-load and wide-constant tests; did not catch a distinct branch. |
| `map_inline_tests.rs` | 1166 | `test_map_inline_real_clang_order` | Documentation-style input ordering variant; existing key extraction and rewrite tests cover the behavior. |
| `map_inline_tests.rs` | 1206 | `map_inline_pass_removes_interleaved_side_effect_free_setup_gap` | Minor setup-gap permutation of the same lookup rewrite. |
| `map_inline_tests.rs` | 1247 | `test_map_inline_r2_clobbered_between` | Duplicate non-constant-key skip path; `map_inline_pass_skips_non_constant_key` remains. |
| `map_inline_tests.rs` | 1276 | `map_inline_pass_rewrites_array_lookup_with_pseudo_map_value_zero_key` | Weaker pseudo-map-value key case; 20-byte pseudo-map-value key case remains. |
| `map_inline_tests.rs` | 1355 | `map_inline_pass_rewrites_lookup_with_split_halfword_key_materialization` | Repeated split-key materialization; 16-byte split-DW key case is stricter. |
| `map_inline_tests.rs` | 1586 | `map_inline_pass_removes_hash_lookup_via_alias_guarded_load` | Duplicate alias guarded-load rewrite. |
| `map_inline_tests.rs` | 1626 | `classify_r0_uses_tracks_jne_null_check` | Helper-only variant covered by pass-level JNE guarded-load test. |
| `map_inline_tests.rs` | 1653 | `classify_r0_uses_tracks_backward_jeq_null_check` | Helper-only branch-offset variant with no unique pass behavior. |
| `map_inline_tests.rs` | 1785 | `map_inline_pass_rewrites_load_before_pointer_escape_to_helper` | Weaker partial-rewrite-before-escape case; loaded-scalar helper case remains. |
| `map_inline_tests.rs` | 1874 | `map_inline_pass_rewrites_load_before_lookup_result_write_back` | Same partial load rewrite category as the retained pointer-use cases. |
| `map_inline_tests.rs` | 1918 | `map_inline_pass_rewrites_multiple_lookup_sites` | Simple multi-site duplicate; cascading fixpoint case still covers multiple lookup sites. |
| `map_inline_tests.rs` | 1964 | `map_inline_pass_reaches_fixpoint_across_cascading_lookup_keys` | Weaker cascading case; stack-reloaded-key fixpoint case remains. |
| `map_inline_tests.rs` | 2111 | `map_inline_pass_inlines_non_frozen_array_maps` | Covered by mutable array read-only helper case and mutable store-back rejection. |
| `map_inline_tests.rs` | 2173 | `map_inline_pass_inlines_read_only_site_after_same_map_writeback_elsewhere` | Repeated mutable-array combination; store-back skip and read-only helper cases remain. |
| `map_inline_tests.rs` | 2229 | `map_inline_pass_keeps_other_mutable_read_only_maps_inlineable` | Cross-map permutation of retained mutable-map behavior. |
| `map_inline_tests.rs` | 2311 | `map_inline_pass_skips_hash_lookup_across_readonly_helper_call` | Duplicate helper-crossing skip; mutable side-effect helper skip remains. |
| `map_inline_tests.rs` | 2399 | `map_inline_pass_errors_when_percpu_array_snapshot_key_is_absent` | Same missing snapshot error contract as retained array and per-cpu default-missing tests. |
| `map_inline_tests.rs` | 2454 | `map_inline_pass_uses_nonzero_snapshot_value_for_array_maps` | Non-zero snapshot value covered by tracker and core rewrite tests. |
| `map_inline_tests.rs` | 2590 | `map_inline_pass_skips_percpu_hash_maps` | Merged into table-driven `map_inline_pass_skips_percpu_hash_family_maps`. |
| `map_inline_tests.rs` | 2628 | `map_inline_pass_skips_lru_percpu_hash_maps` | Merged into table-driven `map_inline_pass_skips_percpu_hash_family_maps`. |
| `pass_tests.rs` | 318 | `test_bpf_program_log_transform` | Trivial state predicate test. |
| `pass_tests.rs` | 344 | `test_analysis_cache_invalidate_all` | Duplicate cache invalidation shape; targeted invalidation and manager invalidation remain. |
| `pass_tests.rs` | 357 | `test_analysis_cache_invalidate_specific` | Duplicate cache invalidation shape. |
| `pass_tests.rs` | 419 | `test_pass_manager_single_pass_no_change` | Shallow single-pass result assertion covered by policy/debug/no-op paths. |
| `pass_tests.rs` | 436 | `test_pass_manager_single_pass_with_change` | Shallow single-pass mutation assertion covered by multi-pass and debug trace tests. |
| `pass_tests.rs` | 643 | `test_kinsn_registry_with_available_targets` | Mostly field-presence/getter behavior; per-target call offset contract remains. |
| `pass_tests.rs` | 696 | `test_remap_annotations_basic` | Insert remap covered by `test_prepend_nop_pass_shifts_annotations_forward`; deletion remap remains. |
| `wide_mem_tests.rs` | 127 | `test_scan_wide_mem_prefers_largest_width` | Duplicate of 4-byte scanner match assertions. |
| `wide_mem_tests.rs` | 175 | `test_scan_high_first_4byte` | Covered by clang-order high-first matcher test. |
| `wide_mem_tests.rs` | 214 | `test_scan_high_first_embedded` | Repeated embedded scan shape already covered for low-first. |
| `wide_mem_tests.rs` | 243 | `test_scan_high_first_prefers_largest` | Duplicate largest-width assertion. |
| `wide_mem_tests.rs` | 253 | `test_emit_wide_mem_4` | Merged into table-driven `test_emit_wide_mem_supported_widths`. |
| `wide_mem_tests.rs` | 285 | `test_emit_wide_mem_2` | Merged into table-driven `test_emit_wide_mem_supported_widths`. |
| `wide_mem_tests.rs` | 317 | `test_emit_wide_mem_8` | Merged into table-driven `test_emit_wide_mem_supported_widths`. |
| `wide_mem_tests.rs` | 378 | `test_wide_mem_pass_finds_sites` | Duplicate pass rewrite assertion; transform and manager tests remain. |
| `wide_mem_tests.rs` | 432 | `test_wide_mem_pass_preserves_branch_offsets` | Duplicate forward branch fixup case. |
| `wide_mem_tests.rs` | 535 | `test_wide_mem_pass_applies_when_scratch_dead` | Covered by normal transform test. |
| `wide_mem_tests.rs` | 767 | `test_wide_mem_skips_non_stack_in_tc` | Same packet-unsafe skip branch as XDP; program-type list test still covers TC classification. |
| `wide_mem_tests.rs` | 878 | `test_wide_mem_allows_non_stack_with_unknown_prog_type` | Same non-packet allow branch as tracing/default contexts. |
| `cli_pipeline.rs` | 190 | `wide_mem_report_is_valid_pass_report_json` | CLI report shape covered by optimize report smoke and pass-level tests. |
| `cli_pipeline.rs` | 339 | `direct_side_input_required_pass_fails_when_missing_input` | Duplicates optimize side-input fail-fast tests. |
| `cli_pipeline.rs` | 348 | `rotate_with_empty_target_kinsns_exits_with_error` | Covered by explicit optimize kinsn target failure. |
| `cli_pipeline.rs` | 370 | `cond_select_with_empty_target_kinsns_exits_with_error` | Same target-kinsn failure shape as retained optimize test. |
| `cli_pipeline.rs` | 392 | `optimize_explicit_const_prop_fails_when_verifier_states_missing` | Duplicates missing side-input contract covered by default optimize fail-fast. |
| `cli_pipeline.rs` | 418 | `optimize_explicit_map_inline_fails_when_map_side_inputs_missing` | Duplicates default optimize map-inline side-input error. |
| `cli_pipeline.rs` | 519 | `optimize_map_inline_errors_when_array_snapshot_value_is_null` | Covered by missing-key and hash-null snapshot CLI cases. |
| `bpfprof/tests/cli.rs` | 42 | `all_mode_writes_json_array_or_skips_without_kernel_access` | Environment-dependent success-or-skip smoke with weak bug signal. |
| `bpfprof/tests/cli.rs` | 89 | `show_mode_prints_table_or_skips_without_kernel_access` | Environment-dependent CLI table smoke; removed as low-value integration coverage. |

## Other Audited Files

- `cond_select_tests.rs`: retained. Remaining tests exercise packed-call liveness,
  alias cycles, condition register overlap, platform/kfunc skips, and branch rewrites.
- `bulk_memory_tests.rs`: retained. Tests cover memcpy/memset matching, overlap,
  branch fixup, kfunc availability, alias gate, and live temporary proof.
- `bpfget/tests/cli.rs`: retained. Kernel-dependent cases are the CLI boundary for
  target JSON, manual kinsn specs, and fail-fast missing program/outdir behavior.
- `bpfrejit/tests/cli.rs`: retained. Tests cover parse and fd/map side-input error
  paths before opening target programs.
- `bpfverify/tests/cli.rs`: retained. Tests cover pipe/report/verifier-states CLI
  contracts and missing required prog-type.
- `kernel-sys/tests/*`: retained. These are kernel ABI smoke tests; they skip only
  when the host lacks required BPF permissions or fork support.

## Verification

Passed:

- `cd bpfopt && cargo fmt --all -- --check`
- `cd bpfopt && cargo build --all-targets`
- `cd bpfopt && cargo clippy --all-targets -- -D warnings`
- `cd bpfopt && cargo test --all-targets`

No KVM validation was run.
