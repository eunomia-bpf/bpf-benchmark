# map_inline lookup-route guard investigation

Scope: read-only investigation of the current worktree under
`/home/yunwei37/workspace/bpf-benchmark`. No code was modified, no benchmarks
were run, and only read-only git commands were used.

## 1. Precise safety property

`map_inline` replaces runtime loads from a map lookup result with constants read
from a daemon-provided map snapshot. The relevant snapshot path is:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:232-282`:
  `lookup_elem()` reads `compressed_values`, `maps_skipped_by_size`, or raw
  `values` for a `(map_id, key)` pair.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1770-1865`:
  `build_site_rewrite()` reads the snapshot value for `info.map_id` and the
  encoded lookup key, emits constant loads for fixed-offset result loads, and
  records the inlined `(map_id, key, value)`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1968-2070`:
  `build_direct_map_value_load_rewrites()` does the same for pseudo-map-value
  loads via `SnapshotMapValue`.
- `bpfopt/crates/bpfopt/src/pass.rs:244-250`:
  `MapInlineRecord` records only the raw snapshot value that was inlined.

For a plain map lookup, the safety property is:

```text
For every inlined map value M[K] = V captured in the snapshot, no runtime path
that can execute the optimized program may mutate M[K] between snapshot capture
and the optimized program's execution.
```

For a map-in-map route, the property has two levels:

```text
For an outer map O and outer key Ko, the snapshot route O[Ko] -> inner map M
must remain the route used at runtime, and the inlined inner value M[Ki] = V
must not be mutated between snapshot capture and program execution.
```

The current code already models the plain-map portion by building a
map-id-specific mutable set:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:594-649`:
  `collect_kernel_mutable_maps()` marks LRU maps mutable and resolves direct
  writer helper calls to a concrete map load when possible.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:664-683`:
  `kernel_mutable_reason_for_map()` turns that set into a per-map skip reason.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1207-1209`:
  normal lookup sites are skipped per site when their concrete map is mutable.

For map-in-map, the guard must not ask "does this program contain any writer?"
It must ask "can this specific outer-key route resolve to an inner map whose
inlined value can be mutated?"

## 2. Outer-to-inner route tracing

Current lookup discovery is direct-map-only:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:345-364`:
  `find_map_lookup_sites()` finds `bpf_map_lookup_elem()` calls only when
  `r1` can be traced to a direct pseudo-map load.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2163-2232`:
  `find_direct_map_load_for_reg_before_site()` follows `mov` and stack spills,
  then accepts `BPF_PSEUDO_MAP_FD` or `BPF_PSEUDO_MAP_IDX`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3483-3505`:
  `analyze_map_info()` maps those pseudo-map load sites to `MapInfo` through
  `ProgramCFG::map_id_for_imm()`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:331-340`:
  `map_id_for_imm()` resolves the pseudo-map immediate through construction-time
  map bindings.

Map-in-map chain detection is separate:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:365-447`:
  `find_map_in_map_chain_for_outer()` starts at an outer lookup result in `r0`,
  tracks aliases through registers and stack, allows one null check, and returns
  the later `map_lookup_elem(inner, &key)` call when that call receives the
  outer result alias in `r1`.

The side input route source is:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2805-2811`:
  `MapSnapshot::inner_map_ids` stores `(outer_map_id, outer_key_bytes) ->
  inner_map_id`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2897-2969`:
  `read_map_values()` fills `inner_map_ids` from bpftool dump entries with
  `inner_map_id`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3053-3106`:
  supplement files can also populate the same `(outer_map_id, key)` mapping.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1923-1967`:
  `resolve_inner_map_id_for_outer_key()` first consults
  `side_input.inner_map_ids[(outer_map_id, encoded_outer_key)]`, then falls
  back to decoding the first four bytes of the outer value snapshot.

Hint resolution binds the route:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:957-1028`:
  `insert_resolved_hint()` resolves a hard map-in-map outer hint key to an
  `inner_map_id` and stores it in `ResolvedMapInlineHint::map_in_map_inner`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:862-906`:
  `resolve_hinted_map_in_map_routes()` finds the outer lookup's chain and maps
  the chain's inner call site to the resolved inner map's `MapInfo`.

Important limitation: the main rewrite loop at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1198-1504` iterates only
`find_map_lookup_sites()` results. Dynamic inner lookups whose `r1` is the
outer lookup result are not direct-map sites. The code can resolve hinted
map-in-map routes, but the main site loop does not currently treat those dynamic
inner calls as first-class `MapLookupSite`s.

## 3. Per-site `is_kernel_mutable_for_this_route` predicate

There is no existing `map_writer_target_map_id` helper. The closest current
code is `collect_kernel_mutable_maps()`:

```rust
// bpfopt/crates/bpfopt/src/passes/map_inline.rs:613-645
for site in prog.all_sites() {
    let insn = prog.insn(site)?;
    if is_map_writer_helper_call(insn) {
        let Some(map_load_site) = find_direct_map_load_for_reg_before_site(prog, site, 1)?
        else {
            continue;
        };
        let info = map_info.get(&map_load_site).ok_or_else(|| {
            anyhow::anyhow!(
                "map_inline cannot resolve map reference at {:?} for {helper_name} helper at {:?}",
                map_load_site,
                site
            )
        })?;
        ids.insert(info.map_id);
        reasons.insert(info.map_id, format!(
            "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={}",
            info.map_id
        ));
    }
}
```

That is sufficient for direct writer helpers, but it does not resolve a writer
whose `r1` is an inner map pointer returned from `bpf_map_lookup_elem(outer,
&outer_key)`. A sound route guard should handle both cases.

Recommended route data:

```rust
#[derive(Clone, Debug)]
struct MapInMapRoute {
    outer_call_site: InsnSite,
    outer_map_load_site: InsnSite,
    inner_call_site: InsnSite,
    outer_map_id: u32,
    outer_key: Vec<u8>,
    inner_map_id: u32,
}
```

Recommended predicate shape:

```rust
fn is_kernel_mutable_for_this_route(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
    kernel_mutable_maps: &KernelMutableMaps,
    route: &MapInMapRoute,
    inner_lookup_key: Option<&[u8]>,
) -> anyhow::Result<Option<String>> {
    let inner_info = side_input.map_info.get(&route.inner_map_id).ok_or_else(|| {
        anyhow::anyhow!(
            "map_values snapshot has no map info for inner map {} from outer map {} key {}",
            route.inner_map_id,
            route.outer_map_id,
            format_bytes_preview(&route.outer_key)
        )
    })?;

    // Direct writer helpers and LRU map types already have map-id-specific
    // coverage through collect_kernel_mutable_maps().
    if let Some(reason) = kernel_mutable_reason_for_map(kernel_mutable_maps, inner_info) {
        return Ok(Some(format!(
            "kernel-mutable inner map route outer_map_id={} outer_key={} inner_map_id={}: {}",
            route.outer_map_id,
            format_bytes_preview(&route.outer_key),
            route.inner_map_id,
            reason
        )));
    }

    // Additional required coverage: writer helper receives r1 from the same
    // outer lookup route rather than from a direct pseudo-map load.
    if route_has_dynamic_inner_writer(prog, side_input, map_info, route, inner_lookup_key)? {
        return Ok(Some(format!(
            "kernel-mutable inner map route outer_map_id={} outer_key={} inner_map_id={}",
            route.outer_map_id,
            format_bytes_preview(&route.outer_key),
            route.inner_map_id
        )));
    }

    Ok(None)
}
```

`route_has_dynamic_inner_writer()` should be conservative:

- Scan `is_map_writer_helper_call()` sites.
- First try the existing direct-map route: `find_direct_map_load_for_reg_before_site(prog,
  writer_site, 1)` and compare the resulting map ID to `route.inner_map_id`.
- If no direct map load resolves, trace `r1` back to an alias of `r0` from an
  outer map-in-map lookup, using the same alias machinery as
  `find_map_in_map_chain_for_outer()`.
- Resolve that writer's outer route key with verifier state or a hard hint. If
  it cannot be resolved, treat it as unsafe only for that outer map route, not
  for every unrelated map in the program.
- For `map_update_elem` and `map_delete_elem`, compare the writer key in `r2`
  to `inner_lookup_key` when both keys are available. If the writer key is
  unavailable, treat the route as unsafe. For push/pop helpers, treat the whole
  target map as unsafe because there is no stable key.

The key precision can be added after route precision. The minimum sound
improvement is route-specific `inner_map_id` matching; key-specific filtering is
a further tightening.

## 4. Replacing the coarse guard

Current pass-level guard:

```rust
// bpfopt/crates/bpfopt/src/passes/map_inline.rs:1111-1118
if prog
    .all_sites()
    .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call))
    && !side_input.hints.is_empty()
    && !side_input.inner_map_ids.is_empty()
    && side_input.map_info.values().any(MapInfo::is_map_in_map)
{
    anyhow::bail!("kernel-mutable inner map");
}
```

This should be deleted. It binds four unrelated "any" predicates:

- any writer helper anywhere in the bytecode,
- any inline hint,
- any `inner_map_ids` entry,
- any map-in-map `MapInfo`.

That rejects safe programs where those facts belong to unrelated maps or lookup
sites. The normal map path already has per-map writer coverage through
`collect_kernel_mutable_maps()` and `kernel_mutable_reason_for_map()`.

Current per-site map-in-map branch:

```rust
// bpfopt/crates/bpfopt/src/passes/map_inline.rs:1215-1249
if info.is_map_in_map() {
    if find_map_in_map_chains(prog, std::slice::from_ref(&site))?
        .into_iter()
        .next()
        .is_some()
    {
        skip_lookup!(
            &mut skipped,
            &mut site_diagnostics,
            site.call_site,
            "map-in-map chain is not inlineable".to_string()
        );
    }
    if site_inline_hints.is_some() {
        if side_input
            .inner_map_ids
            .keys()
            .any(|(outer_map_id, _)| *outer_map_id == info.map_id)
            && has_writer
        {
            anyhow::bail!("kernel-mutable inner map");
        }
        anyhow::bail!(
            "map-in-map outer map_id={} has no live inner map",
            info.map_id
        );
    }
    record_skip(...);
    continue;
}
```

This should become per-site `record_skip()` logic:

- If a route is unsafe, record a skip on that lookup site with a route-specific
  reason and continue.
- If the map-in-map chain is not inlineable, record the existing skip and
  continue.
- If a hard hint references an outer key with no live inner map, record that
  site skip unless the failure is malformed side input or an invalid hint
  contract that should still `bail!`.

This is compatible with `CLAUDE.md` fail-fast intent: malformed input, missing
required metadata, parse errors, and impossible invariants should still fail the
pass. A site that is unsafe to inline is not a fallback; it is a first-class
`site_skipped` result with a precise reason. Processing unrelated safe sites
does not hide the unsafe site.

## 5. Test impact

Existing tests in `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs`:

- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:447-458`
  `map_inline_skips_kernel_mutable_map()` inserts an update helper before a
  normal array lookup and asserts a per-site `"kernel-mutable"` skip. This
  already matches the desired per-site behavior for direct maps.
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:462-476`
  `map_inline_route_a_rejects_missing_outer_entry_for_hint()` hard-hints an
  `ARRAY_OF_MAPS` outer map without a live inner entry and currently expects a
  pass error containing `"has no live inner map"`.
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:530-562`
  `map_inline_route_a_rejects_kernel_mutable_inner_hint()` inserts an update
  helper, adds `inner_map_ids[(111, key)] = 222`, hard-hints the map-in-map
  outer lookup, and expects the pass to error with `"kernel-mutable inner map"`.
  In the current implementation this is caught by the pass-level four-ANY guard
  before hint resolution.
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:566-578`
  `map_inline_route_a_rejects_orphan_inner_hint()` verifies that an inner hint
  with no matching map-in-map outer hint still fails.

Recommended updates:

- Replace `map_inline_route_a_rejects_kernel_mutable_inner_hint()` with an
  assertion that the unsafe route is a site skip, not a pass error.
- Add a regression for the concrete false positive:
  a writer to map A, a hard or soft hint for plain map B, and unrelated
  `inner_map_ids` for map-in-map outer C. Expected result: the B lookup still
  applies or skips for its own reason; the pass must not error with
  `"kernel-mutable inner map"`.
- Add a mixed-site regression:
  one unsafe map-in-map route plus one unrelated safe direct lookup in the same
  program. Expected result: one precise route skip and one successful apply.
- Keep the orphan-inner-hint error test; that is invalid hint structure, not a
  per-site mutability decision.

## 6. Corpus impact estimate

Read-only corpus inspection found no current artifact where `map_inline`
returned `failed_bpfopt` with the exact error `"kernel-mutable inner map"`.

Observed counts:

- Latest completed corpus overall:
  `corpus/results/x86_kvm_corpus_20260513_031240_537649`
  - enabled passes: `rotate`, `cond_select`, `extract`, `endian_fusion`,
    `bulk_memory`
  - tetragon/cilium/tracee `map_inline` pass records: 0
  - matching `"kernel-mutable inner map"` failures: 0
- Latest completed corpus result that includes `map_inline`:
  `corpus/results/x86_kvm_corpus_20260512_232206_068314`
  - enabled passes: `noop`, `map_inline`
  - apps present: katran, otelcol-ebpf-profiler
  - tetragon/cilium/tracee records: not present
- Latest relevant cilium-only `map_inline` result:
  `corpus/results/x86_kvm_corpus_20260512_185218_803256`
  - cilium `map_inline` records: 50
  - cilium `failed_bpfopt`: 0
  - cilium `"kernel-mutable inner map"` failures: 0
- Latest full-ish result with tetragon/cilium/tracee and `map_inline`:
  `corpus/results/x86_kvm_corpus_20260512_010914_520489`
  - tetragon: 75 `map_inline` records, 75 `failed_bpfopt`, 0
    `"kernel-mutable inner map"` failures. The failures are `"snapshot skipped
    map ..."` errors.
  - cilium: 6 `map_inline` records, 0 `failed_bpfopt`, 0
    `"kernel-mutable inner map"` failures.
  - tracee: 37 `map_inline` records, 15 `failed_bpfopt`, 0
    `"kernel-mutable inner map"` failures. The failures are `"snapshot skipped
    map ..."` errors.

Corpus impact from existing artifacts is therefore:

```text
programs affected by this exact guard: 0 observed
lookups hidden by this exact guard: 0 observed
measurable apply-count gain from existing result files: 0
```

The code-level false positive is still real. It just is not present in the
latest available corpus artifacts I inspected. If such a program appears, the
apply-count gain should be exactly the count of unrelated lookup sites that
would otherwise pass their own per-site checks. Existing artifacts cannot
quantify that hidden count without rerunning `map_inline`, which was not done.

## 7. Text-only diff sketch

Delete the pass-level guard:

```diff
diff --git a/bpfopt/crates/bpfopt/src/passes/map_inline.rs b/bpfopt/crates/bpfopt/src/passes/map_inline.rs
@@
 pub fn run_on_bbprogram(prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
     let side_input = map_inline_side_input(prog, ctx)?;
     let initial_map_info = analyze_map_info(prog, &side_input)?;
     let initial_kernel_mutable_maps =
         collect_kernel_mutable_maps(prog, &side_input, &initial_map_info)?;
-    if prog
-        .all_sites()
-        .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call))
-        && !side_input.hints.is_empty()
-        && !side_input.inner_map_ids.is_empty()
-        && side_input.map_info.values().any(MapInfo::is_map_in_map)
-    {
-        anyhow::bail!("kernel-mutable inner map");
-    }
     let initial_inline_hints = resolve_inline_hints(
         prog,
         &side_input,
```

Add route-specific helpers:

```rust
#[derive(Clone, Debug)]
struct MapInMapRoute {
    outer_call_site: InsnSite,
    outer_map_load_site: InsnSite,
    inner_call_site: InsnSite,
    outer_map_id: u32,
    outer_key: Vec<u8>,
    inner_map_id: u32,
}

fn map_writer_target_map_id(
    prog: &ProgramCFG,
    map_info: &MapInfoBySite,
    writer_site: InsnSite,
) -> anyhow::Result<Option<u32>> {
    let Some(map_load_site) = find_direct_map_load_for_reg_before_site(prog, writer_site, 1)? else {
        return Ok(None);
    };
    Ok(Some(
        map_info
            .get(&map_load_site)
            .ok_or_else(|| anyhow::anyhow!(
                "map_inline cannot resolve map reference at {:?} for writer helper at {:?}",
                map_load_site,
                writer_site
            ))?
            .map_id,
    ))
}

fn is_kernel_mutable_for_this_route(
    prog: &ProgramCFG,
    side_input: &MapInlineSideInput<'_>,
    map_info: &MapInfoBySite,
    kernel_mutable_maps: &KernelMutableMaps,
    route: &MapInMapRoute,
    inner_lookup_key: Option<&[u8]>,
) -> anyhow::Result<Option<String>> {
    let inner_info = side_input.map_info.get(&route.inner_map_id).ok_or_else(|| {
        anyhow::anyhow!(
            "map_values snapshot has no map info for inner map {} from outer map {} key {}",
            route.inner_map_id,
            route.outer_map_id,
            format_bytes_preview(&route.outer_key)
        )
    })?;

    if let Some(reason) = kernel_mutable_reason_for_map(kernel_mutable_maps, inner_info) {
        return Ok(Some(format!(
            "kernel-mutable inner map route outer_map_id={} outer_key={} inner_map_id={}: {}",
            route.outer_map_id,
            format_bytes_preview(&route.outer_key),
            route.inner_map_id,
            reason
        )));
    }

    if route_has_dynamic_inner_writer(prog, side_input, map_info, route, inner_lookup_key)? {
        return Ok(Some(format!(
            "kernel-mutable inner map route outer_map_id={} outer_key={} inner_map_id={}",
            route.outer_map_id,
            format_bytes_preview(&route.outer_key),
            route.inner_map_id
        )));
    }

    Ok(None)
}
```

Replace the per-site bail with route-specific skip logic:

```diff
@@
         if info.is_map_in_map() {
-            if find_map_in_map_chains(prog, std::slice::from_ref(&site))?
-                .into_iter()
-                .next()
-                .is_some()
-            {
+            let chain = find_map_in_map_chains(prog, std::slice::from_ref(&site))?
+                .into_iter()
+                .next();
+
+            let mut route_skip = None;
+            if let Some(hints) = site_inline_hints {
+                for hint in hints {
+                    if let Some((_, inner_map_id)) = hint.map_in_map_inner {
+                        let outer_key = encode_key_bytes(&hint.key_bytes, info.key_size as usize);
+                        let inner_call_site = chain
+                            .as_ref()
+                            .map(|chain| chain.inner_call_site)
+                            .unwrap_or(site.call_site);
+                        let route = MapInMapRoute {
+                            outer_call_site: site.call_site,
+                            outer_map_load_site: site.map_load_site,
+                            inner_call_site,
+                            outer_map_id: info.map_id,
+                            outer_key,
+                            inner_map_id,
+                        };
+                        if let Some(reason) = is_kernel_mutable_for_this_route(
+                            prog,
+                            side_input,
+                            &map_info,
+                            &kernel_mutable_maps,
+                            &route,
+                            None,
+                        )? {
+                            route_skip = Some(reason);
+                            break;
+                        }
+                    }
+                }
+            }
+            if let Some(reason) = route_skip {
+                record_skip(
+                    &mut skipped,
+                    &mut site_diagnostics,
+                    site.call_site,
+                    reason,
+                    None,
+                );
+                continue;
+            }
+
+            if chain.is_some() {
                 skip_lookup!(
                     &mut skipped,
                     &mut site_diagnostics,
                     site.call_site,
                     "map-in-map chain is not inlineable".to_string()
                 );
             }
             if site_inline_hints.is_some() {
-                if side_input
-                    .inner_map_ids
-                    .keys()
-                    .any(|(outer_map_id, _)| *outer_map_id == info.map_id)
-                    && has_writer
-                {
-                    anyhow::bail!("kernel-mutable inner map");
-                }
-                anyhow::bail!(
+                record_skip(
+                    &mut skipped,
+                    &mut site_diagnostics,
+                    site.call_site,
+                    format!("map-in-map outer map_id={} has no live inner map", info.map_id),
+                    None,
                 );
+                continue;
             }
             record_skip(
                 &mut skipped,
```

The sketch above intentionally leaves `route_has_dynamic_inner_writer()` as the
main implementation task. Reusing only `collect_kernel_mutable_maps()` would
remove false positives for direct unrelated writers, but it would not be a
complete safety proof for writer helpers that receive the inner map pointer from
the same outer lookup route.

## Verdict

Per-site route guard recommended; diff sketch in section 7.
