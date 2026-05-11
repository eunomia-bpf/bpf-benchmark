# Phase 3 Fix: map_inline BBProgram Convergence

Date: 2026-05-11

## Result

Self-rating: A.

`map_inline.rs` no longer consumes `ctx.verifier_states`, no longer filters verifier snapshots by `state.pc == ...`, and no longer calls `site_pc()` or `site_current_pc()` in production code. Verifier state lookup is now site-keyed through `BBProgram::oracle_at(site)`, and report PC materialization happens only at the CLI report sink through `BBProgram::site_current_pc(site)`.

## Gate Outputs

```text
$ cd bpfopt && cargo build --release
Finished release profile [optimized] target(s) in 0.04s
```

```text
$ cd bpfopt && cargo test --release
test result: ok. 188 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 16 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 12 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

```text
$ cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings
Finished release profile [optimized] target(s) in 0.04s
```

```text
$ rg "ctx\.verifier_states" bpfopt/crates/bpfopt/src/passes/map_inline.rs
<no output>
```

```text
$ rg "state\.pc\s*==\s*" bpfopt/crates/bpfopt/src/passes/map_inline.rs
<no output>
```

```text
$ rg "site_pc\(|site_current_pc\(" bpfopt/crates/bpfopt/src/passes/map_inline.rs
<no output>
```

```text
$ wc -l bpfopt/crates/bpfopt/src/passes/map_inline.rs
5077 bpfopt/crates/bpfopt/src/passes/map_inline.rs
```

LOC: 5100 before, 5077 after, net -23.

## Key Code Changes

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1211`: `try_extract_constant_key_verifier_guided()` now takes only `prog`, `call_site`, and `key_size`, then retrieves the verifier snapshot with `prog.oracle_at(call_site)`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1580`: PC anchor handling converts incoming hint PCs with `prog.original_pc_to_site(pc)` and validates the resulting site is a map lookup call.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2231` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2297`: fixpoint result aggregation carries `SiteDiagnostic` and `SiteSkipReason` without materializing PCs.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3083`: key extraction chooses inline hints or verifier-guided keys entirely from `InsnSite` inputs.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4577` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4612`: diagnostics and skip recording are site-keyed helpers.
- `bpfopt/crates/bpfopt/src/pass.rs:283`: `PassResult` now has site-keyed `site_skipped` and `site_diagnostics` fields for BBProgram-native passes.
- `bpfopt/crates/bpfopt/src/pass.rs:335`: added `SiteSkipReason` and `SiteDiagnostic` records keyed by `InsnSite`.
- `bpfopt/crates/bpfopt/src/main.rs:321`: the CLI captures a pre-pass `BBProgram` snapshot when a report is requested.
- `bpfopt/crates/bpfopt/src/main.rs:1075`: `pass_report()` now owns report-boundary conversion for site-keyed records.
- `bpfopt/crates/bpfopt/src/main.rs:1141`: report PC conversion is centralized in `report_pc()` via `program.site_current_pc(site)`.
- `bpfopt/crates/bpfopt/src/test_helpers.rs:269`: tests materialize site-keyed skips only at the helper/report boundary.

## Removed Legacy Usages

Removed `ctx.verifier_states` usage from `map_inline.rs`:

- Deleted the `verifier_states: &[VerifierInsn]` parameter from `try_extract_constant_key_verifier_guided()`.
- Deleted its `verifier_states.is_empty()` branch.
- Deleted the direct `ctx.verifier_states.as_ref()` argument in `extract_site_constant_key()`.

Removed `state.pc == ...` usage from `map_inline.rs`:

- Deleted the occurrence scan that computed `call_pc` and filtered verifier snapshots with `state.pc == call_pc`.
- Deleted `verifier_state_for_lookup_occurrence()`.
- Deleted `try_extract_constant_key_for_occurrence()`.

Removed `site_pc()` / `site_current_pc()` production usage from `map_inline.rs`:

- Removed the `site_pc` import.
- Removed `MapLookupSite::pc()` and `FixedLoadUse::pc()` bridge helpers.
- Removed PC materialization from verifier-guided key extraction.
- Removed PC materialization from store/key diagnostic paths.
- Removed PC-scanning lookup resolution in favor of `original_pc_to_site()`.
- Removed PC materialization from all skip recording paths.
- Removed PC materialization from map-load diagnostics.
- Removed PC materialization from key extraction debug and error paths.
- Removed PC materialization from nested map-inline record handling.
- Removed PC materialization from direct pseudo-map-value diagnostics.

`PassContext.verifier_states` remains because other code still uses it to seed the `BBProgram` verifier oracle and other passes/tests still reference the field. `map_inline.rs` no longer touches it.

## Notes

I also removed the now-dead legacy helper exports from `analysis/mod.rs` and `analysis/bbprogram_helpers.rs` after `map_inline.rs` stopped importing `site_pc`; otherwise the required clippy gate with `-D dead_code -D warnings` fails. No runner, daemon, corpus, e2e, micro, or YAML files were modified for this task.
