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

## Implemented first step

Implemented complete enumerated runtime-key membership dispatch for HASH-like
maps with uniform entry values.

- It only runs when the key pointer is the simple stack form `r2 = fp + off`,
  the map snapshot/overlay exposes an enumerated key set, every entry's inline
  value is identical, and `r0` is consumed only by the immediate null check plus
  fixed-offset value loads.
- It replaces the helper call with an in-block key membership chain:
  load key from stack, compare against every enumerated key, set `r0` to `1` on
  hit or `0` on miss, then reuse the original null check.
- It constantizes the fixed-offset loads from the uniform value.
- It does not delete key setup/map setup in this first version; later `dce` can
  remove those dead instructions. This keeps the first change tightly scoped and
  avoids branch-target deletion concerns.
- It deliberately does not use `CompressedMapValuesKind::Uniform` by itself:
  uniform value without an enumerated key set does not prove membership.

## Offline testbin result after first step

Validation commands:

- `cargo test --manifest-path bpfopt/Cargo.toml --all map_inline`
- `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml -p bpfopt`
- offline `bpfopt/testbin` sweep with a mock enumerated HASH snapshot:
  every canonicalized map index was assigned a HASH map containing one key
  `00000000` and one all-zero 8 KiB value; verifier input was intentionally
  empty (`0: R0=0`) so this measures matcher shape, not real runtime map
  safety.

Unit tests passed: 21 map_inline lib tests plus 3 CLI map_inline tests.

Mock testbin sweep result:

| app | programs | ok | errors/timeouts | membership dispatch applied |
| --- | ---: | ---: | ---: | ---: |
| bcc_set | 21 | 21 | 0 / 0 | 0 |
| bpftrace_set | 9 | 9 | 0 / 0 | 2 |
| cilium_agent | 53 | 50 | 0 / 0 | 82 |
| katran | 1 | 1 | 0 / 0 | 13 |
| otelcol-ebpf-profiler_profiling | 13 | 7 | 0 / 6 | 13 |
| tetragon_observer | 287 | 129 | 158 / 0 | 395 |
| tracee_monitor | 158 | 153 | 2 / 2 | 336 |
| total | 542 | 370 | 160 / 8 | 841 |

Interpretation:

- The 841 number is a mock-shape upper bound for the new replacement path, not
  a real corpus apply count. It intentionally disables verifier-known constant
  keys and makes every map look like an enumerated uniform HASH map.
- In this mock mode, each `membership dispatch applied` site deletes one
  `bpf_map_lookup_elem` helper and replaces value loads with constants.
- The mock run also explains why the number is much larger than the earlier
  runtime-key census: many constant-key sites become "runtime-key" only because
  the test intentionally supplied no verifier states.
- Katran shows 13 shape matches under the mock setup, but that does not mean 13
  production HASH dispatches are currently available; real Katran map_inline
  count still depends on the live map types, stable values, hints, map-in-map
  state, and verifier-state key proof.
- The Tetragon errors are from the 8 KiB mock value being smaller than fixed
  loads around offsets 24 KiB. They are mock artifact limits, not verifier/JIT
  failures.

## Remaining TODO

1. Add guarded dispatch with helper fallback for incomplete key sets.
   - For a small hot-key set, emit key compares before the original helper.
   - On hit, materialize known value loads and jump to the original post-use
     continuation; on miss, fall back to the original helper.
   - This is safe for HASH membership when completeness is unavailable.

2. Add no-key uniform-value folding only when helper retention is acceptable.
   - This can increase `sites_applied` without deleting the helper.
   - It is useful only if we want load constantization even when helper cost
     remains.

3. Relax HASH helper deletion only for already-proven constant-key sites.
   - Constant key + stable present value + no `r0` pointer uses except fixed
     loads/null check can delete the helper.
   - Testbin census found no clean const-key HASH deletion candidates; this is
     expected to improve native code for selected sites, not materially increase
     `sites_applied`.

4. Tests still worth adding.
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
