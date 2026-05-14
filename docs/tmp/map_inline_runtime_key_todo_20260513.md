# map_inline runtime-key TODO and testbin census

Date: 2026-05-13

Scope: read-only census over all 542 `bpfopt/testbin/*/*/canonicalize_output.bin`
programs, focused on two possible `map_inline` extensions:

- relaxing the current "lookup key must be verifier-known constant bytes" guard;
- relaxing HASH helper deletion, where safe.

## Current code facts

- Current helper-style `map_inline` requires `extract_site_constant_key()`.
  Without verifier-known key bytes or a hard hint, the site is skipped before
  value materialization is attempted.
- Current `has_removable_lookup_pattern()` returns true only for
  `ARRAY`/`PERCPU_ARRAY`. `HASH`/`LRU_HASH` may have value loads constantized,
  but the helper call and null check are intentionally retained.
- Keeping the helper is enough to preserve HASH membership semantics. Deleting
  a HASH helper needs either a proven exact key hit or an explicit complete-key
  dispatch; "all observed values are equal" is not enough by itself because a
  missing key must still return NULL.

## Testbin census

Raw helper lookups found in testbin:

| app | lookups | simple `r2 = fp + off` | runtime-key dispatch candidates | no-key uniform-value candidates |
| --- | ---: | ---: | ---: | ---: |
| bcc_set | 16 | 14 | 0 | 0 |
| bpftrace_set | 22 | 22 | 0 | 0 |
| cilium_agent | 504 | 497 | 7 | 7 |
| katran | 70 | 70 | 0 | 0 |
| otelcol-ebpf-profiler_profiling | 469 | 469 | 16 | 16 |
| tetragon_observer | 4268 | 3243 | 44 | 44 |
| tracee_monitor | 4471 | 3515 | 98 | 112 |
| total | 9820 | 7830 | 165 | 179 |

Definitions:

- `runtime-key dispatch candidate`: lookup has stack key setup, runtime stack
  key stores, immediate null check, fixed-offset loads from `r0`, and no obvious
  other use of the lookup-result pointer in the local window.
- `no-key uniform-value candidate`: lookup has immediate null check and clean
  fixed-offset `r0` loads; the key is not needed if the map value is explicitly
  known to be uniform and the helper is retained for membership/bounds.

These are bytecode-shape upper bounds. Real apply count still depends on map
type, mutability, snapshot/overlay availability, and verifier-state availability.

## Good testbin samples

Small, repeated samples for unit/integration repros:

| purpose | testbin path | PC(s) | shape |
| --- | --- | ---: | --- |
| runtime key, one value load | `bpfopt/testbin/cilium_agent/160_tail_drop_notify/canonicalize_output.bin` | 14 | runtime stack key, helper null check, one fixed load |
| runtime key, repeated lookups | `bpfopt/testbin/otelcol-ebpf-profiler_profiling/44_perf_unwind_native/canonicalize_output.bin` | 406, 606, 638, ... | repeated runtime-key stack lookup with one fixed load |
| runtime key, byte-ladder value loads | `bpfopt/testbin/tetragon_observer/247_generic_kprobe_actions/canonicalize_output.bin` | 441 | key from helper result, eight byte loads from map value |
| runtime key, wide value copy | `bpfopt/testbin/tracee_monitor/701_tracepoint__exec_test/canonicalize_output.bin` | 3233, 4188, ... | runtime key, many fixed loads then stores elsewhere |

Katran is not a good runtime-key testbin for this change: its current
map_inline opportunities are mostly constant/hinted keys, skipped large
snapshots, map-in-map, or mutable maps.

## TODO

1. First implement no-key uniform-value folding.
   - Keep `bpf_map_lookup_elem()` and the null check.
   - Do not delete key setup or the helper.
   - Replace only fixed-offset loads from `r0` with constants.
   - This directly relaxes the key-const guard without needing key dispatch.
   - Safe sources:
     - `CompressedMapValuesKind::Uniform`;
     - `ARRAY`/`PERCPU_ARRAY` raw snapshots only when the full closed key domain
       is dumped and the loaded fields are uniform.
   - Do not use raw HASH dumps as "complete" by default; HASH key space is open.

2. Add runtime-key guarded dispatch only after step 1.
   - Introduce a `LookupKeyRef` carrying stack key location/width and setup
     sites, separate from current concrete `LookupKey`.
   - For a small enumerated key set, emit key compares before the original
     helper. On hit, materialize known value loads and jump to the original
     post-use continuation; on miss, fall back to the original helper.
   - This is safe for HASH membership because miss still calls the helper.
   - This needs code cloning or a controlled in-block replacement shape; it is
     more invasive than step 1.

3. Add complete runtime-key dispatch only with explicit completeness semantics.
   - For ARRAY/PERCPU_ARRAY with full snapshot, miss can mean out-of-range/null.
   - For HASH, require an explicit complete/enumerated side-input or hint.
   - Without completeness, never turn a non-matching runtime key into null.

4. Relax HASH helper deletion only for already-proven sites.
   - Constant key + stable present value + no `r0` pointer uses except fixed
     loads/null check can delete the helper.
   - Runtime-key complete dispatch can delete the helper.
   - Guarded dispatch cannot delete the helper globally because miss falls back.
   - Testbin census found no clean const-key HASH deletion candidates; this is
     expected to improve native code for selected sites, not materially increase
     `sites_applied`.

5. Tests to add.
   - Synthetic unit: runtime key + uniform overlay keeps helper/null check and
     replaces loads.
   - Synthetic unit: HASH hard hint with constant key and clean fixed loads can
     delete helper only when the new deletion path is enabled.
   - Extracted-shape unit from Tetragon actions PC 441 for byte-ladder loads.
   - Extracted-shape unit from Tracee `tracepoint__exec_test` PC 3233 for wide
     fixed loads followed by stores elsewhere.

## Expected apply-count impact

- Step 1 can increase apply count only where a map has explicit uniform value
  semantics or a closed full ARRAY/PERCPU_ARRAY snapshot. The bytecode shape
  upper bound is 179 sites across testbin.
- Step 2 can target up to 165 runtime-key dispatch-shaped sites in testbin, but
  should be gated by small entry count or explicit hot-key hints to avoid adding
  compare-chain overhead on cold misses.
- Step 4 mostly improves generated native code size/latency for sites already
  counted as applied. It should not be presented as an apply-count feature.
