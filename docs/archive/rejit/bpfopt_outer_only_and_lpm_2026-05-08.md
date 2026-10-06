# bpfopt map-in-map outer-only and LPM_TRIE inline

Date: 2026-05-08

## LOC and files

Current task-related diff, excluding this note:

| File | Adds | Deletes |
|---|---:|---:|
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | 259 | 37 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 314 | 1 |
| `runner/config/passes/map_inline/katran.yaml` | 18 | 8 |
| `runner/config/passes/map_inline/overlays/katran/lpm_src_v4.json` | 5 | 0 |
| `runner/config/passes/map_inline/overlays/katran/lpm_src_v6.json` | 5 | 0 |
| Total | 601 | 46 |

The working tree already contained unrelated uncommitted files and some
pre-existing edits in touched files; the list above is the current diff for the
files relevant to this task.

## Mode B outer-only fold

Behavior:

- A hard hint on an ARRAY_OF_MAPS / HASH_OF_MAPS outer lookup with no matching
  inner hard hint is treated as outer-only mode B.
- The outer key still resolves through the normal outer snapshot path.
- The outer lookup helper call is replaced with a verifier-typed map pointer
  load to `r0`.
- The outer NULL check is not folded.
- Inner lookup bytecode remains dynamic, so LRU inner maps are allowed.

Key implementation:

```rust
if map_in_map_outer_only_fold_requested(
    inline_hints.for_call(outer_site.call_pc),
    inline_hints.for_call(chain.inner_call_pc),
) {
    return Ok(Some(build_map_in_map_outer_only_rewrite(
        program,
        outer_site,
        outer_info,
        &outer_key,
        &encoded_outer_key,
        inner_map_id,
    )));
}
```

```rust
fn emit_map_ptr_load(dst_reg: u8, map_id: u32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst_reg, BPF_PSEUDO_MAP_FD),
            0,
            0,
        ),
        BpfInsn::new(0, 0, 0, map_id as i32),
    ]
}
```

## LPM_TRIE NULL fold

Behavior:

- `BPF_MAP_TYPE_LPM_TRIE` is accepted by the overlay/dump path.
- A hard hint whose key is absent from an enumerated overlay folds to NULL.
- Missing hard-hint keys still fail fast for non-enumerated snapshots.
- The NULL fold replaces the lookup call with `r0 = 0`; when the immediate
  `if r0 == 0` guard is present, it is patched to jump to the existing NULL
  path, letting const-prop/DCE remove the dead non-NULL path.

Key implementation:

```rust
Err(MapLookupError::MissingKey { .. })
    if mode == MapInlineHintMode::Hard
        && enumerated_overlay_missing_key(program, info.map_id, key) =>
{
    return Ok(ResolvedInlineValue::Null);
}
```

```rust
replacements.insert(site.call_pc, vec![BpfInsn::mov64_imm(0, 0)]);
```

## Katran config

Updated `runner/config/passes/map_inline/katran.yaml` to inject overlays for:

- `lpm_src_v4`
- `lpm_src_v6`

Added hints:

```yaml
--inline-hint=lpm_src_v4:!00000000
--inline-hint=lpm_src_v6:!00000000
--inline-hint=lru_mapping:!00000000
--inline-hint=global_lru_maps:!00000000
```

`vip_to_down_reals_map` is intentionally not hinted because the benchmark
deployment has no outer entry, so an outer-only hint would fail as an operator
error.

## Test coverage

New/covered `bpfopt` tests:

- `map_inline_outer_only_array_of_maps_hard_hint_replaces_outer_lookup_only`
- `map_inline_outer_only_hash_of_maps_hard_hint_uses_outer_overlay`
- `map_inline_lpm_trie_enumerated_empty_hard_hint_folds_lookup_to_null`
- Existing mode A regression remains covered by
  `map_inline_route_a_array_of_maps_hard_hints_fold_outer_and_inner`
- Existing strict mode A mutable-inner rejection remains covered by
  `map_inline_route_a_rejects_kernel_mutable_inner_hint`

Verification run:

```text
cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt
323 lib tests passed, 9 bin tests passed, 11 cli_pipeline tests passed.
```

No corpus run was performed.
