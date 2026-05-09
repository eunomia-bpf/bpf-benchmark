# Daemon map-in-map supplement fix, 2026-05-08

## LOC

- `daemon/src/commands.rs`: `+135/-80` (`git diff --numstat -- daemon/src/commands.rs`)
- Net code delta before this note: `+55`
- `kernel-sys`: no change; `map_get_next_key()` already wraps libbpf-sys `bpf_map_get_next_key`.

## ARRAY_OF_MAPS iteration

`ARRAY_OF_MAPS` supplement generation no longer reads keys from the bpftool dump.
It enumerates every direct array slot from `0..max_entries`, using a little-endian
u32 key:

```rust
for i in 0..map.max_entries {
    let key = i.to_le_bytes();
    insert_inner_map_id_supplement_entry(
        map.map_id,
        &key,
        &mut lookup_inner_map_id,
        &mut entries,
    )?;
}
```

The daemon unit test
`array_of_maps_supplement_iterates_all_slots_without_bpftool_keys` injects a fake
lookup path and verifies that all four array keys are visited and written as
hex supplement keys.

## HASH_OF_MAPS iteration

`HASH_OF_MAPS` supplement generation now enumerates live keys with
`BPF_MAP_GET_NEXT_KEY` via the existing `kernel_sys::map_get_next_key()` wrapper.
The production closure is:

```rust
|previous_key, key| kernel_sys::map_get_next_key(outer_fd.as_fd(), previous_key, key)
```

The loop carries the previous key until libbpf reports ENOENT through the wrapper
as `Ok(false)`:

```rust
let mut previous_key: Option<Vec<u8>> = None;
loop {
    let mut key = vec![0u8; key_size];
    if !get_next_hash_key(previous_key.as_deref(), &mut key)
        .with_context(|| format!("BPF_MAP_GET_NEXT_KEY on outer map {}", map.map_id))?
    {
        break;
    }
    insert_inner_map_id_supplement_entry(
        map.map_id,
        &key,
        &mut lookup_inner_map_id,
        &mut entries,
    )?;
    previous_key = Some(key);
}
```

## cargo test

Command:

```sh
cargo test --manifest-path daemon/Cargo.toml --workspace
```

Output:

```text
   Compiling bpfrejit-daemon v0.1.0 (/home/yunwei37/workspace/bpf-benchmark/daemon)
    Finished `test` profile [unoptimized + debuginfo] target(s) in 0.65s
     Running unittests src/main.rs (daemon/target/debug/deps/bpfrejit_daemon-5f1bb1c52564a847)

running 28 tests
test bpf::tests::canonicalize_preserves_idx_without_loader_fd_array ... ok
test bpf::tests::canonicalize_remaps_all_four_pseudo_modes_with_loader_fd_array ... ok
test commands::tests::bytecode_decoder_rejects_unaligned_input ... ok
test bpf::tests::canonicalize_rejects_more_unique_loader_fds_than_map_ids ... ok
test bpf::tests::canonicalize_round102_real_pattern_keeps_duplicate_fd_binding ... ok
test bpf::tests::canonicalize_rejects_pseudo_map_idx_out_of_range ... ok
test commands::tests::rejit_fd_array_builder_rejects_conflicting_module_offsets ... ok
test commands::tests::rejit_fd_array_builder_rejects_missing_module_slot ... ok
test bpf::tests::canonicalize_round129_real_ldimm64_pattern_to_idx_order ... ok
test commands::tests::rejit_fd_array_builder_places_maps_first_and_module_btf_fds_at_call_offsets ... ok
test commands::tests::rejit_fd_array_builder_uses_btf_placeholder_when_no_maps ... ok
test commands::tests::target_call_offsets_shift_after_map_prefix ... ok
test server::tests::parse_execute_plan_accepts_empty_programs ... ok
test server::tests::parse_execute_plan_accepts_empty_steps_as_skip ... ok
test commands::tests::array_of_maps_supplement_iterates_all_slots_without_bpftool_keys ... ok
test server::tests::parse_execute_plan_rejects_blank_step_command ... ok
test server::tests::optimize_response_keeps_per_program_errors_under_top_level_ok ... ok
test commands::tests::try_apply_programs_converts_failures_to_program_results ... ok
test server::tests::parse_execute_plan_parses_kinsn_probes ... ok
test server::tests::parse_execute_plan_rejects_duplicate_prog_id ... ok
test server::tests::parse_execute_plan_rejects_invalid_log_level ... ok
test server::tests::parse_execute_plan_rejects_kinsn_probe_with_no_aliases ... ok
test server::tests::parse_execute_plan_rejects_missing_log_level ... ok
test server::tests::parse_execute_plan_rejects_missing_programs ... ok
test server::tests::parse_execute_plan_rejects_non_array_programs ... ok
test server::tests::parse_execute_plan_rejects_zero_prog_id ... ok
test server::tests::parse_execute_plan_treats_missing_steps_as_skip ... ok
test server::tests::process_request_rejects_old_optimize_command ... ok

test result: ok. 28 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.00s
```
