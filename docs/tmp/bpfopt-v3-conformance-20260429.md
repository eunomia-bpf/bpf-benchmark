# bpfopt v3 conformance review (2026-04-29)

Scope: `docs/tmp/bpfopt_design_v3.md` is treated as authoritative. I compared it against:

- `docs/kernel-jit-optimization-plan.md`
- current `bpfopt/`
- `daemon/Cargo.toml`
- current `daemon/src/`
- bpfopt-related docs under `docs/tmp/`
- related runtime docs/build wiring where they materially affect the v3 design

I did not run tests or modify implementation files.

## v3 Baseline

The v3 design is CLI-first and Unix-pipeline-first:

- `bpfopt-suite` is a set of Unix-style tools. Pipeline composition belongs to shell/files, not to any long-running process or internal framework.
- `bpfopt` is a pure bytecode optimizer: raw `struct bpf_insn[]` on stdin/stdout, side-inputs via files, no kernel dependency.
- `bpfverify`, `bpfprof`, `bpfget`, and `bpfrejit` are separate kernel-facing tools.
- `bpfrejit-daemon` is optional. It watches new programs and map invalidations, then triggers an external script/command.
- v3 explicitly says the daemon does not run a pass pipeline, does not call `bpfopt`, does not profile, does not transform bytecode, and does not maintain `PassManager`.

The direct answers requested:

1. v3 says daemon should use bpfopt by external orchestration, not as a library dependency. More precisely, the daemon should not call `bpfopt` itself in its core logic; it should run a user-supplied script with `Command::new(script).arg(prog_id)` and that script may invoke `bpfget | bpfopt ... | bpfrejit`.
2. v3 says benchmark runner should preferably bypass daemon entirely and call CLI tools directly: `bpfget ... | bpfopt optimize ... | bpfrejit ...`.
3. v3 does not design daemon as an in-process Rust embedding of `bpfopt-core`.

## bpfopt-core vs CLI Boundary in v3

`bpfopt-core` responsibilities:

- internal workspace crate, not a public Rust API commitment;
- pure bytecode IR, instruction helpers, analyses, pass traits, `PassManager`, pass implementations, and verifier-log parsing support used by optimizers/verifier tooling;
- no raw BPF syscalls, no live kernel discovery, no profiler, no REJIT, no Unix socket, no daemon session state;
- `MapInlinePass` should consume explicit `map-values.json`, not live map syscalls;
- kinsn availability should come from `target.json` / `--kinsns`, not daemon-owned fd-array transport.

`bpfopt` CLI responsibilities:

- expose every pass as a top-level subcommand: `wide-mem`, `rotate`, `const-prop`, `cond-select`, `extract`, `endian`, `branch-flip`, `dce`, `map-inline`, `bulk-memory`, `bounds-check-merge`, `skb-load-bytes`;
- expose `optimize`, `analyze`, and `list-passes`;
- read/write raw binary bytecode on stdin/stdout unless `--input` / `--output` is supplied;
- parse side-input files: `--target`, `--profile`, `--verifier-states`, `--map-values`, `--map-ids`;
- emit pass reports via `--report`;
- fail loudly on malformed bytecode or missing required side-inputs.

Kernel-facing tool responsibilities:

- `bpfverify`: `BPF_PROG_LOAD` dry-run, verifier log, verifier states, pass-through mode.
- `bpfprof`: collect runtime profile and output `profile.json`.
- `bpfget`: read original kernel bytecode/metadata/map bindings and enumerate programs.
- `bpfrejit`: submit final bytecode to `BPF_PROG_REJIT`.
- `kernel-sys`: raw syscall wrapper crate for kernel-facing CLIs, not for `bpfopt`.

## Current Implementation Snapshot

Current `bpfopt/`:

- `bpfopt/Cargo.toml` has only one workspace member: `crates/bpfopt-core`.
- There is no tracked `bpfopt` CLI crate.
- There are no tracked `kernel-sys`, `bpfverify`, `bpfprof`, `bpfget`, `bpfrejit`, or `bpfrejit-daemon` crates under `bpfopt/`.
- `bpfopt-core` does contain the shared pass/IR/analysis implementation and declares itself zero-kernel-dependency.

Current daemon:

- `daemon/Cargo.toml` directly depends on `bpfopt-core` via `../bpfopt/crates/bpfopt-core`.
- `daemon/src/main.rs` reexports `bpfopt_core::{analysis, insn, pass, passes, verifier_log}` and keeps daemon-only modules for raw BPF syscalls, server, pipeline wrapper, profiler, invalidation, and kfunc discovery.
- `daemon/src/main.rs` exposes only `bpfrejit-daemon serve --socket ...`; it does not expose v3 `--on-new-prog`.
- `daemon/src/commands.rs::try_apply_one()` fetches live program bytecode, installs live map providers, builds `passes::build_full_pipeline()`, performs per-pass `BPF_PROG_LOAD` verification, rolls rejected pass output back, and finally calls `BPF_PROG_REJIT`.
- `daemon/src/server.rs` owns a Unix socket JSON protocol with `optimize`, `optimize-all`, `profile-start`, `profile-stop`, `profile-save`, `profile-load`, and `status`.
- `daemon/src/server.rs` performs invalidation ticks by directly calling `commands::try_apply_one()`, not by launching an external script.

Build wiring is current for the library dependency:

- `runner/mk/build.mk` includes `bpfopt/crates/bpfopt-core/src`, `bpfopt/Cargo.toml`, and `bpfopt-core/Cargo.toml` in daemon source inputs.
- `runner/containers/runner-runtime.Dockerfile` copies `bpfopt` before building daemon.

## Current Code vs v3

### 1. Missing CLI tool suite

v3 requires six tools. Current code has only:

- `bpfopt-core` library crate;
- existing `daemon/` binary named `bpfrejit-daemon`.

Missing tracked v3 artifacts:

- `bpfopt` CLI with stdin/stdout pass subcommands;
- `bpfverify`;
- `bpfprof`;
- `bpfget`;
- `bpfrejit`;
- `kernel-sys`;
- `bpfrejit-daemon` thin v3 watch/trigger implementation.

This is the largest implementation gap. The raw v3 examples such as `bpfget 123 | bpfopt wide-mem | bpfrejit 123` cannot be run from the tracked source tree.

### 2. Daemon uses bpfopt-core as a library dependency

Current daemon directly links `bpfopt-core`. v3 wants the daemon to be an event source plus external command trigger, and explicitly says it must not run a pass pipeline or maintain `PassManager`.

Current flow is therefore non-conformant:

- daemon links `bpfopt-core`;
- daemon constructs `PassContext`;
- daemon builds/runs the full pass pipeline;
- daemon owns per-pass verification and rollback;
- daemon owns final REJIT.

Under v3, this should become either:

- benchmark runner directly runs CLI tools and no daemon is involved; or
- daemon receives an event and executes a configured external script, without knowing pass internals.

### 3. Daemon CLI/API is not v3

v3 example:

```bash
bpfrejit-daemon --on-new-prog /path/to/optimize.sh --socket /var/run/bpfrejit.sock
```

Current CLI:

```bash
bpfrejit-daemon serve --socket /var/run/bpfrejit.sock
```

Current daemon does not implement `--on-new-prog` / `--on-invalidation` script hooks. Instead, the JSON protocol accepts optimization requests and runs the internal pipeline.

### 4. Daemon still owns responsibilities v3 moved out

v3 moved these out of daemon:

- pass pipeline;
- profiler;
- kfunc discovery for target generation;
- verifier-log parsing path for `bpfverify`;
- optimize command implementation.

Current daemon still owns all of them:

- `commands.rs` runs optimization and REJIT;
- `pipeline.rs` does daemon-owned per-pass verify/rollback wrappers;
- `profiler.rs` and `server.rs` implement profiling state and hotness ranking;
- `kfunc_discovery.rs` discovers kinsn metadata at daemon startup;
- `commands.rs` parses verifier logs and seeds/refreshes verifier states.

This matches the older daemon-centric architecture, not v3.

### 5. bpfopt-core is mostly pure, but still shaped for daemon embedding

`bpfopt-core` has no direct raw syscall dependency, which is good. However, its current abstractions are still designed for daemon in-process embedding:

- `BpfProgram` has `map_info_provider` and `map_value_provider` with comments saying the daemon installs live raw-syscall providers.
- `PassContext` has `KinsnCallResolver`; the daemon supplies an fd-array resolver in `daemon/src/pipeline.rs`.
- `MapInlinePass` can run through provider traits instead of purely consuming `map-values.json`.

These adapters are useful for the current implementation, but they are not the v3 file/CLI boundary. v3 wants bpfopt side-inputs to be JSON files and live map/syscall work to be in `bpfget` / daemon / runner, not in an embedded provider path.

### 6. Pass naming and report surface are not exposed as v3 CLI

The current registry uses internal names:

- `const_prop`, `cond_select`, `map_inline`, `bulk_memory`, `bounds_check_merge`, `skb_load_bytes_spec`, `endian_fusion`

v3 CLI names are hyphenated:

- `const-prop`, `cond-select`, `map-inline`, `bulk-memory`, `bounds-check-merge`, `skb-load-bytes`, `endian`

This is not necessarily a core-library problem, but because no CLI exists, there is no translation layer implementing v3's public surface.

### 7. Side-input/error behavior is not implemented as v3 CLI behavior

Examples:

- v3 says missing required side-input for `branch-flip --profile` should exit 1. Current `BranchFlipPass` returns unchanged with a diagnostic if PMU data is missing.
- v3 says `bpfopt --report FILE` writes a `pass-report.json`. Current daemon emits rich JSON over its socket response; no `bpfopt --report` path exists.
- v3 says `bpfverify --verifier-states-out` is the producer for verifier states. Current daemon obtains verifier states inside `commands.rs`.

### 8. Benchmark runner remains daemon-socket based

v3 recommends runner direct CLI integration for benchmark use. Current runner still starts `bpfrejit-daemon serve`, sends socket `{"cmd":"optimize"}` requests, and passes explicit `enabled_passes` lists through the daemon.

This is a direct Phase 3 gap: v3 says benchmark runner should switch from daemon socket protocol to direct CLI.

### 9. Invalidation contract differs

v3 says `bpfopt map-inline --report` should produce invalidation hints; daemon reads those hints, polls map values, and triggers re-optimize via external script.

Current daemon derives `map_inline_records` directly from in-process pass results, stores them in `MapInvalidationTracker`, and calls `try_apply_one()` on invalidation. There is no `invalidation-hints.json` file boundary.

## kernel-jit-optimization-plan.md vs v3

The current plan document is not conformant with v3.

The clearest conflict is §4.6 line 364:

- It says `daemon serve` is the only runtime entry.
- It says pass/IR/analysis should live only in `daemon/src/`.
- It says old `bpfopt/` workspace was deleted.
- It says offline `bpfopt-core`/CLI architecture is deprecated.

All four claims contradict v3:

- v3 makes `bpfopt-suite` the authoritative toolchain.
- v3 requires `bpfopt-core` and multiple CLI tools.
- v3 makes daemon optional and thin.
- v3 recommends runner direct CLI use.

The plan document also still describes daemon as the policy engine that performs discovery, analysis, rewriting, profiling, per-pass verification, and final REJIT. That is the pre-v3 model.

There is also a mismatch between the plan and current code: the plan says pass/IR/analysis are only in `daemon/src/`, but current code has them in `bpfopt-core` and daemon depends on that crate. So `docs/kernel-jit-optimization-plan.md` is stale both relative to v3 and relative to the checkout.

## docs/tmp bpfopt Documents vs v3

### `docs/tmp/bpfopt_design.md`

This older design is not v3-conformant:

- It designs a public-ish Rust library API, `optimize_with_validator`, `ValidationOracle`, `KinsnRequirement`, and C FFI direction.
- It keeps daemon as a kernel-facing driver that still calls `bpfopt::optimize_with_validator()`.
- It says daemon should not build `PassManager`, but it still uses an embedded optimizer library model.

v3 supersedes this with CLI/file boundaries and explicitly excludes public Rust API, `ValidationOracle`, C FFI, symbolic `KinsnRequirement`, and custom framing.

### `docs/tmp/bpfopt_design_v2.md`

v2 is closer to v3 but still not identical:

- It is CLI-first and splits `bpfopt`, `bpfverify`, `bpfprof`, and `bpfrejit-daemon`.
- It keeps daemon as live program session owner and per-pass orchestrator.
- It says daemon organizes `bpfopt pass -> bpfverify -> accept/reject -> final REJIT`.

v3 goes further:

- adds explicit `bpfget` and `bpfrejit` tools;
- says pipeline is bash;
- says daemon does not run a pass pipeline and does not call `bpfopt`;
- recommends benchmark runner direct CLI use.

### `docs/tmp/bpfopt-daemon-refactor-analysis-20260426/summary.md`

This report partially anticipates v3 but then recommends a different endpoint:

- It correctly notes that v3 defines six tools and a thin daemon.
- It also recommends shrinking `bpfopt-suite` to `bpfopt` only and keeping `verify`, `rejit`, `daemon`, `profiler`, and `syscall` in daemon.
- It recommends daemon directly depending on the bpfopt library API.

Those recommendations conflict with v3's six-tool suite and daemon-as-trigger model.

### `docs/tmp/daemon-bpfopt-status-20260428.md`

This report is stale relative to current code and v3:

- It says daemon does not depend on `bpfopt-core`; current `daemon/Cargo.toml` does.
- It says `bpfopt/` contains `bpfopt-core` plus a `bpfopt` CLI; current `bpfopt/` contains only `bpfopt-core`.
- It describes duplicated daemon/core pass implementations; current daemon pass implementation is reexported from `bpfopt-core`.
- Its architecture baseline is still daemon serve/socket, not v3 CLI pipeline.

### `docs/tmp/bpfopt-design-review-20260428.md`

This report is internally superseded and stale:

- It starts with a correction saying `bpfopt-core` should be the shared source of truth.
- It then says a concurrent commit deleted `bpfopt/` and made daemon the single pass implementation.
- Current code now has `bpfopt-core` again, daemon depends on it, and the CLI crate has been removed.

It is not v3-conformant because its recommended runtime remains daemon-centric, not CLI-pipeline-centric.

### `docs/tmp/daemon-bpfopt-unification-20260428.md`

This document accurately describes much of the current code, but it conflicts with v3:

- It says `bpfopt-core` is the single source of truth and daemon depends on it.
- It says daemon remains the only live REJIT runtime entry.
- It says daemon owns raw syscalls, live discovery, per-pass `BPF_PROG_LOAD`, final `BPF_PROG_REJIT`, profiler, invalidation tracker, and final result reporting.

v3 instead wants the daemon thin and optional, with pass execution in CLI pipelines and benchmark runner direct CLI integration.

### `docs/tmp/bpfopt-pass-design-gap-20260429.md`

This document is not v3-based; it extracts requirements from `docs/kernel-jit-optimization-plan.md` and `CLAUDE.md`.

Several findings are now stale against current code:

- It says per-pass records serialize `pass_name`, but current `PassDetail` has `#[serde(rename = "pass")]`.
- It says Docker/build inputs do not include `bpfopt/`, but current `runner/mk/build.mk` and runtime Dockerfile do.
- It says a `bpfopt` CLI exists under `bpfopt/crates/bpfopt/src/main.rs`; current tracked source has no CLI crate.

It still identifies useful non-v3 gaps such as exact-constant-only const-prop and pass coverage limitations, but it should not be treated as a v3 conformance document.

## Other Relevant Docs

`daemon/README.md`, `docs/daemon-architecture.md`, and `docs/paper/documents/eval-spec.md` all document the current daemon-centric serve/socket pipeline. They are consistent with current code, but not with v3:

- daemon is described as the control plane that discovers live programs and runs a multi-pass rewrite pipeline;
- `serve --socket` is the active CLI;
- profile commands and pipeline timing are daemon/socket concepts;
- benchmark evaluation is built around daemon optimize requests.

If v3 is authoritative, these docs need either a stale-status banner or a rewrite.

## Non-Gaps / Already Aligned Pieces

- `bpfopt-core` exists and is the single pass/IR/analysis source for current daemon.
- `bpfopt-core` has no direct raw syscall dependency.
- daemon-owned per-pass verify/rollback is not in `bpfopt-core`; it is in `daemon/src/pipeline.rs`.
- daemon build/image inputs now include `bpfopt-core`.
- current daemon per-pass JSON includes the v2-required `pass` field via serde rename.
- default benchmark config does not use per-prog_type pass exclusions.

These are useful implementation pieces, but they do not make the repo v3-conformant because v3's main boundary is process/file/CLI based.

## Gap Summary

P0 architecture gaps:

1. Implement or restore the six v3 CLI tools.
2. Remove daemon's in-process optimization role, or mark v3 as not implemented.
3. Replace daemon socket optimize path in benchmark runner with direct CLI pipeline.
4. Add v3 `bpfrejit-daemon --on-new-prog` / external script trigger behavior if daemon is retained.

P1 boundary gaps:

1. Add `bpfopt` CLI subcommands, raw stdin/stdout binary protocol, side-input parsing, and report files.
2. Move verifier dry-run behavior to `bpfverify` CLI.
3. Move profiling collection to `bpfprof` CLI.
4. Move program/original-bytecode/target discovery to `bpfget` CLI.
5. Move final REJIT submission to `bpfrejit` CLI.
6. Change map-inline invalidation output to `invalidation-hints.json` file flow.

P2 cleanup/documentation gaps:

1. Update `docs/kernel-jit-optimization-plan.md` §4.6 and #646 text to v3.
2. Mark older `docs/tmp` bpfopt reports as superseded by v3.
3. Update `daemon/README.md`, `docs/daemon-architecture.md`, and paper eval docs if v3 is the intended future.
4. Decide whether `bpfopt-core` provider traits should remain for tests only or be replaced by explicit JSON side-input loading at the CLI boundary.

## Final Assessment

The current checkout is not v3-conformant. It is a hybrid of the later `bpfopt-core` sharing refactor and the older daemon-centric runtime:

- pass code is shared through `bpfopt-core`;
- runtime optimization is still implemented by `bpfrejit-daemon serve`;
- the v3 CLI toolchain is absent;
- benchmark integration still uses daemon socket requests;
- docs are split across at least three incompatible designs.

If `docs/tmp/bpfopt_design_v3.md` is authoritative, the next implementation step should not be another daemon/core refactor. It should be creating the actual CLI/file boundaries first, then deleting or demoting the daemon's internal optimization path once runner integration can use those tools.
