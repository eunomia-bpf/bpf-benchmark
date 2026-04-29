# daemon Plan B Review - 2026-04-29

Reviewed commit: `daa5bd48e0f1197c9cd3a53c814c7d978697a823` (`refactor(daemon): replace internal PassManager with fork+exec CLI (v3 §8 plan B)`).

Scope: read-only code review plus this report. No implementation code or v3 design document was modified.

## Verdict

Not ready for #47 full-platform `corpus+e2e SAMPLES=30` authoritative.

The broad Plan B direction is implemented: daemon no longer links `bpfopt`, runner Python is untouched by this commit, the socket protocol still exists, and the daemon does fork+exec the CLI tools. However, there are critical fail-fast and invalidation regressions that can make smoke numbers look healthy while hiding skipped passes, failed verifier/ReJIT subprocesses, and missing map-inline invalidation state.

## Verified Good

- `daemon/Cargo.toml` has no `bpfopt` path dependency. It depends on `kernel-sys`, `anyhow`, `clap`, `libc`, `serde`, and `serde_json`.
- `cargo tree --manifest-path daemon/Cargo.toml -p bpfrejit-daemon` shows no `bpfopt` or `goblin`; the only project crate below daemon is `kernel-sys`.
- The 6 CLI crates do not depend on each other. Their `Cargo.toml` files depend on shared workspace crates plus `kernel-sys`.
- `daa5bd48^..daa5bd48 -- runner/libs/ corpus/ e2e/ micro/` is empty. The broader `7d34960~..HEAD` range touches only `defad0a6` micro fixes: `micro/driver.py` and stale expected results in `micro/config/micro_pure_jit.yaml`.
- `daemon/src/server.rs` still accepts newline-delimited JSON over a Unix socket and handles `optimize`, `optimize-all`, `profile-start`, `profile-stop`, `profile-save`, `profile-load`, and `status`.
- `daemon/src/commands.rs` uses `std::process::Command` for `bpfget`, `bpfopt`, `bpfverify`, `bpfrejit`, and `bpfprof`.
- There are no remaining daemon references to `PassManager`, pass modules, analysis modules, or `verifier_log` outside stale README text and the `pipeline_run_ns` response field name.

## Findings

### CRITICAL - Map invalidation is no longer wired to optimization results

Locations:
- `daemon/src/commands.rs:515` takes `_invalidation_tracker` but never uses it.
- `daemon/src/commands.rs:621-630` fabricates empty `map_values.json` for `map_inline`.
- `daemon/src/commands.rs:846` always returns `inlined_map_entries: Vec::new()`.
- `daemon/src/invalidation.rs:92-118` still exposes `record_inline_site` / `remove_prog`, but production code never calls `record_inline_site`.

Impact:
- v3 requires the daemon to keep watch + invalidation responsibilities. The tracker tests still pass in isolation, but no accepted map-inline specialization is recorded into the live tracker.
- After a map value changes, `process_invalidation_tick()` has no production entries to find, so no affected program can be reoptimized.
- The old deleted tests included map-inline tracker wiring checks (`test_record_map_inline_records_updates_tracker`, `test_collect_inlined_map_entries_deduplicates_map_key_pairs`). The replacement tests do not cover this path.

Fix:
- Add a bpfopt side-output or report extension for accepted `map_inline_records`.
- Have the daemon parse those records after `bpfopt optimize`, hold/open the relevant map FDs through `kernel-sys`, populate `inlined_map_entries`, and call `tracker.record_inline_site(...)` only after the corresponding ReJIT succeeds.
- Add a fake-CLI daemon test that emits map-inline records and asserts both response `inlined_map_entries` and tracker state.

### CRITICAL - `bpfverify` / `bpfrejit` subprocess failures are converted into `status: ok`

Locations:
- `daemon/src/commands.rs:701-736` catches `bpfverify` failure, marks passes rolled back, pushes `verify_failed`, then continues.
- `daemon/src/commands.rs:752-787` catches `bpfrejit` failure, marks passes rolled back, pushes `rejit_failed`, then continues.
- `daemon/src/commands.rs:819-846` returns `OptimizeOneResult { status: "ok", error_message: None, ... }` even after those failures.
- `daemon/src/server.rs:475-478` treats any `status == "ok"` result as non-error in `optimize-all`, so failed ReJIT attempts are not counted as errors.

Impact:
- This violates fail-fast and the review requirement that `child returncode != 0` must propagate as failure.
- A kernel `BPF_PROG_REJIT` `EINVAL` can become `exit_code=0`, empty `error`, and `not_applied`, instead of surfacing naturally to corpus/e2e.
- `optimize-all` can report `"errors": 0` even when individual programs failed verification or ReJIT.

Fix:
- Propagate `run_output(&mut verify)?` and `run_output(&mut rejit)?` errors, or return `status: "error"` with `error_message` populated.
- Keep pass/attempt diagnostics if useful, but make the socket response fail and make runner-side `exit_code` nonzero.
- Add tests where fake `bpfverify` and fake `bpfrejit` exit nonzero and assert daemon response is error.

### CRITICAL - Missing side inputs are warning-and-continue fallbacks

Locations:
- `daemon/src/commands.rs:563-586` warns and continues when `bpfget --target` fails or lacks requested kinsns.
- `daemon/src/commands.rs:593-616` warns and continues when `bpfverify --verifier-states-out` fails for `const_prop`.
- `daemon/src/commands.rs:347-355` ignores `bpfopt` report `skipped` / `reason`, so skipped requested passes disappear from daemon responses.
- `daemon/src/commands.rs:1273-1286` test `incomplete_target_is_not_passed_to_bpfopt_optimize` locks in this fallback behavior.

Impact:
- A caller can request `rotate`, `cond_select`, `extract`, `endian_fusion`, `bulk_memory`, or `const_prop`; daemon can return `status: ok` after not providing the required side input.
- This directly conflicts with `CLAUDE.md` fail-fast: no fallback, no warning-and-continue for fallible work.
- Smoke applied counts are hard to trust because requested passes may have been skipped without an error.

Fix:
- Treat missing `bpfget --target`, incomplete target kinsns, and `bpfverify --verifier-states-out` failure as daemon request errors when the requested pass requires them.
- Parse and surface `skipped` / `reason` if bpfopt keeps skip semantics for non-default discovery, but do not call the request successful for explicitly requested missing capability.
- Replace the fallback unit test with a nonzero/error assertion.

### HIGH - Dead code allowances remain and daemon clippy fails

Locations:
- `daemon/src/bpf.rs:177`, `182`, `189` use `#[allow(dead_code)]`.
- `daemon/src/invalidation.rs:3`, `74`, `79` use dead-code allowances.
- `daemon/src/server.rs:623` triggers `clippy::type_complexity`.

Impact:
- This violates the explicit "No Dead Code" rule.
- `cargo clippy --manifest-path daemon/Cargo.toml --all-targets -- -D warnings` fails.

Fix:
- Delete unused helpers or gate test-only helpers with `#[cfg(test)]`.
- If invalidation helper APIs are truly production APIs, wire them into production code; otherwise keep them private/test-only.
- Add a small test-only type alias for the mock map state to satisfy clippy.

### HIGH - BPF watch errors are logged and ignored

Locations:
- `daemon/src/server.rs:131-160` logs BPF enumeration errors in `ProgramWatcher::from_live()` / `tick()` and breaks the loop, but daemon serve continues.
- `daemon/src/server.rs:226-236` logs accept/client errors and continues.

Impact:
- The daemon can run with a broken program watcher after a BPF syscall failure.
- This conflicts with the fail-fast rule to propagate BPF syscall errors.

Fix:
- Make `ProgramWatcher::from_live() -> Result<Self>` and `tick() -> Result<()>`.
- Propagate BPF watch failures out of `cmd_serve()` so the daemon exits nonzero with a useful stderr message.
- Keep client protocol errors as per-request JSON errors only when they are genuinely client input problems, not daemon capability failures.

### HIGH - Test reduction removed obsolete tests but also lost critical replacement coverage

Observed:
- `cargo test --manifest-path daemon/Cargo.toml` passes 27 tests.
- The deleted tests are mostly obsolete because they covered in-process BPF syscall wrappers, `PassManager` integration, profiler, kfunc discovery, and platform detection.
- The remaining tests cover CPU-list parsing, map invalidation logic in isolation, JSON request validation, profile save/load, fake-CLI happy path, and fake `bpfprof`.

Gaps:
- No test proves `bpfverify` nonzero propagates as daemon error.
- No test proves `bpfrejit` nonzero propagates as daemon error.
- No test proves accepted map-inline records populate the invalidation tracker.
- Existing `incomplete_target_is_not_passed_to_bpfopt_optimize` tests fallback instead of fail-fast.

Fix:
- Add focused fake-CLI negative tests for each required subprocess.
- Add one socket-level or command-level map-inline invalidation wiring test.
- Keep the obsolete PassManager/profiler tests deleted.

### MEDIUM - Docker layer split is present but ordered against the stated cache goal

Locations:
- `runner/containers/runner-runtime.Dockerfile:344-376`

Impact:
- The Dockerfile now has separate daemon and bpfopt CLI build steps, but it builds daemon first and bpfopt second.
- Docker cache keys include parent layers. A daemon source change invalidates the later bpfopt CLI layer, so "daemon change no longer invalidates bpfopt CLI cache" is not achieved.

Fix:
- Build bpfopt CLI artifacts in a lower layer from `COPY bpfopt ...`.
- Build daemon in a later layer from `COPY daemon ...`, using the already copied `kernel-sys` source.
- Keep Python/config runtime copies above both Rust layers.

### LOW - `daemon/README.md` is stale after the slim-down

Locations:
- `daemon/README.md:3-4`, `86-114`

Impact:
- README still says daemon runs the rewrite pipeline through `PassManager`, references deleted `daemon/src/passes`, `pass.rs`, `profiler.rs`, and `kfunc_discovery.rs`.

Fix:
- Update README to describe socket-to-CLI behavior after code issues above are fixed.

## Smoke Report Notes

- Latest corpus artifact found: `corpus/results/x86_kvm_corpus_20260429_091709_805618/details/result.json`.
  - `25/519` means `sum(rejit_result.program_counts.applied) / sum(rejit_result.program_counts.requested)` across 22 corpus app cases.
  - It is not the comparable performance sample count. The summary `program_count` is `131`, meaning 131 BPF programs had usable baseline and post-ReJIT run counters for `avg_ns_per_run`.
  - `applied` means accepted ReJIT changes per app-level daemon result, not pass-site count.
- I did not find a docs/tmp report substantiating `e2e 27/642`. The latest docs/tmp e2e summary I found is `docs/tmp/aws-x86-corpus-e2e-20260428.md`, which points to older `20260428` e2e artifacts and does not contain that count.
- Latest micro artifact found: `micro/results/x86_kvm_micro_20260429_100044_227599`.
  - Metadata status is `completed`.
  - It has 62 benchmarks and zero correctness mismatches.
  - Current `vm-micro` is `kernel` vs `llvmbpf`; ReJIT applied counts are not the property being measured there.

## Validation Commands

Passed:

```bash
cargo tree --manifest-path daemon/Cargo.toml -p bpfrejit-daemon
cargo build --manifest-path daemon/Cargo.toml
cargo test --manifest-path daemon/Cargo.toml
cargo build --manifest-path bpfopt/Cargo.toml --workspace
cargo test --manifest-path bpfopt/Cargo.toml --workspace
cargo clippy --manifest-path bpfopt/Cargo.toml --workspace --all-targets -- -D warnings
```

Failed:

```bash
cargo clippy --manifest-path daemon/Cargo.toml --all-targets -- -D warnings
```

Failure:

```text
error: very complex type used. Consider factoring parts into `type` definitions
   --> src/server.rs:623:17
```

Other checks:

```bash
rg -n "allow\\(dead_code\\)|\\.ok\\(\\)|let _ =|unwrap_or_default|warning|warn|continue" daemon/src daemon/Cargo.toml
git diff --name-status daa5bd48^..daa5bd48 -- runner/libs/ corpus/ e2e/ micro/
git diff --name-status 7d34960~..HEAD -- runner/libs/ corpus/ e2e/ micro/
rg -n "PassManager|passes::|analysis::|verifier_log|profiler|pipeline|kfunc|platform" daemon/src daemon/Cargo.toml
```

## Conclusion for #47

Do not start full-platform authoritative `corpus+e2e SAMPLES=30` from this commit as-is.

Minimum blockers before #47:

1. Make verifier/ReJIT subprocess failures propagate as daemon request failures.
2. Remove warning-and-continue side-input fallbacks.
3. Reconnect map-inline accepted records to daemon invalidation tracking.
4. Make daemon clippy pass under `-D warnings`.
5. Re-run x86 KVM corpus/e2e smoke and publish an actual docs/tmp smoke report with requested/applied/program_count semantics.
