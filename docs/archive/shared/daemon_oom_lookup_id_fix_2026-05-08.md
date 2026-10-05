# Daemon map-in-map lookup id fix

## Changed LOC

Source change only, excluding this note:

```text
daemon/src/commands.rs: +9 / -15 (net -6)
```

## Fixed lookup_inner_map_id_for_outer_key

`BPF_MAP_LOOKUP_ELEM` on `ARRAY_OF_MAPS` / `HASH_OF_MAPS` returns the inner
map id as a `u32`, not a process-local fd. The daemon now preserves that id
directly and no longer calls `OwnedFd::from_raw_fd()` or
`map_obj_get_info_by_fd()` on the returned value.

```rust
fn lookup_inner_map_id_for_outer_key(
    outer_fd: BorrowedFd<'_>,
    outer_map_id: u32,
    key: &[u8],
) -> Result<Option<u32>> {
    let mut value_bytes = [0u8; 4];
    if !kernel_sys::map_lookup_elem(outer_fd, key, &mut value_bytes)
        .with_context(|| format!("BPF_MAP_LOOKUP_ELEM on outer map {outer_map_id}"))?
    {
        return Ok(None);
    }
    let inner_map_id = u32::from_ne_bytes(value_bytes);
    if inner_map_id == 0 {
        return Ok(None);
    }
    Ok(Some(inner_map_id))
}
```

The existing
`array_of_maps_supplement_iterates_all_slots_without_bpftool_keys` unit test
now names the mocked lookup value as `inner_map_id`, making the test fixture
match the kernel ABI directly instead of modeling an fd.

## Boundary cases

- `map_lookup_elem()` returns `false`: the outer key has no value, so the entry
  is omitted from the supplement.
- `inner_map_id == 0`: treated as an empty map-in-map slot and omitted from the
  supplement.
- `inner_map_id > 0`: written directly to `map-<outer>.inner_map_ids.json`.
- `map_lookup_elem()` error: propagated with outer map context; no warning and
  continue path.
- The returned id is never interpreted as a daemon fd, so no fd ownership is
  taken and no unrelated process fd can be closed or queried by accident.

## Test output

Command:

```text
cargo test --manifest-path daemon/Cargo.toml --workspace
```

Output:

```text
   Compiling bpfrejit-daemon v0.1.0 (/home/yunwei37/workspace/bpf-benchmark/daemon)
    Finished `test` profile [unoptimized + debuginfo] target(s) in 0.40s
     Running unittests src/main.rs (daemon/target/debug/deps/bpfrejit_daemon-5f1bb1c52564a847)

running 28 tests
test bpf::tests::canonicalize_round102_real_pattern_keeps_duplicate_fd_binding ... ok
test bpf::tests::canonicalize_rejects_more_unique_loader_fds_than_map_ids ... ok
test commands::tests::bytecode_decoder_rejects_unaligned_input ... ok
test bpf::tests::canonicalize_preserves_idx_without_loader_fd_array ... ok
test bpf::tests::canonicalize_remaps_all_four_pseudo_modes_with_loader_fd_array ... ok
test bpf::tests::canonicalize_rejects_pseudo_map_idx_out_of_range ... ok
test bpf::tests::canonicalize_round129_real_ldimm64_pattern_to_idx_order ... ok
test commands::tests::rejit_fd_array_builder_places_maps_first_and_module_btf_fds_at_call_offsets ... ok
test commands::tests::target_call_offsets_shift_after_map_prefix ... ok
test commands::tests::rejit_fd_array_builder_uses_btf_placeholder_when_no_maps ... ok
test commands::tests::rejit_fd_array_builder_rejects_conflicting_module_offsets ... ok
test commands::tests::rejit_fd_array_builder_rejects_missing_module_slot ... ok
test commands::tests::array_of_maps_supplement_iterates_all_slots_without_bpftool_keys ... ok
test server::tests::parse_execute_plan_accepts_empty_programs ... ok
test server::tests::parse_execute_plan_accepts_empty_steps_as_skip ... ok
test server::tests::optimize_response_keeps_per_program_errors_under_top_level_ok ... ok
test commands::tests::try_apply_programs_converts_failures_to_program_results ... ok
test server::tests::parse_execute_plan_rejects_blank_step_command ... ok
test server::tests::parse_execute_plan_parses_kop_probes ... ok
test server::tests::parse_execute_plan_rejects_duplicate_prog_id ... ok
test server::tests::parse_execute_plan_rejects_invalid_log_level ... ok
test server::tests::parse_execute_plan_rejects_kop_probe_with_no_aliases ... ok
test server::tests::parse_execute_plan_rejects_missing_log_level ... ok
test server::tests::parse_execute_plan_rejects_missing_programs ... ok
test server::tests::parse_execute_plan_rejects_non_array_programs ... ok
test server::tests::parse_execute_plan_rejects_zero_prog_id ... ok
test server::tests::parse_execute_plan_treats_missing_steps_as_skip ... ok
test server::tests::process_request_rejects_old_optimize_command ... ok

test result: ok. 28 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s
```
