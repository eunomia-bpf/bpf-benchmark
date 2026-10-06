# map-inline fix review: commit 59a5e82b

Review target: `59a5e82b408674f9ea31854d97cb901343bc12a6` (`fix(daemon, bpfopt): map-inline must use live map values; invalidation must rerun with same pass list`)

Scope: C1 map-inline snapshot values, daemon live map-value capture, `scan-map-keys`, C2 invalidation reoptimization, no new fallback/silenced-error paths, test quality.

## Summary

The commit fixes the original ARRAY/PERCPU_ARRAY zero-fill path for normal `bpf_map_lookup_elem()` sites: `SnapshotMapProvider::lookup_elem()` now returns `map_values snapshot missing map ... key ...` instead of fabricating zeroes, and the map-inline pass propagates that as a hard error for lookup rewrites.

The daemon also now calls `bpfopt scan-map-keys`, reads live values through `kernel-sys` map lookup wrappers, writes a non-empty `map_values.json`, remembers pass lists for invalidation, and forces ReJIT during reapply even when the reoptimized candidate equals the original bytecode.

However, I found one CRITICAL correctness hole in the invalidation path and one HIGH scan/coverage hole around `LD_IMM64 BPF_PSEUDO_MAP_VALUE`. I do not consider this ready for #47 authoritative all-platform `SAMPLES=30` yet.

## Findings

### CRITICAL C1/C2: hash-map entry deletion makes invalidation reoptimization fail instead of reinstalling the original program

Locations:
- `daemon/src/commands.rs:1144-1158`
- `bpfopt/crates/bpfopt/src/main.rs:1261-1270`
- `bpfopt/crates/bpfopt/src/pass.rs:285-291`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:938-946`

The daemon intentionally allows live lookup misses for non-array maps: `lookup_map_value()` returns `None`, `write_live_map_values()` only bails on `None` for ARRAY/PERCPU_ARRAY, and then writes the scanned hash key with `value: null`.

`bpfopt` does not preserve that explicit absent-entry state. `read_map_values()` drops null entries entirely, so the pass sees the key as absent from the snapshot. The new missing-snapshot propagation then turns this into a hard error:

`map_inline requires a concrete snapshot value for map ... key ...`

This breaks the exact stale-clearing case C2 needs. If a HASH/LRU_HASH value was previously inlined and later deleted, the invalidation tracker will detect the missing entry and call `try_reapply_one()`, but the reoptimization fails before `force_rejit` can reinstall the original no-inline candidate. The stale installed code remains.

I reproduced this with a temporary hash lookup fixture containing an explicit `{"key":"01000000","value":null}` entry; `bpfopt optimize --passes map-inline` exits 1 with the missing snapshot error.

Fix suggestion:
- Preserve map-value state as tri-state in bpfopt: missing snapshot vs present value vs explicit live absence.
- For HASH/LRU_HASH explicit absence, map-inline should skip that site without error, allowing `try_reapply_one(force_rejit=true)` to verify and ReJIT the original/non-inlined candidate.
- Keep ARRAY/PERCPU_ARRAY absence fail-fast, because those map types should have a value for in-range keys.
- Add a daemon test for “previously inlined hash key deleted -> invalidation reapply calls bpfrejit and reports `reapplied`/clears tracking,” plus a bpfopt CLI/unit test for explicit hash `value:null` producing no map-inline rewrite and no hard error.

### HIGH C1/scan: `scan-map-keys` still does not robustly cover `LD_IMM64 BPF_PSEUDO_MAP_VALUE`

Locations:
- `bpfopt/crates/bpfopt/src/main.rs:525-548`
- `daemon/src/commands.rs:1212-1218`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1407-1556`

`scan-map-keys` is implemented by running the real `map_inline` pass with a recording map provider. That can discover normal helper lookup keys, but it is not a direct bytecode scanner for `LD_IMM64 BPF_PSEUDO_MAP_VALUE`.

Two consequences:

1. Daemon-generated `map_values.json` hardcodes `frozen: false` for every map. The direct pseudo-map-value path only attempts to read and constantize when `info.frozen` is true, so daemon scan does not discover these direct pseudo-map-value keys at all.
2. When a user-provided frozen snapshot is missing the zero key for a direct pseudo-map-value load, `resolve_frozen_map_value()` catches the provider error, records a diagnostic, returns `None`, and the pass succeeds unchanged. That is still a warning-and-continue path for a missing required snapshot value.

Fix suggestion:
- Make `scan-map-keys` a real scanner for both helper lookup sites and `LD_IMM64 BPF_PSEUDO_MAP_VALUE` sources, or add a scan-only mode that records pseudo-map-value source keys without relying on optimization eligibility.
- Carry enough map metadata from `bpfget --full` to distinguish read-only/frozen global maps, or make the scan report include pseudo-map-value source keys separately from the optimize-time frozen decision.
- Make missing snapshot values for actual direct pseudo-map-value constantization fail fast instead of being downgraded to diagnostics.

### HIGH tests: the added tests are useful but miss the two risky boundaries above

Locations:
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:436-464`
- `daemon/src/commands.rs:1762-1904`
- `daemon/src/server.rs:837-889`

The new/reworked tests cover:
- ARRAY/PERCPU_ARRAY missing snapshot key exits 1 for normal lookup sites.
- Non-zero live map value flows into daemon-created `map_values.json`.
- Reapply forces bpfrejit even when the candidate bytecode is unchanged.
- Reoptimization state stores the original requested pass list for map-inline results.

Missing coverage:
- explicit hash `value:null` must not become a missing-snapshot hard error;
- invalidation reapply after a hash entry deletion must clear stale inline code;
- real `bpfopt scan-map-keys` JSON output for helper lookup keys;
- pseudo-map-value scan behavior and missing-snapshot behavior.

These are not garbage-test requests: each would catch a concrete stale-code or fail-fast regression in this commit.

### MEDIUM: reoptimization pass-list state is daemon-process memory only

Locations:
- `daemon/src/server.rs:81-122`
- `daemon/src/server.rs:267-303`

`ReoptimizationState` is an in-memory `HashMap<prog_id, Vec<String>>`. The invalidation tracker is also in-memory. If the daemon restarts after installing map-inline-specialized programs, it no longer has either the tracked `(map,key,value)` dependencies or the enabled pass list needed to reoptimize them on later map changes.

This is not a blocker for a single uninterrupted benchmark run, but it is a real operational limitation. Either persist enough state to disk or add startup reconciliation that clears/rebuilds map-inline specializations. At minimum, document that daemon restart invalidates map-inline tracking assumptions for authoritative runs.

## C1 review notes

Pass-level zero-fill fallback is removed for normal map lookup snapshots:
- `bpfopt/crates/bpfopt/src/pass.rs:285-291` now errors when metadata exists but the key is absent.
- `bpfopt/crates/bpfopt/src/mock_maps.rs:93-95` now mirrors that behavior in tests.

Daemon live value capture exists:
- `daemon/src/commands.rs:594-597` uses `kernel_sys` via `bpf::bpf_map_get_info`, `bpf_map_lookup_value_size`, and `bpf_map_lookup_elem_optional`.
- `daemon/src/commands.rs:1109-1170` iteratively runs `scan-map-keys`, reads live values, writes `map-values.json`, and converges or fails.

The remaining C1 blocker is the explicit hash absence/null state and pseudo-map-value scan path above.

## C2 review notes

The intended in-memory C2 path is implemented:
- `daemon/src/server.rs:81-148` stores and retrieves the original enabled pass list.
- `daemon/src/server.rs:274-282` uses that pass list during invalidation reapply.
- `daemon/src/commands.rs:921-931` forces reoptimization installs when `force_rejit` is true, even if the candidate equals original bytecode.

`bpfget --full` reads original load-time bytecode via `kernel_sys::prog_get_original`, so reapply starts from the original program rather than from already-ReJITed code.

The remaining C2 blocker is the hash deletion path: a legitimate live `None` currently aborts before forced ReJIT can clear stale code.

## New fallback/silencing audit

I did not find new ReJIT filtering, pass exclusions, `LifecycleAbort`, exclusion lists, or reintroduced zero-fill fallback in the reviewed diff.

Notable existing/non-blocking items:
- `WorkDir::drop()` still has `let _ = fs::remove_dir_all(...)`, but that was not introduced by this commit.
- The new `scan-map-keys` flow has bounded convergence and fails if no progress is made.

## Verification

Commands run:
- `cd bpfopt && cargo build --workspace`
- `cd bpfopt && cargo test --workspace`
- `cd bpfopt && cargo clippy --workspace --all-targets -- -D warnings`
- `cd daemon && cargo build`
- `cd daemon && cargo test` (`33 passed`)
- `cd daemon && cargo clippy --all-targets -- -D warnings`

All passed.

## Conclusion

Not ready for #47 authoritative all-platform `SAMPLES=30` yet, even with an image rebuild.

Required before authoritative run:
1. Fix explicit hash miss/delete handling so invalidation reapply can reinstall the original/no-inline candidate.
2. Fix or explicitly scope `scan-map-keys` for `LD_IMM64 BPF_PSEUDO_MAP_VALUE`.
3. Add focused tests for those two behaviors.
4. Re-run build/test/clippy and rebuild images.
