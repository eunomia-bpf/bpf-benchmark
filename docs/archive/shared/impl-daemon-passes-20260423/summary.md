# Daemon Pass Matcher Relaxation — 2026-04-23

Scope:
- Implement only the top 2 ROI items from `docs/tmp/pass-trigger-20260423/summary.md` Part 5.
- No VM / corpus / e2e rerun in this round.
- No changes under `runner/*`, `e2e/*`, `corpus/*`, or `Makefile`.

## Selected Top 2 ROI Items

1. `map_inline` constant-key recovery
2. `map_inline` consumer expansion beyond syntactically direct fixed-offset loads

Why these two:
- Part 5 ranks them as the highest-ROI order for reducing the current unchanged bucket:
  1. `map_inline` key recovery
  2. `map_inline` consumer expansion
- They also match the largest surface in Z’s summary:
  - key recovery: `77 programs / 519 skipped sites`
  - consumer model: `81 programs / 361 skipped sites`
- I intentionally deferred `cond_select`, `rotate`, and `const_prop` because they rank below these two in Z’s current ROI ordering.

## Change 1: `map_inline` constant-key recovery

Files:
- `daemon/src/passes/map_inline.rs:362-405`
- `daemon/src/passes/map_inline.rs:457-659`

Before:
- Constant-key recovery only recognized stack stores that wrote directly through `r10`.
- The backward scan in `find_constant_stack_bytes_with_limit()` rejected stores unless `insn.dst_reg() == 10`.
- The verifier-guided path in `verifier_guided_stack_store_value()` had the same restriction.

After:
- Both paths now accept any stack store whose destination resolves to `fp + const` through existing stack-pointer resolution.
- Concretely, the matcher now routes store recognition through `resolve_stack_store_slot(...)`.
- This enables patterns like:
  - `r6 = r10`
  - `r6 += -8`
  - `*(u32 *)(r6 + 4) = 7`
- The verifier-guided path now uses the same fp-relative store resolution and also records `source_imm_pc` when recoverable.

Behavioral effect:
- Sites that already had a constant key on stack, but materialized it via an fp alias register, no longer fall into:
  - `lookup key is not a constant stack or pseudo-map-value materialization`

New skip reasons:
- None.

Tests added:
- `extract_constant_key_from_fp_alias_store_base` at `daemon/src/passes/map_inline_tests.rs:503-519`
- `verifier_guided_key_extracts_store_via_fp_alias_base` at `daemon/src/passes/map_inline_tests.rs:522-552`

## Change 2: `map_inline` consumer expansion

Files:
- `daemon/src/passes/map_inline.rs:2275-2553`

Before:
- `classify_r0_uses_with_options()` tracked lookup-result aliases as a plain register set.
- A load counted as inlineable only when it was a direct `ldx_mem` from the alias register using the raw instruction offset.
- Any constant pointer adjustment on the alias register caused the use to fall out of the “fixed-offset scalar load” model.

After:
- Alias tracking now carries a constant offset per alias register.
- Supported relaxed forms:
  - `MOV` copies preserve alias offset
  - `ADD/SUB` by constant immediate preserve aliasability and update the offset
  - `ADD/SUB` by constant register also update the offset
  - stack spill/reload preserves alias offset
- A load is now considered fixed-offset if:
  - the source is an alias register, and
  - `alias_offset + insn.off` is a constant effective offset that fits in `i16`
- Null-check recognition stays conservative:
  - only zero-offset aliases are treated as immediate null checks

Behavioral effect:
- Sites that previously hit:
  - `lookup result is not consumed by fixed-offset scalar loads`
  now trigger when the consumer is semantically fixed-offset but expressed as `alias + const`.

New skip reasons:
- None.

Tests added:
- `classify_r0_uses_tracks_alias_offset_loads` at `daemon/src/passes/map_inline_tests.rs:625-645`
- `map_inline_pass_rewrites_lookup_with_fp_alias_store_key_and_offset_load` at `daemon/src/passes/map_inline_tests.rs:839-878`

## Validation

Commands run:
- `cargo test --manifest-path daemon/Cargo.toml`
- `make -C daemon release`
- `make check`

Results:
- `cargo test --manifest-path daemon/Cargo.toml`: `498 passed, 0 failed`
  - Baseline was `494`; this change adds `4` new unit tests.
- `make -C daemon release`: passed
- `make check`: passed

Not run:
- `vm-e2e`
- `vm-corpus`
- any VM-based measurement

## Estimated Unlock

This section is an inference from matcher surface plus Z’s quantified skip buckets, not a measured VM result.

### Change 1: key recovery

Z summary surface:
- `77 programs / 519 skipped sites`

Implemented subset:
- fp-relative constant stores written through alias stack bases

Conservative impact estimate:
- unchanged bucket: likely `+1..4`
- broader corpus ripple: non-trivial subset of the `77 / 519` surface, especially sites whose key pointer already resolves but the store was previously missed

### Change 2: consumer expansion

Z summary surface:
- `81 programs / 361 skipped sites`

Implemented subset:
- alias-preserving constant-offset loads
- not full consumer generalization

Conservative impact estimate:
- unchanged bucket: likely `+1..4`
- broader corpus ripple: subset of the `81 / 361` surface where consumers are fixed-offset after alias arithmetic

### Combined

- Conservative unchanged unlock estimate for this exact patch set: `+2..8`
- Z’s original top-band expectation for the broader `map_inline` relaxation remains `+4..8`, but this patch intentionally implements the safer subset first and does not claim that full upper bound without corpus rerun.

## Deferred Suggestions

- `cond_select` packed-ABI relaxation
  - Deferred because Z ranks both `map_inline` items higher for the current unchanged bucket.
- `cond_select` compare-form widening
  - Same reason; larger code-path change than this round’s matcher-only scope.
- `rotate` subprog-aware support
  - Deferred because it needs pseudo-call / subprog discipline, which is materially riskier than the selected `map_inline` changes.
- `const_prop` daemon-side verifier pre-check
  - Useful for rollback noise reduction, but Z explicitly ranks it below unchanged-bucket expansion work.
- broader `map_inline` consumer generalization beyond alias+const loads
  - Deferred because write/escape-heavy consumers need tighter alias-safety reasoning.
- tracing-oriented helper/context specialization pass
  - Deferred because it is a new pass family, not a matcher relaxation.
- `skb_load_bytes_spec` / `bounds_check_merge` widening
  - Deferred because Z shows zero ROI for this x86 corpus slice.
