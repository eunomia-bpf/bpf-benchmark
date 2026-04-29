# Phase 2 Review: bpfverify + bpfprof + verifier_log migration

Date: 2026-04-28

Reviewed commit: `681f5ba81a0d9f154debc9e8f81777a432832f55`
Base: `dbfda9fc6a0c72369245f1861eae97cf4d431a4e`

Scope:

- `git diff 681f5ba8^..681f5ba8`
- `bpfopt/crates/bpfverify/{Cargo.toml,src/main.rs,src/verifier_log.rs,tests/}`
- `bpfopt/crates/bpfprof/{Cargo.toml,src/main.rs,tests/}`
- daemon verifier-log reference removal
- `bpfopt/crates/bpfopt/src` verifier-states/profile changes
- `bpfopt/Cargo.toml` workspace membership

## Findings

### CRITICAL: `bpfverify --report` does not include parsed verifier states required by v3

Location:

- `bpfopt/crates/bpfverify/src/main.rs:54-66`
- `bpfopt/crates/bpfverify/src/main.rs:154-166`
- `docs/tmp/bpfopt_design_v3.md:119-121`

Description:

v3 §2.2 says `--report FILE` writes structured JSON containing pass/fail, verifier log, and parsed states. The implemented `VerifyReport` contains `status`, `verifier_log`, `insn_count`, `log_level`, `errno`, `jited_size`, and `log_true_size`, but no parsed-state payload. The code writes that report before the `--verifier-states-out` conversion path, so even when log level 2 is available, the report schema never includes the states.

Impact:

Consumers using report mode cannot get the complete v3 report contract. This is not caught by `bpfverify/tests/cli.rs:90-116`, which checks status/log/count only.

Fix recommendation:

Add a report field such as `states` or `verifier_states` using the same v3 §3.5 DTO emitted by `--verifier-states-out`. If report mode is expected to always include parsed states, force `log_level = 2` when `--report` is set; otherwise explicitly represent unavailable states as `null` and update the authoritative v3 contract separately. Add an integration test that asserts the report contains the parsed-state field.

### HIGH: `bpfprof` writes non-per-program PMU counters into every program profile

Location:

- `bpfopt/crates/bpfprof/src/main.rs:113-121`
- `bpfopt/crates/bpfprof/src/main.rs:202-229`
- `bpfopt/crates/bpfprof/src/main.rs:383-396`
- `docs/tmp/bpfopt_design_v3.md:153-157`
- `docs/tmp/bpfprof-design-20260428.md:121`

Description:

`bpfprof` opens one pair of PMU branch counters for the sampling window and passes the single `BranchCounts` value into `build_profiles()`. `build_profiles()` then copies the same `branch_misses`, `branch_instructions`, and `branch_miss_rate` into every `ProfileJson`, including `--all` output. There is no attribution from those PMU counts to the target BPF program ID, and `per_insn` is always empty.

Impact:

The output schema looks like per-program branch PMU data, but the values are shared window-level data. This can mislead downstream `bpfopt branch-flip` because `read_profile()` imports `branch_miss_rate` as program profiling data.

Fix recommendation:

Until there is a real per-program PMU attribution source, do not populate program-level branch PMU fields with shared counters. Prefer making `branch_miss_rate`, `branch_misses`, and `branch_instructions` optional/null in the emitted profile and letting `bpfopt` consume them as `None`, or emit only `run_cnt_delta`, `run_time_ns_delta`, and empty/omitted `per_insn`. If the schema must stay non-null, define the window-level semantics explicitly before Phase 3 and prevent branch-flip from treating them as program-attributed data.

### MEDIUM: `bpfverify --log-level` default diverges from authoritative v3

Location:

- `bpfopt/crates/bpfverify/src/main.rs:37-39`
- `bpfopt/crates/bpfverify/src/main.rs:137-141`
- `docs/tmp/bpfopt_design_v3.md:131-136`

Description:

v3 §2.2 documents `--log-level N` default as `0`, with states mode forcing `2`. The implementation defaults to `1`, and only forces `2` for `--verifier-states-out`.

Impact:

This is a visible CLI contract mismatch. It also means normal pass-through verification pays for verifier logging by default and may emit report logs where v3 says default log level is off.

Fix recommendation:

Change the default to `0` and keep the `--verifier-states-out` force-to-2 behavior. If default `1` is intentionally desired, update v3 in a separate design-doc change before relying on it.

### LOW: Integration tests miss the two highest-risk schema/attribution gaps

Location:

- `bpfopt/crates/bpfverify/tests/cli.rs:90-116`
- `bpfopt/crates/bpfprof/tests/cli.rs:23-62`

Description:

The eight integration tests cover key CLI paths, and all pass in the reviewed commit. They do not assert that `--report` includes parsed states, and the bpfprof integration tests cannot validate PMU attribution or per-program JSON file output under `--output-dir`.

Impact:

The current tests would stay green while the v3 report schema remains incomplete and while branch PMU values are duplicated across programs.

Fix recommendation:

Add one report-schema assertion for parsed states. For bpfprof, add a focused non-kernel unit test around `build_profiles()` that documents the chosen PMU semantics, and add an `--output-dir` integration test where possible. Do not add tests that only restate serde or clap behavior.

## Checks That Passed

### CLI dependency boundary

`bpfverify/Cargo.toml` depends only on `kernel-sys`, `clap`, `serde`, `serde_json`, and `anyhow`.

`bpfprof/Cargo.toml` depends only on `kernel-sys`, `clap`, `serde`, `serde_json`, `anyhow`, `humantime`, and `perf-event-open-sys`.

`cargo tree -p bpfverify --locked` and `cargo tree -p bpfprof --locked` show no dependency on `bpfopt`, other CLI crates, or daemon code.

### Syscall boundary

`rg 'libc::syscall|SYS_bpf' bpfopt/crates/bpfverify bpfopt/crates/bpfprof` returned no matches. BPF program/map/stat operations go through `kernel-sys`. `bpfprof` uses `perf-event-open-sys::perf_event_open`; this is not a BPF syscall and is acceptable in the CLI boundary, subject to the attribution finding above.

### `verifier_log` migration

`git diff --find-renames --summary 681f5ba8^..681f5ba8` reports:

```text
rename bpfopt/crates/{bpfopt => bpfverify}/src/verifier_log.rs (99%)
```

`bpfopt/crates/bpfopt/src/lib.rs` no longer exports `verifier_log`. Daemon imports of `bpfopt::verifier_log` were removed. `bpfopt` now keeps pass-facing `VerifierInsn`/`RegState` types in `bpfopt::pass` and deserializes v3-style JSON instead of parsing raw kernel logs. That is the right direction for avoiding CLI cross-dependencies.

### `bpfopt const-prop` JSON path

`bpfopt/crates/bpfopt/src/main.rs:894-950` deserializes `verifier-states.json` via serde into pass-layer `VerifierInsn` values. It does not reference the moved verifier-log parser. `ConstPropPass` consumes `program.verifier_states` through pass-layer types.

### Workspace membership

`bpfopt/Cargo.toml` lists:

```text
crates/kernel-sys
crates/bpfopt
crates/bpfget
crates/bpfrejit
crates/bpfverify
crates/bpfprof
```

The shared library crate is first, followed by CLI crates. This matches the requested workspace shape.

## Verification Commands

Executed in a detached temporary worktree at `681f5ba8` to avoid touching the main workspace:

```bash
cargo tree -p bpfverify --locked
cargo tree -p bpfprof --locked
cargo build --workspace --locked
cargo test --workspace --locked
```

Results:

- `cargo tree -p bpfverify --locked`: pass
- `cargo tree -p bpfprof --locked`: pass
- `cargo build --workspace --locked`: pass
- `cargo test --workspace --locked`: pass, 448 tests

## Conclusion

Not ready as a clean Phase 2 gate for #41 plus Phase 3+.

The dependency boundary, syscall boundary, verifier-log migration, const-prop JSON input path, workspace membership, build, and tests are in good shape. The blockers are semantic: `bpfverify --report` does not satisfy the v3 report payload, and `bpfprof` emits branch PMU fields as if they were per-program while using one shared counter sample. Fix those before Phase 3 consumes the new CLIs. A narrow #41 minimal pipeline could proceed only if it does not rely on report-mode parsed states and does not feed current bpfprof branch PMU fields into optimization decisions.
