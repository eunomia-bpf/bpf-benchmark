# daemon Blocker Fix Review - 2026-04-29

Reviewed commit: `bb354cd3` (`fix(daemon): propagate subprocess errors; remove side-input fallback; reconnect map-inline invalidation; clippy`).

Scope: read-only code review plus this report. No implementation code or v3 design document was modified.

## Verdict

Not ready for #47 full `SAMPLES=30` cross-platform run yet, even assuming an image rebuild.

C1, C2, and H4 are materially fixed: subprocess failures now propagate through `anyhow`, explicitly requested side-input failures no longer warning-and-continue, and daemon/bpfopt clippy passes. H3 is only partially fixed. The daemon now parses `map_inline_records` and records them into the invalidation tracker after ReJIT, but the map-inline value snapshot and invalidation reoptimization path are still not correct enough to trust full-platform results.

## Findings

### CRITICAL - map-inline still runs with empty map value snapshots

Locations:
- `daemon/src/commands.rs:791-803` enables `map_inline` by writing `--map-values`.
- `daemon/src/commands.rs:1034-1050` builds that file with `entries: Vec::new()` for every map and `frozen: false`.
- `bpfopt/crates/bpfopt/src/pass.rs:261-292` consumes `program.map_values` and falls back when a key is absent.
- `bpfopt/crates/bpfopt/src/pass.rs:296-320` treats absent ARRAY/PERCPU_ARRAY entries as zero-filled values.
- `docs/tmp/bpfopt_design_v3.md:289-309` says `map-values.json` contains actual lookup keys and values, not an empty placeholder.

Impact:

The new report parsing/tracker wiring records whatever `bpfopt` accepted, but the daemon is still giving `bpfopt` an empty value snapshot. For array-like maps, that can make `map_inline` inline zero bytes instead of the live map value. The emitted `map_inline_records` then describe the wrong expected value, so invalidation tracking is attached to a bad specialization after the kernel has already been ReJITed.

Fix:

Do not run `map_inline` from an empty `map-values.json`. Add a real key-discovery + value-read path: first discover candidate map/key pairs without applying an unsafe rewrite, read those values through the daemon/kernel side, write `map-values.json` with concrete `entries`, then run `bpfopt optimize`. Until that exists, a requested `map_inline` should fail fast instead of using empty entries.

### CRITICAL - invalidation reoptimization does not rerun with map-inline side inputs

Locations:
- `daemon/src/server.rs:198-209` reoptimizes invalidated programs with `enabled_passes = None`.
- `daemon/src/commands.rs:735` converts `None` into an empty requested pass list.
- `daemon/src/commands.rs:791-803` only generates `map_inline` side inputs when the requested pass list explicitly contains `map_inline`.
- `bpfopt/crates/bpfget/src/main.rs:248-250` makes `bpfget --full` read original bytecode.
- `daemon/src/commands.rs:840-852` compares the candidate against original bytecode and skips ReJIT on `no_change`.

Impact:

After a map value changes, the invalidation tick can call `try_apply_one(..., None, ...)`, omit `--map-values`/`--map-ids`, let `bpfopt optimize` skip `map_inline`, and then return `no_change` because the candidate equals original bytecode. In that case the currently installed kernel program can remain the stale map-inlined version, and the tracker will keep reporting the same invalidation on later ticks.

Fix:

Persist the effective pass list for each successful ReJIT that records map-inline dependencies, and reuse it during invalidation reoptimization. At minimum, invalidated map-inline programs must rerun with `map_inline` side inputs populated from live values. The invalidation path also needs a restoration strategy when a fresh specialization cannot be produced, instead of treating original-bytecode `no_change` as success while stale optimized code is still installed.

### LOW - subprocess failure tests stop at command layer, not socket response layer

Locations:
- `daemon/src/commands.rs:1474-1559` tests `bpfverify` state, final verify, and `bpfrejit` failures as `try_apply_one(...).unwrap_err()`.
- `daemon/src/server.rs:431-432` wraps `try_apply_one` errors as socket JSON errors.
- `daemon/src/server.rs:479-483` wraps `optimize-all` per-program errors as socket JSON errors.

Impact:

The implementation path is simple and appears correct, but the requested behavior "subprocess fail -> daemon returns `status: error` + stderr" is not directly asserted at the socket/server response boundary. A future change could truncate the error chain or accidentally convert the response back to `status: ok` without these tests catching it.

Fix:

Add a server-level fake-CLI test for `{"cmd":"optimize"}` and one for `optimize-all` where a subprocess exits nonzero. Assert `status == "error"` and that `error_message` contains the subprocess stderr.

## Verified Good

- C1 implementation is fixed for the main subprocess paths. `run_output` and `run_with_file_io` check `status.success()` and include stderr/stdout summaries in the error (`daemon/src/commands.rs:1244-1272`). Final `bpfverify` and `bpfrejit` failures now use `?` and return through `server.rs` as `status: error`.
- C2 implementation is fixed for explicitly requested side inputs. `bpfget --target` failure, missing requested target kinsns, `bpfverify --verifier-states-out` failure, and skipped explicitly requested passes now bail instead of warning and continuing.
- H4 is fixed. The daemon test mock state uses type aliases, dead-code allowances were removed or replaced with `#[cfg(test)]`, and clippy passes.
- The daemon test count is now 31. The meaningful new daemon coverage is `missing_target_kinsn_is_error`, `verifier_states_failure_is_error`, `final_verify_failure_is_error`, `rejit_failure_is_error`, and `map_inline_report_records_refresh_invalidation_tracker_after_rejit` (one previous target fallback test was converted, net +4). These are useful error-path/state-change tests.
- `bpfopt` added `pass_report_serializes_map_inline_records_as_hex`, which is a useful serialization-contract test for the report side-output.
- No added daemon matches for `.ok()`, `let _ =`, `unwrap_or_default`, or `#[allow(dead_code)]` were introduced by `bb354cd3`. Current matches are preexisting/test/drop cleanup uses.

## Validation

Passed:

```bash
cargo test --all-targets
# in daemon/: 31 passed

cargo clippy --all-targets -- -D warnings
# in daemon/: passed

cargo clippy -p bpfopt --all-targets -- -D warnings
# in bpfopt/: passed

cargo clippy --workspace --all-targets -- -D warnings
# in bpfopt/: passed

git diff --check 66cc55e2..bb354cd3
# passed
```

Review grep:

```bash
git diff -U0 66cc55e2..bb354cd3 -- daemon | rg -n "^\\+.*(\\.ok\\(\\)|let _ =|unwrap_or_default|#\\[allow\\(dead_code\\)\\])"
# no matches

rg -n "\\.ok\\(\\)|let _ =|unwrap_or_default|#\\[allow\\(dead_code\\)\\]" daemon
# existing matches only:
# daemon/src/commands.rs:80
# daemon/src/invalidation.rs:209
# daemon/src/server.rs:635
```

## Conclusion for #47

Do not start #47 full `SAMPLES=30` cross-platform authoritative runs yet. Rebuild images after the next fix, then run a smaller x86 smoke that exercises `map_inline` with a nonzero live map value and verifies both the optimized result and a subsequent invalidation/reoptimization cycle before spending the full-platform budget.
