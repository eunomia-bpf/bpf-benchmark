# Mode B Check Order Fix

## Real Code Locations

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs`
  - `resolve_map_in_map_route_a_hints`
  - `has_resolved_map_in_map_outer_hint`
  - `deferred_hint_targets_known_map_in_map_inner`
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs`
  - `map_inline_hash_hard_hint_without_inner_hint_uses_normal_fold`

## Change Snippet

```rust
let routes = resolve_hinted_map_in_map_routes(program, map_info, sites, resolved)?;
if routes.is_empty() {
    let has_map_in_map_outer_hint =
        has_resolved_map_in_map_outer_hint(map_info, sites, resolved)?;
    let has_known_inner_hint = deferred_inner_hints.iter().try_fold(false, |found, hint| {
        deferred_hint_targets_known_map_in_map_inner(program, sites, hint)
            .map(|matches| found || matches)
    })?;
    if has_map_in_map_outer_hint || has_known_inner_hint {
        bail!(
            "inner inline hint anchor {} has no matching map-in-map outer hint",
            format_hint_anchor(&deferred_inner_hints[0].anchor)
        );
    }
    return Ok(());
}
```

The old `first_resolved_non_map_in_map_hint` path was removed. A resolved
ordinary map hint is no longer reclassified as a map-in-map outer just because
there is no matching inner route. The final unmatched-hint check is also gated
by `deferred_hint_targets_known_map_in_map_inner`, so unrelated non-OOM metadata
hints do not become Route A/Mode B errors when a real map-in-map route exists.

## Regression Test

`map_inline_hash_hard_hint_without_inner_hint_uses_normal_fold` builds a normal
`BPF_MAP_TYPE_HASH` lookup with a hard `vip_map` hint and no matching inner hint.
It also includes a metadata-only non-OOM `lpm_src_v4` hint to reproduce the
katran-style mixed hint list. Expected behavior: `vip_map` folds through the
ordinary map path, `sites_applied == 1`, and only one hint is consumed.
